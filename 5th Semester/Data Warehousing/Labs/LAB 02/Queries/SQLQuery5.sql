SELECT StudentID,FullName,AdmissionDate AS RawAdmissionDate,
    SUBSTRING(AdmissionDate, 1, 2) + '/' + 
    SUBSTRING(AdmissionDate, 3, 2) + '/' + 
    SUBSTRING(AdmissionDate, 5, 4) AS FormattedAdmissionDate
FROM Students;