SELECT s.FullName,e.RegistrationDate,
    SUBSTRING(RegistrationDate, 5, 4) AS RegistrationYear
FROM Students s
JOIN Enrollments e ON s.StudentID = e.StudentID
WHERE SUBSTRING(RegistrationDate, 5, 4) = '2023';