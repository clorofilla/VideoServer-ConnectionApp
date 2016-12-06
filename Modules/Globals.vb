Option Strict Off
Option Explicit On
Module Dichiarazioni
	

	Public cnConnection As New ADODB.Connection

	Public Structure LLOG_WRITE
		Dim strLivello As String
		Dim strCartella As String
		Dim strFile As String
		Dim strPeriodo As String
	End Structure
	Public LogDefault As LLOG_WRITE
	Public LogAperture As LLOG_WRITE
	
	Public Structure GGENERAL
        Dim strId As String
        Dim strAvvio_autom As String
	End Structure
	Public Identificativi As GGENERAL
	
	Public Structure QQUEUE
		Dim strEmerg_not As String
	End Structure
	
	Public Structure DDATABASE
		Dim strDriver As String
		Dim strProvider As String
		Dim strPSI As String
		Dim strExt_prop As String
		Dim strDb As String
		Dim strServer As String
		Dim strUid As String
		Dim strPw As String
		Dim strPort As String
		Dim strOption As String
        Dim monitor As String
        Dim host As String
        Dim host2 As String
        Dim host3 As String
        Dim secondi As Integer
    End Structure

    Public DB_conn_string As DDATABASE
	
	Public Structure WWINSOCK
		Dim strPorta As String
		Dim strTentativi As String 'Valore letto dal file
		Dim intTentativi As Short 'Valore convertito dal sw
        Dim timeout As Long
        Dim timeout_risposta As Long
    End Structure
	Public SocketIP As WWINSOCK
	
	Public Structure LLOG_PATHS
		Dim strDefault As String
		Dim strAperture As String
	End Structure
	Public Log_path As LLOG_PATHS 'Percorsi dei 3 file di log
	
	Public Structure LLOG_LEVELS
		Dim intDefault As Short
		Dim intAperture As Short
	End Structure
	Public Log_livello As LLOG_LEVELS 'Livelli di debug dei 3 file
End Module