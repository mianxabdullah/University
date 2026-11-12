USE IndexDB;
GO

-- 1. On Students: Index for Query 1 filtering on enrollment_date
CREATE NONCLUSTERED INDEX IX_Students_EnrollmentDate 
ON Students(enrollment_date);
GO

-- 2. On Enrollments: Indexes for joining and filtering on student_id, course_id, and semester
CREATE NONCLUSTERED INDEX IX_Enrollments_StudentId 
ON Enrollments(student_id);
GO

CREATE NONCLUSTERED INDEX IX_Enrollments_CourseId 
ON Enrollments(course_id);
GO

CREATE NONCLUSTERED INDEX IX_Enrollments_Semester 
ON Enrollments(semester);
GO

-- 3. On Courses: Indexes for joining and searching on teacher_id and course_name
CREATE NONCLUSTERED INDEX IX_Courses_TeacherId 
ON Courses(teacher_id);
GO

CREATE NONCLUSTERED INDEX IX_Courses_CourseName 
ON Courses(course_name);
GO

-- 4. On Teachers: Index for joining on department_id
CREATE NONCLUSTERED INDEX IX_Teachers_DepartmentId 
ON Teachers(department_id);
GO