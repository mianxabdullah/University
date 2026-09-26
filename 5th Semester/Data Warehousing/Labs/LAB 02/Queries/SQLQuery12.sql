SELECT t.TeacherID,t.TeacherName,
COUNT(c.CourseID) AS TotalCoursesTaught
FROM Teachers t
JOIN Departments d ON t.DeptID = d.DeptID
LEFT JOIN Courses c ON t.TeacherID = c.TeacherID
WHERE d.DeptName = 'Data Science'
GROUP BY t.TeacherID, t.TeacherName;