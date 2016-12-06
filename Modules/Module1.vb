Option Strict Off
Option Explicit On
Imports VB = Microsoft.VisualBasic
Imports System.Runtime.InteropServices

Module Module1

    Public Declare Function ZLNET_Login Lib "zlnetsdk.dll" (ByVal pchDVRIP As String, ByVal wDVRPort As Integer, ByVal pchUserName As String, ByVal pchPassword As String, ByRef lpDeviceInfo As NET_DEVICEINFO, ByRef error_Renamed As NET_RET_ERROR) As Integer
    
    Public Declare Function ZLNET_Logout Lib "zlnetsdk.dll" (ByVal lLoginID As Integer) As Integer

    'Realplay API
    Public Declare Function ZLNET_RealPlay Lib "zlnetsdk.dll" (ByVal lLoginID As Integer, ByVal nChannelID As Integer, ByVal hwnd As Integer) As Integer

    Public Declare Function ZLNET_RealPlayEx Lib "zlnetsdk.dll" (ByVal lLoginID As Integer, ByVal nChannelID As Integer, ByVal hwnd As Integer, ByVal rType As Integer) As Integer

    'Stop Realplay
    Public Declare Function ZLNET_StopRealPlayEx Lib "zlnetsdk.dll" (ByVal lLoginID As Integer) As Integer

    Public Declare Sub ZLNET_Cleanup Lib "zlnetsdk.dll" ()

    'Alarm Liten API
    Public Declare Function ZLNET_StartListen Lib "zlnetsdk.dll" (ByVal lLoginID As Integer) As Integer

    'Mess callback API
    Public Declare Function ZLNET_SetDVRMessCallBack Lib "zlnetsdk.dll" (ByVal fMessCallBack As MessFunc, ByVal dwUser As Integer) As Integer
    ' [DllImport("dhnetsdk.dll")]
    'private static extern bool CLIENT_CapturePicture(int hPlayHandle, string pchPicFileName);
    Public Declare Function ZLNET_CapturePicture Lib "zlnetsdk.dll" (ByVal hPlayHandle As Integer, ByVal pchPicFileName As String) As Integer


End Module