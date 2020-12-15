USE [ExceptionsDB]
GO

SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO

ALTER PROCEDURE [dbo].[AddErrorMessage]
    @exception NVARCHAR(50),
    @message NVARCHAR(max),
    @time datetime2(7)
AS

BEGIN

	INSERT INTO DBO.Logs(Exception, Message, Time) 
	VALUES(@exception, @message, @time)

	SELECT SCOPE_IDENTITY()
END;