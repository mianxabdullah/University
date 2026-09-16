SELECT s.StudentID,s.FullName,AVG(e.Marks) AS AverageMarks,
 CASE WHEN AVG(e.marks)>=80 THEN 'YES'
 ELSE 'NO'
 END AS Eligible
FROM Students s
JOIN Enrollments e ON s.StudentID = e.StudentID
GROUP BY s.StudentID, s.FullName
HAVING AVG(e.Marks) >= 80;