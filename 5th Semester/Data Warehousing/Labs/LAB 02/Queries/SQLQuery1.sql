SELECT s.StudentID,s.FullName,e.Marks,
    CASE 
        WHEN e.Marks >= 50 THEN 'Pass'
        ELSE 'Fail'
    END AS Status
FROM Students s
JOIN Enrollments e ON s.StudentID = e.StudentID
JOIN Courses c ON e.CourseID = c.CourseID
WHERE c.CourseName = 'Database Management Systems';