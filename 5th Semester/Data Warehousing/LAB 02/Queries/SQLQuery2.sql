SELECT c.CourseName,
sum(CASE WHEN e.Marks >= 50 THEN 1 ELSE 0 END) AS Pass,
sum(CASE WHEN e.Marks < 50 THEN 1 ELSE 0 END) AS Fail
FROM Enrollments e
JOIN Courses c ON e.CourseID = c.CourseID
JOIN Departments d ON c.DeptID = d.DeptID 
WHERE d.DeptName = 'Data Science'
Group by c.CourseName;