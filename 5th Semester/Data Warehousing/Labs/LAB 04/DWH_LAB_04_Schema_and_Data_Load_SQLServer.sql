-- DWH LAB 04 - Indexed (Materialized) Views
-- BS Data Science DSF24 Afternoon
-- Schema and Data Load Script - MICROSOFT SQL SERVER (T-SQL) version
-- (converted from the Oracle script: VARCHAR2->VARCHAR, NUMBER->INT/DECIMAL,
--  DBMS_RANDOM->NEWID()/CHECKSUM(), PL/SQL blocks->T-SQL WHILE loops)
--
-- Run in SSMS / Azure Data Studio. Use a scratch database.
-- Privileges needed: CREATE TABLE, CREATE VIEW, ALTER on schema dbo.

-- SET options required for creating/maintaining indexed views
SET ANSI_NULLS ON;
SET ANSI_PADDING ON;
SET ANSI_WARNINGS ON;
SET ARITHABORT ON;
SET CONCAT_NULL_YIELDS_NULL ON;
SET QUOTED_IDENTIFIER ON;
SET NUMERIC_ROUNDABORT OFF;
SET NOCOUNT ON;
GO

-- Optional cleanup if objects already exist.
-- Drop your indexed views / summary tables first (schema-bound views block table drops):
-- DROP VIEW IF EXISTS dbo.MV_Course_Summary;  ... (all MV_ views)
-- DROP TABLE IF EXISTS dbo.Course_Results;
-- DROP TABLE IF EXISTS dbo.Students;

-----------------------------------------------------------------------
-- Tables
-----------------------------------------------------------------------
CREATE TABLE dbo.Students (
    StudentID       INT           NOT NULL PRIMARY KEY,
    StudentName     VARCHAR(100)  NOT NULL,
    DegreeProgram   VARCHAR(10)   NOT NULL,   -- BS / MS / PhD
    DegreeTitle     VARCHAR(50)   NOT NULL,   -- Data Science / Computer Science / Software Engineering
    Section         VARCHAR(20)   NOT NULL,   -- Fall22 ... Fall26
    EnrollmentDate  DATE          NOT NULL
);
GO

CREATE TABLE dbo.Course_Results (
    ResultID        INT           NOT NULL PRIMARY KEY,
    StudentID       INT           NOT NULL,
    CourseName      VARCHAR(60)   NOT NULL,
    Semester        VARCHAR(20)   NOT NULL,   -- Fall22, Spring23, ... Spring26
    Marks           DECIMAL(5,2)  NULL,
    GradePoints     DECIMAL(3,2)  NULL,
    CreditHours     INT           NOT NULL,
    AttendancePct   DECIMAL(5,2)  NOT NULL,
    CONSTRAINT FK_Results_Student FOREIGN KEY (StudentID)
        REFERENCES dbo.Students(StudentID)
);
GO

-----------------------------------------------------------------------
-- Data: 100 students (Fall22 - Fall26 intakes)
-----------------------------------------------------------------------
DECLARE @i INT = 1, @r FLOAT, @n INT, @prog VARCHAR(10), @title VARCHAR(50),
        @year INT, @sec VARCHAR(20), @enroll DATE;

WHILE @i <= 100
BEGIN
    SET @r = (ABS(CHECKSUM(NEWID())) % 10000) / 10000.0;
    SET @prog = CASE WHEN @r < 0.65 THEN 'BS'
                     WHEN @r < 0.90 THEN 'MS'
                     ELSE 'PhD' END;

    SET @n = ABS(CHECKSUM(NEWID())) % 3;
    SET @title = CASE @n WHEN 0 THEN 'Data Science'
                         WHEN 1 THEN 'Computer Science'
                         ELSE 'Software Engineering' END;

    SET @year   = 2022 + ABS(CHECKSUM(NEWID())) % 5;          -- 2022 .. 2026
    SET @sec    = 'Fall' + RIGHT(CAST(@year AS VARCHAR(4)), 2);
    SET @enroll = DATEFROMPARTS(@year, 8, 1 + ABS(CHECKSUM(NEWID())) % 28);

    INSERT INTO dbo.Students (StudentID, StudentName, DegreeProgram, DegreeTitle, Section, EnrollmentDate)
    VALUES (1000 + @i, 'Student ' + RIGHT('000' + CAST(@i AS VARCHAR(3)), 3),
            @prog, @title, @sec, @enroll);

    SET @i += 1;
END;
GO

-----------------------------------------------------------------------
-- Data: ~600 course results, Fall22 - Spring26.
-- A student only gets results for semesters on or after their intake, so
-- Fall26 students have no results yet. Fall26 results are left for you to
-- insert during the lab (use StudentID >= 2001 and ResultID >= 9001 for
-- any new rows so they do not clash with generated data).
-----------------------------------------------------------------------
DECLARE @j INT = 1, @sid INT, @start INT, @idx INT, @n INT,
        @sem VARCHAR(20), @course VARCHAR(60),
        @marks DECIMAL(5,2), @gp DECIMAL(3,2);

WHILE @j <= 600
BEGIN
    -- pick a random student enrolled before 2026
    SELECT TOP 1 @sid = StudentID,
                 @start = (YEAR(EnrollmentDate) - 2022) * 2 + 1
    FROM   dbo.Students
    WHERE  EnrollmentDate < '2026-01-01'
    ORDER  BY NEWID();

    -- semester index: 1 = Fall22, 2 = Spring23, ... 8 = Spring26
    SET @idx = @start + ABS(CHECKSUM(NEWID())) % (9 - @start);
    SET @sem = CASE @idx
                   WHEN 1 THEN 'Fall22'  WHEN 2 THEN 'Spring23'
                   WHEN 3 THEN 'Fall23'  WHEN 4 THEN 'Spring24'
                   WHEN 5 THEN 'Fall24'  WHEN 6 THEN 'Spring25'
                   WHEN 7 THEN 'Fall25'  ELSE 'Spring26' END;

    SET @n = ABS(CHECKSUM(NEWID())) % 8;
    SET @course = CASE @n
                      WHEN 0 THEN 'Data Structures'   WHEN 1 THEN 'Database Systems'
                      WHEN 2 THEN 'Data Warehousing'  WHEN 3 THEN 'Machine Learning'
                      WHEN 4 THEN 'Operating Systems' WHEN 5 THEN 'Statistics'
                      WHEN 6 THEN 'Software Design'   ELSE 'Algorithm Analysis' END;

    SET @marks = 35 + (ABS(CHECKSUM(NEWID())) % 6300) / 100.0;   -- 35.00 .. 97.99

    SET @gp = CASE WHEN @marks >= 85 THEN 4.00
                   WHEN @marks >= 80 THEN 3.67
                   WHEN @marks >= 75 THEN 3.33
                   WHEN @marks >= 70 THEN 3.00
                   WHEN @marks >= 65 THEN 2.67
                   WHEN @marks >= 60 THEN 2.33
                   WHEN @marks >= 55 THEN 2.00
                   WHEN @marks >= 50 THEN 1.00
                   ELSE 0.00 END;

    INSERT INTO dbo.Course_Results
        (ResultID, StudentID, CourseName, Semester, Marks, GradePoints, CreditHours, AttendancePct)
    VALUES (5000 + @j, @sid, @course, @sem, @marks, @gp,
            2 + ABS(CHECKSUM(NEWID())) % 3,                          -- 2, 3 or 4 credit hours
            55 + (ABS(CHECKSUM(NEWID())) % 4501) / 100.0);           -- attendance % (55.00 - 100.00)

    SET @j += 1;
END;
GO

-----------------------------------------------------------------------
-- Check loaded data
-----------------------------------------------------------------------
SELECT DegreeProgram, COUNT(*) AS Students FROM dbo.Students GROUP BY DegreeProgram ORDER BY 1;
SELECT Section,       COUNT(*) AS Students FROM dbo.Students GROUP BY Section       ORDER BY 1;
SELECT COUNT(*) AS TotalResults FROM dbo.Course_Results;
SELECT Semester,      COUNT(*) AS Results  FROM dbo.Course_Results GROUP BY Semester ORDER BY 1;
GO
