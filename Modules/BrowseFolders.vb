Option Strict Off
Option Explicit On
Module BrowseFolders
	
	Private Const BIF_RETURNONLYFSDIRS As Integer = &H1 'Uniquement des répertoire
	Private Const BIF_DONTGOBELOWDOMAIN As Integer = &H2 'Domaine globale intredit
	Private Const BIF_STATUSTEXT As Integer = &H4 'Zone de saisie autorisée
	Private Const BIF_RETURNFSANCESTORS As Integer = &H8
	Private Const BIF_EDITBOX As Integer = &H10 'Zone de saisie autorisée
	Private Const BIF_VALIDATE As Integer = &H20 'insist on valid result (or CANCEL)
	Private Const BIF_BROWSEFORCOMPUTER As Integer = &H1000 'Uniquement des PCs.
	Private Const BIF_BROWSEFORPRINTER As Integer = &H2000 'Uniquement des imprimantes
	Private Const BIF_BROWSEINCLUDEFILES As Integer = &H4000 'Browsing for Everything
	
	Private Const MAX_PATH As Short = 260
	
	'Types
	Private Structure T_BROWSEINFO
		Dim HwndOwner As Integer
		Dim pIDLRoot As Integer
		Dim pszDisplayName As Integer
		Dim lpszTitle As Integer
		Dim ulFlags As Integer
		Dim lpfnCallback As Integer
		Dim lParam As Integer
		Dim iImage As Integer
	End Structure
	
	Private Declare Function SHBrowseForFolder Lib "shell32" (ByRef lpbi As T_BROWSEINFO) As Integer
	
	Private Declare Function SHGetPathFromIDList Lib "shell32" (ByVal pidList As Integer, ByVal lpBuffer As String) As Integer
	
	Private Declare Function lstrcat Lib "kernel32"  Alias "lstrcatA"(ByVal lpString1 As String, ByVal lpString2 As String) As Integer
	
	
	Public Function BrowseFolder(ByVal HwndOwner As Integer, ByRef Titre As String) As String
		
		Dim lpIDList As Integer
		Dim sBuffer As String
		Dim BrowseInfo As T_BROWSEINFO
		

		BrowseFolder = ""
		With BrowseInfo
			.HwndOwner = HwndOwner
			.lpszTitle = lstrcat(Titre, "")
			.ulFlags = BIF_RETURNONLYFSDIRS
		End With
		

		lpIDList = SHBrowseForFolder(BrowseInfo)
		

		If (lpIDList) Then
			sBuffer = Space(MAX_PATH)
			SHGetPathFromIDList(lpIDList, sBuffer)
			sBuffer = Left(sBuffer, InStr(sBuffer, vbNullChar) - 1)
			BrowseFolder = sBuffer
		End If
	End Function
End Module