--Task 1.1:
SELECT ROUND(AVG(CGPA), 2) AS Overall_Avg_CGPA
FROM FCIT_Students;


--Task 1.2:
SELECT 
    Department, 
    ROUND(AVG(CGPA), 2) AS Avg_CGPA
FROM FCIT_Students
GROUP BY Department
ORDER BY Department;

--Task 1.3:
SELECT 
    Shift, 
    ROUND(AVG(CGPA), 2) AS Avg_CGPA
FROM FCIT_Students
GROUP BY Shift;


--Task 1.4:
SELECT 
    Batch, 
    ROUND(AVG(CGPA), 2) AS Avg_CGPA
FROM FCIT_Students
GROUP BY Batch
ORDER BY Batch;


--Task 1.5:
SELECT 
    Department, 
    Shift, 
    ROUND(AVG(CGPA), 2) AS Avg_CGPA
FROM FCIT_Students
GROUP BY Department, Shift
ORDER BY Department, Shift;



--Task 2.1:
SELECT 
    Department,
    Total_CGPA,
    Student_Count,
    ROUND(Total_CGPA / Student_Count, 2) AS Derived_Avg_CGPA
FROM VW_Dept_CGPA_Sum;


SELECT 
    Department,
    Total_CGPA,
    Student_Count,
    ROUND(Total_CGPA / Student_Count, 2) AS Derived_Avg_CGPA
FROM VW_Dept_CGPA_Sum;




--Task 2.2:
CREATE MATERIALIZED VIEW VW_Dept_Performance_Counts AS
SELECT 
    Department,
    COUNT(*) AS Total_Students,
    SUM(CASE WHEN CGPA >= 3.5 THEN 1 ELSE 0 END) AS High_Performers,
    SUM(CASE WHEN CGPA < 2.5 THEN 1 ELSE 0 END) AS At_Risk_Students
FROM FCIT_Students
GROUP BY Department;


SELECT 
    Department,
    Total_Students,
    High_Performers,
    At_Risk_Students,
    ROUND((CAST(High_Performers AS FLOAT) / Total_Students) * 100, 2) AS High_Performer_Percentage,
    ROUND((CAST(At_Risk_Students AS FLOAT) / Total_Students) * 100, 2) AS At_Risk_Percentage
FROM VW_Dept_Performance_Counts;





--Task 2.3:
CREATE MATERIALIZED VIEW VW_Overall_FCIT_CGPA AS
SELECT 
    AVG(CGPA) AS Overall_Avg_CGPA
FROM FCIT_Students;


CREATE MATERIALIZED VIEW VW_Dept_Avg_CGPA AS
SELECT 
    Department,
    AVG(CGPA) AS Dept_Avg_CGPA
FROM FCIT_Students
GROUP BY Department;


SELECT 
    d.Department,
    ROUND(d.Dept_Avg_CGPA, 2) AS Dept_Avg_CGPA,
    ROUND(o.Overall_Avg_CGPA, 2) AS Overall_Avg_CGPA,
    ROUND(d.Dept_Avg_CGPA - o.Overall_Avg_CGPA, 2) AS Deviation,
    CASE 
        WHEN d.Dept_Avg_CGPA >= o.Overall_Avg_CGPA THEN 'Above Overall'
        ELSE 'Below Overall'
    END AS Performance_Status
FROM VW_Dept_Avg_CGPA d
CROSS JOIN VW_Overall_FCIT_CGPA o;



-- Task 3:
CREATE TABLE Articles_API (
    PaperID        VARCHAR2(100) PRIMARY KEY,
    Title          VARCHAR2(500),
    Authors        VARCHAR2(1000),
    Abstract       CLOB,
    Year           NUMBER(4),
    CitationCount  NUMBER,
    Reference_List VARCHAR2(4000)
);

ALTER TABLE Articles_API 
ADD Reference_List VARCHAR2(4000);

SELECT TOP 5 PaperID, Title, [Year], CitationCount, Reference_List 
FROM Articles_API;