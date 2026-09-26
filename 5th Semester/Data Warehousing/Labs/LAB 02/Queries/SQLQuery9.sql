SELECT 
    StudentID,
    FullName,
    PhoneNumbers,
    SUBSTRING(PhoneNumbers, 1, 11) AS PrimaryPhoneNumber
FROM Students;