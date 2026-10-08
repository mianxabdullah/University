-- DWH LAB 04 - FCIT CGPA Analytics & API Integration
-- BS Data Science, DSF24 Afternoon
-- Schema and Data Load Script
-- Oracle SQL

-- Optional cleanup if objects already exist:
-- DROP TABLE FCIT_Students CASCADE CONSTRAINTS;
-- DROP TABLE Articles_API CASCADE CONSTRAINTS;

-----------------------------------------------------------------------
-- Table for Task 1 and Task 2
-----------------------------------------------------------------------

CREATE TABLE FCIT_Students (
    StudentID    NUMBER PRIMARY KEY,
    StudentName  VARCHAR2(100) NOT NULL,
    Department   VARCHAR2(50)  NOT NULL,   -- Computer Science, Data Science,
                                            -- Software Engineering, Information Technology
    Shift        VARCHAR2(10)  NOT NULL,   -- Morning, Evening
    Batch        VARCHAR2(10)  NOT NULL,   -- F22, F23, F24, F25
    CGPA         NUMBER(3,2)   NOT NULL    -- 0.00 - 4.00
);

-----------------------------------------------------------------------
-- Data: ~200 students across 4 departments, 2 shifts, 4 batches
-----------------------------------------------------------------------

DECLARE
    v_dept  VARCHAR2(50);
    v_shift VARCHAR2(10);
    v_batch VARCHAR2(10);
    v_cgpa  NUMBER(3,2);
BEGIN
    FOR i IN 1..200 LOOP
        v_dept := CASE TRUNC(DBMS_RANDOM.VALUE(1, 5))
                      WHEN 1 THEN 'Computer Science'
                      WHEN 2 THEN 'Data Science'
                      WHEN 3 THEN 'Software Engineering'
                      ELSE 'Information Technology' END;

        v_shift := CASE WHEN DBMS_RANDOM.VALUE(0, 1) < 0.6 THEN 'Morning' ELSE 'Evening' END;

        v_batch := CASE TRUNC(DBMS_RANDOM.VALUE(1, 5))
                       WHEN 1 THEN 'F22'
                       WHEN 2 THEN 'F23'
                       WHEN 3 THEN 'F24'
                       ELSE 'F25' END;

        v_cgpa := ROUND(DBMS_RANDOM.VALUE(1.80, 4.00), 2);

        INSERT INTO FCIT_Students
        VALUES (3000 + i, 'Student ' || LPAD(i, 3, '0'), v_dept, v_shift, v_batch, v_cgpa);
    END LOOP;
    COMMIT;
END;
/

-----------------------------------------------------------------------
-- Table for Task 3 (Semantic Scholar API metadata)
-----------------------------------------------------------------------

CREATE TABLE Articles_API (
    PaperID        VARCHAR2(100) PRIMARY KEY,
    Title          VARCHAR2(500),
    Authors        VARCHAR2(1000),
    Abstract       CLOB,
    Year           NUMBER(4),
    CitationCount  NUMBER
);

-----------------------------------------------------------------------
-- Check loaded data
-----------------------------------------------------------------------
SELECT Department, COUNT(*) AS Students, ROUND(AVG(CGPA),2) AS AvgCGPA
FROM   FCIT_Students
GROUP  BY Department
ORDER  BY Department;

SELECT Shift, COUNT(*) AS Students FROM FCIT_Students GROUP BY Shift;
SELECT Batch, COUNT(*) AS Students FROM FCIT_Students GROUP BY Batch;
