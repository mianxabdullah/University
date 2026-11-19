"""
Lab 2 - STARTER (fill in every TODO)
Multi-source extraction (PDF, SQL Server, CSV, images) + incremental load with MERGE.

Usage (run from the Lab2_Student_Pack folder):
    python lab2_starter.py stage   data/Enrollment_Fall2026_Batch1.pdf      # PDF -> stg.Enrollment -> MERGE
    python lab2_starter.py stage   data/Enrollment_Fall2026_Batch2_Revised.pdf
    python lab2_starter.py challans data/challans                           # OCR -> stg.Challan
    python lab2_starter.py export  output/Student_Consolidated.csv          # join all sources -> CSV

Requires: pip install pdfplumber pandas pyodbc pytesseract pillow
          + Tesseract OCR installed (Windows: https://github.com/UB-Mannheim/tesseract/wiki)
"""
import os
import re
import sys
import glob

import pandas as pd
import pdfplumber

# ---------------- configuration ----------------
SERVER = r"localhost"          # e.g. r".\SQLEXPRESS"
DATABASE = "Lab2DB"
CONN_STR = (f"DRIVER={{ODBC Driver 17 for SQL Server}};SERVER={SERVER};"
            f"DATABASE={DATABASE};Trusted_Connection=yes;")
TESSERACT_EXE = r"C:\Program Files\Tesseract-OCR\tesseract.exe"   # Windows default path

PDF_COLUMNS = {                       # PDF header  ->  staging column
    "Roll No": "RollNo", "Student Name": "StudentName", "Course Code": "CourseCode",
    "Course Title": "CourseTitle", "Cr. Hrs": "CreditHours", "Section": "Section",
}


def connect():
    import pyodbc
    return pyodbc.connect(CONN_STR, autocommit=False)


# ---------------- E: extract ----------------
def extract_pdf(path):
    rows = []
    with pdfplumber.open(path) as pdf:
        for page in pdf.pages:                                  # TODO 1
            for table in page.extract_tables():
                for r in table:
                    if r[0] == "Roll No":                       # TODO 2: skip repeated header
                        continue
                    rows.append(r)
    df = pd.DataFrame(rows, columns=list(PDF_COLUMNS.keys()))
    df = df.rename(columns=PDF_COLUMNS)                         # TODO 3
    df["CreditHours"] = df["CreditHours"].astype(int)
    df["Section"] = df["Section"].apply(                        # TODO 4
        lambda x: x.strip() if x and x.strip() else None)
    before = len(df)
    df = df.drop_duplicates().reset_index(drop=True)            # TODO 5
    print(f"Duplicates removed: {before - len(df)}")
    return df


def extract_challans(folder):
    from PIL import Image
    import pytesseract
    if os.path.exists(TESSERACT_EXE):
        pytesseract.pytesseract.tesseract_cmd = TESSERACT_EXE
    rows = []
    for f in sorted(glob.glob(os.path.join(folder, "*.png"))):
        text = pytesseract.image_to_string(Image.open(f))       # TODO 6
        roll = re.search(r"Roll\s*No\s*:\s*(\d{2}F-\d{4})", text)          # TODO 7
        chal = re.search(r"Challan\s*No\s*:\s*([A-Z0-9-]+)", text)
        pen = re.search(r"Late\s*Payment\s*Penalty\s*:\s*Rs\.?\s*([\d,]+)", text)
        if not (roll and chal and pen):
            print(f"WARNING: could not parse {os.path.basename(f)}")
            continue
        rows.append((chal.group(1), roll.group(1),
                     int(pen.group(1).replace(",", "")), os.path.basename(f)))
    return pd.DataFrame(rows, columns=["ChallanNo", "RollNo", "PenaltyFee", "SourceImage"])


# ---------------- L: load staging + MERGE ----------------
def stage_and_merge(pdf_path):
    name = os.path.basename(pdf_path)
    df = extract_pdf(pdf_path)
    df = df.astype(object).where(pd.notna(df), None)            # NaN -> NULL
    df["SourceFile"] = name
    conn = connect()
    cur = conn.cursor()
    cur.execute("TRUNCATE TABLE stg.Enrollment")                # TODO 8
    cur.executemany(
        "INSERT INTO stg.Enrollment (RollNo, StudentName, CourseCode, CourseTitle, "
        "CreditHours, Section, SourceFile) VALUES (?,?,?,?,?,?,?)",
        df.values.tolist())
    cur.execute("EXEC dw.usp_MergeEnrollment @SourceFile = ?", name)   # TODO 9
    result = cur.fetchall()
    conn.commit()
    if not result:
        print("No changes.")
    for r in result:
        print(r.ChangeType, r.Cnt)
    conn.close()


def stage_challans(folder):
    df = extract_challans(folder)                               # TODO 10
    conn = connect()
    cur = conn.cursor()
    cur.execute("TRUNCATE TABLE stg.Challan")
    cur.executemany(
        "INSERT INTO stg.Challan (ChallanNo, RollNo, PenaltyFee, SourceImage) VALUES (?,?,?,?)",
        df.values.tolist())
    conn.commit()
    conn.close()
    print(f"{len(df)} challans staged")


# ---------------- T + dump: consolidated CSV ----------------
def export(csv_path):
    conn = connect()
    enr = pd.read_sql(
        "SELECT RollNo, COUNT(*) AS CoursesEnrolled, SUM(CreditHours) AS TotalCreditHours "
        "FROM dw.Enrollment GROUP BY RollNo", conn)
    fee = pd.read_sql(
        "SELECT RollNo, TuitionFee, PaidAmount, FeeStatus FROM src.Student_Fee", conn)
    pen = pd.read_sql(
        "SELECT RollNo, SUM(PenaltyFee) AS PenaltyFee FROM stg.Challan GROUP BY RollNo", conn)
    conn.close()
    con = pd.read_csv("data/student_contacts.csv", dtype=str)
    con["RollNo"] = con["RollNo"].str.strip()
    df = (con[["RollNo", "StudentName", "Department", "Email", "City"]]
          .merge(enr, on="RollNo", how="left")
          .merge(fee, on="RollNo", how="left")
          .merge(pen, on="RollNo", how="left"))
    for c in ["CoursesEnrolled", "TotalCreditHours", "PenaltyFee"]:
        df[c] = df[c].fillna(0).astype(int)
    df["OutstandingBalance"] = df["TuitionFee"] - df["PaidAmount"]
    os.makedirs(os.path.dirname(csv_path) or ".", exist_ok=True)
    df.to_csv(csv_path, index=False)
    print(f"{len(df)} rows written to {csv_path}")


if __name__ == "__main__":
    cmd, arg = sys.argv[1], sys.argv[2]
    {"stage": stage_and_merge, "challans": stage_challans, "export": export}[cmd](arg)