Option Strict Off
Option Explicit On
Module INI_file
   
    Public LogDefault As LLOG_WRITE
	'Lettura dal file sbarre.ini
	'UPGRADE_ISSUE: Declaring a parameter 'As Any' is not supported. Click for more: 'ms-help://MS.VSCC.v90/dv_commoner/local/redirect.htm?keyword="FAE78A8D-8978-4FD4-8208-5B7324A8F795"'
    Private Declare Function GetPrivateProfileString Lib "kernel32" Alias "GetPrivateProfileStringA" (ByVal lpApplicationName As String, ByVal lpKeyName As String, ByVal lpDefault As String, ByVal lpReturnedString As String, ByVal nSize As Integer, ByVal lpFileName As String) As Integer
	
	Private x As Integer
	Private sEntry, sSection, sDefault As String
	Private sRetBuf, sFileName As String
	Private iLenBuf As Short
	Private sValue As String
	Private sString As String
	
	'UPGRADE_NOTE: default was upgraded to default_Renamed. Click for more: 'ms-help://MS.VSCC.v90/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
	Public Function INI_leggi(ByRef section As String, ByRef entry As String, ByRef default_Renamed As String) As String
		sSection = section
		sEntry = entry
		sDefault = default_Renamed
		sRetBuf = New String(Chr(0), 256) '256 null characters
		iLenBuf = Len(sRetBuf)
        sFileName = My.Application.Info.DirectoryPath & "\livecam.ini"
		
		x = GetPrivateProfileString(sSection, sEntry, sDefault, sRetBuf, iLenBuf, sFileName)
		
		sValue = Left(sRetBuf, x)
		INI_leggi = sValue
	End Function
	
	Public Function INI_carica() As Boolean
		
		On Error Resume Next
			
		DB_conn_string.strDriver = INI_leggi("Database", "driver", "")
		DB_conn_string.strDb = INI_leggi("Database", "db", "")
		DB_conn_string.strServer = INI_leggi("Database", "server", "")
		DB_conn_string.strUid = INI_leggi("Database", "uid", "")
		DB_conn_string.strPw = INI_leggi("Database", "pw", "")
        DB_conn_string.monitor = INI_leggi("Database", "collegamento", "")
        DB_conn_string.secondi = INI_leggi("Database", "secondi", "")

        If Err.Number = 0 Then
            INI_carica = True
        Else
            INI_carica = False
            Err.Clear()
        End If
	End Function
    
	
End Module