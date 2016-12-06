Option Strict Off
Option Explicit On
Module Module2
	
	Public Structure NET_DEVICEINFO '设备的结构体
		'UPGRADE_WARNING: Fixed-length string size must fit in the buffer. Click for more: 'ms-help://MS.VSCC.v90/dv_commoner/local/redirect.htm?keyword="3C1E4426-0B80-443E-B943-0627CD55D48B"'
		<VBFixedString(48),System.Runtime.InteropServices.MarshalAs(System.Runtime.InteropServices.UnmanagedType.ByValArray,SizeConst:=48)> Public sSerialNumber() As Char
		Dim byAlarmInPortNum As Byte
		Dim byAlarmOutPortNum As Byte
		Dim byDiskNum As Byte
		Dim byDVRType As Byte
		Dim byChanNum As Byte
	End Structure
	
	Public Structure NET_RET_ERROR
		Dim errcode As Short
	End Structure
	
	'初始化回调函数
    'Public Delegate Sub IniFunc(ByVal lLoginID As Int64, ByVal pchDVRIP As Integer, ByVal nDVRPort As Integer, ByVal dwUser As Integer)
    'Form1.Text1.Text = CStr(lLoginID)
    'End Sub
    Public Delegate Sub DisConnectFunc(ByVal lLoginID As Long, ByVal pchDVRIP As String, ByVal nDVRPort As Long, ByVal dwUser As String)
    Public Delegate Sub MessFunc(ByVal lCommand As Integer, ByVal lLoginID As Integer, ByVal pBuf As Integer, ByVal dwBufLen As Integer, ByVal pchDVRIP As Integer, ByVal nDVRPort As Integer, ByVal dwUser As Integer)


    'Form1.Text1.Text = CStr(lLoginID)
    'Form1.Text2.Text = CStr(pBuf)
    'Form1.Text3.Text = CStr(pchDVRIP)

    ' End Sub

    'Public Sub MessFunc(ByVal lCommand As Integer, ByVal lLoginID As Integer, ByVal pBuf As Integer, ByVal dwBufLen As Integer, ByVal pchDVRIP As Integer, ByVal nDVRPort As Integer, ByVal dwUser As Integer)


    '    Form1.Text1.Text = CStr(lLoginID)
    '    Form1.Text2.Text = CStr(pBuf)
    '    Form1.Text3.Text = CStr(pchDVRIP)

    'End Sub


    '回调函数指针传入
    Public Function PtrToLong(ByVal func As Long) As Long
        PtrToLong = func
    End Function
End Module