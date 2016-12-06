Option Strict Off
Option Explicit On

Imports System.Messaging
Imports System.Diagnostics
Imports System.Configuration
Imports System.IO.File
Imports System.IO
Imports System.GCCollectionMode
Imports System.Collections
Imports VB = Microsoft.VisualBasic
Imports System.Runtime.InteropServices
Public Class form1

    Inherits System.Windows.Forms.Form
    Private pRealPlayHandle As Integer()
    Public my_cam As String = 1
    Public my_server As String
    Public my_name As String
    Public my_user As String
    Public my_pass As String
    Public my_port As Integer
    Public my_flag As Integer
    Public my_idlista As Integer


    Private connection_string As String
    Public my_out_gates() As String
    Public my_id_gates() As String
    Dim g_nMDAlertNum As Integer
    Dim g_nVideoSize As Integer
    Dim g_nAudioSize As Integer
    Dim g_lImgNum As Integer
    Dim g_lNoSignalImgNum As Integer
    Dim g_lMDAlertNum As Integer
    Dim g_CBCalling As Boolean
    Const g_strPermittedCmd As String = "0123456789abcdefABCDEF,"
    Dim g_nAVINum As Integer

    Private Declare Function RemoveMenu Lib "user32" (ByVal hMenu As Integer, ByVal nPosition As Integer, ByVal wFlags As Integer) As Integer
    Private Declare Function GetSystemMenu Lib "user32" (ByVal hwnd As Integer, ByVal bRevert As Integer) As Integer
    Private Const MF_BYPOSITION As Integer = &H1000
    Private Const SC_CLOSE As Integer = &HF060 'Close
    Private Const SC_MAXIMIZE As Integer = &HF030 'Maximize
    Private Const SC_MINIMIZE As Integer = &HF020 'Minimize

    Private bInited As Boolean
    Private bout As Boolean
    Private hLoginId As Object
    Private hMonitorId As Integer
    Private error_Renamed As NET_RET_ERROR
    Private devInfo As NET_DEVICEINFO
    Private dd As Object
    Private longinid As Integer

    Public Delegate Sub ConnectFunc(ByVal lLoginID As Long, ByVal pchDVRIP As String, ByVal nDVRPort As Long, ByVal dwUser As String)

    Public Delegate Sub MessFunc(ByVal lCommand As Integer, ByVal lLoginID As Integer, ByVal pBuf As Integer, ByVal dwBufLen As Integer, ByVal pchDVRIP As Integer, ByVal nDVRPort As Integer, ByVal dwUser As Integer)

    Public Delegate Sub DisConnectFunc(ByVal lLoginID As Long, ByVal pchDVRIP As String, ByVal nDVRPort As Long, ByVal dwUser As String)
    
    Public Shared Sub StaticFunctionToCall(ByVal lLoginID As Long, ByVal pchDVRIP As String, ByVal nDVRPort As Long, ByVal dwUser As String)
    End Sub


    Private Sub SetEditState(ByRef objCtrl As System.Windows.Forms.TextBox, ByRef bEnable As Boolean)
        objCtrl.Enabled = bEnable
        If bEnable = False Then
            objCtrl.BackColor = System.Drawing.ColorTranslator.FromOle(&H8000000F)
        Else
            objCtrl.BackColor = System.Drawing.ColorTranslator.FromOle(&H80000005)
        End If
    End Sub

    Private Sub HandleAudioRelatedCtrl(ByRef bShow As Boolean)
    End Sub

    Private Sub Handle1Or4Channel(ByRef b1Ch As Boolean)
        If b1Ch Then
        End If
    End Sub

    Public Sub popola_testo()

        Dim i As Integer = 0
        Dim cam_table As New DataTable
        Dim my_dispositivo As String = "1"

        my_cam = 1
        my_server = "127.0.0.1"
        my_name = "test cam"
        my_user = "username"
        my_pass = "password"
        my_port = "80"

        'try to put 1 here to test zlnet sdk 
        my_flag = "0"
      

        If my_flag = 0 Then
            If hMonitorId <> 0 Then
                Call ZLNET_StopRealPlayEx(hMonitorId)
                PictureBox1.Refresh()
                hMonitorId = 0
            End If

            If hLoginId <> 0 Then
                Call ZLNET_Logout(hLoginId)
                Call ZLNET_Cleanup()
                hLoginId = 0
            End If

            PictureBox1.Visible = False
            comboChannel.SelectedIndex = my_cam - 1

            VitaminCtrl1.RemoteIPAddr = txtVsIP.Text
            VitaminCtrl1.CurrentControlCam = my_cam
            VitaminCtrl1.Password = my_user
            VitaminCtrl1.UserName = my_pass
            VitaminCtrl1.HttpPort = my_port

            If (VitaminCtrl1.ControlStatus = VITAMINDECODERLib.EControlStatus.ctrlConnectionBroken Or VitaminCtrl1.ControlStatus = VITAMINDECODERLib.EControlStatus.ctrlDisconnecting Or VitaminCtrl1.ControlStatus = VITAMINDECODERLib.EControlStatus.ctrlStopped) Then
                Dim lRet As Object
                VitaminCtrl1.UserName = my_user
                VitaminCtrl1.Password = my_pass
                VitaminCtrl1.RemoteIPAddr = my_server
                VitaminCtrl1.HttpPort = 80
                VitaminCtrl1.CurrentControlCam = "1"
                lRet = VitaminCtrl1.RefreshServerConfig

                If (lRet <> 0) Then
                    MsgBox("Could not refresh config: " & CStr(lRet))
                    Exit Sub
                End If

                UpdateServerSetStatus(True)
                VitaminCtrl1.Connect()
            End If
            System.Windows.Forms.Application.DoEvents()
            Exit Sub

        ElseIf my_flag = 1 Then
            If (TextChannel.Text = my_cam And txtVsIP.Text <> my_server) Or (TextChannel.Text <> my_cam And txtVsIP.Text = my_server) Or (TextChannel.Text <> my_cam And txtVsIP.Text <> my_server) Then
                Livecam_new()
            Else
            End If
            txtVsIP.Text = my_server
            TextChannel.Text = my_cam
        End If

        
        txtVsIP.Text = my_server
        TextChannel.Text = my_cam
        comboChannel.SelectedIndex = my_cam - 1
        System.Windows.Forms.Application.DoEvents()
    End Sub

    Public Shared Sub MessFuncToCall(ByVal lCommand As Integer, ByVal lLoginID As Integer, ByVal pBuf As Integer, ByVal dwBufLen As Integer, ByVal pchDVRIP As Integer, ByVal nDVRPort As Integer, ByVal dwUser As Integer)

    End Sub
    Private Sub Livecam_new()
        On Error GoTo loaderror
        PictureBox1.Visible = True
        VitaminCtrl1.Disconnect()
        If hMonitorId <> 0 Then
            Call ZLNET_StopRealPlayEx(hMonitorId)
            PictureBox1.Refresh()
            hMonitorId = 0
        End If


        Dim esito As Integer = 0
        Dim myDelegate As New DisConnectFunc(AddressOf StaticFunctionToCall)
        Dim MessF As New MessFunc(AddressOf MessFuncToCall)

        Dim err As Integer = 0

        Dim iCountLoop As Integer = 0
        Dim res As Boolean
        Dim oForm As New form1
        Dim retry As Integer = 0

        pRealPlayHandle = Nothing
        pRealPlayHandle = New Integer(15) {}


retry:  iCountLoop = iCountLoop + 1
        If hMonitorId <> 0 Then
            iCountLoop = iCountLoop + 1
            Call ZLNET_StopRealPlayEx(hMonitorId)
            hMonitorId = 0
        End If

        If hLoginId <> 0 Then
            Call ZLNET_Logout(hLoginId)
            Call ZLNET_Cleanup()
            hLoginId = 0
        End If

        Dim ConnectF As New ConnectFunc(AddressOf StaticFunctionToCall)

        bInited = ZLNET_Init(ConnectF, 0)
        hLoginId = ZLNET_Login(my_server, CInt(my_port), my_user, my_pass, devInfo, error_Renamed) 'Login

nextt:  ReDim pRealPlayHandle(devInfo.byChanNum)
        If hLoginId = 0 Then
            Call ZLNET_Cleanup()
            If iCountLoop > 2 Then
                iCountLoop = 0
                'lista ip_video server alternativa
                'Extract_Video_Reserve(my_server, my_port, my_user, my_pass, my_idlista)
                GoTo retry
            Else
                WaitSeconds(2)
                GoTo retry
            End If

        End If

        hMonitorId = ZLNET_RealPlay(CInt(hLoginId), CInt(my_cam), PictureBox1.Handle.ToInt32) 'Realplay
        pRealPlayHandle(my_cam) = hMonitorId

        GC.Collect()
        GC.WaitForPendingFinalizers()
        PictureBox1.Visible = True

        Exit Sub

        Windows.Forms.Application.DoEvents()
loaderror:
        MsgBox("Errore live")
    End Sub
    Public Sub WaitSeconds(ByRef Pausa As Single)

        Dim inizio As Single
        Dim DataInizio As String
        Dim DataAttuale As String

        inizio = VB.Timer()
        DataInizio = CStr(Today)
        Do While VB.Timer() < inizio + Pausa

            System.Windows.Forms.Application.DoEvents()
            DataAttuale = CStr(Today)
            If DataAttuale <> DataInizio Then
                DataInizio = DataAttuale
                inizio = inizio - 86400
            End If
        Loop

    End Sub
    Private Sub SetupInitProtocol(ByRef nIndex As Short)
        Dim comboProtocol As Object = Nothing
        If (nIndex = 1) Then
            ' 3K, TCP, UDP, Http
            comboProtocol.Clear()
            comboProtocol.AddItem("UDP")
            comboProtocol.AddItem("TCP")
            comboProtocol.AddItem("HTTP")
            comboProtocol.ListIndex = 1
        ElseIf (nIndex = 2) Then
            ' 4/5/6 K, UDP, Http

            ' init to Http
        ElseIf (nIndex = 3) Then
            ' 7K Multicast, TCP, UDP, HTTP
            comboProtocol.Clear()
            comboProtocol.AddItem("UDP")
            comboProtocol.AddItem("TCP")
            comboProtocol.AddItem("HTTP")
            comboProtocol.AddItem("MultiCast")
            comboProtocol.ListIndex = 0
        ElseIf (nIndex = 5) Then
            ' 7K Dual-Stream Multicast, TCP, UDP, HTTP
            comboProtocol.Clear()
            comboProtocol.AddItem("UDP")
            comboProtocol.AddItem("TCP")
            comboProtocol.AddItem("HTTP")
            comboProtocol.AddItem("MultiCast")
            ' init to UDP
            comboProtocol.ListIndex = 0
        End If
    End Sub
    Private Sub SetAVIButtonStatus()
        Dim bAutoSet As Boolean
        Dim bSizeByStream As Boolean

        'bAutoSet = chkAVIAutoSet.CheckState
        bSizeByStream = chkAVIAutoSize.CheckState

        labAVIVFR.Enabled = Not bAutoSet
        SetEditState(txtAVIFR, Not bAutoSet)
        chkAVIAutoSize.Enabled = Not bAutoSet
        'cmdUpdateSet.Enabled = Not bAutoSet

        labAVIW.Enabled = Not bAutoSet And Not bSizeByStream
        SetEditState(txtAVIW, Not bAutoSet And Not bSizeByStream)
        labAVIH.Enabled = Not bAutoSet And Not bSizeByStream
        SetEditState(txtAVIH, Not bAutoSet And Not bSizeByStream)

    End Sub

    Private Sub HandleWhenControlTypeChanged()

    End Sub
    Private Sub ResetControls(ByRef bEnable As Boolean)
        Dim i As Object

        For i = 0 To 3
        Next i


        If (bEnable) Then
            'UpdatePresetLocation()
        End If
    End Sub

    Private Sub UpdateServerSetStatus(ByRef bEnable As Boolean)

    End Sub

    Private Sub DoDoSet(ByRef strVal As String, ByRef nPort As Short)
        If Len(strVal) = 0 Then
            MsgBox("Show give the DO value")
            Exit Sub
        End If

        VitaminCtrl1.SendDigitalOut(nPort, CShort(strVal))
    End Sub

    Private Sub chkAutoReconn_CheckStateChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs)
    End Sub
    Private Sub chkAVIAutoSet_CheckStateChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs)
        'VitaminCtrl1.AutoAVISettings = chkAVIAutoSet.CheckState
        SetAVIButtonStatus()

    End Sub
    Private Sub chkAVIAutoSize_CheckStateChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs)
        txtAVIW.Enabled = True
        txtAVIH.Enabled = True
        ' cmdUpdateSet.Enabled = True
        VitaminCtrl1.AVIVideoSizeByStream = chkAVIAutoSize.CheckState
        SetAVIButtonStatus()
    End Sub
    Private Sub SetCtrlButtonState(ByRef nIndex As Integer, ByRef bVisible As Boolean)
        Dim nVal As Integer

        nVal = VitaminCtrl1.ControlButtonOpts
        nVal = nVal And (Not nIndex)
        If (bVisible) Then
            nVal = nVal Or nIndex
        End If
        VitaminCtrl1.ControlButtonOpts = nVal
    End Sub

    Private Sub chkDigitalZoom_Click()
        Dim chkDigitalZoom As Object = Nothing
        SetCtrlButtonState(VITAMINDECODERLib.EControlButtonState.ebutDigitalZoom, chkDigitalZoom.Value)
    End Sub

    Private Sub chkDisplay_Click()
        Dim chkDisplay As Object = Nothing
        VitaminCtrl1.Display = chkDisplay.Value
        popola_testo()
    End Sub
    Private Sub chkForceGDI_Click()
        Dim chkForceGDI As Object = Nothing
        VitaminCtrl1.ForceGDI = chkForceGDI.Value
    End Sub

    Private Sub chkForceNonYUV_Click()
        Dim chkForceNonYUV As Object = Nothing
        VitaminCtrl1.ForceNonYUV = chkForceNonYUV.Value
    End Sub


    Private Sub chkIgnoreBorder_Click()
        Dim chkIgnoreBorder As Object = Nothing
        VitaminCtrl1.IgnoreBorder = chkIgnoreBorder.Value
    End Sub

    Private Sub chkIgnoreCaption_Click()
        Dim chkIgnoreCaption As Object = Nothing
        VitaminCtrl1.IgnoreCaption = chkIgnoreCaption.Value
    End Sub


    Private Sub chkMicCtrl_Click()
        Dim chkMicCtrl As Object = Nothing
        SetCtrlButtonState(VITAMINDECODERLib.EControlButtonState.ebutMicVolume, chkMicCtrl.Value)
    End Sub

    Private Sub chkMoEditMode_Click()
        Dim chkMoEditMode As Object = Nothing
        VitaminCtrl1.MDEditMode = chkMoEditMode.Value
    End Sub

    Private Sub chkMotionFrame_Click()
        Dim chkMotionFrame As Object = Nothing
        VitaminCtrl1.DisplayMotionFrame = chkMotionFrame.Value
    End Sub
    Private Sub chkShowAVIBtn_CheckStateChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles chkShowAVIBtn.Click
        SetCtrlButtonState(VITAMINDECODERLib.EControlButtonState.ebutAVIConvert, (chkShowAVIBtn.CheckState))
    End Sub

    Private Sub chkSound_Click()
        Dim chkSound As Object = Nothing
        If (chkSound.Value = 1) Then
            VitaminCtrl1.MediaType = VITAMINDECODERLib.EMediaType.eMediaAV
        Else
            VitaminCtrl1.MediaType = VITAMINDECODERLib.EMediaType.eMediaVideo
        End If
    End Sub
    Private Sub chkSSLEnable_CheckStateChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs)
    End Sub

    Private Sub chkStretch_Click()
        Dim chkStretch As Object = Nothing
        VitaminCtrl1.Stretch = chkStretch.Value
    End Sub

    Private Sub chkTalkButton_Click()
        Dim chkTalkButton As Object = Nothing
        SetCtrlButtonState(VITAMINDECODERLib.EControlButtonState.ebutTalk, chkTalkButton.Value)
    End Sub
    Private Sub chkTestInput_CheckStateChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs)
        Dim bNotify As Boolean
        VitaminCtrl1.NotifyAudioPacket = bNotify
        VitaminCtrl1.NotifyVideoPacket = bNotify

    End Sub

    Private Sub chkTwoWayAudio_Click()
        Dim chkTwoWayAudio As Object = Nothing
        VitaminCtrl1.EnableTwoWayAudio = chkTwoWayAudio.Value
    End Sub

    Private Sub chkUserDateFmt_Click()
        Dim chkUserDateFmt As Object = Nothing
        VitaminCtrl1.UserDateFormat = chkUserDateFmt.Value
    End Sub

    Private Sub chkUseStretch_Click()
        Dim chkUseStretch As Object = Nothing
        VitaminCtrl1.GDIUseStretchBlt = chkUseStretch.Value
    End Sub

    Private Sub chkVideoRaw_Click()
        Dim chkVideoRaw As Object = Nothing
        If chkVideoRaw.Value = 1 Then
            VitaminCtrl1.NotifyVideoData = True
        Else
            VitaminCtrl1.NotifyVideoData = False
        End If
    End Sub

    Private Sub chkVolumeCtrl_Click()
        Dim chkVolumeCtrl As Object = Nothing
        SetCtrlButtonState(VITAMINDECODERLib.EControlButtonState.ebutPlayVolume, chkVolumeCtrl.Value)
    End Sub

    Private Sub chkZoomEnabled_Click()
        Dim chkZoomEnabled As Object = Nothing
        VitaminCtrl1.DigitalZoomEnabled = chkZoomEnabled.Value
    End Sub

    Private Sub cmd4ChDi_Click(ByRef Index As Short)

    End Sub

    Private Sub cmd4ChDo_Click(ByRef Index As Short)

    End Sub

    Private Function DoDiGet(ByRef nPort As Short) As String
        Dim vData As Object = Nothing

        VitaminCtrl1.GetDigitalIn(nPort, vData)
        If vData = 0 Then
            DoDiGet = "L"
        Else
            DoDiGet = "H"
        End If

    End Function

    Private Sub cmdAudioComp_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs)
        VitaminCtrl1.ChooseAVIAudioCompressor("Audio Compressor")
    End Sub

    Private Sub cmdAuto_Click()
        VitaminCtrl1.SendCameraCommand("auto")
    End Sub
    Private Sub cmdDateTimeSet_Click()
        Dim lRet As Object
        Dim txtDateTimeTime As Object = Nothing
        Dim txtDateTimeDate As Object = Nothing
        If (txtDateTimeDate.Text = "") Then
            MsgBox("must give server date")
            Exit Sub
        End If
        If (txtDateTimeTime.Text = "") Then
            MsgBox("must give server time")
            Exit Sub
        End If
        lRet = VitaminCtrl1.SetServerDateTime(txtDateTimeDate.Text, txtDateTimeTime.Text)
        If (lRet <> 0) Then
            MsgBox("Set server date/time error: " & CStr(lRet))
        End If
    End Sub

    Private Sub cmdDBPathBrowse_Click()
        Dim txtDatabasePath As Object = Nothing
        Dim strRet As Object
        strRet = BrowseFolder(Me.Handle.ToInt32, "Select Database Path")

        If Len(strRet) > 0 Then
            txtDatabasePath.Text = strRet
        End If
    End Sub
    Private Sub cmdDiGet_Click()
        Dim txtDI As Object = Nothing
        txtDI.Text = DoDiGet(1)
    End Sub

    Private Sub cmdDoSet_Click()
        Dim txtDO As Object = Nothing
        DoDoSet(txtDO.Text, 0)
    End Sub
    Private Sub cmdDown_Click()
        VitaminCtrl1.SendCameraCommand("down")
    End Sub

    Private Sub cmdFar_Click()
        VitaminCtrl1.SendCameraCommand("far")
    End Sub

    Private Sub cmdFullScreen_Click()
        VitaminCtrl1.SetFullScreen(True)
    End Sub

    Private Sub cmdHome_Click()
        VitaminCtrl1.SendCameraCommand("home")
    End Sub

    Private Sub DoHttpOper(ByRef bPost As Boolean)
        Dim chkHttpCmdShowRet As Object = Nothing
        Dim txtHttpCmdUrl As Object = Nothing
        Dim lRet As Integer
        Dim strRet As String = ""
        Dim bRead As Boolean

        'UPGRADE_WARNING: Couldn't resolve default property of object txtHttpCmdUrl.Text. Click for more: 'ms-help://MS.VSCC.v90/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        If Len(txtHttpCmdUrl.Text) = 0 Then
            MsgBox("Url command could not be empty")
            Exit Sub
        End If

        bRead = False
        'UPGRADE_WARNING: Couldn't resolve default property of object chkHttpCmdShowRet.Value. Click for more: 'ms-help://MS.VSCC.v90/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        If chkHttpCmdShowRet.Value = 1 Then
            bRead = True
        End If

        'UPGRADE_WARNING: Couldn't resolve default property of object txtHttpCmdUrl.Text. Click for more: 'ms-help://MS.VSCC.v90/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        lRet = VitaminCtrl1.HttpCommand(txtHttpCmdUrl.Text, bPost, bRead, strRet)

        If lRet <> 0 Then
            MsgBox("Failed with error " & CStr(lRet))
            Exit Sub
        End If

        If bRead = True Then
            MsgBox(strRet)
        Else
            MsgBox("Command sent successfully")
        End If
    End Sub

    Private Sub cmdHttpCmdGet_Click()
        DoHttpOper(False)
    End Sub

    Private Sub cmdHttpCmdPost_Click()
        DoHttpOper(True)
    End Sub

    Private Sub cmdIrisAuto_Click()
        VitaminCtrl1.SendCameraCommand("irisauto")
    End Sub

    Private Sub cmdIrisClose_Click()
        VitaminCtrl1.SendCameraCommand("close")
    End Sub

    Private Sub cmdIrisOpen_Click()
        VitaminCtrl1.SendCameraCommand("open")
    End Sub

    Private Sub cmdLeft_Click()
        VitaminCtrl1.SendCameraCommand("left")
    End Sub

    Private Sub cmdNear_Click()
        VitaminCtrl1.SendCameraCommand("near")
    End Sub

    Private Sub cmdPan_Click()
        VitaminCtrl1.SendCameraCommand("pan")
    End Sub

    Private Sub cmdPatrol_Click()
        VitaminCtrl1.SendCameraCommand("patrol")
    End Sub
    Private Sub cmdPTStop_Click()
        VitaminCtrl1.SendCameraCommand("stop")

    End Sub

    Private Sub cmdReadUart_Click()
        Dim txtComCmd As Object = Nothing
        Dim strData As Object = Nothing
        Dim nPort As Short

        nPort = 1
        VitaminCtrl1.GetUartData(strData, 6, nPort, 1000)
        txtComCmd.Text = strData
    End Sub

    'Private Sub cmdRecord_Click()
    '    StartDatabaseRecord(False, VITAMINDECODERLib.EMediaType.eMediaAV)
    'End Sub


    Private Sub cmdRight_Click()
        VitaminCtrl1.SendCameraCommand("right")
    End Sub



    Private Function CheckForUartCommand() As Boolean
        Dim subChar As Object = Nothing
        Dim i As Object = Nothing
        Dim txtComCmd As Object = Nothing
        Dim lIdx, lLen As Integer

        'UPGRADE_WARNING: Couldn't resolve default property of object txtComCmd.Text. Click for more: 'ms-help://MS.VSCC.v90/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        lLen = Len(txtComCmd.Text)

        If lLen = 0 Then
            MsgBox("Command name should not be empty")
            CheckForUartCommand = False
            Exit Function
        End If

        For i = 1 To lLen
            subChar = Mid(txtComCmd.Text, i, 1)
            lIdx = InStr(1, g_strPermittedCmd, subChar)
            If lIdx = 0 Then
                MsgBox("Command for COM contains some forbidden letters, the permitted letters are: " & g_strPermittedCmd)
                CheckForUartCommand = False
            End If
        Next i

        CheckForUartCommand = True
    End Function

    Private Sub cmdSendUartCmd_Click()
        Dim lRet As Object = Nothing
        Dim nPort As Integer = Nothing

        If CheckForUartCommand() = False Then
            Exit Sub
        End If

        nPort = 1

        If (lRet <> 0) Then
            MsgBox("Failed: " & CStr(lRet))
        End If
    End Sub

    Private Sub cmdSetRead_Click()
        Dim txtSetValue As Object = Nothing
        Dim txtSetSecEntry As Object = Nothing
        Dim lIndex As Object = Nothing
        Dim txtSetIndex As Object = Nothing
        Dim strSec As String
        Dim strEntry As String
        lIndex = CShort(txtSetIndex.Text)

        strSec = VitaminCtrl1.get_ServerConfigSection(lIndex)
        strEntry = VitaminCtrl1.get_ServerConfigEntry(lIndex)

        If (strEntry = "") Then
            txtSetSecEntry.Text = "No Such item"
            txtSetValue.Text = ""
        Else
            txtSetSecEntry.Text = strSec & "/" & strEntry
            txtSetValue.Text = VitaminCtrl1.get_ServerConfig(lIndex, 0)
        End If
    End Sub

    Private Sub cmdSetRefresh_Click()
        Dim lRet As Integer

        VitaminCtrl1.UserName = "username"
        VitaminCtrl1.Password = "password"
        VitaminCtrl1.RemoteIPAddr = txtVsIP.Text
        VitaminCtrl1.HttpPort = 80
        VitaminCtrl1.CurrentControlCam = TextChannel.Text
        lRet = VitaminCtrl1.RefreshServerConfig
        VitaminCtrl1.CurrentControlCam = comboChannel.Text
        If (lRet <> 0) Then
            MsgBox("Could not refresh config: " & CStr(lRet))
            Exit Sub
        End If

        UpdateServerSetStatus(True)
        cmdSetRead_Click()
    End Sub

    Private Sub cmdSetSet_Click()
        Dim lRet As Object = Nothing
        Dim txtSetValue As Object = Nothing
        Dim lIndex As Object = Nothing
        Dim txtSetIndex As Object = Nothing
        lIndex = CShort(txtSetIndex.Text)
        lRet = VitaminCtrl1.SetServerConfig(lIndex, 0, txtSetValue.Text)
        If (lRet <> 0) Then
            MsgBox("SetServerConfig cfg failed: " & CStr(lRet))
        End If
    End Sub

    Private Sub cmdSetUpdate_Click()
        Dim lRet As Object = Nothing
        lRet = VitaminCtrl1.UpdateServerConfig()
        If (lRet <> 0) Then
            MsgBox("Update server cfg failed: " & CStr(lRet))
        End If
    End Sub

    Private Sub cmdSnapBrowse_Click()
        Dim txtSnapFileName As Object = Nothing
        Dim CommonDialog1 As Object = Nothing
        CommonDialog1.ShowSave()
        If CommonDialog1.FileName <> "" Then
            txtSnapFileName.Text = CommonDialog1.FileName
        End If
    End Sub

    Private Sub cmdStart_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs)
        Dim lRet As Object = Nothing
        Dim queue As New MessageQueue()
        Dim mes As String = ""
        Dim m As Message = Nothing
        Dim my_dati() As String = Nothing
        Dim allprivatequeus() As MessageQueue = MessageQueue.GetPrivateQueuesByMachine("127.0.0.1")
        popola_testo()
        queue.Path = ".\private$\telecamera"
        Try
            If Not Exists(queue.Path) Then
                System.Messaging.MessageQueue.Create(queue.Path)
            Else
            End If
        Catch
        End Try

    End Sub

    Private Sub cmdStartAVIConvert_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles cmdStartAVIConvert.Click

        If (VitaminCtrl1.AVIStatus = VITAMINDECODERLib.EAVIRecordState.eAVIStop) Then
            VitaminCtrl1.StartAVIConversion()
            cmdStartAVIConvert.Text = "Stop Reg"
            'Timer1.Enabled = False
        Else
            ' Timer1.Enabled = True
            VitaminCtrl1.StopAVIConversion()
            cmdStartAVIConvert.Text = "Registra"
        End If
    End Sub
    Private Sub CapturePicture(ByVal hPlayHandle As Integer, ByVal bmpPath As String)
        If DHCapturePicture(hPlayHandle, bmpPath) Then


        Else

        End If
    End Sub
    Public Shared Function DHCapturePicture(ByVal lPlayHandle As Integer, ByVal phPicFileName As String) As Boolean
        Return ZLNET_CapturePicture(lPlayHandle, phPicFileName)
    End Function

    Private Sub CapturePictureok(ByVal hPlayHandle As Integer)
        Dim bmpPath As String = My.Application.Info.DirectoryPath + "\ImagePath\Image_" + DateTime.Now.ToString("yyyyMMddHHmmss") + ".jpg"

        CapturePicture(hPlayHandle, bmpPath)
    End Sub
    Private Sub btnCapturePicture_Click(ByVal sender As Object, ByVal e As EventArgs)
        Dim channelId As Integer = 0

        channelId = comboChannel.SelectedIndex
        'End If
        CapturePictureok(pRealPlayHandle(channelId + 1))
    End Sub
    Private Sub cmdUp_Click()
        VitaminCtrl1.SendCameraCommand("up")
    End Sub

    Private Sub cmdUpdateSet_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs)
        Dim nW As Integer
        Dim nH As Integer

        ' update FR, W, H
        VitaminCtrl1.AVIVideoFrameRate = CShort(txtAVIFR.Text)
        nW = CShort(txtAVIW.Text)
        nH = CShort(txtAVIH.Text)
        If ((nW Mod 8) <> 0) Then
            nW = nW - (nW Mod 8)
            txtAVIW.Text = CStr(nW)
        End If

        If ((nH Mod 8) <> 0) Then
            nH = nH - (nH Mod 8)
            txtAVIH.Text = CStr(nH)
        End If

        VitaminCtrl1.AVIVideoWidth = nW
        VitaminCtrl1.AVIVideoHeight = nH
    End Sub

    Private Sub cmdVideoComp_Click(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs)
        VitaminCtrl1.ChooseAVIVideoCompressor("Video Compressor")
    End Sub

    Private Sub cmdZoomIn_Click()
        VitaminCtrl1.SendCameraCommand("tele")
    End Sub

    Private Sub cmdZoomOut_Click()
        VitaminCtrl1.SendCameraCommand("wide")
    End Sub


    Private Sub comboChannel_Click()
        Dim comboChannel As Object = Nothing
    End Sub
    Private Sub comboControlType_SelectedIndexChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs)
        If g_CBCalling = False Then
            HandleWhenControlTypeChanged()
        End If
    End Sub

    Private Sub comboDecVideoFmt_Click()
        Dim comboDecVideoFmt As Object = Nothing
        'UPGRADE_WARNING: Couldn't resolve default property of object comboDecVideoFmt.ListIndex. Click for more: 'ms-help://MS.VSCC.v90/dv_commoner/local/redirect.htm?keyword="6A50421D-15FE-4896-8A1B-2EC21E9037B2"'
        VitaminCtrl1.NotifyImageFormat = comboDecVideoFmt.ListIndex + VITAMINDECODERLib.EPictureFormat.ePicFmtJpeg
    End Sub

    Private Sub comboPreset_Click()
        Dim comboPreset As Object = Nothing
        If (comboPreset.Text <> "") Then
            VitaminCtrl1.RecallPtzPosition(comboPreset.Text)
        End If
    End Sub

    Private Sub comboStreamingOpt_Click()
        Dim txtSecsPerFrame As Object = Nothing
        Dim comboStreamingOpt As Object = Nothing
        VitaminCtrl1.StreamingOption = VITAMINDECODERLib.EStreamingOption.eStOpStreaming + comboStreamingOpt.ListIndex
        If (txtSecsPerFrame.Text <> "") Then
            VitaminCtrl1.JpegSecsPerFrame = CShort(txtSecsPerFrame)
        End If
    End Sub


    Private Sub comboUserTimeFmt_Click()
        Dim comboUserTimeFmt As Object = Nothing
        VitaminCtrl1.DisplayTimeFormat = VITAMINDECODERLib.EDisplayTimeFormat.eTimeFmtNormal + comboUserTimeFmt.ListIndex
    End Sub
    Private Sub comboVSize_Click()
        Dim comboVSize As Object = Nothing
        VitaminCtrl1.VideoSize2K = comboVSize.ListIndex + 1
    End Sub

    Private Sub Command1_Click()
        VitaminCtrl1.SendCameraCommandMap(100, 0)
    End Sub

    Private Sub form1_Load(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles MyBase.Load
       
        
        popola_testo()
        g_nAVINum = 0
        g_CBCalling = False
        SetAVIButtonStatus()
        UpdateServerSetStatus(False)
        ResetControls(False)
        System.Windows.Forms.Application.DoEvents()
        'Timer1.Enabled = True
        pRealPlayHandle = New Integer(15) {}
    End Sub

    Private Sub Timer2_Timer()
        Dim bIsRecording As Boolean
        bIsRecording = VitaminCtrl1.IsRecording
    End Sub

    Private Sub txtDisplayPeriod_Change()
        Dim txtDisplayPeriod As Object = Nothing
        popola_testo()
        If (txtDisplayPeriod.Text <> "") Then
            VitaminCtrl1.DisplayPeriod = CShort(txtDisplayPeriod.Text)
        End If
    End Sub
    Private Sub txtSecsPerFrame_Change()
        Dim txtSecsPerFrame As Object = Nothing
        If (txtSecsPerFrame.Text <> "") Then
            VitaminCtrl1.JpegSecsPerFrame = CShort(txtSecsPerFrame)
        End If
    End Sub
    Private Sub VitaminCtrl1_OnAVIStatus(ByVal eventSender As System.Object, ByVal eventArgs As AxVITAMINDECODERLib._IVitaminCtrlEvents_OnAVIStatusEvent) Handles VitaminCtrl1.OnAVIStatus
        If eventArgs.eStatus = VITAMINDECODERLib.EAVIRecordState.eAVIStop Then
            cmdStartAVIConvert.Text = "Registra"
            cmdStartAVIConvert.ForeColor = Color.Green
            'Timer1.Enabled = True
        Else
            cmdStartAVIConvert.Text = "Stop Registrazione"
            'Timer1.Enabled = False
        End If
        If cmdStartAVIConvert.Text = "Stop Registrazione" Then
            cmdStartAVIConvert.ForeColor = Color.Red
        End If
    End Sub

    Private Sub VitaminCtrl1_OnConnectionBroken(ByVal eventSender As System.Object, ByVal eventArgs As AxVITAMINDECODERLib._IVitaminCtrlEvents_OnConnectionBrokenEvent)
        Dim lRet As Object

        lRet = VitaminCtrl1.RefreshServerConfig
        VitaminCtrl1.CurrentControlCam = comboChannel.Text
        If (lRet <> 0) Then
            MsgBox("Could not refresh config: " & CStr(lRet))
            Exit Sub
        End If

        UpdateServerSetStatus(True)
    End Sub

    Private Sub VitaminCtrl1_OnConnectionOK(ByVal eventSender As System.Object, ByVal eventArgs As AxVITAMINDECODERLib._IVitaminCtrlEvents_OnConnectionOKEvent) Handles VitaminCtrl1.OnConnectionOK

    End Sub

    Private Sub Handle4ChDIDOAlert(ByRef lValue As Integer)
        Dim lDI As Object
        Dim lDO As Integer
        Dim lSrcDI As Object
        Dim lSrcDO As Integer
        Dim i As Object
        Dim lMask As Integer

        lSrcDI = lValue And 65535
        lSrcDO = lValue / 65536
        lDI = lValue And 65535
        lDO = lValue / 65536

        lMask = 1
        For i = 0 To 3
            If ((lDI And lMask) <> 0) Then
            End If
            lMask = lMask * 2
        Next i

        lMask = 1
        For i = 0 To 1
            If ((lDO And lMask) <> 0) Then
            End If
            lMask = lMask * 2
        Next i
    End Sub

    Private Sub VitaminCtrl1_OnDIDOAlert(ByVal eventSender As System.Object, ByVal eventArgs As AxVITAMINDECODERLib._IVitaminCtrlEvents_OnDIDOAlertEvent)
        Dim txtDOimg As Object = Nothing
        Dim txtDIimg As Object = Nothing
        Dim lDI As Integer
        Dim lDO As Integer

        lDI = eventArgs.lValue And 65535
        lDO = eventArgs.lValue / 65536

        If (lDI And 1) Then
            txtDIimg.Text = "H"
        End If

        If (lDO And 1) Then
            txtDOimg.Text = "H"
        End If
    End Sub
    Private Sub comboChannel_SelectedIndexChanged(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs) Handles comboChannel.Click, comboChannel.SelectedIndexChanged
        If my_flag = 1 Then Exit Sub
        ' Timer1.Stop()

        Dim lRet As Object = Nothing
        VitaminCtrl1.Disconnect()
        VitaminCtrl1.CurrentControlCam = my_cam
        VitaminCtrl1.Password = "admin"
        VitaminCtrl1.UserName = "root"
        VitaminCtrl1.HttpPort = CInt("80")
        VitaminCtrl1.RemoteIPAddr = my_server

        lRet = VitaminCtrl1.RefreshServerConfig

        UpdateServerSetStatus(True)

        If VitaminCtrl1.Connect() = 1 Then
        End If
        txtVsIP.Enabled = False
    End Sub

    Private Sub VitaminCtrl1_OnNewVideo(ByVal eventSender As System.Object, ByVal eventArgs As AxVITAMINDECODERLib._IVitaminCtrlEvents_OnNewVideoEvent)
        Dim strName As Object = Nothing
        Dim strExt As Object = Nothing
        Dim myArr() As Byte

        g_lImgNum = g_lImgNum + 1
        If (eventArgs.bSignal) Then
            g_lNoSignalImgNum = g_lNoSignalImgNum + 1
        End If

        If eventArgs.bDecodedImg = False Then
            Exit Sub
        End If

        myArr = eventArgs.vPiece(1)
        g_nVideoSize = g_nVideoSize + eventArgs.vPiece(0)(2)


        strName = "c:\video" + strExt

        FileOpen(2, strName, OpenMode.Binary, OpenAccess.Write)
        FilePut(2, myArr)
        FileClose(2)
    End Sub

    Private Sub VitaminCtrl1_OnRecordStatus(ByVal eventSender As System.Object, ByVal eventArgs As AxVITAMINDECODERLib._IVitaminCtrlEvents_OnRecordStatusEvent)
        Dim cmdRecord As Object = Nothing
        Select Case eventArgs.lStatusCode
            Case VITAMINDECODERLib.EDBStatusCode.eStatusDiskFull
            Case VITAMINDECODERLib.EDBStatusCode.eStatusDBRepairFinish
                If eventArgs.lParam = 0 Then
                    MsgBox("Repair database failed")
                    Exit Sub
                End If
                cmdRecord.Enabled = True
            Case VITAMINDECODERLib.EDBStatusCode.eStatusLocRepairFinish
                If eventArgs.lParam = 0 Then
                    MsgBox("Repair location failed")
                    Exit Sub
                End If
                cmdRecord.Enabled = True
        End Select
    End Sub

    Private Sub VitaminCtrl1_OnRequestAVIFileName(ByVal eventSender As System.Object, ByVal eventArgs As AxVITAMINDECODERLib._IVitaminCtrlEvents_OnRequestAVIFileNameEvent)
        VitaminCtrl1.AVIFilePathName = "C:\Documents and Settings\All Users\Registrazioni" & DateTime.Now & CStr(g_nAVINum) & ".avi"
        g_nAVINum = g_nAVINum + 1
    End Sub

    ' sam 2007/05/02
    Private Sub SetupComboProtocol(ByVal eServerModelType As VITAMINDECODERLib.EServerModelType)
        Dim comboProtocol As Object = Nothing
        If (eServerModelType = 0 Or eServerModelType = 4) Then
            ' 2K
        ElseIf (eServerModelType = 1) Then
            ' 3K
            comboProtocol.ListIndex = VitaminCtrl1.ConnectionProtocol - 1
        ElseIf (eServerModelType = 2) Then
            ' 4/5/6 K
            If (VitaminCtrl1.ConnectionProtocol = VITAMINDECODERLib.EConnProtocol.eProtUDP) Then
                comboProtocol.ListIndex = 0
            Else
                comboProtocol.ListIndex = 1
            End If
        ElseIf (eServerModelType = 3) Or (eServerModelType = 5) Then
            comboProtocol.ListIndex = VitaminCtrl1.ConnectionProtocol - 1
        End If
    End Sub

    Private Sub VitaminCtrl1_OnServerModelType(ByVal eventSender As System.Object, ByVal eventArgs As AxVITAMINDECODERLib._IVitaminCtrlEvents_OnServerModelTypeEvent)
        Dim esrv7KDualStream As Object = Nothing
        Dim chkTwoWayAudio As Object = Nothing
        g_CBCalling = True
        If eventArgs.eNewServerModelType = esrv7KDualStream Then
            chkTwoWayAudio.Enabled = True
        End If
        SetupComboProtocol(eventArgs.eNewServerModelType)
        g_CBCalling = False

    End Sub

    Private Sub VitaminCtrl1_OnVideoSignalChange(ByVal eventSender As System.Object, ByVal eventArgs As AxVITAMINDECODERLib._IVitaminCtrlEvents_OnVideoSignalChangeEvent)
        If eventArgs.eStatus = VITAMINDECODERLib.EVideoSignalState.eVideoSignalOff Then
            MsgBox("No Video Signal in This Video Server")
        End If

    End Sub

    Private Sub VitaminCtrl1_OnReachMaxReconnection(ByVal eventSender As System.Object, ByVal eventArgs As System.EventArgs)
        MsgBox("Reach reconnection count")
    End Sub

    Private Sub ToolTip1_Popup(ByVal sender As System.Object, ByVal e As System.Windows.Forms.PopupEventArgs)

    End Sub
    Private Sub ButtReg_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ButtReg.Click
        Dim prc As New Process
        prc.StartInfo.FileName = "C:\Documents and Settings\All Users\Registrazioni"
        prc.Start()
    End Sub

    Private Sub TextChannel_TextChanged()
        'Timer1.Stop()
        Dim lRet As Object
        VitaminCtrl1.Disconnect()
        VitaminCtrl1.CurrentControlCam = my_cam
        VitaminCtrl1.Password = "admin"
        VitaminCtrl1.UserName = "root"
        VitaminCtrl1.HttpPort = CInt("80")
        VitaminCtrl1.RemoteIPAddr = my_server

        lRet = VitaminCtrl1.RefreshServerConfig

        UpdateServerSetStatus(True)

        VitaminCtrl1.Connect()

        
        txtVsIP.Enabled = False
        'Timer1.Start()
    End Sub
    Private Sub VitaminCtrl1_OnClick(ByVal sender As System.Object, ByVal e As AxVITAMINDECODERLib._IVitaminCtrlEvents_OnClickEvent) Handles VitaminCtrl1.OnClick

    End Sub

    Private Sub comboQuality_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles comboQuality.SelectedIndexChanged

    End Sub

    Private Sub Label5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Label5.Click

    End Sub

    Private Sub ListBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs)

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)
        Dim prc As New Process
        prc.StartInfo.FileName = My.Application.Info.DirectoryPath + "\ImagePath"
        prc.Start()
    End Sub

    <DllImport("zlnetsdk.dll", SetLastError:=True)> _
   Public Shared Function ZLNET_Init(ByRef fDisConnect As ConnectFunc, ByVal wDVRPort As Integer) As Integer
    End Function
    <DllImport("zlnetsdk.dll", SetLastError:=True)> _
  Public Shared Function ZLNET_Login(ByVal pchDVRIP As String, ByVal wDVRPort As Integer, ByVal pchUserName As String, ByVal pchPassword As String, ByRef lpDeviceInfo As NET_DEVICEINFO, ByRef error_Renamed As NET_RET_ERROR) As Integer
    End Function
    <DllImport("zlnetsdk.dll", SetLastError:=True)> _
  Public Shared Function ZLNET_Logout(ByVal lLoginID As Integer) As Integer
    End Function
    <DllImport("zlnetsdk.dll", SetLastError:=True)> _
   Public Shared Function ZLNET_RebootDev(ByVal lLoginID As Integer) As Integer
    End Function
    'ZLNET_API BOOL CALL_METHOD ZLNET_RebootDev (LONG lLoginID);
    <DllImport("zlnetsdk.dll", SetLastError:=True)> _
    Shared Function ZLNET_RealPlay(ByVal lLoginID As Integer, ByVal nChannelID As Integer, ByVal hwnd As Integer) As Integer
    End Function
    'Public Declare Function ZLNET_RealPlayEx Lib "zlnetsdk.dll" (ByVal lLoginID As Integer, ByVal nChannelID As Integer, ByVal hwnd As Integer, ByVal rType As Integer) As Integer
    <DllImport("zlnetsdk.dll", SetLastError:=True)> _
   Public Shared Function ZLNET_RealPlayEx(ByVal lLoginID As Integer, ByVal nChannelID As Integer, ByVal hwnd As Integer, ByVal rType As Integer) As Integer

    End Function
    '  <DllImport("zlnetsdk.dll", SetLastError:=True)> _
    'Public Shared Function ZLNET_RealPlay(ByVal lLoginID As Integer, ByVal nChannelID As Integer, ByVal hwnd As Integer) As Integer

    '  End Function
    'Stop Realplay
    ' Public Declare Function ZLNET_StopRealPlayEx Lib "zlnetsdk.dll" (ByVal lLoginID As Integer) As Integer
    <DllImport("zlnetsdk.dll", SetLastError:=True)> _
   Public Shared Function ZLNET_StopRealPlayEx(ByVal lLoginID As Integer) As Integer

    End Function
    <DllImport("zlnetsdk.dll", SetLastError:=True)> _
  Public Shared Function ZLNET_StopRealPlay(ByVal lLoginID As Integer) As Integer

    End Function
    <DllImport("zlnetsdk.dll", SetLastError:=True)> _
   Public Shared Sub ZLNET_Cleanup()

    End Sub
    <DllImport("zlnetsdk.dll", SetLastError:=True)> _
  Public Shared Sub ZLNET_Client_Cleanup()

    End Sub
    'Alarm Liten API
    'Public Declare Function ZLNET_StartListen Lib "zlnetsdk.dll" (ByVal lLoginID As Integer) As Integer
    <DllImport("zlnetsdk.dll", SetLastError:=True)> _
    Shared Function ZLNET_StartListen(ByVal lLoginID As Integer) As Integer

    End Function
    'Mess callback API

    'Public Declare Function ZLNET_SetDVRMessCallBack Lib "zlnetsdk.dll" (ByVal fMessCallBack As MessFunc, ByVal dwUser As Integer) As Integer
    <DllImport("zlnetsdk.dll", SetLastError:=True)> _
   Public Shared Function ZLNET_SetDVRMessCallBack(ByVal fMessCallBack As MessFunc, ByVal dwUser As Integer) As Integer

    End Function
    ' [DllImport("dhnetsdk.dll")]
    'private static extern bool CLIENT_CapturePicture(int hPlayHandle, string pchPicFileName);

    <DllImport("zlnetsdk.dll", SetLastError:=True)> _
  Public Shared Function ZLNET_CapturePicture(ByVal hPlayHandle As Integer, ByVal pchPicFileName As String) As Integer
    End Function
    <DllImport("zlnetsdk.dll", SetLastError:=True)> _
Public Shared Function ZLNET_ConvertToBmpFile(ByRef pBuf As String, ByVal nSize As Integer, ByVal nWidth As Integer, ByVal nHeight As Integer, ByVal nType As Integer, ByRef sFileName As String) As Boolean
    End Function
    Public Structure NET_DEVICEINFO
        'UPGRADE_WARNING: Fixed-length string size must fit in the buffer. Click for more: 'ms-help://MS.VSCC.v90/dv_commoner/local/redirect.htm?keyword="3C1E4426-0B80-443E-B943-0627CD55D48B"'
        <VBFixedString(48), System.Runtime.InteropServices.MarshalAs(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst:=48)> Public sSerialNumber() As Char
        Dim byAlarmInPortNum As Byte
        Dim byAlarmOutPortNum As Byte
        Dim byDiskNum As Byte
        Dim byDVRType As Byte
        Dim byChanNum As Byte

    End Structure

    Public Structure NET_RET_ERROR
        Dim errcode As Short
    End Structure
End Class