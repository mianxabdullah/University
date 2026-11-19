-- Lab 2 : source system (fee database) + DW tables
-- Run in SSMS. Creates database Lab2DB with schemas src, stg, dw.

IF DB_ID('Lab2DB') IS NULL CREATE DATABASE Lab2DB;
GO
USE Lab2DB;
GO
IF SCHEMA_ID('src') IS NULL EXEC('CREATE SCHEMA src');
IF SCHEMA_ID('stg') IS NULL EXEC('CREATE SCHEMA stg');
IF SCHEMA_ID('dw')  IS NULL EXEC('CREATE SCHEMA dw');
GO

-- ===== SOURCE SYSTEM: student fee (OLTP) =====
DROP TABLE IF EXISTS src.Student_Fee;
CREATE TABLE src.Student_Fee (
    RollNo       VARCHAR(10)  NOT NULL PRIMARY KEY,
    StudentName  VARCHAR(60)  NOT NULL,
    Semester     VARCHAR(12)  NOT NULL,
    TuitionFee   INT          NOT NULL,
    PaidAmount   INT          NOT NULL,
    FeeStatus    VARCHAR(10)  NOT NULL   -- Paid / Partial / Unpaid
);

INSERT INTO src.Student_Fee (RollNo, StudentName, Semester, TuitionFee, PaidAmount, FeeStatus) VALUES
('23F-0101', 'Ayesha Khan', 'Fall 2026', 185000, 185000, 'Paid'),
('23F-0102', 'Muhammad Ali Raza', 'Fall 2026', 185000, 120000, 'Partial'),
('23F-0103', 'Fatima Noor', 'Fall 2026', 178000, 178000, 'Paid'),
('23F-0104', 'Hamza Tariq', 'Fall 2026', 185000, 90000, 'Partial'),
('23F-0105', 'Zainab Hussain', 'Fall 2026', 192000, 192000, 'Paid'),
('23F-0106', 'Usman Farooq', 'Fall 2026', 178000, 100000, 'Partial'),
('23F-0107', 'Hira Shahid', 'Fall 2026', 192000, 192000, 'Paid'),
('23F-0108', 'Bilal Ahmed', 'Fall 2026', 185000, 185000, 'Paid'),
('23F-0109', 'Maryam Iqbal', 'Fall 2026', 178000, 0, 'Unpaid'),
('23F-0110', 'Ahmed Hassan', 'Fall 2026', 192000, 150000, 'Partial'),
('23F-0111', 'Sana Javed', 'Fall 2026', 185000, 185000, 'Paid'),
('23F-0112', 'Omer Siddiqui', 'Fall 2026', 178000, 178000, 'Paid'),
('23F-0113', 'Iqra Aslam', 'Fall 2026', 192000, 96000, 'Partial'),
('23F-0114', 'Saad Malik', 'Fall 2026', 185000, 185000, 'Paid');
GO

-- ===== STAGING (truncated and reloaded on every run) =====
DROP TABLE IF EXISTS stg.Enrollment;
CREATE TABLE stg.Enrollment (
    RollNo       VARCHAR(10)  NOT NULL,
    StudentName  VARCHAR(60)  NOT NULL,
    CourseCode   VARCHAR(10)  NOT NULL,
    CourseTitle  VARCHAR(60)  NOT NULL,
    CreditHours  INT          NOT NULL,
    Section      VARCHAR(5)   NULL,          -- blank in the PDF = NULL (To Be Announced)
    SourceFile   VARCHAR(100) NOT NULL
);

DROP TABLE IF EXISTS stg.Challan;
CREATE TABLE stg.Challan (
    ChallanNo    VARCHAR(20)  NOT NULL,
    RollNo       VARCHAR(10)  NOT NULL,
    PenaltyFee   INT          NOT NULL,
    SourceImage  VARCHAR(100) NOT NULL
);

-- ===== DATA WAREHOUSE: enrollment target + change log =====
DROP TABLE IF EXISTS dw.Enrollment;
CREATE TABLE dw.Enrollment (
    RollNo       VARCHAR(10)  NOT NULL,
    CourseCode   VARCHAR(10)  NOT NULL,
    StudentName  VARCHAR(60)  NOT NULL,
    CourseTitle  VARCHAR(60)  NOT NULL,
    CreditHours  INT          NOT NULL,
    Section      VARCHAR(5)   NULL,
    SourceFile   VARCHAR(100) NOT NULL,          -- file that last touched this row
    InsertedAt   DATETIME2    NOT NULL DEFAULT SYSDATETIME(),
    UpdatedAt    DATETIME2    NULL,
    CONSTRAINT PK_dw_Enrollment PRIMARY KEY (RollNo, CourseCode)   -- business key
);

DROP TABLE IF EXISTS dw.Enrollment_ChangeLog;
CREATE TABLE dw.Enrollment_ChangeLog (
    ChangeID         INT IDENTITY(1,1) PRIMARY KEY,
    ChangeType       NVARCHAR(10) NOT NULL,      -- INSERT / UPDATE / DELETE  (from $action)
    RollNo           VARCHAR(10)  NOT NULL,
    CourseCode       VARCHAR(10)  NOT NULL,
    Old_Section      VARCHAR(5)   NULL,
    New_Section      VARCHAR(5)   NULL,
    Old_CreditHours  INT          NULL,
    New_CreditHours  INT          NULL,
    SourceFile       VARCHAR(100) NOT NULL,
    ChangedAt        DATETIME2    NOT NULL DEFAULT SYSDATETIME()
);
GO

SELECT 'src.Student_Fee' AS TableName, COUNT(*) AS [Rows] FROM src.Student_Fee;
