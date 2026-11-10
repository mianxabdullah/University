USE IndexDB;
GO

-- Scale 1:

--Task1:
-- Turn on statistics reporting
SET STATISTICS TIME ON;
GO

-- Paste your query here (e.g., Query 1)
SELECT student_id, first_name, last_name, email, enrollment_date, date_of_birth
FROM Students
WHERE YEAR(enrollment_date) = 2023;
GO

-- Turn off statistics reporting when done
SET STATISTICS TIME OFF;
GO

--Task2:
-- Turn on statistics reporting
SET STATISTICS TIME ON;
GO

-- Paste your query here (e.g., Query 2)
SELECT DISTINCT s.email
FROM Students s
JOIN Enrollments e ON s.student_id = e.student_id
JOIN Courses c ON e.course_id = c.course_id
WHERE c.teacher_id = 50;
GO

-- Turn off statistics reporting when done
SET STATISTICS TIME OFF;
GO

--Task3:
-- Turn on statistics reporting
SET STATISTICS TIME ON;
GO

-- Paste your query here (e.g., Query 3)
SELECT DISTINCT t.first_name, t.last_name
FROM Teachers t
JOIN Courses c ON t.teacher_id = c.teacher_id
WHERE c.course_name LIKE '%Advanced%';
GO

-- Turn off statistics reporting when done
SET STATISTICS TIME OFF;
GO

--Task4:
-- Turn on statistics reporting
SET STATISTICS TIME ON;
GO

-- Paste your query here (e.g., Query 4)
SELECT d.department_name, COUNT(c.course_id) AS total_courses
FROM Departments d
LEFT JOIN Teachers t ON d.department_id = t.department_id
LEFT JOIN Courses c ON t.teacher_id = c.teacher_id
GROUP BY d.department_id, d.department_name;
GO

-- Turn off statistics reporting when done
SET STATISTICS TIME OFF;
GO

--Task5:
-- Turn on statistics reporting
SET STATISTICS TIME ON;
GO

-- Paste your query here (e.g., Query 5)
SELECT TOP 10 
    s.first_name, 
    s.last_name, 
    AVG(CAST(e.grade AS FLOAT)) AS average_grade
FROM Students s
JOIN Enrollments e ON s.student_id = e.student_id
WHERE e.semester = 'Spring 2025'
GROUP BY s.student_id, s.first_name, s.last_name
ORDER BY average_grade DESC;
GO

-- Turn off statistics reporting when done
SET STATISTICS TIME OFF;
GO
