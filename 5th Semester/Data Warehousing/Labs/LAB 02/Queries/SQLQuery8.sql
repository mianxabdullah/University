SELECT 
    StudentID,
    FullName,
    AdmissionDate
FROM Students
WHERE 
    SUBSTRING(AdmissionDate, 1, 2) < 1 OR SUBSTRING(AdmissionDate, 1, 2) > 31
    OR SUBSTRING(AdmissionDate, 3, 2) < 1 OR SUBSTRING(AdmissionDate, 3, 2) > 12
    OR (SUBSTRING(AdmissionDate, 3, 2) = 2 AND SUBSTRING(AdmissionDate, 1, 2) > 29);