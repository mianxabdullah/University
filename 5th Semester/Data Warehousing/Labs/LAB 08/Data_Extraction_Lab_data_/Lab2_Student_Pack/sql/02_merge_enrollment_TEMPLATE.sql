/* Lab 2 - write your MERGE here (Task 5). Python calls this procedure after loading stg.Enrollment. */
USE Lab2DB;
GO
CREATE OR ALTER PROCEDURE dw.usp_MergeEnrollment
    @SourceFile VARCHAR(100)
AS
BEGIN
    SET NOCOUNT ON;

    -- TODO A: stop if stg.Enrollment is empty (why? see the manual).

    -- TODO B: MERGE dw.Enrollment (target) USING the staged rows (source)
    --         ON the business key (RollNo, CourseCode)
    --         WHEN MATCHED AND <something changed>  THEN UPDATE ...
    --         WHEN NOT MATCHED BY TARGET            THEN INSERT ...
    --         WHEN NOT MATCHED BY SOURCE            THEN DELETE
    --         OUTPUT $action, inserted.*, deleted.* ... into dw.Enrollment_ChangeLog

    -- TODO C: return a summary: ChangeType, number of rows, for THIS run only.
END
GO
