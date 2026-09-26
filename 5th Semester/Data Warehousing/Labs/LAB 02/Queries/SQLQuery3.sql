SELECT s.FullName,e.Marks,c.CourseName,
    CASE 
        WHEN e.Marks >= 85 THEN 'A'
        WHEN e.Marks >= 70 THEN 'B'
        WHEN e.Marks >= 55 THEN 'C'
        WHEN e.Marks >= 40 THEN 'D'
        ELSE 'F'
    END AS Status
FROM Students s
JOIN Enrollments e ON s.StudentID = e.StudentID
JOIN Courses c ON e.CourseID = c.CourseID;