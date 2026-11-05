import json
import requests
import pyodbc

# 1. Fetch data from Semantic Scholar API
url = "https://api.semanticscholar.org/graph/v1/paper/search"
params = {
    "query": "artificial intelligence in education",
    "limit": 5,
    "fields": "paperId,title,authors,abstract,year,citationCount,references",
}

headers = {
    "x-api-key": "s2k-MmgQJNgL6PYCD9huDrEhCfLQPfJfdUrJlE3WkdUl",
    "User-Agent": "Mozilla/5.0",
}

print("Fetching papers from Semantic Scholar API...")
response = requests.get(url, params=params, headers=headers)

if response.status_code != 200:
  print(f"Error fetching data: {response.status_code} - {response.text}")
  exit()

data = response.json()
print(f"Successfully retrieved {len(data.get('data', []))} papers.")

# 2. Connect to SQL Server (SSMS) using Windows Authentication
# Change 'YourDatabaseName' to your actual database name, and 'localhost\SQLEXPRESS' to your server name if different
conn_str = (
    "DRIVER={ODBC Driver 17 for SQL Server};"
    "SERVER=localhost;"  # Changed from localhost\SQLEXPRESS to just localhost
    "DATABASE=master;"  # Replace with your real DB name in SSMS
    "Trusted_Connection=yes;"
)

connection = pyodbc.connect(conn_str)
cursor = connection.cursor()

inserted_count = 0

# 3. Insert records into SSMS Articles_API table
for paper in data.get("data", []):
  paper_id = paper.get("paperId")
  title = paper.get("title")
  authors = ", ".join([a.get("name", "") for a in paper.get("authors", [])])
  abstract = paper.get("abstract")
  year = paper.get("year")
  citation_count = paper.get("citationCount", 0)

  # Safe reference extraction
  refs = paper.get("references")
  if refs is None:
    refs = []
  ref_ids = [r.get("paperId") for r in refs if r and r.get("paperId")]
  reference_list_json = json.dumps(ref_ids[:2])

  try:
    cursor.execute(
        """
            INSERT INTO Articles_API 
            (PaperID, Title, Authors, Abstract, Year, CitationCount, Reference_List)
            VALUES (?, ?, ?, ?, ?, ?, ?)
        """,
        (
            paper_id,
            title,
            authors,
            abstract,
            year,
            citation_count,
            reference_list_json,
        ),
    )
    inserted_count += 1
  except Exception as e:
    print(f"Skipped paper {paper_id} due to error: {e}")

connection.commit()
cursor.close()
connection.close()

print(f"Successfully inserted {inserted_count} records into SSMS Articles_API!")