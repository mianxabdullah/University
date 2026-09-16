SELECT RegistrationDate AS RawRegistrationDate,
    SUBSTRING(RegistrationDate, 5, 4) + '/' + 
    SUBSTRING(RegistrationDate, 3, 2) + '/' + 
    SUBSTRING(RegistrationDate, 1, 2) AS FormattedRegistrationDate
FROM Enrollments ;