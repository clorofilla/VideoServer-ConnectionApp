Option Strict Off
Option Explicit On
Module Log
	
	Public Sub Log_scrivi(ByRef Log_time As String, ByRef Log_string As String)
		Dim l As Integer
		On Error Resume Next
		l = FreeFile
		FileOpen(l, Log_path.strDefault, OpenMode.Append)
		PrintLine(l, Log_time, Log_string)
		FileClose(l)
		If Err.Number <> 0 Then Err.Clear()
	End Sub
	
	Public Sub Log_aperture(ByRef Log_string As String)
		Dim l As Integer
		On Error Resume Next
		l = FreeFile
		FileOpen(l, Log_path.strAperture, OpenMode.Append)
		PrintLine(l, CStr(Now), Log_string)
		FileClose(l)
		If Err.Number <> 0 Then Err.Clear()
	End Sub
End Module