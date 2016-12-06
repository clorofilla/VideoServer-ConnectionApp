Option Strict Off
Option Explicit On
Imports System.Text
Module Varchi_Primarie
    
    Public rsCam As New ADODB.Recordset

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
    End Structure
    Private Structure REPLY
        'UPGRADE_NOTE: InputString was upgraded to InputString_Renamed. Click for more: 'ms-help://MS.VSCC.v90/dv_commoner/local/redirect.htm?keyword="A9E4979A-37FA-4718-9994-97DD76ED70A7"'
        Dim InputString_Renamed As String
        Dim StartCh As String
        Dim StopCh As String
        Dim RemoteAddr As String
        Dim LocalAddr As String
        Dim Code As String
        Dim DataLenght As String
        Dim Data As String
        Dim CRC As String
    End Structure
    Dim strSQL As String
    Public Function Apri_ConnessioneDatabase() As Boolean
        On Error GoTo Fine
        Err.Clear()

       
        If (cnConnection.State <> ADODB.ObjectStateEnum.adStateOpen) Then
            cnConnection.ConnectionString = "driver=" & DB_conn_string.strDriver & ";" & "server=" & DB_conn_string.strServer & ";" & "uid=" & DB_conn_string.strUid & ";" & "pwd=" & DB_conn_string.strPw & ";" & "database=" & DB_conn_string.strDb & ";"
            Call cnConnection.Open()
        End If

Fine:
        If Err.Number = 0 Then
            Apri_ConnessioneDatabase = True
           
        Else
            Apri_ConnessioneDatabase = False
        End If
    End Function

    Public Function Chiudi_ConnessioneDatabase() As Boolean
        On Error GoTo Fine

        If (cnConnection.State <> ADODB.ObjectStateEnum.adStateClosed) Then Call cnConnection.Close()

Fine:
        If Err.Number = 0 Then
            Chiudi_ConnessioneDatabase = True
           
        Else
            Chiudi_ConnessioneDatabase = False
            
        End If
    End Function

    Public Function IP_check(ByRef IP As String) As Boolean
        Dim i As Short
        Dim dot_count As Short = 0
        Dim test_octet As String = ""
        Dim byte_check As Object

        IP = Trim(IP)

        ' make sure the IP long enough before continuing
        If Len(IP) < 8 Then
            IP_check = False
            'Show Message
            '    MsgBox IP & " is Invalid", , "IP Validator"
            Exit Function
        End If

        i = 1
        dot_count = 0
        For i = 1 To Len(IP)
            If Mid(IP, i, 1) = "." Then
                ' increment the dot count and
                ' clear the test octet variable
                dot_count = dot_count + 1
                test_octet = ""
                If i = Len(IP) Then
                    ' we've ended with a dot
                    ' this is not good
                    IP_check = False
                    'Show Message
                    '            MsgBox IP & " is Invalid", , "IP Validator"
                    Exit Function
                End If
            Else
                test_octet = test_octet & Mid(IP, i, 1)
                On Error Resume Next
                'UPGRADE_WARNING: Couldn't resolve default property of object byte_check. Click for more: 'ms-help://MS.VSCC.v90/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
                byte_check = CByte(test_octet)
                If Err.Number Then
                    ' either the value is not numeric
                    ' or exceeds the range of the byte
                    ' data type.
                    IP_check = False
                    Exit Function
                End If
            End If
        Next i
        ' so far, so good
        ' did we get the correct number of dots?
        If dot_count <> 3 Then
            IP_check = False
            Exit Function
        End If
        ' we have a valid IP format!
        IP_check = True
        'Show Message
        '    MsgBox IP & " is Valid", , "IP Validator"
    End Function
End Module