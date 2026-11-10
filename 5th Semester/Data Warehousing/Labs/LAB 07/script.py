import random
from datetime import date
from faker import Faker
import pyodbc

# Initialize Faker
fake = Faker()

# Database connection configuration for SQL Server Developer Edition
CONN_STR = (
    "DRIVER={ODBC Driver 17 for SQL Server};"
    "SERVER=localhost;"  # Update server name if necessary
    "DATABASE=IndexDB;"
    "Trusted_connection=yes;"
)


def generate_university_data(num_students: int):
  conn = pyodbc.connect(CONN_STR)
  cursor = conn.cursor()

  # Enable fast_executemany for high-speed bulk inserts in pyodbc
  cursor.fast_executemany = True

  print("\n" + "=" * 50)
  print(f"Starting Data Generation for Scale: {num_students:,} Students")
  print("=" * 50)

  # 1. Insert 10 Departments[cite: 2]
  print("Inserting 10 Departments...")
  departments = [
      ("Computer Science", "Block A"),
      ("Physics", "Science Wing"),
      ("Mathematics", "Block B"),
      ("Electrical Engineering", "Engineering Hub"),
      ("Mechanical Engineering", "Engineering Hub"),
      ("Business Administration", "Management Block"),
      ("Economics", "Management Block"),
      ("Chemistry", "Science Wing"),
      ("Biology", "Science Wing"),
      ("English Literature", "Arts Block"),
  ]
  cursor.executemany(
      """
        INSERT INTO Departments (department_name, building)
        VALUES (?, ?)
    """,
      departments,
  )
  conn.commit()

  # 2. Insert 100 Teachers[cite: 2]
  print("Inserting 100 Teachers...")
  teachers = []
  for _ in range(100):
    first_name = fake.first_name()
    last_name = fake.last_name()
    email = fake.unique.email()
    dept_id = random.randint(1, 10)
    hire_date = fake.date_between(start_date="-10y", end_date="today")
    teachers.append((first_name, last_name, email, dept_id, hire_date))

  cursor.executemany(
      """
        INSERT INTO Teachers (first_name, last_name, email, department_id, hire_date)
        VALUES (?, ?, ?, ?, ?)
    """,
      teachers,
  )
  conn.commit()

  # 3. Insert 200 Courses[cite: 2]
  print("Inserting 200 Courses...")
  base_courses = [
      "Introduction to Algorithms",
      "Quantum Mechanics",
      "Linear Algebra",
      "Circuit Analysis",
      "Thermodynamics",
      "Financial Accounting",
      "Microeconomics",
      "Organic Chemistry",
      "Cell Biology",
      "Shakespearean Drama",
  ]
  courses = []
  for i in range(200):
    # Ensure unique course names by appending an index if needed
    base_name = base_courses[i % len(base_courses)]
    c_name = f"{base_name} {i//len(base_courses) + 1}" if i >= 10 else base_name
    credits = random.choice([3, 4])
    teacher_id = random.randint(1, 100)
    courses.append((c_name, credits, teacher_id))

  cursor.executemany(
      """
        INSERT INTO Courses (course_name, credits, teacher_id)
        VALUES (?, ?, ?)
    """,
      courses,
  )
  conn.commit()

  # 4. Insert Students and Enrollments in Batches
  print(
      f"Inserting {num_students:,} Students and corresponding Enrollments..."
  )

  semesters = ["Fall 2023", "Spring 2024", "Fall 2024", "Spring 2025"]
  batch_size = 5000  # Batch size to manage memory and transaction logs

  # To link enrollments correctly with auto-incrementing student IDs,
  # we insert students in chunks, fetch their assigned IDs, and insert enrollments.
  total_enrollments = 0

  for start_idx in range(1, num_students + 1, batch_size):
    end_idx = min(start_idx + batch_size - 1, num_students)
    current_batch_size = end_idx - start_idx + 1

    student_batch = []
    for _ in range(current_batch_size):
      first_name = fake.first_name()
      last_name = fake.last_name()
      email = fake.unique.email()
      enrollment_date = fake.date_between(start_date="-4y", end_date="today")
      dob = fake.date_of_birth(minimum_age=18, maximum_age=30)
      student_batch.append((first_name, last_name, email, enrollment_date, dob))

    # Insert students
    cursor.executemany(
        """
            INSERT INTO Students (first_name, last_name, email, enrollment_date, date_of_birth)
            VALUES (?, ?, ?, ?, ?)
        """,
        student_batch,
    )
    conn.commit()

    # Retrieve the student IDs just generated for this batch
    cursor.execute(
        """
        SELECT TOP {} student_id FROM Students ORDER BY student_id DESC
    """.format(
            current_batch_size
        )
    )
    # Fetch them in the correct ascending order
    batch_student_ids = [row[0] for row in cursor.fetchall()][::-1]

    # Generate enrollments (each student takes 5 to 10 random courses)[cite: 2]
    enrollment_batch = []
    for s_id in batch_student_ids:
      num_courses = random.randint(5, 10)
      # Pick random unique courses for the student
      enrolled_courses = random.sample(range(1, 201), num_courses)
      for c_id in enrolled_courses:
        semester = random.choice(semesters)
        grade = random.randint(50, 100)  # Realistic passing/grading range
        enrollment_batch.append((s_id, c_id, semester, grade))

    cursor.executemany(
        """
            INSERT INTO Enrollments (student_id, course_id, semester, grade)
            VALUES (?, ?, ?, ?)
        """,
        enrollment_batch,
    )
    conn.commit()
    total_enrollments += len(enrollment_batch)
    print(
        f"Progress: Processed up to student {end_idx:,} / {num_students:,}"
        f" ({total_enrollments:,} total enrollments so far)"
    )

  cursor.close()
  conn.close()
  print("Data generation completed successfully!")


def clear_database():
  conn = pyodbc.connect(CONN_STR)
  cursor = conn.cursor()
  print("\nClearing existing data and resetting identity seeds...")

  # Disable constraints temporarily or delete in correct child-to-parent order
  cursor.execute("DELETE FROM Enrollments")
  cursor.execute("DELETE FROM Students")
  cursor.execute("DELETE FROM Courses")
  cursor.execute("DELETE FROM Teachers")
  cursor.execute("DELETE FROM Departments")

  # Alternatively, use TRUNCATE on tables to reset IDENTITY seeds cleanly:
  # (Note: truncate requires dropping/ignoring FKs, so deleting with RESEED is easier)

  # Reset the identity seeds back to 1 for all tables
  cursor.execute("DBCC CHECKIDENT ('Enrollments', RESEED, 0)")
  cursor.execute("DBCC CHECKIDENT ('Students', RESEED, 0)")
  cursor.execute("DBCC CHECKIDENT ('Courses', RESEED, 0)")
  cursor.execute("DBCC CHECKIDENT ('Teachers', RESEED, 0)")
  cursor.execute("DBCC CHECKIDENT ('Departments', RESEED, 0)")

  conn.commit()
  cursor.close()
  conn.close()
  print("Database cleared and identity seeds reset.")

if __name__ == "__main__":
  # Run for Scale 1 (1,000 students)
  #generate_university_data(1000)

  # When you are ready for Scale 2 (10,000 students):[cite: 3]
   #clear_database()
   #generate_university_data(10000)

  # When you are ready for Scale 3 (100,000 students):[cite: 3]
  #clear_database()
  #generate_university_data(100000)

  # When you are ready for Scale 4 (1,000,000 students):[cite: 3]
    clear_database()
    generate_university_data(1000000)