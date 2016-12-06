Imports System.Drawing

Imports System.Threading
'Imports AxVMRCClientControlLibxx
Imports System.Windows.Forms.AxHost
Imports AxVITAMINDECODERLib

<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> Partial Class form1
#Region "Windows Form Designer generated code "
    <System.Diagnostics.DebuggerNonUserCode()> Public Sub New()
        MyBase.New()
        'This call is required by the Windows Form Designer.
        InitializeComponent()
    End Sub
    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> Protected Overloads Overrides Sub Dispose(ByVal Disposing As Boolean)
        If Disposing Then
            If Not components Is Nothing Then
                components.Dispose()
            End If
        End If
        MyBase.Dispose(Disposing)
    End Sub
    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer
    Public WithEvents txtIdPrk As System.Windows.Forms.TextBox
    Public WithEvents txtVsIP As System.Windows.Forms.TextBox
    Public WithEvents Label10 As System.Windows.Forms.Label
    Public WithEvents Label2 As System.Windows.Forms.Label
    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(form1))
        Me.Label10 = New System.Windows.Forms.Label
        Me.Label2 = New System.Windows.Forms.Label
        Me.txtIdPrk = New System.Windows.Forms.TextBox
        Me.txtVsIP = New System.Windows.Forms.TextBox
        Me.VitaminCtrl1 = New AxVITAMINDECODERLib.AxVitaminCtrl
        Me.frmAVI = New System.Windows.Forms.GroupBox
        Me.chkShowAVIBtn = New System.Windows.Forms.CheckBox
        Me.cmdStartAVIConvert = New System.Windows.Forms.Button
        Me.ButtReg = New System.Windows.Forms.Button
        Me.txtAVIFR = New System.Windows.Forms.TextBox
        Me.chkAVIAutoSize = New System.Windows.Forms.CheckBox
        Me.txtAVIW = New System.Windows.Forms.TextBox
        Me.txtAVIH = New System.Windows.Forms.TextBox
        Me.labAVIVFR = New System.Windows.Forms.Label
        Me.labAVIW = New System.Windows.Forms.Label
        Me.labAVIH = New System.Windows.Forms.Label
        Me.labChannel = New System.Windows.Forms.Label
        Me.comboChannel = New System.Windows.Forms.ComboBox
        Me.Label5 = New System.Windows.Forms.Label
        Me.TextChannel = New System.Windows.Forms.TextBox
        Me.PictureBox1 = New System.Windows.Forms.PictureBox
        Me.comboQuality = New System.Windows.Forms.ComboBox
        CType(Me.VitaminCtrl1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.frmAVI.SuspendLayout()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'Label10
        '
        Me.Label10.BackColor = System.Drawing.Color.FromArgb(CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer))
        Me.Label10.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label10.ForeColor = System.Drawing.Color.Lime
        Me.Label10.Location = New System.Drawing.Point(12, 363)
        Me.Label10.Name = "Label10"
        Me.Label10.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label10.Size = New System.Drawing.Size(24, 17)
        Me.Label10.TabIndex = 36
        Me.Label10.Text = "Id:"
        '
        'Label2
        '
        Me.Label2.BackColor = System.Drawing.Color.FromArgb(CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer))
        Me.Label2.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label2.ForeColor = System.Drawing.Color.Lime
        Me.Label2.Location = New System.Drawing.Point(146, 360)
        Me.Label2.Name = "Label2"
        Me.Label2.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label2.Size = New System.Drawing.Size(62, 19)
        Me.Label2.TabIndex = 0
        Me.Label2.Text = "Server IP:"
        '
        'txtIdPrk
        '
        Me.txtIdPrk.AcceptsReturn = True
        Me.txtIdPrk.BackColor = System.Drawing.Color.FromArgb(CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer))
        Me.txtIdPrk.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.txtIdPrk.Enabled = False
        Me.txtIdPrk.ForeColor = System.Drawing.SystemColors.WindowText
        Me.txtIdPrk.Location = New System.Drawing.Point(45, 360)
        Me.txtIdPrk.MaxLength = 0
        Me.txtIdPrk.Name = "txtIdPrk"
        Me.txtIdPrk.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.txtIdPrk.Size = New System.Drawing.Size(44, 20)
        Me.txtIdPrk.TabIndex = 37
        '
        'txtVsIP
        '
        Me.txtVsIP.AcceptsReturn = True
        Me.txtVsIP.AcceptsTab = True
        Me.txtVsIP.BackColor = System.Drawing.Color.FromArgb(CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer))
        Me.txtVsIP.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.txtVsIP.Enabled = False
        Me.txtVsIP.ForeColor = System.Drawing.SystemColors.WindowText
        Me.txtVsIP.Location = New System.Drawing.Point(218, 360)
        Me.txtVsIP.MaxLength = 0
        Me.txtVsIP.Name = "txtVsIP"
        Me.txtVsIP.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.txtVsIP.Size = New System.Drawing.Size(78, 20)
        Me.txtVsIP.TabIndex = 1
        Me.txtVsIP.Text = "serverip"
        '
        'VitaminCtrl1
        '
        Me.VitaminCtrl1.AllowDrop = True
        Me.VitaminCtrl1.Enabled = True
        Me.VitaminCtrl1.Location = New System.Drawing.Point(0, 4)
        Me.VitaminCtrl1.Name = "VitaminCtrl1"
        Me.VitaminCtrl1.OcxState = CType(resources.GetObject("VitaminCtrl1.OcxState"), System.Windows.Forms.AxHost.State)
        Me.VitaminCtrl1.Size = New System.Drawing.Size(446, 350)
        Me.VitaminCtrl1.TabIndex = 42
        '
        'frmAVI
        '
        Me.frmAVI.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.frmAVI.Controls.Add(Me.chkShowAVIBtn)
        Me.frmAVI.Controls.Add(Me.ButtReg)
        Me.frmAVI.Controls.Add(Me.cmdStartAVIConvert)
        Me.frmAVI.Controls.Add(Me.txtAVIFR)
        Me.frmAVI.Controls.Add(Me.chkAVIAutoSize)
        Me.frmAVI.Controls.Add(Me.txtAVIW)
        Me.frmAVI.Controls.Add(Me.txtAVIH)
        Me.frmAVI.Controls.Add(Me.labAVIVFR)
        Me.frmAVI.Controls.Add(Me.labAVIW)
        Me.frmAVI.Controls.Add(Me.labAVIH)
        Me.frmAVI.ForeColor = System.Drawing.SystemColors.ControlText
        Me.frmAVI.Location = New System.Drawing.Point(0, 411)
        Me.frmAVI.Name = "frmAVI"
        Me.frmAVI.Padding = New System.Windows.Forms.Padding(0)
        Me.frmAVI.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.frmAVI.Size = New System.Drawing.Size(446, 46)
        Me.frmAVI.TabIndex = 43
        Me.frmAVI.TabStop = False
        Me.frmAVI.Text = "AVI Conversion"
        '
        'chkShowAVIBtn
        '
        Me.chkShowAVIBtn.BackColor = System.Drawing.Color.FromArgb(CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer))
        Me.chkShowAVIBtn.Cursor = System.Windows.Forms.Cursors.Default
        Me.chkShowAVIBtn.ForeColor = System.Drawing.Color.Lime
        Me.chkShowAVIBtn.Location = New System.Drawing.Point(16, 22)
        Me.chkShowAVIBtn.Name = "chkShowAVIBtn"
        Me.chkShowAVIBtn.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.chkShowAVIBtn.Size = New System.Drawing.Size(105, 17)
        Me.chkShowAVIBtn.TabIndex = 30
        Me.chkShowAVIBtn.Text = "Show AVI button"
        Me.chkShowAVIBtn.UseVisualStyleBackColor = False
        '
        'cmdStartAVIConvert
        '
        Me.cmdStartAVIConvert.BackColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Me.cmdStartAVIConvert.Cursor = System.Windows.Forms.Cursors.Default
        Me.cmdStartAVIConvert.Font = New System.Drawing.Font("Microsoft Sans Serif", 7.8!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.cmdStartAVIConvert.ForeColor = System.Drawing.Color.Green
        Me.cmdStartAVIConvert.Location = New System.Drawing.Point(139, 18)
        Me.cmdStartAVIConvert.Name = "cmdStartAVIConvert"
        Me.cmdStartAVIConvert.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.cmdStartAVIConvert.Size = New System.Drawing.Size(130, 22)
        Me.cmdStartAVIConvert.TabIndex = 29
        Me.cmdStartAVIConvert.Text = "Registra"
        Me.cmdStartAVIConvert.UseVisualStyleBackColor = False
        '
        'ButtReg
        '
        Me.ButtReg.BackColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Me.ButtReg.Font = New System.Drawing.Font("Microsoft Sans Serif", 7.8!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(0, Byte))
        Me.ButtReg.Location = New System.Drawing.Point(289, 17)
        Me.ButtReg.Margin = New System.Windows.Forms.Padding(2)
        Me.ButtReg.Name = "ButtReg"
        Me.ButtReg.Size = New System.Drawing.Size(151, 24)
        Me.ButtReg.TabIndex = 117
        Me.ButtReg.Text = "Vedere Registrazione"
        Me.ButtReg.UseVisualStyleBackColor = False
        '
        'txtAVIFR
        '
        Me.txtAVIFR.AcceptsReturn = True
        Me.txtAVIFR.BackColor = System.Drawing.SystemColors.Window
        Me.txtAVIFR.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.txtAVIFR.ForeColor = System.Drawing.SystemColors.WindowText
        Me.txtAVIFR.Location = New System.Drawing.Point(64, 48)
        Me.txtAVIFR.MaxLength = 0
        Me.txtAVIFR.Name = "txtAVIFR"
        Me.txtAVIFR.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.txtAVIFR.Size = New System.Drawing.Size(25, 20)
        Me.txtAVIFR.TabIndex = 25
        Me.txtAVIFR.Text = "15"
        Me.txtAVIFR.Visible = False
        '
        'chkAVIAutoSize
        '
        Me.chkAVIAutoSize.BackColor = System.Drawing.SystemColors.Control
        Me.chkAVIAutoSize.Cursor = System.Windows.Forms.Cursors.Default
        Me.chkAVIAutoSize.ForeColor = System.Drawing.SystemColors.ControlText
        Me.chkAVIAutoSize.Location = New System.Drawing.Point(104, 48)
        Me.chkAVIAutoSize.Name = "chkAVIAutoSize"
        Me.chkAVIAutoSize.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.chkAVIAutoSize.Size = New System.Drawing.Size(73, 22)
        Me.chkAVIAutoSize.TabIndex = 24
        Me.chkAVIAutoSize.Text = "Auto Size"
        Me.chkAVIAutoSize.UseVisualStyleBackColor = False
        Me.chkAVIAutoSize.Visible = False
        '
        'txtAVIW
        '
        Me.txtAVIW.AcceptsReturn = True
        Me.txtAVIW.BackColor = System.Drawing.SystemColors.Window
        Me.txtAVIW.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.txtAVIW.ForeColor = System.Drawing.SystemColors.WindowText
        Me.txtAVIW.Location = New System.Drawing.Point(224, 48)
        Me.txtAVIW.MaxLength = 0
        Me.txtAVIW.Name = "txtAVIW"
        Me.txtAVIW.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.txtAVIW.Size = New System.Drawing.Size(33, 20)
        Me.txtAVIW.TabIndex = 23
        Me.txtAVIW.Text = "352"
        Me.txtAVIW.Visible = False
        '
        'txtAVIH
        '
        Me.txtAVIH.AcceptsReturn = True
        Me.txtAVIH.BackColor = System.Drawing.SystemColors.Window
        Me.txtAVIH.Cursor = System.Windows.Forms.Cursors.IBeam
        Me.txtAVIH.ForeColor = System.Drawing.SystemColors.WindowText
        Me.txtAVIH.Location = New System.Drawing.Point(304, 48)
        Me.txtAVIH.MaxLength = 0
        Me.txtAVIH.Name = "txtAVIH"
        Me.txtAVIH.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.txtAVIH.Size = New System.Drawing.Size(33, 20)
        Me.txtAVIH.TabIndex = 22
        Me.txtAVIH.Text = "240"
        Me.txtAVIH.Visible = False
        '
        'labAVIVFR
        '
        Me.labAVIVFR.BackColor = System.Drawing.SystemColors.Control
        Me.labAVIVFR.Cursor = System.Windows.Forms.Cursors.Default
        Me.labAVIVFR.ForeColor = System.Drawing.SystemColors.ControlText
        Me.labAVIVFR.Location = New System.Drawing.Point(8, 48)
        Me.labAVIVFR.Name = "labAVIVFR"
        Me.labAVIVFR.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.labAVIVFR.Size = New System.Drawing.Size(49, 17)
        Me.labAVIVFR.TabIndex = 33
        Me.labAVIVFR.Text = "Video FR:"
        Me.labAVIVFR.Visible = False
        '
        'labAVIW
        '
        Me.labAVIW.BackColor = System.Drawing.SystemColors.Control
        Me.labAVIW.Cursor = System.Windows.Forms.Cursors.Default
        Me.labAVIW.ForeColor = System.Drawing.SystemColors.ControlText
        Me.labAVIW.Location = New System.Drawing.Point(184, 48)
        Me.labAVIW.Name = "labAVIW"
        Me.labAVIW.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.labAVIW.Size = New System.Drawing.Size(41, 17)
        Me.labAVIW.TabIndex = 32
        Me.labAVIW.Text = "Width:"
        Me.labAVIW.Visible = False
        '
        'labAVIH
        '
        Me.labAVIH.BackColor = System.Drawing.SystemColors.Control
        Me.labAVIH.Cursor = System.Windows.Forms.Cursors.Default
        Me.labAVIH.ForeColor = System.Drawing.SystemColors.ControlText
        Me.labAVIH.Location = New System.Drawing.Point(264, 48)
        Me.labAVIH.Name = "labAVIH"
        Me.labAVIH.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.labAVIH.Size = New System.Drawing.Size(41, 17)
        Me.labAVIH.TabIndex = 31
        Me.labAVIH.Text = "Height:"
        Me.labAVIH.Visible = False
        '
        'labChannel
        '
        Me.labChannel.BackColor = System.Drawing.Color.FromArgb(CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer), CType(CType(64, Byte), Integer))
        Me.labChannel.Cursor = System.Windows.Forms.Cursors.Default
        Me.labChannel.ForeColor = System.Drawing.Color.Lime
        Me.labChannel.Location = New System.Drawing.Point(361, 363)
        Me.labChannel.Name = "labChannel"
        Me.labChannel.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.labChannel.Size = New System.Drawing.Size(49, 17)
        Me.labChannel.TabIndex = 112
        Me.labChannel.Text = "Channel:"
        '
        'comboChannel
        '
        Me.comboChannel.BackColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Me.comboChannel.Cursor = System.Windows.Forms.Cursors.Default
        Me.comboChannel.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.comboChannel.ForeColor = System.Drawing.SystemColors.WindowText
        Me.comboChannel.Items.AddRange(New Object() {"1 - Refresh", "2 - Refresh", "3 - Refresh", "4 - Refresh", "All - Refresh"})
        Me.comboChannel.Location = New System.Drawing.Point(337, 387)
        Me.comboChannel.Name = "comboChannel"
        Me.comboChannel.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.comboChannel.Size = New System.Drawing.Size(95, 21)
        Me.comboChannel.Sorted = True
        Me.comboChannel.TabIndex = 1
        '
        'Label5
        '
        Me.Label5.BackColor = System.Drawing.SystemColors.Control
        Me.Label5.Cursor = System.Windows.Forms.Cursors.Default
        Me.Label5.ForeColor = System.Drawing.SystemColors.ControlText
        Me.Label5.Location = New System.Drawing.Point(136, 391)
        Me.Label5.Name = "Label5"
        Me.Label5.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.Label5.Size = New System.Drawing.Size(41, 17)
        Me.Label5.TabIndex = 114
        Me.Label5.Text = "Quality:"
        Me.Label5.Visible = False
        '
        'TextChannel
        '
        Me.TextChannel.BackColor = System.Drawing.Color.FromArgb(CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer), CType(CType(224, Byte), Integer))
        Me.TextChannel.Enabled = False
        Me.TextChannel.Location = New System.Drawing.Point(415, 362)
        Me.TextChannel.Margin = New System.Windows.Forms.Padding(2)
        Me.TextChannel.Name = "TextChannel"
        Me.TextChannel.Size = New System.Drawing.Size(17, 20)
        Me.TextChannel.TabIndex = 119
        '
        'PictureBox1
        '
        Me.PictureBox1.Location = New System.Drawing.Point(10, 29)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(436, 283)
        Me.PictureBox1.TabIndex = 122
        Me.PictureBox1.TabStop = False
        '
        'comboQuality
        '
        Me.comboQuality.BackColor = System.Drawing.SystemColors.Window
        Me.comboQuality.Cursor = System.Windows.Forms.Cursors.Default
        Me.comboQuality.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.comboQuality.ForeColor = System.Drawing.SystemColors.WindowText
        Me.comboQuality.Items.AddRange(New Object() {"Medium", "Standard", "Good", "Detailed", "Excellent"})
        Me.comboQuality.Location = New System.Drawing.Point(44, 387)
        Me.comboQuality.Name = "comboQuality"
        Me.comboQuality.RightToLeft = System.Windows.Forms.RightToLeft.No
        Me.comboQuality.Size = New System.Drawing.Size(81, 21)
        Me.comboQuality.TabIndex = 115
        Me.comboQuality.Visible = False
        '
        'form1
        '
        Me.AccessibleRole = System.Windows.Forms.AccessibleRole.ScrollBar
        Me.AllowDrop = True
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.AutoScroll = True
        Me.AutoSize = True
        Me.BackColor = System.Drawing.Color.FromArgb(CType(CType(192, Byte), Integer), CType(CType(255, Byte), Integer), CType(CType(192, Byte), Integer))
        Me.ClientSize = New System.Drawing.Size(460, 474)
        Me.Controls.Add(Me.PictureBox1)
        Me.Controls.Add(Me.VitaminCtrl1)
        Me.Controls.Add(Me.TextChannel)
        Me.Controls.Add(Me.comboQuality)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.comboChannel)
        Me.Controls.Add(Me.labChannel)
        Me.Controls.Add(Me.frmAVI)
        Me.Controls.Add(Me.txtIdPrk)
        Me.Controls.Add(Me.txtVsIP)
        Me.Controls.Add(Me.Label10)
        Me.Controls.Add(Me.Label2)
        Me.Cursor = System.Windows.Forms.Cursors.Default
        Me.DoubleBuffered = True
        Me.HelpButton = True
        Me.ImeMode = System.Windows.Forms.ImeMode.Off
        Me.KeyPreview = True
        Me.Location = New System.Drawing.Point(4, 23)
        Me.Name = "form1"
        Me.RightToLeft = System.Windows.Forms.RightToLeft.Yes
        Me.SizeGripStyle = System.Windows.Forms.SizeGripStyle.Show
        Me.Text = "LiveCam"
        CType(Me.VitaminCtrl1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.frmAVI.ResumeLayout(False)
        Me.frmAVI.PerformLayout()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
#End Region

    Protected Overrides Sub Finalize()
        MyBase.Finalize()
    End Sub
    Public WithEvents frmAVI As System.Windows.Forms.GroupBox
    Public WithEvents chkShowAVIBtn As System.Windows.Forms.CheckBox
    Public WithEvents cmdStartAVIConvert As System.Windows.Forms.Button
    Public WithEvents txtAVIFR As System.Windows.Forms.TextBox
    Public WithEvents chkAVIAutoSize As System.Windows.Forms.CheckBox
    Public WithEvents txtAVIW As System.Windows.Forms.TextBox
    Public WithEvents txtAVIH As System.Windows.Forms.TextBox
    Public WithEvents labAVIVFR As System.Windows.Forms.Label
    Public WithEvents labAVIW As System.Windows.Forms.Label
    Public WithEvents labAVIH As System.Windows.Forms.Label
    Public WithEvents labChannel As System.Windows.Forms.Label
    Public WithEvents comboChannel As System.Windows.Forms.ComboBox
    Public WithEvents Label5 As System.Windows.Forms.Label
    Public WithEvents VitaminCtrl1 As AxVITAMINDECODERLib.AxVitaminCtrl
    Friend WithEvents ButtReg As System.Windows.Forms.Button
    Friend WithEvents TextChannel As System.Windows.Forms.TextBox
    'Public WithEvents Timer1 As System.Windows.Forms.Timer
    Public WithEvents PictureBox1 As System.Windows.Forms.PictureBox
    Public WithEvents comboQuality As System.Windows.Forms.ComboBox
End Class