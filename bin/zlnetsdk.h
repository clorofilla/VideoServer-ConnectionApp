
#ifndef ZLNETSDK_H
#define ZLNETSDK_H

#include "assistant.h"
//#include "Eng_netsdk.h"

#ifdef WIN32

#ifdef NETSDK_EXPORTS
#define ZLNET_API  __declspec(dllexport) 
#else
#define ZLNET_API  __declspec(dllimport)
#endif

#define CALLBACK __stdcall
#define CALL_METHOD  __stdcall  //__cdecl

#else	//linux

#define ZLNET_API	extern "C"
#define CALL_METHOD
#define CALLBACK

//#define RELEASE_HEADER	//发布头文件
#ifdef RELEASE_HEADER

#define WORD	unsigned short
#define DWORD	unsigned long
#define LPDWORD	DWORD*
#define BOOL	int
#define TRUE	1
#define FALSE	0
#define BYTE	unsigned char
#define LONG	long
#define UINT	unsigned int
#define HDC		void*
#define HWND	void*
#define LPVOID	void*
#define NULL	0
typedef struct  tagRECT
{
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT;

#else	//内部编译
#include "../netsdk/osIndependent.h"
#endif

#endif


#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************
 ** 常量定义
 ***********************************************************************/
#define ZLNET_SERIALNO_LEN 			    48			// 设备序列号字符长度
#define ZLNET_MAX_DISKNUM 				256			// 最大硬盘个数
#define ZLNET_MAX_SDCARDNUM			    32			// 最大SD卡个数
#define ZLNET_MAX_BURNING_DEV_NUM		32			// 最大刻录设备个数
#define ZLNET_BURNING_DEV_NAMELEN		32			// 刻录设备名字最大长度
#define ZLNET_MAX_LINK 				    6
#define ZLNET_MAX_CHANNUM 			    32			// 最大通道个数
#define ZLNET_MAX_ALARMIN 		    	128			// 最大报警输入个数
#define ZLNET_MAX_ALARMOUT 			    64			// 最大报警输出个数
#define ZLNET_MAX_RIGHT_NUM			    200			// 用户权限个数上限
#define ZLNET_MAX_GROUP_NUM			    20			// 用户组个数上限
#define ZLNET_MAX_USER_NUM		    	200			// 用户个数上限
#define ZLNET_RIGHT_NAME_LENGTH		    32			// 权限名长度
#define ZLNET_USER_NAME_LENGTH	    	8			// 用户名长度
#define ZLNET_USER_PSW_LENGTH			8			// 用户密码长度
#define ZLNET_MEMO_LENGTH				32			// 备注长度
#define ZLNET_MAX_STRING_LEN			128
#define ZLNET_DVR_SERIAL_RETURN		    1			// 设备发送序列号回调
#define ZLNET_DVR_DISCONNECT			-1			// 验证期间设备断线回调
#define ZLNET_MAX_STRING_LINE_LEN		6			// 最多六行
#define ZLNET_MAX_PER_STRING_LEN		20			// 每行最大长度
#define ZLNET_MAX_MAIL_NAME_LEN	    	64			// 新的邮件结构体支持的用户名长度
#define ZLNET_MAX_MAIL_PSW_LEN			64			// 新的邮件结构体支持的密码长度

// 远程配置结构体相关常量
#define ZLNET_MAX_MAIL_ADDR_LEN		    128			// 邮件发(收)地址最大长度
#define ZLNET_MAX_MAIL_SUBJECT_LEN		64			// 邮件主题最大长度
#define ZLNET_MAX_IPADDR_LEN			16			// IP地址字符串长度
#define ZLNET_MACADDR_LEN				40			// MAC地址字符串长度
#define ZLNET_MAX_URL_LEN				128			// URL字符串长度
#define ZLNET_VER_SOFTWARE				128			// 软件版本号
#define ZLNET_MAX_DEV_ID_LEN			48			// 机器编号最大长度
#define	ZLNET_MAX_HOST_NAMELEN			64			// 主机名长度，
#define ZLNET_MAX_HOST_PSWLEN			32			// 密码长度
#define ZLNET_MAX_NAME_LEN				16			// 通用名字字符串长度
#define ZLNET_MAX_ETHERNET_NUM			2			// 以太网口最大个数
#define	ZLNET_DEV_SERIALNO_LEN			48			// 序列号字符串长度
#define ZLNET_DEV_TYPE_LEN				32			// 设备类型字符串长度
#define ZLNET_N_WEEKS					7			// 一周的天数	
#define ZLNET_N_TSECT					6			// 通用时间段个数
#define ZLNET_N_REC_TSECT				6			// 录像时间段个数
#define ZLNET_N_COL_TSECT				2			// 颜色时间段个数	
#define ZLNET_CHAN_NAME_LEN			    32			// 通道名长度，DVR DSP能力限制，最多32字节		
#define ZLNET_N_ENCODE_AUX				3			// 扩展码流个数	
#define ZLNET_N_TALK					1			// 最多对讲通道个数
#define ZLNET_N_COVERS					1			// 遮挡区域个数	
#define ZLNET_N_ALARM_TSECT		    	2			// 报警提示时间段个数
#define ZLNET_MAX_ALARMOUT_NUM			16			// 报警输出口个数上限
#define ZLNET_MAX_AUDIO_IN_NUM			16			// 音频输入口个数上限
#define ZLNET_MAX_VIDEO_IN_NUM			32			// 视频输入口个数上限
#define ZLNET_MAX_ALARM_IN_NUM			16			// 报警输入口个数上限
#define ZLNET_MAX_DISK_NUM				16			// 硬盘个数上限，暂定为16
#define ZLNET_MAX_DECODER_NUM			32			// 解码器(485)个数上限	
#define ZLNET_MAX_232FUNCS				10			// 232串口功能个数上限
#define ZLNET_MAX_232_NUM				2			// 232串口个数上限
#define ZLNET_MAX_DECPRO_LIST_SIZE		100			// 解码器协议列表个数上限
#define ZLNET_FTP_MAXDIRLEN		    	240			// FTP文件目录最大长度
#define ZLNET_MATRIX_MAXOUT		    	16			// 矩阵输出口最大个数
#define ZLNET_TOUR_GROUP_NUM			6			// 矩阵输出组最大个数
#define ZLNET_MAX_DDNS_NUM				10			// 设备支持的ddns服务器最大个数
#define ZLNET_MAX_SERVER_TYPE_LEN		32			// ddns服务器类型，最大字符串长度
#define ZLNET_MAX_DOMAIN_NAME_LEN		256			// ddns域名，最大字符串长度
#define ZLNET_MAX_DDNS_ALIAS_LEN		32			// ddns服务器别名，最大字符串长度
#define ZLNET_MOTION_ROW				32			// 动态检测区域的行数
#define ZLNET_MOTION_COL				32			// 动态检测区域的列数
#define	ZLNET_FTP_USERNAME_LEN			64			// FTP配置，用户名最大长度
#define	ZLNET_FTP_PASSWORD_LEN			64			// FTP配置，密码最大长度
#define	ZLNET_TIME_SECTION				2			// FTP配置，每天时间段个数
#define ZLNET_FTP_MAX_PATH				240			// FTP配置，文件路径名最大长度
#define ZLNET_INTERVIDEO_UCOM_CHANID	32			// 平台接入配置，U网通通道ID
#define ZLNET_INTERVIDEO_UCOM_DEVID	    32			// 平台接入配置，U网通设备ID
#define ZLNET_INTERVIDEO_UCOM_REGPSW	16			// 平台接入配置，U网通注册密码
#define ZLNET_INTERVIDEO_UCOM_USERNAME	32			// 平台接入配置，U网通用户名
#define ZLNET_INTERVIDEO_UCOM_USERPSW	32			// 平台接入配置，U网通密码
#define ZLNET_INTERVIDEO_NSS_IP	    	32			// 平台接入配置，中兴力维IP
#define ZLNET_INTERVIDEO_NSS_SERIAL 	32			// 平台接入配置，中兴力维serial
#define ZLNET_INTERVIDEO_NSS_USER		32			// 平台接入配置，中兴力维user
#define ZLNET_INTERVIDEO_NSS_PWD		50			// 平台接入配置，中兴力维password
#define ZLNET_INTERVIDEO_MR_ID			32			// 平台接入配置，明软ID
#define ZLNET_INTERVIDEO_MR_USERPSW		32			// 平台接入配置，明软用户名密码
#define ZLNET_MAX_VIDEO_COVER_NUM		16			// 遮挡区域最大个数
#define ZLNET_MAX_WATERMAKE_DATA		4096		// 水印图片数据最大长度
#define ZLNET_MAX_WATERMAKE_LETTER		128			// 水印文字最大长度
#define ZLNET_MAX_WLANDEVICE_NUM		10			// 最多搜索出的无线设备个数
#define ZLNET_MAX_ALARM_NAME			64			// 地址长度
#define ZLNET_MAX_REGISTER_SERVER_NUM	10			// 主动注册服务器个数
#define ZLNET_SNIFFER_FRAMEID_NUM		6			// 6个FRAME ID 选项
#define ZLNET_SNIFFER_CONTENT_NUM		4			// 每个FRAME对应的4个抓包内容
#define ZLNET_SNIFFER_CONTENT_NUM_EX   	8			// 每个FRAME对应的8个抓包内容
#define ZLNET_SNIFFER_PROTOCOL_SIZE 	20			// 协议名字长度
#define ZLNET_MAX_PROTOCOL_NAME_LENGTH  20
#define ZLNET_SNIFFER_GROUP_NUM	    	4			// 4组抓包设置
#define ZLNET_MAX_PATH_STOR			    240			// 远程目录的长度
#define ZLNET_ALARM_OCCUR_TIME_LEN		40			// 新的报警上传时间的长度
#define ZLNET_VIDEO_OSD_NAME_NUM		64			// 叠加的名称长度，目前支持32个英文，16个中文
#define ZLNET_VIDEO_CUSTOM_OSD_NUM		8			// 支持的自定义叠加的数目，不包含时间和通道
#define ZLNET_CONTROL_AUTO_REGISTER_NUM 100        // 支持定向主动注册服务器的个数
#define ZLNET_MMS_RECEIVER_NUM          100        // 支持短信接收者的个数
#define ZLNET_MMS_SMSACTIVATION_NUM     100        // 支持短信发送者的个数
#define ZLNET_MMS_DIALINACTIVATION_NUM  100        // 支持拨号发送者的个数
#define ZLNET_MAX_ALARMOUT_NUM_EX		32			// 报警输出口个数上限扩展
#define ZLNET_MAX_VIDEO_IN_NUM_EX		32			// 视频输入口个数上限扩展
#define ZLNET_MAX_ALARM_IN_NUM_EX		32			// 报警输入口个数上限
#define ZLNET_MAX_IPADDR_OR_DOMAIN_LEN	64			// IP地址字符串长度密码最大长度
#define	ZLNET_NVR_PASSWORD_LEN			64			// NVR密码最大长度
#define ZLNET_DEVICE_ENABLE_NUM			64			// 设备能力个数
#define ZLENT_DEVICE_ENABLE_STR_LEN		8			// 设备能力字符串长度		
#define ZLNET_LATTICE_LEN				2560		// 点阵定义32 * 24 * 24 / 8
#define ZLNET_CHANNEL_MODE_MAX_NUM		8			// 通道模式最大个数
#define ZLNET_RTSP_URL_MAX_NUM			10			// URL，最大字符串长度
#define ZLNET_WIFI_PSW_LENGTH			64			// wifi密码长度	
#define ZLNET_WIFI_NET_CARD_LEN			12			// 无线网卡名长度
#define ZLNET_WIFI_JUNCTION_LEN			36			// 连接点名称长度
#define ZLNET_WIFI_PROTOCOL_LNE			8			// 协议加密方式长度
#define ZLNET_MAX_WIFI_INFO_NUM			20			// wifi最大扫描个数
#define ZLNET_DEVICE_STUN_USERNAME		32			// 私网穿透用户名最大长度
#define ZLNET_DEVICE_STUN_PASSWORD		32			// 私网穿透密码最大长度
#define ZLNET_DEVICE_STUN_SERVERIP		128			// 私网穿透服务器IP（域名）长度
#define ZLNET_AEB_IP_LEN				32			// 美电贝尔GB28181 IP长度
#define ZLNET_AEB_ID_LEN				32			// 美电贝尔GB28181 ID长度
#define ZLNET_AEB_DOMAIN_LEN			128			// 美电贝尔GB28181 域名长度
#define ZLNET_AEB_PSW_LEN				32			// 美电贝尔GB28181 密码长度
#define ZLNET_AEB_INFO_LEN				32			// 美电贝尔GB28181 信息长度
#define ZLNET_AEB_ALARM_INFO_NUM		32			// AEB GB28181最大报警报警信息个数
#define ZLNET_KONLAN_IP_LEN				32			// 康联 IP长度
#define ZLNET_KONLAN_ID_LEN				32			// 康联 ID长度

// 查询类型，对应ZLNET_QueryDevState接口
#define ZLNET_DEVSTATE_COMM_ALARM		0x0001		// 查询普通报警状态(包括外部报警，视频丢失，动态检测)
#define ZLNET_DEVSTATE_SHELTER_ALARM	0x0002		// 查询遮挡报警状态
#define ZLNET_DEVSTATE_RECORDING		0x0003		// 查询录象状态
#define ZLNET_DEVSTATE_DISK			    0x0004		// 查询硬盘信息
#define ZLNET_DEVSTATE_RESOURCE		    0x0005		// 查询系统资源状态
#define ZLNET_DEVSTATE_BITRATE			0x0006		// 查询通道码流
#define ZLNET_DEVSTATE_CONN			    0x0007		// 查询设备连接状态
#define ZLNET_DEVSTATE_PROTOCAL_VER	    0x0008		// 查询网络协议版本号，pBuf = int*
#define ZLNET_DEVSTATE_TALK_ECTYPE		0x0009		// 查询设备支持的语音对讲格式列表，见结构体ZLNET_DEV_TALKFORMAT_LIST
#define ZLNET_DEVSTATE_SD_CARD			0x000A		// 查询SD卡信息(IPC类产品)
#define ZLNET_DEVSTATE_BURNING_DEV		0x000B		// 查询刻录机信息
#define ZLNET_DEVSTATE_BURNING_PROGRESS 0x000C		// 查询刻录进度
#define ZLNET_DEVSTATE_PLATFORM		    0x000D		// 查询设备支持的接入平台
#define ZLNET_DEVSTATE_CAMERA			0x000E		// 查询摄像头属性信息(IPC类产品)，pBuf = ZLNET_DEV_CAMERA_INFO *，可以有多个结构体
#define ZLNET_DEVSTATE_SOFTWARE		    0x000F		// 查询设备软件版本信息
#define ZLNET_DEVSTATE_LANGUAGE         0x0010		// 查询设备支持的语音种类
#define ZLNET_DEVSTATE_DSP				0x0011		// 查询DSP能力描述
#define	ZLNET_DEVSTATE_OEM				0x0012		// 查询OEM信息
#define	ZLNET_DEVSTATE_NET				0x0013		// 查询网络运行状态信息
#define ZLNET_DEVSTATE_TYPE				0x0014		// 查询设备类型
#define ZLNET_DEVSTATE_SNAP				0x0015		// 查询抓图功能属性(IPC类产品)
#define ZLNET_DEVSTATE_RECORD_TIME		0x0016		// 查询最早录像时间和最近录像时间
#define ZLNET_DEVSTATE_NET_RSSI		    0x0017      // 查询无线网络信号强度，见结构体ZLNET_DEV_WIRELESS_RSS_INFO
#define ZLNET_DEVSTATE_BURNING_ATTACH	0x0018		// 查询附件刻录选项
#define ZLNET_DEVSTATE_BACKUP_DEV		0x0019		// 查询备份设备列表
#define ZLNET_DEVSTATE_BACKUP_DEV_INFO	0x001a		// 查询备份设备详细信息
#define ZLNET_DEVSTATE_BACKUP_FEEDBACK	0x001b		// 备份进度反馈
#define ZLNET_DEVSTATE_ATM_QUERY_TRADE  0x001c		// 查询ATM交易类型
#define ZLNET_DEVSTATE_SIP				0x001d		// 查询sip状态
#define ZLNET_DEVSTATE_HARDWARE_ID      0x001e      // 查询硬件ID
#define ZLNET_DEVSTATE_PRODUCT_TYPE     0x001F      // 查询产品类型
#define ZLNET_DEVSTATE_SERIAL			0x0020      // 查询设备序列号

// 配置类型，对应ZLNET_GetDevConfig和ZLNET_SetDevConfig接口
#define ZLNET_DEV_DEVICECFG				0x0001		// 设备属性配置
#define ZLNET_DEV_NETCFG				0x0002		// 网络配置
#define ZLNET_DEV_CHANNELCFG			0x0003		// 图象通道配置
#define ZLNET_DEV_PREVIEWCFG 			0x0004		// 预览参数配置
#define ZLNET_DEV_RECORDCFG				0x0005		// 录像配置
#define ZLNET_DEV_COMMCFG				0x0006		// 串口属性配置
#define ZLNET_DEV_ALARMCFG 				0x0007		// 报警属性配置
#define ZLNET_DEV_TIMECFG 				0x0008		// DVR时间配置
#define ZLNET_DEV_TALKCFG				0x0009		// 对讲参数配置
#define ZLNET_DEV_AUTOMTCFG				0x000A		// 自动维护配置		
#define	ZLNET_DEV_VEDIO_MARTIX			0x000B		// 本机矩阵控制策略配置	
#define ZLNET_DEV_MULTI_DDNS			0x000C		// 多ddns服务器配置
#define ZLNET_DEV_SNAP_CFG				0x000D		// 抓图相关配置
#define ZLNET_DEV_WEB_URL_CFG			0x000E		// HTTP路径配置
#define ZLNET_DEV_FTP_PROTO_CFG			0x000F		// FTP上传配置
#define ZLNET_DEV_INTERVIDEO_CFG		0x0010		// 平台接入配置，此时channel参数代表平台类型，
													// channel=4： 代表贝尔阿尔卡特；channel=10：代表中兴力维；channel=11：代表U网通
#define ZLNET_DEV_VIDEO_COVER			0x0011		// 区域遮挡配置
#define ZLNET_DEV_TRANS_STRATEGY		0x0012		// 传输策略配置，画质优先\流畅性优先
#define ZLNET_DEV_DOWNLOAD_STRATEGY		0x0013		// 录象下载策略配置，高速下载\普通下载
#define ZLNET_DEV_WATERMAKE_CFG			0x0014		// 图象水印配置
#define ZLNET_DEV_WLAN_CFG				0x0015		// 无线网络配置
#define ZLNET_DEV_WLAN_DEVICE_CFG		0x0016		// 搜索无线设备配置
#define ZLNET_DEV_REGISTER_CFG			0x0017		// 主动注册参数配置
#define ZLNET_DEV_CAMERA_CFG			0x0018		// 摄像头属性配置
#define ZLNET_DEV_INFRARED_CFG 			0x0019		// 红外报警配置
#define ZLNET_DEV_SNIFFER_CFG			0x001A		// Sniffer抓包配置
#define ZLNET_DEV_MAIL_CFG				0x001B		// 邮件配置
#define ZLNET_DEV_DNS_CFG				0x001C		// DNS服务器配置
#define ZLNET_DEV_NTP_CFG				0x001D		// NTP配置
#define ZLNET_DEV_AUDIO_DETECT_CFG		0x001E		// 音频检测配置
#define ZLNET_DEV_STORAGE_STATION_CFG   0x001F      // 存储位置配置
#define ZLNET_DEV_PTZ_OPT_CFG			0x0020		// 云台操作属性(已经废除，请使用ZLNET_GetPtzOptAttr获取云台操作属性)
#define ZLNET_DEV_DST_CFG				0x0021      // 夏令时配置
#define ZLNET_DEV_ALARM_CENTER_CFG		0x0022		// 报警中心配置
#define ZLNET_DEV_VIDEO_OSD_CFG         0x0023		// 视频OSD叠加配置
#define ZLNET_DEV_CDMAGPRS_CFG          0x0024		// CDMA\GPRS网络配置
#define ZLNET_DEV_IPFILTER_CFG          0x0025		// IP过滤配置
#define ZLNET_DEV_TALK_ENCODE_CFG       0x0026      // 语音对讲编码配置
#define ZLNET_DEV_RECORD_PACKET_CFG     0X0027      // 录像打包长度配置
#define ZLNET_DEV_MMS_CFG               0X0028		// 短信MMS配置 
#define ZLNET_DEV_SMSACTIVATION_CFG		0X0029		// 短信激活无线连接配置
#define ZLNET_DEV_DIALINACTIVATION_CFG	0X002A		// 拨号激活无线连接配置
#define ZLNET_DEV_FILETRANS_STOP		0x002B		// 停止文件上传
#define ZLNET_DEV_FILETRANS_BURN		0x002C		// 刻录文件上传
#define ZLNET_DEV_SNIFFER_CFG_EX		0x0030		// 网络抓包配置
#define ZLNET_DEV_DOWNLOAD_RATE_CFG		0x0031		// 下载速度限制
#define ZLNET_DEV_PANORAMA_SWITCH_CFG	0x0032		// 全景切换报警配置
#define ZLNET_DEV_LOST_FOCUS_CFG		0x0033		// 失去焦点报警配置
#define ZLNET_DEV_ALARM_DECODE_CFG		0x0034		// 报警解码器配置
#define ZLNET_DEV_VIDEOOUT_CFG          0x0035      // 视频输出参数配置
#define ZLNET_DEV_POINT_CFG				0x0036		// 预制点使能配置
#define ZLNET_DEV_IP_COLLISION_CFG      0x0037      // Ip冲突检测报警配置
#define ZLNET_DEV_OSD_ENABLE_CFG		0x0038		// OSD叠加使能配置
#define ZLNET_DEV_LOCALALARM_CFG 		0x0039		// 本地报警配置(结构体ZLNET_ALARMIN_CFG_EX)
#define ZLNET_DEV_NETALARM_CFG 			0x003A		// 网络报警配置(结构体ZLNET_ALARMIN_CFG_EX)
#define ZLNET_DEV_MOTIONALARM_CFG 		0x003B		// 动检报警配置(结构体ZLNET_MOTION_DETECT_CFG_EX)
#define ZLNET_DEV_VIDEOLOSTALARM_CFG 	0x003C		// 视频丢失报警配置(结构体ZLNET_VIDEO_LOST_CFG_EX)
#define ZLNET_DEV_BLINDALARM_CFG 		0x003D		// 视频遮挡报警配置(结构体ZLNET_BLIND_CFG_EX)
#define ZLNET_DEV_DISKALARM_CFG 		0x003E		// 硬盘报警配置(结构体ZLNET_DISK_ALARM_CFG_EX)
#define ZLNET_DEV_NETBROKENALARM_CFG 	0x003F		// 网络中断报警配置(结构体ZLNET_NETBROKEN_ALARM_CFG_EX)
#define ZLNET_DEV_ENCODER_CFG		    0x0040      // 数字通道的前端编码器信息（混合DVR使用，结构体ZLNET_DEV_ENCODER_CFG）
#define ZLNET_DEV_TV_ADJUST_CFG         0x0041      // TV调节配置（channel代表TV号(0开始)，类型结构体）
#define ZLNET_DEV_ABOUT_VEHICLE_CFG		0x0042		// 车载相关配置，北京公交使用
#define ZLNET_DEV_ATM_OVERLAY_ABILITY	0x0043		// 获取atm叠加支持能力信息
#define ZLNET_DEV_ATM_OVERLAY_CFG		0x0044		// atm叠加配置，新atm特有
#define ZLNET_DEV_DECODER_TOUR_CFG		0x0045		// 解码器解码轮巡配置
#define ZLNET_DEV_SIP_CFG				0x0046		// SIP配置

#define ZLNET_DEV_LATTICE				0x0047		// 通道名点阵
#define ZLNET_DEV_NVR_CHANNEL_MODE		0x0048		// NVR通道模式

#define ZLNET_DEV_USER_END_CFG			1000

// 报警类型，对应ZLNET_StartListen接口
#define ZLNET_COMM_ALARM				0x1100		// 常规报警(包括外部报警，视频丢失，动态检测)
#define ZLNET_SHELTER_ALARM				0x1101		// 视频遮挡报警
#define ZLNET_DISK_FULL_ALARM			0x1102		// 硬盘满报警
#define ZLNET_DISK_ERROR_ALARM			0x1103		// 硬盘故障报警
#define ZLNET_SOUND_DETECT_ALARM		0x1104		// 音频检测报警
#define ZLNET_ALARM_DECODER_ALARM		0x1105		// 报警解码器报警
#define ZLNET_ALARM_IDVR_ALARM			0x1106		// 智能ATM报警
#define ZLNET_ALARM_IDVR_STAFFCOUNT		0x1107		// 智能人员统计信息
#define ZLNET_ALARM_IDVR_PLATEID		0x1108		// 智能车牌信息

// 扩展报警类型，对应ZLNET_StartListenEx接口
#define ZLNET_ALARM_ALARM_EX			0x2101		// 外部报警
#define ZLNET_MOTION_ALARM_EX			0x2102		// 动态检测报警
#define ZLNET_VIDEOLOST_ALARM_EX		0x2103		// 视频丢失报警
#define ZLNET_SHELTER_ALARM_EX			0x2104		// 视频遮挡报警
#define ZLNET_SOUND_DETECT_ALARM_EX		0x2105		// 音频检测报警
#define ZLNET_DISKFULL_ALARM_EX			0x2106		// 硬盘满报警
#define ZLNET_DISKERROR_ALARM_EX		0x2107		// 坏硬盘报警
#define ZLNET_ENCODER_ALARM_EX			0x210A		// 编码器报警
#define ZLNET_URGENCY_ALARM_EX			0x210B		// 紧急报警
#define ZLNET_WIRELESS_ALARM_EX			0x210C		// 无线报警
#define ZLNET_NEW_SOUND_DETECT_ALARM_EX 0x210D		// 新音频检测报警，报警信息的结构体见ZLNET_NEW_SOUND_ALARM_STATE；
#define ZLNET_ALARM_DECODER_ALARM_EX	0x210E		// 报警解码器报警
#define ZLNET_DECODER_DECODE_ABILITY	0x210F		// 解码器：解码能力报警
#define ZLNET_FDDI_DECODER_ABILITY		0x2110		// 光纤编码器状态报警
#define ZLNET_PANORAMA_SWITCH_ALARM_EX	0x2111		// 切换场景报警
#define ZLNET_LOSTFOCUS_ALARM_EX		0x2112		// 失去焦点报警
#define ZLNET_OEMSTATE_EX				0x2113		// oem报停状态
#define ZLNET_DSP_ALARM_EX				0x2114		// DSP报警
#define ZLNET_ATMPOS_BROKEN_EX			0x2115		// atm和pos机断开报警， 0：连接断开 1：连接正常
#define ZLNET_RECORD_CHANGED_EX			0x2116		// 录像状态变化报警
#define ZLNET_DEVICE_REBOOT_EX			0x2118		// 设备重启报警
#define ZLNET_CONFIG_CHANGED_EX			0x2117		// 配置发生变化报警

// 事件类型
#define ZLNET_CONFIG_RESULT_EVENT_EX	0x3000		// 修改配置的返回码；返回结构见DEV_SET_RESULT
#define ZLNET_REBOOT_EVENT_EX			0x3001		// 设备重启事件；如果未发送重启命令，当前修改的配置不会立即生效
#define ZLNET_AUTO_TALK_START_EX		0x3002		// 设备主动邀请开始语音对讲
#define ZLNET_AUTO_TALK_STOP_EX			0x3003		// 设备主动停止语音对讲
#define ZLNET_CONFIG_CHANGE_EX			0x3004		// 设备配置发生改变

// 报警上传功能的报警类型，对应ZLNET_StartService接口、NEW_ALARM_UPLOAD结构体.
#define ZLNET_UPLOAD_ALARM				0x4000		// 外部报警		
#define ZLNET_UPLOAD_MOTION_ALARM		0x4001		// 动态检测报警
#define ZLNET_UPLOAD_VIDEOLOST_ALARM	0x4002		// 视频丢失报警
#define ZLNET_UPLOAD_SHELTER_ALARM		0x4003		// 视频遮挡报警
#define ZLNET_UPLOAD_SOUND_DETECT_ALARM 0x4004		// 音频检测报警
#define ZLNET_UPLOAD_DISKFULL_ALARM		0x4005		// 硬盘满报警
#define ZLNET_UPLOAD_DISKERROR_ALARM	0x4006		// 坏硬盘报警
#define ZLNET_UPLOAD_ENCODER_ALARM		0x4007		// 编码器报警
#define ZLNET_UPLOAD_DECODER_ALARM		0x400B		// 报警解码器报警
#define ZLNET_UPLOAD_EVENT				0x400C		// 定时上传的

// 异步接口回调类型
#define ZLNET_RESPONSE_DECODER_CTRL_TV		0x00000001	// 对应ZLNET_CtrlDecTVScreen接口
#define ZLNET_RESPONSE_DECODER_SWITCH_TV	0x00000002	// 对应ZLNET_SwitchDecTVEncoder接口
#define ZLNET_RESPONSE_DECODER_PLAYBACK		0x00000003	// 对应ZLNET_DecTVPlayback接口

// 分辨率列表，用于与分辨率掩码进行与、或操作
#define	ZLNET_CAPTURE_SIZE_D1			0x00000001
#define ZLNET_CAPTURE_SIZE_HD1			0x00000002
#define ZLNET_CAPTURE_SIZE_BCIF			0x00000004
#define ZLNET_CAPTURE_SIZE_CIF			0x00000008
#define ZLNET_CAPTURE_SIZE_QCIF			0x00000010	
#define ZLNET_CAPTURE_SIZE_VGA			0x00000020	
#define ZLNET_CAPTURE_SIZE_QVGA			0x00000040
#define ZLNET_CAPTURE_SIZE_SVCD			0x00000080
#define ZLNET_CAPTURE_SIZE_QQVGA		0x00000100
#define ZLNET_CAPTURE_SIZE_SVGA			0x00000200
#define ZLNET_CAPTURE_SIZE_XVGA			0x00000400
#define ZLNET_CAPTURE_SIZE_WXGA			0x00000800
#define ZLNET_CAPTURE_SIZE_SXGA			0x00001000
#define ZLNET_CAPTURE_SIZE_WSXGA		0x00002000   
#define ZLNET_CAPTURE_SIZE_UXGA			0x00004000
#define ZLNET_CAPTURE_SIZE_WUXGA        0x00008000
#define ZLNET_CAPTURE_SIZE_LFT          0x00010000
#define ZLNET_CAPTURE_SIZE_720		    0x00020000
#define ZLNET_CAPTURE_SIZE_1080			0x00040000
#define ZLNET_CAPTURE_SIZE_1_3M			0x00080000

// 编码模式列表，用于与编码模式掩码进行与、或操作
#define ZLNET_CAPTURE_COMP_DIVX_MPEG4	0x00000001
#define ZLNET_CAPTURE_COMP_MS_MPEG4 	0x00000002
#define ZLNET_CAPTURE_COMP_MPEG2		0x00000004
#define ZLNET_CAPTURE_COMP_MPEG1		0x00000008
#define ZLNET_CAPTURE_COMP_H263			0x00000010
#define ZLNET_CAPTURE_COMP_MJPG			0x00000020
#define ZLNET_CAPTURE_COMP_FCC_MPEG4	0x00000040
#define ZLNET_CAPTURE_COMP_H264			0x00000080

// 报警联动动作，用于与报警联动动作掩码进行与、或操作
#define ZLNET_ALARM_UPLOAD				0x00000001
#define ZLNET_ALARM_RECORD				0x00000002
#define ZLNET_ALARM_PTZ			 		0x00000004
#define ZLNET_ALARM_MAIL				0x00000008
#define ZLNET_ALARM_TOUR				0x00000010
#define ZLNET_ALARM_TIP					0x00000020
#define ZLNET_ALARM_OUT					0x00000040
#define ZLNET_ALARM_FTP_UL				0x00000080
#define ZLNET_ALARM_BEEP				0x00000100
#define ZLNET_ALARM_VOICE				0x00000200
#define ZLNET_ALARM_SNAP				0x00000400

// "恢复默认配置"掩码，可进行与、或操作
#define ZLNET_RESTORE_COMMON			0x00000001	// 普通设置
#define ZLNET_RESTORE_CODING			0x00000002	// 编码设置
#define ZLNET_RESTORE_VIDEO				0x00000004	// 录像设置
#define ZLNET_RESTORE_COMM				0x00000008	// 串口设置
#define ZLNET_RESTORE_NETWORK			0x00000010	// 网络设置
#define ZLNET_RESTORE_ALARM				0x00000020	// 报警设置
#define ZLNET_RESTORE_VIDEODETECT		0x00000040	// 视频检测
#define ZLNET_RESTORE_PTZ				0x00000080	// 云台控制
#define ZLNET_RESTORE_OUTPUTMODE		0x00000100	// 输出模式
#define ZLNET_RESTORE_CHANNELNAME		0x00000200	// 通道名称
#define ZLNET_RESTORE_VIDEO_COLOR       0x00010000  // 视频颜色参数恢复默认
#define ZLNET_RESTORE_ALL				0x80000000	// 全部重置

// 云台属性列表
// 低四个字节掩码
#define ZLNET_PTZ_DIRECTION				0x00000001	// 方向
#define ZLNET_PTZ_ZOOM					0x00000002	// 变倍
#define ZLNET_PTZ_FOCUS					0x00000004	// 聚焦
#define ZLNET_PTZ_IRIS					0x00000008	// 光圈
#define ZLNET_PTZ_ALARM					0x00000010	// 报警功能
#define ZLNET_PTZ_LIGHT					0x00000020	// 灯光
#define ZLNET_PTZ_SETPRESET				0x00000040	// 设置预置点
#define ZLNET_PTZ_CLEARPRESET			0x00000080	// 清除预置点
#define ZLNET_PTZ_GOTOPRESET			0x00000100	// 转至预置点
#define ZLNET_PTZ_AUTOPANON				0x00000200	// 水平开始
#define ZLNET_PTZ_AUTOPANOFF			0x00000400	// 水平结束
#define ZLNET_PTZ_SETLIMIT				0x00000800	// 设置边界
#define ZLNET_PTZ_AUTOSCANON			0x00001000	// 自动扫描开始
#define ZLNET_PTZ_AUTOSCANOFF			0x00002000	// 自动扫描开停止
#define ZLNET_PTZ_ADDTOUR				0x00004000	// 增加巡航点
#define ZLNET_PTZ_DELETETOUR			0x00008000	// 删除巡航点
#define ZLNET_PTZ_STARTTOUR				0x00010000	// 开始巡航
#define ZLNET_PTZ_STOPTOUR				0x00020000	// 结束巡航
#define ZLNET_PTZ_CLEARTOUR				0x00040000	// 删除巡航
#define ZLNET_PTZ_SETPATTERN			0x00080000	// 设置模式
#define ZLNET_PTZ_STARTPATTERN			0x00100000	// 开始模式
#define ZLNET_PTZ_STOPPATTERN			0x00200000	// 停止模式
#define ZLNET_PTZ_CLEARPATTERN			0x00400000	// 清除模式
#define ZLNET_PTZ_POSITION				0x00800000	// 快速定位
#define ZLNET_PTZ_AUX					0x01000000	// 辅助开关
#define ZLNET_PTZ_MENU					0x02000000	// 球机菜单
#define ZLNET_PTZ_EXIT					0x04000000	// 退出球机菜单
#define ZLNET_PTZ_ENTER					0x08000000	// 确认
#define ZLNET_PTZ_ESC					0x10000000	// 取消
#define ZLNET_PTZ_MENUUPDOWN			0x20000000	// 菜单上下操作
#define ZLNET_PTZ_MENULEFTRIGHT			0x40000000	// 菜单左右操作
#define ZLNET_PTZ_OPT_NUM				0x80000000	// 操作的个数
// 高四个字节掩码
#define ZLNET_PTZ_DEV					0x00000001	// 云台控制
#define ZLNET_PTZ_MATRIX				0x00000002	// 矩阵控制

// 抓图视频编码类型
#define ZLNET_CODETYPE_MPEG4			0
#define ZLNET_CODETYPE_H264				1
#define ZLNET_CODETYPE_JPG				2

// 码流控制列表
#define ZLNET_CAPTURE_BRC_CBR			0
#define ZLNET_CAPTURE_BRC_VBR			1
//#define ZLNET_CAPTURE_BRC_MBR			2

#define ZLNET_WEEKS_NUM				7		//一个星期7天
#define ZLNET_TSECT_NUM				6		//每天6个时间段
//智能ATM
#define ZLNET_IVA_MAX_CHANNEL		4		//最多通道数
#define ZLNET_IVA_MAX_NUM_ATMALARM_RECT		10		//最多区域数
#define ZLNET_IVA_MAX_LOG_NUM				200		//最多日志条数
//区域配置结构体相关常量
#define ZLNET_IVA_MAX_NUM_REGION				20		//最多检测区域数量
#define ZLNET_IVA_MAX_AREA_WARN				10			//最多报警区域数量
#define	ZLNET_IVA_MAX_NUM_KEYBOARD_REGION		1		//最多键盘区域数量
#define	ZLNET_IVA_MAX_NUM_CARDPORT_REGION		1		//最多插卡口区域数量
#define	ZLNET_IVA_MAX_NUM_KEYMASK_REGION		1		//最多键盘罩区域数量
#define	ZLNET_IVA_MAX_NUM_HUMAN_REGION			1		//最多人员活动区域数量
#define	ZLNET_IVA_MAX_NUM_FACEHUMAN_REGION		1		//最多人脸区域数量
#define	ZLNET_IVA_MAX_NUM_WORN_REGION			1		//屏蔽区域数量
#define ZLNET_IVA_MAX_NUM_OBJSIZE				1		//最小检测尺寸	
#define ZLNET_IVA_MAX_POLYGON_POINT				20		//多边形点数
#define ZLNET_IVA_MAX_NUM_DETECT_FACE_AREA		1		//人脸检测区域数量
#define ZLNET_IVA_MAX_NUM_FACE_AREA				3		//人脸区域数量
#define ZLNET_IVA_MAX_NUM_LICENSE_PLATE			5		//车牌最多检测区域数量
#define ZLNET_IVA_MAX_NUM_DETECT_LINE			1		//人员计数最多检测线数量
#define ZLNET_IVA_MAX_NUM_PROCESS_AREA			1		//处理区域最多个数
#define ZLNET_IVA_MAX_SHIELDED_AREA_NUM			9		//屏蔽区域最多个数
#define ZLNET_IVA_MAX_ALARM_RULE_REGION_NUM		9		//最多报警规则个数
#define ZLNET_IVA_MAX_SSB_AREA					20		//自助厅处理区域(1) + 屏蔽区域(10) + 操作区域(9)
#define ZLNET_IVA_MAX_NUM_SSBALARM				10		//自助银行报警区域
#define ZLNET_IVA_MAX_NUM_FACEALARM			10		//人脸报警区域
#define ZLNET_IVA_MAX_BZS_PROCESS_NUM	ZLNET_IVA_MAX_NUM_PROCESS_AREA + ZLNET_IVA_MAX_SHIELDED_AREA_NUM
#define ZLNET_IVA_MAX_SSB_WITHDRAWALS_NUM		9		//自助厅最多取款区域
#define ZLNET_IVA_MAX_SSB_HALL_SHIELDED_NUM	    10   	//自助厅屏蔽区域最多个数
#define ZLNET_IVA_MAX_SSB_ROOM_SHIELDED_NUM		10		//加钞间屏蔽区域最多个数
#define ZLNET_IVA_MAX_SSB_POLYGON_POINT			10		//SSB加钞间多边形点数
#define ZLNET_IVA_MAX_BZS_POLYGON_POINT			10		//周界多边形点数
#define ZLNET_IVA_MAX_BZS_RULE_REGION			18		//周界规则个数
//GPIO
#define	ZLNET_IVA_MAX_GPI_NUM					4		//GPIO输入端口数量
#define ZLNET_IVA_MAX_GPO_NUM					2		//GPIO输出端口数量

#define ZLNET_IVA_MAX_REGIST_NUM				16		// 设备支持的最大主动注册IP数量
#define ZLNET_IVA_MAX_ONLINE					10		// 最多在线用户
//算法调试
#define ZLNET_IVA_ARITHMETIC_DEBUG_LEN			2		//算法调试个数
#define MAX_NUM_SSB_TRACKEDINFO					10		//SSB算法调试信息的个数
//轨迹跟踪
#define MAX_TRACK_OBJ_NUM						10		//轨迹跟踪物体最大个数			
#define MAX_TRACK_COUNT							120		//轨迹跟踪回调最大上传个数
//智能人员统计
#define ZLNET_IVA_MAX_NUM_STAFFCOUNT_RECT		20		//人员统计区域最多数量
#define ZLNET_IVA_MAX_NUM_STAFFCOUNT_PIC		4		//人员统计图片最多数量
//智能人脸
#define ZLNET_IVA_MAX_FACE_AREA_NUM				1		//人脸检测最多区域个数
#define ZLNET_IVA_MAX_FACE_OVERLAY_NUM			1		//人脸叠加区域最多个数
#define ZLNET_IVA_MAX_NUM_FACE_TRACKEDINFO				10		//人脸算法调试信息结果个数
#define ZLNET_IVA_MAX_FACE_SHIELDED_AREA_NUM			10		//屏蔽区域最多个数

//用户音频
#define ZLNET_IVA_MAX_AUDIO_NUM			8	//用户音频数最大个数
#define ZLNET_IVA_MAX_SECTION_NUM		8   //用户音频规则最大个数

#define ZLNET_MAX_REV_LIST				5	//反向连接最大配置服务器数量

// 错误类型代号，对应ZLNET_GetLastError接口的返回值
#define _EC(x)							(0x80000000|x)
#define ZLNET_NOERROR 					0			// 没有错误
#define ZLNET_ERROR						-1			// 未知错误
#define ZLNET_SYSTEM_ERROR				_EC(1)		// Windows系统出错
#define ZLNET_NETWORK_ERROR				_EC(2)		// 网络错误，可能是因为网络超时
#define ZLNET_DEV_VER_NOMATCH			_EC(3)		// 设备协议不匹配
#define ZLNET_INVALID_HANDLE			_EC(4)		// 句柄无效
#define ZLNET_OPEN_CHANNEL_ERROR		_EC(5)		// 打开通道失败
#define ZLNET_CLOSE_CHANNEL_ERROR		_EC(6)		// 关闭通道失败
#define ZLNET_ILLEGAL_PARAM				_EC(7)		// 用户参数不合法
#define ZLNET_SDK_INIT_ERROR			_EC(8)		// SDK初始化出错
#define ZLNET_SDK_UNINIT_ERROR			_EC(9)		// SDK清理出错
#define ZLNET_RENDER_OPEN_ERROR			_EC(10)		// 申请render资源出错
#define ZLNET_DEC_OPEN_ERROR			_EC(11)		// 打开解码库出错
#define ZLNET_DEC_CLOSE_ERROR			_EC(12)		// 关闭解码库出错
#define ZLNET_MULTIPLAY_NOCHANNEL		_EC(13)		// 多画面预览中检测到通道数为0
#define ZLNET_TALK_INIT_ERROR			_EC(14)		// 录音库初始化失败
#define ZLNET_TALK_NOT_INIT				_EC(15)		// 录音库未经初始化
#define	ZLNET_TALK_SENDDATA_ERROR		_EC(16)		// 发送音频数据出错
#define ZLNET_REAL_ALREADY_SAVING		_EC(17)		// 实时数据已经处于保存状态
#define ZLNET_NOT_SAVING				_EC(18)		// 未保存实时数据
#define ZLNET_OPEN_FILE_ERROR			_EC(19)		// 打开文件出错
#define ZLNET_PTZ_SET_TIMER_ERROR		_EC(20)		// 启动云台控制定时器失败
#define ZLNET_RETURN_DATA_ERROR			_EC(21)		// 对返回数据的校验出错
#define ZLNET_INSUFFICIENT_BUFFER		_EC(22)		// 没有足够的缓存
#define ZLNET_NOT_SUPPORTED				_EC(23)		// 当前SDK未支持该功能
#define ZLNET_NO_RECORD_FOUND			_EC(24)		// 查询不到录象
#define ZLNET_NOT_AUTHORIZED			_EC(25)		// 无操作权限
#define ZLNET_NOT_NOW					_EC(26)		// 暂时无法执行
#define ZLNET_NO_TALK_CHANNEL			_EC(27)		// 未发现对讲通道
#define ZLNET_NO_AUDIO					_EC(28)		// 未发现音频
#define ZLNET_NO_INIT					_EC(29)		// 网络SDK未经初始化
#define ZLNET_DOWNLOAD_END				_EC(30)		// 下载已结束
#define ZLNET_EMPTY_LIST				_EC(31)		// 查询结果为空
#define ZLNET_ERROR_GETCFG_SYSATTR		_EC(32)		// 获取系统属性配置失败
#define ZLNET_ERROR_GETCFG_SERIAL		_EC(33)		// 获取序列号失败
#define ZLNET_ERROR_GETCFG_GENERAL		_EC(34)		// 获取常规属性失败
#define ZLNET_ERROR_GETCFG_DSPCAP		_EC(35)		// 获取DSP能力描述失败
#define ZLNET_ERROR_GETCFG_NETCFG		_EC(36)		// 获取网络配置失败
#define ZLNET_ERROR_GETCFG_CHANNAME		_EC(37)		// 获取通道名称失败
#define ZLNET_ERROR_GETCFG_VIDEO		_EC(38)		// 获取视频属性失败
#define ZLNET_ERROR_GETCFG_RECORD		_EC(39)		// 获取录象配置失败
#define ZLNET_ERROR_GETCFG_PRONAME		_EC(40)		// 获取解码器协议名称失败
#define ZLNET_ERROR_GETCFG_FUNCNAME		_EC(41)		// 获取232串口功能名称失败
#define ZLNET_ERROR_GETCFG_485DECODER	_EC(42)		// 获取解码器属性失败
#define ZLNET_ERROR_GETCFG_232COM		_EC(43)		// 获取232串口配置失败
#define ZLNET_ERROR_GETCFG_ALARMIN		_EC(44)		// 获取外部报警输入配置失败
#define ZLNET_ERROR_GETCFG_ALARMDET		_EC(45)		// 获取动态检测报警失败
#define ZLNET_ERROR_GETCFG_SYSTIME		_EC(46)		// 获取设备时间失败
#define ZLNET_ERROR_GETCFG_PREVIEW		_EC(47)		// 获取预览参数失败
#define ZLNET_ERROR_GETCFG_AUTOMT		_EC(48)		// 获取自动维护配置失败
#define ZLNET_ERROR_GETCFG_VIDEOMTRX	_EC(49)		// 获取视频矩阵配置失败
#define ZLNET_ERROR_GETCFG_COVER		_EC(50)		// 获取区域遮挡配置失败
#define ZLNET_ERROR_GETCFG_WATERMAKE	_EC(51)		// 获取图象水印配置失败
#define ZLNET_ERROR_SETCFG_GENERAL		_EC(55)		// 修改常规属性失败
#define ZLNET_ERROR_SETCFG_NETCFG		_EC(56)		// 修改网络配置失败
#define ZLNET_ERROR_SETCFG_CHANNAME		_EC(57)		// 修改通道名称失败
#define ZLNET_ERROR_SETCFG_VIDEO		_EC(58)		// 修改视频属性失败
#define ZLNET_ERROR_SETCFG_RECORD		_EC(59)		// 修改录象配置失败
#define ZLNET_ERROR_SETCFG_485DECODER	_EC(60)		// 修改解码器属性失败
#define ZLNET_ERROR_SETCFG_232COM		_EC(61)		// 修改232串口配置失败
#define ZLNET_ERROR_SETCFG_ALARMIN		_EC(62)		// 修改外部输入报警配置失败
#define ZLNET_ERROR_SETCFG_ALARMDET	    _EC(63)		// 修改动态检测报警配置失败
#define ZLNET_ERROR_SETCFG_SYSTIME		_EC(64)		// 修改设备时间失败
#define ZLNET_ERROR_SETCFG_PREVIEW		_EC(65)		// 修改预览参数失败
#define ZLNET_ERROR_SETCFG_AUTOMT		_EC(66)		// 修改自动维护配置失败
#define ZLNET_ERROR_SETCFG_VIDEOMTRX	_EC(67)		// 修改视频矩阵配置失败
#define ZLNET_ERROR_SETCFG_COVER		_EC(68)		// 修改区域遮挡配置失败
#define ZLNET_ERROR_SETCFG_WATERMAKE	_EC(69)		// 修改图象水印配置失败
#define ZLNET_ERROR_SETCFG_WLAN			_EC(70)		// 修改无线网络信息失败
#define ZLNET_ERROR_SETCFG_WLANDEV		_EC(71)		// 选择无线网络设备失败
#define ZLNET_ERROR_SETCFG_REGISTER		_EC(72)		// 修改主动注册参数配置失败
#define ZLNET_ERROR_SETCFG_CAMERA		_EC(73)		// 修改摄像头属性配置失败
#define ZLNET_ERROR_SETCFG_INFRARED		_EC(74)		// 修改红外报警配置失败
#define ZLNET_ERROR_SETCFG_SOUNDALARM	_EC(75)		// 修改音频报警配置失败
#define ZLNET_ERROR_SETCFG_STORAGE      _EC(76)		// 修改存储位置配置失败
#define ZLNET_AUDIOENCODE_NOTINIT		_EC(77)		// 音频编码接口没有成功初始化
#define ZLNET_DATA_TOOLONGH				_EC(78)		// 数据过长
#define ZLNET_UNSUPPORTED				_EC(79)		// 设备不支持该操作
#define ZLNET_DEVICE_BUSY				_EC(80)		// 设备资源不足
#define ZLNET_SERVER_STARTED			_EC(81)		// 服务器已经启动
#define ZLNET_SERVER_STOPPED			_EC(82)		// 服务器尚未成功启动
#define ZLNET_LISTER_INCORRECT_SERIAL	_EC(83)		// 输入序列号有误
#define ZLNET_QUERY_DISKINFO_FAILED		_EC(84)		// 获取硬盘信息失败
#define ZLNET_ERROR_GETCFG_SESSION		_EC(85)		// 获取连接Session信息
#define ZLNET_USER_FLASEPWD_TRYTIME		_EC(86)		// 输入密码错误超过限制次数
#define ZLNET_LOGIN_ERROR_PASSWORD		_EC(100)	// 密码不正确
#define ZLNET_LOGIN_ERROR_USER			_EC(101)	// 帐户不存在
#define ZLNET_LOGIN_ERROR_TIMEOUT		_EC(102)	// 等待登录返回超时
#define ZLNET_LOGIN_ERROR_RELOGGIN		_EC(103)	// 帐号已登录
#define ZLNET_LOGIN_ERROR_LOCKED		_EC(104)	// 帐号已被锁定
#define ZLNET_LOGIN_ERROR_BLACKLIST		_EC(105)	// 帐号已被列为黑名单
#define ZLNET_LOGIN_ERROR_BUSY			_EC(106)	// 资源不足，系统忙
#define ZLNET_LOGIN_ERROR_CONNECT		_EC(107)	// 登录设备超时，请检查网络并重试
#define ZLNET_LOGIN_ERROR_NETWORK		_EC(108)	// 网络连接失败
#define ZLNET_LOGIN_ERROR_SUBCONNECT	_EC(109)	// 登录设备成功，但无法创建视频通道，请检查网络状况
#define ZLNET_RENDER_SOUND_ON_ERROR		_EC(120)	// Render库打开音频出错
#define ZLNET_RENDER_SOUND_OFF_ERROR	_EC(121)	// Render库关闭音频出错
#define ZLNET_RENDER_SET_VOLUME_ERROR	_EC(122)	// Render库控制音量出错
#define ZLNET_RENDER_ADJUST_ERROR		_EC(123)	// Render库设置画面参数出错
#define ZLNET_RENDER_PAUSE_ERROR		_EC(124)	// Render库暂停播放出错
#define ZLNET_RENDER_SNAP_ERROR			_EC(125)	// Render库抓图出错
#define ZLNET_RENDER_STEP_ERROR			_EC(126)	// Render库步进出错
#define ZLNET_RENDER_FRAMERATE_ERROR	_EC(127)	// Render库设置帧率出错
#define ZLNET_GROUP_EXIST				_EC(140)	// 组名已存在
#define	ZLNET_GROUP_NOEXIST				_EC(141)	// 组名不存在
#define ZLNET_GROUP_RIGHTOVER			_EC(142)	// 组的权限超出权限列表范围
#define ZLNET_GROUP_HAVEUSER			_EC(143)	// 组下有用户，不能删除
#define ZLNET_GROUP_RIGHTUSE			_EC(144)	// 组的某个权限被用户使用，不能出除
#define ZLNET_GROUP_SAMENAME			_EC(145)	// 新组名同已有组名重复
#define	ZLNET_USER_EXIST				_EC(146)	// 用户已存在
#define ZLNET_USER_NOEXIST				_EC(147)	// 用户不存在
#define ZLNET_USER_RIGHTOVER			_EC(148)	// 用户权限超出组权限
#define ZLNET_USER_PWD					_EC(149)	// 保留帐号，不容许修改密码
#define ZLNET_USER_FLASEPWD				_EC(150)	// 密码不正确
#define ZLNET_USER_NOMATCHING			_EC(151)	// 密码不匹配
#define ZLNET_ERROR_GETCFG_ETHERNET		_EC(300)	// 获取网卡配置失败
#define ZLNET_ERROR_GETCFG_WLAN			_EC(301)	// 获取无线网络信息失败
#define ZLNET_ERROR_GETCFG_WLANDEV		_EC(302)	// 获取无线网络设备失败
#define ZLNET_ERROR_GETCFG_REGISTER		_EC(303)	// 获取主动注册参数失败
#define ZLNET_ERROR_GETCFG_CAMERA		_EC(304)	// 获取摄像头属性失败
#define ZLNET_ERROR_GETCFG_INFRARED		_EC(305)	// 获取红外报警配置失败
#define ZLNET_ERROR_GETCFG_SOUNDALARM	_EC(306)	// 获取音频报警配置失败
#define ZLNET_ERROR_GETCFG_STORAGE      _EC(307)	// 获取存储位置配置失败
#define ZLNET_ERROR_GETCFG_MAIL			_EC(308)	// 获取邮件配置失败
#define ZLNET_CONFIG_DEVBUSY			_EC(309)	// 暂时无法设置
#define ZLNET_CONFIG_DATAILLEGAL		_EC(310)	// 配置数据不合法
#define ZLNET_ERROR_GETCFG_DST          _EC(311)    // 获取夏令时配置失败
#define ZLNET_ERROR_SETCFG_DST          _EC(312)    // 设置夏令时配置失败
#define ZLNET_ERROR_GETCFG_VIDEO_OSD    _EC(313)    // 获取视频OSD叠加配置失败
#define ZLNET_ERROR_SETCFG_VIDEO_OSD    _EC(314)    // 设置视频OSD叠加配置失败
#define ZLNET_ERROR_GETCFG_GPRSCDMA     _EC(315)    // 获取CDMA\GPRS网络配置失败
#define ZLNET_ERROR_SETCFG_GPRSCDMA     _EC(316)    // 设置CDMA\GPRS网络配置失败
#define ZLNET_ERROR_GETCFG_IPFILTER     _EC(317)    // 获取IP过滤配置失败
#define ZLNET_ERROR_SETCFG_IPFILTER     _EC(318)    // 设置IP过滤配置失败
#define ZLNET_ERROR_GETCFG_TALKENCODE   _EC(319)    // 获取语音对讲编码配置失败
#define ZLNET_ERROR_SETCFG_TALKENCODE   _EC(320)    // 设置语音对讲编码配置失败
#define ZLNET_ERROR_GETCFG_RECORDLEN    _EC(321)    // 获取录像打包长度配置失败
#define ZLNET_ERROR_SETCFG_RECORDLEN    _EC(322)    // 设置录像打包长度配置失败
#define	ZLNET_DONT_SUPPORT_SUBAREA		_EC(323)	// 不支持网络硬盘分区
#define	ZLNET_ERROR_GET_AUTOREGSERVER	_EC(324)	// 获取设备上主动注册服务器信息失败
#define	ZLNET_ERROR_CONTROL_AUTOREGISTER    _EC(325)	// 主动注册重定向注册错误
#define	ZLNET_ERROR_DISCONNECT_AUTOREGISTER	_EC(326)	// 断开主动注册服务器错误
#define ZLNET_ERROR_GETCFG_MMS				_EC(327)	// 获取mms配置失败
#define ZLNET_ERROR_SETCFG_MMS				_EC(328)	// 设置mms配置失败
#define ZLNET_ERROR_GETCFG_SMSACTIVATION    _EC(329)	// 获取短信激活无线连接配置失败
#define ZLNET_ERROR_SETCFG_SMSACTIVATION    _EC(330)	// 设置短信激活无线连接配置失败
#define ZLNET_ERROR_GETCFG_DIALINACTIVATION	_EC(331)	// 获取拨号激活无线连接配置失败
#define ZLNET_ERROR_SETCFG_DIALINACTIVATION	_EC(332)	// 设置拨号激活无线连接配置失败
#define ZLNET_ERROR_GETCFG_VIDEOOUT         _EC(333)    // 查询视频输出参数配置失败
#define ZLNET_ERROR_SETCFG_VIDEOOUT			_EC(334)	// 设置视频输出参数配置失败
#define ZLNET_ERROR_GETCFG_OSDENABLE		_EC(335)	// 获取osd叠加使能配置失败
#define ZLNET_ERROR_SETCFG_OSDENABLE		_EC(336)	// 设置osd叠加使能配置失败
#define ZLNET_ERROR_SETCFG_ENCODERINFO      _EC(337)    // 设置数字通道前端编码接入配置失败
#define ZLNET_ERROR_GETCFG_TVADJUST		    _EC(338)	// 获取TV调节配置失败
#define ZLNET_ERROR_SETCFG_TVADJUST			_EC(339)	// 设置TV调节配置失败

#define ZLNET_ERROR_CONNECT_FAILED			_EC(340)	// 请求建立连接失败
#define ZLNET_ERROR_SETCFG_BURNFILE			_EC(341)	// 请求刻录文件上传失败
#define ZLNET_ERROR_SNIFFER_GETCFG			_EC(342)	// 获取抓包配置信息失败
#define ZLNET_ERROR_SNIFFER_SETCFG			_EC(343)	// 设置抓包配置信息失败
#define ZLNET_ERROR_DOWNLOADRATE_GETCFG		_EC(344)	// 查询下载限制信息失败
#define ZLNET_ERROR_DOWNLOADRATE_SETCFG		_EC(345)	// 设置下载限制信息失败
#define ZLNET_ERROR_SEARCH_TRANSCOM			_EC(346)	// 查询串口参数失败
#define ZLNET_ERROR_GETCFG_POINT			_EC(347)	// 获取预制点信息错误
#define ZLNET_ERROR_SETCFG_POINT			_EC(348)	// 设置预制点信息错误
#define ZLNET_SDK_LOGOUT_ERROR				_EC(349)    // SDK没有正常登出设备
#define ZLNET_ERROR_GET_VEHICLE_CFG			_EC(350)	// 获取车载配置失败
#define ZLNET_ERROR_SET_VEHICLE_CFG			_EC(351)	// 设置车载配置失败
#define ZLNET_ERROR_GET_ATM_OVERLAY_CFG		_EC(352)	// 获取atm叠加配置失败
#define ZLNET_ERROR_SET_ATM_OVERLAY_CFG		_EC(353)	// 设置atm叠加配置失败
#define ZLNET_ERROR_GET_ATM_OVERLAY_ABILITY	_EC(354)	// 获取atm叠加能力失败
#define ZLNET_ERROR_GET_DECODER_TOUR_CFG	_EC(355)	// 获取解码器解码轮巡配置失败
#define ZLNET_ERROR_SET_DECODER_TOUR_CFG	_EC(356)	// 设置解码器解码轮巡配置失败
#define ZLNET_ERROR_CTRL_DECODER_TOUR		_EC(357)	// 控制解码器解码轮巡失败
#define ZLNET_GROUP_OVERSUPPORTNUM			_EC(358)	// 超出设备支持最大用户组数目
#define ZLNET_USER_OVERSUPPORTNUM			_EC(359)	// 超出设备支持最大用户数目
#define ZLNET_ERROR_GET_SIP_CFG				_EC(368)	// 获取SIP配置失败
#define ZLNET_ERROR_SET_SIP_CFG				_EC(369)	// 设置SIP配置失败
#define ZLNET_ERROR_GET_SIP_ABILITY			_EC(370)	// 获取SIP能力失败
#define ZLNET_TALK_REJECT					_EC(371)	// 拒绝对讲
#define ZLNET_TALK_BUSY						_EC(372)	// 资源冲突、不能对讲
#define ZLNET_TALK_FORMAT_NOT_SUPPORTED		_EC(373)	// 拒绝对讲，编码格式不支持
#define ZLNET_ERROR_UPSUPPORT_WAV			_EC(374)	// 不支持的WAV文件
#define ZLNET_ERROR_CHANGE_FORMAT_WAV		_EC(375)	// 转换WAV采样率失败
#define ZLNET_ERROR_PACKFRAME				_EC(376)	// 打包失败
#define ZLNET_ERROR_LATTICE_CFG				_EC(377)	// 设置点阵配置失败

/************************************************************************
 ** 枚举定义
 ***********************************************************************/
// 设备类型
enum ZLNET_DEVICE_TYPE 
{
	ZLNET_NULL = 0,
	ZLNET_DVR=100,
	ZLNET_DVR_6004,
	ZLNET_DVR_6008,
	ZLNET_DVR_6016,
	ZLNET_DVR_7004=110,
	ZLNET_DVR_7008,
	ZLNET_DVR_7008E,
	ZLNET_DVR_7016,
	ZLNET_DVR_7016E,
	ZLNET_DVR_7016H,
	ZLNET_DVR_7032,
	ZLNET_DVR_7024,
	ZLNET_DVR_7016N,
	ZLNET_DVR_7008N,
	ZLNET_DVR_8004=120,
	ZLNET_DVR_8008,
	ZLNET_DVR_8016,
	ZLNET_DVR_8016E,
	ZLNET_DVR_9016=130,
	ZLNET_DVR_9008,
	ZLNET_DVR_9016N,
	ZLNET_IPC_Int=140,
	ZLNET_IVA_PLATEID,		//智能车牌
	ZLNET_IVA_STAFFCOUNT,	//智能人数统计
	ZLNET_IVA_BZS,				//智能周界
	ZLNET_IVA_ATM=150,			//智能ATM
	ZLNET_IVA_SSB,				//智能SSB
	ZLNET_IVA_FACE,				//智能人脸
	ZLNET_IPC=180,
	ZLNET_IPC_3507_SD,			//3507标清
	ZLNET_IPC_3507_720p,		//3507 720p
	ZLNET_IPC_3507_VGA,			//3507VGA
	ZLNET_IPC_3516_720p=188,	//3516 720p
	ZLNET_IPC_3516_1080p,		//3516 1080p
	ZLNET_DVR_D7004E = 200,
	ZLNET_DVR_D7008E ,
	ZLNET_DVR_D7016E ,
	ZLNET_DVR_D7004 ,
	ZLNET_DVR_D7008 ,
	ZLNET_DVR_D7016 ,
	ZLNET_DVR_D8004 ,
	ZLNET_DVR_D8008 ,
	ZLNET_DVR_D8016 ,
	ZLNET_DVR_D8308 ,
	ZLNET_DVR_D8316 ,
	ZLNET_DVR_D8324 ,
	ZLNET_DVR_D8332 ,
	ZLNET_DVR_D8408 ,
	ZLNET_DVR_D8416 ,
	ZLNET_DVR_D8424 ,
	ZLNET_DVR_D8816 ,
	ZLNET_DVR_NEW=230,
	ZLNET_DVR_7004N,
	ZLNET_DVR_7116E,
	ZLNET_DVR_9104,
	ZLNET_DVR_7116,
	ZLNET_DVR_7108E,
	ZLNET_UNKNOWN=255,
};

// 语言种类
typedef enum __ZLNET_LANGUAGE_TYPE
{
	ZLNET_LANGUAGE_ENGLISH,							// 英文	
	ZLNET_LANGUAGE_CHINESE_SIMPLIFIED,				// 简体中文	
	ZLNET_LANGUAGE_CHINESE_TRADITIONAL,				// 繁体中文	
	ZLNET_LANGUAGE_ITALIAN,							// 意大利文	
	ZLNET_LANGUAGE_SPANISH,							// 西班牙文
	ZLNET_LANGUAGE_JAPANESE,						// 日文版	
	ZLNET_LANGUAGE_RUSSIAN,							// 俄文版		
	ZLNET_LANGUAGE_FRENCH,							// 法文版		
	ZLNET_LANGUAGE_GERMAN, 							// 德文版		
	ZLNET_LANGUAGE_PORTUGUESE,						// 葡萄牙语	
	ZLNET_LANGUAGE_TURKEY,							// 土尔其语	
	ZLNET_LANGUAGE_POLISH,							// 波兰语	
	ZLNET_LANGUAGE_ROMANIAN,						// 罗马尼亚	
	ZLNET_LANGUAGE_HUNGARIAN,						// 匈牙利语	
	ZLNET_LANGUAGE_FINNISH,							// 芬兰语	
	ZLNET_LANGUAGE_ESTONIAN,						// 爱沙尼亚语	
	ZLNET_LANGUAGE_KOREAN,							// 韩语	
	ZLNET_LANGUAGE_FARSI,							// 波斯语 	
	ZLNET_LANGUAGE_DANSK,							// 丹麦语
	ZLNET_LANGUAGE_CZECHISH,						// 捷克文
	ZLNET_LANGUAGE_BULGARIA,						// 保加利亚文
	ZLNET_LANGUAGE_SLOVAKIAN,						// 斯洛伐克语
	ZLNET_LANGUAGE_SLOVENIA,						// 斯洛文尼亚文
	ZLNET_LANGUAGE_CROATIAN,						// 克罗地亚语
	ZLNET_LANGUAGE_DUTCH,							// 荷兰语
	ZLNET_LANGUAGE_GREEK,							// 希腊语
	ZLNET_LANGUAGE_UKRAINIAN,						// 乌克兰语
	ZLNET_LANGUAGE_SWEDISH,							// 瑞典语
	ZLNET_LANGUAGE_SERBIAN,							// 塞尔维亚语
	ZLNET_LANGUAGE_VIETNAMESE,						// 越南语
	ZLNET_LANGUAGE_LITHUANIAN,						// 立陶宛语
	ZLNET_LANGUAGE_FILIPINO,						// 菲律宾语
	ZLNET_LANGUAGE_ARABIC,							// 阿拉伯语
	ZLNET_LANGUAGE_CATALAN,							// 加泰罗尼亚语
	ZLNET_LANGUAGE_LATVIAN,							// 拉脱维亚语
	ZLNET_LANGUAGE_THAI,							// 泰语
	ZLNET_LANGUAGE_HEBREW,							// 希伯来语
	ZLNET_LANGUAGE_Bosnian,							// 波斯尼亚文
} ZLNET_LANGUAGE_TYPE;

// 升级类型
typedef enum __ZLNET_UPGRADE_TYPE
{
	ZLNET_UPGRADE_BIOS_TYPE = 1,					// BIOS升级
	ZLNET_UPGRADE_WEB_TYPE,							// WEB升级
	ZLNET_UPGRADE_BOOT_YPE,							// BOOT升级
	ZLNET_UPGRADE_CHARACTER_TYPE,					// 汉字库
	ZLNET_UPGRADE_LOGO_TYPE,						// LOGO
	ZLNET_UPGRADE_EXE_TYPE,							// EXE，例如播放器等
} ZLNET_UPGRADE_TYPE;

// 录象类型(定时、动态检测、报警)
typedef enum __ZLNET_REC_TYPE
{
	ZLNET_REC_TYPE_TIM = 0,
	ZLNET_REC_TYPE_MTD,
	ZLNET_REC_TYPE_ALM,
	ZLNET_REC_TYPE_NUM,
} ZLNET_REC_TYPE;

// 网络类型 
typedef enum __ZLNET_GPRSCDMA_NETWORK_TYPE
{
	ZLNET_TYPE_AUTOSEL = 0,							// 自动选择
	ZLNET_TYPE_TD_SCDMA,							// TD-SCDMA网络 
	ZLNET_TYPE_WCDMA,								// WCDMA网络
	ZLNET_TYPE_CDMA_1x,								// CDMA 1.x网络
	ZLNET_TYPE_EDGE,								// GPRS网络
	ZLNET_TYPE_EVDO,								// EVDO网络
	ZLNET_TYPE_WIFI,								// 无线
} ZLNET_GPRSCDMA_NETWORK_TYPE;

// 接口类型，对应ZLNET_SetSubconnCallBack接口
typedef enum __ZLNET_INTERFACE_TYPE
{
	ZLNET_INTERFACE_OTHER = 0x00000000,				// 未知接口
	ZLNET_INTERFACE_REALPLAY,						// 实时监视接口
	ZLNET_INTERFACE_PREVIEW,						// 多画面预览接口
	ZLNET_INTERFACE_PLAYBACK,						// 回放接口
	ZLNET_INTERFACE_DOWNLOAD,						// 下载接口
} ZLNET_INTERFACE_TYPE;

/////////////////////////////////监视相关/////////////////////////////////

// 预览类型，对应ZLNET_RealPlayEx接口
typedef enum _ZLNET_RealPlayType
{
	ZLNET_RType_Realplay = 0,						// 实时预览
	ZLNET_RType_Multiplay,							// 多画面预览
		
	ZLNET_RType_Realplay_0,						// 实时监视-主码流，等同于ZLNET_RType_Realplay
	ZLNET_RType_Realplay_1,						// 实时监视-从码流1
	ZLNET_RType_Realplay_2,						// 实时监视-从码流2
	ZLNET_RType_Realplay_3,						// 实时监视-从码流3
		
	ZLNET_RType_Multiplay_1,						// 多画面预览－1画面
	ZLNET_RType_Multiplay_4,						// 多画面预览－4画面
	ZLNET_RType_Multiplay_8,						// 多画面预览－8画面
	ZLNET_RType_Multiplay_9,						// 多画面预览－9画面
	ZLNET_RType_Multiplay_16,						// 多画面预览－16画面
	ZLNET_RType_Multiplay_6,						// 多画面预览－6画面
	ZLNET_RType_Multiplay_12,						// 多画面预览－12画面
} ZLNET_RealPlayType;

/////////////////////////////////云台相关/////////////////////////////////

// 通用云台控制命令
typedef enum _ZLNET_PTZ_ControlType
{
	ZLNET_PTZ_UP_CONTROL = 0,						// 上
	ZLNET_PTZ_DOWN_CONTROL,							// 下
	ZLNET_PTZ_LEFT_CONTROL,							// 左
	ZLNET_PTZ_RIGHT_CONTROL,						// 右
	ZLNET_PTZ_ZOOM_ADD_CONTROL,						// 变倍+
	ZLNET_PTZ_ZOOM_DEC_CONTROL,						// 变倍-
	ZLNET_PTZ_FOCUS_ADD_CONTROL,					// 调焦+
	ZLNET_PTZ_FOCUS_DEC_CONTROL,					// 调焦-
	ZLNET_PTZ_APERTURE_ADD_CONTROL,				// 光圈+
	ZLNET_PTZ_APERTURE_DEC_CONTROL,				// 光圈-
    ZLNET_PTZ_POINT_MOVE_CONTROL,					// 转至预置点
    ZLNET_PTZ_POINT_SET_CONTROL,					// 设置
    ZLNET_PTZ_POINT_DEL_CONTROL,					// 删除
    ZLNET_PTZ_POINT_LOOP_CONTROL,					// 点间巡航
    ZLNET_PTZ_LAMP_CONTROL							// 灯光雨刷
} ZLNET_PTZ_ControlType;

// 云台控制扩展命令
typedef enum _ZLNET_EXTPTZ_ControlType
{
	ZLNET_EXTPTZ_LEFTTOP = 0x20,					// 左上
	ZLNET_EXTPTZ_RIGHTTOP,							// 右上
	ZLNET_EXTPTZ_LEFTDOWN,							// 左下
	ZLNET_EXTPTZ_RIGHTDOWN,							// 右下
	ZLNET_EXTPTZ_ADDTOLOOP,							// 加入预置点到巡航 巡航线路 预置点值
	ZLNET_EXTPTZ_DELFROMLOOP,						// 删除巡航中预置点 巡航线路 预置点值
    ZLNET_EXTPTZ_CLOSELOOP,							// 清除巡航 巡航线路
	ZLNET_EXTPTZ_STARTPANCRUISE,					// 开始水平旋转
	ZLNET_EXTPTZ_STOPPANCRUISE,						// 停止水平旋转
	ZLNET_EXTPTZ_SETLEFTBORDER,						// 设置左边界
	ZLNET_EXTPTZ_SETRIGHTBORDER,					// 设置右边界
	ZLNET_EXTPTZ_STARTLINESCAN,						// 开始线扫
    ZLNET_EXTPTZ_CLOSELINESCAN,						// 停止线扫
    ZLNET_EXTPTZ_SETMODESTART,						// 设置模式开始	模式线路
    ZLNET_EXTPTZ_SETMODESTOP,						// 设置模式结束	模式线路
	ZLNET_EXTPTZ_RUNMODE,							// 运行模式	模式线路
	ZLNET_EXTPTZ_STOPMODE,							// 停止模式	模式线路
	ZLNET_EXTPTZ_DELETEMODE,						// 清除模式	模式线路
	ZLNET_EXTPTZ_REVERSECOMM,						// 翻转命令
	ZLNET_EXTPTZ_FASTGOTO,							// 快速定位 水平坐标(8192) 垂直坐标(8192) 变倍(4)
	ZLNET_EXTPTZ_AUXIOPEN,							// 辅助开关开 辅助点
	ZLNET_EXTPTZ_AUXICLOSE,							// 辅助开关关 辅助点
	ZLNET_EXTPTZ_OPENMENU = 0x36,					// 打开球机菜单
	ZLNET_EXTPTZ_CLOSEMENU,							// 关闭菜单
	ZLNET_EXTPTZ_MENUOK,							// 菜单确定
	ZLNET_EXTPTZ_MENUCANCEL,						// 菜单取消
	ZLNET_EXTPTZ_MENUUP,							// 菜单上
	ZLNET_EXTPTZ_MENUDOWN,							// 菜单下
	ZLNET_EXTPTZ_MENULEFT,							// 菜单左
	ZLNET_EXTPTZ_MENURIGHT,							// 菜单右
	ZLNET_EXTPTZ_ALARMHANDLE = 0x40,				// 报警联动云台 parm1：报警输入通道；parm2：报警联动类型1-预置点2-线扫3-巡航；parm3：联动值，如预置点号
	ZLNET_EXTPTZ_MATRIXSWITCH = 0x41,				// 矩阵切换 parm1：监视器号(视频输出号)；parm2：视频输入号；parm3：矩阵号
	ZLNET_EXTPTZ_LIGHTCONTROL,						// 灯光控制器
	ZLNET_EXTPTZ_UP_TELE = 0x70,					// 上 + TELE param1=速度(1-8)，下同
	ZLNET_EXTPTZ_DOWN_TELE,							// 下 + TELE
	ZLNET_EXTPTZ_LEFT_TELE,							// 左 + TELE
	ZLNET_EXTPTZ_RIGHT_TELE,						// 右 + TELE
	ZLNET_EXTPTZ_LEFTUP_TELE,						// 左上 + TELE
	ZLNET_EXTPTZ_LEFTDOWN_TELE,						// 左下 + TELE
	ZLNET_EXTPTZ_TIGHTUP_TELE,						// 右上 + TELE
	ZLNET_EXTPTZ_RIGHTDOWN_TELE,					// 右下 + TELE
	ZLNET_EXTPTZ_UP_WIDE,							// 上 + WIDE param1=速度(1-8)，下同
	ZLNET_EXTPTZ_DOWN_WIDE,							// 下 + WIDE
	ZLNET_EXTPTZ_LEFT_WIDE,							// 左 + WIDE
	ZLNET_EXTPTZ_RIGHT_WIDE,						// 右 + WIDE
	ZLNET_EXTPTZ_LEFTUP_WIDE,						// 左上 + WIDE
	ZLNET_EXTPTZ_LEFTDOWN_WIDE,						// 左下 + WIDE
	ZLNET_EXTPTZ_TIGHTUP_WIDE,						// 右上 + WIDE
	ZLNET_EXTPTZ_RIGHTDOWN_WIDE,					// 右下 + WIDE
	ZLNET_EXTPTZ_TOTAL,							// 最大命令值
} ZLNET_EXTPTZ_ControlType;

/////////////////////////////////日志相关/////////////////////////////////

// 日志查询类型
typedef enum _ZLNET_LOG_QUERY_TYPE
{
	ZLNET_LOG_QUY_ALL = 0,								// 所有日志
	ZLNET_LOG_QUY_SYSTEM,								// 系统日志
	ZLNET_LOG_QUY_CONFIG,								// 配置日志
	ZLNET_LOG_QUY_STORAGE,								// 存储相关
	ZLNET_LOG_QUY_ALARM,								// 报警日志
	ZLNET_LOG_QUY_RECORD,								// 录象相关
	ZLNET_LOG_QUY_ACCOUNT,								// 帐号相关
	ZLNET_LOG_QUY_CLEAR,								// 清除日志
	ZLNET_LOG_QUY_PLAYBACK								// 回放相关
} ZLNET_LOG_QUERY_TYPE;

// 日志类型
typedef enum _ZL_LOG_TYPE
{
	ZLNET_LOG_REBOOT = 0x0000,						// 设备重启
	ZLNET_LOG_SHUT,									// 设备关机
	ZLNET_LOG_UPGRADE = 0x0004,						// 设备升级
	ZLNET_LOG_CONFSAVE = 0x0100,					// 保存配置
	ZLNET_LOG_CONFLOAD,								// 读取配置
	ZLNET_LOG_FSERROR = 0x0200,						// 文件系统错误
	ZLNET_LOG_HDD_WERR,								// 硬盘写错误
	ZLNET_LOG_HDD_RERR,								// 硬盘读错误
	ZLNET_LOG_HDD_TYPE,								// 设置硬盘类型
	ZLNET_LOG_HDD_FORMAT,							// 格式化硬盘
	ZLNET_LOG_HDD_NOSPACE,							// 当前工作盘空间不足
	ZLNET_LOG_HDD_TYPE_RW,							// 设置硬盘类型为读写盘
	ZLNET_LOG_HDD_TYPE_RO,							// 设置硬盘类型为只读盘	
	ZLNET_LOG_HDD_TYPE_RE,							// 设置硬盘类型为冗余盘
	ZLNET_LOG_HDD_TYPE_SS,							// 设置硬盘类型为快照盘
	ZLNET_LOG_HDD_NONE,								// 无硬盘记录
	ZLNET_LOG_HDD_NOWORKHDD,						// 无工作盘(没有读写盘)
	ZLNET_LOG_HDD_TYPE_BK,							// 设置硬盘类型为备份盘
	ZLNET_LOG_HDD_TYPE_REVERSE,						// 设置硬盘类型为保留分区
	ZLNET_LOG_ALM_IN = 0x0300,						// 外部输入报警开始
	ZLNET_LOG_NETALM_IN,							// 网络报警输入
	ZLNET_LOG_ALM_END = 0x0302,						// 外部输入报警停止
	ZLNET_LOG_LOSS_IN,								// 视频丢失报警开始
	ZLNET_LOG_LOSS_END,								// 视频丢失报警结束
	ZLNET_LOG_MOTION_IN,							// 动态检测报警开始
	ZLNET_LOG_MOTION_END,							// 动态检测报警结束
	ZLNET_LOG_ALM_BOSHI,							// 报警器报警输入
	ZLNET_LOG_NET_ABORT = 0x0308,					// 网络断开
	ZLNET_LOG_NET_ABORT_RESUME,						// 网络恢复
	ZLNET_LOG_CODER_BREAKDOWN,						// 编码器故障
	ZLNET_LOG_CODER_BREAKDOWN_RESUME,				// 编码器故障恢复
	ZLNET_LOG_BLIND_IN,								// 视频遮挡
	ZLNET_LOG_BLIND_END,							// 视频遮挡恢复
	ZLNET_LOG_ALM_TEMP_HIGH,						// 温度过高
	ZLNET_LOG_ALM_VOLTAGE_LOW,						// 电压过低
	ZLNET_LOG_ALM_BATTERY_LOW,						// 电池容量不足
	ZLNET_LOG_ALM_ACC_BREAK,						// ACC断电
	ZLNET_LOG_INFRAREDALM_IN = 0x03a0,				// 无线报警开始
	ZLNET_LOG_INFRAREDALM_END,						// 无线报警结束
	ZLNET_LOG_IPCONFLICT,							// IP冲突
	ZLNET_LOG_IPCONFLICT_RESUME,					// IP恢复
	ZLNET_LOG_SDPLUG_IN,							// SD卡插入
	ZLNET_LOG_SDPLUG_OUT,							// SD卡拔出
	ZLNET_LOG_NET_PORT_BIND_FAILED,					// 网络端口绑定失败
	ZLNET_LOG_AUTOMATIC_RECORD = 0x0400,			// 自动录像
	ZLNET_LOG_MANUAL_RECORD = 0x0401,				// 手动录象
	ZLNET_LOG_CLOSED_RECORD,						// 停止录象
	ZLNET_LOG_LOGIN = 0x0500,						// 登录
	ZLNET_LOG_LOGOUT,								// 注销
	ZLNET_LOG_ADD_USER,								// 添加用户
	ZLNET_LOG_DELETE_USER,							// 删除用户
	ZLNET_LOG_MODIFY_USER,							// 修改用户
	ZLNET_LOG_ADD_GROUP,							// 添加用户组
	ZLNET_LOG_DELETE_GROUP,							// 删除用户组
	ZLNET_LOG_MODIFY_GROUP,							// 修改用户组
	ZLNET_LOG_NET_LOGIN = 0x0508,					// 网络用户登录
	ZLNET_LOG_CLEAR = 0x0600,						// 清除日志
	ZLNET_LOG_SEARCHLOG,							// 查询日志
	ZLNET_LOG_SEARCH = 0x0700,						// 录像查询
	ZLNET_LOG_DOWNLOAD,								// 录像下载
	ZLNET_LOG_PLAYBACK,								// 录像回放
	ZLNET_LOG_BACKUP,								// 备份录像文件
	ZLNET_LOG_BACKUPERROR,							// 备份录像文件失败

	ZLNET_LOG_TYPE_NR = 7,
} ZL_LOG_TYPE;

// 扩展日志类型，对应ZLNET_QueryLogEx接口，条件(int nType = 1；参数reserved = &nType)
typedef enum _ZLNET_NEWLOG_TYPE
{
	ZLNET_NEWLOG_REBOOT = 0x0000,					// 设备重启
	ZLNET_NEWLOG_SHUT,								// 设备关机
	ZLNET_NEWLOG_UPGRADE = 0x0004,					// 设备升级
	ZLNET_NEWLOG_CONFSAVE = 0x0100,					// 保存配置
	ZLNET_NEWLOG_CONFLOAD,							// 读取配置
	ZLNET_NEWLOG_FSERROR = 0x0200,					// 文件系统错误
	ZLNET_NEWLOG_HDD_WERR,							// 硬盘写错误
	ZLNET_NEWLOG_HDD_RERR,							// 硬盘读错误
	ZLNET_NEWLOG_HDD_TYPE,							// 设置硬盘类型
	ZLNET_NEWLOG_HDD_FORMAT,						// 格式化硬盘
	ZLNET_NEWLOG_HDD_NOSPACE,						// 当前工作盘空间不足
	ZLNET_NEWLOG_HDD_TYPE_RW,						// 设置硬盘类型为读写盘
	ZLNET_NEWLOG_HDD_TYPE_RO,						// 设置硬盘类型为只读盘	
	ZLNET_NEWLOG_HDD_TYPE_RE,						// 设置硬盘类型为冗余盘
	ZLNET_NEWLOG_HDD_TYPE_SS,						// 设置硬盘类型为快照盘
	ZLNET_NEWLOG_HDD_NONE,							// 无硬盘记录日志
	ZLNET_NEWLOG_HDD_NOWORKHDD,						// 无工作盘(没有读写盘)
	ZLNET_NEWLOG_HDD_TYPE_BK,						// 设置硬盘类型为备份盘
	ZLNET_NEWLOG_HDD_TYPE_REVERSE,					// 设置硬盘类型为保留分区
	ZLNET_NEWLOG_ALM_IN = 0x0300,					// 外部输入报警开始
	ZLNET_NEWLOG_NETALM_IN,							// 网络报警
	ZLNET_NEWLOG_ALM_END = 0x0302,					// 外部输入报警停止
	ZLNET_NEWLOG_LOSS_IN,							// 视频丢失报警开始
	ZLNET_NEWLOG_LOSS_END,							// 视频丢失报警结束
	ZLNET_NEWLOG_MOTION_IN,							// 动态检测报警开始
	ZLNET_NEWLOG_MOTION_END,						// 动态检测报警结束
	ZLNET_NEWLOG_ALM_BOSHI,							// 报警器报警输入
	ZLNET_NEWLOG_NET_ABORT = 0x0308,				// 网络断开
	ZLNET_NEWLOG_NET_ABORT_RESUME,					// 网络恢复
	ZLNET_NEWLOG_CODER_BREAKDOWN,					// 编码器故障
	ZLNET_NEWLOG_CODER_BREAKDOWN_RESUME,			// 编码器故障恢复
	ZLNET_NEWLOG_BLIND_IN,							// 视频遮挡
	ZLNET_NEWLOG_BLIND_END,							// 视频遮挡恢复
	ZLNET_NEWLOG_ALM_TEMP_HIGH,						// 温度过高
	ZLNET_NEWLOG_ALM_VOLTAGE_LOW,					// 电压过低
	ZLNET_NEWLOG_ALM_BATTERY_LOW,					// 电池容量不足
	ZLNET_NEWLOG_ALM_ACC_BREAK,						// ACC断电
	ZLNET_NEWLOG_INFRAREDALM_IN = 0x03a0,			// 无线报警开始
	ZLNET_NEWLOG_INFRAREDALM_END,					// 无线报警结束
	ZLNET_NEWLOG_IPCONFLICT,						// IP冲突
	ZLNET_NEWLOG_IPCONFLICT_RESUME,					// IP恢复
	ZLNET_NEWLOG_SDPLUG_IN,							// SD卡插入
	ZLNET_NEWLOG_SDPLUG_OUT,						// SD卡拔出
	ZLNET_NEWLOG_NET_PORT_BIND_FAILED,				// 网络端口绑定失败
	ZLNET_NEWLOG_AUTOMATIC_RECORD = 0x0400,			// 自动录象
	ZLNET_NEWLOG_MANUAL_RECORD,						// 手动录象开
	ZLNET_NEWLOG_CLOSED_RECORD,						// 停止录象
	ZLNET_NEWLOG_LOGIN = 0x0500,					// 登录
	ZLNET_NEWLOG_LOGOUT,							// 注销
	ZLNET_NEWLOG_ADD_USER,							// 添加用户
	ZLNET_NEWLOG_DELETE_USER,						// 删除用户
	ZLNET_NEWLOG_MODIFY_USER,						// 修改用户
	ZLNET_NEWLOG_ADD_GROUP,							// 添加用户组
	ZLNET_NEWLOG_DELETE_GROUP,						// 删除用户组
	ZLNET_NEWLOG_MODIFY_GROUP,						// 修改用户组
	ZLNET_NEWLOG_NET_LOGIN = 0x0508,				// 网络用户登录
	ZLNET_NEWLOG_CLEAR = 0x0600,					// 清除日志
	ZLNET_NEWLOG_SEARCHLOG,							// 查询日志
	ZLNET_NEWLOG_SEARCH = 0x0700,					// 录像查询
	ZLNET_NEWLOG_DOWNLOAD,							// 录像下载
	ZLNET_NEWLOG_PLAYBACK,							// 录像回放
	ZLNET_NEWLOG_BACKUP,							// 备份录像文件
	ZLNET_NEWLOG_BACKUPERROR,						// 备份录像文件失败
	
	ZLNET_NEWLOG_TYPE_NR = 8,		
} ZLNET_NEWLOG_TYPE;

///////////////////////////////语音对讲相关///////////////////////////////

// 语音编码类型
typedef enum __ZLNET_TALK_CODING_TYPE
{
	ZLNET_TALK_DEFAULT = 0,							// 无头PCM
	ZLNET_TALK_PCM = 1,								// 带头PCM
	ZLNET_TALK_G711a,								// G711a
	ZLNET_TALK_AMR,									// AMR
	ZLNET_TALK_G711u,								// G711u
	ZLNET_TALK_G726,								// G726
} ZLNET_TALK_CODING_TYPE;

// 对讲方式
typedef enum __ZLNET_USEDEV_MODE
{
	ZLNET_TALK_CLIENT_MODE,							// 设置客户端方式进行语音对讲
	ZLNET_TALK_SERVER_MODE,							// 设置服务器方式进行语音对讲
	ZLNET_TALK_ENCODE_TYPE,							// 设置语音对讲编码格式
	ZLNET_ALARM_LISTEN_MODE,						// 设置报警订阅方式
	ZLNET_CONFIG_AUTHORITY_MODE,					// 设置通过权限进行配置管理
} ZLNET_USEDEV_MODE;

// AMR编码类型
typedef enum __ZLNET_ARM_ENCODE_MODE
{
	ZLNET_TALK_AMR_AMR475 = 1,						// AMR475编码
	ZLNET_TALK_AMR_AMR515,							// AMR515编码
	ZLNET_TALK_AMR_AMR59,							// AMR59编码
	ZLNET_TALK_AMR_AMR67,							// AMR67编码
	ZLNET_TALK_AMR_AMR74,							// AMR74编码
	ZLNET_TALK_AMR_AMR795,							// AMR795编码
	ZLNET_TALK_AMR_AMR102,							// AMR102编码
	ZLNET_TALK_AMR_AMR122,							// AMR122编码
} ZLNET_ARM_ENCODE_MODE;

/////////////////////////////////控制相关/////////////////////////////////

// 控制类型，对应ZLNET_ControlDevice接口
typedef enum _ZLNET_CtrlType
{
	ZLNET_CTRL_REBOOT = 0,							// 重启设备	
	ZLNET_CTRL_SHUTDOWN,							// 关闭设备
	ZLNET_CTRL_DISK,								// 硬盘管理
	ZLNET_KEYBOARD_POWER = 3,						// 网络键盘
	ZLNET_KEYBOARD_ENTER,
	ZLNET_KEYBOARD_ESC,
	ZLNET_KEYBOARD_UP,
	ZLNET_KEYBOARD_DOWN,
	ZLNET_KEYBOARD_LEFT,
	ZLNET_KEYBOARD_RIGHT,
	ZLNET_KEYBOARD_BTN0,
	ZLNET_KEYBOARD_BTN1,
	ZLNET_KEYBOARD_BTN2,
	ZLNET_KEYBOARD_BTN3,
	ZLNET_KEYBOARD_BTN4,
	ZLNET_KEYBOARD_BTN5,
	ZLNET_KEYBOARD_BTN6,
	ZLNET_KEYBOARD_BTN7,
	ZLNET_KEYBOARD_BTN8,
	ZLNET_KEYBOARD_BTN9,
	ZLNET_KEYBOARD_BTN10,
	ZLNET_KEYBOARD_BTN11,
	ZLNET_KEYBOARD_BTN12,
	ZLNET_KEYBOARD_BTN13,
	ZLNET_KEYBOARD_BTN14,
	ZLNET_KEYBOARD_BTN15,
	ZLNET_KEYBOARD_BTN16,
	ZLNET_KEYBOARD_SPLIT,
	ZLNET_KEYBOARD_ONE,
	ZLNET_KEYBOARD_NINE,
	ZLNET_KEYBOARD_ADDR,
	ZLNET_KEYBOARD_INFO,
	ZLNET_KEYBOARD_REC,
	ZLNET_KEYBOARD_FN1,
	ZLNET_KEYBOARD_FN2,
	ZLNET_KEYBOARD_PLAY,
	ZLNET_KEYBOARD_STOP,
	ZLNET_KEYBOARD_SLOW,
	ZLNET_KEYBOARD_FAST,
	ZLNET_KEYBOARD_PREW,
	ZLNET_KEYBOARD_NEXT,
	ZLNET_KEYBOARD_JMPDOWN,
	ZLNET_KEYBOARD_JMPUP,
	ZLNET_TRIGGER_ALARM_IN = 100,					// 触发报警输入
	ZLNET_TRIGGER_ALARM_OUT,						// 触发报警输出
	ZLNET_CTRL_MATRIX,								// 矩阵控制
	ZLNET_CTRL_SDCARD,								// SD卡控制(IPC产品)参数同硬盘控制
	ZLNET_BURNING_START,							// 刻录机控制，开始刻录
	ZLNET_BURNING_STOP,								// 刻录机控制，结束刻录
	ZLNET_BURNING_ADDPWD,							// 刻录机控制，叠加密码(以'\0'为结尾的字符串，最大长度8位)
	ZLNET_BURNING_ADDHEAD,							// 刻录机控制，叠加片头(以'\0'为结尾的字符串，最大长度1024字节，支持分行，行分隔符'\n')
	ZLNET_BURNING_ADDSIGN,							// 刻录机控制，叠加打点到刻录信息(参数无)
	ZLNET_BURNING_ADDCURSTOMINFO,					// 刻录机控制，自定义叠加(以'\0'为结尾的字符串，最大长度1024字节，支持分行，行分隔符'\n')
	ZLNET_CTRL_RESTOREDEFAULT,						// 恢复设备的默认设置
	ZLNET_CTRL_CAPTURE_START,						// 触发设备抓图
	ZLNET_CTRL_CLEARLOG,							// 清除日志
	ZLNET_TRIGGER_ALARM_WIRELESS = 200,			// 触发无线报警(IPC产品)
	ZLNET_MARK_IMPORTANT_RECORD,					// 标识重要录像文件
	ZLNET_CTRL_DISK_SUBAREA, 						// 网络硬盘分区	
	ZLNET_BURNING_ATTACH,							// 刻录机控制，附件刻录.
	ZLNET_BURNING_PAUSE,							// 刻录暂停
	ZLNET_BURNING_CONTINUE,						// 刻录继续
	ZLNET_BURNING_POSTPONE,						// 刻录顺延
	ZLNET_CTRL_OEMCTRL,							// 报停控制
	ZLNET_BACKUP_START,							// 设备备份开始
	ZLNET_BACKUP_STOP,								// 设备备份停止
} ZLNET_CtrlType;

// IO控制命令，对应ZLNET_QueryIOControlState接口
typedef enum _ZLNET_IOTYPE
{
	ZLNET_ALARMINPUT = 1,							// 控制报警输入
	ZLNET_ALARMOUTPUT = 2,							// 控制报警输出
	ZLNET_DECODER_ALARMOUT = 3,					// 控制报警解码器输出
	ZLNET_WIRELESS_ALARMOUT = 5,					// 控制无线报警输出
	ZLNET_ALARM_TRIGGER_MODE = 7,					// 报警触发方式（手动,自动,关闭），使用TRIGGER_MODE_CONTROL结构体
} ZLNET_IOTYPE;

/////////////////////////////////配置相关/////////////////////////////////

// 分辨率枚举，供ZL_DSP_ENCODECAP使用
typedef enum _ZLNET_CAPTURE_SIZE
{
	ZLNET_DSP_CAPTURE_SIZE_D1,							// 704*576(PAL)  704*480(NTSC)
	ZLNET_DSP_CAPTURE_SIZE_HD1,							// 352*576(PAL)  352*480(NTSC)
	ZLNET_DSP_CAPTURE_SIZE_BCIF,							// 704*288(PAL)  704*240(NTSC)
	ZLNET_DSP_CAPTURE_SIZE_CIF,							// 352*288(PAL)  352*240(NTSC)
	ZLNET_DSP_CAPTURE_SIZE_QCIF,							// 176*144(PAL)  176*120(NTSC)
	ZLNET_DSP_CAPTURE_SIZE_VGA,							// 640*480
	ZLNET_DSP_CAPTURE_SIZE_QVGA,							// 320*240
	ZLNET_DSP_CAPTURE_SIZE_SVCD,							// 480*480
	ZLNET_DSP_CAPTURE_SIZE_QQVGA,							// 160*128
	ZLNET_DSP_CAPTURE_SIZE_SVGA,							// 800*592
	ZLNET_DSP_CAPTURE_SIZE_XVGA,							// 1024*768
	ZLNET_DSP_CAPTURE_SIZE_WXGA,							// 1280*800
	ZLNET_DSP_CAPTURE_SIZE_SXGA,							// 1280*1024  
	ZLNET_DSP_CAPTURE_SIZE_WSXGA,							// 1600*1024  
	ZLNET_DSP_CAPTURE_SIZE_UXGA,							// 1600*1200
	ZLNET_DSP_CAPTURE_SIZE_WUXGA,							// 1920*1200
	ZLNET_DSP_CAPTURE_SIZE_LTF,							// 240*192
	ZLNET_DSP_CAPTURE_SIZE_720,							// 1280*720
	ZLNET_DSP_CAPTURE_SIZE_1080,							// 1920*1080
	ZLNET_DSP_CAPTURE_SIZE_1_3M,							// 1280*960
	ZLNET_DSP_CAPTURE_SIZE_NR 
} ZLNET_CAPTURE_SIZE;

// 配置文件类型，供ZLNET_ExportConfigFile接口使用
typedef enum __ZLNET_CONFIG_FILE_TYPE
{
	ZLNET_CONFIGFILE_ALL = 0,						// 全部配置文件
	ZLNET_CONFIGFILE_LOCAL,						// 本地配置文件
	ZLNET_CONFIGFILE_NETWORK,						// 网络配置文件
	ZLNET_CONFIGFILE_USER,							// 用户配置文件
} ZLNET_CONFIG_FILE_TYPE;

// NTP
typedef enum __ZLNET_TIME_ZONE_TYPE
{
	ZLNET_TIME_ZONE_0,								// {0, 0*3600,"GMT+00:00"}
	ZLNET_TIME_ZONE_1,								// {1, 1*3600,"GMT+01:00"}
	ZLNET_TIME_ZONE_2,								// {2, 2*3600,"GMT+02:00"}
	ZLNET_TIME_ZONE_3,								// {3, 3*3600,"GMT+03:00"}
	ZLNET_TIME_ZONE_4,								// {4, 3*3600+1800,"GMT+03:30"}
	ZLNET_TIME_ZONE_5,								// {5, 4*3600,"GMT+04:00"}
	ZLNET_TIME_ZONE_6,								// {6, 4*3600+1800,"GMT+04:30"}
	ZLNET_TIME_ZONE_7,								// {7, 5*3600,"GMT+05:00"}
	ZLNET_TIME_ZONE_8,								// {8, 5*3600+1800,"GMT+05:30"}
	ZLNET_TIME_ZONE_9,								// {9, 5*3600+1800+900,"GMT+05:45"}
	ZLNET_TIME_ZONE_10,							// {10, 6*3600,"GMT+06:00"}
	ZLNET_TIME_ZONE_11,							// {11, 6*3600+1800,"GMT+06:30"}
	ZLNET_TIME_ZONE_12,							// {12, 7*3600,"GMT+07:00"}
	ZLNET_TIME_ZONE_13,							// {13, 8*3600,"GMT+08:00"}
	ZLNET_TIME_ZONE_14,							// {14, 9*3600,"GMT+09:00"}
	ZLNET_TIME_ZONE_15,							// {15, 9*3600+1800,"GMT+09:30"}
	ZLNET_TIME_ZONE_16,							// {16, 10*3600,"GMT+10:00"}
	ZLNET_TIME_ZONE_17,							// {17, 11*3600,"GMT+11:00"}
	ZLNET_TIME_ZONE_18,							// {18, 12*3600,"GMT+12:00"}
	ZLNET_TIME_ZONE_19,							// {19, 13*3600,"GMT+13:00"}
	ZLNET_TIME_ZONE_20,							// {20, -1*3600,"GMT-01:00"}
	ZLNET_TIME_ZONE_21,							// {21, -2*3600,"GMT-02:00"}
	ZLNET_TIME_ZONE_22,							// {22, -3*3600,"GMT-03:00"}
	ZLNET_TIME_ZONE_23,							// {23, -3*3600-1800,"GMT-03:30"}
	ZLNET_TIME_ZONE_24,							// {24, -4*3600,"GMT-04:00"}
	ZLNET_TIME_ZONE_25,							// {25, -5*3600,"GMT-05:00"}
	ZLNET_TIME_ZONE_26,							// {26, -6*3600,"GMT-06:00"}
	ZLNET_TIME_ZONE_27,							// {27, -7*3600,"GMT-07:00"}
	ZLNET_TIME_ZONE_28,							// {28, -8*3600,"GMT-08:00"}
	ZLNET_TIME_ZONE_29,							// {29, -9*3600,"GMT-09:00"}
	ZLNET_TIME_ZONE_30,							// {30, -10*3600,"GMT-10:00"}
	ZLNET_TIME_ZONE_31,							// {31, -11*3600,"GMT-11:00"}
	ZLNET_TIME_ZONE_32,							// {32, -12*3600,"GMT-12:00"}
} ZLNET_TIME_ZONE_TYPE;

typedef enum _ZLNET_SNAP_TYPE
{
	ZLNET_SNAP_TYP_TIMING = 0,
	ZLNET_SNAP_TYP_ALARM,
	ZLNET_SNAP_TYP_NUM,
} ZLNET_SNAP_TYPE;

/////////////////////////////////淘汰类型/////////////////////////////////

// 配置类型，目前使用该枚举的接口已淘汰，请不要使用
typedef enum _ZLNET_CFG_INDEX
{
    ZLNET_CFG_GENERAL = 0,						        // 普通
	ZLNET_CFG_COMM,									// 串口
	ZLNET_CFG_NET,									    // 网络
	ZLNET_CFG_RECORD,									// 录像
	ZLNET_CFG_CAPTURE,								    // 图像设置
	ZLNET_CFG_PTZ,								    	// 云台
	ZLNET_CFG_DETECT,									// 动态检测
	ZLNET_CFG_ALARM,									// 报警
	ZLNET_CFG_DISPLAY,								    // 显示
	ZLNET_CFG_RESERVED,								// 保留，使类型连贯
	ZLNET_CFG_TITLE = 10,								// 通道标题
	ZLNET_CFG_MAIL = 11,								// 邮件功能
	ZLNET_CFG_EXCAPTURE = 12,							// 预览图像设置
	ZLNET_CFG_PPPOE = 13,								// pppoe设置
	ZLNET_CFG_DDNS = 14,								// DDNS设置
	ZLNET_CFG_SNIFFER	= 15,							// 网络监视捕获设置
	ZLNET_CFG_DSPINFO	= 16,							// 编码能力信息
	ZLNET_CFG_COLOR = 126,							    // 颜色配置信息
	ZLNET_CFG_ALL,									    // 保留
} ZLNET_CFG_INDEX;

//NVR网络通道状态
typedef enum _ZLNET_NVR_NET_CHANNEL_STATE
{
	ZLNET_STATE_NULL = 0,			//正常
	ZLNET_STATE_NO_SET,				//未开启
	ZLNET_STATE_ERROR,				//错误
	ZLNET_STATE_LOGINING,			//正在登录
	ZLNET_STATE_LOGIN_TIMEOUT,		//登录超时
	ZLNET_STATE_NET_FAILED,			//网络错误
	ZLNET_STATE_USER_PWD_FAILED,	//用户名密码错误
	ZLNET_STATE_USER_UNREPEAT,		//账号不能复用
	ZLNET_STATE_USER_LOCKED,		//帐号已锁定
	ZLNET_STATE_CHANNEL_UNEXIST,	//通道不存在
	ZLNET_STATE_MAIN_STREAM_NODATA,	//无主码流数据
	ZLNET_STATE_SUB_STREAM_NODATA,	//无辅码流数据
	ZLNET_STATE_VDEC_LACK_ABILITY,	//解码能力不够
	ZLNET_STATE_VDEC_INABILITY,		//无法解码
	ZLNET_STATE_NET_LACK_ABILITY,	//网络接入能力超出
} ZLNET_NVR_NET_CHANNEL_STATE;

//DDNS类型
typedef enum _ZLNET_DDNS_MODE
{
	ZLNET_ZL_DDNS = 0,
	ZLNET_BXS_DDNS,
} ZLNET_DDNS_MODE;

/************************************************************************
 ** 结构体定义
 ***********************************************************************/
// 时间
typedef struct 
{
	DWORD				dwYear;					// 年
	DWORD				dwMonth;				// 月
	DWORD				dwDay;					// 日
	DWORD				dwHour;					// 时
	DWORD				dwMinute;				// 分
	DWORD				dwSecond;				// 秒
} ZLNET_TIME,*LPZLNET_TIME;

// 日志信息里的时间定义
typedef struct _ZLNET_DEVTIME
{
	DWORD				second		:6;			// 秒	1-60		
	DWORD				minute		:6;			// 分	1-60		
	DWORD				hour		:5;			// 时	1-24		
	DWORD				day			:5;			// 日	1-31		
	DWORD				month		:4;			// 月	1-12		
	DWORD				year		:6;			// 年	2000-2063	
} ZLNET_DEVTIME, *LPZLNET_DEVTIME;

// 回调数据(异步接口)
typedef struct __ZLNET_CALLBACK_DATA 
{
	int					nResultCode;			// 返回码；0：成功
	char				*pBuf;					// 接收数据，缓冲是由用户开辟的，从接口形参传入
	int					nRetLen;				// 接收长度
	LONG				lOperateHandle;			// 操作句柄
	void*				userdata;				// 操作对应用户参数
	char				reserved[16];
} ZLNET_CALLBACK_DATA, *LPZLNET_CALLBACK_DATA;

///////////////////////////////监视相关定义///////////////////////////////

// 回调视频数据帧的帧参数结构体
typedef struct _ZLNET_VideoFrameParam
{
	BYTE				encode;					// 编码类型
	BYTE				frametype;				// I = 0, P = 1, B = 2...
	BYTE				format;					// PAL - 0, NTSC - 1
	BYTE				size;					// CIF - 0, HD1 - 1, 2CIF - 2, D1 - 3, VGA - 4, QCIF - 5, QVGA - 6 ,
												// SVCD - 7,QQVGA - 8, SVGA - 9, XVGA - 10,WXGA - 11,SXGA - 12,WSXGA - 13,UXGA - 14,WUXGA - 15, LFT - 16, 720 - 17, 1080 - 18
	DWORD				fourcc;					// 如果是H264编码则总为0，MPEG4这里总是填写FOURCC('X','V','I','D');
	DWORD				reserved;				// 保留
	ZLNET_TIME			struTime;				// 时间信息
} ZLNET_VideoFrameParam;

// 回调音频数据帧的帧参数结构体
typedef struct _ZLNET_CBPCMDataParam
{
	BYTE				channels;				// 声道数
	BYTE				samples;				// 采样 0 - 8000, 1 - 11025, 2 - 16000, 3 - 22050, 4 - 32000, 5 - 44100, 6 - 48000
	BYTE				depth;					// 采样深度 取值8或者16等。直接表示
	BYTE				param1;					// 0 - 指示无符号，1-指示有符号
	DWORD				reserved;				// 保留
} ZLNET_CBPCMDataParam;

// 通道画面字幕叠加的数据结构
typedef struct _ZLNET_CHANNEL_OSDSTRING
{
	BOOL				bEnable;				// 使能
	DWORD				dwPosition[ZLNET_MAX_STRING_LINE_LEN];	//各行字符的位置　用1-9整数表示，与小键盘位置对应
												//		7左上	8上		9右上
												//		4左		5中		6右
												//		1左下	2下		3右下
	char				szStrings[ZLNET_MAX_STRING_LINE_LEN][ZLNET_MAX_PER_STRING_LEN];	// 最多六行字符，每行最多20个字节
} ZLNET_CHANNEL_OSDSTRING;

///////////////////////////////回放相关定义///////////////////////////////

// 录像文件信息
typedef struct
{
    unsigned int		ch;						// 通道号
    char				filename[128];			// 文件名
    unsigned int		size;					// 文件长度
    ZLNET_TIME			starttime;				// 开始时间
    ZLNET_TIME			endtime;				// 结束时间
    unsigned int		driveno;				// 磁盘号(区分网络录像和本地录像的类型，0－127表示本地录像，128表示网络录像)
    unsigned int		startcluster;			// 起始簇号
	BYTE				nRecordFileType;		// 录象文件类型  0：普通录象；1：报警录象；2：移动检测；3：卡号录象；4：图片
	BYTE                bImportantRecID;		// 0:普通录像 1:重要录像
	BYTE                bHint;					// 文件定位索引
	BYTE                bReserved;				// 保留
} ZLNET_RECORDFILE_INFO, *LPZLNET_RECORDFILE_INFO;

typedef enum _ZLNET_DOWNLOADFILE_MODE
{
	ZLNET_DOWNLOADFILE_DEFAULT = 0,		//默认, 全部下载
	ZLNET_MODE_VIDEO,		//只下载视频文件, 并去掉智领包装头
}ZLNET_DOWNLOADFILE_MODE;

// 系统时间结构
typedef struct SYSTEM_TIME{
    int  year;///< 年。   
	int  month;///< 月，January = 1, February = 2, and so on.   
	int  day;///< 日。   
	int  hour;///< 时。   
	int  minute;///< 分。   
	int  second;///< 秒。   
}SYSTEM_TIME;

typedef struct SYSTEM_TIME_DST
{
    int  year;///< 年。   
	int  month;///< 月，January = 1, February = 2, and so on.   
	int  day;///< 日。   
	int  wday;///< 星期，Sunday = 0, Monday = 1, and so on   
	int  hour;///< 时。   
	int  minute;///< 分。   
	int  second;///< 秒。   
	int  isdst;///< 夏令时标识。   
}SYSTEM_TIME_DST;

//夏令时时间结构															    
typedef struct _ZLNET_IDVR_TIME_DST
{
	int tm_year;    
	int tm_mon;     // [0,11] 
	int tm_mday;    // [1,31] 
	int tm_wday;	// 星期
	int tm_hour;    // [0,23] 
	int tm_min;     // [0,59] 
	int tm_sec;     // [0,59] 
	int  isdst;		// 夏令时标识。   
}ZLNET_IDVR_TIME_DST;

//智能DVR文件信息
typedef struct _ZLNET_IDVR_LOG_FILE_ITEM
{
	unsigned long		 id;			//报警ID	
	ZLNET_DEVTIME		 time;		//时间
	unsigned char 		 chn;			//通道
	unsigned char		 type;		//文件类型1录像2图片
	unsigned char 		 Length;	//录像时间(S)
	unsigned char     Reserve; //保留位
}ZLNET_IDVR_LOG_FILE_ITEM, *LPZLNET_IDVR_LOG_FILE_ITEM;

// 最早录像时间
typedef struct  
{
	int					nChnCount;				// 通道数目
	ZLNET_TIME			stuFurthestTime[16];	// 最早录像时间,有效值为前面0 到 (nChnCount-1)个.如果某通道没有录象的话，最早录象时间全为0
	BYTE				bReserved[384];			// 保留字段
} ZLNET_FURTHEST_RECORD_TIME;

///////////////////////////////报警相关定义///////////////////////////////


// 普通报警信息
typedef struct
{
	int					channelcount;
	int					alarminputcount;
	unsigned char		alarm[16];				// 外部报警
	unsigned char		motiondection[16];		// 动态检测
	unsigned char		videolost[16];			// 视频丢失
} ZLNET_CLIENT_STATE;

// 报警IO控制
typedef struct 
{
	unsigned short		index;					// 端口序号
	unsigned short		state;					// 端口状态
} ZLNET_ALARM_CONTROL;

// 触发方式
typedef struct
{
	unsigned short		index;					// 端口序号
	unsigned short		mode;					// 触发方式(0关闭1手动2自动);不设置的通道，sdk默认将保持原来的设置。
	BYTE				bReserved[28];			
} ZLNET_TRIGGER_MODE_CONTROL;

// 报警解码器控制
typedef struct 
{
	int					decoderNo;				// 报警解码器号，从0开始
	unsigned short		alarmChn;				// 报警输出口，从0开始
	unsigned short		alarmState;				// 报警输出状态；1：打开，0：关闭
} ZLNET_DECODER_ALARM_CONTROL;

// 报警上传功能的报警信息
typedef struct  
{
	DWORD				dwAlarmType;			// 报警类型，dwAlarmType = ZLNET_UPLOAD_EVENT时，dwAlarmMask和bAlarmDecoderIndex是无效的
	DWORD				dwAlarmMask;			// 报警信息掩码，按位表示各报警通道状态
	char				szGlobalIP[ZLNET_MAX_IPADDR_LEN];	// 客户端IP地址
	char				szDomainName[ZLNET_MAX_DOMAIN_NAME_LEN];	// 客户端域名
	int					nPort;					// 报警上传时客户端连接的端口
	char				szAlarmOccurTime[ZLNET_ALARM_OCCUR_TIME_LEN];	// 报警发生的时间
	BYTE				bAlarmDecoderIndex;		// 表示第几个报警解码器，dwAlarmType = ZLNET_UPLOAD_DECODER_ALARM 才有效.
	BYTE				bReservedSpace[15];
} ZLNET_NEW_ALARM_UPLOAD;

// 智能设备上传信息
typedef struct  
{
	char				szDomainName[ZLNET_MAX_DOMAIN_NAME_LEN];	// 设备域名
	char				szIP[ZLNET_MAX_IPADDR_LEN];					// 设备IP地址
	int					nPort;								//设备端口号
	char				szSerial[ZLNET_DEV_SERIALNO_LEN];	//设备序列号
	char				szOccurTime[ZLNET_ALARM_OCCUR_TIME_LEN];	//上传时间
}ZLNET_IDVR_UPLOAD;

// 录像状态变化报警信息
typedef struct
{
	int					nChannel;				// 录像通道号
	char				reserved[12];
} ZLNET_ALARM_RECORDING_CHANGED;

/////////////////////////////语音对讲相关定义/////////////////////////////

// 音频格式信息
typedef struct
{
	BYTE				byFormatTag;			// 编码类型，如0：PCM
	WORD				nChannels;				// 声道数
	WORD				wBitsPerSample;			// 采样深度			
	DWORD				nSamplesPerSec;			// 采样率
} ZLNET_AUDIO_FORMAT, *LPZLNET_AUDIO_FORMAT;

/////////////////////////////用户管理相关定义/////////////////////////////

// 支持用户名最大长度为8位的设备，对应ZLNET_QueryUserInfo和ZLNET_OperateUserInfo接口
// 权限信息
typedef struct _ZLNET_OPR_RIGHT
{
	DWORD				dwID;
	char				name[ZLNET_RIGHT_NAME_LENGTH];
	char				memo[ZLNET_MEMO_LENGTH];
} ZLNET_OPR_RIGHT;

// 用户信息
typedef struct _ZLNET_USER_INFO
{
	DWORD				dwID;
	DWORD				dwGroupID;
	char				name[ZLNET_USER_NAME_LENGTH];
	char				passWord[ZLNET_USER_PSW_LENGTH];
	DWORD				dwRightNum;
	DWORD				rights[ZLNET_MAX_RIGHT_NUM];
	char				memo[ZLNET_MEMO_LENGTH];
	DWORD				dwReusable;				// 是否复用；1：复用，0：不复用
} ZLNET_USER_INFO;

// 用户组信息
typedef struct _ZLNET_USER_GROUP_INFO
{
	DWORD				dwID;
	char				name[ZLNET_USER_NAME_LENGTH];
	DWORD				dwRightNum;
	DWORD				rights[ZLNET_MAX_RIGHT_NUM];
	char				memo[ZLNET_MEMO_LENGTH];
} ZLNET_USER_GROUP_INFO;

// 用户信息表
typedef struct _ZLNET_USER_MANAGE_INFO
{
	DWORD				dwRightNum;				// 权限信息
	ZLNET_OPR_RIGHT			rightList[ZLNET_MAX_RIGHT_NUM];
	DWORD				dwGroupNum;				// 用户组信息
	ZLNET_USER_GROUP_INFO		groupList[ZLNET_MAX_GROUP_NUM];
	DWORD				dwUserNum;				// 用户信息
	ZLNET_USER_INFO			userList[ZLNET_MAX_USER_NUM];
	DWORD				dwSpecial;				// 用户复用能力；1：支持用户复用，0：不支持用户复用
} ZLNET_USER_MANAGE_INFO;

// 支持用户名最大长度为8位或16位的设备，对应扩展接口CLIENT_QueryUserInfoEx和CLIENT_OperateUserInfoEx
#define ZLNET_USER_NAME_LENGTH_EX		16			// 用户名长度
#define ZLNET_USER_PSW_LENGTH_EX		16			// 密码

// 权限信息
typedef struct _ZLNET_OPR_RIGHT_EX
{
	DWORD				dwID;
	char				name[ZLNET_RIGHT_NAME_LENGTH];
	char				memo[ZLNET_MEMO_LENGTH];
} ZLNET_OPR_RIGHT_EX;

// 用户信息
typedef struct _ZLNET_USER_INFO_EX
{
	DWORD				dwID;
	DWORD				dwGroupID;
	char				name[ZLNET_USER_NAME_LENGTH_EX];
	char				passWord[ZLNET_USER_PSW_LENGTH_EX];
	DWORD				dwRightNum;
	DWORD				rights[ZLNET_MAX_RIGHT_NUM];
	char				memo[ZLNET_MEMO_LENGTH];
	DWORD				dwFouctionMask;			// 掩码，0x00000001 - 支持用户复用
	BYTE				byReserve[32];
} ZLNET_USER_INFO_EX;

// 用户组信息
typedef struct _ZLNET_USER_GROUP_INFO_EX
{
	DWORD				dwID;
	char				name[ZLNET_USER_NAME_LENGTH_EX];
	DWORD				dwRightNum;
	DWORD				rights[ZLNET_MAX_RIGHT_NUM];
	char				memo[ZLNET_MEMO_LENGTH];
} ZLNET_USER_GROUP_INFO_EX;

// 用户信息表
typedef struct _ZLNET_USER_MANAGE_INFO_EX
{
	DWORD				dwRightNum;				// 权限信息
	ZLNET_OPR_RIGHT_EX		rightList[ZLNET_MAX_RIGHT_NUM];
	DWORD				dwGroupNum;				// 用户组信息
	ZLNET_USER_GROUP_INFO_EX  groupList[ZLNET_MAX_GROUP_NUM];
	DWORD				dwUserNum;				// 用户信息
	ZLNET_USER_INFO_EX		userList[ZLNET_MAX_USER_NUM];
	DWORD				dwFouctionMask;			// 掩码；0x00000001 - 支持用户复用，0x00000002 - 密码修改需要校验
	BYTE				byNameMaxLength;		// 支持的用户名最大长度
	BYTE				byPSWMaxLength;			// 支持的密码最大长度
	BYTE				byReserve[254];
} ZLNET_USER_MANAGE_INFO_EX;

///////////////////////////////查询相关定义///////////////////////////////

// 设备支持语言种类
typedef struct _ZLNET_LANGUAGE_DEVINFO
{
	DWORD				dwLanguageNum;			// 支持语言个数
	BYTE				byLanguageType[252];	// 枚举值，详见ZL_LANGUAGE_TYPE
} ZLNET_LANGUAGE_DEVINFO, *LPZLNET_LANGUAGE_DEVINFO;

// 硬盘信息
typedef struct
{
	DWORD				dwVolume;				// 硬盘的容量
	DWORD				dwFreeSpace;			// 硬盘的剩余空间
	BYTE				dwStatus;				// 硬盘的状态,0-休眠,1-活动,2-故障等；将DWORD拆成四个BYTE
	BYTE				bDiskNum;				// 硬盘号
	BYTE				bSubareaNum;			// 分区号
	BYTE				bSignal;				// 标识，0为本地 1为远程
} ZLNET_DEV_DISKSTATE,*LPZLNET_DEV_DISKSTATE;

// 设备硬盘信息
typedef struct _ZLNET_HARDDISK_STATE
{
	DWORD				dwDiskNum;				// 个数
	ZLNET_DEV_DISKSTATE	stDisks[ZLNET_MAX_DISKNUM];// 硬盘或分区信息
} ZLNET_HARDDISK_STATE, *LPZLNET_HARDDISK_STATE;

typedef ZLNET_HARDDISK_STATE	ZLNET_SDCARD_STATE;	// SD卡，数据结构同硬盘信息

// 语音编码信息
typedef struct  
{
	ZLNET_TALK_CODING_TYPE	encodeType;				// 编码类型
	int					nAudioBit;				// 位数，如8或16
	DWORD				dwSampleRate;			// 采样率，如8000或16000
	char				reserved[64];
} ZLNET_DEV_TALKDECODE_INFO;

// 设备支持的语音对讲类型
typedef struct 
{
	int					nSupportNum;			// 个数
	ZLNET_DEV_TALKDECODE_INFO type[64];				// 编码类型
	char				reserved[64];
} ZLNET_DEV_TALKFORMAT_LIST;

// 云台属性信息
#define  ZLNET_NAME_MAX_LEN 16
typedef struct 
{
	DWORD				dwHighMask;				// 操作的掩码高位
	DWORD				dwLowMask;				// 操作的掩码低位
	char				szName[ZLNET_NAME_MAX_LEN];	// 操作的协议名
	WORD				wCamAddrMin;			// 通道地址的最小值
	WORD				wCamAddrMax;			// 通道地址的最大值
	WORD				wMonAddrMin;			// 监视地址的最小值
	WORD				wMonAddrMax;			// 监视地址的最大值
	BYTE				bPresetMin;				// 预置点的最小值
	BYTE				bPresetMax;				// 预置点的最大值
	BYTE				bTourMin;				// 自动巡航线路的最小值
	BYTE				bTourMax;				// 自动巡航线路的最大值
	BYTE				bPatternMin;			// 轨迹线路的最小值
	BYTE				bPatternMax;			// 轨迹线路的最大值
	BYTE				bTileSpeedMin;			// 垂直速度的最小值
	BYTE				bTileSpeedMax;			// 垂直速度的最大值
	BYTE				bPanSpeedMin;			// 水平速度的最小值
	BYTE				bPanSpeedMax;			// 水平速度的最大值
	BYTE				bAuxMin;				// 辅助功能的最小值
	BYTE				bAuxMax;				// 辅助功能的最大值
	int					nInternal;				// 发送命令的时间间隔
	char				cType;					// 协议的类型
	BYTE				bReserved_1;			// 保留
	BYTE				bFuncMask;				// 协议功能掩码,按位表示,置１表示支持,第一位表示内置云台功能，其它７位暂时保留
	BYTE				bReserved_2;
	char				Reserved[4];
} ZLNET_PTZ_OPT_ATTR;

// 刻录机信息
typedef struct _ZLNET_DEV_BURNING
{
	DWORD				dwDriverType;			// 刻录驱动器类型；0：DHFS，1：DISK，2：CDRW
	DWORD				dwBusType;				// 总线类型；0：USB，1：1394，2：IDE
	DWORD				dwTotalSpace;			// 总容量(KB)
	DWORD				dwRemainSpace;			// 剩余容量(KB)
	BYTE				dwDriverName[ZLNET_BURNING_DEV_NAMELEN];	// 刻录驱动器名称
} ZLNET_DEV_BURNING, *LPZLNET_DEV_BURNING;

// 设备刻录机信息
typedef struct _ZLNET_BURNING_DEVINFO
{
	DWORD				dwDevNum;				// 刻录设备个数
	ZLNET_DEV_BURNING		stDevs[ZLNET_MAX_BURNING_DEV_NUM];	// 各刻录设备信息
} ZLNET_BURNING_DEVINFO, *LPZLNET_BURNING_DEVINFO;

// 刻录进度
typedef struct _ZLNET_BURNING_PROGRESS
{
	BYTE				bBurning;				// 刻录机状态；0：可以刻录，1：刻录机类型不对，是一个非光盘设备，
												// 2：未找到刻录机，3：有其它光盘在刻录，4：刻录机处于非空闲状态，即在备份、刻录或回放中
	BYTE				bRomType;				// 盘片类型；0：智诺文件系统，1：移动硬盘或U盘，2：光盘
	BYTE				bOperateType;			// 操作类型；0：空闲，1：正在备份中，2：正在刻录中，3：正在进行光盘回放
	BYTE				bType;					// 备份或刻录过程状态；0：停止或结束，1：开始，2：出错，3：满，4：正在初始化
	ZLNET_TIME			stTimeStart;			// 开始时间　
	DWORD				dwTimeElapse;			// 已刻录时间(秒)
	DWORD				dwTotalSpace;			// 光盘总容量
	DWORD				dwRemainSpace;			// 光盘剩余容量
	DWORD				dwBurned;				// 已刻录容量
	WORD				dwStatus;				// 保留
	WORD				wChannelMask;			// 正在刻录的通道掩码
} ZLNET_BURNING_PROGRESS, *LPZLNET_BURNING_PROGRESS;

// 日志信息，对应接口CLIENT_QueryLog接口
typedef struct _ZLNET_LOG_ITEM
{
    ZLNET_DEVTIME			time;					// 日期
    unsigned short		type;					// 类型
    unsigned char		reserved;				// 保留
    unsigned char		data;					// 数据
    unsigned char		context[8];				// 内容
} ZLNET_LOG_ITEM, *LPZLNET_LOG_ITEM;

// 日志信息，对应扩展接口CLIENT_QueryLogEx，参数reserved(int nType=1;reserved=&nType;)
typedef struct _ZLNET_NEWLOG_ITEM
{
	ZLNET_DEVTIME			time;					// 日期
	WORD				type;					// 类型
	WORD				data;					// 数据
	char				szOperator[8]; 			// 用户名
	BYTE				context[16];		    // 内容	
} ZLNET_NEWLOG_ITEM, *LPZLNET_NEWLOG_ITEM;

// 日志信息，对应接口CLIENT_QueryDeviceLog接口
typedef struct _ZLNET_DEVICE_LOG_ITEM
{
	int					nLogType;				// 日志类型
	ZLNET_DEVTIME			stuOperateTime;			// 日期
	char				szOperator[16]; 		// 操作者
	BYTE				bReserved[3];
	BYTE				bUnionType;				//  union结构类型,0:szLogContext；1:stuOldLog。
	union
	{
		char			szLogContext[64];		// 日志内容
		struct 
		{
			ZLNET_LOG_ITEM		stuLog;				// 旧的日志结构体
			BYTE			bReserved[48];		// 保留
		}stuOldLog;
	};
	char				reserved[16];
} ZLNET_DEVICE_LOG_ITEM, *LPZLNET_DEVICE_LOG_ITEM;

// 录象日志信息，对应日志结构体里的context
typedef struct _ZLNET_LOG_ITEM_RECORD
{
	ZLNET_DEVTIME			time;					// 时间
	BYTE				channel;				// 通道
	BYTE				type;					// 录像类型
	BYTE				reserved[2];
} ZLNET_LOG_ITEM_RECORD, *LPZLNET_LOG_ITEM_RECORD;

typedef struct _ZLNET_QUERY_DEVICE_LOG_PARAM
{
	ZLNET_LOG_QUERY_TYPE	emLogType;				// 查询日志类型
	ZLNET_TIME			stuStartTime;			// 查询日志的开始时间
	ZLNET_TIME			stuEndTime;				// 查询日志的结束时间
	int					nStartNum;				// 在时间段中从第几条日志开始查询，开始第一次查询可设为0
	int					nEndNum;				// 一次查询中到第几条日志结束。
	BYTE				bReserved[48];
} ZLNET_QUERY_DEVICE_LOG_PARAM;

// 设备硬盘里的录象信息
typedef struct __ZLNET_DEV_DISK_RECORD_INFO 
{
	ZLNET_TIME			stuBeginTime;			// 最早录象时间
	ZLNET_TIME			stuEndTime;				// 最近录象时间
	char				reserved[128];
} ZLNET_DEV_DISK_RECORD_INFO;

///////////////////////////////控制相关定义///////////////////////////////

// 硬盘操作
typedef struct _ZLNET_DISKCTRL_PARAM
{
	DWORD				dwSize;					// 结构体大小，版本控制用
	int					nIndex;					// 为硬盘信息结构体ZLNET_HARDDISK_STATE里的数组stDisks下标，从0开始
	int					ctrlType;				// 操作类型，
												// 0 - 清除数据, 1 - 设为读写盘, 2 - 设为只读盘
												// 3 - 设为冗余盘, 4 - 恢复错误, 5 - 设为快照盘
} ZLNET_DISKCTRL_PARAM;

typedef struct  
{
	BYTE				bSubareaNum;			// 预分区的个数
	BYTE				bIndex;					// 为硬盘信息结构体ZL_HARDDISK_STATE里的数组stDisks下标，从0开始
	BYTE				bSubareaSize[32];		// 分区大小（百分比）
	BYTE				bReserved[30];			// 保留
} ZLNET_DISKCTRL_SUBAREA;

// 报警状态
typedef struct _ZLNET_ALARMCTRL_PARAM
{
	DWORD				dwSize;
	int					nAlarmNo;				// 报警通道号，从0开始
	int					nAction;				// 1：触发报警，0：停止报警
} ZLNET_ALARMCTRL_PARAM;

// 矩阵控制
typedef struct _ZLNET_MATRIXCTRL_PARAM
{
	DWORD				dwSize;
	int					nChannelNo;				// 视频输入号，从0开始
	int					nMatrixNo;				// 矩阵输出号，从0开始
} ZLNET_MATRIXCTRL_PARAM;

// 刻录控制
typedef struct _ZLNET_BURNING_PARM
{
	int					channelMask;			// 通道掩码，按位表示要刻录的通道
	int					devMask;				// 刻录机掩码，根据查询到的刻录机列表，按位表示
} ZLNET_BURNING_PARM;

// 附件刻录
typedef struct _ZLNET_BURNING_PARM_ATTACH
{
	BOOL				bAttachBurn;			// 是否为附件刻录，0:不是; 1:是
	BYTE				bReserved[12];			// 保留字段
} ZLNET_BURNING_PARM_ATTACH;

///////////////////////////////配置相关定义///////////////////////////////

//-------------------------------设备属性---------------------------------
// 设备信息
typedef struct
{
	BYTE				sSerialNumber[ZLNET_SERIALNO_LEN];	// 序列号
	BYTE				byAlarmInPortNum;		// DVR报警输入个数
	BYTE				byAlarmOutPortNum;		// DVR报警输出个数
	BYTE				byDiskNum;				// DVR硬盘个数
	BYTE				byDVRType;				// DVR类型, 见枚举ZLNET_DEVICE_TYPE
	BYTE				byChanNum;				// DVR通道个数
} ZLNET_DEVICEINFO, *LPZLNET_DEVICEINFO;

// 设备软件版本信息，高16位表示主版本号，低16位表示次版本号
typedef struct 
{
	DWORD				dwSoftwareVersion;
	DWORD				dwSoftwareBuildDate;
	DWORD				dwDspSoftwareVersion;
	DWORD				dwDspSoftwareBuildDate;
	DWORD				dwPanelVersion;
	DWORD				dwPanelSoftwareBuildDate;
	DWORD				dwHardwareVersion;
	DWORD				dwHardwareDate;
	DWORD				dwWebVersion;
//	DWORD				dwWebBuildDate;
} ZLNET_VERSION_INFO, *LPZLNET_VERSION_INFO;

// 设备软件版本信息，对应ZLNET_DEVICE_TYPE接口
typedef struct  
{
	char				szDevSerialNo[ZLNET_DEV_SERIALNO_LEN];	// 序列号
	char				byDevType;				// 设备类型，见枚举ZLNET_DEVICE_TYPE
	char				szDevType[ZLNET_DEV_TYPE_LEN];	// 设备详细型号，字符串格式，可能为空
	int					nProtocalVer;			// 协议版本号
	char				szSoftWareVersion[ZLNET_MAX_URL_LEN];
	DWORD				dwSoftwareBuildDate;
	char				szDspSoftwareVersion[ZLNET_MAX_URL_LEN];
	DWORD				dwDspSoftwareBuildDate;
	char				szPanelVersion[ZLNET_MAX_URL_LEN];
	DWORD				dwPanelSoftwareBuildDate;
	char				szHardwareVersion[ZLNET_MAX_URL_LEN];
	DWORD				dwHardwareDate;
	char				szWebVersion[ZLNET_MAX_URL_LEN];
//	DWORD				dwWebBuildDate;
	char				chHardVersion;	//硬件版本类型 0：16M Flash  1：32M Flash
	char				reserved[255];
} ZLNET_DEV_VERSION_INFO;

//
typedef struct 
{
	unsigned int nMaxEncodePower; ///< DSP 支持的最高编码能力。
	unsigned short nMaxSupportChannel; ///< DSP 支持最多输入视频通道数。
	unsigned short bChannelMaxSetSync; ///< DSP 每通道的最大编码设置是否同步 0-不同步, 1 -同步。
	unsigned short nExpandChannel;  ///< DSP 支持的扩展通道数，主要是多路回放使用，目前只是一个
	unsigned short  rev;
}ZLNET_CAPTURE_DSPINFO, *LPZLNET_CAPTURE_DSPINFO;

#define MAX_ENC_CHIP_NR (32)
typedef struct  
{
	int EncChipNR;
	ZLNET_CAPTURE_DSPINFO EncChipInfo[MAX_ENC_CHIP_NR];
}ZLNET_CAPTURE_CAPABILITY;

// DSP能力描述，对应CLIENT_GetDevConfig接口
typedef struct 
{
	DWORD				dwVideoStandardMask;	// 视频制式掩码，按位表示设备能够支持的视频制式
	DWORD				dwImageSizeMask;		// 分辨率掩码，按位表示设备能够支持的分辨率设置
	DWORD				dwEncodeModeMask;		// 编码模式掩码，按位表示设备能够支持的编码模式设置	
	DWORD				dwStreamCap;			// 按位表示设备支持的多媒体功能，
												// 第一位表示支持主码流
												// 第二位表示支持辅码流1
												// 第三位表示支持辅码流2
												// 第五位表示支持jpg抓图
	DWORD				dwImageSizeMask_Assi[8];// 表示主码流为各分辨率时，支持的辅码流分辨率掩码。
	ZLNET_CAPTURE_CAPABILITY captureCapability;
} ZLNET_DSP_ENCODECAP, *LPZLNET_DSP_ENCODECAP;

// DSP能力描述，扩展类型，对应ZLNET_DEVICE_TYPE接口
typedef struct 
{
	DWORD				dwVideoStandardMask;	// 视频制式掩码，按位表示设备能够支持的视频制式
	DWORD				dwImageSizeMask;		// 分辨率掩码，按位表示设备能够支持的分辨率
	DWORD				dwEncodeModeMask;		// 编码模式掩码，按位表示设备能够支持的编码模式
	DWORD				dwStreamCap;			// 按位表示设备支持的多媒体功能，
												// 第一位表示支持主码流
												// 第二位表示支持辅码流1
												// 第三位表示支持辅码流2
												// 第五位表示支持jpg抓图
	DWORD				dwImageSizeMask_Assi[32];// 表示主码流为各分辨率时，支持的辅码流分辨率掩码。
	ZLNET_CAPTURE_CAPABILITY captureCapability;
	BYTE				bMaxFrameOfImageSize[32];// 不同分辨率下的最大采集帧率，与dwVideoStandardMask按位对应
	BYTE				bEncodeCap;				// 标志，配置时要求符合下面条件，否则配置不能生效；
												// 0：主码流的编码能力+辅码流的编码能力 <= 设备的编码能力，
												// 1：主码流的编码能力+辅码流的编码能力 <= 设备的编码能力，
												// 辅码流的编码能力 <= 主码流的编码能力，
												// 辅码流的分辨率 <= 主码流的分辨率，
												// 主码流和辅码流的帧率 <= 前端视频采集帧率
												// 2：N5的计算方法
												// 辅码流的分辨率 <= 主码流的分辨率
												// 查询支持的分辨率和相应最大帧率
	char				reserved[95];
} ZLNET_DEV_DSP_ENCODECAP, *LPZLNET_DEV_DSP_ENCODECAP;

// 系统信息
typedef struct 
{
	DWORD				dwSize;
	/* 下面是设备的只读部分 */
	ZLNET_VERSION_INFO		stVersion;
	ZLNET_DSP_ENCODECAP	stDspEncodeCap;			// DSP能力描述
	BYTE				szDevSerialNo[ZLNET_DEV_SERIALNO_LEN];	// 序列号
	BYTE				byDevType;				// 设备类型，见枚举ZLNET_DEVICE_TYPE
	BYTE				szDevType[ZLNET_DEV_TYPE_LEN];	// 设备详细型号，字符串格式，可能为空
	BYTE				byVideoCaptureNum;		// 视频口数量
	BYTE				byAudioCaptureNum;		// 音频口数量
	BYTE				byTalkInChanNum;		// NSP
	BYTE				byTalkOutChanNum;		// NSP
	BYTE				byDecodeChanNum;		// NSP
	BYTE				byAlarmInNum;			// 报警输入口数
	BYTE				byAlarmOutNum;			// 报警输出口数
	BYTE				byNetIONum;				// 网络口数
	BYTE				byUsbIONum;				// USB口数量
	BYTE				byIdeIONum;				// IDE数量
	BYTE				byComIONum;				// 串口数量
	BYTE				byLPTIONum;				// 并口数量
	BYTE				byVgaIONum;				// NSP
	BYTE				byIdeControlNum;		// NSP
	BYTE				byIdeControlType;		// NSP
	BYTE				byCapability;			// NSP，扩展描述
	BYTE				byMatrixOutNum;			// 视频矩阵输出口数
	UINT                uOEM;                   // OEM版本号
	/* 下面是设备的可写部分 */
	BYTE				byOverWrite;			// 硬盘满处理方式(覆盖、停止)
	BYTE				byRecordLen;			// 录象打包长度
	BYTE				byDSTEnable;			// 是否实行夏令时 1-实行 0-不实行
	WORD				wDevNo;					// 设备编号，用于遥控
	BYTE				byVideoStandard;		// 视频制式:0-PAL,1-NTSC
	BYTE				byDateFormat;			// 日期格式
	BYTE				byDateSprtr;			// 日期分割符(0："."，1："-"，2："/")
	BYTE				byTimeFmt;				// 时间格式 (0-24小时，1－12小时)
	BYTE				byLanguage;				// 枚举值详见ZLNET_LANGUAGE_TYPE
} ZLNET_DEV_SYSTEM_ATTR_CFG, *LPZLNET_DEV_SYSTEM_ATTR_CFG;

// 修改设备配置返回信息
typedef struct
{
	DWORD				dwType;					// 类型(即GetDevConfig和SetDevConfig的类型)
	WORD				wResultCode;			// 返回码；0：成功，1：失败，2：数据不合法，3：暂时无法设置，4：没有权限
	WORD   				wRebootSign;			// 重启标志；0：不需要重启，1：需要重启才生效
	DWORD				dwReserved[2];			// 保留	
} ZLNET_DEV_SET_RESULT;

//DST(夏令时)配置
typedef struct  
{
	int					nYear;					// 年[200 - 2037]
	int					nMonth;					// 月[1 - 12]
	int					nHour;					// 小时 [0 - 23]
	int					nMinute;				// 分钟 [0 - 59]
	int					nWeekOrDay;				// [-1 - 4]0:表示使用按日期计算的方法
												// 1: 按周计算: 第一周,2: 第二周,3: 第三周,4: 第四周,-1: 最后一周
	union
	{
		int				iWeekDay;				// 周[0 - 6](nWeekOrDay：按周计算时)0:星期日, 1:星期一, 2:星期二,3:星期三,4:星期四,5:星期五,6:星期六
		int				iDay;					// 日期[1 - 31] (nWeekOrDay：按日期计算)
	};
	
	DWORD				dwReserved[8];			// 保留	
}ZLNET_DST_POINT;

typedef struct  
{
	DWORD				dwSize;
	int					nDSTType;				// 夏令时定位方式 0:按日期定位方式, 1:按周定位方式
	ZLNET_DST_POINT        stDSTStart;             // 开始夏令时
	ZLNET_DST_POINT        stDSTEnd;				// 结束夏令时
	DWORD				dwReserved[16];			// 保留	
}ZLNET_DST_DEV_CFG;


// 自动维护配置
typedef struct
{
	DWORD				dwSize;
	BYTE				byAutoRebootDay;		// 自动重启；0：从不, 1：每天，2：每星期日，3：每星期一，......
	BYTE				byAutoRebootTime;		// 0：0:00，1：1:00，......23：23:00
	BYTE				byAutoDeleteFilesTime;	// 自动删除文件；0：从不，1：24H，2：48H，3：72H，4：96H，5：ONE WEEK，6：ONE MONTH
	BYTE				reserved[13];			// 保留位
} ZLNET_AUTOMT_CFG;

//-----------------------------图像通道属性-------------------------------

// 时间段结构															    
typedef struct 
{
	BOOL				bEnable;				// 当表示录像时间段时，按位表示三个使能，从低位到高位分别表示动检录象、报警录象、普通录象
	int					iBeginHour;
	int					iBeginMin;
	int					iBeginSec;
	int					iEndHour;
	int					iEndMin;
	int					iEndSec;
} ZLNET_TSECT, *LPZLNET_TSECT;

// 点坐标
typedef struct _ZLNET_POINT
{
	long	x;
	long	y;
}ZLNET_POINT;
// 区域；各边距按整长8192的比例
typedef struct {
   long					left;
   long					top;
   long					right;
   long					bottom;
} ZLNET_RECT, *LPZLNET_RECT;

// OSD属性结构
typedef struct  __ZLNET_ENCODE_WIDGET
{
	DWORD				rgbaFrontground;		// 物件的前景；按字节表示，分别为红、绿、蓝和透明度
	DWORD				rgbaBackground;			// 物件的背景；按字节表示，分别为红、绿、蓝和透明度
	ZLNET_RECT				rcRect;					// 位置
	BYTE				bShow;					// 显示使能
	BYTE				byReserved[3];
} ZLNET_ENCODE_WIDGET, *LPZLNET_ENCODE_WIDGET;

// 通道音视频属性
typedef struct 
{
	// 视频参数
	BYTE				byVideoEnable;			// 视频使能；1：打开，0：关闭
	BYTE				byBitRateControl;		// 码流控制；参照常量"码流控制"定义
	BYTE				byFramesPerSec;			// 帧率
	BYTE				byEncodeMode;			// 编码模式；参照常量"编码模式"定义
	BYTE				byImageSize;			// 分辨率；参照常量"分辨率"定义
	BYTE				byImageQlty;			// 档次1-6
	WORD				wLimitStream;			// 限码流参数
	// 音频参数
	BYTE				byAudioEnable;			// 音频使能；1：打开，0：关闭
	BYTE				wFormatTag;				// 音频编码类型
	WORD				nChannels;				// 声道数
	WORD				wBitsPerSample;			// 采样深度	
	BYTE				bAudioOverlay;			// 音频叠加使能
	BYTE				bReserved_2;
	DWORD				nSamplesPerSec;			// 采样率
	BYTE				bIFrameInterval;		// I帧间隔帧数量，描述两个I帧之间的P帧个数，0-149
	BYTE				bScanMode;				// NSP
	BYTE				bReserved_3;
	BYTE				bReserved_4;
} ZLNET_VIDEOENC_OPT, *LPZLNET_VIDEOENC_OPT;

// 画面颜色属性
typedef struct 
{
	ZLNET_TSECT			stSect;
	BYTE				byBrightness;			// 亮度；0-100
	BYTE				byContrast;				// 对比度；0-100
	BYTE				bySaturation;			// 饱和度；0-100
	BYTE				byHue;					// 色度；0-100
	BYTE				byGainEn;				// 增益使能
	BYTE				byGain;					// 增益；0-100
	BYTE				byWhitebalance;			/*!<自动白电平控制，bit7置位表示开启自动控制.0x0,0x1,0x2分别代表低,中,高等级*/
	BYTE				byReserved[1];
} ZLNET_COLOR_CFG, *LPZLNET_COLOR_CFG;

// 图像通道属性结构体
typedef struct 
{
	//DWORD				dwSize;
	WORD				dwSize;
	BYTE				bNoise;
	BYTE				byMicAutoSwitch;/* MIC和线性音频 MIC:0  线性音频：1 */
	char				szChannelName[ZLNET_CHAN_NAME_LEN];
	ZLNET_VIDEOENC_OPT		stMainVideoEncOpt[ZLNET_REC_TYPE_NUM];
	ZLNET_VIDEOENC_OPT		stAssiVideoEncOpt[ZLNET_N_ENCODE_AUX];		
	ZLNET_COLOR_CFG		stColorCfg[ZLNET_N_COL_TSECT];
	ZLNET_ENCODE_WIDGET	stTimeOSD;
	ZLNET_ENCODE_WIDGET	stChannelOSD;
	ZLNET_ENCODE_WIDGET	stBlindCover[ZLNET_N_COVERS];	// 单区域遮挡
	BYTE				byBlindEnable;			// 区域遮盖开关；0x00：不使能遮盖，0x01：仅遮盖设备本地预览，0x10：仅遮盖录像及网络预览，0x11：都遮盖
	BYTE				byBlindMask;			// 区域遮盖掩码；第一位：设备本地预览；第二位：录像(及网络预览) */
	BYTE				bVolume;				// 音量阀值(0~100可调)
	BYTE				bVolumeEnable;			// 音量阀值使能
} ZLNET_DEV_CHANNEL_CFG, *LPZLNET_DEV_CHANNEL_CFG;

// 预览图像参数
typedef struct 
{
	DWORD				dwSize;
	ZLNET_VIDEOENC_OPT		stPreView;
	ZLNET_COLOR_CFG		stColorCfg[ZLNET_N_COL_TSECT];
}ZLNET_DEV_PREVIEW_CFG;

//-------------------------------串口属性---------------------------------

// 串口基本属性
typedef struct
{
	BYTE				byDataBit;				// 数据位；0：5，1：6，2：7，3：8
	BYTE				byStopBit;				// 停止位；0：1位，1：1.5位，2：2位
	BYTE				byParity;				// 校验位；0：无校验，1：奇校验；2：偶校验
	BYTE				byBaudRate;				// 波特率；0：300，1：600，2：1200，3：2400，4：4800，
												// 5：9600，6：19200，7：38400，8：57600，9：115200
} ZLNET_COMM_PROP;

// 485解码器配置
typedef struct
{ 
	ZLNET_COMM_PROP		struComm;
	BYTE				wProtocol;				// 协议类型，对应"协议名列表"下标
	BYTE				bPTZType;				// 0-兼容，本地云台 1-远程网络云台,通过能力查询(见DEV_ENCODER_CFG)。
	BYTE				wDecoderAddress;		// 解码器地址；0 - 255
	BYTE 				byMartixID;				// 矩阵号
} ZLNET_485_CFG;

//485模拟控制
typedef struct
{
	BOOL bSimulationCtrl;						//模拟控制 0-关闭 1-打开
	int nSimulationSpeed;						//模拟速率 1~30s
	int nRes[4];
} ZLNET_485_SIMULATION_CTRL;

//485模拟控制配置
typedef struct
{
	int nSize;														//结构体大小
	int nValidNum;													//有效个数
	ZLNET_485_SIMULATION_CTRL simulationCtrl[ZLNET_MAX_CHANNUM];	//各通道模拟控制
} ZLNET_485_SIMULATION_CTRL_CFG;

// 232串口配置
typedef struct
{
	ZLNET_COMM_PROP		struComm;
	BYTE				byFunction;				// 串口功能，对应"功能名列表"下标
	BYTE				byReserved[3];
} ZLNET_RS232_CFG;

// 串口配置结构体
typedef struct
{
	DWORD				dwSize;

	DWORD				dwDecProListNum;				// 解码器协议个数
	char				DecProName[ZLNET_MAX_DECPRO_LIST_SIZE][ZLNET_MAX_NAME_LEN]; // 协议名列表
	ZLNET_485_CFG			stDecoder[ZLNET_MAX_DECODER_NUM];	// 各解码器当前属性

	DWORD				dw232FuncNameNum;		// 232功能个数
	char				s232FuncName[ZLNET_MAX_232FUNCS][ZLNET_MAX_NAME_LEN];	// 功能名列表
	ZLNET_RS232_CFG		st232[ZLNET_MAX_232_NUM];	// 各232串口当前属性
} ZLNET_DEV_COMM_CFG;

// 串口状态
typedef struct
{
	unsigned int		uBeOpened;
	unsigned int		uBaudRate;
	unsigned int		uDataBites;
	unsigned int		uStopBits;
	unsigned int		uParity;
	BYTE				bReserved[32];
} ZLNET_COMM_STATE;

//串口类型
typedef struct _ZLNET_COM_TYPE
{
	int nSize;				//结构体大小
	int nComType;			//串口类型 0:232 1:485
	int Res[4];
}ZLNET_COM_TYPE;

//-------------------------------录象配置---------------------------------

// 定时录象
typedef struct 
{
	DWORD				dwSize;
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];
	BYTE				byPreRecordLen;			// 预录时间，单位是s，0表示不预录
	BYTE				byRedundancyEn;			// 录像冗余开关
	BYTE                byRecordType;           // 录像码流类型：0-主码流 1-辅码流1 2-辅码流2 3-辅码流3
	BYTE				byReserved;
} ZLNET_DEV_RECORD_CFG, *LPZLNET_DEV_RECORD_CFG;

// NTP配置
typedef struct  
{
	BOOL				bEnable;				//	是否启用
	int					nHostPort;				//	NTP服务器默认端口为123
	char				szHostIp[32];			//	主机IP
	char				szDomainName[128];		//	域名
	int					nType;					//	不可设置，0：表示IP，1：表示域名，2：表示IP和域名
	int					nUpdateInterval;		//	更新时间(分钟)
	int					nTimeZone;				//	见ZLNET_TIME_ZONE_TYPE
	char				reserved[128];
} ZLNET_NTP_DEV_CFG;

// FTP上传配置
typedef struct
{
	struct
	{
		ZLNET_TSECT		struSect;				// 该时间段内的“使能”无效，可忽略
		BOOL			bMdEn;					// 上传动态检测录象
		BOOL			bAlarmEn;				// 上传外部报警录象
		BOOL			bTimerEn;				// 上传普通定时录像
		DWORD			dwRev[4];
	} struPeriod[ZLNET_TIME_SECTION];
} ZLNET_FTP_UPLOAD_CFG;

typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;							// 是否启用
	char				szHostIp[ZLNET_MAX_IPADDR_LEN];		// 主机IP
	WORD				wHostPort;							// 主机端口
	char				szDirName[ZLNET_FTP_MAX_PATH];			// FTP目录路径
	char				szUserName[ZLNET_FTP_USERNAME_LEN];	// 用户名
	char				szPassword[ZLNET_FTP_PASSWORD_LEN];	// 密码
	int					iFileLen;							// 文件长度
	int					iInterval;							// 相邻文件时间间隔
	ZLNET_FTP_UPLOAD_CFG	struUploadCfg[ZLNET_MAX_CHANNUM][ZLNET_N_WEEKS];
	char 				protocol;							// 0-FTP 1-SMB
	char				NASVer;								// 网络存储服务器版本0=老的FTP(界面上显示时间段)，1=NAS存储(界面上屏蔽时间段)
	DWORD				dwFunctionMask;						// 功能能力掩码，按位表示，低16位(网络存储)依次表示FTP，SMB，NFS，高16位(本地存储)依次为DISK，U
	BOOL				bAnonymous;							// 是否匿名登录
	BYTE 				reserved[120];
} ZLNET_FTP_PROTO_CFG;

typedef struct
{
	ZLNET_FTP_PROTO_CFG struFtpCfg[2]; //0: 录像FTP 1:图片FTP
}ZLNET_FTP_PROTO_CFG_EX;



//-------------------------------网络配置---------------------------------

// 以太网配置
typedef struct 
{
	char				sDevIPAddr[ZLNET_MAX_IPADDR_LEN];	// DVR IP 地址
	char				sDevIPMask[ZLNET_MAX_IPADDR_LEN];	// DVR IP 地址掩码
	char				sGatewayIP[ZLNET_MAX_IPADDR_LEN];	// 网关地址

	/*
	 * 1：10Mbps 全双工
	 * 2：10Mbps 自适应
	 * 3：10Mbps 半双工
	 * 4：100Mbps 全双工
	 * 5：100Mbps 自适应
	 * 6：100Mbps 半双工
	 * 7：自适应
	 */
	// 为了扩展将DWORD拆成四个
	BYTE				dwNetInterface;			// NSP
	BYTE				bTranMedia;				// 0：有线，1：无线
	BYTE				bValid;					// 按位表示，第一位：1：有效 0：无效；第二位：0：DHCP关闭 1：DHCP使能；第三位：0：不支持DHCP 1：支持DHCP
	BYTE				bDefaultEth;			// 是否作为默认的网卡 1：默认 0：非默认
	char				byMACAddr[ZLNET_MACADDR_LEN];	// MAC地址，只读
} ZLNET_ETHERNET; 

// 远程主机配置
typedef struct 
{
	BYTE				byEnable;				// 连接使能
	BYTE				byAssistant;            // 目前只对于PPPoE服务器有用，0：在有线网卡拨号；1：在无线网卡上拨号
	WORD				wHostPort;				// 远程主机 端口
	char				sHostIPAddr[ZLNET_MAX_IPADDR_LEN];		// 远程主机 IP 地址		
	char				sHostUser[ZLNET_MAX_HOST_NAMELEN];		// 远程主机 用户名
	char				sHostPassword[ZLNET_MAX_HOST_PSWLEN];	// 远程主机 密码
} ZLNET_REMOTE_HOST;

// 邮件配置
typedef struct 
{
	char				sMailIPAddr[ZLNET_MAX_IPADDR_LEN];	// 邮件服务器IP地址
	WORD				wMailPort;				// 邮件服务器端口
	WORD				wReserved;				// 保留
	char				sSenderAddr[ZLNET_MAX_MAIL_ADDR_LEN];	// 发送地址
	char				sUserName[ZLNET_MAX_NAME_LEN];			// 用户名
	char				sUserPsw[ZLNET_MAX_NAME_LEN];			// 用户密码
	char				sDestAddr[ZLNET_MAX_MAIL_ADDR_LEN];	// 目的地址
	char				sCcAddr[ZLNET_MAX_MAIL_ADDR_LEN];		// 抄送地址
	char				sBccAddr[ZLNET_MAX_MAIL_ADDR_LEN];		// 暗抄地址
	char				sSubject[ZLNET_MAX_MAIL_SUBJECT_LEN];	// 标题
} ZLNET_MAIL_CFG;

// 网络配置结构体
typedef struct
{ 
	DWORD				dwSize; 

	char				sDevName[ZLNET_MAX_NAME_LEN];	// 设备主机名

	WORD				wTcpMaxConnectNum;		// TCP最大连接数
	WORD				wTcpPort;				// TCP帧听端口
	WORD				wUdpPort;				// UDP侦听端口
	WORD				wHttpPort;				// HTTP端口号
	WORD				wHttpsPort;				// HTTPS端口号
	WORD				wSslPort;				// SSL端口号
	ZLNET_ETHERNET			stEtherNet[ZLNET_MAX_ETHERNET_NUM];	// 以太网口

	ZLNET_REMOTE_HOST		struAlarmHost;			// 报警服务器
	ZLNET_REMOTE_HOST		struLogHost;			// 日志服务器
	ZLNET_REMOTE_HOST		struSmtpHost;			// SMTP服务器
	ZLNET_REMOTE_HOST		struMultiCast;			// 多播组
	ZLNET_REMOTE_HOST		struNfs;				// NFS服务器
	ZLNET_REMOTE_HOST		struPppoe;				// PPPoE服务器
	char				sPppoeIP[ZLNET_MAX_IPADDR_LEN]; // PPPoE注册返回的IP
	ZLNET_REMOTE_HOST		struDdns;				// DDNS服务器
	char				sDdnsHostName[ZLNET_MAX_HOST_NAMELEN];	// DDNS主机名
	ZLNET_REMOTE_HOST		struDns;				// DNS服务器
	ZLNET_MAIL_CFG			struMail;				// 邮件配置
} ZLNET_DEV_NET_CFG;

// 网络配置结构体——扩展
typedef struct
{ 
	ZLNET_DEV_NET_CFG pDevNetCfg;

	//能力管控
	int MaxNetMonitor;  //网络监控。0表示禁止网传，0x7FFFFFFF表示无限制
	int MaxDownload;  //录像下载
} ZLNET_DEV_NET_CFG_EX;

// 网络配置结构体——扩展2
typedef struct
{ 
	ZLNET_DEV_NET_CFG pDevNetCfg;

	//能力管控
	int MaxNetMonitor;  //网络监控。0表示禁止网传，0x7FFFFFFF表示无限制
	int MaxDownload;	//录像下载
	BOOL bUpnpEnable;	//upnp使能
	int nRtspPort;		//RTSP端口
	int Res[15];		//保留
} ZLNET_DEV_NET_CFG_NEW_EX;

//RTSP配置
typedef struct
{
	int nSize;														//结构体大小
	int nValidNum;													//有效个数
	char chRstpUrl[ZLNET_RTSP_URL_MAX_NUM][ZLNET_MAX_URL_LEN];	//RTSP URL
	int nRes[16];													//保留
} ZLNET_DEV_RTSP_CONFIG;

// 多ddns配置结构体
typedef struct
{
	DWORD				dwId;					// ddns服务器id号
	BOOL				bEnable;				// 使能，同一时间只能有一个ddns服务器处于使能状态
	char				szServerType[ZLNET_MAX_SERVER_TYPE_LEN];	// 服务器类型，希网..
	char				szServerIp[ZLNET_MAX_DOMAIN_NAME_LEN];		// 服务器ip或者域名
	DWORD				dwServerPort;			// 服务器端口
	char				szDomainName[ZLNET_MAX_DOMAIN_NAME_LEN];	// dvr域名，如jeckean.3322.org
	char				szUserName[ZLNET_MAX_HOST_NAMELEN];		// 用户名
	char				szUserPsw[ZLNET_MAX_HOST_PSWLEN];			// 密码
	char				szAlias[ZLNET_MAX_DDNS_ALIAS_LEN];			// 服务器别名，如"ZL inter ddns"
	DWORD				dwAlivePeriod;							// DDNS 保活时间
	char				reserved[256];
} ZLNET_DDNS_SERVER_CFG;

typedef struct
{
	DWORD				dwSize;
	DWORD				dwDdnsServerNum;	
	ZLNET_DDNS_SERVER_CFG	struDdnsServer[ZLNET_MAX_DDNS_NUM];	
} ZLNET_DEV_MULTI_DDNS_CFG;

// 邮件配置结构体
typedef struct 
{
	char				sMailIPAddr[ZLNET_MAX_DOMAIN_NAME_LEN];	// 邮件服务器地址(IP或者域名)
	char				sSubMailIPAddr[ZLNET_MAX_DOMAIN_NAME_LEN];
	WORD				wMailPort;								// 邮件服务器端口
	WORD				wSubMailPort;
	WORD				wReserved;								// 保留
	char				sSenderAddr[ZLNET_MAX_MAIL_ADDR_LEN];	// 发送地址
	char				sUserName[ZLNET_MAX_MAIL_NAME_LEN];		// 用户名
	char				sUserPsw[ZLNET_MAX_MAIL_NAME_LEN];		// 用户密码
	char				sDestAddr[ZLNET_MAX_MAIL_ADDR_LEN];		// 目的地址
	char				sCcAddr[ZLNET_MAX_MAIL_ADDR_LEN];		// 抄送地址
	char				sBccAddr[ZLNET_MAX_MAIL_ADDR_LEN];		// 暗抄地址
	char				sSubject[ZLNET_MAX_MAIL_SUBJECT_LEN];	// 标题
	BYTE				bEnable;								// 使能0:false,	1:true
	BYTE				bSSLEnable;								// SSL使能
	WORD				wSendInterval;							// 发送时间间隔,[0,3600]秒
	BYTE				bAnonymous;								// 匿名选项[0,1], 0表示FALSE,1表示TRUE.
	BYTE				bAttachEnable;							// 附件使能[0,1], 0表示FALSE,1表示TRUE.
	char				reserved[154];
} ZLNET_MAIL_DEV_CFG;

// DNS服务器配置
typedef struct  
{
	char				szPrimaryIp[ZLNET_MAX_IPADDR_LEN];
	char				szSecondaryIp[ZLNET_MAX_IPADDR_LEN];
	char				reserved[256];
} ZLNET_DNS_DEV_CFG;

// 录象下载策略配置
typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;				// TRUE：高速下载，FALSE：普通下载
}ZLNET_DEV_DOWNLOAD_STRATEGY_CFG;

// 网络传输策略配置
typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;
	int					iStrategy;				// 0：画质优先，1：流畅性优先，2：自动
}ZLNET_DEV_TRANSFER_STRATEGY_CFG;

// 设置登入时的相关参数
typedef struct  
{
	int					nWaittime;				// 等待超时时间(毫秒为单位)，为0默认5000ms
	int					nConnectTime;			// 连接超时时间(毫秒为单位)，为0默认1500ms
	int					nConnectTryNum;			// 连接尝试次数，为0默认1次
	int					nSubConnectSpaceTime;	// 子连接之间的等待时间(毫秒为单位)，为0默认10ms
	int					nGetDevInfoTime;		// 获取设备信息超时时间，为0默认1000ms
	int					nConnectBufSize;		// 每个连接接收数据缓冲大小(字节为单位)，为0默认250*1024
	int					nGetConnInfoTime;		// 获取子连接信息超时时间(毫秒为单位)，为0默认1000ms
	BYTE				bReserved[20];			// 保留字段
} ZLNET_PARAM;

// 搜索类型，对应ZLNET_SearchDevices接口
typedef enum __ZLNET_SEARCH_MODE
{
	ZL_MODE = 0,	//智领模式 端口6060(默认)
	DH_MODE,		//大华模式 端口5050
}ZLNET_SEARCH_MODE;

// 对应ZLNET_SearchDevices接口
typedef struct 
{
	char				szIP[ZLNET_MAX_IPADDR_LEN];			// IP
	int					nPort;								// 端口
	int					nChn;								// 通道数量
	char				szSubmask[ZLNET_MAX_IPADDR_LEN];	// 子网掩码
	char				szGateway[ZLNET_MAX_IPADDR_LEN];	// 网关
	char				szMac[ZLNET_MACADDR_LEN];			// MAC地址
	char				szDeviceType[16];					// 设备类型
	char				szSerial[32];						// 序列号
	BYTE				bRegist;							// 是否反向注册信息
	BYTE				bIPCP;								// 是否IPCP设备
	char				reverse[10];						// 预留
} ZLNET_DEVICE_NET_INFO;

//-------------------------------报警属性---------------------------------

// 云台联动
typedef struct 
{
	int					iType;
	int					iValue;
} ZLNET_PTZ_LINK, *LPZLNET_PTZ_LINK;

// 报警联动结构体
typedef struct 
{
	/* 消息处理方式，可以同时多种处理方式，包括
	 * 0x00000001 - 报警上传
	 * 0x00000002 - 联动录象
	 * 0x00000004 - 云台联动
	 * 0x00000008 - 发送邮件
	 * 0x00000010 - 本地轮巡
	 * 0x00000020 - 本地提示
	 * 0x00000040 - 报警输出
	 * 0x00000080 - Ftp上传
	 * 0x00000100 - 蜂鸣
	 * 0x00000200 - 语音提示
	 * 0x00000400 - 抓图
	*/

	/* 当前报警所支持的处理方式，按位掩码表示 */
	DWORD				dwActionMask;

	/* 触发动作，按位掩码表示，具体动作所需要的参数在各自的配置中体现 */
	DWORD				dwActionFlag;
	
	/* 报警触发的输出通道，报警触发的输出，为1表示触发该输出 */ 
	BYTE				byRelAlarmOut[ZLNET_MAX_ALARMOUT_NUM];
	DWORD				dwDuration;				/* 报警持续时间 */

	/* 联动录象 */
	BYTE				byRecordChannel[ZLNET_MAX_VIDEO_IN_NUM]; /* 报警触发的录象通道，为1表示触发该通道 */
	DWORD				dwRecLatch;				/* 录象持续时间 */

	/* 抓图通道 */
	BYTE				bySnap[ZLNET_MAX_VIDEO_IN_NUM];
	/* 轮巡通道 */
	BYTE				byTour[ZLNET_MAX_VIDEO_IN_NUM];

	/* 云台联动 */
	ZLNET_PTZ_LINK			struPtzLink[ZLNET_MAX_VIDEO_IN_NUM];
	DWORD				dwEventLatch;			/* 联动开始延时时间，s为单位，范围是0~15，默认值是0 */
	/* 报警触发的无线输出通道，报警触发的输出，为1表示触发该输出 */ 
	BYTE				byRelWIAlarmOut[ZLNET_MAX_ALARMOUT_NUM];
	BYTE				bMessageToNet;
	BYTE                bMMSEn;                /*短信报警使能*/
	BYTE                bySnapshotTimes;       /*短信发送抓图张数 */
	BYTE				bMatrixEn;				/*!< 矩阵使能 */
	DWORD				dwMatrix;				/*!< 矩阵掩码 */			
	BYTE				bLog;					/*!< 日志使能，目前只有在WTN动态检测中使用 */
	BYTE				Res[3];
	DWORD				dwBeepLatch;			//蜂鸣延时
	BYTE				byReserved[94];   
} ZLNET_MSG_HANDLE;

// 外部报警
typedef struct
{
	BYTE				byAlarmType;			// 报警器类型，0：常闭，1：常开
	BYTE				byAlarmEn;				// 报警使能
	BYTE				byReserved[2];						
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE		struHandle;				// 处理方式
} ZLNET_ALARMIN_CFG, *LPZLNET_ALARMIN_CFG; 

// 动态检测报警
typedef struct 
{
	BYTE				byMotionEn;				// 动态检测报警使能
	BYTE				byReserved;
	WORD				wSenseLevel;			// 灵敏度
	WORD				wMotionRow;				// 动态检测区域的行数
	WORD				wMotionCol;				// 动态检测区域的列数
	BYTE				byDetected[ZLNET_MOTION_ROW][ZLNET_MOTION_COL]; // 检测区域，最多32*32块区域
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	//NSP
	ZLNET_MSG_HANDLE		struHandle;				//处理方式
} ZLNET_MOTION_DETECT_CFG;

// 视频丢失报警
typedef struct
{
	BYTE				byAlarmEn;				// 视频丢失报警使能
	BYTE				byReserved[3];
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	//NSP
	ZLNET_MSG_HANDLE		struHandle;				// 处理方式
} ZLNET_VIDEO_LOST_CFG;

// 图像遮挡报警
typedef struct
{
	BYTE				byBlindEnable;			// 使能
	BYTE				byBlindLevel;			// 灵敏度1-6
	BYTE				byReserved[2];
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	//NSP
	ZLNET_MSG_HANDLE		struHandle;				// 处理方式
} ZLNET_BLIND_CFG;

// 硬盘消息(内部报警)
typedef struct 
{
	BYTE				byNoDiskEn;				// 无硬盘时报警
	BYTE				byReserved_1[3];
	ZLNET_TSECT			stNDSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE		struNDHandle;			// 处理方式

	BYTE				byLowCapEn;				// 硬盘低容量时报警
	BYTE				byLowerLimit;			// 容量阀值，0-99
	BYTE				byReserved_2[2];
	ZLNET_TSECT			stLCSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE		struLCHandle;			// 处理方式

	BYTE				byDiskErrEn;			// 硬盘故障报警
	BYTE				bDiskNum;
	BYTE				byReserved_3[2];
	ZLNET_TSECT			stEDSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE		struEDHandle;			// 处理方式
} ZLNET_DISK_ALARM_CFG;

typedef struct
{
	BYTE				byEnable;
	BYTE				byReserved[3];
	ZLNET_MSG_HANDLE		struHandle;
} ZLNET_NETBROKEN_ALARM_CFG;

// 报警布防
typedef struct
{
	DWORD dwSize;
	ZLNET_ALARMIN_CFG 		struLocalAlmIn[ZLNET_MAX_ALARM_IN_NUM];
	ZLNET_ALARMIN_CFG		struNetAlmIn[ZLNET_MAX_ALARM_IN_NUM];
	ZLNET_MOTION_DETECT_CFG struMotion[ZLNET_MAX_VIDEO_IN_NUM];
	ZLNET_VIDEO_LOST_CFG	struVideoLost[ZLNET_MAX_VIDEO_IN_NUM];
	ZLNET_BLIND_CFG		struBlind[ZLNET_MAX_VIDEO_IN_NUM];
	ZLNET_DISK_ALARM_CFG	struDiskAlarm;
	ZLNET_NETBROKEN_ALARM_CFG	struNetBrokenAlarm;
} ZLNET_DEV_ALARM_SCHEDULE;

#define ZLNET_DECODER_OUT_SLOTS_MAX_NUM 		16
#define ZLNET_DECODER_IN_SLOTS_MAX_NUM 		16

// 报警解码器配置
typedef struct  
{
	DWORD				dwAddr;									// 报警解码器地址
	BOOL				bEnable;								// 报警解码器使能
	DWORD				dwOutSlots[ZLNET_DECODER_OUT_SLOTS_MAX_NUM];	// 现在只支持8个.
	int					nOutSlotNum;							// dwOutSlots数组有效元素个数.
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];
	ZLNET_MSG_HANDLE		struHandle[ZLNET_DECODER_IN_SLOTS_MAX_NUM];	// 现在只支持8个.
	int					nMsgHandleNum;							// stuHandle数组有效元素个数.
	BYTE				bReserved[120];
} ZLNET_ALARMDEC_CFG;

// 报警上传的配置
typedef struct  
{
	BYTE				byEnable;				// 上传使能
	BYTE				bReserverd;				// 保留
	WORD				wHostPort;				// 报警中心侦听端口
	char				sHostIPAddr[ZLNET_MAX_IPADDR_LEN];		// 报警中心IP

	int					nByTimeEn;				// 定时上传使能，可以用来向中心上传IP或域名等
	int					nUploadDay;				/* 设置上传日期	
													"Never = 0", "Everyday = 1", "Sunday = 2", 
													"Monday = 3", Tuesday = 4", "Wednesday = 5",
													"Thursday = 6", "Friday = 7", "Saturday = 8"*/	
	int					nUploadHour;			// 设置上传时间 ,[0~23]点
	
	DWORD				dwReserved[300]; 		// 保留待扩展。
} ZLNET_ALARMCENTER_UP_CFG;

// 全景切换报警配置
typedef struct __ZLNET_PANORAMA_SWITCH_CFG 
{
	BOOL				bEnable;				// 使能
	int					nReserved[5];			// 保留
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];
	ZLNET_MSG_HANDLE		struHandle;				// 报警联动
} ZLNET_PANORAMA_SWITCH_CFG;

typedef struct __ZLNET_ALARM_PANORAMA_SWITCH_CFG 
{
	int					nAlarmChnNum;			// 报警通道个数
	ZLNET_PANORAMA_SWITCH_CFG stuPanoramaSwitch[ZLNET_MAX_VIDEO_IN_NUM];
} ZLNET_ALARM_PANORAMA_SWITCH_CFG;

// 失去焦点报警配置
typedef struct __ZLNET_LOST_FOCUS_CFG
{
	BOOL				bEnable;				// 使能
	int					nReserved[5];			// 保留
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];
	ZLNET_MSG_HANDLE		struHandle;				// 报警联动
} ZLNET_LOST_FOCUS_CFG;

typedef struct __ZLNET_ALARM_LOST_FOCUS_CFG 
{
	int					nAlarmChnNum;			// 报警通道个数
	ZLNET_LOST_FOCUS_CFG stuLostFocus[ZLNET_MAX_VIDEO_IN_NUM];
} ZLNET_ALARM_LOST_FOCUS_CFG;

// IP冲突检测报警配置
typedef struct __ZLNET_ALARM_IP_COLLISION_CFG
{
	BOOL				bEnable;				// 使能
	ZLNET_MSG_HANDLE		struHandle;				// 报警联动
	int                 nReserved[300];			// 保留
} ZLNET_ALARM_IP_COLLISION_CFG;

//------------------------------多区域遮挡--------------------------------

// 遮挡信息
typedef struct __ZLNET_VIDEO_COVER_ATTR
{
	ZLNET_RECT				rcBlock;				// 覆盖的区域坐标
	int					nColor;					// 覆盖的颜色
	BYTE				bBlockType;				// 覆盖方式；0：黑块，1：马赛克
	BYTE				bEncode;				// 编码级遮挡；1：生效，0：不生效
	BYTE				bPriview;				// 预览遮挡； 1：生效，0：不生效
	char				reserved[29];			// 保留
} ZLNET_VIDEO_COVER_ATTR;

// 多区域遮挡配置
typedef struct __ZLNET_DEV_VIDEOCOVER_CFG 
{
	DWORD				dwSize;
	char				szChannelName[ZLNET_CHAN_NAME_LEN]; // 只读
	BYTE				bTotalBlocks;			// 支持的遮挡块数
	BYTE				bCoverCount;			// 已设置的遮挡块数
	ZLNET_VIDEO_COVER_ATTR	CoverBlock[ZLNET_MAX_VIDEO_COVER_NUM]; // 覆盖的区域	
	char				reserved[30];			// 保留
}ZLNET_DEV_VIDEOCOVER_CFG;

////////////////////////////////IPC产品支持////////////////////////////////

// 配置无线网络信息
typedef struct 
{
	int					nEnable;				// 无线使能
	char				szSSID[36];				// SSID
	int					nLinkMode;				// 连接模式；0：auto，1：adhoc，2：Infrastructure
	int					nEncryption;			// 加密；0：off，2：WEP64bit，3：WEP128bit, 4:WPA-PSK-TKIP, 5: WPA-PSK-CCMP
	int					nKeyType;				// 0：Hex，1：ASCII
    int					nKeyID;					// 序号
	union
	{
		char			szKeys[4][32];			// 四组密码
		char			szWPAKeys[128];			// nEncryption为4、5时使用，传128长度，不用结束符。
	};
	int					nKeyFlag;
	char				reserved[12];
} ZLNET_DEV_WLAN_INFO;

// 选择使用某个无线设备
typedef struct  
{
	char				szSSID[36];
	int					nLinkMode;				// 连接模式；0：adhoc，1：Infrastructure
	int 				nEncryption;			// 加密；0：off，2：WEP64bit，3：WEP128bit
	char				reserved[48];
} ZLNET_DEV_WLAN_DEVICE;

// 搜索到的无线设备列表
typedef struct  
{
	DWORD				dwSize;
	BYTE				bWlanDevCount;			// 搜索到的无线设备个数
	ZLNET_DEV_WLAN_DEVICE	lstWlanDev[ZLNET_MAX_WLANDEVICE_NUM];
	char				reserved[255];
} ZLNET_DEV_WLAN_DEVICE_LIST;

// 主动注册参数配置
typedef struct  
{
	char				szServerIp[32];			// 注册服务器IP
	int					nServerPort;			// 端口号
	char				reserved[64];
} ZLNET_DEV_SERVER_INFO;

typedef struct  
{
	DWORD				dwSize;
	BYTE				bServerNum;				// 支持的最大ip数
	ZLNET_DEV_SERVER_INFO	lstServer[ZLNET_MAX_REGISTER_SERVER_NUM];
	BYTE				bEnable;				// 使能
	char				szDeviceID[32];			// 设备id
	char				reserved[94];
} ZLNET_DEV_REGISTER_SERVER;

// 摄像头属性
typedef struct __ZLNET_DEV_CAMERA_INFO
{
	BYTE				bBrightnessEn;			// 亮度可调；1：可，0：不可
	BYTE				bContrastEn;			// 对比度可调
	BYTE				bColorEn;				// 色度可调
	BYTE				bGainEn;				// 增益可调
	BYTE				bSaturationEn;			// 饱和度可调
	BYTE				bBacklightEn;			// 背光补偿 0表示不支持背光补偿,1表示支持一级补偿（开,关），2表示支持两级补偿（关,高,低），3表示支持三级补偿（关,高,中,低）
	BYTE				bExposureEn;			// 曝光选择:
												// 0:表示不支持曝光控制
												// 1:表示只支持自动曝光
												// n:曝光的等级数(1表示支持自动曝光 2~n表示支持的手动控制曝光的等级)
	BYTE				bColorConvEn;			// 自动彩黑转换可调
	BYTE				bAttrEn;				// 属性选项；1：可，0：不可
	BYTE				bMirrorEn;				// 镜像；1：支持，0：不支持
    BYTE				bFlipEn;				// 翻转；1：支持，0：不支持
	BYTE				iWhiteBalance;			// 白平衡 2 支持情景模式， 1 支持白平衡 ，0 不支持
	BYTE				iSignalFormatMask;		// 信号格式掩码，按位从低到高位分别为：0-Inside(内部输入) 1- BT656 2-720p 3-1080i  4-1080p  5-1080sF
	BYTE				bRotate90;				//	90度旋转 0-不支持 1-支持
    BYTE				bLimitedAutoExposure;   // 是否支持带时间上下限的自动曝光
    BYTE				bCustomManualExposure;  // 是否支持用户自定义手动曝光时间
	BYTE				bRev[120];				// 保留
} ZLNET_DEV_CAMERA_INFO;

// 摄像头属性配置
typedef struct __ZLNET_DEV_CAMERA_CFG 
{
	DWORD				dwSize;
	BYTE				bExposure;				// 曝光模式；取值范围取决于设备能力集：0-自动曝光，1-曝光等级1，2-曝光等级2…n-1最大曝光等级数 n带时间上下限的自动曝光 n+1自定义时间手动曝光 (n==bExposureEn）
	BYTE				bBacklight;				// 背光补偿：背光补偿等级取值范围取决于设备能力集，0-关闭，1-背光补偿强度1，2-背光补偿强度2…n-最大背光补偿等级数 
	BYTE				bAutoColor2BW;			// 日/夜模式；2：开(黑白)，1：自动，0：关(彩色)
	BYTE				bMirror;				// 镜像；1：开，0：关
	BYTE				bFlip;					// 翻转；1：开，0：关
	BYTE				bLensEn;				// 自动光圈功能能力: 1：支持；0 ：不支持
	BYTE				bLensFunction;			// 自动光圈功能: 1:开启自动光圈；0: 关闭自动光圈
	BYTE				bWhiteBalance;			// 白平衡 0:Disabled,1:Auto 2:sunny 3:cloudy 4:home 5:office 6:night
	BYTE				bSignalFormat;			// 信号格式0-Inside(内部输入) 1- BT656 2-720p 3-1080i  4-1080p  5-1080sF
	BYTE				bRotate90;				// 0-不旋转，1-顺时针90°，2-逆时针90°
	BYTE                reserved[2];            // 保留
	float				ExposureValue1;			// 自动曝光时间下限或者手动曝光自定义时间,毫秒为单位，取值0.1ms~80ms
	float				ExposureValue2;			// 自动曝光时间上限,毫秒为单位，取值0.1ms~80ms
	
	char				bRev[108];				// 保留
} ZLNET_CAMERA_CFG;

#define ALARM_MAX_NAME 64
// (无线)红外报警配置
typedef struct
{
	BOOL				bEnable;				// 报警输入使能
	char				szAlarmName[ZLNET_MAX_ALARM_NAME];	// 报警输入名称
	int					nAlarmInPattern;		// 报警器输入波形
	int					nAlarmOutPattern;		// 报警输出波形
	char				szAlarmInAddress[ZLNET_MAX_ALARM_NAME];// 报警输入地址
	int					nSensorType;			// 外部设备传感器类型常开 or 常闭
	int					nDefendEfectTime;		// 布撤防延时时间，在此时间后该报警输入有效
	int					nDefendAreaType;		// 防区类型 
	int					nAlarmSmoothTime;		// 报警平滑时间，即在此时间内如果只有一个报警输入连续输入两次则忽略掉后面一次
	char				reserved[128];
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];
	ZLNET_MSG_HANDLE		struHandle;				// 处理方式
} ZLNET_INFRARED_INFO;

// 无线遥控器配置
typedef struct 
{
	BYTE				address[ALARM_MAX_NAME];// 遥控器地址
	BYTE				name[ALARM_MAX_NAME];	// 遥控器名称
	BYTE				reserved[32];			// 保留字段
} ZLNET_WI_CONFIG_ROBOT;

// 无线报警输出配置
typedef struct 
{
	BYTE				address[ALARM_MAX_NAME];// 报警输出地址
	BYTE				name[ALARM_MAX_NAME];	// 报警输出名称
	BYTE				reserved[32];			// 保留字段
} ZLNET_WI_CONFIG_ALARM_OUT;

typedef struct  
{
	DWORD				dwSize;
	BYTE				bAlarmInNum;			// 无线报警输入数
	BYTE				bAlarmOutNum;			// 无线报警输出数
	ZLNET_WI_CONFIG_ALARM_OUT AlarmOutAddr[16];	// 报警输出地址
	BYTE				bRobotNum;				// 遥控器个数
	ZLNET_WI_CONFIG_ROBOT RobotAddr[16];			// 遥控器地址
	ZLNET_INFRARED_INFO	InfraredAlarm[16];
	char				reserved[256];
} ZLNET_INFRARED_CFG;

// 新音频检测报警信息
typedef struct
{
	int					channel;				// 报警通道号
	int					alarmType;				// 报警类型；0：音频值过低，1：音频值过高
	unsigned int		volume;					// 音量值
	char				reserved[256];
} ZLNET_NEW_SOUND_ALARM_STATE;

typedef struct  
{
	int					channelcount;			// 报警的通道个数
	ZLNET_NEW_SOUND_ALARM_STATE SoundAlarmInfo[ZLNET_MAX_ALARM_IN_NUM];
} ZLNET_DEV_NEW_SOUND_ALARM_STATE;

// 抓图功能属性结构体
typedef struct 
{
	int					nChannelNum;			// 通道号
	DWORD				dwVideoStandardMask;	// 分辨率(按位)，具体查看枚举CAPTURE_SIZE						
	int					nFramesCount;			// Frequence[128]数组的有效长度
	char				Frames[128];			// 帧率(按数值)
												// -25：25秒1帧；-24：24秒1帧；-23：23秒1帧；-22：22秒1帧
												// ……
												// 0：无效；1：1秒1帧；2：1秒2帧；3：1秒3帧
												// 4：1秒4帧；5：1秒5帧；17：1秒17帧；18：1秒18帧
												// 19：1秒19帧；20：1秒20帧
												// ……
												// 25: 1秒25帧
	int					nSnapModeCount;			// SnapMode[16]数组的有效长度
	char				SnapMode[16];			// (按数值)0：定时触发抓图，1：手动触发抓图
	int					nPicFormatCount;		// Format[16]数组的有效长度
	char 				PictureFormat[16];		// (按数值)0：BMP格式，1：JPG格式
	int					nPicQualityCount;		// Quality[32]数组的有效长度
	char 				PictureQuality[32];		// 按数值
												// 100：图象质量100%；80:图象质量80%；60:图象质量60%
												// 50:图象质量50%；30:图象质量30%；10:图象质量10%
	char 				nReserved[128];			// 保留
} ZLNET_QUERY_SNAP_INFO;

typedef struct 
{
	int					nChannelCount;			// 通道个数
	ZLNET_QUERY_SNAP_INFO  stuSnap[ZLNET_MAX_CHANNUM];
} ZLNET_SNAP_ATTR_EN;


/* IP过滤功能配置 */
#define ZLNET_IPIFILTER_NUM			200			// IP

// IP信息
typedef struct 
{
	DWORD				dwIPNum;				// IP个数
	char				SZIP[ZLNET_IPIFILTER_NUM][ZLNET_MAX_IPADDR_LEN]; // IP
	char				byReserve[32];			// 保留
} ZLNET_IPIFILTER_INFO;

// IP过滤配置结构体
typedef struct
{
	DWORD				dwSize;
	DWORD				dwEnable;				// 使能
	DWORD				dwType;					// 当前名单类型：0：白名单 1：黑名单（设备只能使一种名单生效，或者是白名单或者是黑名单）
	ZLNET_IPIFILTER_INFO		BannedIP;				// 黑名单
	ZLNET_IPIFILTER_INFO		TrustIP;				// 白名单
	char				byReserve[256];			// 保留
} ZLNET_DEV_IPIFILTER_CFG;

/*语音对讲编码配置*/
typedef struct
{
	DWORD				dwSize;
	int					nCompression;			// 压缩格式，枚举值，相见ZLNET_TALK_CODING_TYPE，请根据设备支持的语音对讲类型设置压缩格式。
	int					nMode;					// 编码模式，枚举值，为0时表示该压缩格式不支持编码模式。
												// 根据压缩格式可以设置对应的编码格式，如
												// AMR详见EM_ARM_ENCODE_MODE
	char				byReserve[256];			// 保留
} ZLNET_DEC_TALK_ENCODE_CFG;

// 以下是mobile功能相关
// (事件触发多媒体彩信/短信发送)MMS配置结构体
typedef struct
{
	DWORD				dwSize;
	DWORD				dwEnable;				// 使能
	DWORD				dwReceiverNum;			// 短信接收者个数
	char				SZReceiver[ZLNET_MMS_RECEIVER_NUM][32];	// 短信接收者，一般为手机号码
    BYTE                byType;					// 短信信息类型 0:MMS；1:SMS
	char                SZTitle[32];			// 短信信息标题
	char				byReserve[223];			// 保留
} ZLNET_DEC_MMS_CFG;

// (短信激活无线连接配置)
typedef struct  
{
	DWORD				dwSize;
	DWORD				dwEnable;				// 使能
	DWORD				dwSenderNum;			// 短信发送者个数
	char				SZSender[ZLNET_MMS_SMSACTIVATION_NUM][32];	// 短信发送者，一般为手机号码
 	char				byReserve[256];			// 保留
}ZLNET_DEC_SMSACTIVATION_CFG;

// (拨号激活无线连接配置)
typedef struct  
{
	DWORD				dwSize;
	DWORD				dwEnable;				// 使能
	DWORD				dwCallerNum;			// 发送者个数
	char				SZCaller[ZLNET_MMS_DIALINACTIVATION_NUM][32];	// 发送者, 一般为手机号码
 	char				byReserve[256];			// 保留
}ZLNET_DEC_DIALINACTIVATION_CFG;
// 以上是mobile功能相关


// 无线网络信号强度结构体
typedef struct
{
	DWORD				dwSize;
	DWORD				dwTDSCDMA;				// TD-SCDMA强度，范围：0－100
	DWORD				dwWCDMA;				// WCDMA强度，范围：0－100
	DWORD				dwCDMA1x;				// CDMA1x强度，范围：0－100
	DWORD				dwEDGE;					// EDGE强度，范围：0－100
	DWORD				dwEVDO;					// EVDO强度，范围：0－100
	int					nCurrentType;			// 当前类型
												// 0	设备不支持这一项
												// 1    TD_SCDMA
												// 2	WCDMA
												// 3	CDMA_1x
												// 4	EDGE
												// 5	EVDO
	char				byReserve[252];			// 保留
} ZLNET_DEV_WIRELESS_RSS_INFO;

typedef struct _ZLNET_DEC_SIP_CFG
{
	BOOL	bUnregOnBoot;						//Unregister on Reboot
	char	szAccoutName[64];					//Account Name
	char	szSIPServer[128];					//SIP Server
	char	szOutBoundProxy[128];				//Outbound Proxy
	DWORD	dwSIPUsrID;							//SIP User ID
	DWORD	dwAuthID;							//Authenticate ID
	char	szAuthPsw[64];						//Authenticate Password
	char	szSTUNServer[128];					//STUN Server
	DWORD	dwRegExp;							//Registration Expiration
	DWORD	dwLocalSIPPort;						//Local SIP Port
	DWORD	dwLocalRTPPort;						//Local RTP Port
	BYTE	bReserved[1024];					//reserved
} ZLNET_DEC_SIP_CFG;

typedef struct _ZLNET_DEV_SIP_STATE
{
	BOOL	bOnline;							//TRUE:online, FALSE:offline
	BYTE	bReserved[64];						//保留
}ZLNET_DEV_SIP_STATE;

/***************************** 云台预制点配置 ***********************************/
typedef struct _ZLNET_POINTEANBLE
{
	BYTE				bPoint;	//预制点的有效范围闭区间[1,80]，无效设置为0。
	BYTE				bEnable;	//是否有效,0无效，1有效
	BYTE				bReserved[2];
} ZLNET_POINTEANBLE;

typedef struct _ZL_POINTCFG
{
	char				szIP[ZLNET_MAX_IPADDR_LEN];// ip
	int					nPort;					// 端口	
	ZLNET_POINTEANBLE			stuPointEnable[80];		// 预制点使能
	BYTE				bReserved[256];
}ZLNET_POINTCFG;

typedef struct _ZLNET_DEC_POINT_CFG
{
	int					nSupportNum;			// 只读参数，设置的时候需要返回给sdk，表示支持的预制点数
	ZLNET_POINTCFG			stuPointCfg[16];		// 二维下标表示通道号。要设置的点数值放在前nSupportNum个下标里面。
	BYTE				bReserved[256];			// 保留
}ZLNET_DEC_POINT_CFG;
////////////////////////////////车载DVR支持////////////////////////////////

// GPS信息(车载设备)
typedef struct _ZLNET_GPS_Info
{
    ZLNET_TIME			revTime;				// 定位时间
	char				DvrSerial[50];			// 设备序列号
    double				longitude;				// 经度(单位是百万分之度，范围0-360度)
    double				latidude;				// 纬度(单位是百万分之度，范围0-180度)
    double				height;					// 高度(米)
    double				angle;					// 方向角(正北方向为原点，顺时针为正)
    double				speed;					// 速度(单位是海里，speed/1000*1.852公里/小时)
    WORD				starCount;				// 定位星数
    BOOL				antennaState;			// 天线状态(true 好，false 坏)
    BOOL				orientationState;		// 定位状态(true 定位，false 不定位)
} ZLNET_GPS_Info,*LPZLNET_GPS_Info;

// 抓图参数结构体
typedef struct _ZLNET_snap_param
{
	unsigned int		Channel;				// 抓图的通道
	unsigned int		Quality;				// 画质；1~6
	unsigned int		ImageSize;				// 画面大小；0：QCIF，1：CIF，2：D1
	unsigned int		mode;					// 抓图模式；0：表示请求一帧，1：表示定时发送请求，2：表示连续请求
	unsigned int		InterSnap;				// 时间单位秒；若mode=1表示定时发送请求时，此时间有效
	unsigned int		CmdSerial;				// 请求序列号
	unsigned int		Reserved[4];
} ZLNET_SNAP_PARAMS, *LPZLNET_SNAP_PARAMS;

// 抓图功能配置
typedef struct 
{
	DWORD				dwSize;
	BYTE				bTimingEnable;				// 定时抓图开关(报警抓图开关在各报警联动配置中体现)
	BYTE                bReserved;
	short	            PicTimeInterval;			// 定时抓图时间间隔，单位为秒,目前设备支持最大的抓图时间间隔为30分钟                           
	ZLNET_VIDEOENC_OPT		struSnapEnc[ZLNET_SNAP_TYP_NUM]; // 抓图编码配置，现支持其中的分辨率、画质、帧率设置，帧率在这里是负数，表示一秒抓图的次数。
} ZLNET_SNAP_DEV_CFG;

//////////////////////////////////ATM支持//////////////////////////////////

typedef struct
{
	int					Offset;					// 标志位的位偏移
	int					Length;					// 标志位的长度
	char				Key[16];				// 标志位的值
} ZLNET_SNIFFER_FRAMEID;

typedef struct 
{
	int					Offset;					// 标志位的位偏移
	int					Offset2;				// 目前没有应用
	int					Length;					// 标志位的长度
	int					Length2;				// 目前没有应用
	char				KeyTitle[24];			// 标题的值
} ZLNET_SNIFFER_CONTENT;

// 网络抓包配置
typedef struct 
{
	ZLNET_SNIFFER_FRAMEID	snifferFrameId;			// 每个FRAME ID 选项
	ZLNET_SNIFFER_CONTENT	snifferContent[ZLNET_SNIFFER_CONTENT_NUM];	// 每个FRAME对应的4个抓包内容
} ZLNET_SNIFFER_FRAME;

// 每组抓包对应的配置结构
typedef struct
{
	char				SnifferSrcIP[ZLNET_MAX_IPADDR_LEN];	// 抓包源地址		
	int					SnifferSrcPort;			// 抓包源端口
	char				SnifferDestIP[ZLNET_MAX_IPADDR_LEN];	// 抓包目标地址
	int					SnifferDestPort;		// 抓包目标端口
	char				reserved[28];			// 保留字段
	ZLNET_SNIFFER_FRAME	snifferFrame[ZLNET_SNIFFER_FRAMEID_NUM];	// 6个FRAME 选项
	int					displayPosition;		// 显示位置
	int					recdChannelMask;		// 通道掩码
} ZLNET_ATM_SNIFFER_CFG;

typedef struct  
{
	DWORD				dwSize;
	ZLNET_ATM_SNIFFER_CFG	SnifferConfig[4];
	char				reserved[256];			// 保留字段
} ZLNET_SNIFFER_CFG;

typedef ZLNET_SNIFFER_FRAMEID ZLNET_SNIFFER_FRAMEID_EX;
typedef ZLNET_SNIFFER_CONTENT ZLNET_SNIFFER_CONTENT_EX;

// 网络抓包配置
typedef struct  
{
	ZLNET_SNIFFER_FRAMEID	snifferFrameId;								// 每个FRAME ID 选项
	ZLNET_SNIFFER_CONTENT	snifferContent[ZLNET_SNIFFER_CONTENT_NUM_EX];	// 每个FRAME对应的8个抓包内容	
} ZLNET_SNIFFER_FRAME_EX;

// 每组抓包对应的配置结构
typedef struct
{
	char				SnifferSrcIP[ZLNET_MAX_IPADDR_LEN];					// 抓包源地址		
	int					SnifferSrcPort;										// 抓包源端口
	char				SnifferDestIP[ZLNET_MAX_IPADDR_LEN];					// 抓包目标地址
	int					SnifferDestPort;									// 抓包目标端口
	ZLNET_SNIFFER_FRAME_EX	snifferFrame[ZLNET_SNIFFER_FRAMEID_NUM];				// 6个FRAME 选项
	int					displayPosition;									// 显示位置
	int					recdChannelMask;									// 通道掩码
	BOOL				bDateScopeEnable;									// 数据来源使能
	BOOL				bProtocolEnable;									// 协议使能
	char				szProtocolName[ZLNET_SNIFFER_PROTOCOL_SIZE];			// 协议名字
	int					nSnifferMode;										// 抓包方式，0:net,1:232.
	char				reserved[256];
} ZLNET_ATM_SNIFFER_CFG_EX;

// Atm交易类型查询返回结构体
#define ZLNET_ATM_MAX_TRADE_TYPE_NAME	64
#define ZLNET_ATM_MAX_TRADE_NUM		1024

typedef struct __ZLNET_ATM_QUERY_TRADE   
{
	int					nTradeTypeNum;										// 实际交易类型数量
	int					nExceptionTypeNum;									// 实际异常事件数量
	char				szSupportTradeType[ZLNET_ATM_MAX_TRADE_NUM][ZLNET_ATM_MAX_TRADE_TYPE_NAME];    // 交易事件名数组
	char				szSupportExceptionType[ZLNET_ATM_MAX_TRADE_NUM][ZLNET_ATM_MAX_TRADE_TYPE_NAME];// 异常事件名数组
} ZLNET_ATM_QUERY_TRADE, *LPZLNET_ATM_QUERY_TRADE;

/////////////////////////////////解码器支持/////////////////////////////////

// 解码器信息
typedef struct __ZLNET_DEV_DECODER_INFO 
{
	char			szDecType[64];			// 类型
	int				nMonitorNum;			// TV个数
	int				nEncoderNum;			// 解码通道个数
	BYTE			szSplitMode[16];		// 支持的TV画面分割数，以数组形式表示，0为结尾
	BYTE            bMonitorEnable[16];		// 各TV使能
	char			reserved[64];
} ZLNET_DEV_DECODER_INFO, *LPZLNET_DEV_DECODER_INFO;

// 连接的编码器信息
typedef struct __ZLNET_DEV_ENCODER_INFO 
{
	char			szDevIp[ZLNET_MAX_IPADDR_LEN];			// 前端DVR的IP地址
	WORD			wDevPort;							// 前端DVR的端口号
	BYTE			bDevChnEnable;                      // 解码通道使能
	BYTE			byEncoderID;						// 对应解码通道号
	char			szDevUser[ZLNET_USER_NAME_LENGTH_EX];	// 用户名
	char			szDevPwd[ZLNET_USER_PSW_LENGTH_EX];	// 密码
	int				nDevChannel;						// 通道号
	int				nStreamType;						// 码流类型，0：主码流；1：子码流; 2:snap
	BYTE			byConnType;							// 0：TCP；1：UDP；2：组播
	BYTE			byWorkMode;							// 0：直连；1：转发
	WORD			wListenPort;						// 指示侦听服务的端口，转发时有效
	DWORD			dwProtoType;						// 协议类型,
														// 0:兼容以前
														// 1:智诺二代协议
														// 2:智诺系统集成协议
														// 3:智诺DSS协议
														// 4:智诺rtsp协议
	char			szDevName[64];						// 前端设备名称
	BYTE            byVideoInType;                      // 该解码通道当前视频源类型:0-标清(SD),1-高清(HD),注:设备支持高清通道才有效		
	char			szDevIpEx[ZLNET_MAX_IPADDR_OR_DOMAIN_LEN];// szDevIp扩展，前端DVR的IP地址(可以输入域名)
	BYTE            bySnapMode;                         //抓图模式(nStreamType==2时有效) 0：表示请求一帧,1：表示定时发送请求
	BYTE            byManuFactory;						//目标设备的生产厂商,0:Private(智诺私有)
	BYTE            byDeviceType;                       //目标设备的设备类型,0:IPC
	char			reserved[48];
} ZLNET_DEV_ENCODER_INFO, *LPZLNET_DEV_ENCODER_INFO;

// TV参数信息
typedef struct __ZLNET_DEV_DECODER_TV 
{
	int				nID;								// TV号
	BOOL			bEnable;							// 使能，开启或关闭
	int				nSplitType;							// 画面分割数
	ZLNET_DEV_ENCODER_INFO stuDevInfo[16];					// 各画面编码器信息
	char			reserved[16];
} ZLNET_DEV_DECODER_TV, *LPZLNET_DEV_DECODER_TV;

// 解码器画面组合信息
typedef struct __ZLNET_DEC_COMBIN_INFO
{
	int				nCombinID;							// 组合ID
	int             nSplitType;							// 画面分割数 
	BYTE            bDisChn[16];						// 显示通道
	char			reserved[16];
} ZLNET_DEC_COMBIN_INFO, *LPZLNET_DEC_COMBIN_INFO;

// 解码器轮巡信息
#define ZLNET_DEC_COMBIN_NUM 			32						// 轮巡组合个数
typedef struct __ZLNET_DEC_TOUR_COMBIN 
{
	int				nTourTime;							// 轮巡间隔(秒)
	int				nCombinNum;							// 组合个数
	BYTE			bCombinID[ZLNET_DEC_COMBIN_NUM];			// 组合表
	char			reserved1[32];
	BYTE			bCombinState[ZLNET_DEC_COMBIN_NUM];		// 组合项的使能状态，0：关；1：开
	char			reserved2[32];
} ZLNET_DEC_TOUR_COMBIN, *LPZLNET_DEC_TOUR_COMBIN;

// 解码器回放类型
typedef enum __ZLNET_DEC_PLAYBACK_MODE
{
	ZL_Dec_By_Device_File = 0,								// 前端设备－按文件方式
	ZL_Dec_By_Device_Time,									// 前端设备－按时间方式
} ZLNET_DEC_PLAYBACK_MODE;

// 解码器回放控制类型
typedef enum __ZLNET_DEC_CTRL_PLAYBACK_TYPE
{
	ZL_Dec_Playback_Seek = 0,								// 拖动
	ZL_Dec_Playback_Play,									// 播放
	ZL_Dec_Playback_Pause,									// 暂停
	ZL_Dec_Playback_Stop,									// 停止
} ZLNET_DEC_CTRL_PLAYBACK_TYPE;

//轮巡控制类型
typedef enum __ZLNET_DEC_CTRL_TOUR_TYPE
{
	ZL_Dec_Tour_Stop = 0,									// 停止
	ZL_Dec_Tour_Start,										// 开始
	ZL_Dec_Tour_Pause,										// 暂停
	ZL_Dec_Tour_Resume,									// 恢复
} ZLNET_DEC_CTRL_TOUR_TYPE;

// 按文件回放前端设备条件
typedef struct __ZLNET_DEC_PLAYBACK_FILE_PARAM 
{
	char			szDevIp[ZLNET_MAX_IPADDR_LEN];			// 前端DVR的IP地址
	WORD			wDevPort;							// 前端DVR的端口号
	BYTE			bDevChnEnable;                      // 解码通道使能
	BYTE			byEncoderID;						// 对应解码通道号
	char			szDevUser[ZLNET_USER_NAME_LENGTH_EX];	// 用户名
	char			szDevPwd[ZLNET_USER_PSW_LENGTH_EX];	// 密码
	ZLNET_RECORDFILE_INFO stuRecordInfo;					// 录像文件信息
	char			reserved[12];
} ZLNET_DEC_PLAYBACK_FILE_PARAM, *LPZLNET_DEC_PLAYBACK_FILE_PARAM;

// 按时间回放前端设备条件
typedef struct __ZLNET_DEC_PLAYBACK_TIME_PARAM 
{
	char			szDevIp[ZLNET_MAX_IPADDR_LEN];			// 前端DVR的IP地址
	WORD			wDevPort;							// 前端DVR的端口号
	BYTE			bDevChnEnable;                      // 解码通道使能
	BYTE			byEncoderID;						// 对应解码通道号
	char			szDevUser[ZLNET_USER_NAME_LENGTH_EX];	// 用户名
	char			szDevPwd[ZLNET_USER_PSW_LENGTH_EX];	// 密码
	int				nChannelID;
	ZLNET_TIME		startTime;
	ZLNET_TIME		endTime;
	char			reserved[12];
} ZLNET_DEC_PLAYBACK_TIME_PARAM, *LPZLNET_DEC_PLAYBACK_TIME_PARAM;

// 当前解码通道状态信息(包括通道状态，解码流信息等)
typedef struct __ZLNET_DEV_DECCHANNEL_STATE
{
	BYTE			byEncoderID;						// 对应解码通道号
	BYTE            byChnState;                         // 当前解码通道正在操作状态:0－空闲，1－实时监视，2－回放 3 - 轮巡
	BYTE			byFrame;                            // 当前数据帧率
	BYTE            byReserved;                         // 保留
	int				nChannelFLux;						// 解码通道数据总量
	int             nDecodeFlux;						// 解码数据量
	char            szResolution[16];                   // 当前数据分辨率
	char			reserved[256];
} ZLNET_DEV_DECCHANNEL_STATE, *LPZLNET_DEV_DECCHANNEL_STATE;

// 设备TV输出参数信息
typedef struct __ZL_DEV_VIDEOOUT_INFO
{
	DWORD				dwVideoStandardMask;			// NSP,视频制式掩码，按位表示设备能够支持的视频制式(暂不支持)
	int					nVideoStandard;                 // NSP,当前的制式(暂不支持，请使用DHDEV_SYSTEM_ATTR_CFG的byVideoStandard对制式读取和配置)
	DWORD				dwImageSizeMask;				// 分辨率掩码，按位表示设备能够支持的分辨率
	int                 nImageSize;                     // 当前的分辨率
	char				reserved[256];
}ZLNET_DEV_VIDEOOUT_INFO, *LPZLNET_DEV_VIDEOOUT_INFO;

// 调节TV输出
typedef struct __ZLNET_DEV_TVADJUST_CFG
{
	int					nTop;							// 上测边距（0－100）
	int					nBotton;						// 下测边距（0－100）
	int					nLeft;							// 左测边距（0－100）
	int                 nRight;							// 右测边距（0－100）
	int					reserved[32];
}ZLNET_DEV_TVADJUST_CFG, *LPZLNET_DEV_TVADJUST_CFG;

// 解码轮巡配置
typedef struct __ZLNET_DEV_DECODER_TOUR_SINGLE_CFG
{
	char		szIP[128];								// 前端设备ip.例如"10.7.5.21". 保留对域名的支持.需要以'\0'结束.
	int			nPort;									// 前端设备端口.(0, 65535).
	int			nPlayChn;								// 请求前端设备通道[1, 16].
	int			nPlayType;								// 请求前端码流类型, 0:主码流; 1:辅码流.
	char		szUserName[32];							// 登陆前端设备的用户名,需要以'\0'结束.
	char		szPassword[32];							// 登陆前端设备的密码,需要以'\0'结束.
	int			nInterval;								// 轮巡间隔时间[10, 120],单位秒.
	BYTE		bReserved[64];							// 保留字节,留待扩展.
}ZLNET_DEV_DECODER_TOUR_SINGLE_CFG;

typedef struct __ZLNET_DECODER_TOUR_CFG_DEV
{
	int								nCfgNum;			// 配置结构体数目. 现在最大支持32个.具体支持数目可以通过能力查询.
	ZLNET_DEV_DECODER_TOUR_SINGLE_CFG	tourCfg[64];		// 轮询配置数组,有效结构体个数由成员"nCfgNum"指定. 保留32个留待扩展.
	BYTE							bReserved[256];		// 保留字节,留待扩展.
}ZLNET_DECODER_TOUR_CFG_DEV;
/////////////////////////////////特殊版本/////////////////////////////////

// 触发设备抓图，叠加卡号信息
typedef struct __ZLNET_SNAP_COMMANDINFO 
{
	char				szCardInfo[16];			// 卡号信息
	char				reserved[64];			// 保留
} ZLNET_SNAP_COMMANDINFO, LPZLNET_SNAP_COMMANDINFO;

typedef struct
{
	int					nChannelNum;			// 通道号
	char				szUseType[32];			// 通道用途
	DWORD				dwStreamSize;			// 流量大小(单位：kb/s)
	char				reserved[32];			// 保留
} ZLNET_DEV_USE_CHANNEL_STATE;

typedef struct 
{
	char				szUserName[32];			// 用户名
	char				szUserGroup[32];		// 用户组
	ZLNET_TIME			time;					// 登入时间
	int					nOpenedChannelNum;		// 开启的通道个数
	ZLNET_DEV_USE_CHANNEL_STATE	channelInfo[ZLNET_MAX_CHANNUM];
	char				reserved[64];
} ZLNET_DEV_USER_NET_INFO;

// 网络运行状态信息
typedef	struct 
{
	int					nUserCount;				// 用户数量
	ZLNET_DEV_USER_NET_INFO	stuUserInfo[32];
	char				reserved[256];
}ZLNET_DEV_TOTAL_NET_STATE;

// 图象水印配置
typedef struct __ZLNET_WATERMAKE_CFG_DEV 
{
	DWORD				dwSize;
	int					nEnable;				// 使能
	int					nStream;				// 码流(1～n)0-所有码流
	int					nKey;					// 数据类型(1-文字，2-图片)
	char				szLetterData[ZLNET_MAX_WATERMAKE_LETTER];	//	文字
	char				szData[ZLNET_MAX_WATERMAKE_DATA]; // 图片数据
	BYTE				bReserved[512];			// 保留
} ZLNET_WATERMAKE_CFG_DEV;

// 存储位置设置结构体，每通道独立设置,每通道可以选择各种存储类型, 目前包括本地, 可移动, 远程存储.
typedef struct 
{
	DWORD				dwSize;
	DWORD				dwLocalMask;			// 本地存储掩码；按位表示：
												// 第一位：系统预录，第二位：定时录像，第三位：动检录像，
												// 第四位：报警录像，第五位：卡号录像，第六位：手动录像
	DWORD				dwMobileMask;			// 可移动存储掩码 存储掩码如本地存储掩码
	int					RemoteType;				// 远程存储类型 0: Ftp  1: Smb 
	DWORD				dwRemoteMask;			// 远程存储掩码 存储掩码如本地存储掩码
	DWORD				dwRemoteSecondSelLocal;	// 远程异常时本地存储掩码
	DWORD				dwRemoteSecondSelMobile;// 远程异常时可移动存储掩码
	char				SubRemotePath[ZLNET_MAX_PATH_STOR]; // 远程目录, 其中长度为240
	DWORD				dwFunctionMask;			//功能屏蔽位，按位表示，bit0 = 1:屏蔽抓图事件触发存储位置功能
	
	char				reserved[124];
} ZLNET_STORAGE_STATION_CFG;

#define ZLNET_MAX_ALARM_DECODER_NUM 16
typedef struct  
{
	DWORD				dwAlarmDecoder;			// 现在最多支持8个报警输入口，留8位待以后扩展
	BYTE				bDecoderIndex;			// 表示第几个报警解码器
	BYTE				bReserved[3];
} ZLNET_ALARM_DECODER;

// 报警解码器报警
typedef struct
{
	int					nAlarmDecoderNum;
	ZLNET_ALARM_DECODER		stuAlarmDecoder[ZLNET_MAX_ALARM_DECODER_NUM];
	BYTE				bReserved[32];
} ZLNET_ALARM_DECODER_ALARM_DEV;

//DSP报警
typedef struct  
{
	BOOL				bError;			//0,DSP正常 1,DSP异常
	DWORD				dwErrorMask;	//按位表示，非0表示有此错误，0表示没有。(目前每次报警只有一位有效)
										//bit		DSP报警
										//1			DSP加载失败 
										//2			DSP错误
										//3			制式不对 
										//4			分辨率不支持
										//5			数据格式不支持
										//6			找不到I帧
	DWORD               dwDecChnnelMask;//按位表示，报警的解码通道号，dwErrorMask为DSP错误，制式不对，分辨率不支持，数据格式不支持时此项有效
	
	BYTE				bReserved[28];
}ZLNET_DSP_ALARM;

// 光纤编码能力报警
typedef struct  
{
	int		nFDDINum;
	BYTE	bAlarm[256];
} ZLNET_ALARM_FDDI_ALARM;

// 新音频检测报警配置
typedef struct
{
	BOOL				bEnable;				// 报警输入使能
	int					Volume_min;				// 音量的最小值
	int					Volume_max;				// 音量的最大值
	char				reserved[128];	
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	
	ZLNET_MSG_HANDLE		struHandle;				// 处理方式
} ZLNET_AUDIO_DETECT_INFO;

typedef struct  
{
	DWORD				dwSize;
	int					AlarmNum;
	ZLNET_AUDIO_DETECT_INFO AudioDetectAlarm[ZLNET_MAX_AUDIO_IN_NUM];
	char				reserved[256];
} ZLNET_AUDIO_DETECT_CFG;

typedef struct
{
	BOOL				bTourEnable;			// 轮巡使能
	int					nTourPeriod;			// 轮巡间隔，单位秒, 5-300 
	DWORD				dwChannelMask;			// 轮巡的通道，掩码形式表示
	char				reserved[64];
}ZLNET_VIDEOGROUP_CFG;

// 本机矩阵控制策略配置
typedef struct
{
	DWORD				dwSize;
	int					nMatrixNum;				// 矩阵个数(注：不允许修改)
	ZLNET_VIDEOGROUP_CFG	struVideoGroup[ZLNET_MATRIX_MAXOUT];
	char				reserved[32];
} ZLNET_DEV_VIDEO_MATRIX_CFG;   

// WEB路径配置
typedef struct 
{
	DWORD				dwSize;
	BOOL				bSnapEnable;			// 是否抓图
	int					iSnapInterval;			// 抓图周期
	char				szHostIp[ZLNET_MAX_IPADDR_LEN]; // HTTP主机IP
	WORD				wHostPort;
	int					iMsgInterval;			// 状态消息发送间隔
	char				szUrlState[ZLNET_MAX_URL_LEN];	// 状态消息上传URL
	char				szUrlImage[ZLNET_MAX_URL_LEN];	// 图片上传Url
	char				szDevId[ZLNET_MAX_DEV_ID_LEN];	// 机器的web编号
	BYTE				byReserved[2];
} ZLNET_DEV_URL_CFG;

// OEM查询
typedef struct  
{
	char				szVendor[ZLNET_MAX_STRING_LEN];
	char				szType[ZLNET_MAX_STRING_LEN];
	char				reserved[128];
} ZLNET_DEV_OEM_INFO;


//视频OSD叠加配置
typedef struct 
{ 
	DWORD	rgbaFrontground;		// 物件的前景；按字节表示，分别为红、绿、蓝和透明度
	DWORD	rgbaBackground;			// 物件的背景；按字节表示，分别为红、绿、蓝和透明度	
	RECT	rcRelativePos;			// 位置,物件边距与整长的比例*8191	
	BOOL	bPreviewBlend;			// 预览叠加使能	
	BOOL	bEncodeBlend;			// 编码叠加使能
	BYTE    bReserved[4];           // 保留
} ZLNET_DVR_VIDEO_WIDGET;

typedef struct 
{
	ZLNET_DVR_VIDEO_WIDGET	StOSD_POS; 								// OSD叠加的位置和背景色
	char 				SzOSD_Name[ZLNET_VIDEO_OSD_NAME_NUM]; 		// OSD叠加的名称
}ZLNET_DVR_VIDEOITEM;
 
// 每个通道的OSD信息
typedef struct 
{
	DWORD 				dwSize;
	ZLNET_DVR_VIDEOITEM 	StOSDTitleOpt [ZLNET_VIDEO_CUSTOM_OSD_NUM]; 	// 每个通道的OSD信息
	BYTE    			bReserved[16];                  		  // 保留
} ZLNET_DVR_VIDEOOSD_CFG;

// 配置CDMA/GPRS网络信息
// 时间段结构															    
typedef struct 
{
	BYTE				bEnable;				  // 时间段使能，1表示该时间段有效，0表示该时间段无效。
	BYTE				bBeginHour;
	BYTE				bBeginMin;
	BYTE				bBeginSec;
	BYTE				bEndHour;
	BYTE				bEndMin;
	BYTE				bEndSec;
	BYTE    			bReserved;                //保留
} ZLNET_3G_TIMESECT, *LPZLNET_3G_TIMESECT;

typedef struct 
{
	DWORD 				dwSize;
	BOOL				bEnable;					// 无线模块使能标志
	DWORD               dwTypeMask;                 // 设备支持网络类型掩码;按位表示,第一位;自动选择;
													// 第二位：TD-SCDMA网络；第三位：WCDMA网络;
													// 第四位：CDMA 1.x网络;第五位：CDMA2000网络;第六位：GPRS网络;
													// 第七位：EVDO网络;第八位：WIFI
	DWORD               dwNetType;                  // 当前的无线网络类型，为ZLNET_GPRSCDMA_NETWORK_TYPE值
	char				szAPN[128];					// 接入点名称
	char				szDialNum[128];				// 拨号号码
	char				szUserName[128];			// 拨号用户名
	char				szPWD[128];					// 拨号密码
	
	/* 下面是设备的只读部分 */
	BOOL				iAccessStat;				// 无线网络注册状态
    char				szDevIP[16];				// 前端设备拨号IP，字符串, 包括'\0'结束符共16byte  
	char				szSubNetMask [16];			// 前端设备拨号子网掩码，字符串, 包括'\0'结束符共16byte 
	char				szGateWay[16];				// 前端设备拨号网关，字符串, 包括'\0'结束符共16byte 
	/* 上面是设备的只读部分 */
	int                 iKeepLive;					// 保活时间
	ZLNET_3G_TIMESECT		stSect[ZLNET_N_WEEKS][ZLNET_N_TSECT];// 3G拨号时间段，有效时间段之内，开启拨号；有效时间段之外，关闭拨号。
	BYTE                byActivate;                  //是否需要被语音或短信激活
	char				Reserved[171];				// 保留字节，用于扩展
} ZLNET_CDMAGPRS_CFG_DEV;

// 录像打包长度配置
typedef struct  
{
	DWORD 				dwSize;
	int					nType;						// 0:按时间，1：按大小
	int					nValue;						// nType = 0时:单位分钟，nType = 1时:单位KB
	char				Reserved[128];				// 保留字节，用于扩展
} ZLNET_RECORD_PACKET_CFG_DEV;

// (定向)主动注册服务器信息
typedef struct __ZLNET_DEV_AUTOREGISTER_INFO 
{
	LONG			lConnectionID;						// 连接ID
	char			szServerIp[ZLNET_MAX_IPADDR_LEN];		// 主动注册服务器的IP
	int				nPort;								// 主动注册服务器端口0- 65535
	int             nState;                             // 服务器的状态：0－注册失败；1-注册成功; 2-连接失败
	char			reserved[16];
} ZLNET_DEV_AUTOREGISTER_INFO;

typedef struct __ZLNET_DEV_SERVER_AUTOREGISTER 
{
	DWORD					dwSize;
	int						nRegisterSeverCount;											// 主动注册服务器个数
	ZLNET_DEV_AUTOREGISTER_INFO	stuDevRegisterSeverInfo[ZLNET_CONTROL_AUTO_REGISTER_NUM];			// 各主动注册服务器信息
	char					reserved[256];
} ZLNET_DEV_SERVER_AUTOREGISTER, *LPZLNET_DEV_SERVER_AUTOREGISTER;

// 附件刻录附件上传
typedef struct
{
	DWORD				dwSize;		
	char				szSourFile[ZLNET_MAX_PATH_STOR];	// 源文件路径
	int					nFileSize;					// 源文件大小，如果小于等于0，sdk自行计算文件大小.
	char				szBurnFile[ZLNET_MAX_PATH_STOR];	// 刻录后的文件名
	BYTE				bReserved[64];
} ZLNET_DEV_BURNFILE_TRANS_CFG;

// 郑州威科姆EC_U视频数据叠加使能配置
typedef struct 
{
	BOOL				bEnable;					// 使能
	int					nPort;						// 端口
	BYTE				bReserved[64];
} ZLNET_OSD_ENABLE_CFG_DEV;

// 车载相关配置:北京公交使用配置
typedef struct	
{
	BOOL				bAutoBootEnable;				//自动开机使能
	DWORD				dwAutoBootTime;					//每天自动开机时间点, 单位秒,从0算起.[0,82800]
	BOOL				bAutoShutDownEnable;			//自动关机使能
	DWORD				dwAutoShutDownTime;				//每天自动关机时间点, 单位秒,从0算起.[0,82800]
	DWORD				dwShutDownDelayTime;			//延时关机时间,单位秒.
	BYTE				bEventNoDisk;					//1,(Ignore:忽略); 2,(Reboot:重起系统)
	BYTE				bReserved[511];					//reserved byte.
} ZLNET_ABOUT_VEHICLE_CFG_DEV;

// atm:查询叠加相关能力信息
typedef struct  
{
	DWORD				dwDataSource;					//1:Net(网络), 2:Com(串口), 3:Net&Com(网络和串口)
	char				szProtocol[32][33];				//协议名字,最大长度32(保留一个结束符).
	BYTE				bReserved[256];
} ZLNET_DEV_ATM_OVERLAY_GENERAL;
 
// atm:配置叠加设置
typedef struct 
{
	DWORD				dwDataSource;					//1:Net(网络), 2:Com(串口)
	char				szProtocol[33];					//协议名字，由DHDEV_ATM_OVERLAY_GENERAL返回
	BYTE				bReserved_1[3];
	DWORD				dwChannelMask;					//叠加的通道号，掩码表示。
	BYTE				bMode;							//1:Preview(预览叠加), 2:Encode(编码叠加), 3:Preview&Encode(预览和编码叠加)
	BYTE				bLocation;						//1:LeftTop(左上), 2:LeftBottom(左下), 3:RightTop(右上), 4:RightBottom(右下)
	BYTE				bReserved_2[258];
} ZLNET_DEV_ATM_OVERLAY_CONFIG;

#define ZLNET_MAX_BACKUPDEV_NUM			16
#define ZLNET_MAX_BACKUP_NAME				32

// 备份设备列表
typedef struct 
{
	int					nBackupDevNum;								// 实际的备份设备数量
	char				szBackupDevNames[ZLNET_MAX_BACKUPDEV_NUM][ZLNET_MAX_BACKUP_NAME]; // 备份设备的名称
} ZLNET_DEV_BACKUP_LIST, *LPZLNET_DEV_BACKUP_LIST;

// 备份设备介质类型
typedef enum __ZLNET_BACKUP_TYPE
{
	ZLNET_BT_ZLFS = 0,							// 智诺文件系统
	ZLNET_BT_DISK,								// 移动硬盘
	ZLNET_BT_CDRW								// 光盘刻录
} ZLNET_DEV_BACKUP_TYPE;	

// 备份设备接口类型
typedef enum __ZLNET_BACKUP_BUS
{
	ZLNET_BB_USB = 0,								// usb接口
	ZLNET_BB_1394,								// 1394接口
	ZLNET_BB_IDE,									// ide接口
	ZLNET_BB_ESATA,								// esata接口
} ZLNET_DEV_BACKUP_BUS;	

typedef struct 
{
	char				szName[32];						// 设备名 
	BYTE				byType;							// 备份设备的介质类型 枚举值见BACKUP_TYPE
	BYTE				byBus;							// 备份设备的接口类型 枚举值见BACKUP_BUS
	UINT				nCapability;					// 总容量, 以kBytes为单位
	UINT				nRemain;						// 剩余容量,以kBytes为单位
	char				szDirectory[128];				// 远程备份的目录
} ZLNET_DEV_BACKUP_INFO, *LPZLNET_DEV_BACKUP_INFO;

typedef struct 
{
	char				szName[32];						// 设备名 
	UINT				nCapability;					// 总容量, 以kBytes为单位
	UINT				nRemain;						// 当前备份剩余容量,以kBytes为单位
} ZLNET_DEV_BACKUP_FEEDBACK, *LPZLNET_DEV_BACKUP_FEEDBACK;

#define  ZLNET_MAX_BACKUPRECORD_NUM 1024

typedef struct  
{
	char				szDeviceName[ZLNET_MAX_BACKUP_NAME];			//备份设备名称
	int					nRecordNum;									//备份记录数量
	ZLNET_RECORDFILE_INFO	stuRecordInfo[ZLNET_MAX_BACKUPRECORD_NUM];		//备份记录信息
} ZLNET_BACKUP_RECORD, *LPZLNET_BACKUP_RECORD;

/////////////////////////////////平台接入/////////////////////////////////

// 平台接入配置 － U网通
typedef struct
{
    BOOL				bChnEn;
    char				szChnId[ZLNET_INTERVIDEO_UCOM_CHANID];
} ZLNET_INTERVIDEO_UCOM_CHN_CFG;

typedef struct
{
	DWORD				dwSize;
	BOOL				bFuncEnable;			// 接入功能使能
	BOOL				bAliveEnable;			// 心跳使能
	DWORD				dwAlivePeriod;			// 心跳周期，单位秒，0-3600
	char				szServerIp[ZLNET_MAX_IPADDR_LEN]; // CMS的IP
	WORD				wServerPort;			// CMS的Port
    char				szRegPwd[ZLNET_INTERVIDEO_UCOM_REGPSW]; // 注册密码
	char				szDeviceId[ZLNET_INTERVIDEO_UCOM_DEVID];// 设备id
	char				szUserName[ZLNET_INTERVIDEO_UCOM_USERNAME];
	char				szPassWord[ZLNET_INTERVIDEO_UCOM_USERPSW];
    ZLNET_INTERVIDEO_UCOM_CHN_CFG  struChnInfo[ZLNET_MAX_CHANNUM]; // 通道id,en
} ZLNET_DEV_INTERVIDEO_UCOM_CFG;

// 平台接入配置 － 阿尔卡特
typedef struct
{
	DWORD				dwSize;
    unsigned short		usCompanyID[2];			// 公司ID，数值，不同的第三方服务公司，考虑4字节对齐，目前只用数组第一个
    char				szDeviceNO[32];			// 前端设备序列号，字符串，包括'\0'结束符共32byte
    char				szVSName[32];			// 前端设备名称，字符串，包括'\0'结束符共16byte
    char				szVapPath[32];			// VAP路径
    unsigned short		usTcpPort;				// TCP端口，数值：数值 1~65535 
    unsigned short		usUdpPort;				// UDP端口，数值：数值 1~65535
    bool				bCsEnable[4];			// 中心服务器使能标志，数值：true使能，false不使能，考虑4字节对齐，目前只用数组第一个
    char				szCsIP[16];				// 中心服务器IP地址，字符串，包括'\0'结束符共16byte
    unsigned short		usCsPort[2];			// 中心服务器端口，数值：数值 1~65535，考虑4字节对齐，目前只用数组第一个
    bool				bHsEnable[4];			// 心跳服务器使能标志，数值：true使能，false不使能，考虑4字节对齐，目前只用数组第一个
    char				szHsIP[16];				// 心跳服务器IP地址，字符串，包括'\0'结束符共16byte
    unsigned short		usHsPort[2];			// 心跳服务器端口，数值：数值 1~65535，考虑4字节对齐，目前只用数组第一个
    int					iHsIntervalTime;		// 心跳服务器间隔周期，数值(单位:秒)
    bool				bRsEnable[4];			// 注册服务器使能标志，数值：true使能，false不使能，考虑4字节对齐，目前只用数组第一个
    char				szRsIP[16];				// 注册服务器IP地址，字符串，包括'\0'结束符共16byte
    unsigned short		usRsPort[2];			// 注册服务器端口，数值：数值 1~65535，考虑4字节对齐，目前只用数组第一个
    int					iRsAgedTime;			// 注册服务器有效时间，数值(单位:小时)
    char				szAuthorizeServerIp[16];// 鉴权服务器IP
    unsigned short		usAuthorizePort[2];		// 鉴权服务器端口，考虑4字节对齐，目前只用数组第一个
    char				szAuthorizeUsername[32];// 鉴权服务器帐号
    char				szAuthorizePassword[36];// 鉴权服务器密码
    
    char				szIpACS[16];			// ACS(自动注册服务器) IP
    unsigned short		usPortACS[2];			// ACS Port，考虑4字节对齐，目前只用数组第一个
    char				szUsernameACS[32];		// ACS用户名
    char				szPasswordACS[36];		// ACS密码
    bool				bVideoMonitorEnabled[4];// DVS是否定期上报前端视频信号监控信息，数值：true使能，false不使能
    int					iVideoMonitorInterval;	// 上报周期(分钟)
    
    char				szCoordinateGPS[64];	// GPS坐标
    char				szPosition[32];			// 设备位置
    char				szConnPass[36];			// 设备接入码
} ZLNET_DEV_INTERVIDEO_BELL_CFG;

// 平台接入配置 － 中兴力维
typedef struct  
{
	DWORD				dwSize;
	unsigned short		nSevPort;				// 服务器端口，数值，数值1~65535
    char				szSevIp[ZLNET_INTERVIDEO_NSS_IP]; // 服务器IP地址，字符串，包括'\0'结束符共32byte
    char				szDevSerial[ZLNET_INTERVIDEO_NSS_SERIAL]; // 前端设备序列号，字符串，包括'\0'结束符共32byte
    char				szUserName[ZLNET_INTERVIDEO_NSS_USER];
    char				szPwd[ZLNET_INTERVIDEO_NSS_PWD];
} ZLNET_DEV_INTERVIDEO_NSS_CFG;

//平台接入配置 － 明软
typedef struct {
	DWORD serverip;
	int serverport;
	char szDevID[ZLNET_INTERVIDEO_MR_ID];
	char DVRUserName[ZLNET_INTERVIDEO_MR_USERPSW];
	char DVRPassword[ZLNET_INTERVIDEO_MR_USERPSW];
}ZLNET_MR_SYSTEM_CONFIG;

typedef struct 
{
	int Enable;								//使能标志, 数值, 1 使能, 0 不使能.
	ZLNET_MR_SYSTEM_CONFIG JFSysConfig;
}ZLNET_INTERVIDEO_MR_CFG;

////////////////////////////////HDVR专用//////////////////////////////////
// 报警联动扩展结构体
typedef struct 
{
	/* 消息处理方式，可以同时多种处理方式，包括
	 * 0x00000001 - 报警上传
	 * 0x00000002 - 联动录象
	 * 0x00000004 - 云台联动
	 * 0x00000008 - 发送邮件
	 * 0x00000010 - 本地轮巡
	 * 0x00000020 - 本地提示
	 * 0x00000040 - 报警输出
	 * 0x00000080 - Ftp上传
	 * 0x00000100 - 蜂鸣
	 * 0x00000200 - 语音提示
	 * 0x00000400 - 抓图
	*/

	/* 当前报警所支持的处理方式，按位掩码表示 */
	DWORD				dwActionMask;

	/* 触发动作，按位掩码表示，具体动作所需要的参数在各自的配置中体现 */
	DWORD				dwActionFlag;
	
	/* 报警触发的输出通道，报警触发的输出，为1表示触发该输出 */ 
	BYTE				byRelAlarmOut[ZLNET_MAX_ALARMOUT_NUM_EX];
	DWORD				dwDuration;				/* 报警持续时间 */

	/* 联动录象 */
	BYTE				byRecordChannel[ZLNET_MAX_VIDEO_IN_NUM_EX]; /* 报警触发的录象通道，为1表示触发该通道 */
	DWORD				dwRecLatch;				/* 录象持续时间 */

	/* 抓图通道 */
	BYTE				bySnap[ZLNET_MAX_VIDEO_IN_NUM_EX];
	/* 轮巡通道 */
	BYTE				byTour[ZLNET_MAX_VIDEO_IN_NUM_EX];

	/* 云台联动 */
	ZLNET_PTZ_LINK			struPtzLink[ZLNET_MAX_VIDEO_IN_NUM_EX];
	DWORD				dwEventLatch;			/* 联动开始延时时间，s为单位，范围是0~15，默认值是0 */
	/* 报警触发的无线输出通道，报警触发的输出，为1表示触发该输出 */ 
	BYTE				byRelWIAlarmOut[ZLNET_MAX_ALARMOUT_NUM_EX];
	BYTE				bMessageToNet;
	BYTE                bMMSEn;                /*短信报警使能*/
	BYTE                bySnapshotTimes;       /*短信发送抓图张数 */
	BYTE				bMatrixEn;				/*!< 矩阵使能 */
	DWORD				dwMatrix;				/*!< 矩阵掩码 */			
	BYTE				bLog;					/*!< 日志使能，目前只有在WTN动态检测中使用 */
	BYTE				byReserved[511];   
} ZLNET_MSG_HANDLE_EX;

// 外部报警扩展
typedef struct
{
	BYTE				byAlarmType;			// 报警器类型，0：常闭，1：常开
	BYTE				byAlarmEn;				// 报警使能
	BYTE				byReserved[2];						
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE_EX	struHandle;				// 处理方式
} ZLNET_ALARMIN_CFG_EX, *LPZLNET_DEV_ALARMIN_CFG_EX; 

// 动态检测报警
typedef struct 
{
	BYTE				byMotionEn;				// 动态检测报警使能
	BYTE				byReserved;
	WORD				wSenseLevel;			// 灵敏度
	WORD				wMotionRow;				// 动态检测区域的行数
	WORD				wMotionCol;				// 动态检测区域的列数
	BYTE				byDetected[ZLNET_MOTION_ROW][ZLNET_MOTION_COL]; // 检测区域，最多32*32块区域
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	//NSP
	ZLNET_MSG_HANDLE_EX		struHandle;				//处理方式
} ZLNET_MOTION_DETECT_CFG_EX;

// 视频丢失报警
typedef struct
{
	BYTE				byAlarmEn;				// 视频丢失报警使能
	BYTE				byReserved[3];
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	//NSP
	ZLNET_MSG_HANDLE_EX	struHandle;				// 处理方式
} ZLNET_VIDEO_LOST_CFG_EX;

// 图像遮挡报警
typedef struct
{
	BYTE				byBlindEnable;			// 使能
	BYTE				byBlindLevel;			// 灵敏度1-6
	BYTE				byReserved[2];
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	//NSP
	ZLNET_MSG_HANDLE_EX	struHandle;				// 处理方式
} ZLNET_BLIND_CFG_EX;

// 硬盘消息(内部报警)
typedef struct 
{
	BYTE				byNoDiskEn;				// 无硬盘时报警
	BYTE				byReserved_1[3];
	ZLNET_TSECT			stNDSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE_EX	struNDHandle;			// 处理方式
	
	BYTE				byLowCapEn;				// 硬盘低容量时报警
	BYTE				byLowerLimit;			// 容量阀值，0-99
	BYTE				byReserved_2[2];
	ZLNET_TSECT			stLCSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE_EX	struLCHandle;			// 处理方式
	
	BYTE				byDiskErrEn;			// 硬盘故障报警
	BYTE				bDiskNum;
	BYTE				byReserved_3[2];
	ZLNET_TSECT			stEDSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE_EX	struEDHandle;			// 处理方式
} ZLNET_DISK_ALARM_CFG_EX;

typedef struct
{
	BYTE				byEnable;
	BYTE				byReserved[3];
	ZLNET_MSG_HANDLE_EX	struHandle;
} ZLNET_NETBROKEN_ALARM_CFG_EX;

// 前端接入配置参数信息
typedef struct __ZLNET_ENCODER_CFG_DEV 
{
	int					nChannels;				// 数字通道个数
	ZLNET_DEV_ENCODER_INFO	stuDevInfo[32];			// 各数字通道的前端编码器信息
	BYTE				byHDAbility;			// 数字通道中最多可支持高清视频个数(为0表示不支持高清设置)
												// 注：如果支持高清设置，高清通道为0~N-1，若将N之后的数字通道设置为高清，有可能保存不成功
	BYTE				bTVAdjust;				// 设备是否支持TV调节, 0:不支持 1:支持.
	BYTE				bDecodeTour;			// 设备是否支持解码轮巡, 0:不支持 大于0:表示前端支持轮巡最大设备数.
	BYTE				bRemotePTZCtl;			// 指示是否支持远程云台控制。
	char				reserved[12];
} ZLNET_ENCODER_CFG_DEV, *LPZLNET_ENCODER_CFG_DEV;

/////////////////////////////////淘汰类型/////////////////////////////////

// 查询设备工作状态通道信息，相关接口已淘汰，请不要使用
typedef struct
{
	BYTE				byRecordStatic;			// 通道是否在录像；0：不录像，1：手动录像，2：自动录象
	BYTE				bySignalStatic;			// 连接的信号状态；0：正常，1：信号丢失
	BYTE				byHardwareStatic;		// 通道硬件状态；0：正常，1：异常，例如DSP死掉
	char				reserve;
	DWORD				dwBitRate;				// 实际码率
	DWORD				dwLinkNum;				// 客户端连接的个数
	DWORD				dwClientIP[ZLNET_MAX_LINK];// 客户端的IP地址
} ZLNET_DEV_CHANNELSTATE, *LPZLNET_DEV_CHANNELSTATE;

// 查询设备工作状态，相关接口已淘汰，请不要使用
typedef struct
{
	DWORD				dwDeviceStatic;			// 设备的状态；0x00：正常，0x01：CPU占用过高，0x02：硬件错误
	ZLNET_DEV_DISKSTATE	stHardDiskStatic[ZLNET_MAX_DISKNUM]; 
	ZLNET_DEV_CHANNELSTATE stChanStatic[ZLNET_MAX_CHANNUM];	//通道的状态
	BYTE				byAlarmInStatic[ZLNET_MAX_ALARMIN];//报警端口的状态；0：没有报警，1：有报警
	BYTE				byAlarmOutStatic[ZLNET_MAX_ALARMOUT]; //报警输出端口的状态；0：没有输出，1：有报警输出
	DWORD				dwLocalDisplay;			// 本地显示状态；0：正常，1：不正常
} ZLNET_DEV_WORKSTATE, *LPZLNET_DEV_WORKSTATE;

// 协议信息
typedef struct 
{
	char				protocolname[12];		// 协议名
	unsigned int		baudbase;				// 波特率
	unsigned char		databits;				// 数据位
	unsigned char		stopbits;				// 停止位
	unsigned char		parity;					// 校验位
	unsigned char		reserve;
} ZLNET_PROTOCOL_INFO, *LPZLNET_PROTOCOL_INFO;

// 语音对讲参数配置
typedef struct 
{
	// 音频输入参数
	BYTE				byInFormatTag;			// 编码类型，如PCM
	BYTE				byInChannels;			// 声道数
	WORD				wInBitsPerSample;		// 采样深度					
	DWORD				dwInSamplesPerSec;		// 采样率

	// 音频输出参数
	BYTE				byOutFormatTag;			// 编码类型，如PCM
	BYTE				byOutChannels;			// 声道数
	WORD				wOutBitsPerSample;		// 采样深度				
	DWORD				dwOutSamplesPerSec;		// 采样率
} ZLNET_DEV_TALK_CFG, *LPZLNET_DEV_TALK_CFG;

//NVR(混合DVR)
typedef enum
{
	NVR_PROTOCOL_TYPE_ZL = 0,
	NVR_PROTOCOL_TYPE_DH,
	NVR_PROTOCOL_TYPE_HH,
	NVR_PROTOCOL_TYPE_ONVIF,
	NVR_PROTOCOL_TYPE_RTSP,
	NVR_PROTOCOL_TYPE_MAX,
}ZLNET_NVR_PROTOCOL;

//连接设备配置
typedef struct 
{
	ZLNET_NVR_PROTOCOL  protocol;			//接入协议
	char ip[ZLNET_MAX_URL_LEN];		//接入的设备IP
	int Port;								//接入的设备端口
	char UserName[ZLNET_NVR_PASSWORD_LEN];	//接入的设备用户名
	char Password[ZLNET_NVR_PASSWORD_LEN];	//接入的设备密码
	int channel;							//接入的设备通道
	BOOL bEnable;							//网络通道使能
	int nNvrResolution;						//当前网络通道的分辨率
	BYTE nReserved[32];						//保留
}ZLNET_NVR_CONFIG_NET_CHN;

//连接设备配置
typedef struct 
{
	int nSize;
	int nValidNum;		//有效配置个数
	int nMaxEncode;		//最大编码能力
	ZLNET_NVR_CONFIG_NET_CHN NetConfig[ZLNET_MAX_CHANNUM];
}ZLNET_NVR_CONFIG_NET;

//通道数
typedef struct 
{
	int nSize;
	int nLocalChn;	//本地通道数
	int nMixChn;	//网络通道数
}ZLNET_NVR_CHANNEL;

//当前网络通道个数
typedef struct 
{
	int nSize;
	int nChannelNum;
	int nError;
	int Reserved1;
	int Reserved2;
	ZLNET_NVR_CONFIG_NET_CHN configNetChN;
} ZLNET_NVR_CHANNEL_INFO_EX ;

//搜索结构体
typedef struct
{
	ZLNET_NVR_PROTOCOL  eProtocol;	//协议类型
	char ip[128];					//ip或者URL
	int  nPort;						//端口号
	char szDevType[32];				//设备类型
}ZLNET_NVR_SEARCHINFO;

//网络通道PTZ参数
typedef struct 
{
	int		nSize;		//结构体大小
	int		nChannel;	//网络通道号
	int		minPreset;	//预置点最小值；
	int		maxPreset;	//预置点最大值；
	int		minTour;	//自动巡航线路的最小值；
	int		maxTour;	//自动巡航线路的最大值；
	int		minPattern;	//轨迹线路的最小值；
	int		maxPattern;	//轨迹线路的最大值；
}ZLNET_NVR_NET_PTZ_PARAM;

//通道名点阵
typedef struct _ZLNET_CHANNEL_NAME_LATTICE
{
	int nSize;						//结构体大小
	int nChannel;					//通道
	int	nWidth;						//点阵宽度
	int nHeight;					//点阵高度
	int nCharacterSize;				//字符长度
	BYTE buffer[ZLNET_LATTICE_LEN];	//一个通道名的点阵大小
} ZLNET_CHANNEL_NAME_LATTICE;

//NVR设备通道模式
typedef struct
{
	int nLocalD1Channel;	//本地通d1道数
	int nLocalCIFChannel;	//本地通cif道数
	int nNetChannel;		//网络通道数
	int nAbility;			//网络接入能力
} ZLNET_NVR_CHANNEL_MODE;

typedef struct
{
	int nSize;						//结构体大小
	int nMode;						//当前通道模式
	int nModeNum;					//通道模式个数
	ZLNET_NVR_CHANNEL_MODE channelMode[ZLNET_CHANNEL_MODE_MAX_NUM];//通道模式
} ZLNET_NVR_CHANNEL_MODE_SUPPORT;

//NVR网络通道状态
typedef struct 
{
	int nChn;		//通道号
	int nState;		//通道状态		
	int nWith;		//分辨率宽
	int nHeight;	//分辨率高
	int nFps;		//帧率
	int nBitRate;	//码率
	int nReserved[4]; 
}ZLNET_NVR_STATE_NET_CHN;

//NVR网络通道状态配置
typedef struct 
{
	int nSize;
	int nNetChnNum;     //NVR有效网络通道数
	ZLNET_NVR_STATE_NET_CHN NetChnState[ZLNET_MAX_CHANNUM]; //网络通道状态信息
}ZLNET_NVR_STATE_NET;

//高清IPC视频参数
typedef struct _ZLNET_VIDEO_PARAM
{
	int nSize;			//结构体大小

	int nCmd;			//视频参数默认命令 0：忽略 1：恢复默认值 2：自然 3：标准 4：艳丽

	int nLens;			//光圈类型
	int nShutter;		//快门控制
	int nAgc;			//自动增益控制

	int nSenseup;		//帧累积

	int nBrightness;	//亮度
	int nAcce;			//亮度动态调节
	int nDefog;			//除雾功能

	int nBackLight;		//背光补偿
	int nWhiteBal;		//白平衡
	int nDayNight;		//日|夜

	int nTwoDNR;		//2D降噪	开关
	int nThreeDNR;		//3D降噪 开关
	int nTdLevel;		//3D降噪级别

	int nMirror;		//镜像 翻转

	int nSharpness;		//锐度开关
	int nSharpnessLevel;//锐度调整级别

	int nLlsc;			//图像四角亮度补偿 开关
	int nNorP;			//N|P 制式选择 实现帧率选择 N:30fps P:25fps

	int nRes[4];		//保留
} ZLNET_VIDEO_PARAM;

//球机视频参数
typedef struct _ZLNET_DOME_CAMERA_VIDEO_PARAM
{
	int nWhiteBalance;					//白平衡
	int nWideDynamic;					//宽动态
	int nHyperResolution;				//超分辨率
	int nICR;							//彩色黑白
	int nAutoICR;						//自动彩转黑
	int nSaturation;					//饱和度
	int nHue;							//色调
	int nRes[4];
}ZLNET_DOME_CAMERA_VIDEO_PARAM;

//UPNP状态
typedef struct _ZLNET_NET_UPNP_STATE
{
	int nSize;			//结构体大小
	int nState;			//UPNP连接状态
	int Res[4];			//保留
} ZLNET_NET_UPNP_STATE;

//WIFI使能
typedef struct _ZLNET_WIFI_ENABLE
{
	int nSize;		//结构体大小
	int nCmd;		//命令 0：关闭 1：开启
	int Res[4];		//保留
} ZLNET_WIFI_ENABLE;

//WIFI连接方式
typedef struct _ZLNET_WIFI_CONNECTION_TYPE
{
	int nSize;		//结构体大小
	int nCmd;		//命令 0：手动 1：自动
	int Res[4];		//保留
} ZLNET_WIFI_CONNECTION_TYPE;

//连接到AP需要设置的参数
//ssid必须设置
//jfs加密方式，根据扫描的结果进行设置
//根据加密方式选择填充其余成员：
//jfs=1	填充:	psk, proto, encryption 
//jfs=2 填充:	wep_tx_keyidx, wep_key
typedef struct _ZLNET_DEV_WIFI_CFG
{
	int nSize;									//结构体大小

	char ifname[ZLNET_WIFI_NET_CARD_LEN];		//eth1 /eth2 //无线网卡名

	char ssid[ZLNET_WIFI_JUNCTION_LEN];			//连接点名称

	/* 加密方式 */
	int nJfs; 									//0:无密码 1:WPA|WPA2 	2:WEP  
	int nKeyType; 								//0:ascii 1:hex 密码格式

	/* WPA */
	char psk[ZLNET_WIFI_PSW_LENGTH];			//密码ascii 和 hex之分
	char protocol[ZLNET_WIFI_PROTOCOL_LNE];		//协议有WPA 和 RSN之分
	char encryption[ZLNET_WIFI_PROTOCOL_LNE];	//加密方法，编码方式 TKIP | CCMP

	/* WEP */
	int nWepTxKeyidx; 							//可以有4组密码，该成员变量表示选择哪组密码
	char wepKey[ZLNET_WIFI_PSW_LENGTH];			//密码

	char Res[64];								//保留
} ZLNET_DEV_WIFI_CFG;

//WIFI可能的加密类型  0为没有加密方式
typedef enum _ZLNET_WIFI_ENCRYPTION_TYPE
{								// +相应的对ZLNET_DEV_WIFI_CFG的设置 
	ZLNET_WIFI_NO = 0,			// |ssid=***, jfs=0
	ZLNET_WIFI_WEP,				// |ssid=***, jfs=2 ,wep_tx_keyidx=?, wep_key=***, key_type=?
	ZLNET_WIFI_WPA_TKIP,	 	// |ssid=***, jfs=1 ,proto=WPA, encryption=TKIP, psk=*** , key_type=?
	ZLNET_WIFI_WPA_CCMP,	 	// |ssid=***, jfs=1 ,proto=WPA, encryption=CCMP, psk=*** , key_type=?  
	ZLNET_WIFI_WPA2_TKIP,		// |ssid=***, jfs=1 ,proto=RSN, encryption=TKIP, psk=*** , key_type=?
	ZLNET_WIFI_WPA2_CCMP		// |ssid=***, jfs=1 ,proto=RSN, encryption=CCMP, psk=*** , key_type=?
} ZLNET_WIFI_ENCRYPTION_TYPE;

//一个无线路由信息
typedef struct _ZLNET_WIRELESS_ROUTER_INFO
{
	char    macAddr[ZLNET_MACADDR_LEN];		//MAC地址
	int     nFreq;							//channel 频段
	int		nChannel;						//无线信道
	int     nSignalLevel;					//信号强度 dbm
	int     nFlags;							//加密方式 WPA-PSK-TKIP | WEP 等等  0:为没有加密 -1:为未知的加密方式
	char    ssid[ZLNET_WIFI_JUNCTION_LEN];	//ap名称
} ZLNET_WIRELESS_ROUTER_INFO;

//wifi扫描得到的信息
typedef struct _ZLNETl_WIFI_NETWORK_INFO
{
	int nSize;			//结构体大小
	int nValidNum;		//有效个数
	ZLNET_WIRELESS_ROUTER_INFO info[ZLNET_MAX_WIFI_INFO_NUM];
} ZLNETl_WIFI_NETWORK_INFO;

//DDNS注册信息
typedef struct _ZLNET_DDNS_REGISTER_INFO
{
	int nSize;									//结构体大小
	int nCmd;									//注册命令
	ZLNET_DDNS_SERVER_CFG  struDdnsServer;		//DDNS服务器结构体
}ZLNET_DDNS_REGISTER_INFO;

//DDNS状态
typedef struct _ZLNET_DDNS_STATE
{
	int nSize;														//结构体大小
	int nValidNum;													//有效个数
	char ddnsType[ZLNET_MAX_DDNS_NUM][ZLNET_MAX_SERVER_TYPE_LEN];	//设备支持的DDNS服务器类型
	int nState[ZLNET_MAX_DDNS_NUM];									//DDNS状态码
	int nRes[4];
}ZLNET_DDNS_STATE;

//私网穿透配置
typedef struct _ZLNET_DEV_STUN_CONFIG 
{
	//char DeviceIP[32];
	int StunEnable;											//私网穿透使能		
	char ServerIP[ZLNET_DEVICE_STUN_SERVERIP];				//服务器IP（域名）
	int SerPort;											//服务器端口
	char LoginSvrName[ZLNET_DEVICE_STUN_USERNAME];			//用户名
	char LoginSvrPassword[ZLNET_DEVICE_STUN_PASSWORD];		//密码
	DWORD Res[48];
}ZLNET_DEV_STUN_CONFIG;

//私网穿透状态
typedef struct _ZLNET_DEV_STUN_STATE
{
	int nState;			//连接状态
	int nError;			//错误码
}ZLNET_DEV_STUN_STATE;

//美电贝尔GB28181配置
typedef struct
{
	int nSize;								//结构体大小

	char deviceID[ZLNET_AEB_ID_LEN];		//美电贝尔GB28181 Device ID
	int nSipPort;							//美电贝尔GB28181 sip 端口
	char deviceDomain[ZLNET_AEB_DOMAIN_LEN];//美电贝尔GB28181 Device 域名
	char password[ZLNET_AEB_PSW_LEN];		//美电贝尔GB28181 密码
	int nExpire;							//美电贝尔GB28181 有效时间
	int nKeepLive;							//美电贝尔GB28181 保活时间

	char serverIp[ZLNET_AEB_IP_LEN];		//美电贝尔GB28181 Server IP
	int nServerPort;						//美电贝尔GB28181 Server 端口
	char serverID[ZLNET_AEB_ID_LEN];		//美电贝尔GB28181 Server ID
	char serverDomain[ZLNET_AEB_DOMAIN_LEN];//美电贝尔GB28181 Server 域名

	int nAlarmNum;							//报警通道数
	int nChannelNum;						//通道数

	char channelInfo[ZLNET_MAX_CHANNUM][ZLNET_AEB_INFO_LEN];		//美电贝尔GB28181 通道信息
	char alarmInfo[ZLNET_AEB_ALARM_INFO_NUM][ZLNET_AEB_INFO_LEN];	//美电贝尔GB28181 报警信息

	int nRes[64];							//保留
} ZLNET_AEB_GB_PROTOCOL;

//康联网络配置
typedef struct
{
	char serverIP[ZLNET_KONLAN_IP_LEN];		//服务器IP
	int  nPort;								//端口
	char id[ZLNET_KONLAN_ID_LEN];			//ID		
	int  nRes[4];							
}ZLNET_KONLAN_NET_CONFIG;					

//通道录像状态
typedef struct
{
	int		nSize;								//结构体大小
	int		nChannelNum;						//通道数
	DWORD	dwRecordStateMask;					//各个通道录像状态掩码值 0:未录像 1:正在录像
	int		nRes[4];
}ZLNET_CHANNEL_RECORD_STATE;

////////////////////////////////智能相关/////////////////////////////////
//智能ATM索引
typedef enum _ZLNET_IVA_ATM_INDEX
{
	ZLNET_IVA_NULL = -1,
	ZLNET_IVA_ATM1 = 0,
	ZLNET_IVA_ATM2,
}ZLNET_IVA_ATM_INDEX;

//自助银行索引
typedef enum _ZLNET_IVA_SSB_INDEX
{
	ZLNET_IVA_SSB_NULL = -1,
	ZLNET_IVA_SSB_HALL = 0,
	ZLNET_IVA_SSB_ROOM,
}ZLNET_IVA_SSB_INDEX;

//人脸通道索引
typedef enum _ZLNET_IVA_FACE_INDEX
{
	ZLNET_IVA_FACE_NULL = -1,
	ZLNET_IVA_FACE_ANALYSIS = 0,	//分析通道
	ZLNET_IVA_FACE_PANORAMIC,		//全景通道
}ZLNET_IVA_FACE_INDEX;

//车牌区域类型
typedef enum _ZLNET_LICENSE_PLATE_REGION_TYPE
{
	ZLNET_IVA_LICENSE_PLATE_REGION_NULL = 0,
	ZLNET_IVA_LICENSE_PLATE_REGION_DETECTION,	//车辆屏蔽区域
	ZLNET_IVA_LICENSE_PLATE_REGION_FORBIDDEN,	//车辆检测区域
} ZLNET_LICENSE_PLATE_REGION_TYPE;

//逻辑通道顺序
typedef enum _ZLNET_IVA_LOGIC_CHANNEL
{
	ZLNET_IVA_ATM1_PANEL = 0,		//ATM1面板
	ZLNET_IVA_ATM1_FACE,			//ATM1人脸
	ZLNET_IVA_ATM2_PANEL,			//ATM2面板
	ZLNET_IVA_ATM2_FACE,			//ATM2人脸
}ZLNET_IVA_LOGIC_CHANNEL;

//日志存储模式 
typedef enum _ZLNET_IVA_LOG_MODE
{
	ZLNET_IVA_LOGMODE_NETSEND = 0,		/*网络发送*/
	ZLNET_IVA_LOGMODE_LOCAL,			/*本地存储*/
	ZLNET_IVA_LOGMODE_LOCALA_NETSEND	/*网络发送并本地存储*/
}ZLNET_IVA_LOG_MODE;

//日志查询方式
typedef enum _ZLNET_IVA_LOG_SEARCH_MODE
{
	ZLNET_IVA_SEARCHMODE_DATE = 0,	/* 日期模式 */
	ZLNET_IVA_SEARCHMODE_ID,		/* ID模式 */
}ZLNET_IVA_LOG_SEARCH_MODE;

//日志下载模式
typedef enum _ZLNET_IVA_LOG_DOWNLOAD_MODE
{
	ZLNET_IVA_DOWNLOADMODE_DOWNLOAD = 0,	/* 下载 */
	ZLNET_IVA_DOWNLOADMODE_DOWNLOADDEL,		/* 下载并删除 */
	ZLNET_IVA_DOWNLOADMODE_DEL,				/* 删除 */
}ZLNET_IVA_LOG_DOWNLOAD_MODE;

//人员统计人员进入方向
typedef enum _ZLNET_IVA_HDCTTYPE
{
	ZLNET_IVA_HDCT_IN = 0 ,		//人员进入
	ZLNET_IVA_HDCT_OUT			//人员离开
}ZLNET_IVA_HDCTTYPE; 

//智能报警类型
typedef enum _ZLNET_IVA_ATM_ALARM_TYPE
{
	ZLNET_IVA_ATMALARMTYPE_ATM_DETECTAREA = 26,		//检测区域不明物报警(跟设备兼容)
	ZLNET_IVA_ATMALARMTYPE_ATM_KEYBOARDAREA,		//键盘区域不明物报警
	ZLNET_IVA_ATMALARMTYPE_ATM_CARDREGION,			//插卡口区域不明物报警
	ZLNET_IVA_ATMALARMTYPE_ATM_SHIELD,				//键盘罩区域不明物报警
	ZLNET_IVA_ATMALARMTYPE_ATM_ENTER,				//人员进入报警
	ZLNET_IVA_ATMALARMTYPE_ATM_LEAVE,				//人员离开报警
	ZLNET_IVA_ATMALARMTYPE_ATM_PROCESS_TOOLONG,		//人员长时间操作报警
	ZLNET_IVA_ATMALARMTYPE_ATM_PANEL_CAMERA_BLOCK,	//面板摄像头被堵报警
	ZLNET_IVA_ATMALARMTYPE_ATM_FACE_CAMERA_BLOCK,	//人脸摄像头被堵报警
	ZLNET_IVA_ATMALARMTYPE_ATM_PANEL_AMERA_NOSIGNAL,//面板摄像头无视频信号报警
	ZLNET_IVA_ATMALARMTYPE_ATM_FACE_CAMERA_NOSIGNAL,//人脸摄像头无视频信号报警
	ZLNET_IVA_ATMALARMTYPE_ATM_STRANGER,			//陌生人报警(正常人脸报警)
	ZLNET_IVA_ATMALARMTYPE_ATM_ARNORMAL,			//异常人报警
	ZLNET_IVA_ATMALARMTYPE_ATM_GPI,					//开关输入报警(外部报警)

	ZLNET_IVA_PLATEID_ALARM_TYPE = 51,				//车牌报警
	ZLNET_IVA_PLATEID_ALARM_GPI = 52,				//车牌设备本地报警

	ZLNET_IVA_STAFFCOUNT_FORWARD = 61,					//人头统计进入报警
	ZLNET_IVA_STAFFCOUNT_REVERSE,								//人头统计离开报警
	ZLNET_IVA_STAFFCOUNT_MULTIUSER,							//多人报警	
	ZLNET_IVA_STAFFCOUNT_ALARM_GPI,							//开关输入报警(外部报警)

	ZLNET_IVA_SSB_TRAILING_WITHDRAWALS = 71,		//大厅尾随取款报警
	ZLNET_IVA_SSB_PEOPEL_HOVER,						//大厅人员徘徊
	ZLNET_IVA_SSB_PEOPEL_FELL,						//大厅人员倒地
	ZLNET_IVA_SSB_REMNANTS,							//大厅遗留物报警
	ZLNET_IVA_SSB_PEOPELS_GATHER,					//大厅多人聚集报警
	ZLNET_IVA_SSB_FORBIDDEN_ACCESS,                 //大厅禁止进入
	ZLNET_IVA_SSB_FIGHTING,                         //大厅打架事件
	ZLNET_IVA_SSB_CAMERA_NO_SIGNAL,					//大厅摄像头无信号报警
	ZLNET_IVA_SSB_CAMERA_ABNORMAL,					//大厅摄像头异常报警
	ZLNET_IVA_SSB_SPORTS_INVADE,					//加钞间运动入侵报警
	ZLNET_IVA_SSB_ROOM_CAMERA_NO_SIGNAL,			//加钞间摄像头无信号报警
	ZLNET_IVA_SSB_ALARM_GPI,						//开关输入报警(外部报警)

	ZLNET_IVA_BZS_CROSS_FORWARD_ALARM = 101,		//正向跨线报警
	ZLNET_IVA_BZS_CROSS_REVERSE_ALARM,      		//反向跨线报警
	ZLNET_IVA_BZS_TOUCH_LINE_ALARM,					//正向触线报警
	ZLNET_IVA_BZS_TOUCH_LINE_NEG_DIR_ALARM, 		//反向触线报警
	ZLNET_IVA_BZS_CROSS_TWO_LINE_ALARM,				//双线检测报警
	ZLNET_IVA_BZS_AREA_ENTER_ALARM, 				//区域检测进入区域报警
	ZLNET_IVA_BZS_AREA_LEAVE_ALARM, 				//区域检测离开区域报警
	ZLNET_IVA_BZS_AREA_TOUCH_AREA_ALARM,			//区域检测触及区域报警
	ZLNET_IVA_BZS_AREA_LINGER_ALARM,				//区域检测徘徊报警
	ZLNET_IVA_BZS_AREA_APPEAR_ALARM,				//区域检测出现报警(子类型)
	ZLNET_IVA_BZS_AREA_DISAPPEAR_ALARM,				//区域检测消失报警(子类型)
	ZLNET_IVA_BZS_OBJECT_MOVE_ALARM,      			//盗移报警
	ZLNET_IVA_BZS_CAMERA_NO_SIGNAL_ALARM,			//摄像无信号头报警
	ZLNET_IVA_BZS_CAMERA_ABNORMAL_ALARM, 			//摄像异常头报警
	ZLNET_IVA_BZS_GPI_ALARM,						//开关输入报警(外部报警)

	ZLNET_IVA_FACE_CAPTURE_ALARM = 131,				//人脸捕获报警
	ZLNET_IVA_FACE_ANALYSIS_NO_SIGNAL_ALARM,		//分析通道摄像头无信号
	ZLNET_IVA_FACE_PANORAMIC_NO_SIGNAL_ALARM,		//全景通道摄像头无信号
	ZLNET_IVA_FACE_GPI_ALARM,						//开关输入报警(外部报警)
	ZLNET_IVA_ARMTYPE_MIN = ZLNET_IVA_ATMALARMTYPE_ATM_DETECTAREA,		//报警最小值
	ZLNET_IVA_ARMTYPE_MAX = ZLNET_IVA_FACE_GPI_ALARM,		//报警最大值(注意:增加报警类型需要替换成最大的类型值!!!)
}ZLNET_IVA_ALARM_TYPE; 

typedef enum _ZLNET_IVA_STAFF_ALARM_ENABLE_MASK 
{
	ZLNET_IVA_STAFF_FORWARD_MASK = 0x01,
	ZLNET_IVA_STAFF_REVERSE_MASK = 0x02,
	ZLNET_IVA_STAFF_MULTI_MASK = 0x04,
}ZLNET_IVA_STAFF_ALARM_ENABLE_MASK;

typedef enum _ZLNET_IVA_ATM_ALARM_ENABLE_MASK 
{
	ZLNET_IVA_ATM_DETECTAREA_MASK = 0x1,				//检测区域不明物报警(跟设备兼容)
	ZLNET_IVA_ATM_KEYBOARDAREA_MASK = 0x2,				//键盘区域不明物报警
	ZLNET_IVA_ATM_CARDREGION_MASK = 0x4,				//插卡口区域不明物报警
	ZLNET_IVA_ATM_SHIELD_MASK = 0x8,					//键盘罩区域不明物报警
	ZLNET_IVA_ATM_ENTER_MASK = 0x10,					//人员进入报警
	ZLNET_IVA_ATM_LEAVE_MASK = 0x20,					//人员离开报警
	ZLNET_IVA_ATM_PROCESS_TOOLONG_MASK = 0x40,			//人员长时间操作报警
	ZLNET_IVA_ATM_PANEL_CAMERA_BLOCK_MASK = 0x80,		//面板摄像头被堵报警
	ZLNET_IVA_ATM_FACE_CAMERA_BLOCK_MASK = 0x100,		//人脸摄像头被堵报警
	ZLNET_IVA_ATM_PANEL_AMERA_NOSIGNAL_MASK = 0x200,	//面板摄像头无视频信号报警
	ZLNET_IVA_ATM_FACE_CAMERA_NOSIGNAL_MASK = 0x400,	//人脸摄像头无视频信号报警
	ZLNET_IVA_ATM_STRANGER_MASK = 0x800,				//陌生人报警(正常人脸报警)
	ZLNET_IVA_ATM_ARNORMA_MASK = 0x1000,				//异常人报警
}ZLNET_IVA_ATM_ALARM_ENABLE_MASK;

//自助银行报警类型使能
typedef enum _ZLNET_IVA_SSB_ALARM_ENABLE_MASK 
{
	ZLNET_IVA_SSB_TRAILING_WITHDRAWALS_MASK = 0x1,	//大厅尾随取款报警
	ZLNET_IVA_SSB_PEOPEL_HOVER_MASK = 0x2,			//大厅人员徘徊
	ZLNET_IVA_SSB_PEOPEL_FELL_MASK = 0x4,			//大厅人员倒地
	ZLNET_IVA_SSB_REMNANTS_MASK = 0x8,				//大厅遗留物报警
	ZLNET_IVA_SSB_PEOPELS_GATHER_MASK = 0x10,		//大厅多人聚集报警
	ZLNET_IVA_SSB_FORBIDDEN_ACCESS_MASK = 0x20,     //大厅禁止进入
	ZLNET_IVA_SSB_FIGHTING_MASK = 0x40,             //大厅打架事件
	ZLNET_IVA_SSB_CAMERA_NO_SIGNAL_MASK = 0x80,		//大厅摄像头无信号报警
	ZLNET_IVA_SSB_CAMERA_ABNORMAL_MASK = 0x100,		//大厅摄像头异常报警
	ZLNET_IVA_SSB_SPORTS_INVADE_MASK = 0x200,       //加钞间运动入侵
	ZLNET_IVA_SSB_ROOM_CAMERA_NO_SIGNAL_MASK = 0x400,//加钞间摄像头无信号报警
}ZLNET_IVA_SSB_ALARM_ENABLE_MASK;

//周界报警类型使能
typedef enum _IVA_BZS_ALARM_ENABLE_MASK
{
	ZLNET_IVA_BZS_SINGLE_WARNING_LINE_MASK = 0x01,			//正向跨越报警
	ZLNET_IVA_BZS_NEG_CROSS_WARNING_LINE_MASK = 0x02,       //反向跨线报警
	ZLNET_IVA_BZS_TOUCH_WARNING_LING_MASK = 0x04,           //正向触线报警
	ZLNET_IVA_BZS_NEG_TOUCH_WARNING_LINE_MASK= 0x08,        //反向触线报警
	ZLNET_IVA_BZS_DOUBLE_WARNING_LINE_MASK = 0x10,			//周界双警界线报警
	ZLNET_IVA_BZS_ENTER_AREA_WARNING_MASK = 0x20,			//进入区域报警
	ZLNET_IVA_BZS_LEAVE_AREA_WARNING_MASK = 0x40,           //离开区域报警
	ZLNET_IVA_BZS_TOUCH_AREA_WARNING_MASK = 0x80,           //触及区域报警
	ZLNET_IVA_BZS_LINGER_AREA_WARNING_MASK = 0x100,         //区域检测徘徊报警
	ZLNET_IVA_BZS_APPEAR_AREA_WARNING_MASK = 0x200,         //区域检测出现报警
	ZLNET_IVA_BZS_DISAPPEAR_AREA_WARNING_MASK = 0x400,		//区域检测消失报警
	ZLNET_IVA_BZS_OBJECT_STOLEN_MASK = 0x800,				//物品盗移报警
	ZLNET_IVA_BZS_CAMERA_NO_SIGNAL_MASK = 0x1000,           //摄像头无信号
	ZLNET_IVA_BZS_CAMERA_ABNORMAL_MASK = 0x2000,			//摄像头异常报警
}IVA_BZS_ALARM_ENABLE_MASK;

//人脸报警类型使能
typedef enum _ZLNET_IVA_FACE_ALARM_ENABLE_MASK
{
	ZLNET_IVA_FACE_CAPTURE_MASK = 0x01,						//人脸捕获报警
	ZLNET_IVA_FACE_CAMERA_NO_SIGNAL_MASK = 0x02,			//人脸通道摄像头无信号
	ZLNET_IVA_PANORAMIC_CAMERA_NO_SIGNAL_MASK = 0x04,		//全景通道摄像头无信号
} ZLNET_IVA_FACE_ALARM_ENABLE_MASK;

//音频上传信息
#define ZLNET_IVA_AUDIO_UPLOAD_INFO_NUM	(ZLNET_IVA_ATMALARMTYPE_ATM_GPI - ZLNET_IVA_ATMALARMTYPE_ATM_DETECTAREA + ZLNET_IVA_MAX_CHANNEL)

//报警信息类型
typedef enum _ZLNET_IVA_ALARMINFO_TYPE
{
	ZLNET_IVA_ALARMINFO_NULL = 0,
	ZLNET_IVA_ALARMINFO_PICTURE = 0x1,	//图片
	ZLNET_IVA_ALARMINFO_VIDEO = 0x2,	//视频
}ZLNET_IVA_ALARMINFO_TYPE;
//报警视频流类型定义
typedef enum _ZLNET_IVA_ALARMVIDEOTYPE
{
	ZLNET_VIDEO_START = 1,			//视频流开始
	ZLNET_VIDEO_ALARM,				//视频流传送中
	ZLNET_VIDEO_STOP				//视频流结束
}ZLNET_IVA_ALARMVIDEOTYPE;


#define ZLNET_IVA_ATM_TOTAL		20	//ATM区域类型总数
//区域类型
typedef enum _ZLNET_IVA_AREA_TYPE
{
	ZLNET_IVA_AREA_NULL = -1,
	ZLNET_IVA_AREA_WARN = 0,				//报警区域	多
	ZLNET_IVA_AREA_KEYBOARD,				//键盘区域
	ZLNET_IVA_AREA_CARDPORT,				//插卡口区域
	ZLNET_IVA_AREA_KEYMASK,					//键盘罩区域
	ZLNET_IVA_AREA_HUMAN,					//人员活动区域 多
	ZLNET_IVA_AREA_FACEHUMAN,				//人脸区域	面板右边
	ZLNET_IVA_AREA_OBJSIZE,					//目标区域 (最小检测尺寸)
	ZLNET_IVA_AREA_SCREEN,					//屏幕区域	(没实现)
	ZLNET_IVA_VEHICLE_DETECTION_AREA,		//车辆检测区域
	ZLNET_IVA_VEHICLES_PROHIBITED_AREA,		//车辆屏蔽区域
	ZLNET_IVA_DETECTION_LINE,				//人数统计检测线
	ZLNET_IVA_BZS_PROCESS_REGION = 30,		//周界处理区域
	ZLNET_IVA_BZS_SHIELD_REGION,			//周界屏蔽区域
	ZLNET_IVA_BZS_CROSS_ONE_LINE_RULE,		//周界单线检测
	ZLNET_IVA_BZS_CROSS_TWO_LINE_RULE,		//周界双线检测
	ZLNET_IVA_BZS_AREA_DETECT_RULE,			//周界区域检测
	ZLNET_IVA_BZS_OBJECT_MOVE,				//周界盗移检测
	ZLNET_IVA_SSB_HALL_PROCESS = 45,		//自助厅处理区域
	ZLNET_IVA_SSB_HALL_WITHDRAWALS,			//自助厅取款区域
	ZLNET_IVA_SSB_HALL_SHIELD,				//自助厅屏蔽区域
	ZLNET_IVA_SSB_ROOM_PROCESS,				//加钞间处理区域
	ZLNET_IVA_SSB_ROOM_SHIELD,				//加钞间屏蔽区域
	ZLNET_IVA_FACE_DETECT,					//人脸检测区域
	ZLNET_IVA_FACE_OVERLAY,					//人脸叠加区域
	ZLNET_IVA_FACE_SHIELD,							//人脸屏蔽区域 原保留一
	ZLNET_IVA_AREA_RESERVED2,
	ZLNET_IVA_AREA_RESERVED3,
	ZLNET_IVA_AREA_TOTAL,
}ZLNET_IVA_AREA_TYPE;

//视频叠加模式
typedef enum _ZLNET_IVA_VIDEOBLEND_MODE
{
	ZLNET_IVA_VIDEOBLEND_PREVIEW = 0x1,		//网络预览叠加
	ZLNET_IVA_VIDEOBLEND_PIC = 0x2,			//抓图叠加
	ZLNET_IVA_VIDEOBLEND_LOCAL = 0x4,		//设备本地视频输出叠加
	ZLNET_IVA_VIDEOBLEND_DEBUG = 0x8,		//算法调试
	ZLNET_IVA_VIDEOBLEND_RULE = 0x10,       //网络预览规则框
	ZLNET_IVA_VIDEOBLEND_INFO  = 0x20,      //网络预览报警框
	ZLNET_IVA_VIDEOBLEND_TRACK = 0x40,      //网络预览跟踪框、人脸跟踪
	ZLNET_IVA_VIDEOBLEND_OVERLAY = 0x80,    //是否叠加人脸区域
	ZLNET_IVA_TRACK_INFO = 0x100,			//跟踪轨迹
}ZLNET_IVA_VIDEOBLEND_MODE;

//在线用户操作类型
typedef enum _ZLNET_IVA_ONLINE_OPRATE
{
	ZLNET_IVA_ONLINE_NULL = 0,
	ZLNET_IVA_ONLINE_KICK,		//踢除
	ZLNET_IVA_ONLINE_BLOCK,		//屏蔽
}ZLNET_IVA_ONLINE_OPRATE;

//车牌检测参数设置
typedef enum _ZLNET_IVA_LICENSE_PLATE_TYPE
{	
	ZLNET_IVA_PLATEID_CONFIGFLAG_NONE = 0x0,				//无配置
	ZLNET_IVA_PLATEID_CONFIGFLAG_VCOMPRESS = 0x1,   		//垂直方向压缩 
	ZLNET_IVA_PLATEID_CONFIGFLAG_FIELDIMG = 0x2,   			//是否是场图像 
	ZLNET_IVA_PLATEID_CONFIGFLAG_OUTPUTSINGLEFRAME = 0x4,	//军车识别 
	ZLNET_IVA_PLATEID_CONFIGFLAG_INDIVIDUA = 0x8,   		//个性化车牌识别 
	ZLNET_IVA_PLATEID_CONFIGFLAG_TWOROWYELLOW = 0x10,   	//双排黄色车识别 
	ZLNET_IVA_PLATEID_CONFIGFLAG_ARMPOLICE = 0x20,   		//双排军车识别 
	ZLNET_IVA_PLATEID_CONFIGFLAG_TWOROWARMY = 0x40,  		//同一车多幅图像只输出一个结果
	ZLNET_IVA_PLATEID_CONFIGFLAG_TRIGGE = 0x80,				//是否同时发送场景图像
} ZLNET_IVA_LICENSE_PLATE_TYPE;

//车辆方向
typedef enum _ZLNET_IVA_PLATEID_DRIVE
{	
	ZLNET_IVA_PLATEID_DRIVE_NULL = 0x0,
	ZLNET_IVA_PLATEID_DRIVE_LEFT ,		//向左			
	ZLNET_IVA_PLATEID_DRIVE_RIGHT ,		//向右			
	ZLNET_IVA_PLATEID_DRIVE_UP ,		//向上			
	ZLNET_IVA_PLATEID_DRIVE_DOWN ,		//向下			
} ZLNET_IVA_PLATEID_DRIVE;

//逆向行驶报警
typedef enum _ZLNET_IVA_REVERSE_DRIVE_SET
{	
	ZLNET_IVA_EVERSE_DRIVE_NONE = 0x0,						
	ZLNET_IVA_EVERSE_DRIVE_LEFT = 0x1,   	//向左	
	ZLNET_IVA_EVERSE_DRIVE_RIGHT = 0x2,   	//向右	
	ZLNET_IVA_EVERSE_DRIVE_UP = 0x4,		//向上	
	ZLNET_IVA_EVERSE_DRIVE_DOWN = 0x8,   	//向下	
} ZLNET_IVA_REVERSE_DRIVE_SET;

//车牌颜色
typedef enum _ZLNET_IVA_PLATEID_COLOR
{
	ZLNET_IVA_PLATEID_COLORUNKNOWN = 0,		//未知颜色
	ZLNET_IVA_PLATEID_COLORBLUE,			//蓝色
	ZLNET_IVA_PLATEID_COLORYELLOW,			//黄色
	ZLNET_IVA_PLATEID_COLORWHITE,			//白色
	ZLNET_IVA_PLATEID_COLORBLACK,			//黑色
	ZLNET_IVA_PLATEID_COLORGREEN,			//绿色
} ZLNET_IVA_PLATEID_COLOR;

//车牌类型
typedef enum _ZLNET_IVA_PLATEID_TYPE
{
	ZLNET_IVA_PLATEID_TYPEUNKNOWN = 0,		//未知类型
	ZLNET_IVA_PLATEID_TYPEBLUE,				//蓝车牌
	ZLNET_IVA_PLATEID_TYPEBLACK,			//黑车牌
	ZLNET_IVA_PLATEID_TYPEYELLOW,			//单排黄色车牌
	ZLNET_IVA_PLATEID_TYPEYELLOW2,			//双排黄色车牌
	ZLNET_IVA_PLATEID_TYPEPOLICE,			//警车车牌
	ZLNET_IVA_PLATEID_TYPEARMPOL,			//军警车牌
	ZLNET_IVA_PLATEID_TYPEINDIVI,			//个性化车牌
	ZLNET_IVA_PLATEID_TYPEARMY,				//单排军用车牌
	ZLNET_IVA_PLATEID_TYPEARMY2,			//双排军用车牌
	ZLNET_IVA_PLATEID_TYPEEMBASSY,			//大使馆车牌
	ZLNET_IVA_PLATEID_TYPEHONGKONG,			//香港车牌
} ZLNET_IVA_PLATEID_TYPE;

//周界禁止区域类型
typedef enum _ZLNET_IVA_BZS_AREA_ALARM_MASK
{
	ZLNET_IVA_BZS_AREA_ENTER 	  = 0x0001,		// 进入区域
	ZLNET_IVA_BZS_AREA_LEAVE 	  = 0x0002,		// 离开区域
	ZLNET_IVA_BZS_AREA_TOUCH_AREA = 0x0004,		// 触及区域
	ZLNET_IVA_BZS_AREA_OBJMOVE 	  = 0x0008,		// 盗移
	ZLNET_IVA_BZS_AREA_LINGER	  = 0x0010,		// 徘徊
	ZLNET_IVA_BZS_AREA_APPEAR	  = 0x0020,		// 出现
	ZLNET_IVA_BZS_AREA_DISAPPEAR  = 0x0040		// 消失
} ZLNET_IVA_BZS_AREA_ALARM_MASK;

//周界单线使能
typedef enum _ZLNET_IVA_BZS_CROSS_LINE_MASK
{
	ZLNET_IVA_BZS_CROSS_ONEWAY = 0x0001,		// 正向跨线
	ZLNET_IVA_BZS_CROSS_TWOWAY	= 0x0002,		// 反向跨线
	ZLNET_IVA_BZS_TOUCHLINE_ONEWAY = 0x0004,	// 正向触线
	ZLNET_IVA_BZS_TOUCHLINE_TWOWAY = 0x0008 	// 反向触线
} ZLNET_IVA_BZS_CROSS_LINE_MASK;	

//背景更新掩码
typedef enum _ZLNET_IVA_BACKGROUND_UPDATE_MASK 
{
	ZLNET_IVA_ATM_MASK= 0x1,			//ATM 0-忽略 1-重启
	ZLNET_IVA_PLATEID_MASK = 0x2,		//车牌 0-忽略 1-重启
	ZLNET_IVA_STAFFCOUNT_MASK = 0x4,	//人头计数 0-忽略 1-重启
	ZLNET_IVA_SSB_MASK = 0x8,			//自助银行 0-忽略 1-重启
	ZLNET_IVA_BZS_MASK = 0x10,			//周界 0-忽略 1-重启
} ZLNET_IVA_BACKGROUND_UPDATE_MASK;

//人头分析通道
typedef enum _ZLNET_IVA_STAFF_COUNT_CHANNEL
{
	ZLNET_IVA_STAFFCOUNT_ANALYSIS_CH = -1,//代表以前的一路设备
	ZLNET_IVA_STAFFCOUNT_ANALYSIS_CH1 = 0,
	ZLNET_IVA_STAFFCOUNT_ANALYSIS_CH2,
	ZLNET_IVA_STAFFCOUNT_ANALYSIS_CH3,
	ZLNET_IVA_STAFFCOUNT_ANALYSIS_CH4,
} ZLNET_IVA_STAFF_COUNT_CHANNEL;

//人脸捕获模式
typedef enum _ZLNET_IVA_FACE_CAPTURE_MODE
{
	ZLNET_IVA_FACE_CAPTURE = 0,		//抓拍模式
	ZLNET_IVA_FACE_THAN,			//比对模式
} ZLNET_IVA_FACE_CAPTURE_MODE;

//人脸叠加模式
typedef enum _ZLNET_IVA_FACE_OVERLAY_MODE
{
	ZLNET_IVA_FACE_NO_OVERLAY = 0,		//不叠加
	ZLNET_IVA_FACE_OVERLAY_FACE,		//叠加人脸
	ZLNET_IVA_FACE_OVERLAY_FACE_VIDEO,	//叠加人脸视频
} ZLNET_IVA_FACE_OVERLAY_MODE;

typedef struct _ZLNET_ALARMRECT
{
	int left ;
	int top ;
	int right ;
	int bottom ;
} ZLNET_ALARMRECT;

//时间结构															    
typedef struct _ZLNET_IVA_TIME
{
	int tm_year;    
	int tm_mon;     // [0,11] 
	int tm_mday;    // [1,31] 
	int tm_hour;    // [0,23] 
	int tm_min;     // [0,59] 
	int tm_sec;     // [0,59] 
}ZLNET_IVA_TIME;

//点坐标
typedef struct _ZLNET_IVA_POINT
{
	long	x;
	long	y;
}ZLNET_IVA_POINT;

typedef struct _ZLNET_IVA_RECTINFO
{
	int		left ;
	int		top ;
	int		right ;
	int		bottom ;
	int		nConfidence;	// 人脸分数
	int		nTrackID;	// 追踪ID
} ZLNET_IVA_RECTINFO;

//区域结构
typedef struct  _ZLNET_IVA_MONITORREGION
{
	unsigned int point[ZLNET_IVA_MAX_POLYGON_POINT];//多边形点坐标(高16位为Y, 低16位为X)
	short		 pointNum;							//有效点数
	ZLNET_IVA_AREA_TYPE	 regionType;				//区域类型
} ZLNET_IVA_MONITORREGION;

//视频通道模式配置
 typedef struct _ZLNET_IVA_CHANNEL_CONFIG
 {
 	int		size;					
	ZLNET_IVA_VIDEOBLEND_MODE  blendMode[ZLNET_IVA_MAX_CHANNEL];	//视频叠加模式
	int		videoMode[ZLNET_IVA_MAX_CHANNEL];				//逻辑通道和物理通道的映射关系(已不用)
	int		asscEnabel[ZLNET_IVA_MAX_CHANNEL/2];			//关联分析使能
	int		faceCompare[ZLNET_IVA_MAX_CHANNEL/2];			//人脸连续对比
	int videoPinMode;										//模拟视频通道输出掩码
 }ZLNET_IVA_CHANNEL_CONFIG;

 //报警信息图片
 typedef struct _ZLNET_IVA_ALARMINFO_PIC
 {
	 unsigned int		picMode;	//0:实时图片 1：预录图片
	 unsigned int		logicChn;	//逻辑通道号				
	 unsigned int		dataLen;	//数据长度
	 unsigned char		*data;		//数据
 } ZLNET_IVA_ALARMINFO_PIC;

 //智能报警共用部分
 typedef struct _ZLNET_IVA_EVENT
 {
	 DWORD 	  id;            // 日志ID
	 ZLNET_DEVTIME  time;    // 日期
	 WORD      alarmType;    // 报警类型(SSB报警类型和ATM报警类型)
	 BYTE      logicChn;     // 产生报警的通道
	 BYTE      picNum;   	 // 图片张数
	 ZLNET_DEVTIME	  stTime;       //联动录像开始时间
	 ZLNET_DEVTIME    endTime;      //联动录像结束时间
	 DWORD			driveno;		// 磁盘号(老设备, 磁盘号和起始簇号都为0)
	 DWORD			startcluster;	// 起始簇号
	 BYTE      reserve[8];  //保留
 }ZLNET_IVA_EVENT;

//ATM报警事件详细信息
typedef struct _ZLNET_IVA_ATM_DETAIL
{
	DWORD 			rectValidNum;
	ZLNET_IVA_RECTINFO  rect[ZLNET_IVA_MAX_NUM_ATMALARM_RECT];     // 区域
	BYTE		    reserve[16];  //保留
}ZLNET_IVA_ATM_DETAIL;

//ATM报警上传日志+区域信息+图片
typedef struct _ZLNET_IVA_ALARMINFO
{
	DWORD     	size; 	 //结构体大小
	ZLNET_IVA_EVENT      IVSEvent;  //基本信息
	ZLNET_IVA_ATM_DETAIL IVSDetail; //详细信息
	ZLNET_IVA_ALARMINFO_PIC pic[ZLNET_IVA_MAX_CHANNEL*2];	// 图片数据
}ZLNET_IVA_ATM_ALARMINFO;


//人数统计报警信息
typedef struct _ZLNET_IVA_HDCTRECT
{
	ZLNET_IVA_HDCTTYPE   type ;
	ZLNET_RECT  rect;
	int    nReserved[4];
} ZLNET_IVA_HDCRECT; 

//报警联动配置子项
typedef struct _ZLNET_IVA_ALARM_ASSCONFIG
{
	int		size;			
	int 	bVoice;					//语音提示
	int		bAlarmOutEn;			//报警输出
	int		dwAlarmOut;				//报警输出通道掩码 
	int		iAOLatch;				//报警输出延时
	int 	iRecLatch;				//报警录像延时
	unsigned char asschn[ZLNET_IVA_MAX_CHANNEL];//物理通道关联动作，值为报警信息类型(ZLNET_IVA_ALARMINFO_TYPE)组合
	int		bFtp;					//是否上传FTP
	int		bEmail;					//是否上传Emil
}ZLNET_IVA_ALARM_ASSCONFIG;

//外部报警配置
typedef struct _ZLNET_IVA_GPI_ASSCONFIG
{
	int		enable;					//使能
	int     polarity;				//极性
	ZLNET_IVA_ALARM_ASSCONFIG	assc;	//联动项 
}ZLNET_IVA_GPI_ASSCONFIG;

//报警录像配置参数
typedef struct _ZLNET_IVA_ALARM_RECORD
{
	short		pretime;			//报警前录像时间(秒)
	short		aftertime;			//报警后录像时间(秒)
}ZLNET_IVA_ALARM_RECORD;

//星期时间段
typedef struct _ZLNET_IVA_WEEK_SECTION
{
	ZLNET_TSECT	sec[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	//时间段
}ZLNET_IVA_WEEK_SECTION;

//工作表信息	
typedef struct _ZLNET_IVA_WORKSHEET
{
	int					nInterval;	//音频播放间隔
	ZLNET_IVA_WEEK_SECTION	chnR;	//时间段
}ZLNET_IVA_WORKSHEET;

//网络配置
typedef struct _ZLNET_IVA_NET_CFG
{
	ZLNET_ETHERNET			stEtherNet[ZLNET_MAX_ETHERNET_NUM];	// 以太网口
	ZLNET_DNS_DEV_CFG		stDNS;								// DNS服务器
	ZLNET_REMOTE_HOST		stPppoeServer;						// PPPoE服务器
	ZLNET_NTP_DEV_CFG		stNTP;								// NTP服务器
	int						nTcpPort;							// TCP帧听端口
}ZLNET_IVA_NET_CFG;

//人脸区域结构
typedef struct _ZLNET_IVA_ATM_FACEAREA
{
	int			maxsize;				//检测最大像素
	int			minsize;				//检测最小像素		
	int			left;
	int			top;
	int			right;
	int			bottom;
}ZLNET_IVA_ATM_FACEAREA;

//人脸检测区域
typedef struct _ZLNET_IVA_ATM_ALARMAREA_FACE
{
	int			size;	
	int			logicChn;					//逻辑通道号
	int			faceAreaNum;				//有效区域数
	ZLNET_IVA_ATM_FACEAREA	faceArea[ZLNET_IVA_MAX_NUM_FACE_AREA];
}ZLNET_IVA_ATM_ALARMAREA_FACE;


//ATM检测区域
typedef struct _ZLNET_IVA_ATM_DETECTAREA
{
	int			size;	
	int			logicChn;							//逻辑通道号
	int			alarmAreaNum;
	ZLNET_IVA_MONITORREGION detectArea[ZLNET_IVA_ATM_TOTAL];	//区域数组
}ZLNET_IVA_ATM_DETECTAREA;


//ATM配置参数
typedef struct _ZLNET_IVA_ATM_PARAM
{
	int			size;	
	int			waittime;				//等待报警时间
	int 		updatebk;				//更新背景时间
	int			camerablocked;			//摄像头遮挡报警时间
	int 		atmcamerathreold;		//ATM摄像头遮挡阀值
	int			operatorlong;			//长时间不操作时间
}ZLNET_IVA_ATM_PARAM;

//ATM异常人脸参数设置
typedef struct _ZLNET_IVA_ATM_ARNORMAL_FACE_PARAM
{
	int			size;	
	int			enable;					//使能
	int 		holdtime;				//遮挡持续时间
	int			tracktime;				//最大跟踪时间
	int			forebg;					//前景最小像素差阀值
	int			tagminarea;				//物体最小面积阀值
	int 		stillperfect;			//完全静止时间阀值
	int			stillness;				//人静止不动的最长时间阀值
	int			face;					//人脸检测阀值
	int 		facedetect;				//人脸检测敏感系数
	int 		alarm;					//持续报警
	int			score;					//分数阀值
}ZLNET_IVA_ATM_ARNORMAL_FACE_PARAM;

//视频颜色结构
typedef struct tagVIDEOCOLOR
{
	ZLNET_COLOR_CFG		dstColor;       // 画面颜色属性
	int					iEnable;        //时间段使能
	int					Res[5];         //预留
}ZLNET_IVA_VIDEOCOLOR;
//ATM人脸视频颜色参数
#define N_COLOR_SECTION 2
typedef struct tagCONFIG_VIDEOCOLOR
{
	ZLNET_IVA_VIDEOCOLOR dstVideoColor[N_COLOR_SECTION];//视频颜色结构
}ZLNET_IVA_ATM_CONFIG_VIDEOCOLOR;


// ATM报警查询日志
typedef struct _ZLNET_IVA_ATM_LOG
{
	DWORD     	size; 	 //结构体大小
	ZLNET_IVA_EVENT      IVSEvent;  //基本信息
	ZLNET_IVA_ATM_DETAIL IVSDetail; //详细信息
} ZLNET_IVA_ATM_LOG, *LPZLNET_IVA_ATM_LOG;

//智能报警使能
typedef struct _ZLNET_IVA_ALARM_ENABLE 
{
	int		size;
	int     nType;			//设备类型
	int     nSubType;
	int 	nAlarmEnable;	//ATM按位参看ZLNET_IVA_ATM_ALARM_ENABLE_MASK 周界参看ZLNET_IVA_BZS_ALARM_ENABLE_MASK 自助银行参看ZLNET_IVA_SSB_ALARM_ENABLE_MASK 人脸参看ZLNET_IVA_FACE_ALARM_ENABLE_MASK
}ZLNET_IVA_ALARM_ENABLE;

typedef struct _ZLNET_IVA_DEV_INFO
{	
	char	szDevSerialNo[ZLNET_DEV_SERIALNO_LEN];	//序列号
	char	szSoftWareVersion[ZLNET_VER_SOFTWARE];	//软件版本号
	DWORD		dwSoftwareBuildDate;				//软件BUILD
	BYTE		byVideoCaptureNum;					//视频口In数量
	BYTE		byVideoOutNum;						//视频口Out数量
	BYTE		byAudioCaptureNum;					//音频口In数量
	BYTE		byAudioOutNum;						//音频口Out数量
	BYTE		byAlarmInNum;						//报警In口数
	BYTE		byAlarmOutNum;						//报警Out口数
	BYTE		byTalkInChanNum;					//对讲口In数量
	BYTE		byTalkOutChanNum;					//对讲口Out数量
	BYTE		byNetIONum;							//网络口数
	BYTE		byComIONum;							//串口数量
	BYTE		byLPTIONum;							//并口数量	
	BYTE		byVideoStandard;					//视频制式:0-PAL,1-NTSC
}ZLNET_IVA_DEV_INFO;

// 自动维护配置
typedef struct _ZLNET_IVA_AUTOMAINTAIN
{
	BYTE				byAutoRebootDay;		// 自动重启；0：从不, 1：每天，2：每星期日，3：每星期一，......
	BYTE				byAutoRebootTime;		// 0：0:00，1：1:00，......23：23:00
} ZLNET_IVA_AUTOMAINTAIN;

// 注册IP网络配置
typedef struct _ZLNET_IVA_REGISTIP
{
	char				ip[ZLNET_MAX_IPADDR_LEN];				// IP
	int					port;									// 端口
	char				domainName[ZLNET_MAX_DOMAIN_NAME_LEN];	// dvr域名
}ZLNET_IVA_REGISTIP;

// 注册IP网络配置列表
typedef struct _ZLNET_IVA_CENTER_HOSTIP_LIST
{
	int validNum;		//有效个数
	ZLNET_IVA_REGISTIP hostIP[ZLNET_IVA_MAX_REGIST_NUM];
}ZLNET_IVA_REGISTIP_LIST;

// 在线用户信息
typedef struct _ZLNET_IVA_USER_ONLINE
{
	int				id;
	char				ip[ZLNET_MAX_IPADDR_LEN];		// IP
	char				name[ZLNET_USER_NAME_LENGTH_EX];	// 用户名称
}ZLNET_IVA_USER_ONLINE;

// 在线用户信息列表
typedef struct _ZLNET_IVA_USER_ONLINE_LIST
{
	int			validNum;		//有效个数
	ZLNET_IVA_ONLINE_OPRATE  opt;							// 操作类型
	int				blockTime;							// 屏蔽时间（当操作类型为ZLNET_IVA_ONLINE_BLOCK的时候有效）
	ZLNET_IVA_USER_ONLINE online[ZLNET_IVA_MAX_ONLINE];
}ZLNET_IVA_USER_ONLINE_LIST;

// 智能设备上传信息
typedef struct  _ZLNET_IVA_ZLNET_IVA_UPLOAD
{
	char				szDomainName[ZLNET_MAX_DOMAIN_NAME_LEN];	// 设备域名
	char				szIP[ZLNET_MAX_IPADDR_LEN];				// 设备IP地址
	int					nPort;									//设备端口号
	char				szSerial[ZLNET_DEV_SERIALNO_LEN];		//设备序列号
	char				szOccurTime[ZLNET_ALARM_OCCUR_TIME_LEN];	//上传时间
}ZLNET_IVA_ZLNET_IVA_UPLOAD;

//ATM算法调试
typedef struct _ZLNET_IVA_ARITHMETIC_DEBUG_ITEM
{
	int		size;			//结构体大小
	BOOL	bDebugInfo;		//调试信息
	BOOL	bTargetFrame;	//目标框
	BOOL	bRuleFrame;		//规则框
}ZLNET_IVA_ARITHMETIC_DEBUG_ITEM;

//算法调试
typedef struct _ZLNET_IVA_ARITHMETIC_DEBUG
{
	ZLNET_IVA_ARITHMETIC_DEBUG_ITEM arithDebug[ZLNET_IVA_ARITHMETIC_DEBUG_LEN];
}ZLNET_IVA_ARITHMETIC_DEBUG;

//配置OSD
typedef struct _ZLNET_IVA_OSD_CONFIG
{
	int		size;
	BOOL bTimeDisplay[ZLNET_IVA_MAX_CHANNEL];						//是否显示时间OSD，物理通道为准
	BOOL bChannelDisplay[ZLNET_IVA_MAX_CHANNEL];						//是否显示通道OSD，物理通道为准
	char szChannelName[ZLNET_IVA_MAX_CHANNEL][ZLNET_CHAN_NAME_LEN];	//通道名称，物理通道为准
}ZLNET_IVA_OSD_CONFIG;

//音频上传信息
typedef struct _AUDIO_UPLOAD_INFO
{
	ZLNET_IVA_ALARM_TYPE atmAlarmType;	//ATM报警类型
	int					channel;		//通道号
}ZLNET_AUDIO_UPLOAD_INFO;

//音频上传信息列表
typedef struct _ZLNET_IVA_AUDIO_UPLOAD_INFO 
{
	int nCount;
	ZLNET_AUDIO_UPLOAD_INFO pAudioInfo[ZLNET_IVA_AUDIO_UPLOAD_INFO_NUM];
}ZLNET_IVA_AUDIO_UPLOAD_INFO;
//智能视频报警调试
typedef struct _ZLNET_IVA_ALARM_DEBUG
{
	int		nATMWarns;       //已经报警的数量
	int		nATMBlocks;      //面板堵塞计数
	int		nProbeBlocks;    //人脸堵塞计数
	int		nFaceTrackID;    //人脸跟踪最新ID
	char	bATMProbe;		 //人脸视频中检测到人员
	char	bATMMoving;      //面板视频中检测到人员
	char	bATMHands;       //人员操作ATM机
}ZLNET_IVA_ALARM_DEBUG;


//车辆检测区域和车辆屏蔽区域
typedef struct _ZLNET_IVA_REGION
{
	int			size;	
	int			areaNum;									//有效区域数
	ZLNET_IVA_MONITORREGION detectArea[ZLNET_IVA_MAX_NUM_LICENSE_PLATE];	//区域数组
}ZLNET_IVA_REGION;

//OSD车牌参数配置
typedef struct _ZLNET_IVA_OSD_LICENSE_PALTE_PARAM
{
	int			size;						//结构体大小
	int			superimposedType;			//叠加方式
	int			superimposedX;				//叠加坐标x(像素)
	int			superimposedY;				//叠加坐标Y(像素)
	int			superimposedSize;			//叠加显示尺寸
	int			superimposedTime;			//叠加停留时间
}ZLNET_IVA_OSD_LICENSE_PALTE_PARAM;

//车牌参数配置
typedef struct _ZLNET_IVA_PLATEID_PARAM
{
	int			size;						//结构体大小
	int			IVSPlateIDSpringType;		//触发模式   0  视频模式  1  串口模式
	int			nMinPlateWidth;				//检测的最小车牌宽度，以像素为单位
	int			nMaxPlateWidth;				//检测的最大车牌宽度，以像素为单位
	int		    nConfigFlag;				//车牌检测设置,按位参见ZLNET_IVA_LICENSE_PLATE_TYPE
	int			nLocalProvince[3];			//本省车牌设置
	float		fSlantAngle;				//倾斜角度
}ZLNET_IVA_PLATEID_PARAM;

//车牌报警上传(日志+区域)
typedef struct _ZLNET_IVA_PLATEID_DETAIL
{
	BOOL		bAlarm;			//车辆是否逆行
	char		byLicense[16];	//车牌号字符形式表示
	unsigned char		byCharScore[16];//每个车牌号的分数
	ZLNET_ALARMRECT           rcCharPos[16];	//每个字符的位置
	int			nCharNum;				//车牌字符数				
	ZLNET_IVA_PLATEID_COLOR		nColor;			//车牌颜色
	ZLNET_IVA_PLATEID_TYPE			nType;		//车牌类型
	int			nConfidence;	//车牌检测分数
	int			nBright;		//亮度
	ZLNET_IVA_PLATEID_DRIVE			nDirection;	//车辆方向
	ZLNET_IVA_AREA_TYPE	nWhy;		//检测区域类型 0：无区域 8:车辆检测区域 9:车辆屏蔽区域
	ZLNET_ALARMRECT   rcLocation;	//车牌位置
	char		res[16];
} ZLNET_IVA_PLATEID_DETAIL;

//车牌报警上传日志+区域信息
typedef struct _ZLNET_IVA_PLATEID_ALARMINFO
{
	DWORD     	size; 	 //结构体大小
	ZLNET_IVA_EVENT      IVSEvent;  //基本信息
	ZLNET_IVA_PLATEID_DETAIL IVSDetail; //详细信息
	ZLNET_IVA_ALARMINFO_PIC pic[ZLNET_IVA_MAX_CHANNEL*2];	// 图片数据
}ZLNET_IVA_PLATEID_ALARMINFO;

//车牌查询日志
typedef struct _ZLNET_IVA_PLATEID_LOG
{
	DWORD     	size; 	 //结构体大小
	ZLNET_IVA_EVENT      IVSEvent;  //基本信息
	ZLNET_IVA_PLATEID_DETAIL IVSDetail; //详细信息
} ZLNET_IVA_PLATEID_LOG ;

typedef enum _ZLNET_HDCTTYPE
{
	HDCT_IN = 0 ,
	HDCT_OUT
}ZLNET_HDCTTYPE; 
//逆向行驶报警
typedef struct _ZLNET_IVA_PLATEID_ALARM
{
	int		size;							//结构体大小
	int		nEnable;						//报警使能
	int		nDirection;						//报警触发方向,按位参看ZLNET_IVA_REVERSE_DRIVE_SET
	int		nMinScore;						//报警上传最小分数
}ZLNET_IVA_PLATEID_ALARM;

//人数统计报警信息
typedef struct _ZLNET_HDCTRECT
{
	ZLNET_HDCTTYPE   type ;
	ZLNET_ALARMRECT  rect;
	int    nReserved[4];
} ZLNET_HDCRECT; 

//人员统计配置参数
typedef struct _ZLNET_IVA_STAFF_COUNT_CONFIG
{
	int			size;						//结构体大小
	int			nWidth;                     //检测区域宽度
	int			nHeight;                    //检测区域高度
	int			nObjWidth;                  //检测宽度
	ZLNET_IVA_POINT	ptStart;				    //区域起始点
	ZLNET_IVA_POINT	ptEnd;						//区域终点
	ZLNET_IVA_POINT	ptDirection;				//方向点
	int			nPassFrames;				//目标运动速度
	int			nMutiObjWidth;				//多目标宽度
	int			nMutiObjWidthEdge;         	//边缘宽度
	int			nThreshBackDiff;			//背景差阈值
	int			nThreshFrameDiff;			//帧间差阈值
	int			bStartPtLabel;              //Start端抑制
	int			bEndPtLabel;                //End端抑制
	int			nHalfObjW;                  //抑制宽度
} ZLNET_IVA_STAFF_COUNT_CONFIG;

//人员统计详细信息
typedef struct _ZLNET_IVA_STAFFCOUNT_DETAIL
{
	int 			numRegion;     //区域个数
	ZLNET_IVA_HDCRECT	 		region[20] ;   //区域信息
	unsigned int 	totalInCount ;		//从设备启动到当前时间总共进入的人数
	unsigned int 	totalOutCount ;		//从设备启动到当前时间总共离开的人数  
	int 			flag;   			// 标记，如果设备或算法重启，该标记将发生变化,-1表示该参数无效
	int     		nInCount; 	 //进入人数
	int     		nOutCount; 	 //离开人数
	int 			reserve[14];
} ZLNET_IVA_STAFFCOUNT_DETAIL ;

//人员统计日志信息
typedef struct _ZLNET_IVA_STAFFCOUNT_LOG
{
	DWORD     	size; 	 //结构体大小
	ZLNET_IVA_EVENT      IVSEvent;  //基本信息
	ZLNET_IVA_STAFFCOUNT_DETAIL IVSDetail; //详细信息
} ZLNET_IVA_STAFFCOUNT_LOG ;

//人员统计上传日志+区域信息+图片
typedef struct _ZLNET_IVA_STAFFCOUNT
{
	DWORD     	size; 	 //结构体大小
	ZLNET_IVA_EVENT      IVSEvent;  //基本信息
	ZLNET_IVA_STAFFCOUNT_DETAIL IVSDetail; //详细信息
	ZLNET_IVA_ALARMINFO_PIC pic[ZLNET_IVA_MAX_CHANNEL*2];	// 图片数据
}ZLNET_IVA_ALARMINFO_STAFFCOUNT;

//人数统计算法调试结构体
typedef struct _ZLNET_IVA_STAFF_ARITH_DEBUG 
{
	int			numRegion;     //区域个数
	ZLNET_IVA_HDCRECT    region[20] ;   //区域信息
	int     	nInCount; 	 //进入人数
	int     	nOutCount; 	 //离开人数
}ZLNET_IVA_STAFF_ARITH_DEBUG;

//人数统计多人报警参数
typedef struct _ZLNET_IVA_STAFF_MULTIUSERPARAM 
{
	int  nSize;
	int  nNum;        //多人报警下限
	int  nReserved[8];
}ZLNET_IVA_STAFF_MULTIUSERPARAM;

//周界防范参数设置

//算法区域
typedef struct _ZLNET_IVA_BZS_REGION
{
	int			size;	
	int			areaNum;										//有效区域数
	ZLNET_IVA_MONITORREGION detectArea[ZLNET_IVA_MAX_BZS_PROCESS_NUM];	//区域数组
}ZLNET_IVA_BZS_REGION;

//算法基本设置
typedef struct _ZLNET_IVA_BZS_BASIC_SETTIINGS
{
	int			 nSize;									//结构体大小
	int			 nWidth;								//检测区域宽度
	int			 nHeight;								//检测区域高度
	int 		 nForegroundTh;							//前景差阈值

	ZLNET_IVA_BZS_REGION pPolygonNoProc;				//处理区域(1)

	int 		 nObjHeight;							//高度标尺
	BOOL		 bImgTransform;							//是否校正图像
	float		 fTransformParam[9];					//校正图像参数
	float		 fTransformParamInv[9];					//校正图像反转参数
} ZLNET_IVA_BZS_BASIC_SETTIINGS;

//功能参数设置

//算法参数设置
typedef struct _ZLNET_IVA_BZS_ALGORITHM_PARAM
{
	int	    nSize;							//结构体大小
	int		nCmd;							//0忽略 !0重启算法

	/*丢包参数设置*/
	int		nMinSizeWidthHeight;			//物体最小宽度和高度
	int		nMaxRectArea;					//物体最大外包面积
	int		nMinForegroundArea;				//最小占有前景像素点数
	int		nThresholdTime;					//持续多长时间报警

	/*徘徊参数设置*/
	int		nThresholdBlockCntLingering;	//总的移动距离
	int		nStayingFrameTh;				//总的逗留时间

	/*多人聚集参数设置*/
	int		nThresholdMultiPeoPersonCnt;	//报警人数
	int		nThresholdMultiPeoFGPercent;	//前景面积百分比
	int		nWarningIntervalFrmsMultiPeo;	//两次报警间隔
	int		nThresholdMultiPeoFrmCnt;		//确认报警阈值

	/*剧烈运动检测*/
	int		nTHresholdFastMove;				//灵敏度（1~100）
	int		nWarningIntervalFrmsFastMove;	//两次报警间隔
} ZLNET_IVA_BZS_ALGORITHM_PARAM;

//摄像机异常参数设置
typedef struct _ZLNET_IVA_BZS_CAMERA_ABNORMAL_PARAM
{
	int		nSize;					//结构体大小
	BOOL	bDetectBright;			//亮度异常开关
	BOOL	bDetectNoSignal;		//信号丢失开关
	BOOL	bDetectBlock;			//视频遮挡开关
	BOOL	bDetectColor;			//色彩异常开关
	BOOL	bDetectBlur;			//画面模糊开关
	BOOL	bDetectNoise;			//图像噪声开关

	int		nBrightSensitivity;		//亮度异常灵敏度
	int		nNoSignalSensitivity;	//信号丢失灵敏度
	int		nBlockSensitivity;		//视频遮挡灵敏度
	int		nColorSensitivity;		//色彩异常灵敏度
	int		nBlurSensitivity;		//画面模糊灵敏度
	int		nNoiseSensitivity;		//图像噪声灵敏度

	int		nAlarmDurationTh;		//报警持续时间阈值
	int  	nBrightTh;				//镜头遮挡亮度阈值
} ZLNET_IVA_BZS_CAMERA_ABNORMAL_PARAM;

//报警规则设置
//区域及盗移
typedef struct _ZLNET_IVA_BZS_AREA_DETECT
{
	int					nSize;					// 结构体大小
	BOOL				bEnable;				// 使能
	int					nSerial;				// 区域序号
	int					nRegionMask;     		// 区域类型掩码，参看ZLNET_IVA_BZS_AREA_ALARM_MASK
	ZLNET_IVA_MONITORREGION  pynPos;			// 区域位置
	int					nFramesConfirmEnter;  	// 进入区域时间
	int					nFramesConfirmLeave;	// 离开区域时间
	int					nFramesConfirmTouch;	// 触及区域时间
	int					nFramesConfirmObjMove;	// 盗移动区域时间
	int					nFramesConfirmLinger;	// 徘徊时间
	int					nFramesConfirmAppear;	// 出现时间
	int					nFramesConfirmDisappear;// 消失时间
	char			    chMemo[64];				// 备注
} ZLNET_IVA_BZS_AREA_DETECT;

typedef struct _ZLNET_IVA_BZS_AREA_DETECT_PARAM
{
	int					nSize;					// 结构体大小
	int				    nValidNum;				// 有效个数
	ZLNET_IVA_BZS_AREA_DETECT areaDetect[ZLNET_IVA_MAX_BZS_RULE_REGION];
} ZLNET_IVA_BZS_AREA_DETECT_PARAM_PARAM;

//单线规则
typedef struct _ZLNET_IVA_BZS_CROSS_0NE_LINE
{
	int				  nSize;					// 结构体大小
	BOOL			  bEnable;					// 使能
	int				  nSerial;					// 区域序号
	int				  nLineMask;   				// 跨线使能掩码，参看ZLNET_IVA_BZS_CROSS_LINE_MASK
	ZLNET_IVA_POINT   ptStart;					// 跨线起始点
	ZLNET_IVA_POINT   ptEnd;					// 跨线终点
	ZLNET_IVA_POINT   ptDriection;				// 跨线方向点(双向传正向点)
	int				  nFramesConfirmCrossOneWay;// 单向跨线确认时长
	int 		      nFramesConfirmCrossTwoWay;// 双向跨线时长
	int 			  nFramesConfirmTouchOneWay;// 正向触线时间
	int 			  nFramesConfirmTouchTwoWay;// 反向触线时间
	char			  chMemo[64];				// 备注
} ZLNET_IVA_BZS_CROSS_0NE_LINE;

typedef struct _ZLNET_IVA_BZS_CROSS_0NE_LINE_PARAM
{
	int				  nSize;					// 结构体大小
	int				  nValidNum;				// 有效个数
	ZLNET_IVA_BZS_CROSS_0NE_LINE oneLine[ZLNET_IVA_MAX_BZS_RULE_REGION];
} ZLNET_IVA_BZS_CROSS_0NE_LINE_PARAM;

//双线规则
typedef struct _ZLNET_IVA_BZS_CROSS_TWO_LINE
{
	int				  nSize;					// 结构体大小
	BOOL			  bEnable;					// 使能
	int				  nSerial;					// 区域序号
	ZLNET_IVA_POINT   ptPredictStart;			// 预测双线起始点
	ZLNET_IVA_POINT   ptPredictEnd;				// 预测双线终点
	ZLNET_IVA_POINT   ptPredictDirection;		// 预测方向点
	ZLNET_IVA_POINT   ptDecideStart;			// 确认双线起始点
	ZLNET_IVA_POINT   ptDecideEnd;				// 确认双线终点	
	ZLNET_IVA_POINT   ptDecideDirection;		// 确认双方向点
	int				  nFramesConfirmClimb;		// 跨线时间
	char			  chMemo[64];				// 备注
} ZLNET_IVA_BZS_CROSS_TWO_LINE;

typedef struct _ZLNET_IVA_BZS_CROSS_TWO_LINE_PARAM
{
	int				  nSize;					// 结构体大小
	int				  nValidNum;				// 有效个数
	ZLNET_IVA_BZS_CROSS_TWO_LINE twoLine[ZLNET_IVA_MAX_BZS_RULE_REGION];
} ZLNET_IVA_BZS_CROSS_TWO_LINE_PARAM;

//自助银行

//区域结构
typedef struct _ZLNET_IVA_SELF_BANK_REGION
{
	int			size;	
	int			areaNum;										//有效区域数
	ZLNET_IVA_MONITORREGION detectArea[ZLNET_IVA_MAX_SSB_AREA];	//区域数组
} ZLNET_IVA_SSB_REGION;

//自助厅功能配置
typedef struct _ZLNET_IVA_SSB_HALL_FUNC
{
	int			 nSize;										//结构体大小
	int			 nWidth;									//检测区域宽度
	int			 nHeight;									//检测区域高度
	int 		 nForegroundTh;								//前景差阈值
	ZLNET_IVA_SSB_REGION PolygonNoProc;						//处理区域(1) + 屏蔽区域(9) + 操作区域(10)
	int 		 nObjHeight;								//高度标尺
	BOOL		 bImgTransform;								//是否校正图像
	float		 fTransformParam[9];						//校正图像参数
	float		 fTransformParamInv[9];						//校正图像反转参数
} ZLNET_IVA_SSB_HALL_FUNC;

//自助厅异常检测参数
typedef struct _ZLNET_IVA_SSB_ABNORMAL_PARAM
{
	int         nSize;
	int			nCmd;					// 0、忽略 1、算法重启

	// 遗留物参数
	int   		nMinSizeWidthHeight;	//包的最小大小（高度或者宽度）
	int   		nMaxRectArea;			//物体最大外包矩形面积
	int    		nMinForegroundArea;		//最小占有前景像素点个数
	int   		nThresholdTime;			//持续多长时间报警（秒）

	// 徘徊参数
	int     	nTotaolDisLingering;	//徘徊移动的距离
	int   		nTotalStayingTime;		//总的逗留时间
	int    		nTotalStayInterval;		//逗留时间的间隔

	// 多人参数
	int			nGatherNum;				//聚集人数
	int			nWarningInterval;		//两次聚集的间隔时间
	int			nTotalMultiPeoTime;		//总的聚集时间

	// 人员倒地参数
	int			nTotalFellTime;		    //总的倒下时间

	// 尾随取款
	int			nStatAtmSideTime;	    //停留在ATM附近的持续时间
	int			nIntervalAlarm;		    //两次报警的间隔

	// 禁止区域
	int			nInForbiddenAreaTime;   //进入禁止区域的持续时间

	// 打架事件进入相关
	int			nTotalFightingTime;	    //打架持续时间
	int			nIntervalFighting;	    //两次打架报警间隔
	int			nFightThInFrame;		//帧内判定报警的阈值,越小越容易报100 (0-256)
	int			nFightThInFramePixel;   //越小越容易报，报警等级2(1/2/3/4)
	BOOL		bBottomRule;		    //是否采用底部约束，用于图像下方为进入区域的情况，默认为1
	BOOL		bHeightChangeRule;	    //是否采用高度变化约束：要求物体的高度有起伏变化，如果物体充满图像，该约束置为0，默认为1
	int 		nFrameGrayChangeTh;	    //帧间变化灰度阈值30(1-250)
	BOOL		bUnused;			    //0
	int			reserved[7];
} ZLNET_IVA_SSB_ABNORMAL_PARAM;

//摄像头异常检测参数
typedef struct _ZLNET_IVA_SSB_CAMERE_ABNORMAL
{
	int     nSize;					//参数大小
	BOOL	bDetectBright;			//亮度异常 使能
	BOOL	bDetectNoSignal;		//信号丢失 使能
	BOOL	bDetectBlock;			//视频遮挡 使能
	BOOL	bDetectColor;			//色彩异常 使能
	BOOL	bDetectBlur;			//画面模糊 使能
	BOOL	bDetectNoise;			//图像噪声 使能

	int		nBrightSensitivity;		//亮度异常 灵敏度
	int		nNoSignalSensitivity;	//信号丢失 灵敏度
	int		nBlockSensitivity;		//视频遮挡 灵敏度
	int		nColorSensitivity;		//色彩异常 灵敏度
	int		nBlurSensitivity;		//画面模糊 灵敏度
	int		nNoiseSensitivity;		//图像噪声 灵敏度

	int		nAlarmDurationTh;		//报警持续时间
	int		nBrightTh;				//镜头遮挡亮度阈值
} ZLNET_IVA_SSB_CAMERE_ABNORMAL;

//加钞间算法参数
typedef struct _ZLNET_IVA_SSB_ROOM_PARAM
{
	int			 nSize;					//结构体大小
	ZLNET_IVA_SSB_REGION PolygonNoProc;	//处理区域（1） + 禁止区域（9）
	int			 nThFg;				//前景阈值，15为推荐值
	int			 nThArea;			//移动的区域占总区域的百分之几，25为推荐值
	int			 nWarningInterval;  //报警间隔，15s*帧率为推荐值
	int			 nNoProcess;		//禁止区域个数
} ZLNET_IVA_SSB_ROOM_PARAM;


//SSB报警事件详细信息
typedef struct _ZLNET_IVA_SSB_DETAIL
{
	DWORD    alarmNo;	//区域个数
	ZLNET_IVA_RECTINFO   alarmRect[ZLNET_IVA_MAX_NUM_SSBALARM];     // 区域
	BYTE      reserve[16];  //保留
}ZLNET_IVA_SSB_DETAIL; //报警信息结构体

//SSB报警信息
typedef struct _ZLNET_IVA_SSB_ALARMINFO
{
	DWORD         size;     //结构体大小
	ZLNET_IVA_EVENT      IVSEvent;  //基本信息
	ZLNET_IVA_SSB_DETAIL IVSDetail; //详细信息
	ZLNET_IVA_ALARMINFO_PIC pic[ZLNET_IVA_MAX_CHANNEL*2];	// 图片数据
}ZLNET_IVA_SSB_ALARMINFO;

//BZS报警事件详细信息
typedef struct _ZLNET_IVA_BZS_DETAIL
{
	DWORD    alarmNo;	//区域个数
	ZLNET_IVA_RECTINFO   alarmRect[8];     // 区域
	char      strMemo[64];  //区域说明
}ZLNET_IVA_BZS_DETAIL; //报警信息结构体

//BZS报警信息
typedef struct _ZLNET_IVA_BZS_ALARMINFO
{
	DWORD         size;     //结构体大小
	ZLNET_IVA_EVENT      IVSEvent;  //基本信息
	ZLNET_IVA_BZS_DETAIL IVSDetail; //详细信息
	ZLNET_IVA_ALARMINFO_PIC pic[ZLNET_IVA_MAX_CHANNEL*2];	// 图片数据
}ZLNET_IVA_BZS_ALARMINFO;

//SSB查询日志
typedef struct _ZLNET_IVA_SSB_LOG
{
	DWORD     	size; 	 //结构体大小
	ZLNET_IVA_EVENT      IVSEvent;  //基本信息
	ZLNET_IVA_SSB_DETAIL IVSDetail; //详细信息
} ZLNET_IVA_SSB_LOG;

//BZS查询日志 
typedef struct _ZLNET_IVA_BZS_LOG
{
	DWORD     	size; 	 //结构体大小
	ZLNET_IVA_EVENT      IVSEvent;  //基本信息
	ZLNET_IVA_BZS_DETAIL IVSDetail; //详细信息
} ZLNET_IVA_BZS_LOG;

//SSB跟踪信息的结构体：可以叠加跟踪框
typedef struct _ZLNET_IVA_SSB_TRACKEDINFO
{
	ZLNET_ALARMRECT rcObjectPos;	//在这一帧中，跟踪物体的位置（矩形：left,right,top,buttom）
	int				nTrackID;		//跟踪物体ID
	int				nType;			// 0:消失 1:显示
} ZLNET_IVA_SSB_TRACKEDINFO;

typedef struct _ZLNET_IVA_SSB_ARITH_DEBUG
{
	DWORD            DebugNo;
	ZLNET_IVA_SSB_TRACKEDINFO  DebugInfo[MAX_NUM_SSB_TRACKEDINFO];
} ZLNET_IVA_SSB_ARITH_DEBUG;

//BZS跟踪信息的结构体：可以叠加跟踪框
typedef struct _ZLNET_IVA_BZS_TRACKEDINFO
{
	ZLNET_ALARMRECT rcObjectPos;	//在这一帧中，跟踪物体的位置（矩形：left,right,top,buttom）
	int				nTrackID;		//跟踪物体ID
	int				nType;			// 0:消失 1:显示
} ZLNET_IVA_BZS_TRACKEDINFO;

//BZS算法调试信息
typedef struct _ZLNET_IVA_BZS_ARITH_DEBUG
{
	DWORD            DebugNo;
	ZLNET_IVA_BZS_TRACKEDINFO  DebugInfo[MAX_NUM_SSB_TRACKEDINFO];
} ZLNET_IVA_BZS_ARITH_DEBUG;

//BZS轨迹跟踪元素
typedef struct _ZLNET_IVA_BZS_TRACK
{
	DWORD nTrackID;   //跟踪物体ID
	WORD  nPosX;	  //x坐标
	WORD  nPosY;	  //y坐标  当nPosX和nPosY都为0的时候代表一个物体轨迹跟踪结束
}ZLNET_IVA_BZS_TRACK; 

//BZS轨迹跟踪
typedef struct _ZLNET_IVA_BZS_TRACK_INFO
{
	DWORD  nTrackNum;                                  //有效个数
	ZLNET_IVA_BZS_TRACK stTrackInfo[MAX_TRACK_COUNT];  //BZS轨迹跟踪元素
}ZLNET_IVA_BZS_TRACK_INFO;



//背景更新
typedef struct _ZLNET_IVA_RESTART_ALGORITHM
{
	int nSize;				//结构体大小
	int nBackgroundUpdate;	//背景更新命令，按位参看ZLNET_IVA_BACKGROUND_UPDATE_MASK
	int nReserved[2];		//保留
} ZLNET_IVA_BACKGROUND_UPDATE;

//设备能力获取
typedef struct _ZLNET_DEVICE_ENABLE
{
	int nSize;
	char szDevType[ZLNET_DEV_TYPE_LEN];								//设备类型
	char szEn[ZLNET_DEVICE_ENABLE_NUM][ZLENT_DEVICE_ENABLE_STR_LEN];//主要能力(支持64项)
	DWORD dwEnMask[ZLNET_DEVICE_ENABLE_NUM];						//主要能力掩码
	BYTE  bResverd[28];												//预留
} ZLNET_DEVICE_ENABLE;

//智能人脸

//区域
typedef struct _ZLNET_IVA_FACE_AREA
{
	int				nMinFace;	//检测最小像素
	int				nMaxFace;	//检测最大像素
	ZLNET_ALARMRECT	area;		//矩形区域
} ZLNET_IVA_FACE_AREA;

//人脸检测结果
typedef struct _ZLNET_IVA_FACE_TRACK_INFO
{
	ZLNET_ALARMRECT position;		//检测区域
	int				nConfidence;	//检测分数，分数越高画质越清晰
	int				nTrackID;		//检测ID
} ZLNET_IVA_FACE_TRACK_INFO;

//人脸报警事件详细信息
typedef struct _ZLNET_IVA_FACE_DETAIL
{
	DWORD    alarmNo;	//区域个数
	ZLNET_IVA_FACE_TRACK_INFO   alarmRect[ZLNET_IVA_MAX_NUM_FACEALARM];     // 区域
	BYTE      reserve[16];  //保留
}ZLNET_IVA_FACE_DETAIL;

//人脸报警事件
typedef struct _ZLNET_IVA_FACE_ALARMINFO
{
	DWORD     	size; 	 //结构体大小
	ZLNET_IVA_EVENT      IVSEvent;  //基本信息
	ZLNET_IVA_FACE_DETAIL IVSDetail; //详细信息
	ZLNET_IVA_ALARMINFO_PIC pic[ZLNET_IVA_MAX_CHANNEL*2];	// 图片数据
} ZLNET_IVA_FACE_ALARMINFO ;

//人脸报警日志信息
typedef struct _ZLNET_IVA_FACE_LOG
{
	DWORD     	size; 	 //结构体大小
	ZLNET_IVA_EVENT      IVSEvent;  //基本信息
	ZLNET_IVA_FACE_DETAIL IVSDetail; //详细信息
} ZLNET_IVA_FACE_LOG ;

//检测区域参数
typedef struct _ZLNET_IVA_FACE_AREA_PARAM
{
	int					nSize;		//大小
	int					nValidNum;	//有效个数
	ZLNET_IVA_FACE_AREA faceArea[ZLNET_IVA_MAX_FACE_AREA_NUM];	//区域个数
	int                 nNoProcNum;                      //屏蔽区域个数
	ZLNET_ALARMRECT          noProcArea[ZLNET_IVA_MAX_FACE_SHIELDED_AREA_NUM];
} ZLNET_IVA_FACE_AREA_PARAM;

//人脸检测参数
typedef struct _ZLNET_IVA_FACE_DETECT_PARAM
{
	int								nSize;			//大小
	int								nChannel;		//通道
	int								nIntervalTime;	//抓拍间隔
	ZLNET_IVA_FACE_CAPTURE_MODE		nModeType;		//捕获模式 参看ZLNET_IVA_FACE_CAPTURE_MODE
	int								nScore;        //检测结果最低分数(低于此分数的结果将不被上传)
} ZLNET_IVA_FACE_DETECT_PARAM;

//人脸叠加参数
typedef struct _ZLNET_IVA_FACE_OVERLAY_PARAM
{
	int								nSize;			//大小
	int     						nChannel;       //通道
	int								nOverlayTime;	//叠加停留时间
	ZLNET_IVA_FACE_OVERLAY_MODE		nOverlayMode;	//叠加方式 参看ZLNET_IVA_FACE_OVERLAY_MODE
	ZLNET_ALARMRECT					position;		//叠加区域
} ZLNET_IVA_FACE_OVERLAY_PARAM;

//人脸算法调试结构体
typedef struct _ZLNET_IVA_FACE_ARITH_DEBUG
{
	DWORD		nTrackInfo;		//个数
	ZLNET_IVA_FACE_TRACK_INFO trackInfo[ZLNET_IVA_MAX_NUM_FACE_TRACKEDINFO]; //调试结果
} ZLNET_IVA_FACE_ARITH_DEBUG;

// DVR反向连接
//单个服务器连接信息
typedef struct 
{
	char	ip[ZLNET_MAX_DOMAIN_NAME_LEN];		//连接的服务器地址
	int		port;			//服务器端口
	long	linkcount;		//连接次数 0: 断开 0xffffffff: 一直连接, 直到成功为止
	int		res[20];		//预留
}ZLNET_REV_LINK_INFO;

// 服务器连接信息
typedef struct
{
	int		validcount;		//有效个数
	ZLNET_REV_LINK_INFO		info[ZLNET_MAX_REV_LIST - 1];//连接信息
	int		res[20];		//预留
}ZLNET_REV_LINK;

// 设备通知信息
typedef struct
{
	char	ip[ZLNET_MAX_DOMAIN_NAME_LEN];	//连接的服务器地址
	int     port;			//端口号
	int		ret;			//连接返回结果 0:成功 -1:超过尝试连接次数 -2:设备断开 -3:设备连接达到最大值
	int		res[20];		//预留
}ZLNET_REV_LINK_RET;

//IPCP详细信息
typedef struct
{
	int		nChn;		//通道数量
	char*	szSerial;	//序列号
	char*	szUserName;	//IPCP 用户名
	char*	szPWD;		//IPCP 密码
}ZLNET_EXTERN_INFO;

/************************************************************************
 ** 回调函数定义
 ***********************************************************************/

//心跳回调
typedef int (CALLBACK *fZLIDVRHeatBeat)( int loginHandle, const char* ip, const char* serial, unsigned long userData);

// 网络连接断开回调函数原形
typedef void (CALLBACK *fZLDisConnect)(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser);

// 网络连接恢复回调函数原形
typedef void (CALLBACK *fZLHaveReConnect)(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser);

// 动态子连接断开回调函数原形
typedef void (CALLBACK *fZLSubDisConnect)(ZLNET_INTERFACE_TYPE emInterfaceType, BOOL bOnline, LONG lOperateHandle, LONG lLoginID, DWORD dwUser);

// 实时监视数据回调函数原形
typedef void (CALLBACK *fZLRealDataCallBack)(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, DWORD dwUser);

// 实时监视数据回调函数原形--扩展
typedef void (CALLBACK *fZLRealDataCallBackEx)(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LONG param, DWORD dwUser);

// 屏幕叠加回调函数原形
typedef void (CALLBACK *fZLDrawCallBack)(LONG lLoginID, LONG lPlayHandle, HDC hDC, DWORD dwUser);

// 回放数据回调函数原形
typedef int (CALLBACK *fZLDataCallBack)(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, DWORD dwUser);

// 回放进度回调函数原形
typedef void (CALLBACK *fZLDownLoadPosCallBack)(LONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, DWORD dwUser);

// 按时间回放进度回调函数原形
typedef void (CALLBACK *fZLTimeDownLoadPosCallBack) (LONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, int index, ZLNET_RECORDFILE_INFO recordfileinfo, DWORD dwUser);

// 消息回调函数原形
typedef BOOL (CALLBACK *fZLMessCallBack)(LONG lCommand, LONG lLoginID, char *pBuf, DWORD dwBufLen, char *pchDVRIP, LONG nDVRPort, DWORD dwUser);

// 侦听服务器回调函数原形
// 反向注册的返回信息pParam指向一个ZLNET_EXTERN_INFO的结构体(SDK内部命名为AFK_EXTERN_INFO)
typedef int (CALLBACK *fZLServiceCallBack)(LONG lHandle, char *pIp, WORD wPort, LONG lCommand, void *pParam, DWORD dwParamLen, DWORD dwUserData);

// 语音对讲的音频数据回调函数原形
typedef void (CALLBACK *pfZLAudioDataCallBack)(LONG lTalkHandle, char *pDataBuf, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser);

// 升级设备程序回调函数原形
typedef void (CALLBACK *fZLUpgradeCallBack) (LONG lLoginID, LONG lUpgradechannel, int nTotalSize, int nSendSize, DWORD dwUser);

// 透明串口回调函数原形
typedef void (CALLBACK *fZLTransComCallBack) (LONG lLoginID, LONG lTransComChannel, char *pBuffer, DWORD dwBufSize, DWORD dwUser);

// 查询设备日志数据回调函数原形
typedef void (CALLBACK *fZLLogDataCallBack)(LONG lLoginID, char *pBuffer, DWORD dwBufSize, DWORD nTotalSize, BOOL bEnd, DWORD dwUser);

// 抓图回调函数原形
typedef void (CALLBACK *fZLSnapRev)(LONG lLoginID, BYTE *pBuf, UINT RevLen, UINT EncodeType, DWORD CmdSerial, DWORD dwUser);

// GPS信息订阅回调
typedef void (CALLBACK *fZLGPSRev)(LONG lLoginID, ZLNET_GPS_Info GpsInfo, DWORD dwUserData);

// 异步数据回调
typedef void (CALLBACK *fZLMessDataCallBack)(LONG lCommand, LPZLNET_CALLBACK_DATA lpData, DWORD dwUser);

// 文件传输回调
typedef void (CALLBACK *fZLTransFileCallBack)(LONG lHandle, int nTransType, int nState, int nSendSize, int nTotalSize, DWORD dwUser);

//报警视频接收回调函数
typedef int (CALLBACK *fidvrDownLoadVideoCallback)( LONG lRealHandle, ZLNET_IVA_ALARMVIDEOTYPE type,  const void* videoBuf, unsigned long videoBufLen , DWORD userData );

//ATM报警调试回调函数
typedef void (CALLBACK *fZLAlarmDebugRevCallback)(long ILongID, int nATMIndex, ZLNET_IVA_ALARM_DEBUG Debug,unsigned long dwuser);

//人数统计报警调试回调函数
typedef void (CALLBACK *fZLAlarmDebugStaffRevCallback)(long ILongID, int nSCIndex, ZLNET_IVA_STAFF_ARITH_DEBUG Debug, unsigned long dwuser);

//SSB报警调试回调函数
typedef void (CALLBACK *fZLAlarmDebugSSBRevCallback)(long ILongID, int nSSBIndex, ZLNET_IVA_SSB_ARITH_DEBUG Debug,unsigned long dwuser);

//BZS报警调试回调函数
typedef void (CALLBACK *fZLAlarmDebugBZSRevCallback)(long ILongID, int nBZSIndex, ZLNET_IVA_BZS_ARITH_DEBUG Debug,unsigned long dwuser);

//BZS跟踪轨迹信息
typedef void (CALLBACK *fZLBZSTrackInfoCallback)(long ILongID, int nBZSIndex, ZLNET_IVA_BZS_TRACK_INFO Debug,unsigned long dwuser);

//人脸报警调试回调函数
typedef void (CALLBACK *fZLAlarmDebugFaceRevCallback)(long ILongID, int nFaceIndex, ZLNET_IVA_FACE_ARITH_DEBUG Debug,unsigned long dwuser);

//智能人数统计信息、图片回调函数
typedef int (CALLBACK *fIdvrAlarmUpStaffCountCallback)( int loginHandle, ZLNET_IVA_ALARMINFO_STAFFCOUNT* info, DWORD userData );

//智能车牌信息上传回调函数
typedef int (CALLBACK *fIdvrAlarmUpPlateIdCallback)( int loginHandle, ZLNET_IVA_PLATEID_ALARMINFO*  info, DWORD userData);

//智能ATM报警日志、图片回调函数
typedef int (CALLBACK *fIdvrAlarmUpATMCallback)( int loginHandle, ZLNET_IVA_ATM_ALARMINFO*  info, DWORD userData);

//智能SSB报警
typedef int (CALLBACK *fIdvrAlarmUpSSBCallback)( int loginHandle, ZLNET_IVA_SSB_ALARMINFO*  info, DWORD userData);

//智能BZS报警
typedef int (CALLBACK *fIdvrAlarmUpBZSCallback)( int loginHandle, ZLNET_IVA_BZS_ALARMINFO*  info, DWORD userData);

//智能人脸报警
typedef int (CALLBACK *fIdvrAlarmUpFaceCallback)( int loginHandle, ZLNET_IVA_FACE_ALARMINFO*  info, DWORD userData);

//智能报警视频接收回调函数
typedef int (CALLBACK *fIdvrAlarmUpVideoCallback)( int loginHandle, DWORD id, ZLNET_TIME Time, ZLNET_IVA_ALARMVIDEOTYPE type,  int chn, const void* videoBuf, unsigned long videoBufLen , DWORD userData );

//上传音频文件进度回调函数
typedef void (CALLBACK *fIDdvrUploadPosCallBack)(LONG lUploadHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, DWORD dwUser);

//NVR搜索设备回调
typedef void (CALLBACK *fZLNVRSearch)(LONG lLoginID, ZLNET_NVR_SEARCHINFO* Info, DWORD dwUserData);

//反向注册通知信息回调
typedef void (CALLBACK *fZLRevLink)(LONG lLoginID, ZLNET_REV_LINK_RET* Info, DWORD dwUserData);

/************************************************************************
 ** 接口定义
 ***********************************************************************/

// SDK初始化
ZLNET_API BOOL CALL_METHOD ZLNET_Init(fZLDisConnect cbDisConnect, DWORD dwUser);

//设置心跳回调
ZLNET_API void CALL_METHOD ZLNET_SetHeartBeatCallBack(fZLIDVRHeatBeat cbHeartBeat,DWORD dwUser);

// SDK退出清理
ZLNET_API void CALL_METHOD ZLNET_Cleanup();

//------------------------------------------------------------------------

// 设置断线重连成功回调函数，设置后SDK内部断线自动重连
ZLNET_API void CALL_METHOD ZLNET_SetAutoReconnect(fZLHaveReConnect cbAutoConnect, DWORD dwUser);

// 设置动态子连接断线回调函数，目前SVR设备的监视和回放是短连接的。
ZLNET_API void CALL_METHOD ZLNET_SetSubconnCallBack(fZLSubDisConnect cbSubDisConnect, DWORD dwUser);

// 返回函数执行失败代码
ZLNET_API DWORD CALL_METHOD ZLNET_GetLastError(void);

// 设置连接设备超时时间和尝试次数
ZLNET_API void CALL_METHOD ZLNET_SetConnectTime(int nWaitTime, int nTryTimes);

// 设置登陆网络环境
ZLNET_API void CALL_METHOD ZLNET_SetNetworkParam(ZLNET_PARAM *pNetParam);

// 获取SDK的版本信息
ZLNET_API DWORD CALL_METHOD ZLNET_GetSDKVersion();

//------------------------------------------------------------------------

// 向设备注册
ZLNET_API LONG CALL_METHOD ZLNET_Login(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, LPZLNET_DEVICEINFO lpDeviceInfo, int *error = 0);

// 扩展接口；nSpecCap = 0为TCP方式下的登入，nSpecCap = 2为主动注册的登入，nSpecCap = 3为组播方式下的登入，nSpecCap = 4为UDP方式下的登入，nSpecCap = 6为只建主连接下的登入，nSpecCap = 7为SSL加密
ZLNET_API LONG CALL_METHOD ZLNET_LoginEx(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, int nSpecCap, void* pCapParam, LPZLNET_DEVICEINFO lpDeviceInfo, int *error = 0);

// 向设备注销
ZLNET_API BOOL CALL_METHOD ZLNET_Logout(LONG lLoginID);

ZLNET_API LONG CALL_METHOD ZLNET_GetIPByDDNSID(char *szServerIp, int nServerPort, char *ddnsID, char* szRetIP, int *pHttpPort, int *pTcpPort, int *pErrorCode);

//------------------------------------------------------------------------

// 开始实时监视
ZLNET_API LONG CALL_METHOD ZLNET_RealPlay(LONG lLoginID, int nChannelID, HWND hWnd);

// 开始实时监视--扩展
ZLNET_API LONG CALL_METHOD ZLNET_RealPlayEx(LONG lLoginID, int nChannelID, HWND hWnd, ZLNET_RealPlayType rType = ZLNET_RType_Realplay);

// 多画面实时预览
ZLNET_API LONG CALL_METHOD ZLNET_MultiPlay(LONG lLoginID, HWND hWnd);

// 停止多画面实时预览
ZLNET_API BOOL CALL_METHOD ZLNET_StopMultiPlay(LONG lMultiHandle);

// 抓图；hPlayHandle为监视或回放句柄
ZLNET_API BOOL CALL_METHOD ZLNET_CapturePicture(LONG hPlayHandle, const char *pchPicFileName);

// 设置实时监视数据回调
ZLNET_API BOOL CALL_METHOD ZLNET_SetRealDataCallBack(LONG lRealHandle, fZLRealDataCallBack cbRealData, DWORD dwUser);

// 设置实时监视数据回调--扩展
ZLNET_API BOOL CALL_METHOD ZLNET_SetRealDataCallBackEx(LONG lRealHandle, fZLRealDataCallBackEx cbRealData, DWORD dwUser, DWORD dwFlag);

// 设置图象流畅性
ZLNET_API BOOL	CALL_METHOD ZLNET_AdjustFluency(LONG lRealHandle, int nLevel);

// 保存数据为文件
ZLNET_API BOOL CALL_METHOD ZLNET_SaveRealData(LONG lRealHandle, const char *pchFileName);

// 结束保存数据为文件
ZLNET_API BOOL CALL_METHOD ZLNET_StopSaveRealData(LONG lRealHandle);

// 设置图像属性
ZLNET_API BOOL CALL_METHOD ZLNET_ZLSetVideoEffect(LONG lPlayHandle, unsigned char nBrightness, unsigned char nContrast, unsigned char nHue, unsigned char nSaturation);

// 获取图像属性
ZLNET_API BOOL CALL_METHOD ZLNET_ZLGetVideoEffect(LONG lPlayHandle, unsigned char *nBrightness, unsigned char *nContrast, unsigned char *nHue, unsigned char *nSaturation);

// 设置屏幕叠加回调
ZLNET_API void CALL_METHOD ZLNET_RigisterDrawFun(fZLDrawCallBack cbDraw, DWORD dwUser);

// 打开声音
ZLNET_API BOOL CALL_METHOD ZLNET_OpenSound(LONG hPlayHandle);

// 设置音量；lPlayHandle为监视或回放句柄
ZLNET_API BOOL CALL_METHOD ZLNET_SetVolume(LONG lPlayHandle, int nVolume);

// 关闭声音
ZLNET_API BOOL CALL_METHOD ZLNET_CloseSound();

// 停止实时预览
ZLNET_API BOOL CALL_METHOD ZLNET_StopRealPlay(LONG lRealHandle);

// 停止实时预览--扩展
ZLNET_API BOOL CALL_METHOD ZLNET_StopRealPlayEx(LONG lRealHandle);

//------------------------------------------------------------------------

// 通用云台控制
ZLNET_API BOOL CALL_METHOD ZLNET_PTZControl(LONG lLoginID, int nChannelID, DWORD dwPTZCommand, DWORD dwStep, BOOL dwStop);

// 智领云台控制
ZLNET_API BOOL CALL_METHOD ZLNET_ZLPTZControl(LONG lLoginID, int nChannelID, DWORD dwPTZCommand, unsigned char param1, unsigned char param2, unsigned char param3, BOOL dwStop);

// 智领云台控制扩展接口，支持三维快速定位
ZLNET_API BOOL CALL_METHOD ZLNET_ZLPTZControlEx(LONG lLoginID, int nChannelID, DWORD dwPTZCommand, LONG lParam1, LONG lParam2, LONG lParam3, BOOL dwStop);

//------------------------------------------------------------------------

// 查询时间段内是否有录像文件
ZLNET_API BOOL CALL_METHOD ZLNET_QueryRecordTime(LONG lLoginID, int nChannelId, int nRecordFileType, LPZLNET_TIME tmStart, LPZLNET_TIME tmEnd, char* pchCardid, BOOL *bResult, int waittime=1000);

// 查询时间段内的所有录像文件
ZLNET_API BOOL CALL_METHOD ZLNET_QueryRecordFile(LONG lLoginID, int nChannelId, int nRecordFileType, LPZLNET_TIME tmStart, LPZLNET_TIME tmEnd, char* pchCardid, LPZLNET_RECORDFILE_INFO nriFileinfo, int maxlen, int *filecount, int waittime=1000, BOOL bTime = FALSE);

// 查询最早录像时间
ZLNET_API BOOL CALL_METHOD ZLNET_QueryFurthestRecordTime(LONG lLoginID, int nRecordFileType, char *pchCardid, ZLNET_FURTHEST_RECORD_TIME* pFurthrestTime, int nWaitTime);

// 开始查找录像文件
ZLNET_API LONG	CALL_METHOD ZLNET_FindFile(LONG lLoginID, int nChannelId, int nRecordFileType, char* cardid, LPZLNET_TIME time_start, LPZLNET_TIME time_end, BOOL bTime, int waittime);

// 查找录像文件
ZLNET_API int	CALL_METHOD ZLNET_FindNextFile(LONG lFindHandle,LPZLNET_RECORDFILE_INFO lpFindData);

// 结束录像文件查找
ZLNET_API BOOL CALL_METHOD ZLNET_FindClose(LONG lFindHandle);

// 按文件方式回放
ZLNET_API LONG CALL_METHOD ZLNET_PlayBackByRecordFile(LONG lLoginID, LPZLNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwUserData);

// 按文件方式回放--扩展
ZLNET_API LONG CALL_METHOD ZLNET_PlayBackByRecordFileEx(LONG lLoginID, LPZLNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwPosUser, fZLDataCallBack fDownLoadDataCallBack, DWORD dwDataUser);

// 按时间方式回放
ZLNET_API LONG CALL_METHOD ZLNET_PlayBackByTime(LONG lLoginID, int nChannelID, LPZLNET_TIME lpStartTime, LPZLNET_TIME lpStopTime, HWND hWnd, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwPosUser);

// 按时间方式回放--扩展
ZLNET_API LONG CALL_METHOD ZLNET_PlayBackByTimeEx(LONG lLoginID, int nChannelID, LPZLNET_TIME lpStartTime, LPZLNET_TIME lpStopTime, HWND hWnd, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwPosUser, fZLDataCallBack fDownLoadDataCallBack, DWORD dwDataUser);

// 定位录像回放起始点
ZLNET_API BOOL CALL_METHOD ZLNET_SeekPlayBack(LONG lPlayHandle, unsigned int offsettime, unsigned int offsetbyte);

// 暂停或恢复录像回放
ZLNET_API BOOL CALL_METHOD ZLNET_PausePlayBack(LONG lPlayHandle, BOOL bPause);

// 快进录像回放
ZLNET_API BOOL CALL_METHOD ZLNET_FastPlayBack(LONG lPlayHandle);

// 慢进录像回放
ZLNET_API BOOL CALL_METHOD ZLNET_SlowPlayBack(LONG lPlayHandle);

// 步进录像回放
ZLNET_API BOOL CALL_METHOD ZLNET_StepPlayBack(LONG lPlayHandle, BOOL bStop);

// 设置回放帧速
ZLNET_API BOOL CALL_METHOD ZLNET_SetFramePlayBack(LONG lPlayHandle, int framerate);

// 获取回放帧速
ZLNET_API BOOL CALL_METHOD ZLNET_GetFramePlayBack(LONG lPlayHandle, int *fileframerate, int *playframerate);

// 恢复正常回放速度
ZLNET_API BOOL CALL_METHOD ZLNET_NormalPlayBack(LONG lPlayHandle);

// 获取回放OSD时间
ZLNET_API BOOL CALL_METHOD ZLNET_GetPlayBackOsdTime(LONG lPlayHandle, LPZLNET_TIME lpOsdTime, LPZLNET_TIME lpStartTime, LPZLNET_TIME lpEndTime);

// 停止录像回放
ZLNET_API BOOL CALL_METHOD ZLNET_StopPlayBack(LONG lPlayHandle);

// 下载录像文件
ZLNET_API LONG CALL_METHOD ZLNET_DownloadByRecordFile(LONG lLoginID,LPZLNET_RECORDFILE_INFO lpRecordFile, char *sSavedFileName, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwUserData);

// 设置下载文件模式
ZLNET_API BOOL CALL_METHOD ZLNET_SetDownloadFileMode(LONG lLoginID, ZLNET_DOWNLOADFILE_MODE eMode);

// 通过时间下载录像
ZLNET_API LONG CALL_METHOD ZLNET_DownloadByTime(LONG lLoginID, int nChannelId, int nRecordFileType, LPZLNET_TIME tmStart, LPZLNET_TIME tmEnd, char *sSavedFileName, fZLTimeDownLoadPosCallBack cbTimeDownLoadPos, DWORD dwUserData);

// 查询录像下载进度
ZLNET_API BOOL CALL_METHOD ZLNET_GetDownloadPos(LONG lFileHandle, int *nTotalSize, int *nDownLoadSize);

// 停止录像下载
ZLNET_API BOOL CALL_METHOD ZLNET_StopDownload(LONG lFileHandle);
//------------------------------------------------------------------------

// 设置报警回调函数
ZLNET_API void CALL_METHOD ZLNET_SetDVRMessCallBack(fZLMessCallBack cbMessage,DWORD dwUser);

// 设置报警回调扩展函数
ZLNET_API void CALL_METHOD ZLNET_SetDVRMessCallBackEx(LONG ID, fZLMessCallBack cbMessage,DWORD dwUser, BOOL bAdd = TRUE);

// 向设备订阅报警
ZLNET_API BOOL CALL_METHOD ZLNET_StartListen(LONG lLoginID);

// 向设备订阅报警--扩展
ZLNET_API BOOL CALL_METHOD ZLNET_StartListenEx(LONG lLoginID);

// 停止订阅报警
ZLNET_API BOOL CALL_METHOD ZLNET_StopListen(LONG lLoginID);

//------------------------------------------------------------------------

// 主动注册功能，启动服务；nTimeout参数已无效
ZLNET_API LONG CALL_METHOD ZLNET_ListenServer(char* ip, WORD port, int nTimeout, fZLServiceCallBack cbListen, DWORD dwUserData);

// 停止服务
ZLNET_API BOOL CALL_METHOD ZLNET_StopListenServer(LONG lServerHandle);

// 响应设备的注册请求
ZLNET_API BOOL CALL_METHOD ZLNET_ResponseDevReg(char *devSerial, char* ip, WORD port, BOOL bAccept);

//------------------------------------------------------------------------

// 报警上传功能，启动服务；dwTimeOut参数已无效
ZLNET_API LONG CALL_METHOD ZLNET_StartService(WORD wPort, char *pIp = NULL, fZLServiceCallBack pfscb = NULL, DWORD dwTimeOut = 0xffffffff, DWORD dwUserData = 0);

// 停止服务
ZLNET_API BOOL CALL_METHOD ZLNET_StopService(LONG lHandle);

//------------------------------------------------------------------------

// 设置语音对讲模式，客户端方式还是服务器方式
ZLNET_API BOOL CALL_METHOD ZLNET_SetDeviceMode(LONG lLoginID, ZLNET_USEDEV_MODE emType, void* pValue);

// 打开语音对讲
ZLNET_API LONG CALL_METHOD ZLNET_StartTalkEx(LONG lLoginID, pfZLAudioDataCallBack pfcb, DWORD dwUser);

// 开始PC端录音
ZLNET_API BOOL CALL_METHOD ZLNET_RecordStart();

// 结束PC端录音
ZLNET_API BOOL CALL_METHOD ZLNET_RecordStop();

// 发送语音数据到设备
ZLNET_API LONG CALL_METHOD ZLNET_TalkSendData(LONG lTalkHandle, char *pSendBuf, DWORD dwBufSize);

// 解码音频数据
ZLNET_API void CALL_METHOD ZLNET_AudioDec(char *pAudioDataBuf, DWORD dwBufSize);

// 设置语音对讲的音量
ZLNET_API BOOL CALL_METHOD ZLNET_SetAudioClientVolume(LONG lTalkHandle, WORD wVolume);

// 停止语音对讲
ZLNET_API BOOL CALL_METHOD ZLNET_StopTalkEx(LONG lTalkHandle);

// 添加设备到广播组
ZLNET_API BOOL CALL_METHOD ZLNET_AudioBroadcastAddDev(LONG lLoginID);

// 从广播组中删除设备
ZLNET_API BOOL CALL_METHOD ZLNET_AudioBroadcastDelDev(LONG lLoginID);

// 音频编码--初始化(特定标准格式->智领格式)
ZLNET_API int  CALL_METHOD ZLNET_InitAudioEncode(ZLNET_AUDIO_FORMAT aft);

// 音频编码--数据编码
ZLNET_API int	CALL_METHOD	ZLNET_AudioEncode(LONG lTalkHandle, BYTE *lpInBuf, DWORD *lpInLen, BYTE *lpOutBuf, DWORD *lpOutLen);

// 音频编码--音频数据->智领格式
ZLNET_API int  CALL_METHOD ZLNET_AudioFormatZL(BYTE *lpInBuf, DWORD *lpInLen, BYTE *lpOutBuf, DWORD *lpOutLen, ZLNET_AUDIO_FORMAT aft);

// 音频编码--完成退出
ZLNET_API int	CALL_METHOD	ZLNET_ReleaseAudioEncode();

//------------------------------------------------------------------------

// 查询设备日志
ZLNET_API BOOL CALL_METHOD ZLNET_QueryLog(LONG lLoginID, char *pLogBuffer, int maxlen, int *nLogBufferlen, int waittime=3000);

// 查询设备日志，以分页方式查询
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDeviceLog(LONG lLoginID, ZLNET_QUERY_DEVICE_LOG_PARAM *pQueryParam, char *pLogBuffer, int nLogBufferLen, int *pRecLogNum, int waittime=3000);

// 查道通道录像状态
ZLNET_API BOOL CALL_METHOD ZLNET_QueryRecordState(LONG lLoginID, char *pRSBuffer, int maxlen, int *nRSBufferlen, int waittime=1000);

// 查询设备状态
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDevState(LONG lLoginID, int nType, char *pBuf, int nBufLen, int *pRetLen, int waittime=1000);

// 查询系统能力信息
ZLNET_API BOOL CALL_METHOD ZLNET_QuerySystemInfo(LONG lLoginID, int nSystemType, char *pSysInfoBuffer, int maxlen, int *nSysInfolen, int waittime=1000);

// 获取通道码流
ZLNET_API LONG CALL_METHOD ZLNET_GetStatiscFlux(LONG lLoginID, LONG lPlayHandle);

// 获取云台信息
ZLNET_API BOOL  CALL_METHOD ZLNET_GetPtzOptAttr(LONG lLoginID,DWORD dwProtocolIndex,LPVOID lpOutBuffer,DWORD dwBufLen,DWORD *lpBytesReturned,int waittime=500);

//------------------------------------------------------------------------

// 重启设备
ZLNET_API BOOL CALL_METHOD ZLNET_RebootDev(LONG lLoginID);

// 关闭设备
ZLNET_API BOOL CALL_METHOD ZLNET_ShutDownDev(LONG lLoginID);

// 设备控制
ZLNET_API BOOL CALL_METHOD ZLNET_ControlDevice(LONG lLoginID, ZLNET_CtrlType type, void *param, int waittime = 1000);

// 设置通道录像状态
ZLNET_API BOOL CALL_METHOD ZLNET_SetupRecordState(LONG lLoginID, char *pRSBuffer, int nRSBufferlen);

// 查询IO状态
ZLNET_API BOOL CALL_METHOD ZLNET_QueryIOControlState(LONG lLoginID, ZLNET_IOTYPE emType, 
                                           void *pState, int maxlen, int *nIOCount, int waittime=1000);

// IO控制
ZLNET_API BOOL CALL_METHOD ZLNET_IOControl(LONG lLoginID, ZLNET_IOTYPE emType, void *pState, int maxlen);

// 强制I帧；nChannelID：通道号，nSubChannel：码流类型(0：主，1：子码流1)
ZLNET_API BOOL CALL_METHOD ZLNET_MakeKeyFrame(LONG lLoginID, int nChannelID, int nSubChannel=0);

//------------------------------------------------------------------------

// 查询用户信息
ZLNET_API BOOL CALL_METHOD ZLNET_QueryUserInfo(LONG lLoginID, ZLNET_USER_MANAGE_INFO *info, int waittime=1000);

// 查询用户信息--扩展
ZLNET_API BOOL CALL_METHOD ZLNET_QueryUserInfoEx(LONG lLoginID,  ZLNET_USER_MANAGE_INFO_EX *info, int waittime=1000);

// 操作设备用户
ZLNET_API BOOL CALL_METHOD ZLNET_OperateUserInfo(LONG lLoginID, int nOperateType, void *opParam, void *subParam, int waittime=1000);

// 操作设备用户--扩展
ZLNET_API BOOL CALL_METHOD ZLNET_OperateUserInfoEx(LONG lLoginID, int nOperateType, void *opParam, void *subParam, int waittime=1000);

//------------------------------------------------------------------------

// 创建透明串口通道
ZLNET_API LONG CALL_METHOD ZLNET_CreateTransComChannel(LONG lLoginID, int TransComType, unsigned int baudrate, unsigned int databits, unsigned int stopbits, unsigned int parity, fZLTransComCallBack cbTransCom, DWORD dwUser);

// 透明串口发送数据
ZLNET_API BOOL CALL_METHOD ZLNET_SendTransComData(LONG lTransComChannel, char *pBuffer, DWORD dwBufSize);

// 释放通明串口通道
ZLNET_API BOOL CALL_METHOD ZLNET_DestroyTransComChannel(LONG lTransComChannel);

// 查询透明串口状态
ZLNET_API BOOL   CALL_METHOD ZLNET_QueryTransComParams(LONG lLoginID, int TransComType, ZLNET_COMM_STATE* pCommState, int nWaitTime = 500);

//------------------------------------------------------------------------

// 开始升级设备程序
ZLNET_API LONG CALL_METHOD ZLNET_StartUpgrade(LONG lLoginID, char *pchFileName, fZLUpgradeCallBack cbUpgrade, DWORD dwUser);

// 开始升级设备程序--扩展
ZLNET_API LONG CALL_METHOD ZLNET_StartUpgradeEx(LONG lLoginID, ZLNET_UPGRADE_TYPE emType, char *pchFileName, fZLUpgradeCallBack cbUpgrade, DWORD dwUser);

// 发送数据
ZLNET_API BOOL CALL_METHOD ZLNET_SendUpgrade(LONG lUpgradeID);

// 结束升级设备程序
ZLNET_API BOOL CALL_METHOD ZLNET_StopUpgrade(LONG lUpgradeID);

//------------------------------------------------------------------------

// 查询配置信息
ZLNET_API BOOL  CALL_METHOD ZLNET_GetDevConfig(LONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime=500);

// 设置配置信息
ZLNET_API BOOL  CALL_METHOD ZLNET_SetDevConfig(LONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize, int waittime=500);

// 新配置接口，查询配置信息(以Json格式，具体见配置SDK)
ZLNET_API BOOL CALL_METHOD ZLNET_GetNewDevConfig(LONG lLoginID, char* szCommand, char* szOutBuffer, DWORD dwOutBufferSize, int *error, int waittime=1500);

// 新配置接口，设置配置信息(以Json格式，具体见配置SDK)
ZLNET_API BOOL CALL_METHOD ZLNET_SetNewDevConfig(LONG lLoginID, char* szInBuffer, DWORD dwInBufferSize, int *error, int *restart, int waittime=1500);

//------------------------------------------------------------------------

// 查询设备通道名称
ZLNET_API BOOL CALL_METHOD ZLNET_QueryChannelName(LONG lLoginID, char *pChannelName, int maxlen, int *nChannelCount, int waittime=1000);

// 设置设备通道名称
ZLNET_API BOOL  CALL_METHOD ZLNET_SetupChannelName(LONG lLoginID,char *pbuf, int nbuflen);

// 设置设备通道字符叠加
ZLNET_API BOOL  CALL_METHOD ZLNET_SetupChannelOsdString(LONG lLoginID, int nChannelNo, ZLNET_CHANNEL_OSDSTRING* struOsdString, int nbuflen);

// 查询设备当前时间
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDeviceTime(LONG lLoginID, LPZLNET_TIME pDeviceTime, int waittime=1000);

// 设置设备当前时间
ZLNET_API BOOL CALL_METHOD ZLNET_SetupDeviceTime(LONG lLoginID, LPZLNET_TIME pDeviceTime);

// 设置设备限制码流
ZLNET_API BOOL CALL_METHOD ZLNET_SetMaxFlux(LONG lLoginID, WORD wFlux);

//------------------------------------------------------------------------

// 导入配置文件
ZLNET_API LONG CALL_METHOD ZLNET_ImportConfigFile(LONG lLoginID, char *szFileName, fZLDownLoadPosCallBack cbUploadPos, DWORD dwUserData, DWORD param=0);

// 停止导入配置文件
ZLNET_API BOOL CALL_METHOD ZLNET_StopImportCfgFile(LONG lImportHandle);

// 导出配置文件
ZLNET_API LONG CALL_METHOD ZLNET_ExportConfigFile(LONG lLoginID, ZLNET_CONFIG_FILE_TYPE emConfigFileType, char *szSavedFilePath, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwUserData);

// 停止导出配置文件
ZLNET_API BOOL CALL_METHOD ZLNET_StopExportCfgFile(LONG lExportHandle);

//------------------------------------------------------------------------

// 通过设备名字或者设备序列号向DDNS服务器查询设备IP
ZLNET_API BOOL CALL_METHOD ZLNET_GetDVRIPByResolveSvr(char *pchDVRIP, WORD wDVRPort, BYTE *sDVRName, WORD wDVRNameLen, BYTE *sDVRSerialNumber, WORD wDVRSerialLen, char* sGetIP);

// 搜索局域网内IPC、NVS等设备
ZLNET_API BOOL CALL_METHOD ZLNET_SearchDevices(char* szBuf, int nBufLen, int* pRetLen, DWORD dwSearchTime);

// 搜索局域网内IPC、NVS、IVA等设备扩展接口
ZLNET_API BOOL CALL_METHOD ZLNET_SearchDevicesEx(char* szBuf, int nBufLen, int* pRetLen, DWORD dwSearchTime, ZLNET_SEARCH_MODE eMode);

//------------------------------------------------------------------------

// 平台接入接口
ZLNET_API BOOL CALL_METHOD ZLNET_GetPlatFormInfo(LONG lLoginID, DWORD dwCommand, int nSubCommand, int nParam, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime=500);
ZLNET_API BOOL CALL_METHOD ZLNET_SetPlatFormInfo(LONG lLoginID, DWORD dwCommand, int nSubCommand, int nParam, LPVOID lpInBuffer, DWORD dwInBufferSize, int waittime=500);


// 设置抓图回调函数
ZLNET_API void CALL_METHOD ZLNET_SetSnapRevCallBack(fZLSnapRev OnSnapRevMessage, DWORD dwUser);

// 抓图请求
ZLNET_API BOOL CALL_METHOD ZLNET_SnapPicture(LONG lLoginID, ZLNET_SNAP_PARAMS par);

// 设置GPS订阅回调函数
ZLNET_API void CALL_METHOD ZLNET_SetSubcribeGPSCallBack(fZLGPSRev OnGPSMessage, DWORD dwUser);

// GPS信息订阅
ZLNET_API BOOL CALL_METHOD ZLNET_SubcribeGPS (LONG lLoginID, BOOL bStart, LONG KeepTime, LONG InterTime);

//订阅智能报警调试
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SubcribeAlarmDebug (LONG lLoginID,        //设备句柄
													 int nATMIndex,			//ATM操作索引
													BOOL bStart);		  //是否启动 

ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SubcribeAlarmSSBDebug (LONG lLoginID,      //设备句柄
															int nSSBIndex,		//SSB索引
														 BOOL bStart);			//是否启动 

ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SubcribeAlarmBZSDebug (LONG lLoginID,      //设备句柄
															int nBZSIndex,		//SSB索引
															BOOL bStart);		//是否启动 

ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SubcribeAlarmFaceDebug(LONG lLoginID,      //设备句柄
															int nFaceIndex,		//人脸索引
															BOOL bStart);		//是否启动 

ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SubcribeAlarmStaffDebug(LONG lLoginID,      //设备句柄
															int nSCIndex,		//人数统计索引
															BOOL bStart);		//是否启动 

//设置智能报警调试回调
ZLNET_API void CALL_METHOD ZLNET_IVA_SetSubcribeAlarmDebugCallBack(fZLAlarmDebugRevCallback cbDebugRec, DWORD dwUser); 

ZLNET_API void CALL_METHOD ZLNET_IVA_SetSubcribeAlarmSSBDebugCallBack(fZLAlarmDebugSSBRevCallback cbDebugRec, DWORD dwUser);

ZLNET_API void CALL_METHOD ZLNET_IVA_SetSubcribeAlarmBZSDebugCallBack(fZLAlarmDebugBZSRevCallback cbDebugRec, DWORD dwUser);

ZLNET_API void CALL_METHOD ZLNET_IVA_SetSubcribeAlarmFaceDebugCallBack(fZLAlarmDebugFaceRevCallback cbDebugRec, DWORD dwUser);

ZLNET_API void CALL_METHOD ZLNET_IVA_SetSubcribeAlarmStaffDebugCallBack(fZLAlarmDebugStaffRevCallback cbDebugRec, DWORD dwUser);

//轨迹跟踪回调
ZLNET_API void CALL_METHOD ZLNET_IVA_SetBZSTrackInfoCallBack(LONG lLoginID, fZLBZSTrackInfoCallback cbTrackInfo, DWORD dwUser);


//////////////////////////////解码器设备接口//////////////////////////////

// 查询解码器信息
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDecoderInfo(LONG lLoginID, LPZLNET_DEV_DECODER_INFO lpDecInfo, int waittime=1000);

// 查询解码器当前TV信息
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDecoderTVInfo(LONG lLoginID, int nMonitorID, LPZLNET_DEV_DECODER_TV lpMonitorInfo, int waittime=1000);

// 查询解码通道信息
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDecEncoderInfo(LONG lLoginID, int nEncoderID, LPZLNET_DEV_ENCODER_INFO lpEncoderInfo, int waittime=1000);

// 设置解码器TV输出使能
ZLNET_API BOOL CALL_METHOD ZLNET_SetDecTVOutEnable(LONG lLoginID, BYTE *pDecTVOutEnable, int nBufLen, int waittime=1000);

//------------------------------------------------------------------------

// 设置异步回调函数
ZLNET_API BOOL CALL_METHOD ZLNET_SetOperateCallBack(LONG lLoginID, fZLMessDataCallBack cbMessData, DWORD dwUser);

// 控制解码器TV画面分割，接口为异步方式
ZLNET_API LONG CALL_METHOD ZLNET_CtrlDecTVScreen(LONG lLoginID, int nMonitorID, BOOL bEnable, int nSplitType, BYTE *pEncoderChannel, int nBufLen, void* userdata=NULL);

// 解码器TV画面切换，接口为异步方式
// 根据nMonitorID(TV号)、nWndID(画面号)转换为nEncoderID(解码通道)公式：nEncoderID＝nMonitorID*nSplitNum(分割数)+nWndID
ZLNET_API LONG CALL_METHOD ZLNET_SwitchDecTVEncoder(LONG lLoginID, int nEncoderID, LPZLNET_DEV_ENCODER_INFO lpEncoderInfo, void* userdata=NULL);

//------------------------------------------------------------------------

// 增加画面组合
ZLNET_API int CALL_METHOD ZLNET_AddTourCombin(LONG lLoginID, int nMonitorID, int nSplitType, BYTE *pEncoderChannnel, int nBufLen, int waittime=1000);

// 删除画面组合
ZLNET_API BOOL CALL_METHOD ZLNET_DelTourCombin(LONG lLoginID, int nMonitorID, int nCombinID, int waittime=1000);

// 修改画面组合
ZLNET_API BOOL CALL_METHOD ZLNET_SetTourCombin(LONG lLoginID, int nMonitorID, int nCombinID, int nSplitType, BYTE *pEncoderChannel, int nBufLen, int waittime=1000);

// 查询画面组合，nCombinID范围0～32
ZLNET_API BOOL CALL_METHOD ZLNET_QueryTourCombin(LONG lLoginID, int nMonitorID, int nCombinID, LPZLNET_DEC_COMBIN_INFO lpDecCombinInfo, int waittime=1000);

// 设置轮巡操作
ZLNET_API BOOL CALL_METHOD ZLNET_SetDecoderTour(LONG lLoginID, int nMonitorID, LPZLNET_DEC_TOUR_COMBIN lpDecTourInfo, int waittime=1000);

// 查询轮巡操作
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDecoderTour(LONG lLoginID, int nMonitorID, LPZLNET_DEC_TOUR_COMBIN lpDecTourInfo, int waittime=1000);

// 查询当前解码通道流信息
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDecChannelFlux(LONG lLoginID, int nEncoderID, LPZLNET_DEV_DECCHANNEL_STATE lpChannelStateInfo, int waittime=1000);

//解码器控制轮巡
ZLNET_API BOOL CALL_METHOD ZLNET_CtrlDecoderTour(LONG lLoginID, int nMonitorID, ZLNET_DEC_CTRL_TOUR_TYPE emActionParam, int waittime = 1000);
//------------------------------------------------------------------------

typedef void (CALLBACK *fDecPlayBackPosCallBack)(LONG lLoginID, int nEncoderID, DWORD dwTotalSize, DWORD dwPlaySize, DWORD dwUser);

// 设置回放进度回调函数
ZLNET_API BOOL CALL_METHOD ZLNET_SetDecPlaybackPos(LONG lLoginID, fDecPlayBackPosCallBack cbPlaybackPos, DWORD dwUser);

// 解码器TV画面回放，接口为异步方式
ZLNET_API LONG CALL_METHOD ZLNET_DecTVPlayback(LONG lLoginID, int nEncoderID, ZLNET_DEC_PLAYBACK_MODE emPlaybackMode, LPVOID lpInBuffer, DWORD dwInBufferSize, void* userdata=NULL);

// 解码器TV画面回放控制
ZLNET_API BOOL CALL_METHOD ZLNET_CtrlDecPlayback(LONG lLoginID, int nEncoderID, ZLNET_DEC_CTRL_PLAYBACK_TYPE emCtrlType, int nValue, int waittime=1000);


///////////////////////////////特殊版本接口///////////////////////////////

// 查询设备日志--扩展
ZLNET_API BOOL CALL_METHOD ZLNET_QueryLogEx(LONG lLoginID, ZLNET_LOG_QUERY_TYPE logType, char *pLogBuffer, int maxlen, int *nLogBufferlen, void* reserved, int waittime=3000);

// 主动注册重定向功能，建立定向连接
ZLNET_API LONG CALL_METHOD ZLNET_ControlConnectServer(LONG lLoginID, char* RegServerIP, WORD RegServerPort, int TimeOut=3000);

// 连接主动注册
ZLNET_API BOOL CALL_METHOD ZLNET_ControlRegisterServer(LONG lLoginID, LONG ConnectionID, int waittime=1000);

// 断开定向连接
ZLNET_API BOOL CALL_METHOD ZLNET_ControlDisconnectRegServer(LONG lLoginID, LONG ConnectionID);

// 查询设备上主动注册服务器信息
ZLNET_API BOOL CALL_METHOD ZLNET_QueryControlRegServerInfo(LONG lLoginID, LPZLNET_DEV_SERVER_AUTOREGISTER lpRegServerInfo, int waittime=2000);

// 文件上传接口
ZLNET_API LONG CALL_METHOD ZLNET_FileTransmit(LONG lLoginID, int nTransType, char* szInBuf, int nInBufLen, fZLTransFileCallBack cbTransFile, DWORD dwUserData, int waittime);

/////////////////////////////////淘汰接口/////////////////////////////////

// 查询系统服务器配置；该接口已淘汰，请使用ZLNET_GetDevConfig
ZLNET_API BOOL CALL_METHOD ZLNET_QueryConfig(LONG lLoginID, int nConfigType, char *pConfigbuf, int maxlen, int *nConfigbuflen, int waittime=1000);

// 设置系统服务器配置；该接口已淘汰，请使用ZLNET_SetDevConfig
ZLNET_API BOOL CALL_METHOD ZLNET_SetupConfig(LONG lLoginID, int nConfigType, char *pConfigbuf, int nConfigbuflen, int waittime=1000);

// 该接口已淘汰，请不要使用
ZLNET_API BOOL CALL_METHOD ZLNET_Reset(LONG lLoginID, BOOL bReset);

// 查询串口协议 － 该接口已淘汰，请使用ZLNET_GetDevConfig
ZLNET_API BOOL CALL_METHOD ZLNET_QueryComProtocol(LONG lLoginID, int nProtocolType, char *pProtocolBuffer, int maxlen, int *nProtocollen, int waittime=1000);

// 开始对讲；该接口已淘汰，请使用ZLNET_StartTalkEx
ZLNET_API BOOL CALL_METHOD ZLNET_StartTalk(LONG lRealHandle, BOOL bCustomSend=false);

// 结束对讲；该接口已淘汰，请使用ZLNET_StopTalkEx
ZLNET_API BOOL CALL_METHOD ZLNET_StopTalk(LONG lRealHandle);

// 发送自定义对讲数据；该接口已淘汰，请使用ZLNET_TalkSendData
ZLNET_API BOOL CALL_METHOD ZLNET_SendTalkData_Custom(LONG lRealHandle, char *pBuffer, DWORD dwBufSize);

// 设置实时预览缓冲大小
ZLNET_API BOOL CALL_METHOD ZLNET_SetPlayerBufNumber(LONG lRealHandle, DWORD dwBufNum);

// 通过时间下载文件
ZLNET_API BOOL CALL_METHOD ZLNET_GetFileByTime(LONG lLoginID, int nChannelID, LPZLNET_TIME lpStartTime, LPZLNET_TIME lpStopTime, char *sSavedFileName);

// 网络回放控制
ZLNET_API BOOL CALL_METHOD ZLNET_PlayBackControl(LONG lPlayHandle, DWORD dwControlCode, DWORD dwInValue, DWORD *lpOutValue);

// 查询设备工作状态 该接口已淘汰，请使用ZLNET_QueryDevState
ZLNET_API BOOL CALL_METHOD ZLNET_GetDEVWorkState(LONG lLoginID, LPZLNET_DEV_WORKSTATE lpWorkState, int waittime=1000);

// 异步查询设备日志
ZLNET_API BOOL CALL_METHOD ZLNET_QueryLogCallback(LONG lLoginID, fZLLogDataCallBack cbLogData, DWORD dwUser);

// 上传音频文件(WAV格式) 
ZLNET_API LONG CALL_METHOD ZLNET_UploadAudio(long lLoginID, int nAlarmType, int nSubType, char* szPath, int nPathLen, fIDdvrUploadPosCallBack cbUploadPos, DWORD dwUserData);

//停止上传
ZLNET_API BOOL CALL_METHOD ZLNET_StopUploadAudio(long lUploadHandle);

/////////////////////////////////NVR/////////////////////////////////////////////

//获取通道信息
ZLNET_API int  CALL_METHOD  ZLNET_NVR_GetChannelInfo(long lLoginID, ZLNET_NVR_CHANNEL& NetConfig);

//获取网络当前通道个数
ZLNET_API int  CALL_METHOD  ZLNET_NVR_GetCurNetChannelInfo(long lLoginID, ZLNET_NVR_CHANNEL_INFO_EX& curChannelInfo);

//设置网络配置
ZLNET_API int  CALL_METHOD  ZLNET_NVR_SetNetConfig(long lLoginID, const ZLNET_NVR_CONFIG_NET NetConfig);

//获取网络配置
ZLNET_API int  CALL_METHOD  ZLNET_NVR_GetNetConfig(long lLoginID, ZLNET_NVR_CONFIG_NET& NetConfig);

//获取网络通道云台协议
ZLNET_API int  CALL_METHOD  ZLNET_NVR_GetNetPtzParam(long lLoginID, ZLNET_NVR_NET_PTZ_PARAM& NetPtzParam, int nChannel);

//设置设备搜索回调函数
ZLNET_API void CALL_METHOD ZLNET_NVR_SetSearchCallBack(fZLNVRSearch cbSearchMessage, DWORD dwUser);

//设备搜索命令
ZLNET_API BOOL CALL_METHOD ZLNET_NVR_Search(LONG lLoginID, BOOL bStart, int protocol);

/////////////////////////////////智能相关/////////////////////////////////////////
//主动注册IP服务地址
ZLNET_API int CALL_METHOD ZLNET_IVA_RegistDev(int loginHandle, const ZLNET_IVA_REGISTIP& stuHost);

//获取已注册IP地址列表
ZLNET_API int  CALL_METHOD ZLNET_IVA_GetRegistDevList(int loginHandle, ZLNET_IVA_REGISTIP_LIST& hostList);

//设置已注册IP地址列表
ZLNET_API int  CALL_METHOD ZLNET_IVA_SetRegistDevList(int loginHandle, const ZLNET_IVA_REGISTIP_LIST* delHostList);

//设置日志存储模式
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetLogMode(long lLoginID, const ZLNET_IVA_LOG_MODE logMode);

//获取日志存储模式
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetLogMode(long lLoginID, ZLNET_IVA_LOG_MODE& logMode);

//获取报警录像配置
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetAlarmRecord(long lLoginID, ZLNET_IVA_ALARM_RECORD& config);

//设置报警录像配置
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetAlarmRecord(long lLoginID, ZLNET_IVA_ALARM_RECORD config);

//设置视频通道模式
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetVideoMode(long lLoginID, const ZLNET_IVA_CHANNEL_CONFIG* cfg);

//获取视频通道模式
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetVideoMode(long lLoginID, ZLNET_IVA_CHANNEL_CONFIG& chnCfg);

//设置报警联动
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetAlarmAssc(long lLoginID, int nAlarmTpye, const ZLNET_IVA_ALARM_ASSCONFIG* alarmCfg, int emIndex = 0);

//获取报警联动
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetAlarmAssc(long lLoginID, int nAlarmType, ZLNET_IVA_ALARM_ASSCONFIG& alarmCfg, int emIndex = 0);

//设置报警工作表
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetWorkSheet(long lLoginID, int nAlarmType, const ZLNET_IVA_WEEK_SECTION* alarmWorksheet, int emIndex = 0);

//获取报警工作表
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetWorkSheet(long lLoginID, int alarmType, ZLNET_IVA_WEEK_SECTION& alarmWorksheet,int emIndex );

//设置外部报警联动
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetGpiAssc(long lLoginID, const ZLNET_IVA_GPI_ASSCONFIG* alarmCfg, int chn);

//获取外部报警联动
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetGpiAssc(long lLoginID, ZLNET_IVA_GPI_ASSCONFIG& alarmCfg, int	chn);

//设置外部报警工作表
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetGpiWorkSheet(long lLoginID, const ZLNET_IVA_WEEK_SECTION* alarmWorksheet, int chn);

//获取外部报警工作表
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetGpiWorkSheet(long lLoginID, ZLNET_IVA_WEEK_SECTION& alarmWorksheet, int	chn);

//设置ATM人脸检测区域参数
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetATMAreaFaceParm(long lLoginID, const ZLNET_IVA_ATM_ALARMAREA_FACE* alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//获取ATM人脸检测区域参数
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetATMAreaFaceParm(long lLoginID, ZLNET_IVA_ATM_ALARMAREA_FACE& alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//设置ATM报警区域
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetATMAlarmAreaParm(long lLoginID, const ZLNET_IVA_ATM_DETECTAREA* alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//获取ATM报警区域
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetATMAlarmAreaParm(long lLoginID, ZLNET_IVA_ATM_DETECTAREA& alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//设置ATM配置参数
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetATMParm(long lLoginID, const ZLNET_IVA_ATM_PARAM* alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1); 

//获取ATM配置参数
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetATMParm(long lLoginID, ZLNET_IVA_ATM_PARAM& alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1); 

//设置ATM异常人脸配置参数 
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetATMArnomalFaceParm(long lLoginID, const ZLNET_IVA_ATM_ARNORMAL_FACE_PARAM* alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//获取ATM异常人脸配置参数 
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetATMArnomalFaceParm(long lLoginID, ZLNET_IVA_ATM_ARNORMAL_FACE_PARAM& alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//设置ATM人脸视频颜色参数
ZLNET_API int  CALL_METHOD	ZLNET_IVA_SetATMFaceColorParm(long lLoginID ,const ZLNET_IVA_ATM_CONFIG_VIDEOCOLOR* alarmParm,ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//获取ATM人脸视频颜色参数
ZLNET_API int  CALL_METHOD	ZLNET_IVA_GetATMFaceColorParm(long lLoginID , ZLNET_IVA_ATM_CONFIG_VIDEOCOLOR& alarmParm,ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//获取在线用户
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetOnlineConfig(long lLoginID, ZLNET_IVA_USER_ONLINE_LIST&  onlineCfg);

//设置在线用户
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetOnlineConfig(long lLoginID, const ZLNET_IVA_USER_ONLINE_LIST* onlineCfg);

//获取白名单
ZLNET_API BOOL CALL_METHOD ZLNET_GetIPFilterCfg(long lLoginID, ZLNET_DEV_IPIFILTER_CFG&  IPFilterCfg);

//设置白名单
ZLNET_API BOOL CALL_METHOD ZLNET_SetIPFilterCfg(long lLoginID, const ZLNET_DEV_IPIFILTER_CFG* IPFilterCfg);

//设置算法调试
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetArithmeticDebug(long lLoginID, ZLNET_IVA_ARITHMETIC_DEBUG&  arithDebug);

//获取算法调试
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetArithmeticDebug(long lLoginID, const ZLNET_IVA_ARITHMETIC_DEBUG* arithDebug);

//获取音频上传信息
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetAudioUploadInfo(long lLoginID, ZLNET_IVA_AUDIO_UPLOAD_INFO& audioInfo);

//获取车辆检测区域和车辆屏蔽区域
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetLicensePlateRegion(long lLoginID, ZLNET_IVA_REGION& licensePlateRegion);

//设置车辆检测区域和车辆屏蔽区域
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetLicensePlateRegion(long lLoginID, ZLNET_IVA_REGION* licensePlateRegion);

//获取OSD及车牌配置参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetOsdLicensePlateConfig(long lLoginID, ZLNET_IVA_OSD_LICENSE_PALTE_PARAM& osdLicensePlateParam);

//设置OSD及车牌配置参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetOsdLicensePlateConfig(long lLoginID, ZLNET_IVA_OSD_LICENSE_PALTE_PARAM* osdLicensePlateParam);

//获取车牌配置参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetLicensePlateConfig(long lLoginID, ZLNET_IVA_PLATEID_PARAM& liscensePlateParam);

//设置车牌配置参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetLicensePlateConfig(long lLoginID, ZLNET_IVA_PLATEID_PARAM* liscensePlateParam);

//获取车牌报警参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetLicensePlateAlarm(long lLoginID, ZLNET_IVA_PLATEID_ALARM& liscensePlateParam);

//设置车牌报警参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetLicensePlateAlarm(long lLoginID, ZLNET_IVA_PLATEID_ALARM* liscensePlateParam);

//触发(一次)车牌检测
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetLicensePlateDetect(long lLoginID, int nChn);

//获取人员检测参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetStaffCountConfig(long lLoginID, ZLNET_IVA_STAFF_COUNT_CONFIG& staffCountConfig);

//设置人员检测参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetStaffCountConfig(long lLoginID, ZLNET_IVA_STAFF_COUNT_CONFIG* staffCountConfig);

//获取人员检测参数-扩展
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetStaffCountConfigEx(long lLoginID, ZLNET_IVA_STAFF_COUNT_CONFIG& staffCountConfig, int nChannel);

//设置人员检测参数-扩展
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetStaffCountConfigEx(long lLoginID, ZLNET_IVA_STAFF_COUNT_CONFIG* staffCountConfig, int nChannel);

//获取周界基本参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetBZSBasicSet(long lLoginID, ZLNET_IVA_BZS_BASIC_SETTIINGS& bzsBasic);

//设置周界基本参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetBZSBasicSet(long lLoginID, ZLNET_IVA_BZS_BASIC_SETTIINGS* bzsBasic);

//获取周界算法参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetBZSAlgorithm(long lLoginID, ZLNET_IVA_BZS_ALGORITHM_PARAM& bzsAlgorithm);

//设置周界算法参数	  
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetBZSAlgorithm(long lLoginID, ZLNET_IVA_BZS_ALGORITHM_PARAM* bzsAlgorithm);

//获取周界相机异常参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetBZSCameraAbnormal(long lLoginID, ZLNET_IVA_BZS_CAMERA_ABNORMAL_PARAM& bzsCameraAbnormal);

//设置周界相机异常参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetBZSCameraAbnormal(long lLoginID, ZLNET_IVA_BZS_CAMERA_ABNORMAL_PARAM* bzsCameraAbnormal);

//获取周界单线规则
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetBZSOneLineAlarmRule(long lLoginID, ZLNET_IVA_BZS_CROSS_0NE_LINE_PARAM& oneLineRule);

//设置周界单线规则
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetBZSOneLineAlarmRule(long lLoginID, ZLNET_IVA_BZS_CROSS_0NE_LINE_PARAM* oneLineRule);

//获取周界双线规则
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetBZSTwoLineAlarmRule(long lLoginID, ZLNET_IVA_BZS_CROSS_TWO_LINE_PARAM& bzsTwoLineRule);

//设置周界双线规则
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetBZSTwoLineAlarmRule(long lLoginID, ZLNET_IVA_BZS_CROSS_TWO_LINE_PARAM* bzsTwoLineRule);

//获取周界区域规则
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetBZSAreaAlarmRule(long lLoginID, ZLNET_IVA_BZS_AREA_DETECT_PARAM_PARAM& bzsAreaRule);

//设置周界区域规则
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetBZSAreaAlarmRule(long lLoginID, ZLNET_IVA_BZS_AREA_DETECT_PARAM_PARAM* bzsAreaRule);

//获取报警使能
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetAlarmEnable(long lLoginID, ZLNET_IVA_ALARM_ENABLE& AlarmEnable, int nChn);

//设置报警使能
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetAlarmEnable(long lLoginID, ZLNET_IVA_ALARM_ENABLE* AlarmEnable, int nChn);

//获取SSB自助厅参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetSSBHallFunc(long lLoginID, ZLNET_IVA_SSB_HALL_FUNC& ssbHallFunc);

//设置SSB自助厅参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetSSBHallFunc(long lLoginID, ZLNET_IVA_SSB_HALL_FUNC* pSsbHallFunc);

//获取SSB自助厅异常参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetSSBHallAbnormal(long lLoginID, ZLNET_IVA_SSB_ABNORMAL_PARAM& ssbAbnormal);

//设置SSB自助厅异常参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetSSBHallAbnormal(long lLoginID, ZLNET_IVA_SSB_ABNORMAL_PARAM* pSsbAbnormal);

//获取SSB摄像头异常参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetSSBCameraAbnormal(long lLoginID, ZLNET_IVA_SSB_CAMERE_ABNORMAL& ssbCameraAbnormal, ZLNET_IVA_SSB_INDEX ssbIndex);

//设置SSB摄像头异常参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetSSBCameraAbnormal(long lLoginID, ZLNET_IVA_SSB_CAMERE_ABNORMAL* pSsbCameraAbnormal, ZLNET_IVA_SSB_INDEX ssbIndex);

//获取SSB加钞间参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetSSBRoomFunc(long lLoginID, ZLNET_IVA_SSB_ROOM_PARAM& ssbRoomParam);

//设置SSB加钞间参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetSSBRoomFunc(long lLoginID, ZLNET_IVA_SSB_ROOM_PARAM* pSsbRoomParam);

//算法重启
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetBackgroundUpdate(long lLoginID, ZLNET_IVA_BACKGROUND_UPDATE* pBackgroundUpdate);

//获取人脸检测区域
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetFaceArea(long lLoginID, ZLNET_IVA_FACE_AREA_PARAM& ssbRoomParam, int nIndex = -1);

//设置人脸检测区域
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetFaceArea(long lLoginID, ZLNET_IVA_FACE_AREA_PARAM* pSsbRoomParam, int nIndex = -1);

//获取人脸检测参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetFaceDetect(long lLoginID, ZLNET_IVA_FACE_DETECT_PARAM& ssbRoomParam, int nIndex = -1);

//设置人脸检测参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetFaceDetect(long lLoginID, ZLNET_IVA_FACE_DETECT_PARAM* pSsbRoomParam, int nIndex = -1);

//获取人脸叠加参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetFaceOverlay(long lLoginID, ZLNET_IVA_FACE_OVERLAY_PARAM& ssbRoomParam, int nIndex = -1);

//设置人脸叠加参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetFaceOverlay(long lLoginID, ZLNET_IVA_FACE_OVERLAY_PARAM* pSsbRoomParam, int nIndex = -1);

//模拟报警(ZLNET_IVA_SSB_ALARM_TYPE或ZLNET_IVA_ATM_ALARM_TYPE)
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SimulateAlarm(long lLoginID, int alarmType, int nChn);

// 设置抓图回调函数(jpg)
ZLNET_API void  CALL_METHOD ZLNET_IVA_SetSnapRevCallBack(fZLSnapRev cbSnapRev, DWORD dwUser, DWORD CmdSerial = 0, BOOL bAdd = TRUE);

//停止下载智能报警文件
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_StopDownload(long lLoginID);

//订阅ATM报警信息回调
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_ListenAlarmATMIDVR(long lLoginID, fIdvrAlarmUpATMCallback cbDataCallback, DWORD dwUser);

//订阅人员统计信息回调
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_ListenAlarmStaffCountIDVR(long lLoginID, fIdvrAlarmUpStaffCountCallback cbDataCallback, DWORD dwUser);

//订阅车牌信息回调
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_ListenAlarmPlateIdIDVR(long lLoginID, fIdvrAlarmUpPlateIdCallback cbDataCallback, DWORD dwUser);

//订阅自助银行信息回调
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_ListenAlarmSSBIDVR(long lLoginID, fIdvrAlarmUpSSBCallback cbDataCallback, DWORD dwUser);

//订阅周界报警信息回调
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_ListenAlarmBZSIDVR(long lLoginID, fIdvrAlarmUpBZSCallback cbDataCallback, DWORD dwUser);

//订阅人脸报警信息回调
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_ListenAlarmFaceIDVR(long lLoginID, fIdvrAlarmUpFaceCallback cbDataCallback, DWORD dwUser);

//订阅智能报警视频上传
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetAlarmUpVideoIDVR(long lLoginID, fIdvrAlarmUpVideoCallback cbDataCallback, DWORD dwUser);

// 查询时间段内的所有智能DVR报警录像文件
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_QueryRecordFile(LONG lLoginID, int nChannelId, LPZLNET_TIME tmStart, LPZLNET_TIME tmEnd, 
													 int idBeg, int idEnd, void* itemInfo, int maxlen, int *itemCount, int waittime=1000, 
													 ZLNET_IVA_LOG_SEARCH_MODE mode = ZLNET_IVA_SEARCHMODE_DATE, ZLNET_DEVICE_TYPE eDevType = ZLNET_IVA_ATM);

//下载智能报警文件
ZLNET_API int  CALL_METHOD ZLNET_IVA_DownloadFileIDVR(long lLoginID, int id, char* szDirPath, ZLNET_IVA_LOG_DOWNLOAD_MODE mode, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwUserData, ZLNET_DEVICE_TYPE eType = ZLNET_IVA_ATM);

//下载智能报警文件(新协议)
ZLNET_API long  CALL_METHOD ZLNET_IVA_DownloadFile(long lLoginID, char* szDirPath, ZLNET_IVA_EVENT* struDownloadParm, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwUserData);

//触发用户音频播放 emAudio 音频序号  nInterval播放间隔 单位s   未使用
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_StartAudioPlay(long lLoginID, int nAlarmType, int nInterval = 0, int nAudioIndex = 0);

//关闭用户音频播放
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_StopAudioPlay(long lLoginID, int nAlarmType, int nAudioIndex = 0);

//设置音频工作表
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetAudioWorkSheet(long lLoginID, int nAlarmType, const ZLNET_IVA_WORKSHEET* pAudioWorksheet, int nAudioIndex = 0);

//获取音频工作表
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetAudioWorkSheet(long lLoginID, int nAlarmType, ZLNET_IVA_WORKSHEET& audioWorksheet, int nAudioIndex = 0);

//重置设备参数（1为人数统计清除算法中的总人数）
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_ResetDev(long lLoginID, int nChn, int nCommand = 1);

//设置人数统计多人报警参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetMultiUserParam(long lLoginID, const ZLNET_IVA_STAFF_MULTIUSERPARAM* pMultiParam, int nSCIndex );

//获取人数统计多人报警参数
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetMultiUserParam(long lLoginID, ZLNET_IVA_STAFF_MULTIUSERPARAM& multiParam, int nSCIndex );

//////////////////////////////////////////////////////////////////////////

//获取设备能力信息
ZLNET_API BOOL CALL_METHOD ZLNET_Dev_Enable(long lLoginID, ZLNET_DEVICE_ENABLE& devEnable);

//获取NVR通道模式
ZLNET_API BOOL CALL_METHOD ZLNET_Nvr_GetChannelMode(long lLoginID, ZLNET_NVR_CHANNEL_MODE_SUPPORT& chMode);

//设置NVR通道模式
ZLNET_API BOOL CALL_METHOD ZLNET_Nvr_SetChannelMode(long lLoginID, ZLNET_NVR_CHANNEL_MODE_SUPPORT* pChMode);

//获取NVR网络通道状态
ZLNET_API BOOL CALL_METHOD ZLNET_Nvr_GetNvrChnState(long lLoginID, ZLNET_NVR_STATE_NET &chnState);

//获取高清IPC视频参数配置
ZLNET_API BOOL CALL_METHOD ZLNET_HDIPC_GetVideoParam(long lLoginID, ZLNET_VIDEO_PARAM& videoParam);

//设置视频高清IPC视频参数配置
ZLNET_API BOOL CALL_METHOD ZLNET_HDIPC_SetVideoParam(long lLoginID, ZLNET_VIDEO_PARAM* pVideoParam);

//获取UPNP连接状态
ZLNET_API BOOL CALL_METHOD ZLNET_GetUpnpState(long lLoginID, ZLNET_NET_UPNP_STATE& upnpState);

//获取RTSP配置
ZLNET_API BOOL CALL_METHOD ZLNET_GetRtspCfg(long lLoginID, ZLNET_DEV_RTSP_CONFIG& rtspCfg);

//获取wifi使能
ZLNET_API BOOL CALL_METHOD ZLNET_GetWifiEnable(long lLoginID, ZLNET_WIFI_ENABLE& wifiEnable);

//设置wifi使能
ZLNET_API BOOL CALL_METHOD ZLNET_SetWifiEnable(long lLoginID, ZLNET_WIFI_ENABLE* pWifiEnable);

//获取wifi连接方式
ZLNET_API BOOL CALL_METHOD ZLNET_GetWifiConnType(long lLoginID, ZLNET_WIFI_CONNECTION_TYPE& wifiType);

//设置wifi连接方式
ZLNET_API BOOL CALL_METHOD ZLNET_SetWifiConnType(long lLoginID, ZLNET_WIFI_CONNECTION_TYPE* pWifiType);

//获取wifi参数
ZLNET_API BOOL CALL_METHOD ZLNET_GetWifiCfg(long lLoginID, ZLNET_DEV_WIFI_CFG& wifiCfg);

//设置wifi参数
ZLNET_API BOOL CALL_METHOD ZLNET_SetWifiCfg(long lLoginID, ZLNET_DEV_WIFI_CFG* pWifiCfg);

//扫描路由网点信息
ZLNET_API BOOL CALL_METHOD ZLNET_ScanWifiNetwork(long lLoginID, ZLNETl_WIFI_NETWORK_INFO& networkInfo);

//DDNS注册
ZLNET_API BOOL CALL_METHOD ZLNET_DdnsRegister(long lLoginID, ZLNET_DDNS_REGISTER_INFO* pDdnsRegisterInfo);

//获取私网穿透配置
ZLNET_API BOOL CALL_METHOD ZLNET_GetDevStunCfg(long lLoginID, ZLNET_DEV_STUN_CONFIG& devStunCfg);

//获取DDNS状态
ZLNET_API BOOL CALL_METHOD ZLNET_GetDdnsState(long lLoginID, ZLNET_DDNS_STATE& ddnsState);

//设置私网穿透配置
ZLNET_API BOOL CALL_METHOD ZLNET_SetDevStunCfg(long lLoginID, ZLNET_DEV_STUN_CONFIG* pDevStunCfg);

//获取私网穿透状态
ZLNET_API BOOL CALL_METHOD ZLNET_GetDevStunState(long lLoginID, ZLNET_DEV_STUN_STATE& devStunState);

//获取默认图像颜色
ZLNET_API BOOL CALL_METHOD ZLNET_GetDefaultColor(long lLoginID, ZLNET_COLOR_CFG &defColor);

//获取云台模拟控制配置
ZLNET_API BOOL CALL_METHOD ZLNET_GetPtzSimulationCtrlCfg(long lLoginID, ZLNET_485_SIMULATION_CTRL_CFG& ptzSimulation);

//设置云台模拟控制配置
ZLNET_API BOOL CALL_METHOD ZLNET_SetPtzSimulationCtrlCfg(long lLoginID, ZLNET_485_SIMULATION_CTRL_CFG* pPtzSimulation);

//获取球机视频参数
ZLNET_API BOOL CALL_METHOD ZLNET_GetDomeCameraVideoParam(long lLoginID, ZLNET_DOME_CAMERA_VIDEO_PARAM& videoParam);

//设置球机视频参数
ZLNET_API BOOL CALL_METHOD ZLNET_SetDomeCameraVideoParam(long lLoginID, ZLNET_DOME_CAMERA_VIDEO_PARAM* pVideoParam);


//侦听反向连接信息
ZLNET_API LONG CALL_METHOD ZLNET_ListenRevLink(long lLoginID, fZLRevLink cbRevLink, DWORD dwUser);

//停止侦听反向连接信息
ZLNET_API BOOL CALL_METHOD ZLNET_StopRevLink(long lLoginID);

//设置反向连接服务器信息(注意: 要侦听返回信息的话, 一定要在ZLNET_ListenRevLink之后调用)
ZLNET_API BOOL CALL_METHOD ZLNET_SetRevLink(long lLoginID, ZLNET_REV_LINK& networkInfo);

//获取AEV配置
ZLNET_API BOOL CALL_METHOD ZLNET_GetAebGbCfg(long lLoginID, ZLNET_AEB_GB_PROTOCOL& aebGbCfg);

//设置AEV配置
ZLNET_API BOOL CALL_METHOD ZLNET_SetAebGbCfg(long lLoginID, ZLNET_AEB_GB_PROTOCOL* pAebGbCfg);

//获取康联网络配置
ZLNET_API BOOL CALL_METHOD ZLNET_GetKonlanNetCfg(long lLoginID, ZLNET_KONLAN_NET_CONFIG& konlanCfg);

//设置康联网络配置
ZLNET_API BOOL CALL_METHOD ZLNET_SetKonlanNetCfg(long lLoginID, ZLNET_KONLAN_NET_CONFIG* pKonlanCfg);

//获取串口类型
ZLNET_API BOOL CALL_METHOD ZLNET_GetComType(long lLoginID, ZLNET_COM_TYPE& comType);

//设置串口类型
ZLNET_API BOOL CALL_METHOD ZLNET_SetComType(long lLoginID, ZLNET_COM_TYPE* pComType);

//获取通道录像状态
ZLNET_API BOOL CALL_METHOD ZLNET_GetChannelRecordState(long lLoginID, ZLNET_CHANNEL_RECORD_STATE& recordState);

#ifdef __cplusplus
}
#endif

#endif // ZLNETSDK_H