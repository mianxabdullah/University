SELECT s.StudentID,s.FullName,
	STRING_AGG(c.CourseName, ', ') AS EnrolledCourses
FROM Students s
JOIN Enrollments e ON s.StudentID = e.StudentID
JOIN Courses c ON e.CourseID = c.CourseID
GROUP BY s.StudentID, s.FullName;