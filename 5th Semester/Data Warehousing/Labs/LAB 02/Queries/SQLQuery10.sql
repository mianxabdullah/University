SELECT StudentID,FullName,
    SUBSTRING(FullName, 1, CHARINDEX(' ', FullName) - 1) AS FirstName,
    SUBSTRING(FullName, CHARINDEX(' ', FullName) + 1, LEN(FullName)) AS LastName
FROM Students;