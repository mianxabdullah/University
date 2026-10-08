-- Task 1:
CREATE MATERIALIZED VIEW mv_course_summary
BUILD IMMEDIATE
REFRESH COMPLETE ON DEMAND AS
SELECT 
    CourseName,
    ROUND(AVG(Marks), 2) AS AvgMarks,
    ROUND(AVG(GradePoints), 2) AS AvgGradePoints,
    COUNT(*) AS TotalResults
FROM Course_Results
GROUP BY CourseName;



-- Task 2:
CREATE MATERIALIZED VIEW mv_semester_summary
BUILD IMMEDIATE
REFRESH COMPLETE ON DEMAND AS
SELECT 
    Semester,
    COUNT(*) AS TotalResults,
    SUM(CreditHours) AS TotalCreditHours
FROM Course_Results
GROUP BY Semester;



-- Task 3:
CREATE MATERIALIZED VIEW highest_lowest_marks
BUILD IMMEDIATE
REFRESH COMPLETE ON DEMAND AS
SELECT 
    CourseName,
    MAX(Marks) AS HighestMarks,
    MIN(Marks) AS LowestMarks
FROM Course_Results
GROUP BY CourseName;



-- Task 4:
CREATE MATERIALIZED VIEW mv_program_performance
BUILD IMMEDIATE
REFRESH COMPLETE ON DEMAND AS
SELECT 
    s.DegreeProgram,
    s.DegreeTitle,
    COUNT(*) AS TotalResults,
    ROUND(AVG(r.GradePoints), 2) AS AvgGradePoints
FROM Course_Results r
JOIN Students s ON r.StudentID = s.StudentID
GROUP BY s.DegreeProgram, s.DegreeTitle;



-- Task 5:
CREATE MATERIALIZED VIEW mv_section_low_attendance
BUILD IMMEDIATE
REFRESH COMPLETE ON DEMAND AS
SELECT 
    s.Section,
    COUNT(r.ResultID) AS LowAttendanceCount,
    ROUND(AVG(r.Marks), 2) AS AvgMarks
FROM Students s
JOIN Course_Results r ON s.StudentID = r.StudentID
WHERE r.AttendancePct < 75
GROUP BY s.Section;



-- Task 6:
CREATE MATERIALIZED VIEW mv_enrollment_semester_perf
BUILD IMMEDIATE
REFRESH COMPLETE ON DEMAND AS
SELECT 
    EXTRACT(YEAR FROM s.EnrollmentDate) AS EnrollmentYear,
    r.Semester,
    COUNT(r.ResultID) AS TotalResults,
    ROUND(AVG(r.GradePoints), 2) AS AvgGradePoints
FROM Students s
JOIN Course_Results r ON s.StudentID = r.StudentID
GROUP BY EXTRACT(YEAR FROM s.EnrollmentDate), r.Semester;



-- Task 7:
CREATE MATERIALIZED VIEW mv_grade_distribution
BUILD IMMEDIATE
REFRESH COMPLETE ON DEMAND AS
SELECT 
    s.DegreeTitle,
    CASE 
        WHEN r.Marks >= 85 THEN 'A'
        WHEN r.Marks >= 70 THEN 'B'
        WHEN r.Marks >= 60 THEN 'C'
        WHEN r.Marks >= 50 THEN 'D'
        ELSE 'F'
    END AS LetterGrade,
    COUNT(r.ResultID) AS ResultCount
FROM Students s
JOIN Course_Results r ON s.StudentID = r.StudentID
GROUP BY s.DegreeTitle, 
         CASE 
             WHEN r.Marks >= 85 THEN 'A'
             WHEN r.Marks >= 70 THEN 'B'
             WHEN r.Marks >= 60 THEN 'C'
             WHEN r.Marks >= 50 THEN 'D'
             ELSE 'F'
         END;
	

--Task 8:
SELECT s.DegreeProgram, s.DegreeTitle, AVG(cr.GradePoints), COUNT(cr.ResultID) 
FROM STUDENTS s JOIN COURSE_RESULTS cr ON s.StudentID = cr.StudentID 
GROUP BY s.DegreeProgram, s.DegreeTitle

SELECT *
FROM MV_PROGRAM_PERFORMANCE



--Task 9:
BEGIN
   DBMS_MVIEW.REFRESH('MV_PROGRAM_PERFORMANCE', 'C');
   DBMS_MVIEW.REFRESH('MV_LOW_ATTENDANCE_SECTION', 'C');
END;

SELECT MVIEW_NAME, STALENESS, LAST_REFRESH_DATE 
FROM USER_MVIEWS 
WHERE MVIEW_NAME IN ('MV_PROGRAM_PERFORMANCE', 'MV_LOW_ATTENDANCE_SECTION')



--Task10:	
UPDATE STUDENTS SET Section = 'Fall26' WHERE StudentID = 1001
SELECT MVIEW_NAME, STALENESS FROM USER_MVIEWS


--Task 11:
CREATE MATERIALIZED VIEW LOG ON COURSE_RESULTS
WITH ROWID, SEQUENCE (StudentID, CourseName, Semester, Marks, GradePoints, CreditHours, AttendancePct)
INCLUDING NEW VALUES



--Task 12:
CREATE MATERIALIZED VIEW MV_FAST_SEMESTER_STATS
REFRESH FAST ON DEMAND AS
SELECT 
    Semester,
    COUNT(*) AS Total_Count,
    SUM(Marks) AS Sum_Marks,
    COUNT(Marks) AS Count_Marks
FROM COURSE_RESULTS
GROUP BY Semester

INSERT INTO COURSE_RESULTS VALUES (9011, 2001, 'Machine Learning', 'Fall26', 85.00, 4.00, 3, 90.00)
INSERT INTO COURSE_RESULTS VALUES (9012, 2002, 'Data Warehousing', 'Fall26', 95.00, 4.00, 3, 98.00)

BEGIN
   DBMS_MVIEW.REFRESH('MV_FAST_SEMESTER_STATS', 'F');
END;

SELECT Semester, Total_Count, Sum_Marks / Count_Marks AS Avg_Marks FROM MV_FAST_SEMESTER_STATS;



--Task 13:
CREATE MATERIALIZED VIEW MV_FAIL_AVG
REFRESH FAST ON DEMAND AS
SELECT 
    Semester,
    AVG(Marks) AS Avg_Marks
FROM COURSE_RESULTS
GROUP BY Semester



--Task14:
CREATE MATERIALIZED VIEW LOG ON STUDENTS
WITH ROWID, SEQUENCE (StudentID, StudentName, DegreeProgram, DegreeTitle, Section, EnrollmentDate)
INCLUDING NEW VALUES

CREATE MATERIALIZED VIEW MV_FAST_JOIN_SUCCESS
REFRESH FAST ON DEMAND AS
SELECT 
    s.ROWID AS student_rowid,
    cr.ROWID AS result_rowid,
    s.StudentID,
    s.StudentName,
    s.DegreeProgram,
    cr.CourseName,
    cr.GradePoints
FROM STUDENTS s JOIN COURSE_RESULTS cr ON s.StudentID = cr.StudentID


INSERT INTO COURSE_RESULTS VALUES (9013, 1001, 'Statistics', 'Fall26', 88.00, 3.67, 3, 92.00)

BEGIN
   DBMS_MVIEW.REFRESH('MV_FAST_JOIN_SUCCESS', 'F');
END;

SELECT * FROM MV_FAST_JOIN_SUCCESS WHERE StudentID = 1001 AND CourseName = 'Statistics'




-- Task15:
CREATE MATERIALIZED VIEW MV_COMMIT_REFRESH
REFRESH FAST ON COMMIT AS
SELECT 
    Semester,
    COUNT(*) AS Total_Results
FROM COURSE_RESULTS
GROUP BY Semester

BEGIN
   INSERT INTO COURSE_RESULTS VALUES (9014, 1002, 'Operating Systems', 'Fall26', 82.00, 3.33, 3, 85.00);
   COMMIT;
END;


SELECT * FROM MV_COMMIT_REFRESH WHERE Semester = 'Fall26'
