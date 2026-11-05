import json
import oracledb
import requests

# 1. Define the Semantic Scholar API endpoint and search parameters (reduced limit to 5 to avoid 429)
url = "https://api.semanticscholar.org/graph/v1/paper/search"
params = {
    "query": "artificial intelligence in education",
    "limit": 5,
    "fields": (
        "paperId,title,authors,abstract,year,citationCount,referenceCount,references"
    ),
}

# Added a User-Agent header alongside your API key
headers = {
    "x-api-key": "s2k-MmgQJNgL6PYCD9huDrEhCfLQPfJfdUrJlE3WkdUl",
    "User-Agent": "Mozilla/5.0",
}

print("Fetching research papers from Semantic Scholar API...")
response = requests.get(url, params=params, headers=headers)

if response.status_code != 200:
  print(f"Error fetching data: {response.status_code} - {response.text}")
  exit()

data = response.json()
print(f"Successfully retrieved {len(data.get('data', []))} papers.")

# 2. Connect to your local Oracle Express Edition database
connection = oracledb.connect(
    user="Abdullah Ayub", password="Abdsep03@.", dsn="localhost:1521/XE"
)
cursor = connection.cursor()

inserted_count = 0

# 3. Loop through results and insert into Articles_API table
for paper in data.get("data", []):
  paper_id = paper.get("paperId")
  title = paper.get("title")

  # Join multiple authors into a single comma-separated string
  authors = ", ".join([a.get("name", "") for a in paper.get("authors", [])])
  abstract = paper.get("abstract")
  year = paper.get("year")
  citation_count = paper.get("citationCount", 0)

  # Task 3.3: Extract references and store at least 2 as a JSON/text list
  refs = paper.get("references", [])
  ref_ids = [r.get("paperId") for r in refs if r.get("paperId")]
  reference_list_json = json.dumps(ref_ids[:2])  # Grabbing up to 2 references

  try:
    cursor.execute(
        """
            INSERT INTO Articles_API 
            (PaperID, Title, Authors, Abstract, Year, CitationCount, Reference_List)
            VALUES (:1, :2, :3, :4, :5, :6, :7)
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

# Commit changes and close database connection
connection.commit()
cursor.close()
connection.close()

print(
    f"Successfully inserted {inserted_count} records into your Oracle"
    " Articles_API table!"
)