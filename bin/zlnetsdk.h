
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

//#define RELEASE_HEADER	//����ͷ�ļ�
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

#else	//�ڲ�����
#include "../netsdk/osIndependent.h"
#endif

#endif


#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************
 ** ��������
 ***********************************************************************/
#define ZLNET_SERIALNO_LEN 			    48			// �豸���к��ַ�����
#define ZLNET_MAX_DISKNUM 				256			// ���Ӳ�̸���
#define ZLNET_MAX_SDCARDNUM			    32			// ���SD������
#define ZLNET_MAX_BURNING_DEV_NUM		32			// ����¼�豸����
#define ZLNET_BURNING_DEV_NAMELEN		32			// ��¼�豸������󳤶�
#define ZLNET_MAX_LINK 				    6
#define ZLNET_MAX_CHANNUM 			    32			// ���ͨ������
#define ZLNET_MAX_ALARMIN 		    	128			// ��󱨾��������
#define ZLNET_MAX_ALARMOUT 			    64			// ��󱨾��������
#define ZLNET_MAX_RIGHT_NUM			    200			// �û�Ȩ�޸�������
#define ZLNET_MAX_GROUP_NUM			    20			// �û����������
#define ZLNET_MAX_USER_NUM		    	200			// �û���������
#define ZLNET_RIGHT_NAME_LENGTH		    32			// Ȩ��������
#define ZLNET_USER_NAME_LENGTH	    	8			// �û�������
#define ZLNET_USER_PSW_LENGTH			8			// �û����볤��
#define ZLNET_MEMO_LENGTH				32			// ��ע����
#define ZLNET_MAX_STRING_LEN			128
#define ZLNET_DVR_SERIAL_RETURN		    1			// �豸�������кŻص�
#define ZLNET_DVR_DISCONNECT			-1			// ��֤�ڼ��豸���߻ص�
#define ZLNET_MAX_STRING_LINE_LEN		6			// �������
#define ZLNET_MAX_PER_STRING_LEN		20			// ÿ����󳤶�
#define ZLNET_MAX_MAIL_NAME_LEN	    	64			// �µ��ʼ��ṹ��֧�ֵ��û�������
#define ZLNET_MAX_MAIL_PSW_LEN			64			// �µ��ʼ��ṹ��֧�ֵ����볤��

// Զ�����ýṹ����س���
#define ZLNET_MAX_MAIL_ADDR_LEN		    128			// �ʼ���(��)��ַ��󳤶�
#define ZLNET_MAX_MAIL_SUBJECT_LEN		64			// �ʼ�������󳤶�
#define ZLNET_MAX_IPADDR_LEN			16			// IP��ַ�ַ�������
#define ZLNET_MACADDR_LEN				40			// MAC��ַ�ַ�������
#define ZLNET_MAX_URL_LEN				128			// URL�ַ�������
#define ZLNET_VER_SOFTWARE				128			// ����汾��
#define ZLNET_MAX_DEV_ID_LEN			48			// ���������󳤶�
#define	ZLNET_MAX_HOST_NAMELEN			64			// ���������ȣ�
#define ZLNET_MAX_HOST_PSWLEN			32			// ���볤��
#define ZLNET_MAX_NAME_LEN				16			// ͨ�������ַ�������
#define ZLNET_MAX_ETHERNET_NUM			2			// ��̫����������
#define	ZLNET_DEV_SERIALNO_LEN			48			// ���к��ַ�������
#define ZLNET_DEV_TYPE_LEN				32			// �豸�����ַ�������
#define ZLNET_N_WEEKS					7			// һ�ܵ�����	
#define ZLNET_N_TSECT					6			// ͨ��ʱ��θ���
#define ZLNET_N_REC_TSECT				6			// ¼��ʱ��θ���
#define ZLNET_N_COL_TSECT				2			// ��ɫʱ��θ���	
#define ZLNET_CHAN_NAME_LEN			    32			// ͨ�������ȣ�DVR DSP�������ƣ����32�ֽ�		
#define ZLNET_N_ENCODE_AUX				3			// ��չ��������	
#define ZLNET_N_TALK					1			// ���Խ�ͨ������
#define ZLNET_N_COVERS					1			// �ڵ��������	
#define ZLNET_N_ALARM_TSECT		    	2			// ������ʾʱ��θ���
#define ZLNET_MAX_ALARMOUT_NUM			16			// ��������ڸ�������
#define ZLNET_MAX_AUDIO_IN_NUM			16			// ��Ƶ����ڸ�������
#define ZLNET_MAX_VIDEO_IN_NUM			32			// ��Ƶ����ڸ�������
#define ZLNET_MAX_ALARM_IN_NUM			16			// ��������ڸ�������
#define ZLNET_MAX_DISK_NUM				16			// Ӳ�̸������ޣ��ݶ�Ϊ16
#define ZLNET_MAX_DECODER_NUM			32			// ������(485)��������	
#define ZLNET_MAX_232FUNCS				10			// 232���ڹ��ܸ�������
#define ZLNET_MAX_232_NUM				2			// 232���ڸ�������
#define ZLNET_MAX_DECPRO_LIST_SIZE		100			// ������Э���б��������
#define ZLNET_FTP_MAXDIRLEN		    	240			// FTP�ļ�Ŀ¼��󳤶�
#define ZLNET_MATRIX_MAXOUT		    	16			// ���������������
#define ZLNET_TOUR_GROUP_NUM			6			// ���������������
#define ZLNET_MAX_DDNS_NUM				10			// �豸֧�ֵ�ddns������������
#define ZLNET_MAX_SERVER_TYPE_LEN		32			// ddns���������ͣ�����ַ�������
#define ZLNET_MAX_DOMAIN_NAME_LEN		256			// ddns����������ַ�������
#define ZLNET_MAX_DDNS_ALIAS_LEN		32			// ddns����������������ַ�������
#define ZLNET_MOTION_ROW				32			// ��̬������������
#define ZLNET_MOTION_COL				32			// ��̬������������
#define	ZLNET_FTP_USERNAME_LEN			64			// FTP���ã��û�����󳤶�
#define	ZLNET_FTP_PASSWORD_LEN			64			// FTP���ã�������󳤶�
#define	ZLNET_TIME_SECTION				2			// FTP���ã�ÿ��ʱ��θ���
#define ZLNET_FTP_MAX_PATH				240			// FTP���ã��ļ�·������󳤶�
#define ZLNET_INTERVIDEO_UCOM_CHANID	32			// ƽ̨�������ã�U��ͨͨ��ID
#define ZLNET_INTERVIDEO_UCOM_DEVID	    32			// ƽ̨�������ã�U��ͨ�豸ID
#define ZLNET_INTERVIDEO_UCOM_REGPSW	16			// ƽ̨�������ã�U��ͨע������
#define ZLNET_INTERVIDEO_UCOM_USERNAME	32			// ƽ̨�������ã�U��ͨ�û���
#define ZLNET_INTERVIDEO_UCOM_USERPSW	32			// ƽ̨�������ã�U��ͨ����
#define ZLNET_INTERVIDEO_NSS_IP	    	32			// ƽ̨�������ã�������άIP
#define ZLNET_INTERVIDEO_NSS_SERIAL 	32			// ƽ̨�������ã�������άserial
#define ZLNET_INTERVIDEO_NSS_USER		32			// ƽ̨�������ã�������άuser
#define ZLNET_INTERVIDEO_NSS_PWD		50			// ƽ̨�������ã�������άpassword
#define ZLNET_INTERVIDEO_MR_ID			32			// ƽ̨�������ã�����ID
#define ZLNET_INTERVIDEO_MR_USERPSW		32			// ƽ̨�������ã������û�������
#define ZLNET_MAX_VIDEO_COVER_NUM		16			// �ڵ�����������
#define ZLNET_MAX_WATERMAKE_DATA		4096		// ˮӡͼƬ������󳤶�
#define ZLNET_MAX_WATERMAKE_LETTER		128			// ˮӡ������󳤶�
#define ZLNET_MAX_WLANDEVICE_NUM		10			// ����������������豸����
#define ZLNET_MAX_ALARM_NAME			64			// ��ַ����
#define ZLNET_MAX_REGISTER_SERVER_NUM	10			// ����ע�����������
#define ZLNET_SNIFFER_FRAMEID_NUM		6			// 6��FRAME ID ѡ��
#define ZLNET_SNIFFER_CONTENT_NUM		4			// ÿ��FRAME��Ӧ��4��ץ������
#define ZLNET_SNIFFER_CONTENT_NUM_EX   	8			// ÿ��FRAME��Ӧ��8��ץ������
#define ZLNET_SNIFFER_PROTOCOL_SIZE 	20			// Э�����ֳ���
#define ZLNET_MAX_PROTOCOL_NAME_LENGTH  20
#define ZLNET_SNIFFER_GROUP_NUM	    	4			// 4��ץ������
#define ZLNET_MAX_PATH_STOR			    240			// Զ��Ŀ¼�ĳ���
#define ZLNET_ALARM_OCCUR_TIME_LEN		40			// �µı����ϴ�ʱ��ĳ���
#define ZLNET_VIDEO_OSD_NAME_NUM		64			// ���ӵ����Ƴ��ȣ�Ŀǰ֧��32��Ӣ�ģ�16������
#define ZLNET_VIDEO_CUSTOM_OSD_NUM		8			// ֧�ֵ��Զ�����ӵ���Ŀ��������ʱ���ͨ��
#define ZLNET_CONTROL_AUTO_REGISTER_NUM 100        // ֧�ֶ�������ע��������ĸ���
#define ZLNET_MMS_RECEIVER_NUM          100        // ֧�ֶ��Ž����ߵĸ���
#define ZLNET_MMS_SMSACTIVATION_NUM     100        // ֧�ֶ��ŷ����ߵĸ���
#define ZLNET_MMS_DIALINACTIVATION_NUM  100        // ֧�ֲ��ŷ����ߵĸ���
#define ZLNET_MAX_ALARMOUT_NUM_EX		32			// ��������ڸ���������չ
#define ZLNET_MAX_VIDEO_IN_NUM_EX		32			// ��Ƶ����ڸ���������չ
#define ZLNET_MAX_ALARM_IN_NUM_EX		32			// ��������ڸ�������
#define ZLNET_MAX_IPADDR_OR_DOMAIN_LEN	64			// IP��ַ�ַ�������������󳤶�
#define	ZLNET_NVR_PASSWORD_LEN			64			// NVR������󳤶�
#define ZLNET_DEVICE_ENABLE_NUM			64			// �豸��������
#define ZLENT_DEVICE_ENABLE_STR_LEN		8			// �豸�����ַ�������		
#define ZLNET_LATTICE_LEN				2560		// ������32 * 24 * 24 / 8
#define ZLNET_CHANNEL_MODE_MAX_NUM		8			// ͨ��ģʽ������
#define ZLNET_RTSP_URL_MAX_NUM			10			// URL������ַ�������
#define ZLNET_WIFI_PSW_LENGTH			64			// wifi���볤��	
#define ZLNET_WIFI_NET_CARD_LEN			12			// ��������������
#define ZLNET_WIFI_JUNCTION_LEN			36			// ���ӵ����Ƴ���
#define ZLNET_WIFI_PROTOCOL_LNE			8			// Э����ܷ�ʽ����
#define ZLNET_MAX_WIFI_INFO_NUM			20			// wifi���ɨ�����
#define ZLNET_DEVICE_STUN_USERNAME		32			// ˽����͸�û�����󳤶�
#define ZLNET_DEVICE_STUN_PASSWORD		32			// ˽����͸������󳤶�
#define ZLNET_DEVICE_STUN_SERVERIP		128			// ˽����͸������IP������������
#define ZLNET_AEB_IP_LEN				32			// ���籴��GB28181 IP����
#define ZLNET_AEB_ID_LEN				32			// ���籴��GB28181 ID����
#define ZLNET_AEB_DOMAIN_LEN			128			// ���籴��GB28181 ��������
#define ZLNET_AEB_PSW_LEN				32			// ���籴��GB28181 ���볤��
#define ZLNET_AEB_INFO_LEN				32			// ���籴��GB28181 ��Ϣ����
#define ZLNET_AEB_ALARM_INFO_NUM		32			// AEB GB28181��󱨾�������Ϣ����
#define ZLNET_KONLAN_IP_LEN				32			// ���� IP����
#define ZLNET_KONLAN_ID_LEN				32			// ���� ID����

// ��ѯ���ͣ���ӦZLNET_QueryDevState�ӿ�
#define ZLNET_DEVSTATE_COMM_ALARM		0x0001		// ��ѯ��ͨ����״̬(�����ⲿ��������Ƶ��ʧ����̬���)
#define ZLNET_DEVSTATE_SHELTER_ALARM	0x0002		// ��ѯ�ڵ�����״̬
#define ZLNET_DEVSTATE_RECORDING		0x0003		// ��ѯ¼��״̬
#define ZLNET_DEVSTATE_DISK			    0x0004		// ��ѯӲ����Ϣ
#define ZLNET_DEVSTATE_RESOURCE		    0x0005		// ��ѯϵͳ��Դ״̬
#define ZLNET_DEVSTATE_BITRATE			0x0006		// ��ѯͨ������
#define ZLNET_DEVSTATE_CONN			    0x0007		// ��ѯ�豸����״̬
#define ZLNET_DEVSTATE_PROTOCAL_VER	    0x0008		// ��ѯ����Э��汾�ţ�pBuf = int*
#define ZLNET_DEVSTATE_TALK_ECTYPE		0x0009		// ��ѯ�豸֧�ֵ������Խ���ʽ�б����ṹ��ZLNET_DEV_TALKFORMAT_LIST
#define ZLNET_DEVSTATE_SD_CARD			0x000A		// ��ѯSD����Ϣ(IPC���Ʒ)
#define ZLNET_DEVSTATE_BURNING_DEV		0x000B		// ��ѯ��¼����Ϣ
#define ZLNET_DEVSTATE_BURNING_PROGRESS 0x000C		// ��ѯ��¼����
#define ZLNET_DEVSTATE_PLATFORM		    0x000D		// ��ѯ�豸֧�ֵĽ���ƽ̨
#define ZLNET_DEVSTATE_CAMERA			0x000E		// ��ѯ����ͷ������Ϣ(IPC���Ʒ)��pBuf = ZLNET_DEV_CAMERA_INFO *�������ж���ṹ��
#define ZLNET_DEVSTATE_SOFTWARE		    0x000F		// ��ѯ�豸����汾��Ϣ
#define ZLNET_DEVSTATE_LANGUAGE         0x0010		// ��ѯ�豸֧�ֵ���������
#define ZLNET_DEVSTATE_DSP				0x0011		// ��ѯDSP��������
#define	ZLNET_DEVSTATE_OEM				0x0012		// ��ѯOEM��Ϣ
#define	ZLNET_DEVSTATE_NET				0x0013		// ��ѯ��������״̬��Ϣ
#define ZLNET_DEVSTATE_TYPE				0x0014		// ��ѯ�豸����
#define ZLNET_DEVSTATE_SNAP				0x0015		// ��ѯץͼ��������(IPC���Ʒ)
#define ZLNET_DEVSTATE_RECORD_TIME		0x0016		// ��ѯ����¼��ʱ������¼��ʱ��
#define ZLNET_DEVSTATE_NET_RSSI		    0x0017      // ��ѯ���������ź�ǿ�ȣ����ṹ��ZLNET_DEV_WIRELESS_RSS_INFO
#define ZLNET_DEVSTATE_BURNING_ATTACH	0x0018		// ��ѯ������¼ѡ��
#define ZLNET_DEVSTATE_BACKUP_DEV		0x0019		// ��ѯ�����豸�б�
#define ZLNET_DEVSTATE_BACKUP_DEV_INFO	0x001a		// ��ѯ�����豸��ϸ��Ϣ
#define ZLNET_DEVSTATE_BACKUP_FEEDBACK	0x001b		// ���ݽ��ȷ���
#define ZLNET_DEVSTATE_ATM_QUERY_TRADE  0x001c		// ��ѯATM��������
#define ZLNET_DEVSTATE_SIP				0x001d		// ��ѯsip״̬
#define ZLNET_DEVSTATE_HARDWARE_ID      0x001e      // ��ѯӲ��ID
#define ZLNET_DEVSTATE_PRODUCT_TYPE     0x001F      // ��ѯ��Ʒ����
#define ZLNET_DEVSTATE_SERIAL			0x0020      // ��ѯ�豸���к�

// �������ͣ���ӦZLNET_GetDevConfig��ZLNET_SetDevConfig�ӿ�
#define ZLNET_DEV_DEVICECFG				0x0001		// �豸��������
#define ZLNET_DEV_NETCFG				0x0002		// ��������
#define ZLNET_DEV_CHANNELCFG			0x0003		// ͼ��ͨ������
#define ZLNET_DEV_PREVIEWCFG 			0x0004		// Ԥ����������
#define ZLNET_DEV_RECORDCFG				0x0005		// ¼������
#define ZLNET_DEV_COMMCFG				0x0006		// ������������
#define ZLNET_DEV_ALARMCFG 				0x0007		// ������������
#define ZLNET_DEV_TIMECFG 				0x0008		// DVRʱ������
#define ZLNET_DEV_TALKCFG				0x0009		// �Խ���������
#define ZLNET_DEV_AUTOMTCFG				0x000A		// �Զ�ά������		
#define	ZLNET_DEV_VEDIO_MARTIX			0x000B		// ����������Ʋ�������	
#define ZLNET_DEV_MULTI_DDNS			0x000C		// ��ddns����������
#define ZLNET_DEV_SNAP_CFG				0x000D		// ץͼ�������
#define ZLNET_DEV_WEB_URL_CFG			0x000E		// HTTP·������
#define ZLNET_DEV_FTP_PROTO_CFG			0x000F		// FTP�ϴ�����
#define ZLNET_DEV_INTERVIDEO_CFG		0x0010		// ƽ̨�������ã���ʱchannel��������ƽ̨���ͣ�
													// channel=4�� �������������أ�channel=10������������ά��channel=11������U��ͨ
#define ZLNET_DEV_VIDEO_COVER			0x0011		// �����ڵ�����
#define ZLNET_DEV_TRANS_STRATEGY		0x0012		// ����������ã���������\����������
#define ZLNET_DEV_DOWNLOAD_STRATEGY		0x0013		// ¼�����ز������ã���������\��ͨ����
#define ZLNET_DEV_WATERMAKE_CFG			0x0014		// ͼ��ˮӡ����
#define ZLNET_DEV_WLAN_CFG				0x0015		// ������������
#define ZLNET_DEV_WLAN_DEVICE_CFG		0x0016		// ���������豸����
#define ZLNET_DEV_REGISTER_CFG			0x0017		// ����ע���������
#define ZLNET_DEV_CAMERA_CFG			0x0018		// ����ͷ��������
#define ZLNET_DEV_INFRARED_CFG 			0x0019		// ���ⱨ������
#define ZLNET_DEV_SNIFFER_CFG			0x001A		// Snifferץ������
#define ZLNET_DEV_MAIL_CFG				0x001B		// �ʼ�����
#define ZLNET_DEV_DNS_CFG				0x001C		// DNS����������
#define ZLNET_DEV_NTP_CFG				0x001D		// NTP����
#define ZLNET_DEV_AUDIO_DETECT_CFG		0x001E		// ��Ƶ�������
#define ZLNET_DEV_STORAGE_STATION_CFG   0x001F      // �洢λ������
#define ZLNET_DEV_PTZ_OPT_CFG			0x0020		// ��̨��������(�Ѿ��ϳ�����ʹ��ZLNET_GetPtzOptAttr��ȡ��̨��������)
#define ZLNET_DEV_DST_CFG				0x0021      // ����ʱ����
#define ZLNET_DEV_ALARM_CENTER_CFG		0x0022		// ������������
#define ZLNET_DEV_VIDEO_OSD_CFG         0x0023		// ��ƵOSD��������
#define ZLNET_DEV_CDMAGPRS_CFG          0x0024		// CDMA\GPRS��������
#define ZLNET_DEV_IPFILTER_CFG          0x0025		// IP��������
#define ZLNET_DEV_TALK_ENCODE_CFG       0x0026      // �����Խ���������
#define ZLNET_DEV_RECORD_PACKET_CFG     0X0027      // ¼������������
#define ZLNET_DEV_MMS_CFG               0X0028		// ����MMS���� 
#define ZLNET_DEV_SMSACTIVATION_CFG		0X0029		// ���ż���������������
#define ZLNET_DEV_DIALINACTIVATION_CFG	0X002A		// ���ż���������������
#define ZLNET_DEV_FILETRANS_STOP		0x002B		// ֹͣ�ļ��ϴ�
#define ZLNET_DEV_FILETRANS_BURN		0x002C		// ��¼�ļ��ϴ�
#define ZLNET_DEV_SNIFFER_CFG_EX		0x0030		// ����ץ������
#define ZLNET_DEV_DOWNLOAD_RATE_CFG		0x0031		// �����ٶ�����
#define ZLNET_DEV_PANORAMA_SWITCH_CFG	0x0032		// ȫ���л���������
#define ZLNET_DEV_LOST_FOCUS_CFG		0x0033		// ʧȥ���㱨������
#define ZLNET_DEV_ALARM_DECODE_CFG		0x0034		// ��������������
#define ZLNET_DEV_VIDEOOUT_CFG          0x0035      // ��Ƶ�����������
#define ZLNET_DEV_POINT_CFG				0x0036		// Ԥ�Ƶ�ʹ������
#define ZLNET_DEV_IP_COLLISION_CFG      0x0037      // Ip��ͻ��ⱨ������
#define ZLNET_DEV_OSD_ENABLE_CFG		0x0038		// OSD����ʹ������
#define ZLNET_DEV_LOCALALARM_CFG 		0x0039		// ���ر�������(�ṹ��ZLNET_ALARMIN_CFG_EX)
#define ZLNET_DEV_NETALARM_CFG 			0x003A		// ���籨������(�ṹ��ZLNET_ALARMIN_CFG_EX)
#define ZLNET_DEV_MOTIONALARM_CFG 		0x003B		// ���챨������(�ṹ��ZLNET_MOTION_DETECT_CFG_EX)
#define ZLNET_DEV_VIDEOLOSTALARM_CFG 	0x003C		// ��Ƶ��ʧ��������(�ṹ��ZLNET_VIDEO_LOST_CFG_EX)
#define ZLNET_DEV_BLINDALARM_CFG 		0x003D		// ��Ƶ�ڵ���������(�ṹ��ZLNET_BLIND_CFG_EX)
#define ZLNET_DEV_DISKALARM_CFG 		0x003E		// Ӳ�̱�������(�ṹ��ZLNET_DISK_ALARM_CFG_EX)
#define ZLNET_DEV_NETBROKENALARM_CFG 	0x003F		// �����жϱ�������(�ṹ��ZLNET_NETBROKEN_ALARM_CFG_EX)
#define ZLNET_DEV_ENCODER_CFG		    0x0040      // ����ͨ����ǰ�˱�������Ϣ�����DVRʹ�ã��ṹ��ZLNET_DEV_ENCODER_CFG��
#define ZLNET_DEV_TV_ADJUST_CFG         0x0041      // TV�������ã�channel����TV��(0��ʼ)�����ͽṹ�壩
#define ZLNET_DEV_ABOUT_VEHICLE_CFG		0x0042		// ����������ã���������ʹ��
#define ZLNET_DEV_ATM_OVERLAY_ABILITY	0x0043		// ��ȡatm����֧��������Ϣ
#define ZLNET_DEV_ATM_OVERLAY_CFG		0x0044		// atm�������ã���atm����
#define ZLNET_DEV_DECODER_TOUR_CFG		0x0045		// ������������Ѳ����
#define ZLNET_DEV_SIP_CFG				0x0046		// SIP����

#define ZLNET_DEV_LATTICE				0x0047		// ͨ��������
#define ZLNET_DEV_NVR_CHANNEL_MODE		0x0048		// NVRͨ��ģʽ

#define ZLNET_DEV_USER_END_CFG			1000

// �������ͣ���ӦZLNET_StartListen�ӿ�
#define ZLNET_COMM_ALARM				0x1100		// ���汨��(�����ⲿ��������Ƶ��ʧ����̬���)
#define ZLNET_SHELTER_ALARM				0x1101		// ��Ƶ�ڵ�����
#define ZLNET_DISK_FULL_ALARM			0x1102		// Ӳ��������
#define ZLNET_DISK_ERROR_ALARM			0x1103		// Ӳ�̹��ϱ���
#define ZLNET_SOUND_DETECT_ALARM		0x1104		// ��Ƶ��ⱨ��
#define ZLNET_ALARM_DECODER_ALARM		0x1105		// ��������������
#define ZLNET_ALARM_IDVR_ALARM			0x1106		// ����ATM����
#define ZLNET_ALARM_IDVR_STAFFCOUNT		0x1107		// ������Աͳ����Ϣ
#define ZLNET_ALARM_IDVR_PLATEID		0x1108		// ���ܳ�����Ϣ

// ��չ�������ͣ���ӦZLNET_StartListenEx�ӿ�
#define ZLNET_ALARM_ALARM_EX			0x2101		// �ⲿ����
#define ZLNET_MOTION_ALARM_EX			0x2102		// ��̬��ⱨ��
#define ZLNET_VIDEOLOST_ALARM_EX		0x2103		// ��Ƶ��ʧ����
#define ZLNET_SHELTER_ALARM_EX			0x2104		// ��Ƶ�ڵ�����
#define ZLNET_SOUND_DETECT_ALARM_EX		0x2105		// ��Ƶ��ⱨ��
#define ZLNET_DISKFULL_ALARM_EX			0x2106		// Ӳ��������
#define ZLNET_DISKERROR_ALARM_EX		0x2107		// ��Ӳ�̱���
#define ZLNET_ENCODER_ALARM_EX			0x210A		// ����������
#define ZLNET_URGENCY_ALARM_EX			0x210B		// ��������
#define ZLNET_WIRELESS_ALARM_EX			0x210C		// ���߱���
#define ZLNET_NEW_SOUND_DETECT_ALARM_EX 0x210D		// ����Ƶ��ⱨ����������Ϣ�Ľṹ���ZLNET_NEW_SOUND_ALARM_STATE��
#define ZLNET_ALARM_DECODER_ALARM_EX	0x210E		// ��������������
#define ZLNET_DECODER_DECODE_ABILITY	0x210F		// ��������������������
#define ZLNET_FDDI_DECODER_ABILITY		0x2110		// ���˱�����״̬����
#define ZLNET_PANORAMA_SWITCH_ALARM_EX	0x2111		// �л���������
#define ZLNET_LOSTFOCUS_ALARM_EX		0x2112		// ʧȥ���㱨��
#define ZLNET_OEMSTATE_EX				0x2113		// oem��ͣ״̬
#define ZLNET_DSP_ALARM_EX				0x2114		// DSP����
#define ZLNET_ATMPOS_BROKEN_EX			0x2115		// atm��pos���Ͽ������� 0�����ӶϿ� 1����������
#define ZLNET_RECORD_CHANGED_EX			0x2116		// ¼��״̬�仯����
#define ZLNET_DEVICE_REBOOT_EX			0x2118		// �豸��������
#define ZLNET_CONFIG_CHANGED_EX			0x2117		// ���÷����仯����

// �¼�����
#define ZLNET_CONFIG_RESULT_EVENT_EX	0x3000		// �޸����õķ����룻���ؽṹ��DEV_SET_RESULT
#define ZLNET_REBOOT_EVENT_EX			0x3001		// �豸�����¼������δ�������������ǰ�޸ĵ����ò���������Ч
#define ZLNET_AUTO_TALK_START_EX		0x3002		// �豸�������뿪ʼ�����Խ�
#define ZLNET_AUTO_TALK_STOP_EX			0x3003		// �豸����ֹͣ�����Խ�
#define ZLNET_CONFIG_CHANGE_EX			0x3004		// �豸���÷����ı�

// �����ϴ����ܵı������ͣ���ӦZLNET_StartService�ӿڡ�NEW_ALARM_UPLOAD�ṹ��.
#define ZLNET_UPLOAD_ALARM				0x4000		// �ⲿ����		
#define ZLNET_UPLOAD_MOTION_ALARM		0x4001		// ��̬��ⱨ��
#define ZLNET_UPLOAD_VIDEOLOST_ALARM	0x4002		// ��Ƶ��ʧ����
#define ZLNET_UPLOAD_SHELTER_ALARM		0x4003		// ��Ƶ�ڵ�����
#define ZLNET_UPLOAD_SOUND_DETECT_ALARM 0x4004		// ��Ƶ��ⱨ��
#define ZLNET_UPLOAD_DISKFULL_ALARM		0x4005		// Ӳ��������
#define ZLNET_UPLOAD_DISKERROR_ALARM	0x4006		// ��Ӳ�̱���
#define ZLNET_UPLOAD_ENCODER_ALARM		0x4007		// ����������
#define ZLNET_UPLOAD_DECODER_ALARM		0x400B		// ��������������
#define ZLNET_UPLOAD_EVENT				0x400C		// ��ʱ�ϴ���

// �첽�ӿڻص�����
#define ZLNET_RESPONSE_DECODER_CTRL_TV		0x00000001	// ��ӦZLNET_CtrlDecTVScreen�ӿ�
#define ZLNET_RESPONSE_DECODER_SWITCH_TV	0x00000002	// ��ӦZLNET_SwitchDecTVEncoder�ӿ�
#define ZLNET_RESPONSE_DECODER_PLAYBACK		0x00000003	// ��ӦZLNET_DecTVPlayback�ӿ�

// �ֱ����б�������ֱ�����������롢�����
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

// ����ģʽ�б����������ģʽ��������롢�����
#define ZLNET_CAPTURE_COMP_DIVX_MPEG4	0x00000001
#define ZLNET_CAPTURE_COMP_MS_MPEG4 	0x00000002
#define ZLNET_CAPTURE_COMP_MPEG2		0x00000004
#define ZLNET_CAPTURE_COMP_MPEG1		0x00000008
#define ZLNET_CAPTURE_COMP_H263			0x00000010
#define ZLNET_CAPTURE_COMP_MJPG			0x00000020
#define ZLNET_CAPTURE_COMP_FCC_MPEG4	0x00000040
#define ZLNET_CAPTURE_COMP_H264			0x00000080

// �������������������뱨������������������롢�����
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

// "�ָ�Ĭ������"���룬�ɽ����롢�����
#define ZLNET_RESTORE_COMMON			0x00000001	// ��ͨ����
#define ZLNET_RESTORE_CODING			0x00000002	// ��������
#define ZLNET_RESTORE_VIDEO				0x00000004	// ¼������
#define ZLNET_RESTORE_COMM				0x00000008	// ��������
#define ZLNET_RESTORE_NETWORK			0x00000010	// ��������
#define ZLNET_RESTORE_ALARM				0x00000020	// ��������
#define ZLNET_RESTORE_VIDEODETECT		0x00000040	// ��Ƶ���
#define ZLNET_RESTORE_PTZ				0x00000080	// ��̨����
#define ZLNET_RESTORE_OUTPUTMODE		0x00000100	// ���ģʽ
#define ZLNET_RESTORE_CHANNELNAME		0x00000200	// ͨ������
#define ZLNET_RESTORE_VIDEO_COLOR       0x00010000  // ��Ƶ��ɫ�����ָ�Ĭ��
#define ZLNET_RESTORE_ALL				0x80000000	// ȫ������

// ��̨�����б�
// ���ĸ��ֽ�����
#define ZLNET_PTZ_DIRECTION				0x00000001	// ����
#define ZLNET_PTZ_ZOOM					0x00000002	// �䱶
#define ZLNET_PTZ_FOCUS					0x00000004	// �۽�
#define ZLNET_PTZ_IRIS					0x00000008	// ��Ȧ
#define ZLNET_PTZ_ALARM					0x00000010	// ��������
#define ZLNET_PTZ_LIGHT					0x00000020	// �ƹ�
#define ZLNET_PTZ_SETPRESET				0x00000040	// ����Ԥ�õ�
#define ZLNET_PTZ_CLEARPRESET			0x00000080	// ���Ԥ�õ�
#define ZLNET_PTZ_GOTOPRESET			0x00000100	// ת��Ԥ�õ�
#define ZLNET_PTZ_AUTOPANON				0x00000200	// ˮƽ��ʼ
#define ZLNET_PTZ_AUTOPANOFF			0x00000400	// ˮƽ����
#define ZLNET_PTZ_SETLIMIT				0x00000800	// ���ñ߽�
#define ZLNET_PTZ_AUTOSCANON			0x00001000	// �Զ�ɨ�迪ʼ
#define ZLNET_PTZ_AUTOSCANOFF			0x00002000	// �Զ�ɨ�迪ֹͣ
#define ZLNET_PTZ_ADDTOUR				0x00004000	// ����Ѳ����
#define ZLNET_PTZ_DELETETOUR			0x00008000	// ɾ��Ѳ����
#define ZLNET_PTZ_STARTTOUR				0x00010000	// ��ʼѲ��
#define ZLNET_PTZ_STOPTOUR				0x00020000	// ����Ѳ��
#define ZLNET_PTZ_CLEARTOUR				0x00040000	// ɾ��Ѳ��
#define ZLNET_PTZ_SETPATTERN			0x00080000	// ����ģʽ
#define ZLNET_PTZ_STARTPATTERN			0x00100000	// ��ʼģʽ
#define ZLNET_PTZ_STOPPATTERN			0x00200000	// ֹͣģʽ
#define ZLNET_PTZ_CLEARPATTERN			0x00400000	// ���ģʽ
#define ZLNET_PTZ_POSITION				0x00800000	// ���ٶ�λ
#define ZLNET_PTZ_AUX					0x01000000	// ��������
#define ZLNET_PTZ_MENU					0x02000000	// ����˵�
#define ZLNET_PTZ_EXIT					0x04000000	// �˳�����˵�
#define ZLNET_PTZ_ENTER					0x08000000	// ȷ��
#define ZLNET_PTZ_ESC					0x10000000	// ȡ��
#define ZLNET_PTZ_MENUUPDOWN			0x20000000	// �˵����²���
#define ZLNET_PTZ_MENULEFTRIGHT			0x40000000	// �˵����Ҳ���
#define ZLNET_PTZ_OPT_NUM				0x80000000	// �����ĸ���
// ���ĸ��ֽ�����
#define ZLNET_PTZ_DEV					0x00000001	// ��̨����
#define ZLNET_PTZ_MATRIX				0x00000002	// �������

// ץͼ��Ƶ��������
#define ZLNET_CODETYPE_MPEG4			0
#define ZLNET_CODETYPE_H264				1
#define ZLNET_CODETYPE_JPG				2

// ���������б�
#define ZLNET_CAPTURE_BRC_CBR			0
#define ZLNET_CAPTURE_BRC_VBR			1
//#define ZLNET_CAPTURE_BRC_MBR			2

#define ZLNET_WEEKS_NUM				7		//һ������7��
#define ZLNET_TSECT_NUM				6		//ÿ��6��ʱ���
//����ATM
#define ZLNET_IVA_MAX_CHANNEL		4		//���ͨ����
#define ZLNET_IVA_MAX_NUM_ATMALARM_RECT		10		//���������
#define ZLNET_IVA_MAX_LOG_NUM				200		//�����־����
//�������ýṹ����س���
#define ZLNET_IVA_MAX_NUM_REGION				20		//�������������
#define ZLNET_IVA_MAX_AREA_WARN				10			//��౨����������
#define	ZLNET_IVA_MAX_NUM_KEYBOARD_REGION		1		//��������������
#define	ZLNET_IVA_MAX_NUM_CARDPORT_REGION		1		//���忨����������
#define	ZLNET_IVA_MAX_NUM_KEYMASK_REGION		1		//����������������
#define	ZLNET_IVA_MAX_NUM_HUMAN_REGION			1		//�����Ա���������
#define	ZLNET_IVA_MAX_NUM_FACEHUMAN_REGION		1		//���������������
#define	ZLNET_IVA_MAX_NUM_WORN_REGION			1		//������������
#define ZLNET_IVA_MAX_NUM_OBJSIZE				1		//��С���ߴ�	
#define ZLNET_IVA_MAX_POLYGON_POINT				20		//����ε���
#define ZLNET_IVA_MAX_NUM_DETECT_FACE_AREA		1		//���������������
#define ZLNET_IVA_MAX_NUM_FACE_AREA				3		//������������
#define ZLNET_IVA_MAX_NUM_LICENSE_PLATE			5		//�����������������
#define ZLNET_IVA_MAX_NUM_DETECT_LINE			1		//��Ա���������������
#define ZLNET_IVA_MAX_NUM_PROCESS_AREA			1		//��������������
#define ZLNET_IVA_MAX_SHIELDED_AREA_NUM			9		//��������������
#define ZLNET_IVA_MAX_ALARM_RULE_REGION_NUM		9		//��౨���������
#define ZLNET_IVA_MAX_SSB_AREA					20		//��������������(1) + ��������(10) + ��������(9)
#define ZLNET_IVA_MAX_NUM_SSBALARM				10		//�������б�������
#define ZLNET_IVA_MAX_NUM_FACEALARM			10		//������������
#define ZLNET_IVA_MAX_BZS_PROCESS_NUM	ZLNET_IVA_MAX_NUM_PROCESS_AREA + ZLNET_IVA_MAX_SHIELDED_AREA_NUM
#define ZLNET_IVA_MAX_SSB_WITHDRAWALS_NUM		9		//���������ȡ������
#define ZLNET_IVA_MAX_SSB_HALL_SHIELDED_NUM	    10   	//��������������������
#define ZLNET_IVA_MAX_SSB_ROOM_SHIELDED_NUM		10		//�ӳ�����������������
#define ZLNET_IVA_MAX_SSB_POLYGON_POINT			10		//SSB�ӳ������ε���
#define ZLNET_IVA_MAX_BZS_POLYGON_POINT			10		//�ܽ����ε���
#define ZLNET_IVA_MAX_BZS_RULE_REGION			18		//�ܽ�������
//GPIO
#define	ZLNET_IVA_MAX_GPI_NUM					4		//GPIO����˿�����
#define ZLNET_IVA_MAX_GPO_NUM					2		//GPIO����˿�����

#define ZLNET_IVA_MAX_REGIST_NUM				16		// �豸֧�ֵ��������ע��IP����
#define ZLNET_IVA_MAX_ONLINE					10		// ��������û�
//�㷨����
#define ZLNET_IVA_ARITHMETIC_DEBUG_LEN			2		//�㷨���Ը���
#define MAX_NUM_SSB_TRACKEDINFO					10		//SSB�㷨������Ϣ�ĸ���
//�켣����
#define MAX_TRACK_OBJ_NUM						10		//�켣��������������			
#define MAX_TRACK_COUNT							120		//�켣���ٻص�����ϴ�����
//������Աͳ��
#define ZLNET_IVA_MAX_NUM_STAFFCOUNT_RECT		20		//��Աͳ�������������
#define ZLNET_IVA_MAX_NUM_STAFFCOUNT_PIC		4		//��Աͳ��ͼƬ�������
//��������
#define ZLNET_IVA_MAX_FACE_AREA_NUM				1		//�����������������
#define ZLNET_IVA_MAX_FACE_OVERLAY_NUM			1		//������������������
#define ZLNET_IVA_MAX_NUM_FACE_TRACKEDINFO				10		//�����㷨������Ϣ�������
#define ZLNET_IVA_MAX_FACE_SHIELDED_AREA_NUM			10		//��������������

//�û���Ƶ
#define ZLNET_IVA_MAX_AUDIO_NUM			8	//�û���Ƶ��������
#define ZLNET_IVA_MAX_SECTION_NUM		8   //�û���Ƶ����������

#define ZLNET_MAX_REV_LIST				5	//��������������÷���������

// �������ʹ��ţ���ӦZLNET_GetLastError�ӿڵķ���ֵ
#define _EC(x)							(0x80000000|x)
#define ZLNET_NOERROR 					0			// û�д���
#define ZLNET_ERROR						-1			// δ֪����
#define ZLNET_SYSTEM_ERROR				_EC(1)		// Windowsϵͳ����
#define ZLNET_NETWORK_ERROR				_EC(2)		// ������󣬿�������Ϊ���糬ʱ
#define ZLNET_DEV_VER_NOMATCH			_EC(3)		// �豸Э�鲻ƥ��
#define ZLNET_INVALID_HANDLE			_EC(4)		// �����Ч
#define ZLNET_OPEN_CHANNEL_ERROR		_EC(5)		// ��ͨ��ʧ��
#define ZLNET_CLOSE_CHANNEL_ERROR		_EC(6)		// �ر�ͨ��ʧ��
#define ZLNET_ILLEGAL_PARAM				_EC(7)		// �û��������Ϸ�
#define ZLNET_SDK_INIT_ERROR			_EC(8)		// SDK��ʼ������
#define ZLNET_SDK_UNINIT_ERROR			_EC(9)		// SDK�������
#define ZLNET_RENDER_OPEN_ERROR			_EC(10)		// ����render��Դ����
#define ZLNET_DEC_OPEN_ERROR			_EC(11)		// �򿪽�������
#define ZLNET_DEC_CLOSE_ERROR			_EC(12)		// �رս�������
#define ZLNET_MULTIPLAY_NOCHANNEL		_EC(13)		// �໭��Ԥ���м�⵽ͨ����Ϊ0
#define ZLNET_TALK_INIT_ERROR			_EC(14)		// ¼�����ʼ��ʧ��
#define ZLNET_TALK_NOT_INIT				_EC(15)		// ¼����δ����ʼ��
#define	ZLNET_TALK_SENDDATA_ERROR		_EC(16)		// ������Ƶ���ݳ���
#define ZLNET_REAL_ALREADY_SAVING		_EC(17)		// ʵʱ�����Ѿ����ڱ���״̬
#define ZLNET_NOT_SAVING				_EC(18)		// δ����ʵʱ����
#define ZLNET_OPEN_FILE_ERROR			_EC(19)		// ���ļ�����
#define ZLNET_PTZ_SET_TIMER_ERROR		_EC(20)		// ������̨���ƶ�ʱ��ʧ��
#define ZLNET_RETURN_DATA_ERROR			_EC(21)		// �Է������ݵ�У�����
#define ZLNET_INSUFFICIENT_BUFFER		_EC(22)		// û���㹻�Ļ���
#define ZLNET_NOT_SUPPORTED				_EC(23)		// ��ǰSDKδ֧�ָù���
#define ZLNET_NO_RECORD_FOUND			_EC(24)		// ��ѯ����¼��
#define ZLNET_NOT_AUTHORIZED			_EC(25)		// �޲���Ȩ��
#define ZLNET_NOT_NOW					_EC(26)		// ��ʱ�޷�ִ��
#define ZLNET_NO_TALK_CHANNEL			_EC(27)		// δ���ֶԽ�ͨ��
#define ZLNET_NO_AUDIO					_EC(28)		// δ������Ƶ
#define ZLNET_NO_INIT					_EC(29)		// ����SDKδ����ʼ��
#define ZLNET_DOWNLOAD_END				_EC(30)		// �����ѽ���
#define ZLNET_EMPTY_LIST				_EC(31)		// ��ѯ���Ϊ��
#define ZLNET_ERROR_GETCFG_SYSATTR		_EC(32)		// ��ȡϵͳ��������ʧ��
#define ZLNET_ERROR_GETCFG_SERIAL		_EC(33)		// ��ȡ���к�ʧ��
#define ZLNET_ERROR_GETCFG_GENERAL		_EC(34)		// ��ȡ��������ʧ��
#define ZLNET_ERROR_GETCFG_DSPCAP		_EC(35)		// ��ȡDSP��������ʧ��
#define ZLNET_ERROR_GETCFG_NETCFG		_EC(36)		// ��ȡ��������ʧ��
#define ZLNET_ERROR_GETCFG_CHANNAME		_EC(37)		// ��ȡͨ������ʧ��
#define ZLNET_ERROR_GETCFG_VIDEO		_EC(38)		// ��ȡ��Ƶ����ʧ��
#define ZLNET_ERROR_GETCFG_RECORD		_EC(39)		// ��ȡ¼������ʧ��
#define ZLNET_ERROR_GETCFG_PRONAME		_EC(40)		// ��ȡ������Э������ʧ��
#define ZLNET_ERROR_GETCFG_FUNCNAME		_EC(41)		// ��ȡ232���ڹ�������ʧ��
#define ZLNET_ERROR_GETCFG_485DECODER	_EC(42)		// ��ȡ����������ʧ��
#define ZLNET_ERROR_GETCFG_232COM		_EC(43)		// ��ȡ232��������ʧ��
#define ZLNET_ERROR_GETCFG_ALARMIN		_EC(44)		// ��ȡ�ⲿ������������ʧ��
#define ZLNET_ERROR_GETCFG_ALARMDET		_EC(45)		// ��ȡ��̬��ⱨ��ʧ��
#define ZLNET_ERROR_GETCFG_SYSTIME		_EC(46)		// ��ȡ�豸ʱ��ʧ��
#define ZLNET_ERROR_GETCFG_PREVIEW		_EC(47)		// ��ȡԤ������ʧ��
#define ZLNET_ERROR_GETCFG_AUTOMT		_EC(48)		// ��ȡ�Զ�ά������ʧ��
#define ZLNET_ERROR_GETCFG_VIDEOMTRX	_EC(49)		// ��ȡ��Ƶ��������ʧ��
#define ZLNET_ERROR_GETCFG_COVER		_EC(50)		// ��ȡ�����ڵ�����ʧ��
#define ZLNET_ERROR_GETCFG_WATERMAKE	_EC(51)		// ��ȡͼ��ˮӡ����ʧ��
#define ZLNET_ERROR_SETCFG_GENERAL		_EC(55)		// �޸ĳ�������ʧ��
#define ZLNET_ERROR_SETCFG_NETCFG		_EC(56)		// �޸���������ʧ��
#define ZLNET_ERROR_SETCFG_CHANNAME		_EC(57)		// �޸�ͨ������ʧ��
#define ZLNET_ERROR_SETCFG_VIDEO		_EC(58)		// �޸���Ƶ����ʧ��
#define ZLNET_ERROR_SETCFG_RECORD		_EC(59)		// �޸�¼������ʧ��
#define ZLNET_ERROR_SETCFG_485DECODER	_EC(60)		// �޸Ľ���������ʧ��
#define ZLNET_ERROR_SETCFG_232COM		_EC(61)		// �޸�232��������ʧ��
#define ZLNET_ERROR_SETCFG_ALARMIN		_EC(62)		// �޸��ⲿ���뱨������ʧ��
#define ZLNET_ERROR_SETCFG_ALARMDET	    _EC(63)		// �޸Ķ�̬��ⱨ������ʧ��
#define ZLNET_ERROR_SETCFG_SYSTIME		_EC(64)		// �޸��豸ʱ��ʧ��
#define ZLNET_ERROR_SETCFG_PREVIEW		_EC(65)		// �޸�Ԥ������ʧ��
#define ZLNET_ERROR_SETCFG_AUTOMT		_EC(66)		// �޸��Զ�ά������ʧ��
#define ZLNET_ERROR_SETCFG_VIDEOMTRX	_EC(67)		// �޸���Ƶ��������ʧ��
#define ZLNET_ERROR_SETCFG_COVER		_EC(68)		// �޸������ڵ�����ʧ��
#define ZLNET_ERROR_SETCFG_WATERMAKE	_EC(69)		// �޸�ͼ��ˮӡ����ʧ��
#define ZLNET_ERROR_SETCFG_WLAN			_EC(70)		// �޸�����������Ϣʧ��
#define ZLNET_ERROR_SETCFG_WLANDEV		_EC(71)		// ѡ�����������豸ʧ��
#define ZLNET_ERROR_SETCFG_REGISTER		_EC(72)		// �޸�����ע���������ʧ��
#define ZLNET_ERROR_SETCFG_CAMERA		_EC(73)		// �޸�����ͷ��������ʧ��
#define ZLNET_ERROR_SETCFG_INFRARED		_EC(74)		// �޸ĺ��ⱨ������ʧ��
#define ZLNET_ERROR_SETCFG_SOUNDALARM	_EC(75)		// �޸���Ƶ��������ʧ��
#define ZLNET_ERROR_SETCFG_STORAGE      _EC(76)		// �޸Ĵ洢λ������ʧ��
#define ZLNET_AUDIOENCODE_NOTINIT		_EC(77)		// ��Ƶ����ӿ�û�гɹ���ʼ��
#define ZLNET_DATA_TOOLONGH				_EC(78)		// ���ݹ���
#define ZLNET_UNSUPPORTED				_EC(79)		// �豸��֧�ָò���
#define ZLNET_DEVICE_BUSY				_EC(80)		// �豸��Դ����
#define ZLNET_SERVER_STARTED			_EC(81)		// �������Ѿ�����
#define ZLNET_SERVER_STOPPED			_EC(82)		// ��������δ�ɹ�����
#define ZLNET_LISTER_INCORRECT_SERIAL	_EC(83)		// �������к�����
#define ZLNET_QUERY_DISKINFO_FAILED		_EC(84)		// ��ȡӲ����Ϣʧ��
#define ZLNET_ERROR_GETCFG_SESSION		_EC(85)		// ��ȡ����Session��Ϣ
#define ZLNET_USER_FLASEPWD_TRYTIME		_EC(86)		// ����������󳬹����ƴ���
#define ZLNET_LOGIN_ERROR_PASSWORD		_EC(100)	// ���벻��ȷ
#define ZLNET_LOGIN_ERROR_USER			_EC(101)	// �ʻ�������
#define ZLNET_LOGIN_ERROR_TIMEOUT		_EC(102)	// �ȴ���¼���س�ʱ
#define ZLNET_LOGIN_ERROR_RELOGGIN		_EC(103)	// �ʺ��ѵ�¼
#define ZLNET_LOGIN_ERROR_LOCKED		_EC(104)	// �ʺ��ѱ�����
#define ZLNET_LOGIN_ERROR_BLACKLIST		_EC(105)	// �ʺ��ѱ���Ϊ������
#define ZLNET_LOGIN_ERROR_BUSY			_EC(106)	// ��Դ���㣬ϵͳæ
#define ZLNET_LOGIN_ERROR_CONNECT		_EC(107)	// ��¼�豸��ʱ���������粢����
#define ZLNET_LOGIN_ERROR_NETWORK		_EC(108)	// ��������ʧ��
#define ZLNET_LOGIN_ERROR_SUBCONNECT	_EC(109)	// ��¼�豸�ɹ������޷�������Ƶͨ������������״��
#define ZLNET_RENDER_SOUND_ON_ERROR		_EC(120)	// Render�����Ƶ����
#define ZLNET_RENDER_SOUND_OFF_ERROR	_EC(121)	// Render��ر���Ƶ����
#define ZLNET_RENDER_SET_VOLUME_ERROR	_EC(122)	// Render�������������
#define ZLNET_RENDER_ADJUST_ERROR		_EC(123)	// Render�����û����������
#define ZLNET_RENDER_PAUSE_ERROR		_EC(124)	// Render����ͣ���ų���
#define ZLNET_RENDER_SNAP_ERROR			_EC(125)	// Render��ץͼ����
#define ZLNET_RENDER_STEP_ERROR			_EC(126)	// Render�ⲽ������
#define ZLNET_RENDER_FRAMERATE_ERROR	_EC(127)	// Render������֡�ʳ���
#define ZLNET_GROUP_EXIST				_EC(140)	// �����Ѵ���
#define	ZLNET_GROUP_NOEXIST				_EC(141)	// ����������
#define ZLNET_GROUP_RIGHTOVER			_EC(142)	// ���Ȩ�޳���Ȩ���б�Χ
#define ZLNET_GROUP_HAVEUSER			_EC(143)	// �������û�������ɾ��
#define ZLNET_GROUP_RIGHTUSE			_EC(144)	// ���ĳ��Ȩ�ޱ��û�ʹ�ã����ܳ���
#define ZLNET_GROUP_SAMENAME			_EC(145)	// ������ͬ���������ظ�
#define	ZLNET_USER_EXIST				_EC(146)	// �û��Ѵ���
#define ZLNET_USER_NOEXIST				_EC(147)	// �û�������
#define ZLNET_USER_RIGHTOVER			_EC(148)	// �û�Ȩ�޳�����Ȩ��
#define ZLNET_USER_PWD					_EC(149)	// �����ʺţ��������޸�����
#define ZLNET_USER_FLASEPWD				_EC(150)	// ���벻��ȷ
#define ZLNET_USER_NOMATCHING			_EC(151)	// ���벻ƥ��
#define ZLNET_ERROR_GETCFG_ETHERNET		_EC(300)	// ��ȡ��������ʧ��
#define ZLNET_ERROR_GETCFG_WLAN			_EC(301)	// ��ȡ����������Ϣʧ��
#define ZLNET_ERROR_GETCFG_WLANDEV		_EC(302)	// ��ȡ���������豸ʧ��
#define ZLNET_ERROR_GETCFG_REGISTER		_EC(303)	// ��ȡ����ע�����ʧ��
#define ZLNET_ERROR_GETCFG_CAMERA		_EC(304)	// ��ȡ����ͷ����ʧ��
#define ZLNET_ERROR_GETCFG_INFRARED		_EC(305)	// ��ȡ���ⱨ������ʧ��
#define ZLNET_ERROR_GETCFG_SOUNDALARM	_EC(306)	// ��ȡ��Ƶ��������ʧ��
#define ZLNET_ERROR_GETCFG_STORAGE      _EC(307)	// ��ȡ�洢λ������ʧ��
#define ZLNET_ERROR_GETCFG_MAIL			_EC(308)	// ��ȡ�ʼ�����ʧ��
#define ZLNET_CONFIG_DEVBUSY			_EC(309)	// ��ʱ�޷�����
#define ZLNET_CONFIG_DATAILLEGAL		_EC(310)	// �������ݲ��Ϸ�
#define ZLNET_ERROR_GETCFG_DST          _EC(311)    // ��ȡ����ʱ����ʧ��
#define ZLNET_ERROR_SETCFG_DST          _EC(312)    // ��������ʱ����ʧ��
#define ZLNET_ERROR_GETCFG_VIDEO_OSD    _EC(313)    // ��ȡ��ƵOSD��������ʧ��
#define ZLNET_ERROR_SETCFG_VIDEO_OSD    _EC(314)    // ������ƵOSD��������ʧ��
#define ZLNET_ERROR_GETCFG_GPRSCDMA     _EC(315)    // ��ȡCDMA\GPRS��������ʧ��
#define ZLNET_ERROR_SETCFG_GPRSCDMA     _EC(316)    // ����CDMA\GPRS��������ʧ��
#define ZLNET_ERROR_GETCFG_IPFILTER     _EC(317)    // ��ȡIP��������ʧ��
#define ZLNET_ERROR_SETCFG_IPFILTER     _EC(318)    // ����IP��������ʧ��
#define ZLNET_ERROR_GETCFG_TALKENCODE   _EC(319)    // ��ȡ�����Խ���������ʧ��
#define ZLNET_ERROR_SETCFG_TALKENCODE   _EC(320)    // ���������Խ���������ʧ��
#define ZLNET_ERROR_GETCFG_RECORDLEN    _EC(321)    // ��ȡ¼������������ʧ��
#define ZLNET_ERROR_SETCFG_RECORDLEN    _EC(322)    // ����¼������������ʧ��
#define	ZLNET_DONT_SUPPORT_SUBAREA		_EC(323)	// ��֧������Ӳ�̷���
#define	ZLNET_ERROR_GET_AUTOREGSERVER	_EC(324)	// ��ȡ�豸������ע���������Ϣʧ��
#define	ZLNET_ERROR_CONTROL_AUTOREGISTER    _EC(325)	// ����ע���ض���ע�����
#define	ZLNET_ERROR_DISCONNECT_AUTOREGISTER	_EC(326)	// �Ͽ�����ע�����������
#define ZLNET_ERROR_GETCFG_MMS				_EC(327)	// ��ȡmms����ʧ��
#define ZLNET_ERROR_SETCFG_MMS				_EC(328)	// ����mms����ʧ��
#define ZLNET_ERROR_GETCFG_SMSACTIVATION    _EC(329)	// ��ȡ���ż���������������ʧ��
#define ZLNET_ERROR_SETCFG_SMSACTIVATION    _EC(330)	// ���ö��ż���������������ʧ��
#define ZLNET_ERROR_GETCFG_DIALINACTIVATION	_EC(331)	// ��ȡ���ż���������������ʧ��
#define ZLNET_ERROR_SETCFG_DIALINACTIVATION	_EC(332)	// ���ò��ż���������������ʧ��
#define ZLNET_ERROR_GETCFG_VIDEOOUT         _EC(333)    // ��ѯ��Ƶ�����������ʧ��
#define ZLNET_ERROR_SETCFG_VIDEOOUT			_EC(334)	// ������Ƶ�����������ʧ��
#define ZLNET_ERROR_GETCFG_OSDENABLE		_EC(335)	// ��ȡosd����ʹ������ʧ��
#define ZLNET_ERROR_SETCFG_OSDENABLE		_EC(336)	// ����osd����ʹ������ʧ��
#define ZLNET_ERROR_SETCFG_ENCODERINFO      _EC(337)    // ��������ͨ��ǰ�˱����������ʧ��
#define ZLNET_ERROR_GETCFG_TVADJUST		    _EC(338)	// ��ȡTV��������ʧ��
#define ZLNET_ERROR_SETCFG_TVADJUST			_EC(339)	// ����TV��������ʧ��

#define ZLNET_ERROR_CONNECT_FAILED			_EC(340)	// ����������ʧ��
#define ZLNET_ERROR_SETCFG_BURNFILE			_EC(341)	// �����¼�ļ��ϴ�ʧ��
#define ZLNET_ERROR_SNIFFER_GETCFG			_EC(342)	// ��ȡץ��������Ϣʧ��
#define ZLNET_ERROR_SNIFFER_SETCFG			_EC(343)	// ����ץ��������Ϣʧ��
#define ZLNET_ERROR_DOWNLOADRATE_GETCFG		_EC(344)	// ��ѯ����������Ϣʧ��
#define ZLNET_ERROR_DOWNLOADRATE_SETCFG		_EC(345)	// ��������������Ϣʧ��
#define ZLNET_ERROR_SEARCH_TRANSCOM			_EC(346)	// ��ѯ���ڲ���ʧ��
#define ZLNET_ERROR_GETCFG_POINT			_EC(347)	// ��ȡԤ�Ƶ���Ϣ����
#define ZLNET_ERROR_SETCFG_POINT			_EC(348)	// ����Ԥ�Ƶ���Ϣ����
#define ZLNET_SDK_LOGOUT_ERROR				_EC(349)    // SDKû�������ǳ��豸
#define ZLNET_ERROR_GET_VEHICLE_CFG			_EC(350)	// ��ȡ��������ʧ��
#define ZLNET_ERROR_SET_VEHICLE_CFG			_EC(351)	// ���ó�������ʧ��
#define ZLNET_ERROR_GET_ATM_OVERLAY_CFG		_EC(352)	// ��ȡatm��������ʧ��
#define ZLNET_ERROR_SET_ATM_OVERLAY_CFG		_EC(353)	// ����atm��������ʧ��
#define ZLNET_ERROR_GET_ATM_OVERLAY_ABILITY	_EC(354)	// ��ȡatm��������ʧ��
#define ZLNET_ERROR_GET_DECODER_TOUR_CFG	_EC(355)	// ��ȡ������������Ѳ����ʧ��
#define ZLNET_ERROR_SET_DECODER_TOUR_CFG	_EC(356)	// ���ý�����������Ѳ����ʧ��
#define ZLNET_ERROR_CTRL_DECODER_TOUR		_EC(357)	// ���ƽ�����������Ѳʧ��
#define ZLNET_GROUP_OVERSUPPORTNUM			_EC(358)	// �����豸֧������û�����Ŀ
#define ZLNET_USER_OVERSUPPORTNUM			_EC(359)	// �����豸֧������û���Ŀ
#define ZLNET_ERROR_GET_SIP_CFG				_EC(368)	// ��ȡSIP����ʧ��
#define ZLNET_ERROR_SET_SIP_CFG				_EC(369)	// ����SIP����ʧ��
#define ZLNET_ERROR_GET_SIP_ABILITY			_EC(370)	// ��ȡSIP����ʧ��
#define ZLNET_TALK_REJECT					_EC(371)	// �ܾ��Խ�
#define ZLNET_TALK_BUSY						_EC(372)	// ��Դ��ͻ�����ܶԽ�
#define ZLNET_TALK_FORMAT_NOT_SUPPORTED		_EC(373)	// �ܾ��Խ��������ʽ��֧��
#define ZLNET_ERROR_UPSUPPORT_WAV			_EC(374)	// ��֧�ֵ�WAV�ļ�
#define ZLNET_ERROR_CHANGE_FORMAT_WAV		_EC(375)	// ת��WAV������ʧ��
#define ZLNET_ERROR_PACKFRAME				_EC(376)	// ���ʧ��
#define ZLNET_ERROR_LATTICE_CFG				_EC(377)	// ���õ�������ʧ��

/************************************************************************
 ** ö�ٶ���
 ***********************************************************************/
// �豸����
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
	ZLNET_IVA_PLATEID,		//���ܳ���
	ZLNET_IVA_STAFFCOUNT,	//��������ͳ��
	ZLNET_IVA_BZS,				//�����ܽ�
	ZLNET_IVA_ATM=150,			//����ATM
	ZLNET_IVA_SSB,				//����SSB
	ZLNET_IVA_FACE,				//��������
	ZLNET_IPC=180,
	ZLNET_IPC_3507_SD,			//3507����
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

// ��������
typedef enum __ZLNET_LANGUAGE_TYPE
{
	ZLNET_LANGUAGE_ENGLISH,							// Ӣ��	
	ZLNET_LANGUAGE_CHINESE_SIMPLIFIED,				// ��������	
	ZLNET_LANGUAGE_CHINESE_TRADITIONAL,				// ��������	
	ZLNET_LANGUAGE_ITALIAN,							// �������	
	ZLNET_LANGUAGE_SPANISH,							// ��������
	ZLNET_LANGUAGE_JAPANESE,						// ���İ�	
	ZLNET_LANGUAGE_RUSSIAN,							// ���İ�		
	ZLNET_LANGUAGE_FRENCH,							// ���İ�		
	ZLNET_LANGUAGE_GERMAN, 							// ���İ�		
	ZLNET_LANGUAGE_PORTUGUESE,						// ��������	
	ZLNET_LANGUAGE_TURKEY,							// ��������	
	ZLNET_LANGUAGE_POLISH,							// ������	
	ZLNET_LANGUAGE_ROMANIAN,						// ��������	
	ZLNET_LANGUAGE_HUNGARIAN,						// ��������	
	ZLNET_LANGUAGE_FINNISH,							// ������	
	ZLNET_LANGUAGE_ESTONIAN,						// ��ɳ������	
	ZLNET_LANGUAGE_KOREAN,							// ����	
	ZLNET_LANGUAGE_FARSI,							// ��˹�� 	
	ZLNET_LANGUAGE_DANSK,							// ������
	ZLNET_LANGUAGE_CZECHISH,						// �ݿ���
	ZLNET_LANGUAGE_BULGARIA,						// ����������
	ZLNET_LANGUAGE_SLOVAKIAN,						// ˹�工����
	ZLNET_LANGUAGE_SLOVENIA,						// ˹����������
	ZLNET_LANGUAGE_CROATIAN,						// ���޵�����
	ZLNET_LANGUAGE_DUTCH,							// ������
	ZLNET_LANGUAGE_GREEK,							// ϣ����
	ZLNET_LANGUAGE_UKRAINIAN,						// �ڿ�����
	ZLNET_LANGUAGE_SWEDISH,							// �����
	ZLNET_LANGUAGE_SERBIAN,							// ����ά����
	ZLNET_LANGUAGE_VIETNAMESE,						// Խ����
	ZLNET_LANGUAGE_LITHUANIAN,						// ��������
	ZLNET_LANGUAGE_FILIPINO,						// ���ɱ���
	ZLNET_LANGUAGE_ARABIC,							// ��������
	ZLNET_LANGUAGE_CATALAN,							// ��̩��������
	ZLNET_LANGUAGE_LATVIAN,							// ����ά����
	ZLNET_LANGUAGE_THAI,							// ̩��
	ZLNET_LANGUAGE_HEBREW,							// ϣ������
	ZLNET_LANGUAGE_Bosnian,							// ��˹������
} ZLNET_LANGUAGE_TYPE;

// ��������
typedef enum __ZLNET_UPGRADE_TYPE
{
	ZLNET_UPGRADE_BIOS_TYPE = 1,					// BIOS����
	ZLNET_UPGRADE_WEB_TYPE,							// WEB����
	ZLNET_UPGRADE_BOOT_YPE,							// BOOT����
	ZLNET_UPGRADE_CHARACTER_TYPE,					// ���ֿ�
	ZLNET_UPGRADE_LOGO_TYPE,						// LOGO
	ZLNET_UPGRADE_EXE_TYPE,							// EXE�����粥������
} ZLNET_UPGRADE_TYPE;

// ¼������(��ʱ����̬��⡢����)
typedef enum __ZLNET_REC_TYPE
{
	ZLNET_REC_TYPE_TIM = 0,
	ZLNET_REC_TYPE_MTD,
	ZLNET_REC_TYPE_ALM,
	ZLNET_REC_TYPE_NUM,
} ZLNET_REC_TYPE;

// �������� 
typedef enum __ZLNET_GPRSCDMA_NETWORK_TYPE
{
	ZLNET_TYPE_AUTOSEL = 0,							// �Զ�ѡ��
	ZLNET_TYPE_TD_SCDMA,							// TD-SCDMA���� 
	ZLNET_TYPE_WCDMA,								// WCDMA����
	ZLNET_TYPE_CDMA_1x,								// CDMA 1.x����
	ZLNET_TYPE_EDGE,								// GPRS����
	ZLNET_TYPE_EVDO,								// EVDO����
	ZLNET_TYPE_WIFI,								// ����
} ZLNET_GPRSCDMA_NETWORK_TYPE;

// �ӿ����ͣ���ӦZLNET_SetSubconnCallBack�ӿ�
typedef enum __ZLNET_INTERFACE_TYPE
{
	ZLNET_INTERFACE_OTHER = 0x00000000,				// δ֪�ӿ�
	ZLNET_INTERFACE_REALPLAY,						// ʵʱ���ӽӿ�
	ZLNET_INTERFACE_PREVIEW,						// �໭��Ԥ���ӿ�
	ZLNET_INTERFACE_PLAYBACK,						// �طŽӿ�
	ZLNET_INTERFACE_DOWNLOAD,						// ���ؽӿ�
} ZLNET_INTERFACE_TYPE;

/////////////////////////////////�������/////////////////////////////////

// Ԥ�����ͣ���ӦZLNET_RealPlayEx�ӿ�
typedef enum _ZLNET_RealPlayType
{
	ZLNET_RType_Realplay = 0,						// ʵʱԤ��
	ZLNET_RType_Multiplay,							// �໭��Ԥ��
		
	ZLNET_RType_Realplay_0,						// ʵʱ����-����������ͬ��ZLNET_RType_Realplay
	ZLNET_RType_Realplay_1,						// ʵʱ����-������1
	ZLNET_RType_Realplay_2,						// ʵʱ����-������2
	ZLNET_RType_Realplay_3,						// ʵʱ����-������3
		
	ZLNET_RType_Multiplay_1,						// �໭��Ԥ����1����
	ZLNET_RType_Multiplay_4,						// �໭��Ԥ����4����
	ZLNET_RType_Multiplay_8,						// �໭��Ԥ����8����
	ZLNET_RType_Multiplay_9,						// �໭��Ԥ����9����
	ZLNET_RType_Multiplay_16,						// �໭��Ԥ����16����
	ZLNET_RType_Multiplay_6,						// �໭��Ԥ����6����
	ZLNET_RType_Multiplay_12,						// �໭��Ԥ����12����
} ZLNET_RealPlayType;

/////////////////////////////////��̨���/////////////////////////////////

// ͨ����̨��������
typedef enum _ZLNET_PTZ_ControlType
{
	ZLNET_PTZ_UP_CONTROL = 0,						// ��
	ZLNET_PTZ_DOWN_CONTROL,							// ��
	ZLNET_PTZ_LEFT_CONTROL,							// ��
	ZLNET_PTZ_RIGHT_CONTROL,						// ��
	ZLNET_PTZ_ZOOM_ADD_CONTROL,						// �䱶+
	ZLNET_PTZ_ZOOM_DEC_CONTROL,						// �䱶-
	ZLNET_PTZ_FOCUS_ADD_CONTROL,					// ����+
	ZLNET_PTZ_FOCUS_DEC_CONTROL,					// ����-
	ZLNET_PTZ_APERTURE_ADD_CONTROL,				// ��Ȧ+
	ZLNET_PTZ_APERTURE_DEC_CONTROL,				// ��Ȧ-
    ZLNET_PTZ_POINT_MOVE_CONTROL,					// ת��Ԥ�õ�
    ZLNET_PTZ_POINT_SET_CONTROL,					// ����
    ZLNET_PTZ_POINT_DEL_CONTROL,					// ɾ��
    ZLNET_PTZ_POINT_LOOP_CONTROL,					// ���Ѳ��
    ZLNET_PTZ_LAMP_CONTROL							// �ƹ���ˢ
} ZLNET_PTZ_ControlType;

// ��̨������չ����
typedef enum _ZLNET_EXTPTZ_ControlType
{
	ZLNET_EXTPTZ_LEFTTOP = 0x20,					// ����
	ZLNET_EXTPTZ_RIGHTTOP,							// ����
	ZLNET_EXTPTZ_LEFTDOWN,							// ����
	ZLNET_EXTPTZ_RIGHTDOWN,							// ����
	ZLNET_EXTPTZ_ADDTOLOOP,							// ����Ԥ�õ㵽Ѳ�� Ѳ����· Ԥ�õ�ֵ
	ZLNET_EXTPTZ_DELFROMLOOP,						// ɾ��Ѳ����Ԥ�õ� Ѳ����· Ԥ�õ�ֵ
    ZLNET_EXTPTZ_CLOSELOOP,							// ���Ѳ�� Ѳ����·
	ZLNET_EXTPTZ_STARTPANCRUISE,					// ��ʼˮƽ��ת
	ZLNET_EXTPTZ_STOPPANCRUISE,						// ֹͣˮƽ��ת
	ZLNET_EXTPTZ_SETLEFTBORDER,						// ������߽�
	ZLNET_EXTPTZ_SETRIGHTBORDER,					// �����ұ߽�
	ZLNET_EXTPTZ_STARTLINESCAN,						// ��ʼ��ɨ
    ZLNET_EXTPTZ_CLOSELINESCAN,						// ֹͣ��ɨ
    ZLNET_EXTPTZ_SETMODESTART,						// ����ģʽ��ʼ	ģʽ��·
    ZLNET_EXTPTZ_SETMODESTOP,						// ����ģʽ����	ģʽ��·
	ZLNET_EXTPTZ_RUNMODE,							// ����ģʽ	ģʽ��·
	ZLNET_EXTPTZ_STOPMODE,							// ֹͣģʽ	ģʽ��·
	ZLNET_EXTPTZ_DELETEMODE,						// ���ģʽ	ģʽ��·
	ZLNET_EXTPTZ_REVERSECOMM,						// ��ת����
	ZLNET_EXTPTZ_FASTGOTO,							// ���ٶ�λ ˮƽ����(8192) ��ֱ����(8192) �䱶(4)
	ZLNET_EXTPTZ_AUXIOPEN,							// �������ؿ� ������
	ZLNET_EXTPTZ_AUXICLOSE,							// �������ع� ������
	ZLNET_EXTPTZ_OPENMENU = 0x36,					// ������˵�
	ZLNET_EXTPTZ_CLOSEMENU,							// �رղ˵�
	ZLNET_EXTPTZ_MENUOK,							// �˵�ȷ��
	ZLNET_EXTPTZ_MENUCANCEL,						// �˵�ȡ��
	ZLNET_EXTPTZ_MENUUP,							// �˵���
	ZLNET_EXTPTZ_MENUDOWN,							// �˵���
	ZLNET_EXTPTZ_MENULEFT,							// �˵���
	ZLNET_EXTPTZ_MENURIGHT,							// �˵���
	ZLNET_EXTPTZ_ALARMHANDLE = 0x40,				// ����������̨ parm1����������ͨ����parm2��������������1-Ԥ�õ�2-��ɨ3-Ѳ����parm3������ֵ����Ԥ�õ��
	ZLNET_EXTPTZ_MATRIXSWITCH = 0x41,				// �����л� parm1����������(��Ƶ�����)��parm2����Ƶ����ţ�parm3�������
	ZLNET_EXTPTZ_LIGHTCONTROL,						// �ƹ������
	ZLNET_EXTPTZ_UP_TELE = 0x70,					// �� + TELE param1=�ٶ�(1-8)����ͬ
	ZLNET_EXTPTZ_DOWN_TELE,							// �� + TELE
	ZLNET_EXTPTZ_LEFT_TELE,							// �� + TELE
	ZLNET_EXTPTZ_RIGHT_TELE,						// �� + TELE
	ZLNET_EXTPTZ_LEFTUP_TELE,						// ���� + TELE
	ZLNET_EXTPTZ_LEFTDOWN_TELE,						// ���� + TELE
	ZLNET_EXTPTZ_TIGHTUP_TELE,						// ���� + TELE
	ZLNET_EXTPTZ_RIGHTDOWN_TELE,					// ���� + TELE
	ZLNET_EXTPTZ_UP_WIDE,							// �� + WIDE param1=�ٶ�(1-8)����ͬ
	ZLNET_EXTPTZ_DOWN_WIDE,							// �� + WIDE
	ZLNET_EXTPTZ_LEFT_WIDE,							// �� + WIDE
	ZLNET_EXTPTZ_RIGHT_WIDE,						// �� + WIDE
	ZLNET_EXTPTZ_LEFTUP_WIDE,						// ���� + WIDE
	ZLNET_EXTPTZ_LEFTDOWN_WIDE,						// ���� + WIDE
	ZLNET_EXTPTZ_TIGHTUP_WIDE,						// ���� + WIDE
	ZLNET_EXTPTZ_RIGHTDOWN_WIDE,					// ���� + WIDE
	ZLNET_EXTPTZ_TOTAL,							// �������ֵ
} ZLNET_EXTPTZ_ControlType;

/////////////////////////////////��־���/////////////////////////////////

// ��־��ѯ����
typedef enum _ZLNET_LOG_QUERY_TYPE
{
	ZLNET_LOG_QUY_ALL = 0,								// ������־
	ZLNET_LOG_QUY_SYSTEM,								// ϵͳ��־
	ZLNET_LOG_QUY_CONFIG,								// ������־
	ZLNET_LOG_QUY_STORAGE,								// �洢���
	ZLNET_LOG_QUY_ALARM,								// ������־
	ZLNET_LOG_QUY_RECORD,								// ¼�����
	ZLNET_LOG_QUY_ACCOUNT,								// �ʺ����
	ZLNET_LOG_QUY_CLEAR,								// �����־
	ZLNET_LOG_QUY_PLAYBACK								// �ط����
} ZLNET_LOG_QUERY_TYPE;

// ��־����
typedef enum _ZL_LOG_TYPE
{
	ZLNET_LOG_REBOOT = 0x0000,						// �豸����
	ZLNET_LOG_SHUT,									// �豸�ػ�
	ZLNET_LOG_UPGRADE = 0x0004,						// �豸����
	ZLNET_LOG_CONFSAVE = 0x0100,					// ��������
	ZLNET_LOG_CONFLOAD,								// ��ȡ����
	ZLNET_LOG_FSERROR = 0x0200,						// �ļ�ϵͳ����
	ZLNET_LOG_HDD_WERR,								// Ӳ��д����
	ZLNET_LOG_HDD_RERR,								// Ӳ�̶�����
	ZLNET_LOG_HDD_TYPE,								// ����Ӳ������
	ZLNET_LOG_HDD_FORMAT,							// ��ʽ��Ӳ��
	ZLNET_LOG_HDD_NOSPACE,							// ��ǰ�����̿ռ䲻��
	ZLNET_LOG_HDD_TYPE_RW,							// ����Ӳ������Ϊ��д��
	ZLNET_LOG_HDD_TYPE_RO,							// ����Ӳ������Ϊֻ����	
	ZLNET_LOG_HDD_TYPE_RE,							// ����Ӳ������Ϊ������
	ZLNET_LOG_HDD_TYPE_SS,							// ����Ӳ������Ϊ������
	ZLNET_LOG_HDD_NONE,								// ��Ӳ�̼�¼
	ZLNET_LOG_HDD_NOWORKHDD,						// �޹�����(û�ж�д��)
	ZLNET_LOG_HDD_TYPE_BK,							// ����Ӳ������Ϊ������
	ZLNET_LOG_HDD_TYPE_REVERSE,						// ����Ӳ������Ϊ��������
	ZLNET_LOG_ALM_IN = 0x0300,						// �ⲿ���뱨����ʼ
	ZLNET_LOG_NETALM_IN,							// ���籨������
	ZLNET_LOG_ALM_END = 0x0302,						// �ⲿ���뱨��ֹͣ
	ZLNET_LOG_LOSS_IN,								// ��Ƶ��ʧ������ʼ
	ZLNET_LOG_LOSS_END,								// ��Ƶ��ʧ��������
	ZLNET_LOG_MOTION_IN,							// ��̬��ⱨ����ʼ
	ZLNET_LOG_MOTION_END,							// ��̬��ⱨ������
	ZLNET_LOG_ALM_BOSHI,							// ��������������
	ZLNET_LOG_NET_ABORT = 0x0308,					// ����Ͽ�
	ZLNET_LOG_NET_ABORT_RESUME,						// ����ָ�
	ZLNET_LOG_CODER_BREAKDOWN,						// ����������
	ZLNET_LOG_CODER_BREAKDOWN_RESUME,				// ���������ϻָ�
	ZLNET_LOG_BLIND_IN,								// ��Ƶ�ڵ�
	ZLNET_LOG_BLIND_END,							// ��Ƶ�ڵ��ָ�
	ZLNET_LOG_ALM_TEMP_HIGH,						// �¶ȹ���
	ZLNET_LOG_ALM_VOLTAGE_LOW,						// ��ѹ����
	ZLNET_LOG_ALM_BATTERY_LOW,						// �����������
	ZLNET_LOG_ALM_ACC_BREAK,						// ACC�ϵ�
	ZLNET_LOG_INFRAREDALM_IN = 0x03a0,				// ���߱�����ʼ
	ZLNET_LOG_INFRAREDALM_END,						// ���߱�������
	ZLNET_LOG_IPCONFLICT,							// IP��ͻ
	ZLNET_LOG_IPCONFLICT_RESUME,					// IP�ָ�
	ZLNET_LOG_SDPLUG_IN,							// SD������
	ZLNET_LOG_SDPLUG_OUT,							// SD���γ�
	ZLNET_LOG_NET_PORT_BIND_FAILED,					// ����˿ڰ�ʧ��
	ZLNET_LOG_AUTOMATIC_RECORD = 0x0400,			// �Զ�¼��
	ZLNET_LOG_MANUAL_RECORD = 0x0401,				// �ֶ�¼��
	ZLNET_LOG_CLOSED_RECORD,						// ֹͣ¼��
	ZLNET_LOG_LOGIN = 0x0500,						// ��¼
	ZLNET_LOG_LOGOUT,								// ע��
	ZLNET_LOG_ADD_USER,								// ����û�
	ZLNET_LOG_DELETE_USER,							// ɾ���û�
	ZLNET_LOG_MODIFY_USER,							// �޸��û�
	ZLNET_LOG_ADD_GROUP,							// ����û���
	ZLNET_LOG_DELETE_GROUP,							// ɾ���û���
	ZLNET_LOG_MODIFY_GROUP,							// �޸��û���
	ZLNET_LOG_NET_LOGIN = 0x0508,					// �����û���¼
	ZLNET_LOG_CLEAR = 0x0600,						// �����־
	ZLNET_LOG_SEARCHLOG,							// ��ѯ��־
	ZLNET_LOG_SEARCH = 0x0700,						// ¼���ѯ
	ZLNET_LOG_DOWNLOAD,								// ¼������
	ZLNET_LOG_PLAYBACK,								// ¼��ط�
	ZLNET_LOG_BACKUP,								// ����¼���ļ�
	ZLNET_LOG_BACKUPERROR,							// ����¼���ļ�ʧ��

	ZLNET_LOG_TYPE_NR = 7,
} ZL_LOG_TYPE;

// ��չ��־���ͣ���ӦZLNET_QueryLogEx�ӿڣ�����(int nType = 1������reserved = &nType)
typedef enum _ZLNET_NEWLOG_TYPE
{
	ZLNET_NEWLOG_REBOOT = 0x0000,					// �豸����
	ZLNET_NEWLOG_SHUT,								// �豸�ػ�
	ZLNET_NEWLOG_UPGRADE = 0x0004,					// �豸����
	ZLNET_NEWLOG_CONFSAVE = 0x0100,					// ��������
	ZLNET_NEWLOG_CONFLOAD,							// ��ȡ����
	ZLNET_NEWLOG_FSERROR = 0x0200,					// �ļ�ϵͳ����
	ZLNET_NEWLOG_HDD_WERR,							// Ӳ��д����
	ZLNET_NEWLOG_HDD_RERR,							// Ӳ�̶�����
	ZLNET_NEWLOG_HDD_TYPE,							// ����Ӳ������
	ZLNET_NEWLOG_HDD_FORMAT,						// ��ʽ��Ӳ��
	ZLNET_NEWLOG_HDD_NOSPACE,						// ��ǰ�����̿ռ䲻��
	ZLNET_NEWLOG_HDD_TYPE_RW,						// ����Ӳ������Ϊ��д��
	ZLNET_NEWLOG_HDD_TYPE_RO,						// ����Ӳ������Ϊֻ����	
	ZLNET_NEWLOG_HDD_TYPE_RE,						// ����Ӳ������Ϊ������
	ZLNET_NEWLOG_HDD_TYPE_SS,						// ����Ӳ������Ϊ������
	ZLNET_NEWLOG_HDD_NONE,							// ��Ӳ�̼�¼��־
	ZLNET_NEWLOG_HDD_NOWORKHDD,						// �޹�����(û�ж�д��)
	ZLNET_NEWLOG_HDD_TYPE_BK,						// ����Ӳ������Ϊ������
	ZLNET_NEWLOG_HDD_TYPE_REVERSE,					// ����Ӳ������Ϊ��������
	ZLNET_NEWLOG_ALM_IN = 0x0300,					// �ⲿ���뱨����ʼ
	ZLNET_NEWLOG_NETALM_IN,							// ���籨��
	ZLNET_NEWLOG_ALM_END = 0x0302,					// �ⲿ���뱨��ֹͣ
	ZLNET_NEWLOG_LOSS_IN,							// ��Ƶ��ʧ������ʼ
	ZLNET_NEWLOG_LOSS_END,							// ��Ƶ��ʧ��������
	ZLNET_NEWLOG_MOTION_IN,							// ��̬��ⱨ����ʼ
	ZLNET_NEWLOG_MOTION_END,						// ��̬��ⱨ������
	ZLNET_NEWLOG_ALM_BOSHI,							// ��������������
	ZLNET_NEWLOG_NET_ABORT = 0x0308,				// ����Ͽ�
	ZLNET_NEWLOG_NET_ABORT_RESUME,					// ����ָ�
	ZLNET_NEWLOG_CODER_BREAKDOWN,					// ����������
	ZLNET_NEWLOG_CODER_BREAKDOWN_RESUME,			// ���������ϻָ�
	ZLNET_NEWLOG_BLIND_IN,							// ��Ƶ�ڵ�
	ZLNET_NEWLOG_BLIND_END,							// ��Ƶ�ڵ��ָ�
	ZLNET_NEWLOG_ALM_TEMP_HIGH,						// �¶ȹ���
	ZLNET_NEWLOG_ALM_VOLTAGE_LOW,					// ��ѹ����
	ZLNET_NEWLOG_ALM_BATTERY_LOW,					// �����������
	ZLNET_NEWLOG_ALM_ACC_BREAK,						// ACC�ϵ�
	ZLNET_NEWLOG_INFRAREDALM_IN = 0x03a0,			// ���߱�����ʼ
	ZLNET_NEWLOG_INFRAREDALM_END,					// ���߱�������
	ZLNET_NEWLOG_IPCONFLICT,						// IP��ͻ
	ZLNET_NEWLOG_IPCONFLICT_RESUME,					// IP�ָ�
	ZLNET_NEWLOG_SDPLUG_IN,							// SD������
	ZLNET_NEWLOG_SDPLUG_OUT,						// SD���γ�
	ZLNET_NEWLOG_NET_PORT_BIND_FAILED,				// ����˿ڰ�ʧ��
	ZLNET_NEWLOG_AUTOMATIC_RECORD = 0x0400,			// �Զ�¼��
	ZLNET_NEWLOG_MANUAL_RECORD,						// �ֶ�¼��
	ZLNET_NEWLOG_CLOSED_RECORD,						// ֹͣ¼��
	ZLNET_NEWLOG_LOGIN = 0x0500,					// ��¼
	ZLNET_NEWLOG_LOGOUT,							// ע��
	ZLNET_NEWLOG_ADD_USER,							// ����û�
	ZLNET_NEWLOG_DELETE_USER,						// ɾ���û�
	ZLNET_NEWLOG_MODIFY_USER,						// �޸��û�
	ZLNET_NEWLOG_ADD_GROUP,							// ����û���
	ZLNET_NEWLOG_DELETE_GROUP,						// ɾ���û���
	ZLNET_NEWLOG_MODIFY_GROUP,						// �޸��û���
	ZLNET_NEWLOG_NET_LOGIN = 0x0508,				// �����û���¼
	ZLNET_NEWLOG_CLEAR = 0x0600,					// �����־
	ZLNET_NEWLOG_SEARCHLOG,							// ��ѯ��־
	ZLNET_NEWLOG_SEARCH = 0x0700,					// ¼���ѯ
	ZLNET_NEWLOG_DOWNLOAD,							// ¼������
	ZLNET_NEWLOG_PLAYBACK,							// ¼��ط�
	ZLNET_NEWLOG_BACKUP,							// ����¼���ļ�
	ZLNET_NEWLOG_BACKUPERROR,						// ����¼���ļ�ʧ��
	
	ZLNET_NEWLOG_TYPE_NR = 8,		
} ZLNET_NEWLOG_TYPE;

///////////////////////////////�����Խ����///////////////////////////////

// ������������
typedef enum __ZLNET_TALK_CODING_TYPE
{
	ZLNET_TALK_DEFAULT = 0,							// ��ͷPCM
	ZLNET_TALK_PCM = 1,								// ��ͷPCM
	ZLNET_TALK_G711a,								// G711a
	ZLNET_TALK_AMR,									// AMR
	ZLNET_TALK_G711u,								// G711u
	ZLNET_TALK_G726,								// G726
} ZLNET_TALK_CODING_TYPE;

// �Խ���ʽ
typedef enum __ZLNET_USEDEV_MODE
{
	ZLNET_TALK_CLIENT_MODE,							// ���ÿͻ��˷�ʽ���������Խ�
	ZLNET_TALK_SERVER_MODE,							// ���÷�������ʽ���������Խ�
	ZLNET_TALK_ENCODE_TYPE,							// ���������Խ������ʽ
	ZLNET_ALARM_LISTEN_MODE,						// ���ñ������ķ�ʽ
	ZLNET_CONFIG_AUTHORITY_MODE,					// ����ͨ��Ȩ�޽������ù���
} ZLNET_USEDEV_MODE;

// AMR��������
typedef enum __ZLNET_ARM_ENCODE_MODE
{
	ZLNET_TALK_AMR_AMR475 = 1,						// AMR475����
	ZLNET_TALK_AMR_AMR515,							// AMR515����
	ZLNET_TALK_AMR_AMR59,							// AMR59����
	ZLNET_TALK_AMR_AMR67,							// AMR67����
	ZLNET_TALK_AMR_AMR74,							// AMR74����
	ZLNET_TALK_AMR_AMR795,							// AMR795����
	ZLNET_TALK_AMR_AMR102,							// AMR102����
	ZLNET_TALK_AMR_AMR122,							// AMR122����
} ZLNET_ARM_ENCODE_MODE;

/////////////////////////////////�������/////////////////////////////////

// �������ͣ���ӦZLNET_ControlDevice�ӿ�
typedef enum _ZLNET_CtrlType
{
	ZLNET_CTRL_REBOOT = 0,							// �����豸	
	ZLNET_CTRL_SHUTDOWN,							// �ر��豸
	ZLNET_CTRL_DISK,								// Ӳ�̹���
	ZLNET_KEYBOARD_POWER = 3,						// �������
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
	ZLNET_TRIGGER_ALARM_IN = 100,					// ������������
	ZLNET_TRIGGER_ALARM_OUT,						// �����������
	ZLNET_CTRL_MATRIX,								// �������
	ZLNET_CTRL_SDCARD,								// SD������(IPC��Ʒ)����ͬӲ�̿���
	ZLNET_BURNING_START,							// ��¼�����ƣ���ʼ��¼
	ZLNET_BURNING_STOP,								// ��¼�����ƣ�������¼
	ZLNET_BURNING_ADDPWD,							// ��¼�����ƣ���������(��'\0'Ϊ��β���ַ�������󳤶�8λ)
	ZLNET_BURNING_ADDHEAD,							// ��¼�����ƣ�����Ƭͷ(��'\0'Ϊ��β���ַ�������󳤶�1024�ֽڣ�֧�ַ��У��зָ���'\n')
	ZLNET_BURNING_ADDSIGN,							// ��¼�����ƣ����Ӵ�㵽��¼��Ϣ(������)
	ZLNET_BURNING_ADDCURSTOMINFO,					// ��¼�����ƣ��Զ������(��'\0'Ϊ��β���ַ�������󳤶�1024�ֽڣ�֧�ַ��У��зָ���'\n')
	ZLNET_CTRL_RESTOREDEFAULT,						// �ָ��豸��Ĭ������
	ZLNET_CTRL_CAPTURE_START,						// �����豸ץͼ
	ZLNET_CTRL_CLEARLOG,							// �����־
	ZLNET_TRIGGER_ALARM_WIRELESS = 200,			// �������߱���(IPC��Ʒ)
	ZLNET_MARK_IMPORTANT_RECORD,					// ��ʶ��Ҫ¼���ļ�
	ZLNET_CTRL_DISK_SUBAREA, 						// ����Ӳ�̷���	
	ZLNET_BURNING_ATTACH,							// ��¼�����ƣ�������¼.
	ZLNET_BURNING_PAUSE,							// ��¼��ͣ
	ZLNET_BURNING_CONTINUE,						// ��¼����
	ZLNET_BURNING_POSTPONE,						// ��¼˳��
	ZLNET_CTRL_OEMCTRL,							// ��ͣ����
	ZLNET_BACKUP_START,							// �豸���ݿ�ʼ
	ZLNET_BACKUP_STOP,								// �豸����ֹͣ
} ZLNET_CtrlType;

// IO���������ӦZLNET_QueryIOControlState�ӿ�
typedef enum _ZLNET_IOTYPE
{
	ZLNET_ALARMINPUT = 1,							// ���Ʊ�������
	ZLNET_ALARMOUTPUT = 2,							// ���Ʊ������
	ZLNET_DECODER_ALARMOUT = 3,					// ���Ʊ������������
	ZLNET_WIRELESS_ALARMOUT = 5,					// �������߱������
	ZLNET_ALARM_TRIGGER_MODE = 7,					// ����������ʽ���ֶ�,�Զ�,�رգ���ʹ��TRIGGER_MODE_CONTROL�ṹ��
} ZLNET_IOTYPE;

/////////////////////////////////�������/////////////////////////////////

// �ֱ���ö�٣���ZL_DSP_ENCODECAPʹ��
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

// �����ļ����ͣ���ZLNET_ExportConfigFile�ӿ�ʹ��
typedef enum __ZLNET_CONFIG_FILE_TYPE
{
	ZLNET_CONFIGFILE_ALL = 0,						// ȫ�������ļ�
	ZLNET_CONFIGFILE_LOCAL,						// ���������ļ�
	ZLNET_CONFIGFILE_NETWORK,						// ���������ļ�
	ZLNET_CONFIGFILE_USER,							// �û������ļ�
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

/////////////////////////////////��̭����/////////////////////////////////

// �������ͣ�Ŀǰʹ�ø�ö�ٵĽӿ�����̭���벻Ҫʹ��
typedef enum _ZLNET_CFG_INDEX
{
    ZLNET_CFG_GENERAL = 0,						        // ��ͨ
	ZLNET_CFG_COMM,									// ����
	ZLNET_CFG_NET,									    // ����
	ZLNET_CFG_RECORD,									// ¼��
	ZLNET_CFG_CAPTURE,								    // ͼ������
	ZLNET_CFG_PTZ,								    	// ��̨
	ZLNET_CFG_DETECT,									// ��̬���
	ZLNET_CFG_ALARM,									// ����
	ZLNET_CFG_DISPLAY,								    // ��ʾ
	ZLNET_CFG_RESERVED,								// ������ʹ��������
	ZLNET_CFG_TITLE = 10,								// ͨ������
	ZLNET_CFG_MAIL = 11,								// �ʼ�����
	ZLNET_CFG_EXCAPTURE = 12,							// Ԥ��ͼ������
	ZLNET_CFG_PPPOE = 13,								// pppoe����
	ZLNET_CFG_DDNS = 14,								// DDNS����
	ZLNET_CFG_SNIFFER	= 15,							// ������Ӳ�������
	ZLNET_CFG_DSPINFO	= 16,							// ����������Ϣ
	ZLNET_CFG_COLOR = 126,							    // ��ɫ������Ϣ
	ZLNET_CFG_ALL,									    // ����
} ZLNET_CFG_INDEX;

//NVR����ͨ��״̬
typedef enum _ZLNET_NVR_NET_CHANNEL_STATE
{
	ZLNET_STATE_NULL = 0,			//����
	ZLNET_STATE_NO_SET,				//δ����
	ZLNET_STATE_ERROR,				//����
	ZLNET_STATE_LOGINING,			//���ڵ�¼
	ZLNET_STATE_LOGIN_TIMEOUT,		//��¼��ʱ
	ZLNET_STATE_NET_FAILED,			//�������
	ZLNET_STATE_USER_PWD_FAILED,	//�û����������
	ZLNET_STATE_USER_UNREPEAT,		//�˺Ų��ܸ���
	ZLNET_STATE_USER_LOCKED,		//�ʺ�������
	ZLNET_STATE_CHANNEL_UNEXIST,	//ͨ��������
	ZLNET_STATE_MAIN_STREAM_NODATA,	//������������
	ZLNET_STATE_SUB_STREAM_NODATA,	//�޸���������
	ZLNET_STATE_VDEC_LACK_ABILITY,	//������������
	ZLNET_STATE_VDEC_INABILITY,		//�޷�����
	ZLNET_STATE_NET_LACK_ABILITY,	//���������������
} ZLNET_NVR_NET_CHANNEL_STATE;

//DDNS����
typedef enum _ZLNET_DDNS_MODE
{
	ZLNET_ZL_DDNS = 0,
	ZLNET_BXS_DDNS,
} ZLNET_DDNS_MODE;

/************************************************************************
 ** �ṹ�嶨��
 ***********************************************************************/
// ʱ��
typedef struct 
{
	DWORD				dwYear;					// ��
	DWORD				dwMonth;				// ��
	DWORD				dwDay;					// ��
	DWORD				dwHour;					// ʱ
	DWORD				dwMinute;				// ��
	DWORD				dwSecond;				// ��
} ZLNET_TIME,*LPZLNET_TIME;

// ��־��Ϣ���ʱ�䶨��
typedef struct _ZLNET_DEVTIME
{
	DWORD				second		:6;			// ��	1-60		
	DWORD				minute		:6;			// ��	1-60		
	DWORD				hour		:5;			// ʱ	1-24		
	DWORD				day			:5;			// ��	1-31		
	DWORD				month		:4;			// ��	1-12		
	DWORD				year		:6;			// ��	2000-2063	
} ZLNET_DEVTIME, *LPZLNET_DEVTIME;

// �ص�����(�첽�ӿ�)
typedef struct __ZLNET_CALLBACK_DATA 
{
	int					nResultCode;			// �����룻0���ɹ�
	char				*pBuf;					// �������ݣ����������û����ٵģ��ӽӿ��βδ���
	int					nRetLen;				// ���ճ���
	LONG				lOperateHandle;			// �������
	void*				userdata;				// ������Ӧ�û�����
	char				reserved[16];
} ZLNET_CALLBACK_DATA, *LPZLNET_CALLBACK_DATA;

///////////////////////////////������ض���///////////////////////////////

// �ص���Ƶ����֡��֡�����ṹ��
typedef struct _ZLNET_VideoFrameParam
{
	BYTE				encode;					// ��������
	BYTE				frametype;				// I = 0, P = 1, B = 2...
	BYTE				format;					// PAL - 0, NTSC - 1
	BYTE				size;					// CIF - 0, HD1 - 1, 2CIF - 2, D1 - 3, VGA - 4, QCIF - 5, QVGA - 6 ,
												// SVCD - 7,QQVGA - 8, SVGA - 9, XVGA - 10,WXGA - 11,SXGA - 12,WSXGA - 13,UXGA - 14,WUXGA - 15, LFT - 16, 720 - 17, 1080 - 18
	DWORD				fourcc;					// �����H264��������Ϊ0��MPEG4����������дFOURCC('X','V','I','D');
	DWORD				reserved;				// ����
	ZLNET_TIME			struTime;				// ʱ����Ϣ
} ZLNET_VideoFrameParam;

// �ص���Ƶ����֡��֡�����ṹ��
typedef struct _ZLNET_CBPCMDataParam
{
	BYTE				channels;				// ������
	BYTE				samples;				// ���� 0 - 8000, 1 - 11025, 2 - 16000, 3 - 22050, 4 - 32000, 5 - 44100, 6 - 48000
	BYTE				depth;					// ������� ȡֵ8����16�ȡ�ֱ�ӱ�ʾ
	BYTE				param1;					// 0 - ָʾ�޷��ţ�1-ָʾ�з���
	DWORD				reserved;				// ����
} ZLNET_CBPCMDataParam;

// ͨ��������Ļ���ӵ����ݽṹ
typedef struct _ZLNET_CHANNEL_OSDSTRING
{
	BOOL				bEnable;				// ʹ��
	DWORD				dwPosition[ZLNET_MAX_STRING_LINE_LEN];	//�����ַ���λ�á���1-9������ʾ����С����λ�ö�Ӧ
												//		7����	8��		9����
												//		4��		5��		6��
												//		1����	2��		3����
	char				szStrings[ZLNET_MAX_STRING_LINE_LEN][ZLNET_MAX_PER_STRING_LEN];	// ��������ַ���ÿ�����20���ֽ�
} ZLNET_CHANNEL_OSDSTRING;

///////////////////////////////�ط���ض���///////////////////////////////

// ¼���ļ���Ϣ
typedef struct
{
    unsigned int		ch;						// ͨ����
    char				filename[128];			// �ļ���
    unsigned int		size;					// �ļ�����
    ZLNET_TIME			starttime;				// ��ʼʱ��
    ZLNET_TIME			endtime;				// ����ʱ��
    unsigned int		driveno;				// ���̺�(��������¼��ͱ���¼������ͣ�0��127��ʾ����¼��128��ʾ����¼��)
    unsigned int		startcluster;			// ��ʼ�غ�
	BYTE				nRecordFileType;		// ¼���ļ�����  0����ͨ¼��1������¼��2���ƶ���⣻3������¼��4��ͼƬ
	BYTE                bImportantRecID;		// 0:��ͨ¼�� 1:��Ҫ¼��
	BYTE                bHint;					// �ļ���λ����
	BYTE                bReserved;				// ����
} ZLNET_RECORDFILE_INFO, *LPZLNET_RECORDFILE_INFO;

typedef enum _ZLNET_DOWNLOADFILE_MODE
{
	ZLNET_DOWNLOADFILE_DEFAULT = 0,		//Ĭ��, ȫ������
	ZLNET_MODE_VIDEO,		//ֻ������Ƶ�ļ�, ��ȥ�������װͷ
}ZLNET_DOWNLOADFILE_MODE;

// ϵͳʱ��ṹ
typedef struct SYSTEM_TIME{
    int  year;///< �ꡣ   
	int  month;///< �£�January = 1, February = 2, and so on.   
	int  day;///< �ա�   
	int  hour;///< ʱ��   
	int  minute;///< �֡�   
	int  second;///< �롣   
}SYSTEM_TIME;

typedef struct SYSTEM_TIME_DST
{
    int  year;///< �ꡣ   
	int  month;///< �£�January = 1, February = 2, and so on.   
	int  day;///< �ա�   
	int  wday;///< ���ڣ�Sunday = 0, Monday = 1, and so on   
	int  hour;///< ʱ��   
	int  minute;///< �֡�   
	int  second;///< �롣   
	int  isdst;///< ����ʱ��ʶ��   
}SYSTEM_TIME_DST;

//����ʱʱ��ṹ															    
typedef struct _ZLNET_IDVR_TIME_DST
{
	int tm_year;    
	int tm_mon;     // [0,11] 
	int tm_mday;    // [1,31] 
	int tm_wday;	// ����
	int tm_hour;    // [0,23] 
	int tm_min;     // [0,59] 
	int tm_sec;     // [0,59] 
	int  isdst;		// ����ʱ��ʶ��   
}ZLNET_IDVR_TIME_DST;

//����DVR�ļ���Ϣ
typedef struct _ZLNET_IDVR_LOG_FILE_ITEM
{
	unsigned long		 id;			//����ID	
	ZLNET_DEVTIME		 time;		//ʱ��
	unsigned char 		 chn;			//ͨ��
	unsigned char		 type;		//�ļ�����1¼��2ͼƬ
	unsigned char 		 Length;	//¼��ʱ��(S)
	unsigned char     Reserve; //����λ
}ZLNET_IDVR_LOG_FILE_ITEM, *LPZLNET_IDVR_LOG_FILE_ITEM;

// ����¼��ʱ��
typedef struct  
{
	int					nChnCount;				// ͨ����Ŀ
	ZLNET_TIME			stuFurthestTime[16];	// ����¼��ʱ��,��ЧֵΪǰ��0 �� (nChnCount-1)��.���ĳͨ��û��¼��Ļ�������¼��ʱ��ȫΪ0
	BYTE				bReserved[384];			// �����ֶ�
} ZLNET_FURTHEST_RECORD_TIME;

///////////////////////////////������ض���///////////////////////////////


// ��ͨ������Ϣ
typedef struct
{
	int					channelcount;
	int					alarminputcount;
	unsigned char		alarm[16];				// �ⲿ����
	unsigned char		motiondection[16];		// ��̬���
	unsigned char		videolost[16];			// ��Ƶ��ʧ
} ZLNET_CLIENT_STATE;

// ����IO����
typedef struct 
{
	unsigned short		index;					// �˿����
	unsigned short		state;					// �˿�״̬
} ZLNET_ALARM_CONTROL;

// ������ʽ
typedef struct
{
	unsigned short		index;					// �˿����
	unsigned short		mode;					// ������ʽ(0�ر�1�ֶ�2�Զ�);�����õ�ͨ����sdkĬ�Ͻ�����ԭ�������á�
	BYTE				bReserved[28];			
} ZLNET_TRIGGER_MODE_CONTROL;

// ��������������
typedef struct 
{
	int					decoderNo;				// �����������ţ���0��ʼ
	unsigned short		alarmChn;				// ��������ڣ���0��ʼ
	unsigned short		alarmState;				// �������״̬��1���򿪣�0���ر�
} ZLNET_DECODER_ALARM_CONTROL;

// �����ϴ����ܵı�����Ϣ
typedef struct  
{
	DWORD				dwAlarmType;			// �������ͣ�dwAlarmType = ZLNET_UPLOAD_EVENTʱ��dwAlarmMask��bAlarmDecoderIndex����Ч��
	DWORD				dwAlarmMask;			// ������Ϣ���룬��λ��ʾ������ͨ��״̬
	char				szGlobalIP[ZLNET_MAX_IPADDR_LEN];	// �ͻ���IP��ַ
	char				szDomainName[ZLNET_MAX_DOMAIN_NAME_LEN];	// �ͻ�������
	int					nPort;					// �����ϴ�ʱ�ͻ������ӵĶ˿�
	char				szAlarmOccurTime[ZLNET_ALARM_OCCUR_TIME_LEN];	// ����������ʱ��
	BYTE				bAlarmDecoderIndex;		// ��ʾ�ڼ���������������dwAlarmType = ZLNET_UPLOAD_DECODER_ALARM ����Ч.
	BYTE				bReservedSpace[15];
} ZLNET_NEW_ALARM_UPLOAD;

// �����豸�ϴ���Ϣ
typedef struct  
{
	char				szDomainName[ZLNET_MAX_DOMAIN_NAME_LEN];	// �豸����
	char				szIP[ZLNET_MAX_IPADDR_LEN];					// �豸IP��ַ
	int					nPort;								//�豸�˿ں�
	char				szSerial[ZLNET_DEV_SERIALNO_LEN];	//�豸���к�
	char				szOccurTime[ZLNET_ALARM_OCCUR_TIME_LEN];	//�ϴ�ʱ��
}ZLNET_IDVR_UPLOAD;

// ¼��״̬�仯������Ϣ
typedef struct
{
	int					nChannel;				// ¼��ͨ����
	char				reserved[12];
} ZLNET_ALARM_RECORDING_CHANGED;

/////////////////////////////�����Խ���ض���/////////////////////////////

// ��Ƶ��ʽ��Ϣ
typedef struct
{
	BYTE				byFormatTag;			// �������ͣ���0��PCM
	WORD				nChannels;				// ������
	WORD				wBitsPerSample;			// �������			
	DWORD				nSamplesPerSec;			// ������
} ZLNET_AUDIO_FORMAT, *LPZLNET_AUDIO_FORMAT;

/////////////////////////////�û�������ض���/////////////////////////////

// ֧���û�����󳤶�Ϊ8λ���豸����ӦZLNET_QueryUserInfo��ZLNET_OperateUserInfo�ӿ�
// Ȩ����Ϣ
typedef struct _ZLNET_OPR_RIGHT
{
	DWORD				dwID;
	char				name[ZLNET_RIGHT_NAME_LENGTH];
	char				memo[ZLNET_MEMO_LENGTH];
} ZLNET_OPR_RIGHT;

// �û���Ϣ
typedef struct _ZLNET_USER_INFO
{
	DWORD				dwID;
	DWORD				dwGroupID;
	char				name[ZLNET_USER_NAME_LENGTH];
	char				passWord[ZLNET_USER_PSW_LENGTH];
	DWORD				dwRightNum;
	DWORD				rights[ZLNET_MAX_RIGHT_NUM];
	char				memo[ZLNET_MEMO_LENGTH];
	DWORD				dwReusable;				// �Ƿ��ã�1�����ã�0��������
} ZLNET_USER_INFO;

// �û�����Ϣ
typedef struct _ZLNET_USER_GROUP_INFO
{
	DWORD				dwID;
	char				name[ZLNET_USER_NAME_LENGTH];
	DWORD				dwRightNum;
	DWORD				rights[ZLNET_MAX_RIGHT_NUM];
	char				memo[ZLNET_MEMO_LENGTH];
} ZLNET_USER_GROUP_INFO;

// �û���Ϣ��
typedef struct _ZLNET_USER_MANAGE_INFO
{
	DWORD				dwRightNum;				// Ȩ����Ϣ
	ZLNET_OPR_RIGHT			rightList[ZLNET_MAX_RIGHT_NUM];
	DWORD				dwGroupNum;				// �û�����Ϣ
	ZLNET_USER_GROUP_INFO		groupList[ZLNET_MAX_GROUP_NUM];
	DWORD				dwUserNum;				// �û���Ϣ
	ZLNET_USER_INFO			userList[ZLNET_MAX_USER_NUM];
	DWORD				dwSpecial;				// �û�����������1��֧���û����ã�0����֧���û�����
} ZLNET_USER_MANAGE_INFO;

// ֧���û�����󳤶�Ϊ8λ��16λ���豸����Ӧ��չ�ӿ�CLIENT_QueryUserInfoEx��CLIENT_OperateUserInfoEx
#define ZLNET_USER_NAME_LENGTH_EX		16			// �û�������
#define ZLNET_USER_PSW_LENGTH_EX		16			// ����

// Ȩ����Ϣ
typedef struct _ZLNET_OPR_RIGHT_EX
{
	DWORD				dwID;
	char				name[ZLNET_RIGHT_NAME_LENGTH];
	char				memo[ZLNET_MEMO_LENGTH];
} ZLNET_OPR_RIGHT_EX;

// �û���Ϣ
typedef struct _ZLNET_USER_INFO_EX
{
	DWORD				dwID;
	DWORD				dwGroupID;
	char				name[ZLNET_USER_NAME_LENGTH_EX];
	char				passWord[ZLNET_USER_PSW_LENGTH_EX];
	DWORD				dwRightNum;
	DWORD				rights[ZLNET_MAX_RIGHT_NUM];
	char				memo[ZLNET_MEMO_LENGTH];
	DWORD				dwFouctionMask;			// ���룬0x00000001 - ֧���û�����
	BYTE				byReserve[32];
} ZLNET_USER_INFO_EX;

// �û�����Ϣ
typedef struct _ZLNET_USER_GROUP_INFO_EX
{
	DWORD				dwID;
	char				name[ZLNET_USER_NAME_LENGTH_EX];
	DWORD				dwRightNum;
	DWORD				rights[ZLNET_MAX_RIGHT_NUM];
	char				memo[ZLNET_MEMO_LENGTH];
} ZLNET_USER_GROUP_INFO_EX;

// �û���Ϣ��
typedef struct _ZLNET_USER_MANAGE_INFO_EX
{
	DWORD				dwRightNum;				// Ȩ����Ϣ
	ZLNET_OPR_RIGHT_EX		rightList[ZLNET_MAX_RIGHT_NUM];
	DWORD				dwGroupNum;				// �û�����Ϣ
	ZLNET_USER_GROUP_INFO_EX  groupList[ZLNET_MAX_GROUP_NUM];
	DWORD				dwUserNum;				// �û���Ϣ
	ZLNET_USER_INFO_EX		userList[ZLNET_MAX_USER_NUM];
	DWORD				dwFouctionMask;			// ���룻0x00000001 - ֧���û����ã�0x00000002 - �����޸���ҪУ��
	BYTE				byNameMaxLength;		// ֧�ֵ��û�����󳤶�
	BYTE				byPSWMaxLength;			// ֧�ֵ�������󳤶�
	BYTE				byReserve[254];
} ZLNET_USER_MANAGE_INFO_EX;

///////////////////////////////��ѯ��ض���///////////////////////////////

// �豸֧����������
typedef struct _ZLNET_LANGUAGE_DEVINFO
{
	DWORD				dwLanguageNum;			// ֧�����Ը���
	BYTE				byLanguageType[252];	// ö��ֵ�����ZL_LANGUAGE_TYPE
} ZLNET_LANGUAGE_DEVINFO, *LPZLNET_LANGUAGE_DEVINFO;

// Ӳ����Ϣ
typedef struct
{
	DWORD				dwVolume;				// Ӳ�̵�����
	DWORD				dwFreeSpace;			// Ӳ�̵�ʣ��ռ�
	BYTE				dwStatus;				// Ӳ�̵�״̬,0-����,1-�,2-���ϵȣ���DWORD����ĸ�BYTE
	BYTE				bDiskNum;				// Ӳ�̺�
	BYTE				bSubareaNum;			// ������
	BYTE				bSignal;				// ��ʶ��0Ϊ���� 1ΪԶ��
} ZLNET_DEV_DISKSTATE,*LPZLNET_DEV_DISKSTATE;

// �豸Ӳ����Ϣ
typedef struct _ZLNET_HARDDISK_STATE
{
	DWORD				dwDiskNum;				// ����
	ZLNET_DEV_DISKSTATE	stDisks[ZLNET_MAX_DISKNUM];// Ӳ�̻������Ϣ
} ZLNET_HARDDISK_STATE, *LPZLNET_HARDDISK_STATE;

typedef ZLNET_HARDDISK_STATE	ZLNET_SDCARD_STATE;	// SD�������ݽṹͬӲ����Ϣ

// ����������Ϣ
typedef struct  
{
	ZLNET_TALK_CODING_TYPE	encodeType;				// ��������
	int					nAudioBit;				// λ������8��16
	DWORD				dwSampleRate;			// �����ʣ���8000��16000
	char				reserved[64];
} ZLNET_DEV_TALKDECODE_INFO;

// �豸֧�ֵ������Խ�����
typedef struct 
{
	int					nSupportNum;			// ����
	ZLNET_DEV_TALKDECODE_INFO type[64];				// ��������
	char				reserved[64];
} ZLNET_DEV_TALKFORMAT_LIST;

// ��̨������Ϣ
#define  ZLNET_NAME_MAX_LEN 16
typedef struct 
{
	DWORD				dwHighMask;				// �����������λ
	DWORD				dwLowMask;				// �����������λ
	char				szName[ZLNET_NAME_MAX_LEN];	// ������Э����
	WORD				wCamAddrMin;			// ͨ����ַ����Сֵ
	WORD				wCamAddrMax;			// ͨ����ַ�����ֵ
	WORD				wMonAddrMin;			// ���ӵ�ַ����Сֵ
	WORD				wMonAddrMax;			// ���ӵ�ַ�����ֵ
	BYTE				bPresetMin;				// Ԥ�õ����Сֵ
	BYTE				bPresetMax;				// Ԥ�õ�����ֵ
	BYTE				bTourMin;				// �Զ�Ѳ����·����Сֵ
	BYTE				bTourMax;				// �Զ�Ѳ����·�����ֵ
	BYTE				bPatternMin;			// �켣��·����Сֵ
	BYTE				bPatternMax;			// �켣��·�����ֵ
	BYTE				bTileSpeedMin;			// ��ֱ�ٶȵ���Сֵ
	BYTE				bTileSpeedMax;			// ��ֱ�ٶȵ����ֵ
	BYTE				bPanSpeedMin;			// ˮƽ�ٶȵ���Сֵ
	BYTE				bPanSpeedMax;			// ˮƽ�ٶȵ����ֵ
	BYTE				bAuxMin;				// �������ܵ���Сֵ
	BYTE				bAuxMax;				// �������ܵ����ֵ
	int					nInternal;				// ���������ʱ����
	char				cType;					// Э�������
	BYTE				bReserved_1;			// ����
	BYTE				bFuncMask;				// Э�鹦������,��λ��ʾ,�ã���ʾ֧��,��һλ��ʾ������̨���ܣ�������λ��ʱ����
	BYTE				bReserved_2;
	char				Reserved[4];
} ZLNET_PTZ_OPT_ATTR;

// ��¼����Ϣ
typedef struct _ZLNET_DEV_BURNING
{
	DWORD				dwDriverType;			// ��¼���������ͣ�0��DHFS��1��DISK��2��CDRW
	DWORD				dwBusType;				// �������ͣ�0��USB��1��1394��2��IDE
	DWORD				dwTotalSpace;			// ������(KB)
	DWORD				dwRemainSpace;			// ʣ������(KB)
	BYTE				dwDriverName[ZLNET_BURNING_DEV_NAMELEN];	// ��¼����������
} ZLNET_DEV_BURNING, *LPZLNET_DEV_BURNING;

// �豸��¼����Ϣ
typedef struct _ZLNET_BURNING_DEVINFO
{
	DWORD				dwDevNum;				// ��¼�豸����
	ZLNET_DEV_BURNING		stDevs[ZLNET_MAX_BURNING_DEV_NUM];	// ����¼�豸��Ϣ
} ZLNET_BURNING_DEVINFO, *LPZLNET_BURNING_DEVINFO;

// ��¼����
typedef struct _ZLNET_BURNING_PROGRESS
{
	BYTE				bBurning;				// ��¼��״̬��0�����Կ�¼��1����¼�����Ͳ��ԣ���һ���ǹ����豸��
												// 2��δ�ҵ���¼����3�������������ڿ�¼��4����¼�����ڷǿ���״̬�����ڱ��ݡ���¼��ط���
	BYTE				bRomType;				// ��Ƭ���ͣ�0����ŵ�ļ�ϵͳ��1���ƶ�Ӳ�̻�U�̣�2������
	BYTE				bOperateType;			// �������ͣ�0�����У�1�����ڱ����У�2�����ڿ�¼�У�3�����ڽ��й��̻ط�
	BYTE				bType;					// ���ݻ��¼����״̬��0��ֹͣ�������1����ʼ��2������3������4�����ڳ�ʼ��
	ZLNET_TIME			stTimeStart;			// ��ʼʱ�䡡
	DWORD				dwTimeElapse;			// �ѿ�¼ʱ��(��)
	DWORD				dwTotalSpace;			// ����������
	DWORD				dwRemainSpace;			// ����ʣ������
	DWORD				dwBurned;				// �ѿ�¼����
	WORD				dwStatus;				// ����
	WORD				wChannelMask;			// ���ڿ�¼��ͨ������
} ZLNET_BURNING_PROGRESS, *LPZLNET_BURNING_PROGRESS;

// ��־��Ϣ����Ӧ�ӿ�CLIENT_QueryLog�ӿ�
typedef struct _ZLNET_LOG_ITEM
{
    ZLNET_DEVTIME			time;					// ����
    unsigned short		type;					// ����
    unsigned char		reserved;				// ����
    unsigned char		data;					// ����
    unsigned char		context[8];				// ����
} ZLNET_LOG_ITEM, *LPZLNET_LOG_ITEM;

// ��־��Ϣ����Ӧ��չ�ӿ�CLIENT_QueryLogEx������reserved(int nType=1;reserved=&nType;)
typedef struct _ZLNET_NEWLOG_ITEM
{
	ZLNET_DEVTIME			time;					// ����
	WORD				type;					// ����
	WORD				data;					// ����
	char				szOperator[8]; 			// �û���
	BYTE				context[16];		    // ����	
} ZLNET_NEWLOG_ITEM, *LPZLNET_NEWLOG_ITEM;

// ��־��Ϣ����Ӧ�ӿ�CLIENT_QueryDeviceLog�ӿ�
typedef struct _ZLNET_DEVICE_LOG_ITEM
{
	int					nLogType;				// ��־����
	ZLNET_DEVTIME			stuOperateTime;			// ����
	char				szOperator[16]; 		// ������
	BYTE				bReserved[3];
	BYTE				bUnionType;				//  union�ṹ����,0:szLogContext��1:stuOldLog��
	union
	{
		char			szLogContext[64];		// ��־����
		struct 
		{
			ZLNET_LOG_ITEM		stuLog;				// �ɵ���־�ṹ��
			BYTE			bReserved[48];		// ����
		}stuOldLog;
	};
	char				reserved[16];
} ZLNET_DEVICE_LOG_ITEM, *LPZLNET_DEVICE_LOG_ITEM;

// ¼����־��Ϣ����Ӧ��־�ṹ�����context
typedef struct _ZLNET_LOG_ITEM_RECORD
{
	ZLNET_DEVTIME			time;					// ʱ��
	BYTE				channel;				// ͨ��
	BYTE				type;					// ¼������
	BYTE				reserved[2];
} ZLNET_LOG_ITEM_RECORD, *LPZLNET_LOG_ITEM_RECORD;

typedef struct _ZLNET_QUERY_DEVICE_LOG_PARAM
{
	ZLNET_LOG_QUERY_TYPE	emLogType;				// ��ѯ��־����
	ZLNET_TIME			stuStartTime;			// ��ѯ��־�Ŀ�ʼʱ��
	ZLNET_TIME			stuEndTime;				// ��ѯ��־�Ľ���ʱ��
	int					nStartNum;				// ��ʱ����дӵڼ�����־��ʼ��ѯ����ʼ��һ�β�ѯ����Ϊ0
	int					nEndNum;				// һ�β�ѯ�е��ڼ�����־������
	BYTE				bReserved[48];
} ZLNET_QUERY_DEVICE_LOG_PARAM;

// �豸Ӳ�����¼����Ϣ
typedef struct __ZLNET_DEV_DISK_RECORD_INFO 
{
	ZLNET_TIME			stuBeginTime;			// ����¼��ʱ��
	ZLNET_TIME			stuEndTime;				// ���¼��ʱ��
	char				reserved[128];
} ZLNET_DEV_DISK_RECORD_INFO;

///////////////////////////////������ض���///////////////////////////////

// Ӳ�̲���
typedef struct _ZLNET_DISKCTRL_PARAM
{
	DWORD				dwSize;					// �ṹ���С���汾������
	int					nIndex;					// ΪӲ����Ϣ�ṹ��ZLNET_HARDDISK_STATE�������stDisks�±꣬��0��ʼ
	int					ctrlType;				// �������ͣ�
												// 0 - �������, 1 - ��Ϊ��д��, 2 - ��Ϊֻ����
												// 3 - ��Ϊ������, 4 - �ָ�����, 5 - ��Ϊ������
} ZLNET_DISKCTRL_PARAM;

typedef struct  
{
	BYTE				bSubareaNum;			// Ԥ�����ĸ���
	BYTE				bIndex;					// ΪӲ����Ϣ�ṹ��ZL_HARDDISK_STATE�������stDisks�±꣬��0��ʼ
	BYTE				bSubareaSize[32];		// ������С���ٷֱȣ�
	BYTE				bReserved[30];			// ����
} ZLNET_DISKCTRL_SUBAREA;

// ����״̬
typedef struct _ZLNET_ALARMCTRL_PARAM
{
	DWORD				dwSize;
	int					nAlarmNo;				// ����ͨ���ţ���0��ʼ
	int					nAction;				// 1������������0��ֹͣ����
} ZLNET_ALARMCTRL_PARAM;

// �������
typedef struct _ZLNET_MATRIXCTRL_PARAM
{
	DWORD				dwSize;
	int					nChannelNo;				// ��Ƶ����ţ���0��ʼ
	int					nMatrixNo;				// ��������ţ���0��ʼ
} ZLNET_MATRIXCTRL_PARAM;

// ��¼����
typedef struct _ZLNET_BURNING_PARM
{
	int					channelMask;			// ͨ�����룬��λ��ʾҪ��¼��ͨ��
	int					devMask;				// ��¼�����룬���ݲ�ѯ���Ŀ�¼���б���λ��ʾ
} ZLNET_BURNING_PARM;

// ������¼
typedef struct _ZLNET_BURNING_PARM_ATTACH
{
	BOOL				bAttachBurn;			// �Ƿ�Ϊ������¼��0:����; 1:��
	BYTE				bReserved[12];			// �����ֶ�
} ZLNET_BURNING_PARM_ATTACH;

///////////////////////////////������ض���///////////////////////////////

//-------------------------------�豸����---------------------------------
// �豸��Ϣ
typedef struct
{
	BYTE				sSerialNumber[ZLNET_SERIALNO_LEN];	// ���к�
	BYTE				byAlarmInPortNum;		// DVR�����������
	BYTE				byAlarmOutPortNum;		// DVR�����������
	BYTE				byDiskNum;				// DVRӲ�̸���
	BYTE				byDVRType;				// DVR����, ��ö��ZLNET_DEVICE_TYPE
	BYTE				byChanNum;				// DVRͨ������
} ZLNET_DEVICEINFO, *LPZLNET_DEVICEINFO;

// �豸����汾��Ϣ����16λ��ʾ���汾�ţ���16λ��ʾ�ΰ汾��
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

// �豸����汾��Ϣ����ӦZLNET_DEVICE_TYPE�ӿ�
typedef struct  
{
	char				szDevSerialNo[ZLNET_DEV_SERIALNO_LEN];	// ���к�
	char				byDevType;				// �豸���ͣ���ö��ZLNET_DEVICE_TYPE
	char				szDevType[ZLNET_DEV_TYPE_LEN];	// �豸��ϸ�ͺţ��ַ�����ʽ������Ϊ��
	int					nProtocalVer;			// Э��汾��
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
	char				chHardVersion;	//Ӳ���汾���� 0��16M Flash  1��32M Flash
	char				reserved[255];
} ZLNET_DEV_VERSION_INFO;

//
typedef struct 
{
	unsigned int nMaxEncodePower; ///< DSP ֧�ֵ���߱���������
	unsigned short nMaxSupportChannel; ///< DSP ֧�����������Ƶͨ������
	unsigned short bChannelMaxSetSync; ///< DSP ÿͨ���������������Ƿ�ͬ�� 0-��ͬ��, 1 -ͬ����
	unsigned short nExpandChannel;  ///< DSP ֧�ֵ���չͨ��������Ҫ�Ƕ�·�ط�ʹ�ã�Ŀǰֻ��һ��
	unsigned short  rev;
}ZLNET_CAPTURE_DSPINFO, *LPZLNET_CAPTURE_DSPINFO;

#define MAX_ENC_CHIP_NR (32)
typedef struct  
{
	int EncChipNR;
	ZLNET_CAPTURE_DSPINFO EncChipInfo[MAX_ENC_CHIP_NR];
}ZLNET_CAPTURE_CAPABILITY;

// DSP������������ӦCLIENT_GetDevConfig�ӿ�
typedef struct 
{
	DWORD				dwVideoStandardMask;	// ��Ƶ��ʽ���룬��λ��ʾ�豸�ܹ�֧�ֵ���Ƶ��ʽ
	DWORD				dwImageSizeMask;		// �ֱ������룬��λ��ʾ�豸�ܹ�֧�ֵķֱ�������
	DWORD				dwEncodeModeMask;		// ����ģʽ���룬��λ��ʾ�豸�ܹ�֧�ֵı���ģʽ����	
	DWORD				dwStreamCap;			// ��λ��ʾ�豸֧�ֵĶ�ý�幦�ܣ�
												// ��һλ��ʾ֧��������
												// �ڶ�λ��ʾ֧�ָ�����1
												// ����λ��ʾ֧�ָ�����2
												// ����λ��ʾ֧��jpgץͼ
	DWORD				dwImageSizeMask_Assi[8];// ��ʾ������Ϊ���ֱ���ʱ��֧�ֵĸ������ֱ������롣
	ZLNET_CAPTURE_CAPABILITY captureCapability;
} ZLNET_DSP_ENCODECAP, *LPZLNET_DSP_ENCODECAP;

// DSP������������չ���ͣ���ӦZLNET_DEVICE_TYPE�ӿ�
typedef struct 
{
	DWORD				dwVideoStandardMask;	// ��Ƶ��ʽ���룬��λ��ʾ�豸�ܹ�֧�ֵ���Ƶ��ʽ
	DWORD				dwImageSizeMask;		// �ֱ������룬��λ��ʾ�豸�ܹ�֧�ֵķֱ���
	DWORD				dwEncodeModeMask;		// ����ģʽ���룬��λ��ʾ�豸�ܹ�֧�ֵı���ģʽ
	DWORD				dwStreamCap;			// ��λ��ʾ�豸֧�ֵĶ�ý�幦�ܣ�
												// ��һλ��ʾ֧��������
												// �ڶ�λ��ʾ֧�ָ�����1
												// ����λ��ʾ֧�ָ�����2
												// ����λ��ʾ֧��jpgץͼ
	DWORD				dwImageSizeMask_Assi[32];// ��ʾ������Ϊ���ֱ���ʱ��֧�ֵĸ������ֱ������롣
	ZLNET_CAPTURE_CAPABILITY captureCapability;
	BYTE				bMaxFrameOfImageSize[32];// ��ͬ�ֱ����µ����ɼ�֡�ʣ���dwVideoStandardMask��λ��Ӧ
	BYTE				bEncodeCap;				// ��־������ʱҪ����������������������ò�����Ч��
												// 0���������ı�������+�������ı������� <= �豸�ı���������
												// 1���������ı�������+�������ı������� <= �豸�ı���������
												// �������ı������� <= �������ı���������
												// �������ķֱ��� <= �������ķֱ��ʣ�
												// �������͸�������֡�� <= ǰ����Ƶ�ɼ�֡��
												// 2��N5�ļ��㷽��
												// �������ķֱ��� <= �������ķֱ���
												// ��ѯ֧�ֵķֱ��ʺ���Ӧ���֡��
	char				reserved[95];
} ZLNET_DEV_DSP_ENCODECAP, *LPZLNET_DEV_DSP_ENCODECAP;

// ϵͳ��Ϣ
typedef struct 
{
	DWORD				dwSize;
	/* �������豸��ֻ������ */
	ZLNET_VERSION_INFO		stVersion;
	ZLNET_DSP_ENCODECAP	stDspEncodeCap;			// DSP��������
	BYTE				szDevSerialNo[ZLNET_DEV_SERIALNO_LEN];	// ���к�
	BYTE				byDevType;				// �豸���ͣ���ö��ZLNET_DEVICE_TYPE
	BYTE				szDevType[ZLNET_DEV_TYPE_LEN];	// �豸��ϸ�ͺţ��ַ�����ʽ������Ϊ��
	BYTE				byVideoCaptureNum;		// ��Ƶ������
	BYTE				byAudioCaptureNum;		// ��Ƶ������
	BYTE				byTalkInChanNum;		// NSP
	BYTE				byTalkOutChanNum;		// NSP
	BYTE				byDecodeChanNum;		// NSP
	BYTE				byAlarmInNum;			// �����������
	BYTE				byAlarmOutNum;			// �����������
	BYTE				byNetIONum;				// �������
	BYTE				byUsbIONum;				// USB������
	BYTE				byIdeIONum;				// IDE����
	BYTE				byComIONum;				// ��������
	BYTE				byLPTIONum;				// ��������
	BYTE				byVgaIONum;				// NSP
	BYTE				byIdeControlNum;		// NSP
	BYTE				byIdeControlType;		// NSP
	BYTE				byCapability;			// NSP����չ����
	BYTE				byMatrixOutNum;			// ��Ƶ�����������
	UINT                uOEM;                   // OEM�汾��
	/* �������豸�Ŀ�д���� */
	BYTE				byOverWrite;			// Ӳ��������ʽ(���ǡ�ֹͣ)
	BYTE				byRecordLen;			// ¼��������
	BYTE				byDSTEnable;			// �Ƿ�ʵ������ʱ 1-ʵ�� 0-��ʵ��
	WORD				wDevNo;					// �豸��ţ�����ң��
	BYTE				byVideoStandard;		// ��Ƶ��ʽ:0-PAL,1-NTSC
	BYTE				byDateFormat;			// ���ڸ�ʽ
	BYTE				byDateSprtr;			// ���ڷָ��(0��"."��1��"-"��2��"/")
	BYTE				byTimeFmt;				// ʱ���ʽ (0-24Сʱ��1��12Сʱ)
	BYTE				byLanguage;				// ö��ֵ���ZLNET_LANGUAGE_TYPE
} ZLNET_DEV_SYSTEM_ATTR_CFG, *LPZLNET_DEV_SYSTEM_ATTR_CFG;

// �޸��豸���÷�����Ϣ
typedef struct
{
	DWORD				dwType;					// ����(��GetDevConfig��SetDevConfig������)
	WORD				wResultCode;			// �����룻0���ɹ���1��ʧ�ܣ�2�����ݲ��Ϸ���3����ʱ�޷����ã�4��û��Ȩ��
	WORD   				wRebootSign;			// ������־��0������Ҫ������1����Ҫ��������Ч
	DWORD				dwReserved[2];			// ����	
} ZLNET_DEV_SET_RESULT;

//DST(����ʱ)����
typedef struct  
{
	int					nYear;					// ��[200 - 2037]
	int					nMonth;					// ��[1 - 12]
	int					nHour;					// Сʱ [0 - 23]
	int					nMinute;				// ���� [0 - 59]
	int					nWeekOrDay;				// [-1 - 4]0:��ʾʹ�ð����ڼ���ķ���
												// 1: ���ܼ���: ��һ��,2: �ڶ���,3: ������,4: ������,-1: ���һ��
	union
	{
		int				iWeekDay;				// ��[0 - 6](nWeekOrDay�����ܼ���ʱ)0:������, 1:����һ, 2:���ڶ�,3:������,4:������,5:������,6:������
		int				iDay;					// ����[1 - 31] (nWeekOrDay�������ڼ���)
	};
	
	DWORD				dwReserved[8];			// ����	
}ZLNET_DST_POINT;

typedef struct  
{
	DWORD				dwSize;
	int					nDSTType;				// ����ʱ��λ��ʽ 0:�����ڶ�λ��ʽ, 1:���ܶ�λ��ʽ
	ZLNET_DST_POINT        stDSTStart;             // ��ʼ����ʱ
	ZLNET_DST_POINT        stDSTEnd;				// ��������ʱ
	DWORD				dwReserved[16];			// ����	
}ZLNET_DST_DEV_CFG;


// �Զ�ά������
typedef struct
{
	DWORD				dwSize;
	BYTE				byAutoRebootDay;		// �Զ�������0���Ӳ�, 1��ÿ�죬2��ÿ�����գ�3��ÿ����һ��......
	BYTE				byAutoRebootTime;		// 0��0:00��1��1:00��......23��23:00
	BYTE				byAutoDeleteFilesTime;	// �Զ�ɾ���ļ���0���Ӳ���1��24H��2��48H��3��72H��4��96H��5��ONE WEEK��6��ONE MONTH
	BYTE				reserved[13];			// ����λ
} ZLNET_AUTOMT_CFG;

//-----------------------------ͼ��ͨ������-------------------------------

// ʱ��νṹ															    
typedef struct 
{
	BOOL				bEnable;				// ����ʾ¼��ʱ���ʱ����λ��ʾ����ʹ�ܣ��ӵ�λ����λ�ֱ��ʾ����¼�󡢱���¼����ͨ¼��
	int					iBeginHour;
	int					iBeginMin;
	int					iBeginSec;
	int					iEndHour;
	int					iEndMin;
	int					iEndSec;
} ZLNET_TSECT, *LPZLNET_TSECT;

// ������
typedef struct _ZLNET_POINT
{
	long	x;
	long	y;
}ZLNET_POINT;
// ���򣻸��߾ఴ����8192�ı���
typedef struct {
   long					left;
   long					top;
   long					right;
   long					bottom;
} ZLNET_RECT, *LPZLNET_RECT;

// OSD���Խṹ
typedef struct  __ZLNET_ENCODE_WIDGET
{
	DWORD				rgbaFrontground;		// �����ǰ�������ֽڱ�ʾ���ֱ�Ϊ�졢�̡�����͸����
	DWORD				rgbaBackground;			// ����ı��������ֽڱ�ʾ���ֱ�Ϊ�졢�̡�����͸����
	ZLNET_RECT				rcRect;					// λ��
	BYTE				bShow;					// ��ʾʹ��
	BYTE				byReserved[3];
} ZLNET_ENCODE_WIDGET, *LPZLNET_ENCODE_WIDGET;

// ͨ������Ƶ����
typedef struct 
{
	// ��Ƶ����
	BYTE				byVideoEnable;			// ��Ƶʹ�ܣ�1���򿪣�0���ر�
	BYTE				byBitRateControl;		// �������ƣ����ճ���"��������"����
	BYTE				byFramesPerSec;			// ֡��
	BYTE				byEncodeMode;			// ����ģʽ�����ճ���"����ģʽ"����
	BYTE				byImageSize;			// �ֱ��ʣ����ճ���"�ֱ���"����
	BYTE				byImageQlty;			// ����1-6
	WORD				wLimitStream;			// ����������
	// ��Ƶ����
	BYTE				byAudioEnable;			// ��Ƶʹ�ܣ�1���򿪣�0���ر�
	BYTE				wFormatTag;				// ��Ƶ��������
	WORD				nChannels;				// ������
	WORD				wBitsPerSample;			// �������	
	BYTE				bAudioOverlay;			// ��Ƶ����ʹ��
	BYTE				bReserved_2;
	DWORD				nSamplesPerSec;			// ������
	BYTE				bIFrameInterval;		// I֡���֡��������������I֮֡���P֡������0-149
	BYTE				bScanMode;				// NSP
	BYTE				bReserved_3;
	BYTE				bReserved_4;
} ZLNET_VIDEOENC_OPT, *LPZLNET_VIDEOENC_OPT;

// ������ɫ����
typedef struct 
{
	ZLNET_TSECT			stSect;
	BYTE				byBrightness;			// ���ȣ�0-100
	BYTE				byContrast;				// �Աȶȣ�0-100
	BYTE				bySaturation;			// ���Ͷȣ�0-100
	BYTE				byHue;					// ɫ�ȣ�0-100
	BYTE				byGainEn;				// ����ʹ��
	BYTE				byGain;					// ���棻0-100
	BYTE				byWhitebalance;			/*!<�Զ��׵�ƽ���ƣ�bit7��λ��ʾ�����Զ�����.0x0,0x1,0x2�ֱ�����,��,�ߵȼ�*/
	BYTE				byReserved[1];
} ZLNET_COLOR_CFG, *LPZLNET_COLOR_CFG;

// ͼ��ͨ�����Խṹ��
typedef struct 
{
	//DWORD				dwSize;
	WORD				dwSize;
	BYTE				bNoise;
	BYTE				byMicAutoSwitch;/* MIC��������Ƶ MIC:0  ������Ƶ��1 */
	char				szChannelName[ZLNET_CHAN_NAME_LEN];
	ZLNET_VIDEOENC_OPT		stMainVideoEncOpt[ZLNET_REC_TYPE_NUM];
	ZLNET_VIDEOENC_OPT		stAssiVideoEncOpt[ZLNET_N_ENCODE_AUX];		
	ZLNET_COLOR_CFG		stColorCfg[ZLNET_N_COL_TSECT];
	ZLNET_ENCODE_WIDGET	stTimeOSD;
	ZLNET_ENCODE_WIDGET	stChannelOSD;
	ZLNET_ENCODE_WIDGET	stBlindCover[ZLNET_N_COVERS];	// �������ڵ�
	BYTE				byBlindEnable;			// �����ڸǿ��أ�0x00����ʹ���ڸǣ�0x01�����ڸ��豸����Ԥ����0x10�����ڸ�¼������Ԥ����0x11�����ڸ�
	BYTE				byBlindMask;			// �����ڸ����룻��һλ���豸����Ԥ�����ڶ�λ��¼��(������Ԥ��) */
	BYTE				bVolume;				// ������ֵ(0~100�ɵ�)
	BYTE				bVolumeEnable;			// ������ֵʹ��
} ZLNET_DEV_CHANNEL_CFG, *LPZLNET_DEV_CHANNEL_CFG;

// Ԥ��ͼ�����
typedef struct 
{
	DWORD				dwSize;
	ZLNET_VIDEOENC_OPT		stPreView;
	ZLNET_COLOR_CFG		stColorCfg[ZLNET_N_COL_TSECT];
}ZLNET_DEV_PREVIEW_CFG;

//-------------------------------��������---------------------------------

// ���ڻ�������
typedef struct
{
	BYTE				byDataBit;				// ����λ��0��5��1��6��2��7��3��8
	BYTE				byStopBit;				// ֹͣλ��0��1λ��1��1.5λ��2��2λ
	BYTE				byParity;				// У��λ��0����У�飬1����У�飻2��żУ��
	BYTE				byBaudRate;				// �����ʣ�0��300��1��600��2��1200��3��2400��4��4800��
												// 5��9600��6��19200��7��38400��8��57600��9��115200
} ZLNET_COMM_PROP;

// 485����������
typedef struct
{ 
	ZLNET_COMM_PROP		struComm;
	BYTE				wProtocol;				// Э�����ͣ���Ӧ"Э�����б�"�±�
	BYTE				bPTZType;				// 0-���ݣ�������̨ 1-Զ��������̨,ͨ��������ѯ(��DEV_ENCODER_CFG)��
	BYTE				wDecoderAddress;		// ��������ַ��0 - 255
	BYTE 				byMartixID;				// �����
} ZLNET_485_CFG;

//485ģ�����
typedef struct
{
	BOOL bSimulationCtrl;						//ģ����� 0-�ر� 1-��
	int nSimulationSpeed;						//ģ������ 1~30s
	int nRes[4];
} ZLNET_485_SIMULATION_CTRL;

//485ģ���������
typedef struct
{
	int nSize;														//�ṹ���С
	int nValidNum;													//��Ч����
	ZLNET_485_SIMULATION_CTRL simulationCtrl[ZLNET_MAX_CHANNUM];	//��ͨ��ģ�����
} ZLNET_485_SIMULATION_CTRL_CFG;

// 232��������
typedef struct
{
	ZLNET_COMM_PROP		struComm;
	BYTE				byFunction;				// ���ڹ��ܣ���Ӧ"�������б�"�±�
	BYTE				byReserved[3];
} ZLNET_RS232_CFG;

// �������ýṹ��
typedef struct
{
	DWORD				dwSize;

	DWORD				dwDecProListNum;				// ������Э�����
	char				DecProName[ZLNET_MAX_DECPRO_LIST_SIZE][ZLNET_MAX_NAME_LEN]; // Э�����б�
	ZLNET_485_CFG			stDecoder[ZLNET_MAX_DECODER_NUM];	// ����������ǰ����

	DWORD				dw232FuncNameNum;		// 232���ܸ���
	char				s232FuncName[ZLNET_MAX_232FUNCS][ZLNET_MAX_NAME_LEN];	// �������б�
	ZLNET_RS232_CFG		st232[ZLNET_MAX_232_NUM];	// ��232���ڵ�ǰ����
} ZLNET_DEV_COMM_CFG;

// ����״̬
typedef struct
{
	unsigned int		uBeOpened;
	unsigned int		uBaudRate;
	unsigned int		uDataBites;
	unsigned int		uStopBits;
	unsigned int		uParity;
	BYTE				bReserved[32];
} ZLNET_COMM_STATE;

//��������
typedef struct _ZLNET_COM_TYPE
{
	int nSize;				//�ṹ���С
	int nComType;			//�������� 0:232 1:485
	int Res[4];
}ZLNET_COM_TYPE;

//-------------------------------¼������---------------------------------

// ��ʱ¼��
typedef struct 
{
	DWORD				dwSize;
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];
	BYTE				byPreRecordLen;			// Ԥ¼ʱ�䣬��λ��s��0��ʾ��Ԥ¼
	BYTE				byRedundancyEn;			// ¼�����࿪��
	BYTE                byRecordType;           // ¼���������ͣ�0-������ 1-������1 2-������2 3-������3
	BYTE				byReserved;
} ZLNET_DEV_RECORD_CFG, *LPZLNET_DEV_RECORD_CFG;

// NTP����
typedef struct  
{
	BOOL				bEnable;				//	�Ƿ�����
	int					nHostPort;				//	NTP������Ĭ�϶˿�Ϊ123
	char				szHostIp[32];			//	����IP
	char				szDomainName[128];		//	����
	int					nType;					//	�������ã�0����ʾIP��1����ʾ������2����ʾIP������
	int					nUpdateInterval;		//	����ʱ��(����)
	int					nTimeZone;				//	��ZLNET_TIME_ZONE_TYPE
	char				reserved[128];
} ZLNET_NTP_DEV_CFG;

// FTP�ϴ�����
typedef struct
{
	struct
	{
		ZLNET_TSECT		struSect;				// ��ʱ����ڵġ�ʹ�ܡ���Ч���ɺ���
		BOOL			bMdEn;					// �ϴ���̬���¼��
		BOOL			bAlarmEn;				// �ϴ��ⲿ����¼��
		BOOL			bTimerEn;				// �ϴ���ͨ��ʱ¼��
		DWORD			dwRev[4];
	} struPeriod[ZLNET_TIME_SECTION];
} ZLNET_FTP_UPLOAD_CFG;

typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;							// �Ƿ�����
	char				szHostIp[ZLNET_MAX_IPADDR_LEN];		// ����IP
	WORD				wHostPort;							// �����˿�
	char				szDirName[ZLNET_FTP_MAX_PATH];			// FTPĿ¼·��
	char				szUserName[ZLNET_FTP_USERNAME_LEN];	// �û���
	char				szPassword[ZLNET_FTP_PASSWORD_LEN];	// ����
	int					iFileLen;							// �ļ�����
	int					iInterval;							// �����ļ�ʱ����
	ZLNET_FTP_UPLOAD_CFG	struUploadCfg[ZLNET_MAX_CHANNUM][ZLNET_N_WEEKS];
	char 				protocol;							// 0-FTP 1-SMB
	char				NASVer;								// ����洢�������汾0=�ϵ�FTP(��������ʾʱ���)��1=NAS�洢(����������ʱ���)
	DWORD				dwFunctionMask;						// �����������룬��λ��ʾ����16λ(����洢)���α�ʾFTP��SMB��NFS����16λ(���ش洢)����ΪDISK��U
	BOOL				bAnonymous;							// �Ƿ�������¼
	BYTE 				reserved[120];
} ZLNET_FTP_PROTO_CFG;

typedef struct
{
	ZLNET_FTP_PROTO_CFG struFtpCfg[2]; //0: ¼��FTP 1:ͼƬFTP
}ZLNET_FTP_PROTO_CFG_EX;



//-------------------------------��������---------------------------------

// ��̫������
typedef struct 
{
	char				sDevIPAddr[ZLNET_MAX_IPADDR_LEN];	// DVR IP ��ַ
	char				sDevIPMask[ZLNET_MAX_IPADDR_LEN];	// DVR IP ��ַ����
	char				sGatewayIP[ZLNET_MAX_IPADDR_LEN];	// ���ص�ַ

	/*
	 * 1��10Mbps ȫ˫��
	 * 2��10Mbps ����Ӧ
	 * 3��10Mbps ��˫��
	 * 4��100Mbps ȫ˫��
	 * 5��100Mbps ����Ӧ
	 * 6��100Mbps ��˫��
	 * 7������Ӧ
	 */
	// Ϊ����չ��DWORD����ĸ�
	BYTE				dwNetInterface;			// NSP
	BYTE				bTranMedia;				// 0�����ߣ�1������
	BYTE				bValid;					// ��λ��ʾ����һλ��1����Ч 0����Ч���ڶ�λ��0��DHCP�ر� 1��DHCPʹ�ܣ�����λ��0����֧��DHCP 1��֧��DHCP
	BYTE				bDefaultEth;			// �Ƿ���ΪĬ�ϵ����� 1��Ĭ�� 0����Ĭ��
	char				byMACAddr[ZLNET_MACADDR_LEN];	// MAC��ַ��ֻ��
} ZLNET_ETHERNET; 

// Զ����������
typedef struct 
{
	BYTE				byEnable;				// ����ʹ��
	BYTE				byAssistant;            // Ŀǰֻ����PPPoE���������ã�0���������������ţ�1�������������ϲ���
	WORD				wHostPort;				// Զ������ �˿�
	char				sHostIPAddr[ZLNET_MAX_IPADDR_LEN];		// Զ������ IP ��ַ		
	char				sHostUser[ZLNET_MAX_HOST_NAMELEN];		// Զ������ �û���
	char				sHostPassword[ZLNET_MAX_HOST_PSWLEN];	// Զ������ ����
} ZLNET_REMOTE_HOST;

// �ʼ�����
typedef struct 
{
	char				sMailIPAddr[ZLNET_MAX_IPADDR_LEN];	// �ʼ�������IP��ַ
	WORD				wMailPort;				// �ʼ��������˿�
	WORD				wReserved;				// ����
	char				sSenderAddr[ZLNET_MAX_MAIL_ADDR_LEN];	// ���͵�ַ
	char				sUserName[ZLNET_MAX_NAME_LEN];			// �û���
	char				sUserPsw[ZLNET_MAX_NAME_LEN];			// �û�����
	char				sDestAddr[ZLNET_MAX_MAIL_ADDR_LEN];	// Ŀ�ĵ�ַ
	char				sCcAddr[ZLNET_MAX_MAIL_ADDR_LEN];		// ���͵�ַ
	char				sBccAddr[ZLNET_MAX_MAIL_ADDR_LEN];		// ������ַ
	char				sSubject[ZLNET_MAX_MAIL_SUBJECT_LEN];	// ����
} ZLNET_MAIL_CFG;

// �������ýṹ��
typedef struct
{ 
	DWORD				dwSize; 

	char				sDevName[ZLNET_MAX_NAME_LEN];	// �豸������

	WORD				wTcpMaxConnectNum;		// TCP���������
	WORD				wTcpPort;				// TCP֡���˿�
	WORD				wUdpPort;				// UDP�����˿�
	WORD				wHttpPort;				// HTTP�˿ں�
	WORD				wHttpsPort;				// HTTPS�˿ں�
	WORD				wSslPort;				// SSL�˿ں�
	ZLNET_ETHERNET			stEtherNet[ZLNET_MAX_ETHERNET_NUM];	// ��̫����

	ZLNET_REMOTE_HOST		struAlarmHost;			// ����������
	ZLNET_REMOTE_HOST		struLogHost;			// ��־������
	ZLNET_REMOTE_HOST		struSmtpHost;			// SMTP������
	ZLNET_REMOTE_HOST		struMultiCast;			// �ಥ��
	ZLNET_REMOTE_HOST		struNfs;				// NFS������
	ZLNET_REMOTE_HOST		struPppoe;				// PPPoE������
	char				sPppoeIP[ZLNET_MAX_IPADDR_LEN]; // PPPoEע�᷵�ص�IP
	ZLNET_REMOTE_HOST		struDdns;				// DDNS������
	char				sDdnsHostName[ZLNET_MAX_HOST_NAMELEN];	// DDNS������
	ZLNET_REMOTE_HOST		struDns;				// DNS������
	ZLNET_MAIL_CFG			struMail;				// �ʼ�����
} ZLNET_DEV_NET_CFG;

// �������ýṹ�塪����չ
typedef struct
{ 
	ZLNET_DEV_NET_CFG pDevNetCfg;

	//�����ܿ�
	int MaxNetMonitor;  //�����ء�0��ʾ��ֹ������0x7FFFFFFF��ʾ������
	int MaxDownload;  //¼������
} ZLNET_DEV_NET_CFG_EX;

// �������ýṹ�塪����չ2
typedef struct
{ 
	ZLNET_DEV_NET_CFG pDevNetCfg;

	//�����ܿ�
	int MaxNetMonitor;  //�����ء�0��ʾ��ֹ������0x7FFFFFFF��ʾ������
	int MaxDownload;	//¼������
	BOOL bUpnpEnable;	//upnpʹ��
	int nRtspPort;		//RTSP�˿�
	int Res[15];		//����
} ZLNET_DEV_NET_CFG_NEW_EX;

//RTSP����
typedef struct
{
	int nSize;														//�ṹ���С
	int nValidNum;													//��Ч����
	char chRstpUrl[ZLNET_RTSP_URL_MAX_NUM][ZLNET_MAX_URL_LEN];	//RTSP URL
	int nRes[16];													//����
} ZLNET_DEV_RTSP_CONFIG;

// ��ddns���ýṹ��
typedef struct
{
	DWORD				dwId;					// ddns������id��
	BOOL				bEnable;				// ʹ�ܣ�ͬһʱ��ֻ����һ��ddns����������ʹ��״̬
	char				szServerType[ZLNET_MAX_SERVER_TYPE_LEN];	// ���������ͣ�ϣ��..
	char				szServerIp[ZLNET_MAX_DOMAIN_NAME_LEN];		// ������ip��������
	DWORD				dwServerPort;			// �������˿�
	char				szDomainName[ZLNET_MAX_DOMAIN_NAME_LEN];	// dvr��������jeckean.3322.org
	char				szUserName[ZLNET_MAX_HOST_NAMELEN];		// �û���
	char				szUserPsw[ZLNET_MAX_HOST_PSWLEN];			// ����
	char				szAlias[ZLNET_MAX_DDNS_ALIAS_LEN];			// ��������������"ZL inter ddns"
	DWORD				dwAlivePeriod;							// DDNS ����ʱ��
	char				reserved[256];
} ZLNET_DDNS_SERVER_CFG;

typedef struct
{
	DWORD				dwSize;
	DWORD				dwDdnsServerNum;	
	ZLNET_DDNS_SERVER_CFG	struDdnsServer[ZLNET_MAX_DDNS_NUM];	
} ZLNET_DEV_MULTI_DDNS_CFG;

// �ʼ����ýṹ��
typedef struct 
{
	char				sMailIPAddr[ZLNET_MAX_DOMAIN_NAME_LEN];	// �ʼ���������ַ(IP��������)
	char				sSubMailIPAddr[ZLNET_MAX_DOMAIN_NAME_LEN];
	WORD				wMailPort;								// �ʼ��������˿�
	WORD				wSubMailPort;
	WORD				wReserved;								// ����
	char				sSenderAddr[ZLNET_MAX_MAIL_ADDR_LEN];	// ���͵�ַ
	char				sUserName[ZLNET_MAX_MAIL_NAME_LEN];		// �û���
	char				sUserPsw[ZLNET_MAX_MAIL_NAME_LEN];		// �û�����
	char				sDestAddr[ZLNET_MAX_MAIL_ADDR_LEN];		// Ŀ�ĵ�ַ
	char				sCcAddr[ZLNET_MAX_MAIL_ADDR_LEN];		// ���͵�ַ
	char				sBccAddr[ZLNET_MAX_MAIL_ADDR_LEN];		// ������ַ
	char				sSubject[ZLNET_MAX_MAIL_SUBJECT_LEN];	// ����
	BYTE				bEnable;								// ʹ��0:false,	1:true
	BYTE				bSSLEnable;								// SSLʹ��
	WORD				wSendInterval;							// ����ʱ����,[0,3600]��
	BYTE				bAnonymous;								// ����ѡ��[0,1], 0��ʾFALSE,1��ʾTRUE.
	BYTE				bAttachEnable;							// ����ʹ��[0,1], 0��ʾFALSE,1��ʾTRUE.
	char				reserved[154];
} ZLNET_MAIL_DEV_CFG;

// DNS����������
typedef struct  
{
	char				szPrimaryIp[ZLNET_MAX_IPADDR_LEN];
	char				szSecondaryIp[ZLNET_MAX_IPADDR_LEN];
	char				reserved[256];
} ZLNET_DNS_DEV_CFG;

// ¼�����ز�������
typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;				// TRUE���������أ�FALSE����ͨ����
}ZLNET_DEV_DOWNLOAD_STRATEGY_CFG;

// ���紫���������
typedef struct
{
	DWORD				dwSize;
	BOOL				bEnable;
	int					iStrategy;				// 0���������ȣ�1�����������ȣ�2���Զ�
}ZLNET_DEV_TRANSFER_STRATEGY_CFG;

// ���õ���ʱ����ز���
typedef struct  
{
	int					nWaittime;				// �ȴ���ʱʱ��(����Ϊ��λ)��Ϊ0Ĭ��5000ms
	int					nConnectTime;			// ���ӳ�ʱʱ��(����Ϊ��λ)��Ϊ0Ĭ��1500ms
	int					nConnectTryNum;			// ���ӳ��Դ�����Ϊ0Ĭ��1��
	int					nSubConnectSpaceTime;	// ������֮��ĵȴ�ʱ��(����Ϊ��λ)��Ϊ0Ĭ��10ms
	int					nGetDevInfoTime;		// ��ȡ�豸��Ϣ��ʱʱ�䣬Ϊ0Ĭ��1000ms
	int					nConnectBufSize;		// ÿ�����ӽ������ݻ����С(�ֽ�Ϊ��λ)��Ϊ0Ĭ��250*1024
	int					nGetConnInfoTime;		// ��ȡ��������Ϣ��ʱʱ��(����Ϊ��λ)��Ϊ0Ĭ��1000ms
	BYTE				bReserved[20];			// �����ֶ�
} ZLNET_PARAM;

// �������ͣ���ӦZLNET_SearchDevices�ӿ�
typedef enum __ZLNET_SEARCH_MODE
{
	ZL_MODE = 0,	//����ģʽ �˿�6060(Ĭ��)
	DH_MODE,		//��ģʽ �˿�5050
}ZLNET_SEARCH_MODE;

// ��ӦZLNET_SearchDevices�ӿ�
typedef struct 
{
	char				szIP[ZLNET_MAX_IPADDR_LEN];			// IP
	int					nPort;								// �˿�
	int					nChn;								// ͨ������
	char				szSubmask[ZLNET_MAX_IPADDR_LEN];	// ��������
	char				szGateway[ZLNET_MAX_IPADDR_LEN];	// ����
	char				szMac[ZLNET_MACADDR_LEN];			// MAC��ַ
	char				szDeviceType[16];					// �豸����
	char				szSerial[32];						// ���к�
	BYTE				bRegist;							// �Ƿ���ע����Ϣ
	BYTE				bIPCP;								// �Ƿ�IPCP�豸
	char				reverse[10];						// Ԥ��
} ZLNET_DEVICE_NET_INFO;

//-------------------------------��������---------------------------------

// ��̨����
typedef struct 
{
	int					iType;
	int					iValue;
} ZLNET_PTZ_LINK, *LPZLNET_PTZ_LINK;

// ���������ṹ��
typedef struct 
{
	/* ��Ϣ����ʽ������ͬʱ���ִ���ʽ������
	 * 0x00000001 - �����ϴ�
	 * 0x00000002 - ����¼��
	 * 0x00000004 - ��̨����
	 * 0x00000008 - �����ʼ�
	 * 0x00000010 - ������Ѳ
	 * 0x00000020 - ������ʾ
	 * 0x00000040 - �������
	 * 0x00000080 - Ftp�ϴ�
	 * 0x00000100 - ����
	 * 0x00000200 - ������ʾ
	 * 0x00000400 - ץͼ
	*/

	/* ��ǰ������֧�ֵĴ���ʽ����λ�����ʾ */
	DWORD				dwActionMask;

	/* ������������λ�����ʾ�����嶯������Ҫ�Ĳ����ڸ��Ե����������� */
	DWORD				dwActionFlag;
	
	/* �������������ͨ�������������������Ϊ1��ʾ��������� */ 
	BYTE				byRelAlarmOut[ZLNET_MAX_ALARMOUT_NUM];
	DWORD				dwDuration;				/* ��������ʱ�� */

	/* ����¼�� */
	BYTE				byRecordChannel[ZLNET_MAX_VIDEO_IN_NUM]; /* ����������¼��ͨ����Ϊ1��ʾ������ͨ�� */
	DWORD				dwRecLatch;				/* ¼�����ʱ�� */

	/* ץͼͨ�� */
	BYTE				bySnap[ZLNET_MAX_VIDEO_IN_NUM];
	/* ��Ѳͨ�� */
	BYTE				byTour[ZLNET_MAX_VIDEO_IN_NUM];

	/* ��̨���� */
	ZLNET_PTZ_LINK			struPtzLink[ZLNET_MAX_VIDEO_IN_NUM];
	DWORD				dwEventLatch;			/* ������ʼ��ʱʱ�䣬sΪ��λ����Χ��0~15��Ĭ��ֵ��0 */
	/* �����������������ͨ�������������������Ϊ1��ʾ��������� */ 
	BYTE				byRelWIAlarmOut[ZLNET_MAX_ALARMOUT_NUM];
	BYTE				bMessageToNet;
	BYTE                bMMSEn;                /*���ű���ʹ��*/
	BYTE                bySnapshotTimes;       /*���ŷ���ץͼ���� */
	BYTE				bMatrixEn;				/*!< ����ʹ�� */
	DWORD				dwMatrix;				/*!< �������� */			
	BYTE				bLog;					/*!< ��־ʹ�ܣ�Ŀǰֻ����WTN��̬�����ʹ�� */
	BYTE				Res[3];
	DWORD				dwBeepLatch;			//������ʱ
	BYTE				byReserved[94];   
} ZLNET_MSG_HANDLE;

// �ⲿ����
typedef struct
{
	BYTE				byAlarmType;			// ���������ͣ�0�����գ�1������
	BYTE				byAlarmEn;				// ����ʹ��
	BYTE				byReserved[2];						
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE		struHandle;				// ����ʽ
} ZLNET_ALARMIN_CFG, *LPZLNET_ALARMIN_CFG; 

// ��̬��ⱨ��
typedef struct 
{
	BYTE				byMotionEn;				// ��̬��ⱨ��ʹ��
	BYTE				byReserved;
	WORD				wSenseLevel;			// ������
	WORD				wMotionRow;				// ��̬������������
	WORD				wMotionCol;				// ��̬������������
	BYTE				byDetected[ZLNET_MOTION_ROW][ZLNET_MOTION_COL]; // ����������32*32������
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	//NSP
	ZLNET_MSG_HANDLE		struHandle;				//����ʽ
} ZLNET_MOTION_DETECT_CFG;

// ��Ƶ��ʧ����
typedef struct
{
	BYTE				byAlarmEn;				// ��Ƶ��ʧ����ʹ��
	BYTE				byReserved[3];
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	//NSP
	ZLNET_MSG_HANDLE		struHandle;				// ����ʽ
} ZLNET_VIDEO_LOST_CFG;

// ͼ���ڵ�����
typedef struct
{
	BYTE				byBlindEnable;			// ʹ��
	BYTE				byBlindLevel;			// ������1-6
	BYTE				byReserved[2];
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	//NSP
	ZLNET_MSG_HANDLE		struHandle;				// ����ʽ
} ZLNET_BLIND_CFG;

// Ӳ����Ϣ(�ڲ�����)
typedef struct 
{
	BYTE				byNoDiskEn;				// ��Ӳ��ʱ����
	BYTE				byReserved_1[3];
	ZLNET_TSECT			stNDSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE		struNDHandle;			// ����ʽ

	BYTE				byLowCapEn;				// Ӳ�̵�����ʱ����
	BYTE				byLowerLimit;			// ������ֵ��0-99
	BYTE				byReserved_2[2];
	ZLNET_TSECT			stLCSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE		struLCHandle;			// ����ʽ

	BYTE				byDiskErrEn;			// Ӳ�̹��ϱ���
	BYTE				bDiskNum;
	BYTE				byReserved_3[2];
	ZLNET_TSECT			stEDSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE		struEDHandle;			// ����ʽ
} ZLNET_DISK_ALARM_CFG;

typedef struct
{
	BYTE				byEnable;
	BYTE				byReserved[3];
	ZLNET_MSG_HANDLE		struHandle;
} ZLNET_NETBROKEN_ALARM_CFG;

// ��������
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

// ��������������
typedef struct  
{
	DWORD				dwAddr;									// ������������ַ
	BOOL				bEnable;								// ����������ʹ��
	DWORD				dwOutSlots[ZLNET_DECODER_OUT_SLOTS_MAX_NUM];	// ����ֻ֧��8��.
	int					nOutSlotNum;							// dwOutSlots������ЧԪ�ظ���.
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];
	ZLNET_MSG_HANDLE		struHandle[ZLNET_DECODER_IN_SLOTS_MAX_NUM];	// ����ֻ֧��8��.
	int					nMsgHandleNum;							// stuHandle������ЧԪ�ظ���.
	BYTE				bReserved[120];
} ZLNET_ALARMDEC_CFG;

// �����ϴ�������
typedef struct  
{
	BYTE				byEnable;				// �ϴ�ʹ��
	BYTE				bReserverd;				// ����
	WORD				wHostPort;				// �������������˿�
	char				sHostIPAddr[ZLNET_MAX_IPADDR_LEN];		// ��������IP

	int					nByTimeEn;				// ��ʱ�ϴ�ʹ�ܣ����������������ϴ�IP��������
	int					nUploadDay;				/* �����ϴ�����	
													"Never = 0", "Everyday = 1", "Sunday = 2", 
													"Monday = 3", Tuesday = 4", "Wednesday = 5",
													"Thursday = 6", "Friday = 7", "Saturday = 8"*/	
	int					nUploadHour;			// �����ϴ�ʱ�� ,[0~23]��
	
	DWORD				dwReserved[300]; 		// ��������չ��
} ZLNET_ALARMCENTER_UP_CFG;

// ȫ���л���������
typedef struct __ZLNET_PANORAMA_SWITCH_CFG 
{
	BOOL				bEnable;				// ʹ��
	int					nReserved[5];			// ����
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];
	ZLNET_MSG_HANDLE		struHandle;				// ��������
} ZLNET_PANORAMA_SWITCH_CFG;

typedef struct __ZLNET_ALARM_PANORAMA_SWITCH_CFG 
{
	int					nAlarmChnNum;			// ����ͨ������
	ZLNET_PANORAMA_SWITCH_CFG stuPanoramaSwitch[ZLNET_MAX_VIDEO_IN_NUM];
} ZLNET_ALARM_PANORAMA_SWITCH_CFG;

// ʧȥ���㱨������
typedef struct __ZLNET_LOST_FOCUS_CFG
{
	BOOL				bEnable;				// ʹ��
	int					nReserved[5];			// ����
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];
	ZLNET_MSG_HANDLE		struHandle;				// ��������
} ZLNET_LOST_FOCUS_CFG;

typedef struct __ZLNET_ALARM_LOST_FOCUS_CFG 
{
	int					nAlarmChnNum;			// ����ͨ������
	ZLNET_LOST_FOCUS_CFG stuLostFocus[ZLNET_MAX_VIDEO_IN_NUM];
} ZLNET_ALARM_LOST_FOCUS_CFG;

// IP��ͻ��ⱨ������
typedef struct __ZLNET_ALARM_IP_COLLISION_CFG
{
	BOOL				bEnable;				// ʹ��
	ZLNET_MSG_HANDLE		struHandle;				// ��������
	int                 nReserved[300];			// ����
} ZLNET_ALARM_IP_COLLISION_CFG;

//------------------------------�������ڵ�--------------------------------

// �ڵ���Ϣ
typedef struct __ZLNET_VIDEO_COVER_ATTR
{
	ZLNET_RECT				rcBlock;				// ���ǵ���������
	int					nColor;					// ���ǵ���ɫ
	BYTE				bBlockType;				// ���Ƿ�ʽ��0���ڿ飬1��������
	BYTE				bEncode;				// ���뼶�ڵ���1����Ч��0������Ч
	BYTE				bPriview;				// Ԥ���ڵ��� 1����Ч��0������Ч
	char				reserved[29];			// ����
} ZLNET_VIDEO_COVER_ATTR;

// �������ڵ�����
typedef struct __ZLNET_DEV_VIDEOCOVER_CFG 
{
	DWORD				dwSize;
	char				szChannelName[ZLNET_CHAN_NAME_LEN]; // ֻ��
	BYTE				bTotalBlocks;			// ֧�ֵ��ڵ�����
	BYTE				bCoverCount;			// �����õ��ڵ�����
	ZLNET_VIDEO_COVER_ATTR	CoverBlock[ZLNET_MAX_VIDEO_COVER_NUM]; // ���ǵ�����	
	char				reserved[30];			// ����
}ZLNET_DEV_VIDEOCOVER_CFG;

////////////////////////////////IPC��Ʒ֧��////////////////////////////////

// ��������������Ϣ
typedef struct 
{
	int					nEnable;				// ����ʹ��
	char				szSSID[36];				// SSID
	int					nLinkMode;				// ����ģʽ��0��auto��1��adhoc��2��Infrastructure
	int					nEncryption;			// ���ܣ�0��off��2��WEP64bit��3��WEP128bit, 4:WPA-PSK-TKIP, 5: WPA-PSK-CCMP
	int					nKeyType;				// 0��Hex��1��ASCII
    int					nKeyID;					// ���
	union
	{
		char			szKeys[4][32];			// ��������
		char			szWPAKeys[128];			// nEncryptionΪ4��5ʱʹ�ã���128���ȣ����ý�������
	};
	int					nKeyFlag;
	char				reserved[12];
} ZLNET_DEV_WLAN_INFO;

// ѡ��ʹ��ĳ�������豸
typedef struct  
{
	char				szSSID[36];
	int					nLinkMode;				// ����ģʽ��0��adhoc��1��Infrastructure
	int 				nEncryption;			// ���ܣ�0��off��2��WEP64bit��3��WEP128bit
	char				reserved[48];
} ZLNET_DEV_WLAN_DEVICE;

// �������������豸�б�
typedef struct  
{
	DWORD				dwSize;
	BYTE				bWlanDevCount;			// �������������豸����
	ZLNET_DEV_WLAN_DEVICE	lstWlanDev[ZLNET_MAX_WLANDEVICE_NUM];
	char				reserved[255];
} ZLNET_DEV_WLAN_DEVICE_LIST;

// ����ע���������
typedef struct  
{
	char				szServerIp[32];			// ע�������IP
	int					nServerPort;			// �˿ں�
	char				reserved[64];
} ZLNET_DEV_SERVER_INFO;

typedef struct  
{
	DWORD				dwSize;
	BYTE				bServerNum;				// ֧�ֵ����ip��
	ZLNET_DEV_SERVER_INFO	lstServer[ZLNET_MAX_REGISTER_SERVER_NUM];
	BYTE				bEnable;				// ʹ��
	char				szDeviceID[32];			// �豸id
	char				reserved[94];
} ZLNET_DEV_REGISTER_SERVER;

// ����ͷ����
typedef struct __ZLNET_DEV_CAMERA_INFO
{
	BYTE				bBrightnessEn;			// ���ȿɵ���1���ɣ�0������
	BYTE				bContrastEn;			// �Աȶȿɵ�
	BYTE				bColorEn;				// ɫ�ȿɵ�
	BYTE				bGainEn;				// ����ɵ�
	BYTE				bSaturationEn;			// ���Ͷȿɵ�
	BYTE				bBacklightEn;			// ���ⲹ�� 0��ʾ��֧�ֱ��ⲹ��,1��ʾ֧��һ����������,�أ���2��ʾ֧��������������,��,�ͣ���3��ʾ֧��������������,��,��,�ͣ�
	BYTE				bExposureEn;			// �ع�ѡ��:
												// 0:��ʾ��֧���ع����
												// 1:��ʾֻ֧���Զ��ع�
												// n:�ع�ĵȼ���(1��ʾ֧���Զ��ع� 2~n��ʾ֧�ֵ��ֶ������ع�ĵȼ�)
	BYTE				bColorConvEn;			// �Զ��ʺ�ת���ɵ�
	BYTE				bAttrEn;				// ����ѡ�1���ɣ�0������
	BYTE				bMirrorEn;				// ����1��֧�֣�0����֧��
    BYTE				bFlipEn;				// ��ת��1��֧�֣�0����֧��
	BYTE				iWhiteBalance;			// ��ƽ�� 2 ֧���龰ģʽ�� 1 ֧�ְ�ƽ�� ��0 ��֧��
	BYTE				iSignalFormatMask;		// �źŸ�ʽ���룬��λ�ӵ͵���λ�ֱ�Ϊ��0-Inside(�ڲ�����) 1- BT656 2-720p 3-1080i  4-1080p  5-1080sF
	BYTE				bRotate90;				//	90����ת 0-��֧�� 1-֧��
    BYTE				bLimitedAutoExposure;   // �Ƿ�֧�ִ�ʱ�������޵��Զ��ع�
    BYTE				bCustomManualExposure;  // �Ƿ�֧���û��Զ����ֶ��ع�ʱ��
	BYTE				bRev[120];				// ����
} ZLNET_DEV_CAMERA_INFO;

// ����ͷ��������
typedef struct __ZLNET_DEV_CAMERA_CFG 
{
	DWORD				dwSize;
	BYTE				bExposure;				// �ع�ģʽ��ȡֵ��Χȡ�����豸��������0-�Զ��ع⣬1-�ع�ȼ�1��2-�ع�ȼ�2��n-1����ع�ȼ��� n��ʱ�������޵��Զ��ع� n+1�Զ���ʱ���ֶ��ع� (n==bExposureEn��
	BYTE				bBacklight;				// ���ⲹ�������ⲹ���ȼ�ȡֵ��Χȡ�����豸��������0-�رգ�1-���ⲹ��ǿ��1��2-���ⲹ��ǿ��2��n-��󱳹ⲹ���ȼ��� 
	BYTE				bAutoColor2BW;			// ��/ҹģʽ��2����(�ڰ�)��1���Զ���0����(��ɫ)
	BYTE				bMirror;				// ����1������0����
	BYTE				bFlip;					// ��ת��1������0����
	BYTE				bLensEn;				// �Զ���Ȧ��������: 1��֧�֣�0 ����֧��
	BYTE				bLensFunction;			// �Զ���Ȧ����: 1:�����Զ���Ȧ��0: �ر��Զ���Ȧ
	BYTE				bWhiteBalance;			// ��ƽ�� 0:Disabled,1:Auto 2:sunny 3:cloudy 4:home 5:office 6:night
	BYTE				bSignalFormat;			// �źŸ�ʽ0-Inside(�ڲ�����) 1- BT656 2-720p 3-1080i  4-1080p  5-1080sF
	BYTE				bRotate90;				// 0-����ת��1-˳ʱ��90�㣬2-��ʱ��90��
	BYTE                reserved[2];            // ����
	float				ExposureValue1;			// �Զ��ع�ʱ�����޻����ֶ��ع��Զ���ʱ��,����Ϊ��λ��ȡֵ0.1ms~80ms
	float				ExposureValue2;			// �Զ��ع�ʱ������,����Ϊ��λ��ȡֵ0.1ms~80ms
	
	char				bRev[108];				// ����
} ZLNET_CAMERA_CFG;

#define ALARM_MAX_NAME 64
// (����)���ⱨ������
typedef struct
{
	BOOL				bEnable;				// ��������ʹ��
	char				szAlarmName[ZLNET_MAX_ALARM_NAME];	// ������������
	int					nAlarmInPattern;		// ���������벨��
	int					nAlarmOutPattern;		// �����������
	char				szAlarmInAddress[ZLNET_MAX_ALARM_NAME];// ���������ַ
	int					nSensorType;			// �ⲿ�豸���������ͳ��� or ����
	int					nDefendEfectTime;		// ��������ʱʱ�䣬�ڴ�ʱ���ñ���������Ч
	int					nDefendAreaType;		// �������� 
	int					nAlarmSmoothTime;		// ����ƽ��ʱ�䣬���ڴ�ʱ�������ֻ��һ��������������������������Ե�����һ��
	char				reserved[128];
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];
	ZLNET_MSG_HANDLE		struHandle;				// ����ʽ
} ZLNET_INFRARED_INFO;

// ����ң��������
typedef struct 
{
	BYTE				address[ALARM_MAX_NAME];// ң������ַ
	BYTE				name[ALARM_MAX_NAME];	// ң��������
	BYTE				reserved[32];			// �����ֶ�
} ZLNET_WI_CONFIG_ROBOT;

// ���߱����������
typedef struct 
{
	BYTE				address[ALARM_MAX_NAME];// ���������ַ
	BYTE				name[ALARM_MAX_NAME];	// �����������
	BYTE				reserved[32];			// �����ֶ�
} ZLNET_WI_CONFIG_ALARM_OUT;

typedef struct  
{
	DWORD				dwSize;
	BYTE				bAlarmInNum;			// ���߱���������
	BYTE				bAlarmOutNum;			// ���߱��������
	ZLNET_WI_CONFIG_ALARM_OUT AlarmOutAddr[16];	// ���������ַ
	BYTE				bRobotNum;				// ң��������
	ZLNET_WI_CONFIG_ROBOT RobotAddr[16];			// ң������ַ
	ZLNET_INFRARED_INFO	InfraredAlarm[16];
	char				reserved[256];
} ZLNET_INFRARED_CFG;

// ����Ƶ��ⱨ����Ϣ
typedef struct
{
	int					channel;				// ����ͨ����
	int					alarmType;				// �������ͣ�0����Ƶֵ���ͣ�1����Ƶֵ����
	unsigned int		volume;					// ����ֵ
	char				reserved[256];
} ZLNET_NEW_SOUND_ALARM_STATE;

typedef struct  
{
	int					channelcount;			// ������ͨ������
	ZLNET_NEW_SOUND_ALARM_STATE SoundAlarmInfo[ZLNET_MAX_ALARM_IN_NUM];
} ZLNET_DEV_NEW_SOUND_ALARM_STATE;

// ץͼ�������Խṹ��
typedef struct 
{
	int					nChannelNum;			// ͨ����
	DWORD				dwVideoStandardMask;	// �ֱ���(��λ)������鿴ö��CAPTURE_SIZE						
	int					nFramesCount;			// Frequence[128]�������Ч����
	char				Frames[128];			// ֡��(����ֵ)
												// -25��25��1֡��-24��24��1֡��-23��23��1֡��-22��22��1֡
												// ����
												// 0����Ч��1��1��1֡��2��1��2֡��3��1��3֡
												// 4��1��4֡��5��1��5֡��17��1��17֡��18��1��18֡
												// 19��1��19֡��20��1��20֡
												// ����
												// 25: 1��25֡
	int					nSnapModeCount;			// SnapMode[16]�������Ч����
	char				SnapMode[16];			// (����ֵ)0����ʱ����ץͼ��1���ֶ�����ץͼ
	int					nPicFormatCount;		// Format[16]�������Ч����
	char 				PictureFormat[16];		// (����ֵ)0��BMP��ʽ��1��JPG��ʽ
	int					nPicQualityCount;		// Quality[32]�������Ч����
	char 				PictureQuality[32];		// ����ֵ
												// 100��ͼ������100%��80:ͼ������80%��60:ͼ������60%
												// 50:ͼ������50%��30:ͼ������30%��10:ͼ������10%
	char 				nReserved[128];			// ����
} ZLNET_QUERY_SNAP_INFO;

typedef struct 
{
	int					nChannelCount;			// ͨ������
	ZLNET_QUERY_SNAP_INFO  stuSnap[ZLNET_MAX_CHANNUM];
} ZLNET_SNAP_ATTR_EN;


/* IP���˹������� */
#define ZLNET_IPIFILTER_NUM			200			// IP

// IP��Ϣ
typedef struct 
{
	DWORD				dwIPNum;				// IP����
	char				SZIP[ZLNET_IPIFILTER_NUM][ZLNET_MAX_IPADDR_LEN]; // IP
	char				byReserve[32];			// ����
} ZLNET_IPIFILTER_INFO;

// IP�������ýṹ��
typedef struct
{
	DWORD				dwSize;
	DWORD				dwEnable;				// ʹ��
	DWORD				dwType;					// ��ǰ�������ͣ�0�������� 1�����������豸ֻ��ʹһ��������Ч�������ǰ����������Ǻ�������
	ZLNET_IPIFILTER_INFO		BannedIP;				// ������
	ZLNET_IPIFILTER_INFO		TrustIP;				// ������
	char				byReserve[256];			// ����
} ZLNET_DEV_IPIFILTER_CFG;

/*�����Խ���������*/
typedef struct
{
	DWORD				dwSize;
	int					nCompression;			// ѹ����ʽ��ö��ֵ�����ZLNET_TALK_CODING_TYPE��������豸֧�ֵ������Խ���������ѹ����ʽ��
	int					nMode;					// ����ģʽ��ö��ֵ��Ϊ0ʱ��ʾ��ѹ����ʽ��֧�ֱ���ģʽ��
												// ����ѹ����ʽ�������ö�Ӧ�ı����ʽ����
												// AMR���EM_ARM_ENCODE_MODE
	char				byReserve[256];			// ����
} ZLNET_DEC_TALK_ENCODE_CFG;

// ������mobile�������
// (�¼�������ý�����/���ŷ���)MMS���ýṹ��
typedef struct
{
	DWORD				dwSize;
	DWORD				dwEnable;				// ʹ��
	DWORD				dwReceiverNum;			// ���Ž����߸���
	char				SZReceiver[ZLNET_MMS_RECEIVER_NUM][32];	// ���Ž����ߣ�һ��Ϊ�ֻ�����
    BYTE                byType;					// ������Ϣ���� 0:MMS��1:SMS
	char                SZTitle[32];			// ������Ϣ����
	char				byReserve[223];			// ����
} ZLNET_DEC_MMS_CFG;

// (���ż���������������)
typedef struct  
{
	DWORD				dwSize;
	DWORD				dwEnable;				// ʹ��
	DWORD				dwSenderNum;			// ���ŷ����߸���
	char				SZSender[ZLNET_MMS_SMSACTIVATION_NUM][32];	// ���ŷ����ߣ�һ��Ϊ�ֻ�����
 	char				byReserve[256];			// ����
}ZLNET_DEC_SMSACTIVATION_CFG;

// (���ż���������������)
typedef struct  
{
	DWORD				dwSize;
	DWORD				dwEnable;				// ʹ��
	DWORD				dwCallerNum;			// �����߸���
	char				SZCaller[ZLNET_MMS_DIALINACTIVATION_NUM][32];	// ������, һ��Ϊ�ֻ�����
 	char				byReserve[256];			// ����
}ZLNET_DEC_DIALINACTIVATION_CFG;
// ������mobile�������


// ���������ź�ǿ�Ƚṹ��
typedef struct
{
	DWORD				dwSize;
	DWORD				dwTDSCDMA;				// TD-SCDMAǿ�ȣ���Χ��0��100
	DWORD				dwWCDMA;				// WCDMAǿ�ȣ���Χ��0��100
	DWORD				dwCDMA1x;				// CDMA1xǿ�ȣ���Χ��0��100
	DWORD				dwEDGE;					// EDGEǿ�ȣ���Χ��0��100
	DWORD				dwEVDO;					// EVDOǿ�ȣ���Χ��0��100
	int					nCurrentType;			// ��ǰ����
												// 0	�豸��֧����һ��
												// 1    TD_SCDMA
												// 2	WCDMA
												// 3	CDMA_1x
												// 4	EDGE
												// 5	EVDO
	char				byReserve[252];			// ����
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
	BYTE	bReserved[64];						//����
}ZLNET_DEV_SIP_STATE;

/***************************** ��̨Ԥ�Ƶ����� ***********************************/
typedef struct _ZLNET_POINTEANBLE
{
	BYTE				bPoint;	//Ԥ�Ƶ����Ч��Χ������[1,80]����Ч����Ϊ0��
	BYTE				bEnable;	//�Ƿ���Ч,0��Ч��1��Ч
	BYTE				bReserved[2];
} ZLNET_POINTEANBLE;

typedef struct _ZL_POINTCFG
{
	char				szIP[ZLNET_MAX_IPADDR_LEN];// ip
	int					nPort;					// �˿�	
	ZLNET_POINTEANBLE			stuPointEnable[80];		// Ԥ�Ƶ�ʹ��
	BYTE				bReserved[256];
}ZLNET_POINTCFG;

typedef struct _ZLNET_DEC_POINT_CFG
{
	int					nSupportNum;			// ֻ�����������õ�ʱ����Ҫ���ظ�sdk����ʾ֧�ֵ�Ԥ�Ƶ���
	ZLNET_POINTCFG			stuPointCfg[16];		// ��ά�±��ʾͨ���š�Ҫ���õĵ���ֵ����ǰnSupportNum���±����档
	BYTE				bReserved[256];			// ����
}ZLNET_DEC_POINT_CFG;
////////////////////////////////����DVR֧��////////////////////////////////

// GPS��Ϣ(�����豸)
typedef struct _ZLNET_GPS_Info
{
    ZLNET_TIME			revTime;				// ��λʱ��
	char				DvrSerial[50];			// �豸���к�
    double				longitude;				// ����(��λ�ǰ����֮�ȣ���Χ0-360��)
    double				latidude;				// γ��(��λ�ǰ����֮�ȣ���Χ0-180��)
    double				height;					// �߶�(��)
    double				angle;					// �����(��������Ϊԭ�㣬˳ʱ��Ϊ��)
    double				speed;					// �ٶ�(��λ�Ǻ��speed/1000*1.852����/Сʱ)
    WORD				starCount;				// ��λ����
    BOOL				antennaState;			// ����״̬(true �ã�false ��)
    BOOL				orientationState;		// ��λ״̬(true ��λ��false ����λ)
} ZLNET_GPS_Info,*LPZLNET_GPS_Info;

// ץͼ�����ṹ��
typedef struct _ZLNET_snap_param
{
	unsigned int		Channel;				// ץͼ��ͨ��
	unsigned int		Quality;				// ���ʣ�1~6
	unsigned int		ImageSize;				// �����С��0��QCIF��1��CIF��2��D1
	unsigned int		mode;					// ץͼģʽ��0����ʾ����һ֡��1����ʾ��ʱ��������2����ʾ��������
	unsigned int		InterSnap;				// ʱ�䵥λ�룻��mode=1��ʾ��ʱ��������ʱ����ʱ����Ч
	unsigned int		CmdSerial;				// �������к�
	unsigned int		Reserved[4];
} ZLNET_SNAP_PARAMS, *LPZLNET_SNAP_PARAMS;

// ץͼ��������
typedef struct 
{
	DWORD				dwSize;
	BYTE				bTimingEnable;				// ��ʱץͼ����(����ץͼ�����ڸ�������������������)
	BYTE                bReserved;
	short	            PicTimeInterval;			// ��ʱץͼʱ��������λΪ��,Ŀǰ�豸֧������ץͼʱ����Ϊ30����                           
	ZLNET_VIDEOENC_OPT		struSnapEnc[ZLNET_SNAP_TYP_NUM]; // ץͼ�������ã���֧�����еķֱ��ʡ����ʡ�֡�����ã�֡���������Ǹ�������ʾһ��ץͼ�Ĵ�����
} ZLNET_SNAP_DEV_CFG;

//////////////////////////////////ATM֧��//////////////////////////////////

typedef struct
{
	int					Offset;					// ��־λ��λƫ��
	int					Length;					// ��־λ�ĳ���
	char				Key[16];				// ��־λ��ֵ
} ZLNET_SNIFFER_FRAMEID;

typedef struct 
{
	int					Offset;					// ��־λ��λƫ��
	int					Offset2;				// Ŀǰû��Ӧ��
	int					Length;					// ��־λ�ĳ���
	int					Length2;				// Ŀǰû��Ӧ��
	char				KeyTitle[24];			// �����ֵ
} ZLNET_SNIFFER_CONTENT;

// ����ץ������
typedef struct 
{
	ZLNET_SNIFFER_FRAMEID	snifferFrameId;			// ÿ��FRAME ID ѡ��
	ZLNET_SNIFFER_CONTENT	snifferContent[ZLNET_SNIFFER_CONTENT_NUM];	// ÿ��FRAME��Ӧ��4��ץ������
} ZLNET_SNIFFER_FRAME;

// ÿ��ץ����Ӧ�����ýṹ
typedef struct
{
	char				SnifferSrcIP[ZLNET_MAX_IPADDR_LEN];	// ץ��Դ��ַ		
	int					SnifferSrcPort;			// ץ��Դ�˿�
	char				SnifferDestIP[ZLNET_MAX_IPADDR_LEN];	// ץ��Ŀ���ַ
	int					SnifferDestPort;		// ץ��Ŀ��˿�
	char				reserved[28];			// �����ֶ�
	ZLNET_SNIFFER_FRAME	snifferFrame[ZLNET_SNIFFER_FRAMEID_NUM];	// 6��FRAME ѡ��
	int					displayPosition;		// ��ʾλ��
	int					recdChannelMask;		// ͨ������
} ZLNET_ATM_SNIFFER_CFG;

typedef struct  
{
	DWORD				dwSize;
	ZLNET_ATM_SNIFFER_CFG	SnifferConfig[4];
	char				reserved[256];			// �����ֶ�
} ZLNET_SNIFFER_CFG;

typedef ZLNET_SNIFFER_FRAMEID ZLNET_SNIFFER_FRAMEID_EX;
typedef ZLNET_SNIFFER_CONTENT ZLNET_SNIFFER_CONTENT_EX;

// ����ץ������
typedef struct  
{
	ZLNET_SNIFFER_FRAMEID	snifferFrameId;								// ÿ��FRAME ID ѡ��
	ZLNET_SNIFFER_CONTENT	snifferContent[ZLNET_SNIFFER_CONTENT_NUM_EX];	// ÿ��FRAME��Ӧ��8��ץ������	
} ZLNET_SNIFFER_FRAME_EX;

// ÿ��ץ����Ӧ�����ýṹ
typedef struct
{
	char				SnifferSrcIP[ZLNET_MAX_IPADDR_LEN];					// ץ��Դ��ַ		
	int					SnifferSrcPort;										// ץ��Դ�˿�
	char				SnifferDestIP[ZLNET_MAX_IPADDR_LEN];					// ץ��Ŀ���ַ
	int					SnifferDestPort;									// ץ��Ŀ��˿�
	ZLNET_SNIFFER_FRAME_EX	snifferFrame[ZLNET_SNIFFER_FRAMEID_NUM];				// 6��FRAME ѡ��
	int					displayPosition;									// ��ʾλ��
	int					recdChannelMask;									// ͨ������
	BOOL				bDateScopeEnable;									// ������Դʹ��
	BOOL				bProtocolEnable;									// Э��ʹ��
	char				szProtocolName[ZLNET_SNIFFER_PROTOCOL_SIZE];			// Э������
	int					nSnifferMode;										// ץ����ʽ��0:net,1:232.
	char				reserved[256];
} ZLNET_ATM_SNIFFER_CFG_EX;

// Atm�������Ͳ�ѯ���ؽṹ��
#define ZLNET_ATM_MAX_TRADE_TYPE_NAME	64
#define ZLNET_ATM_MAX_TRADE_NUM		1024

typedef struct __ZLNET_ATM_QUERY_TRADE   
{
	int					nTradeTypeNum;										// ʵ�ʽ�����������
	int					nExceptionTypeNum;									// ʵ���쳣�¼�����
	char				szSupportTradeType[ZLNET_ATM_MAX_TRADE_NUM][ZLNET_ATM_MAX_TRADE_TYPE_NAME];    // �����¼�������
	char				szSupportExceptionType[ZLNET_ATM_MAX_TRADE_NUM][ZLNET_ATM_MAX_TRADE_TYPE_NAME];// �쳣�¼�������
} ZLNET_ATM_QUERY_TRADE, *LPZLNET_ATM_QUERY_TRADE;

/////////////////////////////////������֧��/////////////////////////////////

// ��������Ϣ
typedef struct __ZLNET_DEV_DECODER_INFO 
{
	char			szDecType[64];			// ����
	int				nMonitorNum;			// TV����
	int				nEncoderNum;			// ����ͨ������
	BYTE			szSplitMode[16];		// ֧�ֵ�TV����ָ�������������ʽ��ʾ��0Ϊ��β
	BYTE            bMonitorEnable[16];		// ��TVʹ��
	char			reserved[64];
} ZLNET_DEV_DECODER_INFO, *LPZLNET_DEV_DECODER_INFO;

// ���ӵı�������Ϣ
typedef struct __ZLNET_DEV_ENCODER_INFO 
{
	char			szDevIp[ZLNET_MAX_IPADDR_LEN];			// ǰ��DVR��IP��ַ
	WORD			wDevPort;							// ǰ��DVR�Ķ˿ں�
	BYTE			bDevChnEnable;                      // ����ͨ��ʹ��
	BYTE			byEncoderID;						// ��Ӧ����ͨ����
	char			szDevUser[ZLNET_USER_NAME_LENGTH_EX];	// �û���
	char			szDevPwd[ZLNET_USER_PSW_LENGTH_EX];	// ����
	int				nDevChannel;						// ͨ����
	int				nStreamType;						// �������ͣ�0����������1��������; 2:snap
	BYTE			byConnType;							// 0��TCP��1��UDP��2���鲥
	BYTE			byWorkMode;							// 0��ֱ����1��ת��
	WORD			wListenPort;						// ָʾ��������Ķ˿ڣ�ת��ʱ��Ч
	DWORD			dwProtoType;						// Э������,
														// 0:������ǰ
														// 1:��ŵ����Э��
														// 2:��ŵϵͳ����Э��
														// 3:��ŵDSSЭ��
														// 4:��ŵrtspЭ��
	char			szDevName[64];						// ǰ���豸����
	BYTE            byVideoInType;                      // �ý���ͨ����ǰ��ƵԴ����:0-����(SD),1-����(HD),ע:�豸֧�ָ���ͨ������Ч		
	char			szDevIpEx[ZLNET_MAX_IPADDR_OR_DOMAIN_LEN];// szDevIp��չ��ǰ��DVR��IP��ַ(������������)
	BYTE            bySnapMode;                         //ץͼģʽ(nStreamType==2ʱ��Ч) 0����ʾ����һ֡,1����ʾ��ʱ��������
	BYTE            byManuFactory;						//Ŀ���豸����������,0:Private(��ŵ˽��)
	BYTE            byDeviceType;                       //Ŀ���豸���豸����,0:IPC
	char			reserved[48];
} ZLNET_DEV_ENCODER_INFO, *LPZLNET_DEV_ENCODER_INFO;

// TV������Ϣ
typedef struct __ZLNET_DEV_DECODER_TV 
{
	int				nID;								// TV��
	BOOL			bEnable;							// ʹ�ܣ�������ر�
	int				nSplitType;							// ����ָ���
	ZLNET_DEV_ENCODER_INFO stuDevInfo[16];					// �������������Ϣ
	char			reserved[16];
} ZLNET_DEV_DECODER_TV, *LPZLNET_DEV_DECODER_TV;

// ���������������Ϣ
typedef struct __ZLNET_DEC_COMBIN_INFO
{
	int				nCombinID;							// ���ID
	int             nSplitType;							// ����ָ��� 
	BYTE            bDisChn[16];						// ��ʾͨ��
	char			reserved[16];
} ZLNET_DEC_COMBIN_INFO, *LPZLNET_DEC_COMBIN_INFO;

// ��������Ѳ��Ϣ
#define ZLNET_DEC_COMBIN_NUM 			32						// ��Ѳ��ϸ���
typedef struct __ZLNET_DEC_TOUR_COMBIN 
{
	int				nTourTime;							// ��Ѳ���(��)
	int				nCombinNum;							// ��ϸ���
	BYTE			bCombinID[ZLNET_DEC_COMBIN_NUM];			// ��ϱ�
	char			reserved1[32];
	BYTE			bCombinState[ZLNET_DEC_COMBIN_NUM];		// ������ʹ��״̬��0���أ�1����
	char			reserved2[32];
} ZLNET_DEC_TOUR_COMBIN, *LPZLNET_DEC_TOUR_COMBIN;

// �������ط�����
typedef enum __ZLNET_DEC_PLAYBACK_MODE
{
	ZL_Dec_By_Device_File = 0,								// ǰ���豸�����ļ���ʽ
	ZL_Dec_By_Device_Time,									// ǰ���豸����ʱ�䷽ʽ
} ZLNET_DEC_PLAYBACK_MODE;

// �������طſ�������
typedef enum __ZLNET_DEC_CTRL_PLAYBACK_TYPE
{
	ZL_Dec_Playback_Seek = 0,								// �϶�
	ZL_Dec_Playback_Play,									// ����
	ZL_Dec_Playback_Pause,									// ��ͣ
	ZL_Dec_Playback_Stop,									// ֹͣ
} ZLNET_DEC_CTRL_PLAYBACK_TYPE;

//��Ѳ��������
typedef enum __ZLNET_DEC_CTRL_TOUR_TYPE
{
	ZL_Dec_Tour_Stop = 0,									// ֹͣ
	ZL_Dec_Tour_Start,										// ��ʼ
	ZL_Dec_Tour_Pause,										// ��ͣ
	ZL_Dec_Tour_Resume,									// �ָ�
} ZLNET_DEC_CTRL_TOUR_TYPE;

// ���ļ��ط�ǰ���豸����
typedef struct __ZLNET_DEC_PLAYBACK_FILE_PARAM 
{
	char			szDevIp[ZLNET_MAX_IPADDR_LEN];			// ǰ��DVR��IP��ַ
	WORD			wDevPort;							// ǰ��DVR�Ķ˿ں�
	BYTE			bDevChnEnable;                      // ����ͨ��ʹ��
	BYTE			byEncoderID;						// ��Ӧ����ͨ����
	char			szDevUser[ZLNET_USER_NAME_LENGTH_EX];	// �û���
	char			szDevPwd[ZLNET_USER_PSW_LENGTH_EX];	// ����
	ZLNET_RECORDFILE_INFO stuRecordInfo;					// ¼���ļ���Ϣ
	char			reserved[12];
} ZLNET_DEC_PLAYBACK_FILE_PARAM, *LPZLNET_DEC_PLAYBACK_FILE_PARAM;

// ��ʱ��ط�ǰ���豸����
typedef struct __ZLNET_DEC_PLAYBACK_TIME_PARAM 
{
	char			szDevIp[ZLNET_MAX_IPADDR_LEN];			// ǰ��DVR��IP��ַ
	WORD			wDevPort;							// ǰ��DVR�Ķ˿ں�
	BYTE			bDevChnEnable;                      // ����ͨ��ʹ��
	BYTE			byEncoderID;						// ��Ӧ����ͨ����
	char			szDevUser[ZLNET_USER_NAME_LENGTH_EX];	// �û���
	char			szDevPwd[ZLNET_USER_PSW_LENGTH_EX];	// ����
	int				nChannelID;
	ZLNET_TIME		startTime;
	ZLNET_TIME		endTime;
	char			reserved[12];
} ZLNET_DEC_PLAYBACK_TIME_PARAM, *LPZLNET_DEC_PLAYBACK_TIME_PARAM;

// ��ǰ����ͨ��״̬��Ϣ(����ͨ��״̬����������Ϣ��)
typedef struct __ZLNET_DEV_DECCHANNEL_STATE
{
	BYTE			byEncoderID;						// ��Ӧ����ͨ����
	BYTE            byChnState;                         // ��ǰ����ͨ�����ڲ���״̬:0�����У�1��ʵʱ���ӣ�2���ط� 3 - ��Ѳ
	BYTE			byFrame;                            // ��ǰ����֡��
	BYTE            byReserved;                         // ����
	int				nChannelFLux;						// ����ͨ����������
	int             nDecodeFlux;						// ����������
	char            szResolution[16];                   // ��ǰ���ݷֱ���
	char			reserved[256];
} ZLNET_DEV_DECCHANNEL_STATE, *LPZLNET_DEV_DECCHANNEL_STATE;

// �豸TV���������Ϣ
typedef struct __ZL_DEV_VIDEOOUT_INFO
{
	DWORD				dwVideoStandardMask;			// NSP,��Ƶ��ʽ���룬��λ��ʾ�豸�ܹ�֧�ֵ���Ƶ��ʽ(�ݲ�֧��)
	int					nVideoStandard;                 // NSP,��ǰ����ʽ(�ݲ�֧�֣���ʹ��DHDEV_SYSTEM_ATTR_CFG��byVideoStandard����ʽ��ȡ������)
	DWORD				dwImageSizeMask;				// �ֱ������룬��λ��ʾ�豸�ܹ�֧�ֵķֱ���
	int                 nImageSize;                     // ��ǰ�ķֱ���
	char				reserved[256];
}ZLNET_DEV_VIDEOOUT_INFO, *LPZLNET_DEV_VIDEOOUT_INFO;

// ����TV���
typedef struct __ZLNET_DEV_TVADJUST_CFG
{
	int					nTop;							// �ϲ�߾ࣨ0��100��
	int					nBotton;						// �²�߾ࣨ0��100��
	int					nLeft;							// ���߾ࣨ0��100��
	int                 nRight;							// �Ҳ�߾ࣨ0��100��
	int					reserved[32];
}ZLNET_DEV_TVADJUST_CFG, *LPZLNET_DEV_TVADJUST_CFG;

// ������Ѳ����
typedef struct __ZLNET_DEV_DECODER_TOUR_SINGLE_CFG
{
	char		szIP[128];								// ǰ���豸ip.����"10.7.5.21". ������������֧��.��Ҫ��'\0'����.
	int			nPort;									// ǰ���豸�˿�.(0, 65535).
	int			nPlayChn;								// ����ǰ���豸ͨ��[1, 16].
	int			nPlayType;								// ����ǰ����������, 0:������; 1:������.
	char		szUserName[32];							// ��½ǰ���豸���û���,��Ҫ��'\0'����.
	char		szPassword[32];							// ��½ǰ���豸������,��Ҫ��'\0'����.
	int			nInterval;								// ��Ѳ���ʱ��[10, 120],��λ��.
	BYTE		bReserved[64];							// �����ֽ�,������չ.
}ZLNET_DEV_DECODER_TOUR_SINGLE_CFG;

typedef struct __ZLNET_DECODER_TOUR_CFG_DEV
{
	int								nCfgNum;			// ���ýṹ����Ŀ. �������֧��32��.����֧����Ŀ����ͨ��������ѯ.
	ZLNET_DEV_DECODER_TOUR_SINGLE_CFG	tourCfg[64];		// ��ѯ��������,��Ч�ṹ������ɳ�Ա"nCfgNum"ָ��. ����32��������չ.
	BYTE							bReserved[256];		// �����ֽ�,������չ.
}ZLNET_DECODER_TOUR_CFG_DEV;
/////////////////////////////////����汾/////////////////////////////////

// �����豸ץͼ�����ӿ�����Ϣ
typedef struct __ZLNET_SNAP_COMMANDINFO 
{
	char				szCardInfo[16];			// ������Ϣ
	char				reserved[64];			// ����
} ZLNET_SNAP_COMMANDINFO, LPZLNET_SNAP_COMMANDINFO;

typedef struct
{
	int					nChannelNum;			// ͨ����
	char				szUseType[32];			// ͨ����;
	DWORD				dwStreamSize;			// ������С(��λ��kb/s)
	char				reserved[32];			// ����
} ZLNET_DEV_USE_CHANNEL_STATE;

typedef struct 
{
	char				szUserName[32];			// �û���
	char				szUserGroup[32];		// �û���
	ZLNET_TIME			time;					// ����ʱ��
	int					nOpenedChannelNum;		// ������ͨ������
	ZLNET_DEV_USE_CHANNEL_STATE	channelInfo[ZLNET_MAX_CHANNUM];
	char				reserved[64];
} ZLNET_DEV_USER_NET_INFO;

// ��������״̬��Ϣ
typedef	struct 
{
	int					nUserCount;				// �û�����
	ZLNET_DEV_USER_NET_INFO	stuUserInfo[32];
	char				reserved[256];
}ZLNET_DEV_TOTAL_NET_STATE;

// ͼ��ˮӡ����
typedef struct __ZLNET_WATERMAKE_CFG_DEV 
{
	DWORD				dwSize;
	int					nEnable;				// ʹ��
	int					nStream;				// ����(1��n)0-��������
	int					nKey;					// ��������(1-���֣�2-ͼƬ)
	char				szLetterData[ZLNET_MAX_WATERMAKE_LETTER];	//	����
	char				szData[ZLNET_MAX_WATERMAKE_DATA]; // ͼƬ����
	BYTE				bReserved[512];			// ����
} ZLNET_WATERMAKE_CFG_DEV;

// �洢λ�����ýṹ�壬ÿͨ����������,ÿͨ������ѡ����ִ洢����, Ŀǰ��������, ���ƶ�, Զ�̴洢.
typedef struct 
{
	DWORD				dwSize;
	DWORD				dwLocalMask;			// ���ش洢���룻��λ��ʾ��
												// ��һλ��ϵͳԤ¼���ڶ�λ����ʱ¼�񣬵���λ������¼��
												// ����λ������¼�񣬵���λ������¼�񣬵���λ���ֶ�¼��
	DWORD				dwMobileMask;			// ���ƶ��洢���� �洢�����籾�ش洢����
	int					RemoteType;				// Զ�̴洢���� 0: Ftp  1: Smb 
	DWORD				dwRemoteMask;			// Զ�̴洢���� �洢�����籾�ش洢����
	DWORD				dwRemoteSecondSelLocal;	// Զ���쳣ʱ���ش洢����
	DWORD				dwRemoteSecondSelMobile;// Զ���쳣ʱ���ƶ��洢����
	char				SubRemotePath[ZLNET_MAX_PATH_STOR]; // Զ��Ŀ¼, ���г���Ϊ240
	DWORD				dwFunctionMask;			//��������λ����λ��ʾ��bit0 = 1:����ץͼ�¼������洢λ�ù���
	
	char				reserved[124];
} ZLNET_STORAGE_STATION_CFG;

#define ZLNET_MAX_ALARM_DECODER_NUM 16
typedef struct  
{
	DWORD				dwAlarmDecoder;			// �������֧��8����������ڣ���8λ���Ժ���չ
	BYTE				bDecoderIndex;			// ��ʾ�ڼ�������������
	BYTE				bReserved[3];
} ZLNET_ALARM_DECODER;

// ��������������
typedef struct
{
	int					nAlarmDecoderNum;
	ZLNET_ALARM_DECODER		stuAlarmDecoder[ZLNET_MAX_ALARM_DECODER_NUM];
	BYTE				bReserved[32];
} ZLNET_ALARM_DECODER_ALARM_DEV;

//DSP����
typedef struct  
{
	BOOL				bError;			//0,DSP���� 1,DSP�쳣
	DWORD				dwErrorMask;	//��λ��ʾ����0��ʾ�д˴���0��ʾû�С�(Ŀǰÿ�α���ֻ��һλ��Ч)
										//bit		DSP����
										//1			DSP����ʧ�� 
										//2			DSP����
										//3			��ʽ���� 
										//4			�ֱ��ʲ�֧��
										//5			���ݸ�ʽ��֧��
										//6			�Ҳ���I֡
	DWORD               dwDecChnnelMask;//��λ��ʾ�������Ľ���ͨ���ţ�dwErrorMaskΪDSP������ʽ���ԣ��ֱ��ʲ�֧�֣����ݸ�ʽ��֧��ʱ������Ч
	
	BYTE				bReserved[28];
}ZLNET_DSP_ALARM;

// ���˱�����������
typedef struct  
{
	int		nFDDINum;
	BYTE	bAlarm[256];
} ZLNET_ALARM_FDDI_ALARM;

// ����Ƶ��ⱨ������
typedef struct
{
	BOOL				bEnable;				// ��������ʹ��
	int					Volume_min;				// ��������Сֵ
	int					Volume_max;				// ���������ֵ
	char				reserved[128];	
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	
	ZLNET_MSG_HANDLE		struHandle;				// ����ʽ
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
	BOOL				bTourEnable;			// ��Ѳʹ��
	int					nTourPeriod;			// ��Ѳ�������λ��, 5-300 
	DWORD				dwChannelMask;			// ��Ѳ��ͨ����������ʽ��ʾ
	char				reserved[64];
}ZLNET_VIDEOGROUP_CFG;

// ����������Ʋ�������
typedef struct
{
	DWORD				dwSize;
	int					nMatrixNum;				// �������(ע���������޸�)
	ZLNET_VIDEOGROUP_CFG	struVideoGroup[ZLNET_MATRIX_MAXOUT];
	char				reserved[32];
} ZLNET_DEV_VIDEO_MATRIX_CFG;   

// WEB·������
typedef struct 
{
	DWORD				dwSize;
	BOOL				bSnapEnable;			// �Ƿ�ץͼ
	int					iSnapInterval;			// ץͼ����
	char				szHostIp[ZLNET_MAX_IPADDR_LEN]; // HTTP����IP
	WORD				wHostPort;
	int					iMsgInterval;			// ״̬��Ϣ���ͼ��
	char				szUrlState[ZLNET_MAX_URL_LEN];	// ״̬��Ϣ�ϴ�URL
	char				szUrlImage[ZLNET_MAX_URL_LEN];	// ͼƬ�ϴ�Url
	char				szDevId[ZLNET_MAX_DEV_ID_LEN];	// ������web���
	BYTE				byReserved[2];
} ZLNET_DEV_URL_CFG;

// OEM��ѯ
typedef struct  
{
	char				szVendor[ZLNET_MAX_STRING_LEN];
	char				szType[ZLNET_MAX_STRING_LEN];
	char				reserved[128];
} ZLNET_DEV_OEM_INFO;


//��ƵOSD��������
typedef struct 
{ 
	DWORD	rgbaFrontground;		// �����ǰ�������ֽڱ�ʾ���ֱ�Ϊ�졢�̡�����͸����
	DWORD	rgbaBackground;			// ����ı��������ֽڱ�ʾ���ֱ�Ϊ�졢�̡�����͸����	
	RECT	rcRelativePos;			// λ��,����߾��������ı���*8191	
	BOOL	bPreviewBlend;			// Ԥ������ʹ��	
	BOOL	bEncodeBlend;			// �������ʹ��
	BYTE    bReserved[4];           // ����
} ZLNET_DVR_VIDEO_WIDGET;

typedef struct 
{
	ZLNET_DVR_VIDEO_WIDGET	StOSD_POS; 								// OSD���ӵ�λ�úͱ���ɫ
	char 				SzOSD_Name[ZLNET_VIDEO_OSD_NAME_NUM]; 		// OSD���ӵ�����
}ZLNET_DVR_VIDEOITEM;
 
// ÿ��ͨ����OSD��Ϣ
typedef struct 
{
	DWORD 				dwSize;
	ZLNET_DVR_VIDEOITEM 	StOSDTitleOpt [ZLNET_VIDEO_CUSTOM_OSD_NUM]; 	// ÿ��ͨ����OSD��Ϣ
	BYTE    			bReserved[16];                  		  // ����
} ZLNET_DVR_VIDEOOSD_CFG;

// ����CDMA/GPRS������Ϣ
// ʱ��νṹ															    
typedef struct 
{
	BYTE				bEnable;				  // ʱ���ʹ�ܣ�1��ʾ��ʱ�����Ч��0��ʾ��ʱ�����Ч��
	BYTE				bBeginHour;
	BYTE				bBeginMin;
	BYTE				bBeginSec;
	BYTE				bEndHour;
	BYTE				bEndMin;
	BYTE				bEndSec;
	BYTE    			bReserved;                //����
} ZLNET_3G_TIMESECT, *LPZLNET_3G_TIMESECT;

typedef struct 
{
	DWORD 				dwSize;
	BOOL				bEnable;					// ����ģ��ʹ�ܱ�־
	DWORD               dwTypeMask;                 // �豸֧��������������;��λ��ʾ,��һλ;�Զ�ѡ��;
													// �ڶ�λ��TD-SCDMA���磻����λ��WCDMA����;
													// ����λ��CDMA 1.x����;����λ��CDMA2000����;����λ��GPRS����;
													// ����λ��EVDO����;�ڰ�λ��WIFI
	DWORD               dwNetType;                  // ��ǰ�������������ͣ�ΪZLNET_GPRSCDMA_NETWORK_TYPEֵ
	char				szAPN[128];					// ���������
	char				szDialNum[128];				// ���ź���
	char				szUserName[128];			// �����û���
	char				szPWD[128];					// ��������
	
	/* �������豸��ֻ������ */
	BOOL				iAccessStat;				// ��������ע��״̬
    char				szDevIP[16];				// ǰ���豸����IP���ַ���, ����'\0'��������16byte  
	char				szSubNetMask [16];			// ǰ���豸�����������룬�ַ���, ����'\0'��������16byte 
	char				szGateWay[16];				// ǰ���豸�������أ��ַ���, ����'\0'��������16byte 
	/* �������豸��ֻ������ */
	int                 iKeepLive;					// ����ʱ��
	ZLNET_3G_TIMESECT		stSect[ZLNET_N_WEEKS][ZLNET_N_TSECT];// 3G����ʱ��Σ���Чʱ���֮�ڣ��������ţ���Чʱ���֮�⣬�رղ��š�
	BYTE                byActivate;                  //�Ƿ���Ҫ����������ż���
	char				Reserved[171];				// �����ֽڣ�������չ
} ZLNET_CDMAGPRS_CFG_DEV;

// ¼������������
typedef struct  
{
	DWORD 				dwSize;
	int					nType;						// 0:��ʱ�䣬1������С
	int					nValue;						// nType = 0ʱ:��λ���ӣ�nType = 1ʱ:��λKB
	char				Reserved[128];				// �����ֽڣ�������չ
} ZLNET_RECORD_PACKET_CFG_DEV;

// (����)����ע���������Ϣ
typedef struct __ZLNET_DEV_AUTOREGISTER_INFO 
{
	LONG			lConnectionID;						// ����ID
	char			szServerIp[ZLNET_MAX_IPADDR_LEN];		// ����ע���������IP
	int				nPort;								// ����ע��������˿�0- 65535
	int             nState;                             // ��������״̬��0��ע��ʧ�ܣ�1-ע��ɹ�; 2-����ʧ��
	char			reserved[16];
} ZLNET_DEV_AUTOREGISTER_INFO;

typedef struct __ZLNET_DEV_SERVER_AUTOREGISTER 
{
	DWORD					dwSize;
	int						nRegisterSeverCount;											// ����ע�����������
	ZLNET_DEV_AUTOREGISTER_INFO	stuDevRegisterSeverInfo[ZLNET_CONTROL_AUTO_REGISTER_NUM];			// ������ע���������Ϣ
	char					reserved[256];
} ZLNET_DEV_SERVER_AUTOREGISTER, *LPZLNET_DEV_SERVER_AUTOREGISTER;

// ������¼�����ϴ�
typedef struct
{
	DWORD				dwSize;		
	char				szSourFile[ZLNET_MAX_PATH_STOR];	// Դ�ļ�·��
	int					nFileSize;					// Դ�ļ���С�����С�ڵ���0��sdk���м����ļ���С.
	char				szBurnFile[ZLNET_MAX_PATH_STOR];	// ��¼����ļ���
	BYTE				bReserved[64];
} ZLNET_DEV_BURNFILE_TRANS_CFG;

// ֣������ķEC_U��Ƶ���ݵ���ʹ������
typedef struct 
{
	BOOL				bEnable;					// ʹ��
	int					nPort;						// �˿�
	BYTE				bReserved[64];
} ZLNET_OSD_ENABLE_CFG_DEV;

// �����������:��������ʹ������
typedef struct	
{
	BOOL				bAutoBootEnable;				//�Զ�����ʹ��
	DWORD				dwAutoBootTime;					//ÿ���Զ�����ʱ���, ��λ��,��0����.[0,82800]
	BOOL				bAutoShutDownEnable;			//�Զ��ػ�ʹ��
	DWORD				dwAutoShutDownTime;				//ÿ���Զ��ػ�ʱ���, ��λ��,��0����.[0,82800]
	DWORD				dwShutDownDelayTime;			//��ʱ�ػ�ʱ��,��λ��.
	BYTE				bEventNoDisk;					//1,(Ignore:����); 2,(Reboot:����ϵͳ)
	BYTE				bReserved[511];					//reserved byte.
} ZLNET_ABOUT_VEHICLE_CFG_DEV;

// atm:��ѯ�������������Ϣ
typedef struct  
{
	DWORD				dwDataSource;					//1:Net(����), 2:Com(����), 3:Net&Com(����ʹ���)
	char				szProtocol[32][33];				//Э������,��󳤶�32(����һ��������).
	BYTE				bReserved[256];
} ZLNET_DEV_ATM_OVERLAY_GENERAL;
 
// atm:���õ�������
typedef struct 
{
	DWORD				dwDataSource;					//1:Net(����), 2:Com(����)
	char				szProtocol[33];					//Э�����֣���DHDEV_ATM_OVERLAY_GENERAL����
	BYTE				bReserved_1[3];
	DWORD				dwChannelMask;					//���ӵ�ͨ���ţ������ʾ��
	BYTE				bMode;							//1:Preview(Ԥ������), 2:Encode(�������), 3:Preview&Encode(Ԥ���ͱ������)
	BYTE				bLocation;						//1:LeftTop(����), 2:LeftBottom(����), 3:RightTop(����), 4:RightBottom(����)
	BYTE				bReserved_2[258];
} ZLNET_DEV_ATM_OVERLAY_CONFIG;

#define ZLNET_MAX_BACKUPDEV_NUM			16
#define ZLNET_MAX_BACKUP_NAME				32

// �����豸�б�
typedef struct 
{
	int					nBackupDevNum;								// ʵ�ʵı����豸����
	char				szBackupDevNames[ZLNET_MAX_BACKUPDEV_NUM][ZLNET_MAX_BACKUP_NAME]; // �����豸������
} ZLNET_DEV_BACKUP_LIST, *LPZLNET_DEV_BACKUP_LIST;

// �����豸��������
typedef enum __ZLNET_BACKUP_TYPE
{
	ZLNET_BT_ZLFS = 0,							// ��ŵ�ļ�ϵͳ
	ZLNET_BT_DISK,								// �ƶ�Ӳ��
	ZLNET_BT_CDRW								// ���̿�¼
} ZLNET_DEV_BACKUP_TYPE;	

// �����豸�ӿ�����
typedef enum __ZLNET_BACKUP_BUS
{
	ZLNET_BB_USB = 0,								// usb�ӿ�
	ZLNET_BB_1394,								// 1394�ӿ�
	ZLNET_BB_IDE,									// ide�ӿ�
	ZLNET_BB_ESATA,								// esata�ӿ�
} ZLNET_DEV_BACKUP_BUS;	

typedef struct 
{
	char				szName[32];						// �豸�� 
	BYTE				byType;							// �����豸�Ľ������� ö��ֵ��BACKUP_TYPE
	BYTE				byBus;							// �����豸�Ľӿ����� ö��ֵ��BACKUP_BUS
	UINT				nCapability;					// ������, ��kBytesΪ��λ
	UINT				nRemain;						// ʣ������,��kBytesΪ��λ
	char				szDirectory[128];				// Զ�̱��ݵ�Ŀ¼
} ZLNET_DEV_BACKUP_INFO, *LPZLNET_DEV_BACKUP_INFO;

typedef struct 
{
	char				szName[32];						// �豸�� 
	UINT				nCapability;					// ������, ��kBytesΪ��λ
	UINT				nRemain;						// ��ǰ����ʣ������,��kBytesΪ��λ
} ZLNET_DEV_BACKUP_FEEDBACK, *LPZLNET_DEV_BACKUP_FEEDBACK;

#define  ZLNET_MAX_BACKUPRECORD_NUM 1024

typedef struct  
{
	char				szDeviceName[ZLNET_MAX_BACKUP_NAME];			//�����豸����
	int					nRecordNum;									//���ݼ�¼����
	ZLNET_RECORDFILE_INFO	stuRecordInfo[ZLNET_MAX_BACKUPRECORD_NUM];		//���ݼ�¼��Ϣ
} ZLNET_BACKUP_RECORD, *LPZLNET_BACKUP_RECORD;

/////////////////////////////////ƽ̨����/////////////////////////////////

// ƽ̨�������� �� U��ͨ
typedef struct
{
    BOOL				bChnEn;
    char				szChnId[ZLNET_INTERVIDEO_UCOM_CHANID];
} ZLNET_INTERVIDEO_UCOM_CHN_CFG;

typedef struct
{
	DWORD				dwSize;
	BOOL				bFuncEnable;			// ���빦��ʹ��
	BOOL				bAliveEnable;			// ����ʹ��
	DWORD				dwAlivePeriod;			// �������ڣ���λ�룬0-3600
	char				szServerIp[ZLNET_MAX_IPADDR_LEN]; // CMS��IP
	WORD				wServerPort;			// CMS��Port
    char				szRegPwd[ZLNET_INTERVIDEO_UCOM_REGPSW]; // ע������
	char				szDeviceId[ZLNET_INTERVIDEO_UCOM_DEVID];// �豸id
	char				szUserName[ZLNET_INTERVIDEO_UCOM_USERNAME];
	char				szPassWord[ZLNET_INTERVIDEO_UCOM_USERPSW];
    ZLNET_INTERVIDEO_UCOM_CHN_CFG  struChnInfo[ZLNET_MAX_CHANNUM]; // ͨ��id,en
} ZLNET_DEV_INTERVIDEO_UCOM_CFG;

// ƽ̨�������� �� ��������
typedef struct
{
	DWORD				dwSize;
    unsigned short		usCompanyID[2];			// ��˾ID����ֵ����ͬ�ĵ���������˾������4�ֽڶ��룬Ŀǰֻ�������һ��
    char				szDeviceNO[32];			// ǰ���豸���кţ��ַ���������'\0'��������32byte
    char				szVSName[32];			// ǰ���豸���ƣ��ַ���������'\0'��������16byte
    char				szVapPath[32];			// VAP·��
    unsigned short		usTcpPort;				// TCP�˿ڣ���ֵ����ֵ 1~65535 
    unsigned short		usUdpPort;				// UDP�˿ڣ���ֵ����ֵ 1~65535
    bool				bCsEnable[4];			// ���ķ�����ʹ�ܱ�־����ֵ��trueʹ�ܣ�false��ʹ�ܣ�����4�ֽڶ��룬Ŀǰֻ�������һ��
    char				szCsIP[16];				// ���ķ�����IP��ַ���ַ���������'\0'��������16byte
    unsigned short		usCsPort[2];			// ���ķ������˿ڣ���ֵ����ֵ 1~65535������4�ֽڶ��룬Ŀǰֻ�������һ��
    bool				bHsEnable[4];			// ����������ʹ�ܱ�־����ֵ��trueʹ�ܣ�false��ʹ�ܣ�����4�ֽڶ��룬Ŀǰֻ�������һ��
    char				szHsIP[16];				// ����������IP��ַ���ַ���������'\0'��������16byte
    unsigned short		usHsPort[2];			// �����������˿ڣ���ֵ����ֵ 1~65535������4�ֽڶ��룬Ŀǰֻ�������һ��
    int					iHsIntervalTime;		// ����������������ڣ���ֵ(��λ:��)
    bool				bRsEnable[4];			// ע�������ʹ�ܱ�־����ֵ��trueʹ�ܣ�false��ʹ�ܣ�����4�ֽڶ��룬Ŀǰֻ�������һ��
    char				szRsIP[16];				// ע�������IP��ַ���ַ���������'\0'��������16byte
    unsigned short		usRsPort[2];			// ע��������˿ڣ���ֵ����ֵ 1~65535������4�ֽڶ��룬Ŀǰֻ�������һ��
    int					iRsAgedTime;			// ע���������Чʱ�䣬��ֵ(��λ:Сʱ)
    char				szAuthorizeServerIp[16];// ��Ȩ������IP
    unsigned short		usAuthorizePort[2];		// ��Ȩ�������˿ڣ�����4�ֽڶ��룬Ŀǰֻ�������һ��
    char				szAuthorizeUsername[32];// ��Ȩ�������ʺ�
    char				szAuthorizePassword[36];// ��Ȩ����������
    
    char				szIpACS[16];			// ACS(�Զ�ע�������) IP
    unsigned short		usPortACS[2];			// ACS Port������4�ֽڶ��룬Ŀǰֻ�������һ��
    char				szUsernameACS[32];		// ACS�û���
    char				szPasswordACS[36];		// ACS����
    bool				bVideoMonitorEnabled[4];// DVS�Ƿ����ϱ�ǰ����Ƶ�źż����Ϣ����ֵ��trueʹ�ܣ�false��ʹ��
    int					iVideoMonitorInterval;	// �ϱ�����(����)
    
    char				szCoordinateGPS[64];	// GPS����
    char				szPosition[32];			// �豸λ��
    char				szConnPass[36];			// �豸������
} ZLNET_DEV_INTERVIDEO_BELL_CFG;

// ƽ̨�������� �� ������ά
typedef struct  
{
	DWORD				dwSize;
	unsigned short		nSevPort;				// �������˿ڣ���ֵ����ֵ1~65535
    char				szSevIp[ZLNET_INTERVIDEO_NSS_IP]; // ������IP��ַ���ַ���������'\0'��������32byte
    char				szDevSerial[ZLNET_INTERVIDEO_NSS_SERIAL]; // ǰ���豸���кţ��ַ���������'\0'��������32byte
    char				szUserName[ZLNET_INTERVIDEO_NSS_USER];
    char				szPwd[ZLNET_INTERVIDEO_NSS_PWD];
} ZLNET_DEV_INTERVIDEO_NSS_CFG;

//ƽ̨�������� �� ����
typedef struct {
	DWORD serverip;
	int serverport;
	char szDevID[ZLNET_INTERVIDEO_MR_ID];
	char DVRUserName[ZLNET_INTERVIDEO_MR_USERPSW];
	char DVRPassword[ZLNET_INTERVIDEO_MR_USERPSW];
}ZLNET_MR_SYSTEM_CONFIG;

typedef struct 
{
	int Enable;								//ʹ�ܱ�־, ��ֵ, 1 ʹ��, 0 ��ʹ��.
	ZLNET_MR_SYSTEM_CONFIG JFSysConfig;
}ZLNET_INTERVIDEO_MR_CFG;

////////////////////////////////HDVRר��//////////////////////////////////
// ����������չ�ṹ��
typedef struct 
{
	/* ��Ϣ����ʽ������ͬʱ���ִ���ʽ������
	 * 0x00000001 - �����ϴ�
	 * 0x00000002 - ����¼��
	 * 0x00000004 - ��̨����
	 * 0x00000008 - �����ʼ�
	 * 0x00000010 - ������Ѳ
	 * 0x00000020 - ������ʾ
	 * 0x00000040 - �������
	 * 0x00000080 - Ftp�ϴ�
	 * 0x00000100 - ����
	 * 0x00000200 - ������ʾ
	 * 0x00000400 - ץͼ
	*/

	/* ��ǰ������֧�ֵĴ���ʽ����λ�����ʾ */
	DWORD				dwActionMask;

	/* ������������λ�����ʾ�����嶯������Ҫ�Ĳ����ڸ��Ե����������� */
	DWORD				dwActionFlag;
	
	/* �������������ͨ�������������������Ϊ1��ʾ��������� */ 
	BYTE				byRelAlarmOut[ZLNET_MAX_ALARMOUT_NUM_EX];
	DWORD				dwDuration;				/* ��������ʱ�� */

	/* ����¼�� */
	BYTE				byRecordChannel[ZLNET_MAX_VIDEO_IN_NUM_EX]; /* ����������¼��ͨ����Ϊ1��ʾ������ͨ�� */
	DWORD				dwRecLatch;				/* ¼�����ʱ�� */

	/* ץͼͨ�� */
	BYTE				bySnap[ZLNET_MAX_VIDEO_IN_NUM_EX];
	/* ��Ѳͨ�� */
	BYTE				byTour[ZLNET_MAX_VIDEO_IN_NUM_EX];

	/* ��̨���� */
	ZLNET_PTZ_LINK			struPtzLink[ZLNET_MAX_VIDEO_IN_NUM_EX];
	DWORD				dwEventLatch;			/* ������ʼ��ʱʱ�䣬sΪ��λ����Χ��0~15��Ĭ��ֵ��0 */
	/* �����������������ͨ�������������������Ϊ1��ʾ��������� */ 
	BYTE				byRelWIAlarmOut[ZLNET_MAX_ALARMOUT_NUM_EX];
	BYTE				bMessageToNet;
	BYTE                bMMSEn;                /*���ű���ʹ��*/
	BYTE                bySnapshotTimes;       /*���ŷ���ץͼ���� */
	BYTE				bMatrixEn;				/*!< ����ʹ�� */
	DWORD				dwMatrix;				/*!< �������� */			
	BYTE				bLog;					/*!< ��־ʹ�ܣ�Ŀǰֻ����WTN��̬�����ʹ�� */
	BYTE				byReserved[511];   
} ZLNET_MSG_HANDLE_EX;

// �ⲿ������չ
typedef struct
{
	BYTE				byAlarmType;			// ���������ͣ�0�����գ�1������
	BYTE				byAlarmEn;				// ����ʹ��
	BYTE				byReserved[2];						
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE_EX	struHandle;				// ����ʽ
} ZLNET_ALARMIN_CFG_EX, *LPZLNET_DEV_ALARMIN_CFG_EX; 

// ��̬��ⱨ��
typedef struct 
{
	BYTE				byMotionEn;				// ��̬��ⱨ��ʹ��
	BYTE				byReserved;
	WORD				wSenseLevel;			// ������
	WORD				wMotionRow;				// ��̬������������
	WORD				wMotionCol;				// ��̬������������
	BYTE				byDetected[ZLNET_MOTION_ROW][ZLNET_MOTION_COL]; // ����������32*32������
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	//NSP
	ZLNET_MSG_HANDLE_EX		struHandle;				//����ʽ
} ZLNET_MOTION_DETECT_CFG_EX;

// ��Ƶ��ʧ����
typedef struct
{
	BYTE				byAlarmEn;				// ��Ƶ��ʧ����ʹ��
	BYTE				byReserved[3];
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	//NSP
	ZLNET_MSG_HANDLE_EX	struHandle;				// ����ʽ
} ZLNET_VIDEO_LOST_CFG_EX;

// ͼ���ڵ�����
typedef struct
{
	BYTE				byBlindEnable;			// ʹ��
	BYTE				byBlindLevel;			// ������1-6
	BYTE				byReserved[2];
	ZLNET_TSECT			stSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	//NSP
	ZLNET_MSG_HANDLE_EX	struHandle;				// ����ʽ
} ZLNET_BLIND_CFG_EX;

// Ӳ����Ϣ(�ڲ�����)
typedef struct 
{
	BYTE				byNoDiskEn;				// ��Ӳ��ʱ����
	BYTE				byReserved_1[3];
	ZLNET_TSECT			stNDSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE_EX	struNDHandle;			// ����ʽ
	
	BYTE				byLowCapEn;				// Ӳ�̵�����ʱ����
	BYTE				byLowerLimit;			// ������ֵ��0-99
	BYTE				byReserved_2[2];
	ZLNET_TSECT			stLCSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE_EX	struLCHandle;			// ����ʽ
	
	BYTE				byDiskErrEn;			// Ӳ�̹��ϱ���
	BYTE				bDiskNum;
	BYTE				byReserved_3[2];
	ZLNET_TSECT			stEDSect[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT]; //NSP
	ZLNET_MSG_HANDLE_EX	struEDHandle;			// ����ʽ
} ZLNET_DISK_ALARM_CFG_EX;

typedef struct
{
	BYTE				byEnable;
	BYTE				byReserved[3];
	ZLNET_MSG_HANDLE_EX	struHandle;
} ZLNET_NETBROKEN_ALARM_CFG_EX;

// ǰ�˽������ò�����Ϣ
typedef struct __ZLNET_ENCODER_CFG_DEV 
{
	int					nChannels;				// ����ͨ������
	ZLNET_DEV_ENCODER_INFO	stuDevInfo[32];			// ������ͨ����ǰ�˱�������Ϣ
	BYTE				byHDAbility;			// ����ͨ��������֧�ָ�����Ƶ����(Ϊ0��ʾ��֧�ָ�������)
												// ע�����֧�ָ������ã�����ͨ��Ϊ0~N-1������N֮�������ͨ������Ϊ���壬�п��ܱ��治�ɹ�
	BYTE				bTVAdjust;				// �豸�Ƿ�֧��TV����, 0:��֧�� 1:֧��.
	BYTE				bDecodeTour;			// �豸�Ƿ�֧�ֽ�����Ѳ, 0:��֧�� ����0:��ʾǰ��֧����Ѳ����豸��.
	BYTE				bRemotePTZCtl;			// ָʾ�Ƿ�֧��Զ����̨���ơ�
	char				reserved[12];
} ZLNET_ENCODER_CFG_DEV, *LPZLNET_ENCODER_CFG_DEV;

/////////////////////////////////��̭����/////////////////////////////////

// ��ѯ�豸����״̬ͨ����Ϣ����ؽӿ�����̭���벻Ҫʹ��
typedef struct
{
	BYTE				byRecordStatic;			// ͨ���Ƿ���¼��0����¼��1���ֶ�¼��2���Զ�¼��
	BYTE				bySignalStatic;			// ���ӵ��ź�״̬��0��������1���źŶ�ʧ
	BYTE				byHardwareStatic;		// ͨ��Ӳ��״̬��0��������1���쳣������DSP����
	char				reserve;
	DWORD				dwBitRate;				// ʵ������
	DWORD				dwLinkNum;				// �ͻ������ӵĸ���
	DWORD				dwClientIP[ZLNET_MAX_LINK];// �ͻ��˵�IP��ַ
} ZLNET_DEV_CHANNELSTATE, *LPZLNET_DEV_CHANNELSTATE;

// ��ѯ�豸����״̬����ؽӿ�����̭���벻Ҫʹ��
typedef struct
{
	DWORD				dwDeviceStatic;			// �豸��״̬��0x00��������0x01��CPUռ�ù��ߣ�0x02��Ӳ������
	ZLNET_DEV_DISKSTATE	stHardDiskStatic[ZLNET_MAX_DISKNUM]; 
	ZLNET_DEV_CHANNELSTATE stChanStatic[ZLNET_MAX_CHANNUM];	//ͨ����״̬
	BYTE				byAlarmInStatic[ZLNET_MAX_ALARMIN];//�����˿ڵ�״̬��0��û�б�����1���б���
	BYTE				byAlarmOutStatic[ZLNET_MAX_ALARMOUT]; //��������˿ڵ�״̬��0��û�������1���б������
	DWORD				dwLocalDisplay;			// ������ʾ״̬��0��������1��������
} ZLNET_DEV_WORKSTATE, *LPZLNET_DEV_WORKSTATE;

// Э����Ϣ
typedef struct 
{
	char				protocolname[12];		// Э����
	unsigned int		baudbase;				// ������
	unsigned char		databits;				// ����λ
	unsigned char		stopbits;				// ֹͣλ
	unsigned char		parity;					// У��λ
	unsigned char		reserve;
} ZLNET_PROTOCOL_INFO, *LPZLNET_PROTOCOL_INFO;

// �����Խ���������
typedef struct 
{
	// ��Ƶ�������
	BYTE				byInFormatTag;			// �������ͣ���PCM
	BYTE				byInChannels;			// ������
	WORD				wInBitsPerSample;		// �������					
	DWORD				dwInSamplesPerSec;		// ������

	// ��Ƶ�������
	BYTE				byOutFormatTag;			// �������ͣ���PCM
	BYTE				byOutChannels;			// ������
	WORD				wOutBitsPerSample;		// �������				
	DWORD				dwOutSamplesPerSec;		// ������
} ZLNET_DEV_TALK_CFG, *LPZLNET_DEV_TALK_CFG;

//NVR(���DVR)
typedef enum
{
	NVR_PROTOCOL_TYPE_ZL = 0,
	NVR_PROTOCOL_TYPE_DH,
	NVR_PROTOCOL_TYPE_HH,
	NVR_PROTOCOL_TYPE_ONVIF,
	NVR_PROTOCOL_TYPE_RTSP,
	NVR_PROTOCOL_TYPE_MAX,
}ZLNET_NVR_PROTOCOL;

//�����豸����
typedef struct 
{
	ZLNET_NVR_PROTOCOL  protocol;			//����Э��
	char ip[ZLNET_MAX_URL_LEN];		//������豸IP
	int Port;								//������豸�˿�
	char UserName[ZLNET_NVR_PASSWORD_LEN];	//������豸�û���
	char Password[ZLNET_NVR_PASSWORD_LEN];	//������豸����
	int channel;							//������豸ͨ��
	BOOL bEnable;							//����ͨ��ʹ��
	int nNvrResolution;						//��ǰ����ͨ���ķֱ���
	BYTE nReserved[32];						//����
}ZLNET_NVR_CONFIG_NET_CHN;

//�����豸����
typedef struct 
{
	int nSize;
	int nValidNum;		//��Ч���ø���
	int nMaxEncode;		//����������
	ZLNET_NVR_CONFIG_NET_CHN NetConfig[ZLNET_MAX_CHANNUM];
}ZLNET_NVR_CONFIG_NET;

//ͨ����
typedef struct 
{
	int nSize;
	int nLocalChn;	//����ͨ����
	int nMixChn;	//����ͨ����
}ZLNET_NVR_CHANNEL;

//��ǰ����ͨ������
typedef struct 
{
	int nSize;
	int nChannelNum;
	int nError;
	int Reserved1;
	int Reserved2;
	ZLNET_NVR_CONFIG_NET_CHN configNetChN;
} ZLNET_NVR_CHANNEL_INFO_EX ;

//�����ṹ��
typedef struct
{
	ZLNET_NVR_PROTOCOL  eProtocol;	//Э������
	char ip[128];					//ip����URL
	int  nPort;						//�˿ں�
	char szDevType[32];				//�豸����
}ZLNET_NVR_SEARCHINFO;

//����ͨ��PTZ����
typedef struct 
{
	int		nSize;		//�ṹ���С
	int		nChannel;	//����ͨ����
	int		minPreset;	//Ԥ�õ���Сֵ��
	int		maxPreset;	//Ԥ�õ����ֵ��
	int		minTour;	//�Զ�Ѳ����·����Сֵ��
	int		maxTour;	//�Զ�Ѳ����·�����ֵ��
	int		minPattern;	//�켣��·����Сֵ��
	int		maxPattern;	//�켣��·�����ֵ��
}ZLNET_NVR_NET_PTZ_PARAM;

//ͨ��������
typedef struct _ZLNET_CHANNEL_NAME_LATTICE
{
	int nSize;						//�ṹ���С
	int nChannel;					//ͨ��
	int	nWidth;						//������
	int nHeight;					//����߶�
	int nCharacterSize;				//�ַ�����
	BYTE buffer[ZLNET_LATTICE_LEN];	//һ��ͨ�����ĵ����С
} ZLNET_CHANNEL_NAME_LATTICE;

//NVR�豸ͨ��ģʽ
typedef struct
{
	int nLocalD1Channel;	//����ͨd1����
	int nLocalCIFChannel;	//����ͨcif����
	int nNetChannel;		//����ͨ����
	int nAbility;			//�����������
} ZLNET_NVR_CHANNEL_MODE;

typedef struct
{
	int nSize;						//�ṹ���С
	int nMode;						//��ǰͨ��ģʽ
	int nModeNum;					//ͨ��ģʽ����
	ZLNET_NVR_CHANNEL_MODE channelMode[ZLNET_CHANNEL_MODE_MAX_NUM];//ͨ��ģʽ
} ZLNET_NVR_CHANNEL_MODE_SUPPORT;

//NVR����ͨ��״̬
typedef struct 
{
	int nChn;		//ͨ����
	int nState;		//ͨ��״̬		
	int nWith;		//�ֱ��ʿ�
	int nHeight;	//�ֱ��ʸ�
	int nFps;		//֡��
	int nBitRate;	//����
	int nReserved[4]; 
}ZLNET_NVR_STATE_NET_CHN;

//NVR����ͨ��״̬����
typedef struct 
{
	int nSize;
	int nNetChnNum;     //NVR��Ч����ͨ����
	ZLNET_NVR_STATE_NET_CHN NetChnState[ZLNET_MAX_CHANNUM]; //����ͨ��״̬��Ϣ
}ZLNET_NVR_STATE_NET;

//����IPC��Ƶ����
typedef struct _ZLNET_VIDEO_PARAM
{
	int nSize;			//�ṹ���С

	int nCmd;			//��Ƶ����Ĭ������ 0������ 1���ָ�Ĭ��ֵ 2����Ȼ 3����׼ 4������

	int nLens;			//��Ȧ����
	int nShutter;		//���ſ���
	int nAgc;			//�Զ��������

	int nSenseup;		//֡�ۻ�

	int nBrightness;	//����
	int nAcce;			//���ȶ�̬����
	int nDefog;			//������

	int nBackLight;		//���ⲹ��
	int nWhiteBal;		//��ƽ��
	int nDayNight;		//��|ҹ

	int nTwoDNR;		//2D����	����
	int nThreeDNR;		//3D���� ����
	int nTdLevel;		//3D���뼶��

	int nMirror;		//���� ��ת

	int nSharpness;		//��ȿ���
	int nSharpnessLevel;//��ȵ�������

	int nLlsc;			//ͼ���Ľ����Ȳ��� ����
	int nNorP;			//N|P ��ʽѡ�� ʵ��֡��ѡ�� N:30fps P:25fps

	int nRes[4];		//����
} ZLNET_VIDEO_PARAM;

//�����Ƶ����
typedef struct _ZLNET_DOME_CAMERA_VIDEO_PARAM
{
	int nWhiteBalance;					//��ƽ��
	int nWideDynamic;					//��̬
	int nHyperResolution;				//���ֱ���
	int nICR;							//��ɫ�ڰ�
	int nAutoICR;						//�Զ���ת��
	int nSaturation;					//���Ͷ�
	int nHue;							//ɫ��
	int nRes[4];
}ZLNET_DOME_CAMERA_VIDEO_PARAM;

//UPNP״̬
typedef struct _ZLNET_NET_UPNP_STATE
{
	int nSize;			//�ṹ���С
	int nState;			//UPNP����״̬
	int Res[4];			//����
} ZLNET_NET_UPNP_STATE;

//WIFIʹ��
typedef struct _ZLNET_WIFI_ENABLE
{
	int nSize;		//�ṹ���С
	int nCmd;		//���� 0���ر� 1������
	int Res[4];		//����
} ZLNET_WIFI_ENABLE;

//WIFI���ӷ�ʽ
typedef struct _ZLNET_WIFI_CONNECTION_TYPE
{
	int nSize;		//�ṹ���С
	int nCmd;		//���� 0���ֶ� 1���Զ�
	int Res[4];		//����
} ZLNET_WIFI_CONNECTION_TYPE;

//���ӵ�AP��Ҫ���õĲ���
//ssid��������
//jfs���ܷ�ʽ������ɨ��Ľ����������
//���ݼ��ܷ�ʽѡ����������Ա��
//jfs=1	���:	psk, proto, encryption 
//jfs=2 ���:	wep_tx_keyidx, wep_key
typedef struct _ZLNET_DEV_WIFI_CFG
{
	int nSize;									//�ṹ���С

	char ifname[ZLNET_WIFI_NET_CARD_LEN];		//eth1 /eth2 //����������

	char ssid[ZLNET_WIFI_JUNCTION_LEN];			//���ӵ�����

	/* ���ܷ�ʽ */
	int nJfs; 									//0:������ 1:WPA|WPA2 	2:WEP  
	int nKeyType; 								//0:ascii 1:hex �����ʽ

	/* WPA */
	char psk[ZLNET_WIFI_PSW_LENGTH];			//����ascii �� hex֮��
	char protocol[ZLNET_WIFI_PROTOCOL_LNE];		//Э����WPA �� RSN֮��
	char encryption[ZLNET_WIFI_PROTOCOL_LNE];	//���ܷ��������뷽ʽ TKIP | CCMP

	/* WEP */
	int nWepTxKeyidx; 							//������4�����룬�ó�Ա������ʾѡ����������
	char wepKey[ZLNET_WIFI_PSW_LENGTH];			//����

	char Res[64];								//����
} ZLNET_DEV_WIFI_CFG;

//WIFI���ܵļ�������  0Ϊû�м��ܷ�ʽ
typedef enum _ZLNET_WIFI_ENCRYPTION_TYPE
{								// +��Ӧ�Ķ�ZLNET_DEV_WIFI_CFG������ 
	ZLNET_WIFI_NO = 0,			// |ssid=***, jfs=0
	ZLNET_WIFI_WEP,				// |ssid=***, jfs=2 ,wep_tx_keyidx=?, wep_key=***, key_type=?
	ZLNET_WIFI_WPA_TKIP,	 	// |ssid=***, jfs=1 ,proto=WPA, encryption=TKIP, psk=*** , key_type=?
	ZLNET_WIFI_WPA_CCMP,	 	// |ssid=***, jfs=1 ,proto=WPA, encryption=CCMP, psk=*** , key_type=?  
	ZLNET_WIFI_WPA2_TKIP,		// |ssid=***, jfs=1 ,proto=RSN, encryption=TKIP, psk=*** , key_type=?
	ZLNET_WIFI_WPA2_CCMP		// |ssid=***, jfs=1 ,proto=RSN, encryption=CCMP, psk=*** , key_type=?
} ZLNET_WIFI_ENCRYPTION_TYPE;

//һ������·����Ϣ
typedef struct _ZLNET_WIRELESS_ROUTER_INFO
{
	char    macAddr[ZLNET_MACADDR_LEN];		//MAC��ַ
	int     nFreq;							//channel Ƶ��
	int		nChannel;						//�����ŵ�
	int     nSignalLevel;					//�ź�ǿ�� dbm
	int     nFlags;							//���ܷ�ʽ WPA-PSK-TKIP | WEP �ȵ�  0:Ϊû�м��� -1:Ϊδ֪�ļ��ܷ�ʽ
	char    ssid[ZLNET_WIFI_JUNCTION_LEN];	//ap����
} ZLNET_WIRELESS_ROUTER_INFO;

//wifiɨ��õ�����Ϣ
typedef struct _ZLNETl_WIFI_NETWORK_INFO
{
	int nSize;			//�ṹ���С
	int nValidNum;		//��Ч����
	ZLNET_WIRELESS_ROUTER_INFO info[ZLNET_MAX_WIFI_INFO_NUM];
} ZLNETl_WIFI_NETWORK_INFO;

//DDNSע����Ϣ
typedef struct _ZLNET_DDNS_REGISTER_INFO
{
	int nSize;									//�ṹ���С
	int nCmd;									//ע������
	ZLNET_DDNS_SERVER_CFG  struDdnsServer;		//DDNS�������ṹ��
}ZLNET_DDNS_REGISTER_INFO;

//DDNS״̬
typedef struct _ZLNET_DDNS_STATE
{
	int nSize;														//�ṹ���С
	int nValidNum;													//��Ч����
	char ddnsType[ZLNET_MAX_DDNS_NUM][ZLNET_MAX_SERVER_TYPE_LEN];	//�豸֧�ֵ�DDNS����������
	int nState[ZLNET_MAX_DDNS_NUM];									//DDNS״̬��
	int nRes[4];
}ZLNET_DDNS_STATE;

//˽����͸����
typedef struct _ZLNET_DEV_STUN_CONFIG 
{
	//char DeviceIP[32];
	int StunEnable;											//˽����͸ʹ��		
	char ServerIP[ZLNET_DEVICE_STUN_SERVERIP];				//������IP��������
	int SerPort;											//�������˿�
	char LoginSvrName[ZLNET_DEVICE_STUN_USERNAME];			//�û���
	char LoginSvrPassword[ZLNET_DEVICE_STUN_PASSWORD];		//����
	DWORD Res[48];
}ZLNET_DEV_STUN_CONFIG;

//˽����͸״̬
typedef struct _ZLNET_DEV_STUN_STATE
{
	int nState;			//����״̬
	int nError;			//������
}ZLNET_DEV_STUN_STATE;

//���籴��GB28181����
typedef struct
{
	int nSize;								//�ṹ���С

	char deviceID[ZLNET_AEB_ID_LEN];		//���籴��GB28181 Device ID
	int nSipPort;							//���籴��GB28181 sip �˿�
	char deviceDomain[ZLNET_AEB_DOMAIN_LEN];//���籴��GB28181 Device ����
	char password[ZLNET_AEB_PSW_LEN];		//���籴��GB28181 ����
	int nExpire;							//���籴��GB28181 ��Чʱ��
	int nKeepLive;							//���籴��GB28181 ����ʱ��

	char serverIp[ZLNET_AEB_IP_LEN];		//���籴��GB28181 Server IP
	int nServerPort;						//���籴��GB28181 Server �˿�
	char serverID[ZLNET_AEB_ID_LEN];		//���籴��GB28181 Server ID
	char serverDomain[ZLNET_AEB_DOMAIN_LEN];//���籴��GB28181 Server ����

	int nAlarmNum;							//����ͨ����
	int nChannelNum;						//ͨ����

	char channelInfo[ZLNET_MAX_CHANNUM][ZLNET_AEB_INFO_LEN];		//���籴��GB28181 ͨ����Ϣ
	char alarmInfo[ZLNET_AEB_ALARM_INFO_NUM][ZLNET_AEB_INFO_LEN];	//���籴��GB28181 ������Ϣ

	int nRes[64];							//����
} ZLNET_AEB_GB_PROTOCOL;

//������������
typedef struct
{
	char serverIP[ZLNET_KONLAN_IP_LEN];		//������IP
	int  nPort;								//�˿�
	char id[ZLNET_KONLAN_ID_LEN];			//ID		
	int  nRes[4];							
}ZLNET_KONLAN_NET_CONFIG;					

//ͨ��¼��״̬
typedef struct
{
	int		nSize;								//�ṹ���С
	int		nChannelNum;						//ͨ����
	DWORD	dwRecordStateMask;					//����ͨ��¼��״̬����ֵ 0:δ¼�� 1:����¼��
	int		nRes[4];
}ZLNET_CHANNEL_RECORD_STATE;

////////////////////////////////�������/////////////////////////////////
//����ATM����
typedef enum _ZLNET_IVA_ATM_INDEX
{
	ZLNET_IVA_NULL = -1,
	ZLNET_IVA_ATM1 = 0,
	ZLNET_IVA_ATM2,
}ZLNET_IVA_ATM_INDEX;

//������������
typedef enum _ZLNET_IVA_SSB_INDEX
{
	ZLNET_IVA_SSB_NULL = -1,
	ZLNET_IVA_SSB_HALL = 0,
	ZLNET_IVA_SSB_ROOM,
}ZLNET_IVA_SSB_INDEX;

//����ͨ������
typedef enum _ZLNET_IVA_FACE_INDEX
{
	ZLNET_IVA_FACE_NULL = -1,
	ZLNET_IVA_FACE_ANALYSIS = 0,	//����ͨ��
	ZLNET_IVA_FACE_PANORAMIC,		//ȫ��ͨ��
}ZLNET_IVA_FACE_INDEX;

//������������
typedef enum _ZLNET_LICENSE_PLATE_REGION_TYPE
{
	ZLNET_IVA_LICENSE_PLATE_REGION_NULL = 0,
	ZLNET_IVA_LICENSE_PLATE_REGION_DETECTION,	//������������
	ZLNET_IVA_LICENSE_PLATE_REGION_FORBIDDEN,	//�����������
} ZLNET_LICENSE_PLATE_REGION_TYPE;

//�߼�ͨ��˳��
typedef enum _ZLNET_IVA_LOGIC_CHANNEL
{
	ZLNET_IVA_ATM1_PANEL = 0,		//ATM1���
	ZLNET_IVA_ATM1_FACE,			//ATM1����
	ZLNET_IVA_ATM2_PANEL,			//ATM2���
	ZLNET_IVA_ATM2_FACE,			//ATM2����
}ZLNET_IVA_LOGIC_CHANNEL;

//��־�洢ģʽ 
typedef enum _ZLNET_IVA_LOG_MODE
{
	ZLNET_IVA_LOGMODE_NETSEND = 0,		/*���緢��*/
	ZLNET_IVA_LOGMODE_LOCAL,			/*���ش洢*/
	ZLNET_IVA_LOGMODE_LOCALA_NETSEND	/*���緢�Ͳ����ش洢*/
}ZLNET_IVA_LOG_MODE;

//��־��ѯ��ʽ
typedef enum _ZLNET_IVA_LOG_SEARCH_MODE
{
	ZLNET_IVA_SEARCHMODE_DATE = 0,	/* ����ģʽ */
	ZLNET_IVA_SEARCHMODE_ID,		/* IDģʽ */
}ZLNET_IVA_LOG_SEARCH_MODE;

//��־����ģʽ
typedef enum _ZLNET_IVA_LOG_DOWNLOAD_MODE
{
	ZLNET_IVA_DOWNLOADMODE_DOWNLOAD = 0,	/* ���� */
	ZLNET_IVA_DOWNLOADMODE_DOWNLOADDEL,		/* ���ز�ɾ�� */
	ZLNET_IVA_DOWNLOADMODE_DEL,				/* ɾ�� */
}ZLNET_IVA_LOG_DOWNLOAD_MODE;

//��Աͳ����Ա���뷽��
typedef enum _ZLNET_IVA_HDCTTYPE
{
	ZLNET_IVA_HDCT_IN = 0 ,		//��Ա����
	ZLNET_IVA_HDCT_OUT			//��Ա�뿪
}ZLNET_IVA_HDCTTYPE; 

//���ܱ�������
typedef enum _ZLNET_IVA_ATM_ALARM_TYPE
{
	ZLNET_IVA_ATMALARMTYPE_ATM_DETECTAREA = 26,		//����������ﱨ��(���豸����)
	ZLNET_IVA_ATMALARMTYPE_ATM_KEYBOARDAREA,		//�����������ﱨ��
	ZLNET_IVA_ATMALARMTYPE_ATM_CARDREGION,			//�忨���������ﱨ��
	ZLNET_IVA_ATMALARMTYPE_ATM_SHIELD,				//�������������ﱨ��
	ZLNET_IVA_ATMALARMTYPE_ATM_ENTER,				//��Ա���뱨��
	ZLNET_IVA_ATMALARMTYPE_ATM_LEAVE,				//��Ա�뿪����
	ZLNET_IVA_ATMALARMTYPE_ATM_PROCESS_TOOLONG,		//��Ա��ʱ���������
	ZLNET_IVA_ATMALARMTYPE_ATM_PANEL_CAMERA_BLOCK,	//�������ͷ���±���
	ZLNET_IVA_ATMALARMTYPE_ATM_FACE_CAMERA_BLOCK,	//��������ͷ���±���
	ZLNET_IVA_ATMALARMTYPE_ATM_PANEL_AMERA_NOSIGNAL,//�������ͷ����Ƶ�źű���
	ZLNET_IVA_ATMALARMTYPE_ATM_FACE_CAMERA_NOSIGNAL,//��������ͷ����Ƶ�źű���
	ZLNET_IVA_ATMALARMTYPE_ATM_STRANGER,			//İ���˱���(������������)
	ZLNET_IVA_ATMALARMTYPE_ATM_ARNORMAL,			//�쳣�˱���
	ZLNET_IVA_ATMALARMTYPE_ATM_GPI,					//�������뱨��(�ⲿ����)

	ZLNET_IVA_PLATEID_ALARM_TYPE = 51,				//���Ʊ���
	ZLNET_IVA_PLATEID_ALARM_GPI = 52,				//�����豸���ر���

	ZLNET_IVA_STAFFCOUNT_FORWARD = 61,					//��ͷͳ�ƽ��뱨��
	ZLNET_IVA_STAFFCOUNT_REVERSE,								//��ͷͳ���뿪����
	ZLNET_IVA_STAFFCOUNT_MULTIUSER,							//���˱���	
	ZLNET_IVA_STAFFCOUNT_ALARM_GPI,							//�������뱨��(�ⲿ����)

	ZLNET_IVA_SSB_TRAILING_WITHDRAWALS = 71,		//����β��ȡ���
	ZLNET_IVA_SSB_PEOPEL_HOVER,						//������Ա�ǻ�
	ZLNET_IVA_SSB_PEOPEL_FELL,						//������Ա����
	ZLNET_IVA_SSB_REMNANTS,							//���������ﱨ��
	ZLNET_IVA_SSB_PEOPELS_GATHER,					//�������˾ۼ�����
	ZLNET_IVA_SSB_FORBIDDEN_ACCESS,                 //������ֹ����
	ZLNET_IVA_SSB_FIGHTING,                         //��������¼�
	ZLNET_IVA_SSB_CAMERA_NO_SIGNAL,					//��������ͷ���źű���
	ZLNET_IVA_SSB_CAMERA_ABNORMAL,					//��������ͷ�쳣����
	ZLNET_IVA_SSB_SPORTS_INVADE,					//�ӳ����˶����ֱ���
	ZLNET_IVA_SSB_ROOM_CAMERA_NO_SIGNAL,			//�ӳ�������ͷ���źű���
	ZLNET_IVA_SSB_ALARM_GPI,						//�������뱨��(�ⲿ����)

	ZLNET_IVA_BZS_CROSS_FORWARD_ALARM = 101,		//������߱���
	ZLNET_IVA_BZS_CROSS_REVERSE_ALARM,      		//������߱���
	ZLNET_IVA_BZS_TOUCH_LINE_ALARM,					//�����߱���
	ZLNET_IVA_BZS_TOUCH_LINE_NEG_DIR_ALARM, 		//�����߱���
	ZLNET_IVA_BZS_CROSS_TWO_LINE_ALARM,				//˫�߼�ⱨ��
	ZLNET_IVA_BZS_AREA_ENTER_ALARM, 				//������������򱨾�
	ZLNET_IVA_BZS_AREA_LEAVE_ALARM, 				//�������뿪���򱨾�
	ZLNET_IVA_BZS_AREA_TOUCH_AREA_ALARM,			//�����ⴥ�����򱨾�
	ZLNET_IVA_BZS_AREA_LINGER_ALARM,				//�������ǻ�����
	ZLNET_IVA_BZS_AREA_APPEAR_ALARM,				//��������ֱ���(������)
	ZLNET_IVA_BZS_AREA_DISAPPEAR_ALARM,				//��������ʧ����(������)
	ZLNET_IVA_BZS_OBJECT_MOVE_ALARM,      			//���Ʊ���
	ZLNET_IVA_BZS_CAMERA_NO_SIGNAL_ALARM,			//�������ź�ͷ����
	ZLNET_IVA_BZS_CAMERA_ABNORMAL_ALARM, 			//�����쳣ͷ����
	ZLNET_IVA_BZS_GPI_ALARM,						//�������뱨��(�ⲿ����)

	ZLNET_IVA_FACE_CAPTURE_ALARM = 131,				//�������񱨾�
	ZLNET_IVA_FACE_ANALYSIS_NO_SIGNAL_ALARM,		//����ͨ������ͷ���ź�
	ZLNET_IVA_FACE_PANORAMIC_NO_SIGNAL_ALARM,		//ȫ��ͨ������ͷ���ź�
	ZLNET_IVA_FACE_GPI_ALARM,						//�������뱨��(�ⲿ����)
	ZLNET_IVA_ARMTYPE_MIN = ZLNET_IVA_ATMALARMTYPE_ATM_DETECTAREA,		//������Сֵ
	ZLNET_IVA_ARMTYPE_MAX = ZLNET_IVA_FACE_GPI_ALARM,		//�������ֵ(ע��:���ӱ���������Ҫ�滻����������ֵ!!!)
}ZLNET_IVA_ALARM_TYPE; 

typedef enum _ZLNET_IVA_STAFF_ALARM_ENABLE_MASK 
{
	ZLNET_IVA_STAFF_FORWARD_MASK = 0x01,
	ZLNET_IVA_STAFF_REVERSE_MASK = 0x02,
	ZLNET_IVA_STAFF_MULTI_MASK = 0x04,
}ZLNET_IVA_STAFF_ALARM_ENABLE_MASK;

typedef enum _ZLNET_IVA_ATM_ALARM_ENABLE_MASK 
{
	ZLNET_IVA_ATM_DETECTAREA_MASK = 0x1,				//����������ﱨ��(���豸����)
	ZLNET_IVA_ATM_KEYBOARDAREA_MASK = 0x2,				//�����������ﱨ��
	ZLNET_IVA_ATM_CARDREGION_MASK = 0x4,				//�忨���������ﱨ��
	ZLNET_IVA_ATM_SHIELD_MASK = 0x8,					//�������������ﱨ��
	ZLNET_IVA_ATM_ENTER_MASK = 0x10,					//��Ա���뱨��
	ZLNET_IVA_ATM_LEAVE_MASK = 0x20,					//��Ա�뿪����
	ZLNET_IVA_ATM_PROCESS_TOOLONG_MASK = 0x40,			//��Ա��ʱ���������
	ZLNET_IVA_ATM_PANEL_CAMERA_BLOCK_MASK = 0x80,		//�������ͷ���±���
	ZLNET_IVA_ATM_FACE_CAMERA_BLOCK_MASK = 0x100,		//��������ͷ���±���
	ZLNET_IVA_ATM_PANEL_AMERA_NOSIGNAL_MASK = 0x200,	//�������ͷ����Ƶ�źű���
	ZLNET_IVA_ATM_FACE_CAMERA_NOSIGNAL_MASK = 0x400,	//��������ͷ����Ƶ�źű���
	ZLNET_IVA_ATM_STRANGER_MASK = 0x800,				//İ���˱���(������������)
	ZLNET_IVA_ATM_ARNORMA_MASK = 0x1000,				//�쳣�˱���
}ZLNET_IVA_ATM_ALARM_ENABLE_MASK;

//�������б�������ʹ��
typedef enum _ZLNET_IVA_SSB_ALARM_ENABLE_MASK 
{
	ZLNET_IVA_SSB_TRAILING_WITHDRAWALS_MASK = 0x1,	//����β��ȡ���
	ZLNET_IVA_SSB_PEOPEL_HOVER_MASK = 0x2,			//������Ա�ǻ�
	ZLNET_IVA_SSB_PEOPEL_FELL_MASK = 0x4,			//������Ա����
	ZLNET_IVA_SSB_REMNANTS_MASK = 0x8,				//���������ﱨ��
	ZLNET_IVA_SSB_PEOPELS_GATHER_MASK = 0x10,		//�������˾ۼ�����
	ZLNET_IVA_SSB_FORBIDDEN_ACCESS_MASK = 0x20,     //������ֹ����
	ZLNET_IVA_SSB_FIGHTING_MASK = 0x40,             //��������¼�
	ZLNET_IVA_SSB_CAMERA_NO_SIGNAL_MASK = 0x80,		//��������ͷ���źű���
	ZLNET_IVA_SSB_CAMERA_ABNORMAL_MASK = 0x100,		//��������ͷ�쳣����
	ZLNET_IVA_SSB_SPORTS_INVADE_MASK = 0x200,       //�ӳ����˶�����
	ZLNET_IVA_SSB_ROOM_CAMERA_NO_SIGNAL_MASK = 0x400,//�ӳ�������ͷ���źű���
}ZLNET_IVA_SSB_ALARM_ENABLE_MASK;

//�ܽ籨������ʹ��
typedef enum _IVA_BZS_ALARM_ENABLE_MASK
{
	ZLNET_IVA_BZS_SINGLE_WARNING_LINE_MASK = 0x01,			//�����Խ����
	ZLNET_IVA_BZS_NEG_CROSS_WARNING_LINE_MASK = 0x02,       //������߱���
	ZLNET_IVA_BZS_TOUCH_WARNING_LING_MASK = 0x04,           //�����߱���
	ZLNET_IVA_BZS_NEG_TOUCH_WARNING_LINE_MASK= 0x08,        //�����߱���
	ZLNET_IVA_BZS_DOUBLE_WARNING_LINE_MASK = 0x10,			//�ܽ�˫�����߱���
	ZLNET_IVA_BZS_ENTER_AREA_WARNING_MASK = 0x20,			//�������򱨾�
	ZLNET_IVA_BZS_LEAVE_AREA_WARNING_MASK = 0x40,           //�뿪���򱨾�
	ZLNET_IVA_BZS_TOUCH_AREA_WARNING_MASK = 0x80,           //�������򱨾�
	ZLNET_IVA_BZS_LINGER_AREA_WARNING_MASK = 0x100,         //�������ǻ�����
	ZLNET_IVA_BZS_APPEAR_AREA_WARNING_MASK = 0x200,         //��������ֱ���
	ZLNET_IVA_BZS_DISAPPEAR_AREA_WARNING_MASK = 0x400,		//��������ʧ����
	ZLNET_IVA_BZS_OBJECT_STOLEN_MASK = 0x800,				//��Ʒ���Ʊ���
	ZLNET_IVA_BZS_CAMERA_NO_SIGNAL_MASK = 0x1000,           //����ͷ���ź�
	ZLNET_IVA_BZS_CAMERA_ABNORMAL_MASK = 0x2000,			//����ͷ�쳣����
}IVA_BZS_ALARM_ENABLE_MASK;

//������������ʹ��
typedef enum _ZLNET_IVA_FACE_ALARM_ENABLE_MASK
{
	ZLNET_IVA_FACE_CAPTURE_MASK = 0x01,						//�������񱨾�
	ZLNET_IVA_FACE_CAMERA_NO_SIGNAL_MASK = 0x02,			//����ͨ������ͷ���ź�
	ZLNET_IVA_PANORAMIC_CAMERA_NO_SIGNAL_MASK = 0x04,		//ȫ��ͨ������ͷ���ź�
} ZLNET_IVA_FACE_ALARM_ENABLE_MASK;

//��Ƶ�ϴ���Ϣ
#define ZLNET_IVA_AUDIO_UPLOAD_INFO_NUM	(ZLNET_IVA_ATMALARMTYPE_ATM_GPI - ZLNET_IVA_ATMALARMTYPE_ATM_DETECTAREA + ZLNET_IVA_MAX_CHANNEL)

//������Ϣ����
typedef enum _ZLNET_IVA_ALARMINFO_TYPE
{
	ZLNET_IVA_ALARMINFO_NULL = 0,
	ZLNET_IVA_ALARMINFO_PICTURE = 0x1,	//ͼƬ
	ZLNET_IVA_ALARMINFO_VIDEO = 0x2,	//��Ƶ
}ZLNET_IVA_ALARMINFO_TYPE;
//������Ƶ�����Ͷ���
typedef enum _ZLNET_IVA_ALARMVIDEOTYPE
{
	ZLNET_VIDEO_START = 1,			//��Ƶ����ʼ
	ZLNET_VIDEO_ALARM,				//��Ƶ��������
	ZLNET_VIDEO_STOP				//��Ƶ������
}ZLNET_IVA_ALARMVIDEOTYPE;


#define ZLNET_IVA_ATM_TOTAL		20	//ATM������������
//��������
typedef enum _ZLNET_IVA_AREA_TYPE
{
	ZLNET_IVA_AREA_NULL = -1,
	ZLNET_IVA_AREA_WARN = 0,				//��������	��
	ZLNET_IVA_AREA_KEYBOARD,				//��������
	ZLNET_IVA_AREA_CARDPORT,				//�忨������
	ZLNET_IVA_AREA_KEYMASK,					//����������
	ZLNET_IVA_AREA_HUMAN,					//��Ա����� ��
	ZLNET_IVA_AREA_FACEHUMAN,				//��������	����ұ�
	ZLNET_IVA_AREA_OBJSIZE,					//Ŀ������ (��С���ߴ�)
	ZLNET_IVA_AREA_SCREEN,					//��Ļ����	(ûʵ��)
	ZLNET_IVA_VEHICLE_DETECTION_AREA,		//�����������
	ZLNET_IVA_VEHICLES_PROHIBITED_AREA,		//������������
	ZLNET_IVA_DETECTION_LINE,				//����ͳ�Ƽ����
	ZLNET_IVA_BZS_PROCESS_REGION = 30,		//�ܽ紦������
	ZLNET_IVA_BZS_SHIELD_REGION,			//�ܽ���������
	ZLNET_IVA_BZS_CROSS_ONE_LINE_RULE,		//�ܽ絥�߼��
	ZLNET_IVA_BZS_CROSS_TWO_LINE_RULE,		//�ܽ�˫�߼��
	ZLNET_IVA_BZS_AREA_DETECT_RULE,			//�ܽ�������
	ZLNET_IVA_BZS_OBJECT_MOVE,				//�ܽ���Ƽ��
	ZLNET_IVA_SSB_HALL_PROCESS = 45,		//��������������
	ZLNET_IVA_SSB_HALL_WITHDRAWALS,			//������ȡ������
	ZLNET_IVA_SSB_HALL_SHIELD,				//��������������
	ZLNET_IVA_SSB_ROOM_PROCESS,				//�ӳ��䴦������
	ZLNET_IVA_SSB_ROOM_SHIELD,				//�ӳ�����������
	ZLNET_IVA_FACE_DETECT,					//�����������
	ZLNET_IVA_FACE_OVERLAY,					//������������
	ZLNET_IVA_FACE_SHIELD,							//������������ ԭ����һ
	ZLNET_IVA_AREA_RESERVED2,
	ZLNET_IVA_AREA_RESERVED3,
	ZLNET_IVA_AREA_TOTAL,
}ZLNET_IVA_AREA_TYPE;

//��Ƶ����ģʽ
typedef enum _ZLNET_IVA_VIDEOBLEND_MODE
{
	ZLNET_IVA_VIDEOBLEND_PREVIEW = 0x1,		//����Ԥ������
	ZLNET_IVA_VIDEOBLEND_PIC = 0x2,			//ץͼ����
	ZLNET_IVA_VIDEOBLEND_LOCAL = 0x4,		//�豸������Ƶ�������
	ZLNET_IVA_VIDEOBLEND_DEBUG = 0x8,		//�㷨����
	ZLNET_IVA_VIDEOBLEND_RULE = 0x10,       //����Ԥ�������
	ZLNET_IVA_VIDEOBLEND_INFO  = 0x20,      //����Ԥ��������
	ZLNET_IVA_VIDEOBLEND_TRACK = 0x40,      //����Ԥ�����ٿ���������
	ZLNET_IVA_VIDEOBLEND_OVERLAY = 0x80,    //�Ƿ������������
	ZLNET_IVA_TRACK_INFO = 0x100,			//���ٹ켣
}ZLNET_IVA_VIDEOBLEND_MODE;

//�����û���������
typedef enum _ZLNET_IVA_ONLINE_OPRATE
{
	ZLNET_IVA_ONLINE_NULL = 0,
	ZLNET_IVA_ONLINE_KICK,		//�߳�
	ZLNET_IVA_ONLINE_BLOCK,		//����
}ZLNET_IVA_ONLINE_OPRATE;

//���Ƽ���������
typedef enum _ZLNET_IVA_LICENSE_PLATE_TYPE
{	
	ZLNET_IVA_PLATEID_CONFIGFLAG_NONE = 0x0,				//������
	ZLNET_IVA_PLATEID_CONFIGFLAG_VCOMPRESS = 0x1,   		//��ֱ����ѹ�� 
	ZLNET_IVA_PLATEID_CONFIGFLAG_FIELDIMG = 0x2,   			//�Ƿ��ǳ�ͼ�� 
	ZLNET_IVA_PLATEID_CONFIGFLAG_OUTPUTSINGLEFRAME = 0x4,	//����ʶ�� 
	ZLNET_IVA_PLATEID_CONFIGFLAG_INDIVIDUA = 0x8,   		//���Ի�����ʶ�� 
	ZLNET_IVA_PLATEID_CONFIGFLAG_TWOROWYELLOW = 0x10,   	//˫�Ż�ɫ��ʶ�� 
	ZLNET_IVA_PLATEID_CONFIGFLAG_ARMPOLICE = 0x20,   		//˫�ž���ʶ�� 
	ZLNET_IVA_PLATEID_CONFIGFLAG_TWOROWARMY = 0x40,  		//ͬһ�����ͼ��ֻ���һ�����
	ZLNET_IVA_PLATEID_CONFIGFLAG_TRIGGE = 0x80,				//�Ƿ�ͬʱ���ͳ���ͼ��
} ZLNET_IVA_LICENSE_PLATE_TYPE;

//��������
typedef enum _ZLNET_IVA_PLATEID_DRIVE
{	
	ZLNET_IVA_PLATEID_DRIVE_NULL = 0x0,
	ZLNET_IVA_PLATEID_DRIVE_LEFT ,		//����			
	ZLNET_IVA_PLATEID_DRIVE_RIGHT ,		//����			
	ZLNET_IVA_PLATEID_DRIVE_UP ,		//����			
	ZLNET_IVA_PLATEID_DRIVE_DOWN ,		//����			
} ZLNET_IVA_PLATEID_DRIVE;

//������ʻ����
typedef enum _ZLNET_IVA_REVERSE_DRIVE_SET
{	
	ZLNET_IVA_EVERSE_DRIVE_NONE = 0x0,						
	ZLNET_IVA_EVERSE_DRIVE_LEFT = 0x1,   	//����	
	ZLNET_IVA_EVERSE_DRIVE_RIGHT = 0x2,   	//����	
	ZLNET_IVA_EVERSE_DRIVE_UP = 0x4,		//����	
	ZLNET_IVA_EVERSE_DRIVE_DOWN = 0x8,   	//����	
} ZLNET_IVA_REVERSE_DRIVE_SET;

//������ɫ
typedef enum _ZLNET_IVA_PLATEID_COLOR
{
	ZLNET_IVA_PLATEID_COLORUNKNOWN = 0,		//δ֪��ɫ
	ZLNET_IVA_PLATEID_COLORBLUE,			//��ɫ
	ZLNET_IVA_PLATEID_COLORYELLOW,			//��ɫ
	ZLNET_IVA_PLATEID_COLORWHITE,			//��ɫ
	ZLNET_IVA_PLATEID_COLORBLACK,			//��ɫ
	ZLNET_IVA_PLATEID_COLORGREEN,			//��ɫ
} ZLNET_IVA_PLATEID_COLOR;

//��������
typedef enum _ZLNET_IVA_PLATEID_TYPE
{
	ZLNET_IVA_PLATEID_TYPEUNKNOWN = 0,		//δ֪����
	ZLNET_IVA_PLATEID_TYPEBLUE,				//������
	ZLNET_IVA_PLATEID_TYPEBLACK,			//�ڳ���
	ZLNET_IVA_PLATEID_TYPEYELLOW,			//���Ż�ɫ����
	ZLNET_IVA_PLATEID_TYPEYELLOW2,			//˫�Ż�ɫ����
	ZLNET_IVA_PLATEID_TYPEPOLICE,			//��������
	ZLNET_IVA_PLATEID_TYPEARMPOL,			//��������
	ZLNET_IVA_PLATEID_TYPEINDIVI,			//���Ի�����
	ZLNET_IVA_PLATEID_TYPEARMY,				//���ž��ó���
	ZLNET_IVA_PLATEID_TYPEARMY2,			//˫�ž��ó���
	ZLNET_IVA_PLATEID_TYPEEMBASSY,			//��ʹ�ݳ���
	ZLNET_IVA_PLATEID_TYPEHONGKONG,			//��۳���
} ZLNET_IVA_PLATEID_TYPE;

//�ܽ��ֹ��������
typedef enum _ZLNET_IVA_BZS_AREA_ALARM_MASK
{
	ZLNET_IVA_BZS_AREA_ENTER 	  = 0x0001,		// ��������
	ZLNET_IVA_BZS_AREA_LEAVE 	  = 0x0002,		// �뿪����
	ZLNET_IVA_BZS_AREA_TOUCH_AREA = 0x0004,		// ��������
	ZLNET_IVA_BZS_AREA_OBJMOVE 	  = 0x0008,		// ����
	ZLNET_IVA_BZS_AREA_LINGER	  = 0x0010,		// �ǻ�
	ZLNET_IVA_BZS_AREA_APPEAR	  = 0x0020,		// ����
	ZLNET_IVA_BZS_AREA_DISAPPEAR  = 0x0040		// ��ʧ
} ZLNET_IVA_BZS_AREA_ALARM_MASK;

//�ܽ絥��ʹ��
typedef enum _ZLNET_IVA_BZS_CROSS_LINE_MASK
{
	ZLNET_IVA_BZS_CROSS_ONEWAY = 0x0001,		// �������
	ZLNET_IVA_BZS_CROSS_TWOWAY	= 0x0002,		// �������
	ZLNET_IVA_BZS_TOUCHLINE_ONEWAY = 0x0004,	// ������
	ZLNET_IVA_BZS_TOUCHLINE_TWOWAY = 0x0008 	// ������
} ZLNET_IVA_BZS_CROSS_LINE_MASK;	

//������������
typedef enum _ZLNET_IVA_BACKGROUND_UPDATE_MASK 
{
	ZLNET_IVA_ATM_MASK= 0x1,			//ATM 0-���� 1-����
	ZLNET_IVA_PLATEID_MASK = 0x2,		//���� 0-���� 1-����
	ZLNET_IVA_STAFFCOUNT_MASK = 0x4,	//��ͷ���� 0-���� 1-����
	ZLNET_IVA_SSB_MASK = 0x8,			//�������� 0-���� 1-����
	ZLNET_IVA_BZS_MASK = 0x10,			//�ܽ� 0-���� 1-����
} ZLNET_IVA_BACKGROUND_UPDATE_MASK;

//��ͷ����ͨ��
typedef enum _ZLNET_IVA_STAFF_COUNT_CHANNEL
{
	ZLNET_IVA_STAFFCOUNT_ANALYSIS_CH = -1,//������ǰ��һ·�豸
	ZLNET_IVA_STAFFCOUNT_ANALYSIS_CH1 = 0,
	ZLNET_IVA_STAFFCOUNT_ANALYSIS_CH2,
	ZLNET_IVA_STAFFCOUNT_ANALYSIS_CH3,
	ZLNET_IVA_STAFFCOUNT_ANALYSIS_CH4,
} ZLNET_IVA_STAFF_COUNT_CHANNEL;

//��������ģʽ
typedef enum _ZLNET_IVA_FACE_CAPTURE_MODE
{
	ZLNET_IVA_FACE_CAPTURE = 0,		//ץ��ģʽ
	ZLNET_IVA_FACE_THAN,			//�ȶ�ģʽ
} ZLNET_IVA_FACE_CAPTURE_MODE;

//��������ģʽ
typedef enum _ZLNET_IVA_FACE_OVERLAY_MODE
{
	ZLNET_IVA_FACE_NO_OVERLAY = 0,		//������
	ZLNET_IVA_FACE_OVERLAY_FACE,		//��������
	ZLNET_IVA_FACE_OVERLAY_FACE_VIDEO,	//����������Ƶ
} ZLNET_IVA_FACE_OVERLAY_MODE;

typedef struct _ZLNET_ALARMRECT
{
	int left ;
	int top ;
	int right ;
	int bottom ;
} ZLNET_ALARMRECT;

//ʱ��ṹ															    
typedef struct _ZLNET_IVA_TIME
{
	int tm_year;    
	int tm_mon;     // [0,11] 
	int tm_mday;    // [1,31] 
	int tm_hour;    // [0,23] 
	int tm_min;     // [0,59] 
	int tm_sec;     // [0,59] 
}ZLNET_IVA_TIME;

//������
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
	int		nConfidence;	// ��������
	int		nTrackID;	// ׷��ID
} ZLNET_IVA_RECTINFO;

//����ṹ
typedef struct  _ZLNET_IVA_MONITORREGION
{
	unsigned int point[ZLNET_IVA_MAX_POLYGON_POINT];//����ε�����(��16λΪY, ��16λΪX)
	short		 pointNum;							//��Ч����
	ZLNET_IVA_AREA_TYPE	 regionType;				//��������
} ZLNET_IVA_MONITORREGION;

//��Ƶͨ��ģʽ����
 typedef struct _ZLNET_IVA_CHANNEL_CONFIG
 {
 	int		size;					
	ZLNET_IVA_VIDEOBLEND_MODE  blendMode[ZLNET_IVA_MAX_CHANNEL];	//��Ƶ����ģʽ
	int		videoMode[ZLNET_IVA_MAX_CHANNEL];				//�߼�ͨ��������ͨ����ӳ���ϵ(�Ѳ���)
	int		asscEnabel[ZLNET_IVA_MAX_CHANNEL/2];			//��������ʹ��
	int		faceCompare[ZLNET_IVA_MAX_CHANNEL/2];			//���������Ա�
	int videoPinMode;										//ģ����Ƶͨ���������
 }ZLNET_IVA_CHANNEL_CONFIG;

 //������ϢͼƬ
 typedef struct _ZLNET_IVA_ALARMINFO_PIC
 {
	 unsigned int		picMode;	//0:ʵʱͼƬ 1��Ԥ¼ͼƬ
	 unsigned int		logicChn;	//�߼�ͨ����				
	 unsigned int		dataLen;	//���ݳ���
	 unsigned char		*data;		//����
 } ZLNET_IVA_ALARMINFO_PIC;

 //���ܱ������ò���
 typedef struct _ZLNET_IVA_EVENT
 {
	 DWORD 	  id;            // ��־ID
	 ZLNET_DEVTIME  time;    // ����
	 WORD      alarmType;    // ��������(SSB�������ͺ�ATM��������)
	 BYTE      logicChn;     // ����������ͨ��
	 BYTE      picNum;   	 // ͼƬ����
	 ZLNET_DEVTIME	  stTime;       //����¼��ʼʱ��
	 ZLNET_DEVTIME    endTime;      //����¼�����ʱ��
	 DWORD			driveno;		// ���̺�(���豸, ���̺ź���ʼ�غŶ�Ϊ0)
	 DWORD			startcluster;	// ��ʼ�غ�
	 BYTE      reserve[8];  //����
 }ZLNET_IVA_EVENT;

//ATM�����¼���ϸ��Ϣ
typedef struct _ZLNET_IVA_ATM_DETAIL
{
	DWORD 			rectValidNum;
	ZLNET_IVA_RECTINFO  rect[ZLNET_IVA_MAX_NUM_ATMALARM_RECT];     // ����
	BYTE		    reserve[16];  //����
}ZLNET_IVA_ATM_DETAIL;

//ATM�����ϴ���־+������Ϣ+ͼƬ
typedef struct _ZLNET_IVA_ALARMINFO
{
	DWORD     	size; 	 //�ṹ���С
	ZLNET_IVA_EVENT      IVSEvent;  //������Ϣ
	ZLNET_IVA_ATM_DETAIL IVSDetail; //��ϸ��Ϣ
	ZLNET_IVA_ALARMINFO_PIC pic[ZLNET_IVA_MAX_CHANNEL*2];	// ͼƬ����
}ZLNET_IVA_ATM_ALARMINFO;


//����ͳ�Ʊ�����Ϣ
typedef struct _ZLNET_IVA_HDCTRECT
{
	ZLNET_IVA_HDCTTYPE   type ;
	ZLNET_RECT  rect;
	int    nReserved[4];
} ZLNET_IVA_HDCRECT; 

//����������������
typedef struct _ZLNET_IVA_ALARM_ASSCONFIG
{
	int		size;			
	int 	bVoice;					//������ʾ
	int		bAlarmOutEn;			//�������
	int		dwAlarmOut;				//�������ͨ������ 
	int		iAOLatch;				//���������ʱ
	int 	iRecLatch;				//����¼����ʱ
	unsigned char asschn[ZLNET_IVA_MAX_CHANNEL];//����ͨ������������ֵΪ������Ϣ����(ZLNET_IVA_ALARMINFO_TYPE)���
	int		bFtp;					//�Ƿ��ϴ�FTP
	int		bEmail;					//�Ƿ��ϴ�Emil
}ZLNET_IVA_ALARM_ASSCONFIG;

//�ⲿ��������
typedef struct _ZLNET_IVA_GPI_ASSCONFIG
{
	int		enable;					//ʹ��
	int     polarity;				//����
	ZLNET_IVA_ALARM_ASSCONFIG	assc;	//������ 
}ZLNET_IVA_GPI_ASSCONFIG;

//����¼�����ò���
typedef struct _ZLNET_IVA_ALARM_RECORD
{
	short		pretime;			//����ǰ¼��ʱ��(��)
	short		aftertime;			//������¼��ʱ��(��)
}ZLNET_IVA_ALARM_RECORD;

//����ʱ���
typedef struct _ZLNET_IVA_WEEK_SECTION
{
	ZLNET_TSECT	sec[ZLNET_N_WEEKS][ZLNET_N_REC_TSECT];	//ʱ���
}ZLNET_IVA_WEEK_SECTION;

//��������Ϣ	
typedef struct _ZLNET_IVA_WORKSHEET
{
	int					nInterval;	//��Ƶ���ż��
	ZLNET_IVA_WEEK_SECTION	chnR;	//ʱ���
}ZLNET_IVA_WORKSHEET;

//��������
typedef struct _ZLNET_IVA_NET_CFG
{
	ZLNET_ETHERNET			stEtherNet[ZLNET_MAX_ETHERNET_NUM];	// ��̫����
	ZLNET_DNS_DEV_CFG		stDNS;								// DNS������
	ZLNET_REMOTE_HOST		stPppoeServer;						// PPPoE������
	ZLNET_NTP_DEV_CFG		stNTP;								// NTP������
	int						nTcpPort;							// TCP֡���˿�
}ZLNET_IVA_NET_CFG;

//��������ṹ
typedef struct _ZLNET_IVA_ATM_FACEAREA
{
	int			maxsize;				//����������
	int			minsize;				//�����С����		
	int			left;
	int			top;
	int			right;
	int			bottom;
}ZLNET_IVA_ATM_FACEAREA;

//�����������
typedef struct _ZLNET_IVA_ATM_ALARMAREA_FACE
{
	int			size;	
	int			logicChn;					//�߼�ͨ����
	int			faceAreaNum;				//��Ч������
	ZLNET_IVA_ATM_FACEAREA	faceArea[ZLNET_IVA_MAX_NUM_FACE_AREA];
}ZLNET_IVA_ATM_ALARMAREA_FACE;


//ATM�������
typedef struct _ZLNET_IVA_ATM_DETECTAREA
{
	int			size;	
	int			logicChn;							//�߼�ͨ����
	int			alarmAreaNum;
	ZLNET_IVA_MONITORREGION detectArea[ZLNET_IVA_ATM_TOTAL];	//��������
}ZLNET_IVA_ATM_DETECTAREA;


//ATM���ò���
typedef struct _ZLNET_IVA_ATM_PARAM
{
	int			size;	
	int			waittime;				//�ȴ�����ʱ��
	int 		updatebk;				//���±���ʱ��
	int			camerablocked;			//����ͷ�ڵ�����ʱ��
	int 		atmcamerathreold;		//ATM����ͷ�ڵ���ֵ
	int			operatorlong;			//��ʱ�䲻����ʱ��
}ZLNET_IVA_ATM_PARAM;

//ATM�쳣������������
typedef struct _ZLNET_IVA_ATM_ARNORMAL_FACE_PARAM
{
	int			size;	
	int			enable;					//ʹ��
	int 		holdtime;				//�ڵ�����ʱ��
	int			tracktime;				//������ʱ��
	int			forebg;					//ǰ����С���زֵ
	int			tagminarea;				//������С�����ֵ
	int 		stillperfect;			//��ȫ��ֹʱ�䷧ֵ
	int			stillness;				//�˾�ֹ�������ʱ�䷧ֵ
	int			face;					//������ֵⷧ
	int 		facedetect;				//�����������ϵ��
	int 		alarm;					//��������
	int			score;					//������ֵ
}ZLNET_IVA_ATM_ARNORMAL_FACE_PARAM;

//��Ƶ��ɫ�ṹ
typedef struct tagVIDEOCOLOR
{
	ZLNET_COLOR_CFG		dstColor;       // ������ɫ����
	int					iEnable;        //ʱ���ʹ��
	int					Res[5];         //Ԥ��
}ZLNET_IVA_VIDEOCOLOR;
//ATM������Ƶ��ɫ����
#define N_COLOR_SECTION 2
typedef struct tagCONFIG_VIDEOCOLOR
{
	ZLNET_IVA_VIDEOCOLOR dstVideoColor[N_COLOR_SECTION];//��Ƶ��ɫ�ṹ
}ZLNET_IVA_ATM_CONFIG_VIDEOCOLOR;


// ATM������ѯ��־
typedef struct _ZLNET_IVA_ATM_LOG
{
	DWORD     	size; 	 //�ṹ���С
	ZLNET_IVA_EVENT      IVSEvent;  //������Ϣ
	ZLNET_IVA_ATM_DETAIL IVSDetail; //��ϸ��Ϣ
} ZLNET_IVA_ATM_LOG, *LPZLNET_IVA_ATM_LOG;

//���ܱ���ʹ��
typedef struct _ZLNET_IVA_ALARM_ENABLE 
{
	int		size;
	int     nType;			//�豸����
	int     nSubType;
	int 	nAlarmEnable;	//ATM��λ�ο�ZLNET_IVA_ATM_ALARM_ENABLE_MASK �ܽ�ο�ZLNET_IVA_BZS_ALARM_ENABLE_MASK �������вο�ZLNET_IVA_SSB_ALARM_ENABLE_MASK �����ο�ZLNET_IVA_FACE_ALARM_ENABLE_MASK
}ZLNET_IVA_ALARM_ENABLE;

typedef struct _ZLNET_IVA_DEV_INFO
{	
	char	szDevSerialNo[ZLNET_DEV_SERIALNO_LEN];	//���к�
	char	szSoftWareVersion[ZLNET_VER_SOFTWARE];	//����汾��
	DWORD		dwSoftwareBuildDate;				//���BUILD
	BYTE		byVideoCaptureNum;					//��Ƶ��In����
	BYTE		byVideoOutNum;						//��Ƶ��Out����
	BYTE		byAudioCaptureNum;					//��Ƶ��In����
	BYTE		byAudioOutNum;						//��Ƶ��Out����
	BYTE		byAlarmInNum;						//����In����
	BYTE		byAlarmOutNum;						//����Out����
	BYTE		byTalkInChanNum;					//�Խ���In����
	BYTE		byTalkOutChanNum;					//�Խ���Out����
	BYTE		byNetIONum;							//�������
	BYTE		byComIONum;							//��������
	BYTE		byLPTIONum;							//��������	
	BYTE		byVideoStandard;					//��Ƶ��ʽ:0-PAL,1-NTSC
}ZLNET_IVA_DEV_INFO;

// �Զ�ά������
typedef struct _ZLNET_IVA_AUTOMAINTAIN
{
	BYTE				byAutoRebootDay;		// �Զ�������0���Ӳ�, 1��ÿ�죬2��ÿ�����գ�3��ÿ����һ��......
	BYTE				byAutoRebootTime;		// 0��0:00��1��1:00��......23��23:00
} ZLNET_IVA_AUTOMAINTAIN;

// ע��IP��������
typedef struct _ZLNET_IVA_REGISTIP
{
	char				ip[ZLNET_MAX_IPADDR_LEN];				// IP
	int					port;									// �˿�
	char				domainName[ZLNET_MAX_DOMAIN_NAME_LEN];	// dvr����
}ZLNET_IVA_REGISTIP;

// ע��IP���������б�
typedef struct _ZLNET_IVA_CENTER_HOSTIP_LIST
{
	int validNum;		//��Ч����
	ZLNET_IVA_REGISTIP hostIP[ZLNET_IVA_MAX_REGIST_NUM];
}ZLNET_IVA_REGISTIP_LIST;

// �����û���Ϣ
typedef struct _ZLNET_IVA_USER_ONLINE
{
	int				id;
	char				ip[ZLNET_MAX_IPADDR_LEN];		// IP
	char				name[ZLNET_USER_NAME_LENGTH_EX];	// �û�����
}ZLNET_IVA_USER_ONLINE;

// �����û���Ϣ�б�
typedef struct _ZLNET_IVA_USER_ONLINE_LIST
{
	int			validNum;		//��Ч����
	ZLNET_IVA_ONLINE_OPRATE  opt;							// ��������
	int				blockTime;							// ����ʱ�䣨����������ΪZLNET_IVA_ONLINE_BLOCK��ʱ����Ч��
	ZLNET_IVA_USER_ONLINE online[ZLNET_IVA_MAX_ONLINE];
}ZLNET_IVA_USER_ONLINE_LIST;

// �����豸�ϴ���Ϣ
typedef struct  _ZLNET_IVA_ZLNET_IVA_UPLOAD
{
	char				szDomainName[ZLNET_MAX_DOMAIN_NAME_LEN];	// �豸����
	char				szIP[ZLNET_MAX_IPADDR_LEN];				// �豸IP��ַ
	int					nPort;									//�豸�˿ں�
	char				szSerial[ZLNET_DEV_SERIALNO_LEN];		//�豸���к�
	char				szOccurTime[ZLNET_ALARM_OCCUR_TIME_LEN];	//�ϴ�ʱ��
}ZLNET_IVA_ZLNET_IVA_UPLOAD;

//ATM�㷨����
typedef struct _ZLNET_IVA_ARITHMETIC_DEBUG_ITEM
{
	int		size;			//�ṹ���С
	BOOL	bDebugInfo;		//������Ϣ
	BOOL	bTargetFrame;	//Ŀ���
	BOOL	bRuleFrame;		//�����
}ZLNET_IVA_ARITHMETIC_DEBUG_ITEM;

//�㷨����
typedef struct _ZLNET_IVA_ARITHMETIC_DEBUG
{
	ZLNET_IVA_ARITHMETIC_DEBUG_ITEM arithDebug[ZLNET_IVA_ARITHMETIC_DEBUG_LEN];
}ZLNET_IVA_ARITHMETIC_DEBUG;

//����OSD
typedef struct _ZLNET_IVA_OSD_CONFIG
{
	int		size;
	BOOL bTimeDisplay[ZLNET_IVA_MAX_CHANNEL];						//�Ƿ���ʾʱ��OSD������ͨ��Ϊ׼
	BOOL bChannelDisplay[ZLNET_IVA_MAX_CHANNEL];						//�Ƿ���ʾͨ��OSD������ͨ��Ϊ׼
	char szChannelName[ZLNET_IVA_MAX_CHANNEL][ZLNET_CHAN_NAME_LEN];	//ͨ�����ƣ�����ͨ��Ϊ׼
}ZLNET_IVA_OSD_CONFIG;

//��Ƶ�ϴ���Ϣ
typedef struct _AUDIO_UPLOAD_INFO
{
	ZLNET_IVA_ALARM_TYPE atmAlarmType;	//ATM��������
	int					channel;		//ͨ����
}ZLNET_AUDIO_UPLOAD_INFO;

//��Ƶ�ϴ���Ϣ�б�
typedef struct _ZLNET_IVA_AUDIO_UPLOAD_INFO 
{
	int nCount;
	ZLNET_AUDIO_UPLOAD_INFO pAudioInfo[ZLNET_IVA_AUDIO_UPLOAD_INFO_NUM];
}ZLNET_IVA_AUDIO_UPLOAD_INFO;
//������Ƶ��������
typedef struct _ZLNET_IVA_ALARM_DEBUG
{
	int		nATMWarns;       //�Ѿ�����������
	int		nATMBlocks;      //����������
	int		nProbeBlocks;    //������������
	int		nFaceTrackID;    //������������ID
	char	bATMProbe;		 //������Ƶ�м�⵽��Ա
	char	bATMMoving;      //�����Ƶ�м�⵽��Ա
	char	bATMHands;       //��Ա����ATM��
}ZLNET_IVA_ALARM_DEBUG;


//�����������ͳ�����������
typedef struct _ZLNET_IVA_REGION
{
	int			size;	
	int			areaNum;									//��Ч������
	ZLNET_IVA_MONITORREGION detectArea[ZLNET_IVA_MAX_NUM_LICENSE_PLATE];	//��������
}ZLNET_IVA_REGION;

//OSD���Ʋ�������
typedef struct _ZLNET_IVA_OSD_LICENSE_PALTE_PARAM
{
	int			size;						//�ṹ���С
	int			superimposedType;			//���ӷ�ʽ
	int			superimposedX;				//��������x(����)
	int			superimposedY;				//��������Y(����)
	int			superimposedSize;			//������ʾ�ߴ�
	int			superimposedTime;			//����ͣ��ʱ��
}ZLNET_IVA_OSD_LICENSE_PALTE_PARAM;

//���Ʋ�������
typedef struct _ZLNET_IVA_PLATEID_PARAM
{
	int			size;						//�ṹ���С
	int			IVSPlateIDSpringType;		//����ģʽ   0  ��Ƶģʽ  1  ����ģʽ
	int			nMinPlateWidth;				//������С���ƿ�ȣ�������Ϊ��λ
	int			nMaxPlateWidth;				//��������ƿ�ȣ�������Ϊ��λ
	int		    nConfigFlag;				//���Ƽ������,��λ�μ�ZLNET_IVA_LICENSE_PLATE_TYPE
	int			nLocalProvince[3];			//��ʡ��������
	float		fSlantAngle;				//��б�Ƕ�
}ZLNET_IVA_PLATEID_PARAM;

//���Ʊ����ϴ�(��־+����)
typedef struct _ZLNET_IVA_PLATEID_DETAIL
{
	BOOL		bAlarm;			//�����Ƿ�����
	char		byLicense[16];	//���ƺ��ַ���ʽ��ʾ
	unsigned char		byCharScore[16];//ÿ�����ƺŵķ���
	ZLNET_ALARMRECT           rcCharPos[16];	//ÿ���ַ���λ��
	int			nCharNum;				//�����ַ���				
	ZLNET_IVA_PLATEID_COLOR		nColor;			//������ɫ
	ZLNET_IVA_PLATEID_TYPE			nType;		//��������
	int			nConfidence;	//���Ƽ�����
	int			nBright;		//����
	ZLNET_IVA_PLATEID_DRIVE			nDirection;	//��������
	ZLNET_IVA_AREA_TYPE	nWhy;		//����������� 0�������� 8:����������� 9:������������
	ZLNET_ALARMRECT   rcLocation;	//����λ��
	char		res[16];
} ZLNET_IVA_PLATEID_DETAIL;

//���Ʊ����ϴ���־+������Ϣ
typedef struct _ZLNET_IVA_PLATEID_ALARMINFO
{
	DWORD     	size; 	 //�ṹ���С
	ZLNET_IVA_EVENT      IVSEvent;  //������Ϣ
	ZLNET_IVA_PLATEID_DETAIL IVSDetail; //��ϸ��Ϣ
	ZLNET_IVA_ALARMINFO_PIC pic[ZLNET_IVA_MAX_CHANNEL*2];	// ͼƬ����
}ZLNET_IVA_PLATEID_ALARMINFO;

//���Ʋ�ѯ��־
typedef struct _ZLNET_IVA_PLATEID_LOG
{
	DWORD     	size; 	 //�ṹ���С
	ZLNET_IVA_EVENT      IVSEvent;  //������Ϣ
	ZLNET_IVA_PLATEID_DETAIL IVSDetail; //��ϸ��Ϣ
} ZLNET_IVA_PLATEID_LOG ;

typedef enum _ZLNET_HDCTTYPE
{
	HDCT_IN = 0 ,
	HDCT_OUT
}ZLNET_HDCTTYPE; 
//������ʻ����
typedef struct _ZLNET_IVA_PLATEID_ALARM
{
	int		size;							//�ṹ���С
	int		nEnable;						//����ʹ��
	int		nDirection;						//������������,��λ�ο�ZLNET_IVA_REVERSE_DRIVE_SET
	int		nMinScore;						//�����ϴ���С����
}ZLNET_IVA_PLATEID_ALARM;

//����ͳ�Ʊ�����Ϣ
typedef struct _ZLNET_HDCTRECT
{
	ZLNET_HDCTTYPE   type ;
	ZLNET_ALARMRECT  rect;
	int    nReserved[4];
} ZLNET_HDCRECT; 

//��Աͳ�����ò���
typedef struct _ZLNET_IVA_STAFF_COUNT_CONFIG
{
	int			size;						//�ṹ���С
	int			nWidth;                     //���������
	int			nHeight;                    //�������߶�
	int			nObjWidth;                  //�����
	ZLNET_IVA_POINT	ptStart;				    //������ʼ��
	ZLNET_IVA_POINT	ptEnd;						//�����յ�
	ZLNET_IVA_POINT	ptDirection;				//�����
	int			nPassFrames;				//Ŀ���˶��ٶ�
	int			nMutiObjWidth;				//��Ŀ����
	int			nMutiObjWidthEdge;         	//��Ե���
	int			nThreshBackDiff;			//��������ֵ
	int			nThreshFrameDiff;			//֡�����ֵ
	int			bStartPtLabel;              //Start������
	int			bEndPtLabel;                //End������
	int			nHalfObjW;                  //���ƿ��
} ZLNET_IVA_STAFF_COUNT_CONFIG;

//��Աͳ����ϸ��Ϣ
typedef struct _ZLNET_IVA_STAFFCOUNT_DETAIL
{
	int 			numRegion;     //�������
	ZLNET_IVA_HDCRECT	 		region[20] ;   //������Ϣ
	unsigned int 	totalInCount ;		//���豸��������ǰʱ���ܹ����������
	unsigned int 	totalOutCount ;		//���豸��������ǰʱ���ܹ��뿪������  
	int 			flag;   			// ��ǣ�����豸���㷨�������ñ�ǽ������仯,-1��ʾ�ò�����Ч
	int     		nInCount; 	 //��������
	int     		nOutCount; 	 //�뿪����
	int 			reserve[14];
} ZLNET_IVA_STAFFCOUNT_DETAIL ;

//��Աͳ����־��Ϣ
typedef struct _ZLNET_IVA_STAFFCOUNT_LOG
{
	DWORD     	size; 	 //�ṹ���С
	ZLNET_IVA_EVENT      IVSEvent;  //������Ϣ
	ZLNET_IVA_STAFFCOUNT_DETAIL IVSDetail; //��ϸ��Ϣ
} ZLNET_IVA_STAFFCOUNT_LOG ;

//��Աͳ���ϴ���־+������Ϣ+ͼƬ
typedef struct _ZLNET_IVA_STAFFCOUNT
{
	DWORD     	size; 	 //�ṹ���С
	ZLNET_IVA_EVENT      IVSEvent;  //������Ϣ
	ZLNET_IVA_STAFFCOUNT_DETAIL IVSDetail; //��ϸ��Ϣ
	ZLNET_IVA_ALARMINFO_PIC pic[ZLNET_IVA_MAX_CHANNEL*2];	// ͼƬ����
}ZLNET_IVA_ALARMINFO_STAFFCOUNT;

//����ͳ���㷨���Խṹ��
typedef struct _ZLNET_IVA_STAFF_ARITH_DEBUG 
{
	int			numRegion;     //�������
	ZLNET_IVA_HDCRECT    region[20] ;   //������Ϣ
	int     	nInCount; 	 //��������
	int     	nOutCount; 	 //�뿪����
}ZLNET_IVA_STAFF_ARITH_DEBUG;

//����ͳ�ƶ��˱�������
typedef struct _ZLNET_IVA_STAFF_MULTIUSERPARAM 
{
	int  nSize;
	int  nNum;        //���˱�������
	int  nReserved[8];
}ZLNET_IVA_STAFF_MULTIUSERPARAM;

//�ܽ������������

//�㷨����
typedef struct _ZLNET_IVA_BZS_REGION
{
	int			size;	
	int			areaNum;										//��Ч������
	ZLNET_IVA_MONITORREGION detectArea[ZLNET_IVA_MAX_BZS_PROCESS_NUM];	//��������
}ZLNET_IVA_BZS_REGION;

//�㷨��������
typedef struct _ZLNET_IVA_BZS_BASIC_SETTIINGS
{
	int			 nSize;									//�ṹ���С
	int			 nWidth;								//���������
	int			 nHeight;								//�������߶�
	int 		 nForegroundTh;							//ǰ������ֵ

	ZLNET_IVA_BZS_REGION pPolygonNoProc;				//��������(1)

	int 		 nObjHeight;							//�߶ȱ��
	BOOL		 bImgTransform;							//�Ƿ�У��ͼ��
	float		 fTransformParam[9];					//У��ͼ�����
	float		 fTransformParamInv[9];					//У��ͼ��ת����
} ZLNET_IVA_BZS_BASIC_SETTIINGS;

//���ܲ�������

//�㷨��������
typedef struct _ZLNET_IVA_BZS_ALGORITHM_PARAM
{
	int	    nSize;							//�ṹ���С
	int		nCmd;							//0���� !0�����㷨

	/*������������*/
	int		nMinSizeWidthHeight;			//������С��Ⱥ͸߶�
	int		nMaxRectArea;					//�������������
	int		nMinForegroundArea;				//��Сռ��ǰ�����ص���
	int		nThresholdTime;					//�����೤ʱ�䱨��

	/*�ǻ���������*/
	int		nThresholdBlockCntLingering;	//�ܵ��ƶ�����
	int		nStayingFrameTh;				//�ܵĶ���ʱ��

	/*���˾ۼ���������*/
	int		nThresholdMultiPeoPersonCnt;	//��������
	int		nThresholdMultiPeoFGPercent;	//ǰ������ٷֱ�
	int		nWarningIntervalFrmsMultiPeo;	//���α������
	int		nThresholdMultiPeoFrmCnt;		//ȷ�ϱ�����ֵ

	/*�����˶����*/
	int		nTHresholdFastMove;				//�����ȣ�1~100��
	int		nWarningIntervalFrmsFastMove;	//���α������
} ZLNET_IVA_BZS_ALGORITHM_PARAM;

//������쳣��������
typedef struct _ZLNET_IVA_BZS_CAMERA_ABNORMAL_PARAM
{
	int		nSize;					//�ṹ���С
	BOOL	bDetectBright;			//�����쳣����
	BOOL	bDetectNoSignal;		//�źŶ�ʧ����
	BOOL	bDetectBlock;			//��Ƶ�ڵ�����
	BOOL	bDetectColor;			//ɫ���쳣����
	BOOL	bDetectBlur;			//����ģ������
	BOOL	bDetectNoise;			//ͼ����������

	int		nBrightSensitivity;		//�����쳣������
	int		nNoSignalSensitivity;	//�źŶ�ʧ������
	int		nBlockSensitivity;		//��Ƶ�ڵ�������
	int		nColorSensitivity;		//ɫ���쳣������
	int		nBlurSensitivity;		//����ģ��������
	int		nNoiseSensitivity;		//ͼ������������

	int		nAlarmDurationTh;		//��������ʱ����ֵ
	int  	nBrightTh;				//��ͷ�ڵ�������ֵ
} ZLNET_IVA_BZS_CAMERA_ABNORMAL_PARAM;

//������������
//���򼰵���
typedef struct _ZLNET_IVA_BZS_AREA_DETECT
{
	int					nSize;					// �ṹ���С
	BOOL				bEnable;				// ʹ��
	int					nSerial;				// �������
	int					nRegionMask;     		// �����������룬�ο�ZLNET_IVA_BZS_AREA_ALARM_MASK
	ZLNET_IVA_MONITORREGION  pynPos;			// ����λ��
	int					nFramesConfirmEnter;  	// ��������ʱ��
	int					nFramesConfirmLeave;	// �뿪����ʱ��
	int					nFramesConfirmTouch;	// ��������ʱ��
	int					nFramesConfirmObjMove;	// ���ƶ�����ʱ��
	int					nFramesConfirmLinger;	// �ǻ�ʱ��
	int					nFramesConfirmAppear;	// ����ʱ��
	int					nFramesConfirmDisappear;// ��ʧʱ��
	char			    chMemo[64];				// ��ע
} ZLNET_IVA_BZS_AREA_DETECT;

typedef struct _ZLNET_IVA_BZS_AREA_DETECT_PARAM
{
	int					nSize;					// �ṹ���С
	int				    nValidNum;				// ��Ч����
	ZLNET_IVA_BZS_AREA_DETECT areaDetect[ZLNET_IVA_MAX_BZS_RULE_REGION];
} ZLNET_IVA_BZS_AREA_DETECT_PARAM_PARAM;

//���߹���
typedef struct _ZLNET_IVA_BZS_CROSS_0NE_LINE
{
	int				  nSize;					// �ṹ���С
	BOOL			  bEnable;					// ʹ��
	int				  nSerial;					// �������
	int				  nLineMask;   				// ����ʹ�����룬�ο�ZLNET_IVA_BZS_CROSS_LINE_MASK
	ZLNET_IVA_POINT   ptStart;					// ������ʼ��
	ZLNET_IVA_POINT   ptEnd;					// �����յ�
	ZLNET_IVA_POINT   ptDriection;				// ���߷����(˫�������)
	int				  nFramesConfirmCrossOneWay;// �������ȷ��ʱ��
	int 		      nFramesConfirmCrossTwoWay;// ˫�����ʱ��
	int 			  nFramesConfirmTouchOneWay;// ������ʱ��
	int 			  nFramesConfirmTouchTwoWay;// ������ʱ��
	char			  chMemo[64];				// ��ע
} ZLNET_IVA_BZS_CROSS_0NE_LINE;

typedef struct _ZLNET_IVA_BZS_CROSS_0NE_LINE_PARAM
{
	int				  nSize;					// �ṹ���С
	int				  nValidNum;				// ��Ч����
	ZLNET_IVA_BZS_CROSS_0NE_LINE oneLine[ZLNET_IVA_MAX_BZS_RULE_REGION];
} ZLNET_IVA_BZS_CROSS_0NE_LINE_PARAM;

//˫�߹���
typedef struct _ZLNET_IVA_BZS_CROSS_TWO_LINE
{
	int				  nSize;					// �ṹ���С
	BOOL			  bEnable;					// ʹ��
	int				  nSerial;					// �������
	ZLNET_IVA_POINT   ptPredictStart;			// Ԥ��˫����ʼ��
	ZLNET_IVA_POINT   ptPredictEnd;				// Ԥ��˫���յ�
	ZLNET_IVA_POINT   ptPredictDirection;		// Ԥ�ⷽ���
	ZLNET_IVA_POINT   ptDecideStart;			// ȷ��˫����ʼ��
	ZLNET_IVA_POINT   ptDecideEnd;				// ȷ��˫���յ�	
	ZLNET_IVA_POINT   ptDecideDirection;		// ȷ��˫�����
	int				  nFramesConfirmClimb;		// ����ʱ��
	char			  chMemo[64];				// ��ע
} ZLNET_IVA_BZS_CROSS_TWO_LINE;

typedef struct _ZLNET_IVA_BZS_CROSS_TWO_LINE_PARAM
{
	int				  nSize;					// �ṹ���С
	int				  nValidNum;				// ��Ч����
	ZLNET_IVA_BZS_CROSS_TWO_LINE twoLine[ZLNET_IVA_MAX_BZS_RULE_REGION];
} ZLNET_IVA_BZS_CROSS_TWO_LINE_PARAM;

//��������

//����ṹ
typedef struct _ZLNET_IVA_SELF_BANK_REGION
{
	int			size;	
	int			areaNum;										//��Ч������
	ZLNET_IVA_MONITORREGION detectArea[ZLNET_IVA_MAX_SSB_AREA];	//��������
} ZLNET_IVA_SSB_REGION;

//��������������
typedef struct _ZLNET_IVA_SSB_HALL_FUNC
{
	int			 nSize;										//�ṹ���С
	int			 nWidth;									//���������
	int			 nHeight;									//�������߶�
	int 		 nForegroundTh;								//ǰ������ֵ
	ZLNET_IVA_SSB_REGION PolygonNoProc;						//��������(1) + ��������(9) + ��������(10)
	int 		 nObjHeight;								//�߶ȱ��
	BOOL		 bImgTransform;								//�Ƿ�У��ͼ��
	float		 fTransformParam[9];						//У��ͼ�����
	float		 fTransformParamInv[9];						//У��ͼ��ת����
} ZLNET_IVA_SSB_HALL_FUNC;

//�������쳣������
typedef struct _ZLNET_IVA_SSB_ABNORMAL_PARAM
{
	int         nSize;
	int			nCmd;					// 0������ 1���㷨����

	// ���������
	int   		nMinSizeWidthHeight;	//������С��С���߶Ȼ��߿�ȣ�
	int   		nMaxRectArea;			//�����������������
	int    		nMinForegroundArea;		//��Сռ��ǰ�����ص����
	int   		nThresholdTime;			//�����೤ʱ�䱨�����룩

	// �ǻ�����
	int     	nTotaolDisLingering;	//�ǻ��ƶ��ľ���
	int   		nTotalStayingTime;		//�ܵĶ���ʱ��
	int    		nTotalStayInterval;		//����ʱ��ļ��

	// ���˲���
	int			nGatherNum;				//�ۼ�����
	int			nWarningInterval;		//���ξۼ��ļ��ʱ��
	int			nTotalMultiPeoTime;		//�ܵľۼ�ʱ��

	// ��Ա���ز���
	int			nTotalFellTime;		    //�ܵĵ���ʱ��

	// β��ȡ��
	int			nStatAtmSideTime;	    //ͣ����ATM�����ĳ���ʱ��
	int			nIntervalAlarm;		    //���α����ļ��

	// ��ֹ����
	int			nInForbiddenAreaTime;   //�����ֹ����ĳ���ʱ��

	// ����¼��������
	int			nTotalFightingTime;	    //��ܳ���ʱ��
	int			nIntervalFighting;	    //���δ�ܱ������
	int			nFightThInFrame;		//֡���ж���������ֵ,ԽСԽ���ױ�100 (0-256)
	int			nFightThInFramePixel;   //ԽСԽ���ױ��������ȼ�2(1/2/3/4)
	BOOL		bBottomRule;		    //�Ƿ���õײ�Լ��������ͼ���·�Ϊ��������������Ĭ��Ϊ1
	BOOL		bHeightChangeRule;	    //�Ƿ���ø߶ȱ仯Լ����Ҫ������ĸ߶�������仯������������ͼ�񣬸�Լ����Ϊ0��Ĭ��Ϊ1
	int 		nFrameGrayChangeTh;	    //֡��仯�Ҷ���ֵ30(1-250)
	BOOL		bUnused;			    //0
	int			reserved[7];
} ZLNET_IVA_SSB_ABNORMAL_PARAM;

//����ͷ�쳣������
typedef struct _ZLNET_IVA_SSB_CAMERE_ABNORMAL
{
	int     nSize;					//������С
	BOOL	bDetectBright;			//�����쳣 ʹ��
	BOOL	bDetectNoSignal;		//�źŶ�ʧ ʹ��
	BOOL	bDetectBlock;			//��Ƶ�ڵ� ʹ��
	BOOL	bDetectColor;			//ɫ���쳣 ʹ��
	BOOL	bDetectBlur;			//����ģ�� ʹ��
	BOOL	bDetectNoise;			//ͼ������ ʹ��

	int		nBrightSensitivity;		//�����쳣 ������
	int		nNoSignalSensitivity;	//�źŶ�ʧ ������
	int		nBlockSensitivity;		//��Ƶ�ڵ� ������
	int		nColorSensitivity;		//ɫ���쳣 ������
	int		nBlurSensitivity;		//����ģ�� ������
	int		nNoiseSensitivity;		//ͼ������ ������

	int		nAlarmDurationTh;		//��������ʱ��
	int		nBrightTh;				//��ͷ�ڵ�������ֵ
} ZLNET_IVA_SSB_CAMERE_ABNORMAL;

//�ӳ����㷨����
typedef struct _ZLNET_IVA_SSB_ROOM_PARAM
{
	int			 nSize;					//�ṹ���С
	ZLNET_IVA_SSB_REGION PolygonNoProc;	//��������1�� + ��ֹ����9��
	int			 nThFg;				//ǰ����ֵ��15Ϊ�Ƽ�ֵ
	int			 nThArea;			//�ƶ�������ռ������İٷ�֮����25Ϊ�Ƽ�ֵ
	int			 nWarningInterval;  //���������15s*֡��Ϊ�Ƽ�ֵ
	int			 nNoProcess;		//��ֹ�������
} ZLNET_IVA_SSB_ROOM_PARAM;


//SSB�����¼���ϸ��Ϣ
typedef struct _ZLNET_IVA_SSB_DETAIL
{
	DWORD    alarmNo;	//�������
	ZLNET_IVA_RECTINFO   alarmRect[ZLNET_IVA_MAX_NUM_SSBALARM];     // ����
	BYTE      reserve[16];  //����
}ZLNET_IVA_SSB_DETAIL; //������Ϣ�ṹ��

//SSB������Ϣ
typedef struct _ZLNET_IVA_SSB_ALARMINFO
{
	DWORD         size;     //�ṹ���С
	ZLNET_IVA_EVENT      IVSEvent;  //������Ϣ
	ZLNET_IVA_SSB_DETAIL IVSDetail; //��ϸ��Ϣ
	ZLNET_IVA_ALARMINFO_PIC pic[ZLNET_IVA_MAX_CHANNEL*2];	// ͼƬ����
}ZLNET_IVA_SSB_ALARMINFO;

//BZS�����¼���ϸ��Ϣ
typedef struct _ZLNET_IVA_BZS_DETAIL
{
	DWORD    alarmNo;	//�������
	ZLNET_IVA_RECTINFO   alarmRect[8];     // ����
	char      strMemo[64];  //����˵��
}ZLNET_IVA_BZS_DETAIL; //������Ϣ�ṹ��

//BZS������Ϣ
typedef struct _ZLNET_IVA_BZS_ALARMINFO
{
	DWORD         size;     //�ṹ���С
	ZLNET_IVA_EVENT      IVSEvent;  //������Ϣ
	ZLNET_IVA_BZS_DETAIL IVSDetail; //��ϸ��Ϣ
	ZLNET_IVA_ALARMINFO_PIC pic[ZLNET_IVA_MAX_CHANNEL*2];	// ͼƬ����
}ZLNET_IVA_BZS_ALARMINFO;

//SSB��ѯ��־
typedef struct _ZLNET_IVA_SSB_LOG
{
	DWORD     	size; 	 //�ṹ���С
	ZLNET_IVA_EVENT      IVSEvent;  //������Ϣ
	ZLNET_IVA_SSB_DETAIL IVSDetail; //��ϸ��Ϣ
} ZLNET_IVA_SSB_LOG;

//BZS��ѯ��־ 
typedef struct _ZLNET_IVA_BZS_LOG
{
	DWORD     	size; 	 //�ṹ���С
	ZLNET_IVA_EVENT      IVSEvent;  //������Ϣ
	ZLNET_IVA_BZS_DETAIL IVSDetail; //��ϸ��Ϣ
} ZLNET_IVA_BZS_LOG;

//SSB������Ϣ�Ľṹ�壺���Ե��Ӹ��ٿ�
typedef struct _ZLNET_IVA_SSB_TRACKEDINFO
{
	ZLNET_ALARMRECT rcObjectPos;	//����һ֡�У����������λ�ã����Σ�left,right,top,buttom��
	int				nTrackID;		//��������ID
	int				nType;			// 0:��ʧ 1:��ʾ
} ZLNET_IVA_SSB_TRACKEDINFO;

typedef struct _ZLNET_IVA_SSB_ARITH_DEBUG
{
	DWORD            DebugNo;
	ZLNET_IVA_SSB_TRACKEDINFO  DebugInfo[MAX_NUM_SSB_TRACKEDINFO];
} ZLNET_IVA_SSB_ARITH_DEBUG;

//BZS������Ϣ�Ľṹ�壺���Ե��Ӹ��ٿ�
typedef struct _ZLNET_IVA_BZS_TRACKEDINFO
{
	ZLNET_ALARMRECT rcObjectPos;	//����һ֡�У����������λ�ã����Σ�left,right,top,buttom��
	int				nTrackID;		//��������ID
	int				nType;			// 0:��ʧ 1:��ʾ
} ZLNET_IVA_BZS_TRACKEDINFO;

//BZS�㷨������Ϣ
typedef struct _ZLNET_IVA_BZS_ARITH_DEBUG
{
	DWORD            DebugNo;
	ZLNET_IVA_BZS_TRACKEDINFO  DebugInfo[MAX_NUM_SSB_TRACKEDINFO];
} ZLNET_IVA_BZS_ARITH_DEBUG;

//BZS�켣����Ԫ��
typedef struct _ZLNET_IVA_BZS_TRACK
{
	DWORD nTrackID;   //��������ID
	WORD  nPosX;	  //x����
	WORD  nPosY;	  //y����  ��nPosX��nPosY��Ϊ0��ʱ�����һ������켣���ٽ���
}ZLNET_IVA_BZS_TRACK; 

//BZS�켣����
typedef struct _ZLNET_IVA_BZS_TRACK_INFO
{
	DWORD  nTrackNum;                                  //��Ч����
	ZLNET_IVA_BZS_TRACK stTrackInfo[MAX_TRACK_COUNT];  //BZS�켣����Ԫ��
}ZLNET_IVA_BZS_TRACK_INFO;



//��������
typedef struct _ZLNET_IVA_RESTART_ALGORITHM
{
	int nSize;				//�ṹ���С
	int nBackgroundUpdate;	//�������������λ�ο�ZLNET_IVA_BACKGROUND_UPDATE_MASK
	int nReserved[2];		//����
} ZLNET_IVA_BACKGROUND_UPDATE;

//�豸������ȡ
typedef struct _ZLNET_DEVICE_ENABLE
{
	int nSize;
	char szDevType[ZLNET_DEV_TYPE_LEN];								//�豸����
	char szEn[ZLNET_DEVICE_ENABLE_NUM][ZLENT_DEVICE_ENABLE_STR_LEN];//��Ҫ����(֧��64��)
	DWORD dwEnMask[ZLNET_DEVICE_ENABLE_NUM];						//��Ҫ��������
	BYTE  bResverd[28];												//Ԥ��
} ZLNET_DEVICE_ENABLE;

//��������

//����
typedef struct _ZLNET_IVA_FACE_AREA
{
	int				nMinFace;	//�����С����
	int				nMaxFace;	//����������
	ZLNET_ALARMRECT	area;		//��������
} ZLNET_IVA_FACE_AREA;

//���������
typedef struct _ZLNET_IVA_FACE_TRACK_INFO
{
	ZLNET_ALARMRECT position;		//�������
	int				nConfidence;	//������������Խ�߻���Խ����
	int				nTrackID;		//���ID
} ZLNET_IVA_FACE_TRACK_INFO;

//���������¼���ϸ��Ϣ
typedef struct _ZLNET_IVA_FACE_DETAIL
{
	DWORD    alarmNo;	//�������
	ZLNET_IVA_FACE_TRACK_INFO   alarmRect[ZLNET_IVA_MAX_NUM_FACEALARM];     // ����
	BYTE      reserve[16];  //����
}ZLNET_IVA_FACE_DETAIL;

//���������¼�
typedef struct _ZLNET_IVA_FACE_ALARMINFO
{
	DWORD     	size; 	 //�ṹ���С
	ZLNET_IVA_EVENT      IVSEvent;  //������Ϣ
	ZLNET_IVA_FACE_DETAIL IVSDetail; //��ϸ��Ϣ
	ZLNET_IVA_ALARMINFO_PIC pic[ZLNET_IVA_MAX_CHANNEL*2];	// ͼƬ����
} ZLNET_IVA_FACE_ALARMINFO ;

//����������־��Ϣ
typedef struct _ZLNET_IVA_FACE_LOG
{
	DWORD     	size; 	 //�ṹ���С
	ZLNET_IVA_EVENT      IVSEvent;  //������Ϣ
	ZLNET_IVA_FACE_DETAIL IVSDetail; //��ϸ��Ϣ
} ZLNET_IVA_FACE_LOG ;

//����������
typedef struct _ZLNET_IVA_FACE_AREA_PARAM
{
	int					nSize;		//��С
	int					nValidNum;	//��Ч����
	ZLNET_IVA_FACE_AREA faceArea[ZLNET_IVA_MAX_FACE_AREA_NUM];	//�������
	int                 nNoProcNum;                      //�����������
	ZLNET_ALARMRECT          noProcArea[ZLNET_IVA_MAX_FACE_SHIELDED_AREA_NUM];
} ZLNET_IVA_FACE_AREA_PARAM;

//����������
typedef struct _ZLNET_IVA_FACE_DETECT_PARAM
{
	int								nSize;			//��С
	int								nChannel;		//ͨ��
	int								nIntervalTime;	//ץ�ļ��
	ZLNET_IVA_FACE_CAPTURE_MODE		nModeType;		//����ģʽ �ο�ZLNET_IVA_FACE_CAPTURE_MODE
	int								nScore;        //�������ͷ���(���ڴ˷����Ľ���������ϴ�)
} ZLNET_IVA_FACE_DETECT_PARAM;

//�������Ӳ���
typedef struct _ZLNET_IVA_FACE_OVERLAY_PARAM
{
	int								nSize;			//��С
	int     						nChannel;       //ͨ��
	int								nOverlayTime;	//����ͣ��ʱ��
	ZLNET_IVA_FACE_OVERLAY_MODE		nOverlayMode;	//���ӷ�ʽ �ο�ZLNET_IVA_FACE_OVERLAY_MODE
	ZLNET_ALARMRECT					position;		//��������
} ZLNET_IVA_FACE_OVERLAY_PARAM;

//�����㷨���Խṹ��
typedef struct _ZLNET_IVA_FACE_ARITH_DEBUG
{
	DWORD		nTrackInfo;		//����
	ZLNET_IVA_FACE_TRACK_INFO trackInfo[ZLNET_IVA_MAX_NUM_FACE_TRACKEDINFO]; //���Խ��
} ZLNET_IVA_FACE_ARITH_DEBUG;

// DVR��������
//����������������Ϣ
typedef struct 
{
	char	ip[ZLNET_MAX_DOMAIN_NAME_LEN];		//���ӵķ�������ַ
	int		port;			//�������˿�
	long	linkcount;		//���Ӵ��� 0: �Ͽ� 0xffffffff: һֱ����, ֱ���ɹ�Ϊֹ
	int		res[20];		//Ԥ��
}ZLNET_REV_LINK_INFO;

// ������������Ϣ
typedef struct
{
	int		validcount;		//��Ч����
	ZLNET_REV_LINK_INFO		info[ZLNET_MAX_REV_LIST - 1];//������Ϣ
	int		res[20];		//Ԥ��
}ZLNET_REV_LINK;

// �豸֪ͨ��Ϣ
typedef struct
{
	char	ip[ZLNET_MAX_DOMAIN_NAME_LEN];	//���ӵķ�������ַ
	int     port;			//�˿ں�
	int		ret;			//���ӷ��ؽ�� 0:�ɹ� -1:�����������Ӵ��� -2:�豸�Ͽ� -3:�豸���Ӵﵽ���ֵ
	int		res[20];		//Ԥ��
}ZLNET_REV_LINK_RET;

//IPCP��ϸ��Ϣ
typedef struct
{
	int		nChn;		//ͨ������
	char*	szSerial;	//���к�
	char*	szUserName;	//IPCP �û���
	char*	szPWD;		//IPCP ����
}ZLNET_EXTERN_INFO;

/************************************************************************
 ** �ص���������
 ***********************************************************************/

//�����ص�
typedef int (CALLBACK *fZLIDVRHeatBeat)( int loginHandle, const char* ip, const char* serial, unsigned long userData);

// �������ӶϿ��ص�����ԭ��
typedef void (CALLBACK *fZLDisConnect)(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser);

// �������ӻָ��ص�����ԭ��
typedef void (CALLBACK *fZLHaveReConnect)(LONG lLoginID, char *pchDVRIP, LONG nDVRPort, DWORD dwUser);

// ��̬�����ӶϿ��ص�����ԭ��
typedef void (CALLBACK *fZLSubDisConnect)(ZLNET_INTERFACE_TYPE emInterfaceType, BOOL bOnline, LONG lOperateHandle, LONG lLoginID, DWORD dwUser);

// ʵʱ�������ݻص�����ԭ��
typedef void (CALLBACK *fZLRealDataCallBack)(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, DWORD dwUser);

// ʵʱ�������ݻص�����ԭ��--��չ
typedef void (CALLBACK *fZLRealDataCallBackEx)(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, LONG param, DWORD dwUser);

// ��Ļ���ӻص�����ԭ��
typedef void (CALLBACK *fZLDrawCallBack)(LONG lLoginID, LONG lPlayHandle, HDC hDC, DWORD dwUser);

// �ط����ݻص�����ԭ��
typedef int (CALLBACK *fZLDataCallBack)(LONG lRealHandle, DWORD dwDataType, BYTE *pBuffer, DWORD dwBufSize, DWORD dwUser);

// �طŽ��Ȼص�����ԭ��
typedef void (CALLBACK *fZLDownLoadPosCallBack)(LONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, DWORD dwUser);

// ��ʱ��طŽ��Ȼص�����ԭ��
typedef void (CALLBACK *fZLTimeDownLoadPosCallBack) (LONG lPlayHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, int index, ZLNET_RECORDFILE_INFO recordfileinfo, DWORD dwUser);

// ��Ϣ�ص�����ԭ��
typedef BOOL (CALLBACK *fZLMessCallBack)(LONG lCommand, LONG lLoginID, char *pBuf, DWORD dwBufLen, char *pchDVRIP, LONG nDVRPort, DWORD dwUser);

// �����������ص�����ԭ��
// ����ע��ķ�����ϢpParamָ��һ��ZLNET_EXTERN_INFO�Ľṹ��(SDK�ڲ�����ΪAFK_EXTERN_INFO)
typedef int (CALLBACK *fZLServiceCallBack)(LONG lHandle, char *pIp, WORD wPort, LONG lCommand, void *pParam, DWORD dwParamLen, DWORD dwUserData);

// �����Խ�����Ƶ���ݻص�����ԭ��
typedef void (CALLBACK *pfZLAudioDataCallBack)(LONG lTalkHandle, char *pDataBuf, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser);

// �����豸����ص�����ԭ��
typedef void (CALLBACK *fZLUpgradeCallBack) (LONG lLoginID, LONG lUpgradechannel, int nTotalSize, int nSendSize, DWORD dwUser);

// ͸�����ڻص�����ԭ��
typedef void (CALLBACK *fZLTransComCallBack) (LONG lLoginID, LONG lTransComChannel, char *pBuffer, DWORD dwBufSize, DWORD dwUser);

// ��ѯ�豸��־���ݻص�����ԭ��
typedef void (CALLBACK *fZLLogDataCallBack)(LONG lLoginID, char *pBuffer, DWORD dwBufSize, DWORD nTotalSize, BOOL bEnd, DWORD dwUser);

// ץͼ�ص�����ԭ��
typedef void (CALLBACK *fZLSnapRev)(LONG lLoginID, BYTE *pBuf, UINT RevLen, UINT EncodeType, DWORD CmdSerial, DWORD dwUser);

// GPS��Ϣ���Ļص�
typedef void (CALLBACK *fZLGPSRev)(LONG lLoginID, ZLNET_GPS_Info GpsInfo, DWORD dwUserData);

// �첽���ݻص�
typedef void (CALLBACK *fZLMessDataCallBack)(LONG lCommand, LPZLNET_CALLBACK_DATA lpData, DWORD dwUser);

// �ļ�����ص�
typedef void (CALLBACK *fZLTransFileCallBack)(LONG lHandle, int nTransType, int nState, int nSendSize, int nTotalSize, DWORD dwUser);

//������Ƶ���ջص�����
typedef int (CALLBACK *fidvrDownLoadVideoCallback)( LONG lRealHandle, ZLNET_IVA_ALARMVIDEOTYPE type,  const void* videoBuf, unsigned long videoBufLen , DWORD userData );

//ATM�������Իص�����
typedef void (CALLBACK *fZLAlarmDebugRevCallback)(long ILongID, int nATMIndex, ZLNET_IVA_ALARM_DEBUG Debug,unsigned long dwuser);

//����ͳ�Ʊ������Իص�����
typedef void (CALLBACK *fZLAlarmDebugStaffRevCallback)(long ILongID, int nSCIndex, ZLNET_IVA_STAFF_ARITH_DEBUG Debug, unsigned long dwuser);

//SSB�������Իص�����
typedef void (CALLBACK *fZLAlarmDebugSSBRevCallback)(long ILongID, int nSSBIndex, ZLNET_IVA_SSB_ARITH_DEBUG Debug,unsigned long dwuser);

//BZS�������Իص�����
typedef void (CALLBACK *fZLAlarmDebugBZSRevCallback)(long ILongID, int nBZSIndex, ZLNET_IVA_BZS_ARITH_DEBUG Debug,unsigned long dwuser);

//BZS���ٹ켣��Ϣ
typedef void (CALLBACK *fZLBZSTrackInfoCallback)(long ILongID, int nBZSIndex, ZLNET_IVA_BZS_TRACK_INFO Debug,unsigned long dwuser);

//�����������Իص�����
typedef void (CALLBACK *fZLAlarmDebugFaceRevCallback)(long ILongID, int nFaceIndex, ZLNET_IVA_FACE_ARITH_DEBUG Debug,unsigned long dwuser);

//��������ͳ����Ϣ��ͼƬ�ص�����
typedef int (CALLBACK *fIdvrAlarmUpStaffCountCallback)( int loginHandle, ZLNET_IVA_ALARMINFO_STAFFCOUNT* info, DWORD userData );

//���ܳ�����Ϣ�ϴ��ص�����
typedef int (CALLBACK *fIdvrAlarmUpPlateIdCallback)( int loginHandle, ZLNET_IVA_PLATEID_ALARMINFO*  info, DWORD userData);

//����ATM������־��ͼƬ�ص�����
typedef int (CALLBACK *fIdvrAlarmUpATMCallback)( int loginHandle, ZLNET_IVA_ATM_ALARMINFO*  info, DWORD userData);

//����SSB����
typedef int (CALLBACK *fIdvrAlarmUpSSBCallback)( int loginHandle, ZLNET_IVA_SSB_ALARMINFO*  info, DWORD userData);

//����BZS����
typedef int (CALLBACK *fIdvrAlarmUpBZSCallback)( int loginHandle, ZLNET_IVA_BZS_ALARMINFO*  info, DWORD userData);

//������������
typedef int (CALLBACK *fIdvrAlarmUpFaceCallback)( int loginHandle, ZLNET_IVA_FACE_ALARMINFO*  info, DWORD userData);

//���ܱ�����Ƶ���ջص�����
typedef int (CALLBACK *fIdvrAlarmUpVideoCallback)( int loginHandle, DWORD id, ZLNET_TIME Time, ZLNET_IVA_ALARMVIDEOTYPE type,  int chn, const void* videoBuf, unsigned long videoBufLen , DWORD userData );

//�ϴ���Ƶ�ļ����Ȼص�����
typedef void (CALLBACK *fIDdvrUploadPosCallBack)(LONG lUploadHandle, DWORD dwTotalSize, DWORD dwDownLoadSize, DWORD dwUser);

//NVR�����豸�ص�
typedef void (CALLBACK *fZLNVRSearch)(LONG lLoginID, ZLNET_NVR_SEARCHINFO* Info, DWORD dwUserData);

//����ע��֪ͨ��Ϣ�ص�
typedef void (CALLBACK *fZLRevLink)(LONG lLoginID, ZLNET_REV_LINK_RET* Info, DWORD dwUserData);

/************************************************************************
 ** �ӿڶ���
 ***********************************************************************/

// SDK��ʼ��
ZLNET_API BOOL CALL_METHOD ZLNET_Init(fZLDisConnect cbDisConnect, DWORD dwUser);

//���������ص�
ZLNET_API void CALL_METHOD ZLNET_SetHeartBeatCallBack(fZLIDVRHeatBeat cbHeartBeat,DWORD dwUser);

// SDK�˳�����
ZLNET_API void CALL_METHOD ZLNET_Cleanup();

//------------------------------------------------------------------------

// ���ö��������ɹ��ص����������ú�SDK�ڲ������Զ�����
ZLNET_API void CALL_METHOD ZLNET_SetAutoReconnect(fZLHaveReConnect cbAutoConnect, DWORD dwUser);

// ���ö�̬�����Ӷ��߻ص�������ĿǰSVR�豸�ļ��Ӻͻط��Ƕ����ӵġ�
ZLNET_API void CALL_METHOD ZLNET_SetSubconnCallBack(fZLSubDisConnect cbSubDisConnect, DWORD dwUser);

// ���غ���ִ��ʧ�ܴ���
ZLNET_API DWORD CALL_METHOD ZLNET_GetLastError(void);

// ���������豸��ʱʱ��ͳ��Դ���
ZLNET_API void CALL_METHOD ZLNET_SetConnectTime(int nWaitTime, int nTryTimes);

// ���õ�½���绷��
ZLNET_API void CALL_METHOD ZLNET_SetNetworkParam(ZLNET_PARAM *pNetParam);

// ��ȡSDK�İ汾��Ϣ
ZLNET_API DWORD CALL_METHOD ZLNET_GetSDKVersion();

//------------------------------------------------------------------------

// ���豸ע��
ZLNET_API LONG CALL_METHOD ZLNET_Login(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, LPZLNET_DEVICEINFO lpDeviceInfo, int *error = 0);

// ��չ�ӿڣ�nSpecCap = 0ΪTCP��ʽ�µĵ��룬nSpecCap = 2Ϊ����ע��ĵ��룬nSpecCap = 3Ϊ�鲥��ʽ�µĵ��룬nSpecCap = 4ΪUDP��ʽ�µĵ��룬nSpecCap = 6Ϊֻ���������µĵ��룬nSpecCap = 7ΪSSL����
ZLNET_API LONG CALL_METHOD ZLNET_LoginEx(char *pchDVRIP, WORD wDVRPort, char *pchUserName, char *pchPassword, int nSpecCap, void* pCapParam, LPZLNET_DEVICEINFO lpDeviceInfo, int *error = 0);

// ���豸ע��
ZLNET_API BOOL CALL_METHOD ZLNET_Logout(LONG lLoginID);

ZLNET_API LONG CALL_METHOD ZLNET_GetIPByDDNSID(char *szServerIp, int nServerPort, char *ddnsID, char* szRetIP, int *pHttpPort, int *pTcpPort, int *pErrorCode);

//------------------------------------------------------------------------

// ��ʼʵʱ����
ZLNET_API LONG CALL_METHOD ZLNET_RealPlay(LONG lLoginID, int nChannelID, HWND hWnd);

// ��ʼʵʱ����--��չ
ZLNET_API LONG CALL_METHOD ZLNET_RealPlayEx(LONG lLoginID, int nChannelID, HWND hWnd, ZLNET_RealPlayType rType = ZLNET_RType_Realplay);

// �໭��ʵʱԤ��
ZLNET_API LONG CALL_METHOD ZLNET_MultiPlay(LONG lLoginID, HWND hWnd);

// ֹͣ�໭��ʵʱԤ��
ZLNET_API BOOL CALL_METHOD ZLNET_StopMultiPlay(LONG lMultiHandle);

// ץͼ��hPlayHandleΪ���ӻ�طž��
ZLNET_API BOOL CALL_METHOD ZLNET_CapturePicture(LONG hPlayHandle, const char *pchPicFileName);

// ����ʵʱ�������ݻص�
ZLNET_API BOOL CALL_METHOD ZLNET_SetRealDataCallBack(LONG lRealHandle, fZLRealDataCallBack cbRealData, DWORD dwUser);

// ����ʵʱ�������ݻص�--��չ
ZLNET_API BOOL CALL_METHOD ZLNET_SetRealDataCallBackEx(LONG lRealHandle, fZLRealDataCallBackEx cbRealData, DWORD dwUser, DWORD dwFlag);

// ����ͼ��������
ZLNET_API BOOL	CALL_METHOD ZLNET_AdjustFluency(LONG lRealHandle, int nLevel);

// ��������Ϊ�ļ�
ZLNET_API BOOL CALL_METHOD ZLNET_SaveRealData(LONG lRealHandle, const char *pchFileName);

// ������������Ϊ�ļ�
ZLNET_API BOOL CALL_METHOD ZLNET_StopSaveRealData(LONG lRealHandle);

// ����ͼ������
ZLNET_API BOOL CALL_METHOD ZLNET_ZLSetVideoEffect(LONG lPlayHandle, unsigned char nBrightness, unsigned char nContrast, unsigned char nHue, unsigned char nSaturation);

// ��ȡͼ������
ZLNET_API BOOL CALL_METHOD ZLNET_ZLGetVideoEffect(LONG lPlayHandle, unsigned char *nBrightness, unsigned char *nContrast, unsigned char *nHue, unsigned char *nSaturation);

// ������Ļ���ӻص�
ZLNET_API void CALL_METHOD ZLNET_RigisterDrawFun(fZLDrawCallBack cbDraw, DWORD dwUser);

// ������
ZLNET_API BOOL CALL_METHOD ZLNET_OpenSound(LONG hPlayHandle);

// ����������lPlayHandleΪ���ӻ�طž��
ZLNET_API BOOL CALL_METHOD ZLNET_SetVolume(LONG lPlayHandle, int nVolume);

// �ر�����
ZLNET_API BOOL CALL_METHOD ZLNET_CloseSound();

// ֹͣʵʱԤ��
ZLNET_API BOOL CALL_METHOD ZLNET_StopRealPlay(LONG lRealHandle);

// ֹͣʵʱԤ��--��չ
ZLNET_API BOOL CALL_METHOD ZLNET_StopRealPlayEx(LONG lRealHandle);

//------------------------------------------------------------------------

// ͨ����̨����
ZLNET_API BOOL CALL_METHOD ZLNET_PTZControl(LONG lLoginID, int nChannelID, DWORD dwPTZCommand, DWORD dwStep, BOOL dwStop);

// ������̨����
ZLNET_API BOOL CALL_METHOD ZLNET_ZLPTZControl(LONG lLoginID, int nChannelID, DWORD dwPTZCommand, unsigned char param1, unsigned char param2, unsigned char param3, BOOL dwStop);

// ������̨������չ�ӿڣ�֧����ά���ٶ�λ
ZLNET_API BOOL CALL_METHOD ZLNET_ZLPTZControlEx(LONG lLoginID, int nChannelID, DWORD dwPTZCommand, LONG lParam1, LONG lParam2, LONG lParam3, BOOL dwStop);

//------------------------------------------------------------------------

// ��ѯʱ������Ƿ���¼���ļ�
ZLNET_API BOOL CALL_METHOD ZLNET_QueryRecordTime(LONG lLoginID, int nChannelId, int nRecordFileType, LPZLNET_TIME tmStart, LPZLNET_TIME tmEnd, char* pchCardid, BOOL *bResult, int waittime=1000);

// ��ѯʱ����ڵ�����¼���ļ�
ZLNET_API BOOL CALL_METHOD ZLNET_QueryRecordFile(LONG lLoginID, int nChannelId, int nRecordFileType, LPZLNET_TIME tmStart, LPZLNET_TIME tmEnd, char* pchCardid, LPZLNET_RECORDFILE_INFO nriFileinfo, int maxlen, int *filecount, int waittime=1000, BOOL bTime = FALSE);

// ��ѯ����¼��ʱ��
ZLNET_API BOOL CALL_METHOD ZLNET_QueryFurthestRecordTime(LONG lLoginID, int nRecordFileType, char *pchCardid, ZLNET_FURTHEST_RECORD_TIME* pFurthrestTime, int nWaitTime);

// ��ʼ����¼���ļ�
ZLNET_API LONG	CALL_METHOD ZLNET_FindFile(LONG lLoginID, int nChannelId, int nRecordFileType, char* cardid, LPZLNET_TIME time_start, LPZLNET_TIME time_end, BOOL bTime, int waittime);

// ����¼���ļ�
ZLNET_API int	CALL_METHOD ZLNET_FindNextFile(LONG lFindHandle,LPZLNET_RECORDFILE_INFO lpFindData);

// ����¼���ļ�����
ZLNET_API BOOL CALL_METHOD ZLNET_FindClose(LONG lFindHandle);

// ���ļ���ʽ�ط�
ZLNET_API LONG CALL_METHOD ZLNET_PlayBackByRecordFile(LONG lLoginID, LPZLNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwUserData);

// ���ļ���ʽ�ط�--��չ
ZLNET_API LONG CALL_METHOD ZLNET_PlayBackByRecordFileEx(LONG lLoginID, LPZLNET_RECORDFILE_INFO lpRecordFile, HWND hWnd, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwPosUser, fZLDataCallBack fDownLoadDataCallBack, DWORD dwDataUser);

// ��ʱ�䷽ʽ�ط�
ZLNET_API LONG CALL_METHOD ZLNET_PlayBackByTime(LONG lLoginID, int nChannelID, LPZLNET_TIME lpStartTime, LPZLNET_TIME lpStopTime, HWND hWnd, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwPosUser);

// ��ʱ�䷽ʽ�ط�--��չ
ZLNET_API LONG CALL_METHOD ZLNET_PlayBackByTimeEx(LONG lLoginID, int nChannelID, LPZLNET_TIME lpStartTime, LPZLNET_TIME lpStopTime, HWND hWnd, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwPosUser, fZLDataCallBack fDownLoadDataCallBack, DWORD dwDataUser);

// ��λ¼��ط���ʼ��
ZLNET_API BOOL CALL_METHOD ZLNET_SeekPlayBack(LONG lPlayHandle, unsigned int offsettime, unsigned int offsetbyte);

// ��ͣ��ָ�¼��ط�
ZLNET_API BOOL CALL_METHOD ZLNET_PausePlayBack(LONG lPlayHandle, BOOL bPause);

// ���¼��ط�
ZLNET_API BOOL CALL_METHOD ZLNET_FastPlayBack(LONG lPlayHandle);

// ����¼��ط�
ZLNET_API BOOL CALL_METHOD ZLNET_SlowPlayBack(LONG lPlayHandle);

// ����¼��ط�
ZLNET_API BOOL CALL_METHOD ZLNET_StepPlayBack(LONG lPlayHandle, BOOL bStop);

// ���ûط�֡��
ZLNET_API BOOL CALL_METHOD ZLNET_SetFramePlayBack(LONG lPlayHandle, int framerate);

// ��ȡ�ط�֡��
ZLNET_API BOOL CALL_METHOD ZLNET_GetFramePlayBack(LONG lPlayHandle, int *fileframerate, int *playframerate);

// �ָ������ط��ٶ�
ZLNET_API BOOL CALL_METHOD ZLNET_NormalPlayBack(LONG lPlayHandle);

// ��ȡ�ط�OSDʱ��
ZLNET_API BOOL CALL_METHOD ZLNET_GetPlayBackOsdTime(LONG lPlayHandle, LPZLNET_TIME lpOsdTime, LPZLNET_TIME lpStartTime, LPZLNET_TIME lpEndTime);

// ֹͣ¼��ط�
ZLNET_API BOOL CALL_METHOD ZLNET_StopPlayBack(LONG lPlayHandle);

// ����¼���ļ�
ZLNET_API LONG CALL_METHOD ZLNET_DownloadByRecordFile(LONG lLoginID,LPZLNET_RECORDFILE_INFO lpRecordFile, char *sSavedFileName, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwUserData);

// ���������ļ�ģʽ
ZLNET_API BOOL CALL_METHOD ZLNET_SetDownloadFileMode(LONG lLoginID, ZLNET_DOWNLOADFILE_MODE eMode);

// ͨ��ʱ������¼��
ZLNET_API LONG CALL_METHOD ZLNET_DownloadByTime(LONG lLoginID, int nChannelId, int nRecordFileType, LPZLNET_TIME tmStart, LPZLNET_TIME tmEnd, char *sSavedFileName, fZLTimeDownLoadPosCallBack cbTimeDownLoadPos, DWORD dwUserData);

// ��ѯ¼�����ؽ���
ZLNET_API BOOL CALL_METHOD ZLNET_GetDownloadPos(LONG lFileHandle, int *nTotalSize, int *nDownLoadSize);

// ֹͣ¼������
ZLNET_API BOOL CALL_METHOD ZLNET_StopDownload(LONG lFileHandle);
//------------------------------------------------------------------------

// ���ñ����ص�����
ZLNET_API void CALL_METHOD ZLNET_SetDVRMessCallBack(fZLMessCallBack cbMessage,DWORD dwUser);

// ���ñ����ص���չ����
ZLNET_API void CALL_METHOD ZLNET_SetDVRMessCallBackEx(LONG ID, fZLMessCallBack cbMessage,DWORD dwUser, BOOL bAdd = TRUE);

// ���豸���ı���
ZLNET_API BOOL CALL_METHOD ZLNET_StartListen(LONG lLoginID);

// ���豸���ı���--��չ
ZLNET_API BOOL CALL_METHOD ZLNET_StartListenEx(LONG lLoginID);

// ֹͣ���ı���
ZLNET_API BOOL CALL_METHOD ZLNET_StopListen(LONG lLoginID);

//------------------------------------------------------------------------

// ����ע�Ṧ�ܣ���������nTimeout��������Ч
ZLNET_API LONG CALL_METHOD ZLNET_ListenServer(char* ip, WORD port, int nTimeout, fZLServiceCallBack cbListen, DWORD dwUserData);

// ֹͣ����
ZLNET_API BOOL CALL_METHOD ZLNET_StopListenServer(LONG lServerHandle);

// ��Ӧ�豸��ע������
ZLNET_API BOOL CALL_METHOD ZLNET_ResponseDevReg(char *devSerial, char* ip, WORD port, BOOL bAccept);

//------------------------------------------------------------------------

// �����ϴ����ܣ���������dwTimeOut��������Ч
ZLNET_API LONG CALL_METHOD ZLNET_StartService(WORD wPort, char *pIp = NULL, fZLServiceCallBack pfscb = NULL, DWORD dwTimeOut = 0xffffffff, DWORD dwUserData = 0);

// ֹͣ����
ZLNET_API BOOL CALL_METHOD ZLNET_StopService(LONG lHandle);

//------------------------------------------------------------------------

// ���������Խ�ģʽ���ͻ��˷�ʽ���Ƿ�������ʽ
ZLNET_API BOOL CALL_METHOD ZLNET_SetDeviceMode(LONG lLoginID, ZLNET_USEDEV_MODE emType, void* pValue);

// �������Խ�
ZLNET_API LONG CALL_METHOD ZLNET_StartTalkEx(LONG lLoginID, pfZLAudioDataCallBack pfcb, DWORD dwUser);

// ��ʼPC��¼��
ZLNET_API BOOL CALL_METHOD ZLNET_RecordStart();

// ����PC��¼��
ZLNET_API BOOL CALL_METHOD ZLNET_RecordStop();

// �����������ݵ��豸
ZLNET_API LONG CALL_METHOD ZLNET_TalkSendData(LONG lTalkHandle, char *pSendBuf, DWORD dwBufSize);

// ������Ƶ����
ZLNET_API void CALL_METHOD ZLNET_AudioDec(char *pAudioDataBuf, DWORD dwBufSize);

// ���������Խ�������
ZLNET_API BOOL CALL_METHOD ZLNET_SetAudioClientVolume(LONG lTalkHandle, WORD wVolume);

// ֹͣ�����Խ�
ZLNET_API BOOL CALL_METHOD ZLNET_StopTalkEx(LONG lTalkHandle);

// ����豸���㲥��
ZLNET_API BOOL CALL_METHOD ZLNET_AudioBroadcastAddDev(LONG lLoginID);

// �ӹ㲥����ɾ���豸
ZLNET_API BOOL CALL_METHOD ZLNET_AudioBroadcastDelDev(LONG lLoginID);

// ��Ƶ����--��ʼ��(�ض���׼��ʽ->�����ʽ)
ZLNET_API int  CALL_METHOD ZLNET_InitAudioEncode(ZLNET_AUDIO_FORMAT aft);

// ��Ƶ����--���ݱ���
ZLNET_API int	CALL_METHOD	ZLNET_AudioEncode(LONG lTalkHandle, BYTE *lpInBuf, DWORD *lpInLen, BYTE *lpOutBuf, DWORD *lpOutLen);

// ��Ƶ����--��Ƶ����->�����ʽ
ZLNET_API int  CALL_METHOD ZLNET_AudioFormatZL(BYTE *lpInBuf, DWORD *lpInLen, BYTE *lpOutBuf, DWORD *lpOutLen, ZLNET_AUDIO_FORMAT aft);

// ��Ƶ����--����˳�
ZLNET_API int	CALL_METHOD	ZLNET_ReleaseAudioEncode();

//------------------------------------------------------------------------

// ��ѯ�豸��־
ZLNET_API BOOL CALL_METHOD ZLNET_QueryLog(LONG lLoginID, char *pLogBuffer, int maxlen, int *nLogBufferlen, int waittime=3000);

// ��ѯ�豸��־���Է�ҳ��ʽ��ѯ
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDeviceLog(LONG lLoginID, ZLNET_QUERY_DEVICE_LOG_PARAM *pQueryParam, char *pLogBuffer, int nLogBufferLen, int *pRecLogNum, int waittime=3000);

// ���ͨ��¼��״̬
ZLNET_API BOOL CALL_METHOD ZLNET_QueryRecordState(LONG lLoginID, char *pRSBuffer, int maxlen, int *nRSBufferlen, int waittime=1000);

// ��ѯ�豸״̬
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDevState(LONG lLoginID, int nType, char *pBuf, int nBufLen, int *pRetLen, int waittime=1000);

// ��ѯϵͳ������Ϣ
ZLNET_API BOOL CALL_METHOD ZLNET_QuerySystemInfo(LONG lLoginID, int nSystemType, char *pSysInfoBuffer, int maxlen, int *nSysInfolen, int waittime=1000);

// ��ȡͨ������
ZLNET_API LONG CALL_METHOD ZLNET_GetStatiscFlux(LONG lLoginID, LONG lPlayHandle);

// ��ȡ��̨��Ϣ
ZLNET_API BOOL  CALL_METHOD ZLNET_GetPtzOptAttr(LONG lLoginID,DWORD dwProtocolIndex,LPVOID lpOutBuffer,DWORD dwBufLen,DWORD *lpBytesReturned,int waittime=500);

//------------------------------------------------------------------------

// �����豸
ZLNET_API BOOL CALL_METHOD ZLNET_RebootDev(LONG lLoginID);

// �ر��豸
ZLNET_API BOOL CALL_METHOD ZLNET_ShutDownDev(LONG lLoginID);

// �豸����
ZLNET_API BOOL CALL_METHOD ZLNET_ControlDevice(LONG lLoginID, ZLNET_CtrlType type, void *param, int waittime = 1000);

// ����ͨ��¼��״̬
ZLNET_API BOOL CALL_METHOD ZLNET_SetupRecordState(LONG lLoginID, char *pRSBuffer, int nRSBufferlen);

// ��ѯIO״̬
ZLNET_API BOOL CALL_METHOD ZLNET_QueryIOControlState(LONG lLoginID, ZLNET_IOTYPE emType, 
                                           void *pState, int maxlen, int *nIOCount, int waittime=1000);

// IO����
ZLNET_API BOOL CALL_METHOD ZLNET_IOControl(LONG lLoginID, ZLNET_IOTYPE emType, void *pState, int maxlen);

// ǿ��I֡��nChannelID��ͨ���ţ�nSubChannel����������(0������1��������1)
ZLNET_API BOOL CALL_METHOD ZLNET_MakeKeyFrame(LONG lLoginID, int nChannelID, int nSubChannel=0);

//------------------------------------------------------------------------

// ��ѯ�û���Ϣ
ZLNET_API BOOL CALL_METHOD ZLNET_QueryUserInfo(LONG lLoginID, ZLNET_USER_MANAGE_INFO *info, int waittime=1000);

// ��ѯ�û���Ϣ--��չ
ZLNET_API BOOL CALL_METHOD ZLNET_QueryUserInfoEx(LONG lLoginID,  ZLNET_USER_MANAGE_INFO_EX *info, int waittime=1000);

// �����豸�û�
ZLNET_API BOOL CALL_METHOD ZLNET_OperateUserInfo(LONG lLoginID, int nOperateType, void *opParam, void *subParam, int waittime=1000);

// �����豸�û�--��չ
ZLNET_API BOOL CALL_METHOD ZLNET_OperateUserInfoEx(LONG lLoginID, int nOperateType, void *opParam, void *subParam, int waittime=1000);

//------------------------------------------------------------------------

// ����͸������ͨ��
ZLNET_API LONG CALL_METHOD ZLNET_CreateTransComChannel(LONG lLoginID, int TransComType, unsigned int baudrate, unsigned int databits, unsigned int stopbits, unsigned int parity, fZLTransComCallBack cbTransCom, DWORD dwUser);

// ͸�����ڷ�������
ZLNET_API BOOL CALL_METHOD ZLNET_SendTransComData(LONG lTransComChannel, char *pBuffer, DWORD dwBufSize);

// �ͷ�ͨ������ͨ��
ZLNET_API BOOL CALL_METHOD ZLNET_DestroyTransComChannel(LONG lTransComChannel);

// ��ѯ͸������״̬
ZLNET_API BOOL   CALL_METHOD ZLNET_QueryTransComParams(LONG lLoginID, int TransComType, ZLNET_COMM_STATE* pCommState, int nWaitTime = 500);

//------------------------------------------------------------------------

// ��ʼ�����豸����
ZLNET_API LONG CALL_METHOD ZLNET_StartUpgrade(LONG lLoginID, char *pchFileName, fZLUpgradeCallBack cbUpgrade, DWORD dwUser);

// ��ʼ�����豸����--��չ
ZLNET_API LONG CALL_METHOD ZLNET_StartUpgradeEx(LONG lLoginID, ZLNET_UPGRADE_TYPE emType, char *pchFileName, fZLUpgradeCallBack cbUpgrade, DWORD dwUser);

// ��������
ZLNET_API BOOL CALL_METHOD ZLNET_SendUpgrade(LONG lUpgradeID);

// ���������豸����
ZLNET_API BOOL CALL_METHOD ZLNET_StopUpgrade(LONG lUpgradeID);

//------------------------------------------------------------------------

// ��ѯ������Ϣ
ZLNET_API BOOL  CALL_METHOD ZLNET_GetDevConfig(LONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime=500);

// ����������Ϣ
ZLNET_API BOOL  CALL_METHOD ZLNET_SetDevConfig(LONG lLoginID, DWORD dwCommand, LONG lChannel, LPVOID lpInBuffer, DWORD dwInBufferSize, int waittime=500);

// �����ýӿڣ���ѯ������Ϣ(��Json��ʽ�����������SDK)
ZLNET_API BOOL CALL_METHOD ZLNET_GetNewDevConfig(LONG lLoginID, char* szCommand, char* szOutBuffer, DWORD dwOutBufferSize, int *error, int waittime=1500);

// �����ýӿڣ�����������Ϣ(��Json��ʽ�����������SDK)
ZLNET_API BOOL CALL_METHOD ZLNET_SetNewDevConfig(LONG lLoginID, char* szInBuffer, DWORD dwInBufferSize, int *error, int *restart, int waittime=1500);

//------------------------------------------------------------------------

// ��ѯ�豸ͨ������
ZLNET_API BOOL CALL_METHOD ZLNET_QueryChannelName(LONG lLoginID, char *pChannelName, int maxlen, int *nChannelCount, int waittime=1000);

// �����豸ͨ������
ZLNET_API BOOL  CALL_METHOD ZLNET_SetupChannelName(LONG lLoginID,char *pbuf, int nbuflen);

// �����豸ͨ���ַ�����
ZLNET_API BOOL  CALL_METHOD ZLNET_SetupChannelOsdString(LONG lLoginID, int nChannelNo, ZLNET_CHANNEL_OSDSTRING* struOsdString, int nbuflen);

// ��ѯ�豸��ǰʱ��
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDeviceTime(LONG lLoginID, LPZLNET_TIME pDeviceTime, int waittime=1000);

// �����豸��ǰʱ��
ZLNET_API BOOL CALL_METHOD ZLNET_SetupDeviceTime(LONG lLoginID, LPZLNET_TIME pDeviceTime);

// �����豸��������
ZLNET_API BOOL CALL_METHOD ZLNET_SetMaxFlux(LONG lLoginID, WORD wFlux);

//------------------------------------------------------------------------

// ���������ļ�
ZLNET_API LONG CALL_METHOD ZLNET_ImportConfigFile(LONG lLoginID, char *szFileName, fZLDownLoadPosCallBack cbUploadPos, DWORD dwUserData, DWORD param=0);

// ֹͣ���������ļ�
ZLNET_API BOOL CALL_METHOD ZLNET_StopImportCfgFile(LONG lImportHandle);

// ���������ļ�
ZLNET_API LONG CALL_METHOD ZLNET_ExportConfigFile(LONG lLoginID, ZLNET_CONFIG_FILE_TYPE emConfigFileType, char *szSavedFilePath, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwUserData);

// ֹͣ���������ļ�
ZLNET_API BOOL CALL_METHOD ZLNET_StopExportCfgFile(LONG lExportHandle);

//------------------------------------------------------------------------

// ͨ���豸���ֻ����豸���к���DDNS��������ѯ�豸IP
ZLNET_API BOOL CALL_METHOD ZLNET_GetDVRIPByResolveSvr(char *pchDVRIP, WORD wDVRPort, BYTE *sDVRName, WORD wDVRNameLen, BYTE *sDVRSerialNumber, WORD wDVRSerialLen, char* sGetIP);

// ������������IPC��NVS���豸
ZLNET_API BOOL CALL_METHOD ZLNET_SearchDevices(char* szBuf, int nBufLen, int* pRetLen, DWORD dwSearchTime);

// ������������IPC��NVS��IVA���豸��չ�ӿ�
ZLNET_API BOOL CALL_METHOD ZLNET_SearchDevicesEx(char* szBuf, int nBufLen, int* pRetLen, DWORD dwSearchTime, ZLNET_SEARCH_MODE eMode);

//------------------------------------------------------------------------

// ƽ̨����ӿ�
ZLNET_API BOOL CALL_METHOD ZLNET_GetPlatFormInfo(LONG lLoginID, DWORD dwCommand, int nSubCommand, int nParam, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned,int waittime=500);
ZLNET_API BOOL CALL_METHOD ZLNET_SetPlatFormInfo(LONG lLoginID, DWORD dwCommand, int nSubCommand, int nParam, LPVOID lpInBuffer, DWORD dwInBufferSize, int waittime=500);


// ����ץͼ�ص�����
ZLNET_API void CALL_METHOD ZLNET_SetSnapRevCallBack(fZLSnapRev OnSnapRevMessage, DWORD dwUser);

// ץͼ����
ZLNET_API BOOL CALL_METHOD ZLNET_SnapPicture(LONG lLoginID, ZLNET_SNAP_PARAMS par);

// ����GPS���Ļص�����
ZLNET_API void CALL_METHOD ZLNET_SetSubcribeGPSCallBack(fZLGPSRev OnGPSMessage, DWORD dwUser);

// GPS��Ϣ����
ZLNET_API BOOL CALL_METHOD ZLNET_SubcribeGPS (LONG lLoginID, BOOL bStart, LONG KeepTime, LONG InterTime);

//�������ܱ�������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SubcribeAlarmDebug (LONG lLoginID,        //�豸���
													 int nATMIndex,			//ATM��������
													BOOL bStart);		  //�Ƿ����� 

ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SubcribeAlarmSSBDebug (LONG lLoginID,      //�豸���
															int nSSBIndex,		//SSB����
														 BOOL bStart);			//�Ƿ����� 

ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SubcribeAlarmBZSDebug (LONG lLoginID,      //�豸���
															int nBZSIndex,		//SSB����
															BOOL bStart);		//�Ƿ����� 

ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SubcribeAlarmFaceDebug(LONG lLoginID,      //�豸���
															int nFaceIndex,		//��������
															BOOL bStart);		//�Ƿ����� 

ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SubcribeAlarmStaffDebug(LONG lLoginID,      //�豸���
															int nSCIndex,		//����ͳ������
															BOOL bStart);		//�Ƿ����� 

//�������ܱ������Իص�
ZLNET_API void CALL_METHOD ZLNET_IVA_SetSubcribeAlarmDebugCallBack(fZLAlarmDebugRevCallback cbDebugRec, DWORD dwUser); 

ZLNET_API void CALL_METHOD ZLNET_IVA_SetSubcribeAlarmSSBDebugCallBack(fZLAlarmDebugSSBRevCallback cbDebugRec, DWORD dwUser);

ZLNET_API void CALL_METHOD ZLNET_IVA_SetSubcribeAlarmBZSDebugCallBack(fZLAlarmDebugBZSRevCallback cbDebugRec, DWORD dwUser);

ZLNET_API void CALL_METHOD ZLNET_IVA_SetSubcribeAlarmFaceDebugCallBack(fZLAlarmDebugFaceRevCallback cbDebugRec, DWORD dwUser);

ZLNET_API void CALL_METHOD ZLNET_IVA_SetSubcribeAlarmStaffDebugCallBack(fZLAlarmDebugStaffRevCallback cbDebugRec, DWORD dwUser);

//�켣���ٻص�
ZLNET_API void CALL_METHOD ZLNET_IVA_SetBZSTrackInfoCallBack(LONG lLoginID, fZLBZSTrackInfoCallback cbTrackInfo, DWORD dwUser);


//////////////////////////////�������豸�ӿ�//////////////////////////////

// ��ѯ��������Ϣ
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDecoderInfo(LONG lLoginID, LPZLNET_DEV_DECODER_INFO lpDecInfo, int waittime=1000);

// ��ѯ��������ǰTV��Ϣ
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDecoderTVInfo(LONG lLoginID, int nMonitorID, LPZLNET_DEV_DECODER_TV lpMonitorInfo, int waittime=1000);

// ��ѯ����ͨ����Ϣ
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDecEncoderInfo(LONG lLoginID, int nEncoderID, LPZLNET_DEV_ENCODER_INFO lpEncoderInfo, int waittime=1000);

// ���ý�����TV���ʹ��
ZLNET_API BOOL CALL_METHOD ZLNET_SetDecTVOutEnable(LONG lLoginID, BYTE *pDecTVOutEnable, int nBufLen, int waittime=1000);

//------------------------------------------------------------------------

// �����첽�ص�����
ZLNET_API BOOL CALL_METHOD ZLNET_SetOperateCallBack(LONG lLoginID, fZLMessDataCallBack cbMessData, DWORD dwUser);

// ���ƽ�����TV����ָ�ӿ�Ϊ�첽��ʽ
ZLNET_API LONG CALL_METHOD ZLNET_CtrlDecTVScreen(LONG lLoginID, int nMonitorID, BOOL bEnable, int nSplitType, BYTE *pEncoderChannel, int nBufLen, void* userdata=NULL);

// ������TV�����л����ӿ�Ϊ�첽��ʽ
// ����nMonitorID(TV��)��nWndID(�����)ת��ΪnEncoderID(����ͨ��)��ʽ��nEncoderID��nMonitorID*nSplitNum(�ָ���)+nWndID
ZLNET_API LONG CALL_METHOD ZLNET_SwitchDecTVEncoder(LONG lLoginID, int nEncoderID, LPZLNET_DEV_ENCODER_INFO lpEncoderInfo, void* userdata=NULL);

//------------------------------------------------------------------------

// ���ӻ������
ZLNET_API int CALL_METHOD ZLNET_AddTourCombin(LONG lLoginID, int nMonitorID, int nSplitType, BYTE *pEncoderChannnel, int nBufLen, int waittime=1000);

// ɾ���������
ZLNET_API BOOL CALL_METHOD ZLNET_DelTourCombin(LONG lLoginID, int nMonitorID, int nCombinID, int waittime=1000);

// �޸Ļ������
ZLNET_API BOOL CALL_METHOD ZLNET_SetTourCombin(LONG lLoginID, int nMonitorID, int nCombinID, int nSplitType, BYTE *pEncoderChannel, int nBufLen, int waittime=1000);

// ��ѯ������ϣ�nCombinID��Χ0��32
ZLNET_API BOOL CALL_METHOD ZLNET_QueryTourCombin(LONG lLoginID, int nMonitorID, int nCombinID, LPZLNET_DEC_COMBIN_INFO lpDecCombinInfo, int waittime=1000);

// ������Ѳ����
ZLNET_API BOOL CALL_METHOD ZLNET_SetDecoderTour(LONG lLoginID, int nMonitorID, LPZLNET_DEC_TOUR_COMBIN lpDecTourInfo, int waittime=1000);

// ��ѯ��Ѳ����
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDecoderTour(LONG lLoginID, int nMonitorID, LPZLNET_DEC_TOUR_COMBIN lpDecTourInfo, int waittime=1000);

// ��ѯ��ǰ����ͨ������Ϣ
ZLNET_API BOOL CALL_METHOD ZLNET_QueryDecChannelFlux(LONG lLoginID, int nEncoderID, LPZLNET_DEV_DECCHANNEL_STATE lpChannelStateInfo, int waittime=1000);

//������������Ѳ
ZLNET_API BOOL CALL_METHOD ZLNET_CtrlDecoderTour(LONG lLoginID, int nMonitorID, ZLNET_DEC_CTRL_TOUR_TYPE emActionParam, int waittime = 1000);
//------------------------------------------------------------------------

typedef void (CALLBACK *fDecPlayBackPosCallBack)(LONG lLoginID, int nEncoderID, DWORD dwTotalSize, DWORD dwPlaySize, DWORD dwUser);

// ���ûطŽ��Ȼص�����
ZLNET_API BOOL CALL_METHOD ZLNET_SetDecPlaybackPos(LONG lLoginID, fDecPlayBackPosCallBack cbPlaybackPos, DWORD dwUser);

// ������TV����طţ��ӿ�Ϊ�첽��ʽ
ZLNET_API LONG CALL_METHOD ZLNET_DecTVPlayback(LONG lLoginID, int nEncoderID, ZLNET_DEC_PLAYBACK_MODE emPlaybackMode, LPVOID lpInBuffer, DWORD dwInBufferSize, void* userdata=NULL);

// ������TV����طſ���
ZLNET_API BOOL CALL_METHOD ZLNET_CtrlDecPlayback(LONG lLoginID, int nEncoderID, ZLNET_DEC_CTRL_PLAYBACK_TYPE emCtrlType, int nValue, int waittime=1000);


///////////////////////////////����汾�ӿ�///////////////////////////////

// ��ѯ�豸��־--��չ
ZLNET_API BOOL CALL_METHOD ZLNET_QueryLogEx(LONG lLoginID, ZLNET_LOG_QUERY_TYPE logType, char *pLogBuffer, int maxlen, int *nLogBufferlen, void* reserved, int waittime=3000);

// ����ע���ض����ܣ�������������
ZLNET_API LONG CALL_METHOD ZLNET_ControlConnectServer(LONG lLoginID, char* RegServerIP, WORD RegServerPort, int TimeOut=3000);

// ��������ע��
ZLNET_API BOOL CALL_METHOD ZLNET_ControlRegisterServer(LONG lLoginID, LONG ConnectionID, int waittime=1000);

// �Ͽ���������
ZLNET_API BOOL CALL_METHOD ZLNET_ControlDisconnectRegServer(LONG lLoginID, LONG ConnectionID);

// ��ѯ�豸������ע���������Ϣ
ZLNET_API BOOL CALL_METHOD ZLNET_QueryControlRegServerInfo(LONG lLoginID, LPZLNET_DEV_SERVER_AUTOREGISTER lpRegServerInfo, int waittime=2000);

// �ļ��ϴ��ӿ�
ZLNET_API LONG CALL_METHOD ZLNET_FileTransmit(LONG lLoginID, int nTransType, char* szInBuf, int nInBufLen, fZLTransFileCallBack cbTransFile, DWORD dwUserData, int waittime);

/////////////////////////////////��̭�ӿ�/////////////////////////////////

// ��ѯϵͳ���������ã��ýӿ�����̭����ʹ��ZLNET_GetDevConfig
ZLNET_API BOOL CALL_METHOD ZLNET_QueryConfig(LONG lLoginID, int nConfigType, char *pConfigbuf, int maxlen, int *nConfigbuflen, int waittime=1000);

// ����ϵͳ���������ã��ýӿ�����̭����ʹ��ZLNET_SetDevConfig
ZLNET_API BOOL CALL_METHOD ZLNET_SetupConfig(LONG lLoginID, int nConfigType, char *pConfigbuf, int nConfigbuflen, int waittime=1000);

// �ýӿ�����̭���벻Ҫʹ��
ZLNET_API BOOL CALL_METHOD ZLNET_Reset(LONG lLoginID, BOOL bReset);

// ��ѯ����Э�� �� �ýӿ�����̭����ʹ��ZLNET_GetDevConfig
ZLNET_API BOOL CALL_METHOD ZLNET_QueryComProtocol(LONG lLoginID, int nProtocolType, char *pProtocolBuffer, int maxlen, int *nProtocollen, int waittime=1000);

// ��ʼ�Խ����ýӿ�����̭����ʹ��ZLNET_StartTalkEx
ZLNET_API BOOL CALL_METHOD ZLNET_StartTalk(LONG lRealHandle, BOOL bCustomSend=false);

// �����Խ����ýӿ�����̭����ʹ��ZLNET_StopTalkEx
ZLNET_API BOOL CALL_METHOD ZLNET_StopTalk(LONG lRealHandle);

// �����Զ���Խ����ݣ��ýӿ�����̭����ʹ��ZLNET_TalkSendData
ZLNET_API BOOL CALL_METHOD ZLNET_SendTalkData_Custom(LONG lRealHandle, char *pBuffer, DWORD dwBufSize);

// ����ʵʱԤ�������С
ZLNET_API BOOL CALL_METHOD ZLNET_SetPlayerBufNumber(LONG lRealHandle, DWORD dwBufNum);

// ͨ��ʱ�������ļ�
ZLNET_API BOOL CALL_METHOD ZLNET_GetFileByTime(LONG lLoginID, int nChannelID, LPZLNET_TIME lpStartTime, LPZLNET_TIME lpStopTime, char *sSavedFileName);

// ����طſ���
ZLNET_API BOOL CALL_METHOD ZLNET_PlayBackControl(LONG lPlayHandle, DWORD dwControlCode, DWORD dwInValue, DWORD *lpOutValue);

// ��ѯ�豸����״̬ �ýӿ�����̭����ʹ��ZLNET_QueryDevState
ZLNET_API BOOL CALL_METHOD ZLNET_GetDEVWorkState(LONG lLoginID, LPZLNET_DEV_WORKSTATE lpWorkState, int waittime=1000);

// �첽��ѯ�豸��־
ZLNET_API BOOL CALL_METHOD ZLNET_QueryLogCallback(LONG lLoginID, fZLLogDataCallBack cbLogData, DWORD dwUser);

// �ϴ���Ƶ�ļ�(WAV��ʽ) 
ZLNET_API LONG CALL_METHOD ZLNET_UploadAudio(long lLoginID, int nAlarmType, int nSubType, char* szPath, int nPathLen, fIDdvrUploadPosCallBack cbUploadPos, DWORD dwUserData);

//ֹͣ�ϴ�
ZLNET_API BOOL CALL_METHOD ZLNET_StopUploadAudio(long lUploadHandle);

/////////////////////////////////NVR/////////////////////////////////////////////

//��ȡͨ����Ϣ
ZLNET_API int  CALL_METHOD  ZLNET_NVR_GetChannelInfo(long lLoginID, ZLNET_NVR_CHANNEL& NetConfig);

//��ȡ���統ǰͨ������
ZLNET_API int  CALL_METHOD  ZLNET_NVR_GetCurNetChannelInfo(long lLoginID, ZLNET_NVR_CHANNEL_INFO_EX& curChannelInfo);

//������������
ZLNET_API int  CALL_METHOD  ZLNET_NVR_SetNetConfig(long lLoginID, const ZLNET_NVR_CONFIG_NET NetConfig);

//��ȡ��������
ZLNET_API int  CALL_METHOD  ZLNET_NVR_GetNetConfig(long lLoginID, ZLNET_NVR_CONFIG_NET& NetConfig);

//��ȡ����ͨ����̨Э��
ZLNET_API int  CALL_METHOD  ZLNET_NVR_GetNetPtzParam(long lLoginID, ZLNET_NVR_NET_PTZ_PARAM& NetPtzParam, int nChannel);

//�����豸�����ص�����
ZLNET_API void CALL_METHOD ZLNET_NVR_SetSearchCallBack(fZLNVRSearch cbSearchMessage, DWORD dwUser);

//�豸��������
ZLNET_API BOOL CALL_METHOD ZLNET_NVR_Search(LONG lLoginID, BOOL bStart, int protocol);

/////////////////////////////////�������/////////////////////////////////////////
//����ע��IP�����ַ
ZLNET_API int CALL_METHOD ZLNET_IVA_RegistDev(int loginHandle, const ZLNET_IVA_REGISTIP& stuHost);

//��ȡ��ע��IP��ַ�б�
ZLNET_API int  CALL_METHOD ZLNET_IVA_GetRegistDevList(int loginHandle, ZLNET_IVA_REGISTIP_LIST& hostList);

//������ע��IP��ַ�б�
ZLNET_API int  CALL_METHOD ZLNET_IVA_SetRegistDevList(int loginHandle, const ZLNET_IVA_REGISTIP_LIST* delHostList);

//������־�洢ģʽ
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetLogMode(long lLoginID, const ZLNET_IVA_LOG_MODE logMode);

//��ȡ��־�洢ģʽ
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetLogMode(long lLoginID, ZLNET_IVA_LOG_MODE& logMode);

//��ȡ����¼������
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetAlarmRecord(long lLoginID, ZLNET_IVA_ALARM_RECORD& config);

//���ñ���¼������
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetAlarmRecord(long lLoginID, ZLNET_IVA_ALARM_RECORD config);

//������Ƶͨ��ģʽ
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetVideoMode(long lLoginID, const ZLNET_IVA_CHANNEL_CONFIG* cfg);

//��ȡ��Ƶͨ��ģʽ
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetVideoMode(long lLoginID, ZLNET_IVA_CHANNEL_CONFIG& chnCfg);

//���ñ�������
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetAlarmAssc(long lLoginID, int nAlarmTpye, const ZLNET_IVA_ALARM_ASSCONFIG* alarmCfg, int emIndex = 0);

//��ȡ��������
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetAlarmAssc(long lLoginID, int nAlarmType, ZLNET_IVA_ALARM_ASSCONFIG& alarmCfg, int emIndex = 0);

//���ñ���������
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetWorkSheet(long lLoginID, int nAlarmType, const ZLNET_IVA_WEEK_SECTION* alarmWorksheet, int emIndex = 0);

//��ȡ����������
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetWorkSheet(long lLoginID, int alarmType, ZLNET_IVA_WEEK_SECTION& alarmWorksheet,int emIndex );

//�����ⲿ��������
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetGpiAssc(long lLoginID, const ZLNET_IVA_GPI_ASSCONFIG* alarmCfg, int chn);

//��ȡ�ⲿ��������
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetGpiAssc(long lLoginID, ZLNET_IVA_GPI_ASSCONFIG& alarmCfg, int	chn);

//�����ⲿ����������
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetGpiWorkSheet(long lLoginID, const ZLNET_IVA_WEEK_SECTION* alarmWorksheet, int chn);

//��ȡ�ⲿ����������
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetGpiWorkSheet(long lLoginID, ZLNET_IVA_WEEK_SECTION& alarmWorksheet, int	chn);

//����ATM��������������
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetATMAreaFaceParm(long lLoginID, const ZLNET_IVA_ATM_ALARMAREA_FACE* alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//��ȡATM��������������
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetATMAreaFaceParm(long lLoginID, ZLNET_IVA_ATM_ALARMAREA_FACE& alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//����ATM��������
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetATMAlarmAreaParm(long lLoginID, const ZLNET_IVA_ATM_DETECTAREA* alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//��ȡATM��������
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetATMAlarmAreaParm(long lLoginID, ZLNET_IVA_ATM_DETECTAREA& alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//����ATM���ò���
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetATMParm(long lLoginID, const ZLNET_IVA_ATM_PARAM* alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1); 

//��ȡATM���ò���
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetATMParm(long lLoginID, ZLNET_IVA_ATM_PARAM& alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1); 

//����ATM�쳣�������ò��� 
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SetATMArnomalFaceParm(long lLoginID, const ZLNET_IVA_ATM_ARNORMAL_FACE_PARAM* alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//��ȡATM�쳣�������ò��� 
ZLNET_API int  CALL_METHOD  ZLNET_IVA_GetATMArnomalFaceParm(long lLoginID, ZLNET_IVA_ATM_ARNORMAL_FACE_PARAM& alarmParm, ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//����ATM������Ƶ��ɫ����
ZLNET_API int  CALL_METHOD	ZLNET_IVA_SetATMFaceColorParm(long lLoginID ,const ZLNET_IVA_ATM_CONFIG_VIDEOCOLOR* alarmParm,ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//��ȡATM������Ƶ��ɫ����
ZLNET_API int  CALL_METHOD	ZLNET_IVA_GetATMFaceColorParm(long lLoginID , ZLNET_IVA_ATM_CONFIG_VIDEOCOLOR& alarmParm,ZLNET_IVA_ATM_INDEX emIndex = ZLNET_IVA_ATM1);

//��ȡ�����û�
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetOnlineConfig(long lLoginID, ZLNET_IVA_USER_ONLINE_LIST&  onlineCfg);

//���������û�
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetOnlineConfig(long lLoginID, const ZLNET_IVA_USER_ONLINE_LIST* onlineCfg);

//��ȡ������
ZLNET_API BOOL CALL_METHOD ZLNET_GetIPFilterCfg(long lLoginID, ZLNET_DEV_IPIFILTER_CFG&  IPFilterCfg);

//���ð�����
ZLNET_API BOOL CALL_METHOD ZLNET_SetIPFilterCfg(long lLoginID, const ZLNET_DEV_IPIFILTER_CFG* IPFilterCfg);

//�����㷨����
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetArithmeticDebug(long lLoginID, ZLNET_IVA_ARITHMETIC_DEBUG&  arithDebug);

//��ȡ�㷨����
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetArithmeticDebug(long lLoginID, const ZLNET_IVA_ARITHMETIC_DEBUG* arithDebug);

//��ȡ��Ƶ�ϴ���Ϣ
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetAudioUploadInfo(long lLoginID, ZLNET_IVA_AUDIO_UPLOAD_INFO& audioInfo);

//��ȡ�����������ͳ�����������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetLicensePlateRegion(long lLoginID, ZLNET_IVA_REGION& licensePlateRegion);

//���ó����������ͳ�����������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetLicensePlateRegion(long lLoginID, ZLNET_IVA_REGION* licensePlateRegion);

//��ȡOSD���������ò���
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetOsdLicensePlateConfig(long lLoginID, ZLNET_IVA_OSD_LICENSE_PALTE_PARAM& osdLicensePlateParam);

//����OSD���������ò���
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetOsdLicensePlateConfig(long lLoginID, ZLNET_IVA_OSD_LICENSE_PALTE_PARAM* osdLicensePlateParam);

//��ȡ�������ò���
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetLicensePlateConfig(long lLoginID, ZLNET_IVA_PLATEID_PARAM& liscensePlateParam);

//���ó������ò���
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetLicensePlateConfig(long lLoginID, ZLNET_IVA_PLATEID_PARAM* liscensePlateParam);

//��ȡ���Ʊ�������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetLicensePlateAlarm(long lLoginID, ZLNET_IVA_PLATEID_ALARM& liscensePlateParam);

//���ó��Ʊ�������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetLicensePlateAlarm(long lLoginID, ZLNET_IVA_PLATEID_ALARM* liscensePlateParam);

//����(һ��)���Ƽ��
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetLicensePlateDetect(long lLoginID, int nChn);

//��ȡ��Ա������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetStaffCountConfig(long lLoginID, ZLNET_IVA_STAFF_COUNT_CONFIG& staffCountConfig);

//������Ա������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetStaffCountConfig(long lLoginID, ZLNET_IVA_STAFF_COUNT_CONFIG* staffCountConfig);

//��ȡ��Ա������-��չ
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetStaffCountConfigEx(long lLoginID, ZLNET_IVA_STAFF_COUNT_CONFIG& staffCountConfig, int nChannel);

//������Ա������-��չ
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetStaffCountConfigEx(long lLoginID, ZLNET_IVA_STAFF_COUNT_CONFIG* staffCountConfig, int nChannel);

//��ȡ�ܽ��������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetBZSBasicSet(long lLoginID, ZLNET_IVA_BZS_BASIC_SETTIINGS& bzsBasic);

//�����ܽ��������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetBZSBasicSet(long lLoginID, ZLNET_IVA_BZS_BASIC_SETTIINGS* bzsBasic);

//��ȡ�ܽ��㷨����
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetBZSAlgorithm(long lLoginID, ZLNET_IVA_BZS_ALGORITHM_PARAM& bzsAlgorithm);

//�����ܽ��㷨����	  
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetBZSAlgorithm(long lLoginID, ZLNET_IVA_BZS_ALGORITHM_PARAM* bzsAlgorithm);

//��ȡ�ܽ�����쳣����
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetBZSCameraAbnormal(long lLoginID, ZLNET_IVA_BZS_CAMERA_ABNORMAL_PARAM& bzsCameraAbnormal);

//�����ܽ�����쳣����
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetBZSCameraAbnormal(long lLoginID, ZLNET_IVA_BZS_CAMERA_ABNORMAL_PARAM* bzsCameraAbnormal);

//��ȡ�ܽ絥�߹���
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetBZSOneLineAlarmRule(long lLoginID, ZLNET_IVA_BZS_CROSS_0NE_LINE_PARAM& oneLineRule);

//�����ܽ絥�߹���
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetBZSOneLineAlarmRule(long lLoginID, ZLNET_IVA_BZS_CROSS_0NE_LINE_PARAM* oneLineRule);

//��ȡ�ܽ�˫�߹���
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetBZSTwoLineAlarmRule(long lLoginID, ZLNET_IVA_BZS_CROSS_TWO_LINE_PARAM& bzsTwoLineRule);

//�����ܽ�˫�߹���
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetBZSTwoLineAlarmRule(long lLoginID, ZLNET_IVA_BZS_CROSS_TWO_LINE_PARAM* bzsTwoLineRule);

//��ȡ�ܽ��������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetBZSAreaAlarmRule(long lLoginID, ZLNET_IVA_BZS_AREA_DETECT_PARAM_PARAM& bzsAreaRule);

//�����ܽ��������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetBZSAreaAlarmRule(long lLoginID, ZLNET_IVA_BZS_AREA_DETECT_PARAM_PARAM* bzsAreaRule);

//��ȡ����ʹ��
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetAlarmEnable(long lLoginID, ZLNET_IVA_ALARM_ENABLE& AlarmEnable, int nChn);

//���ñ���ʹ��
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetAlarmEnable(long lLoginID, ZLNET_IVA_ALARM_ENABLE* AlarmEnable, int nChn);

//��ȡSSB����������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetSSBHallFunc(long lLoginID, ZLNET_IVA_SSB_HALL_FUNC& ssbHallFunc);

//����SSB����������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetSSBHallFunc(long lLoginID, ZLNET_IVA_SSB_HALL_FUNC* pSsbHallFunc);

//��ȡSSB�������쳣����
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetSSBHallAbnormal(long lLoginID, ZLNET_IVA_SSB_ABNORMAL_PARAM& ssbAbnormal);

//����SSB�������쳣����
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetSSBHallAbnormal(long lLoginID, ZLNET_IVA_SSB_ABNORMAL_PARAM* pSsbAbnormal);

//��ȡSSB����ͷ�쳣����
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetSSBCameraAbnormal(long lLoginID, ZLNET_IVA_SSB_CAMERE_ABNORMAL& ssbCameraAbnormal, ZLNET_IVA_SSB_INDEX ssbIndex);

//����SSB����ͷ�쳣����
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetSSBCameraAbnormal(long lLoginID, ZLNET_IVA_SSB_CAMERE_ABNORMAL* pSsbCameraAbnormal, ZLNET_IVA_SSB_INDEX ssbIndex);

//��ȡSSB�ӳ������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetSSBRoomFunc(long lLoginID, ZLNET_IVA_SSB_ROOM_PARAM& ssbRoomParam);

//����SSB�ӳ������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetSSBRoomFunc(long lLoginID, ZLNET_IVA_SSB_ROOM_PARAM* pSsbRoomParam);

//�㷨����
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetBackgroundUpdate(long lLoginID, ZLNET_IVA_BACKGROUND_UPDATE* pBackgroundUpdate);

//��ȡ�����������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetFaceArea(long lLoginID, ZLNET_IVA_FACE_AREA_PARAM& ssbRoomParam, int nIndex = -1);

//���������������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetFaceArea(long lLoginID, ZLNET_IVA_FACE_AREA_PARAM* pSsbRoomParam, int nIndex = -1);

//��ȡ����������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetFaceDetect(long lLoginID, ZLNET_IVA_FACE_DETECT_PARAM& ssbRoomParam, int nIndex = -1);

//��������������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetFaceDetect(long lLoginID, ZLNET_IVA_FACE_DETECT_PARAM* pSsbRoomParam, int nIndex = -1);

//��ȡ�������Ӳ���
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetFaceOverlay(long lLoginID, ZLNET_IVA_FACE_OVERLAY_PARAM& ssbRoomParam, int nIndex = -1);

//�����������Ӳ���
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetFaceOverlay(long lLoginID, ZLNET_IVA_FACE_OVERLAY_PARAM* pSsbRoomParam, int nIndex = -1);

//ģ�ⱨ��(ZLNET_IVA_SSB_ALARM_TYPE��ZLNET_IVA_ATM_ALARM_TYPE)
ZLNET_API int  CALL_METHOD  ZLNET_IVA_SimulateAlarm(long lLoginID, int alarmType, int nChn);

// ����ץͼ�ص�����(jpg)
ZLNET_API void  CALL_METHOD ZLNET_IVA_SetSnapRevCallBack(fZLSnapRev cbSnapRev, DWORD dwUser, DWORD CmdSerial = 0, BOOL bAdd = TRUE);

//ֹͣ�������ܱ����ļ�
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_StopDownload(long lLoginID);

//����ATM������Ϣ�ص�
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_ListenAlarmATMIDVR(long lLoginID, fIdvrAlarmUpATMCallback cbDataCallback, DWORD dwUser);

//������Աͳ����Ϣ�ص�
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_ListenAlarmStaffCountIDVR(long lLoginID, fIdvrAlarmUpStaffCountCallback cbDataCallback, DWORD dwUser);

//���ĳ�����Ϣ�ص�
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_ListenAlarmPlateIdIDVR(long lLoginID, fIdvrAlarmUpPlateIdCallback cbDataCallback, DWORD dwUser);

//��������������Ϣ�ص�
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_ListenAlarmSSBIDVR(long lLoginID, fIdvrAlarmUpSSBCallback cbDataCallback, DWORD dwUser);

//�����ܽ籨����Ϣ�ص�
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_ListenAlarmBZSIDVR(long lLoginID, fIdvrAlarmUpBZSCallback cbDataCallback, DWORD dwUser);

//��������������Ϣ�ص�
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_ListenAlarmFaceIDVR(long lLoginID, fIdvrAlarmUpFaceCallback cbDataCallback, DWORD dwUser);

//�������ܱ�����Ƶ�ϴ�
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetAlarmUpVideoIDVR(long lLoginID, fIdvrAlarmUpVideoCallback cbDataCallback, DWORD dwUser);

// ��ѯʱ����ڵ���������DVR����¼���ļ�
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_QueryRecordFile(LONG lLoginID, int nChannelId, LPZLNET_TIME tmStart, LPZLNET_TIME tmEnd, 
													 int idBeg, int idEnd, void* itemInfo, int maxlen, int *itemCount, int waittime=1000, 
													 ZLNET_IVA_LOG_SEARCH_MODE mode = ZLNET_IVA_SEARCHMODE_DATE, ZLNET_DEVICE_TYPE eDevType = ZLNET_IVA_ATM);

//�������ܱ����ļ�
ZLNET_API int  CALL_METHOD ZLNET_IVA_DownloadFileIDVR(long lLoginID, int id, char* szDirPath, ZLNET_IVA_LOG_DOWNLOAD_MODE mode, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwUserData, ZLNET_DEVICE_TYPE eType = ZLNET_IVA_ATM);

//�������ܱ����ļ�(��Э��)
ZLNET_API long  CALL_METHOD ZLNET_IVA_DownloadFile(long lLoginID, char* szDirPath, ZLNET_IVA_EVENT* struDownloadParm, fZLDownLoadPosCallBack cbDownLoadPos, DWORD dwUserData);

//�����û���Ƶ���� emAudio ��Ƶ���  nInterval���ż�� ��λs   δʹ��
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_StartAudioPlay(long lLoginID, int nAlarmType, int nInterval = 0, int nAudioIndex = 0);

//�ر��û���Ƶ����
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_StopAudioPlay(long lLoginID, int nAlarmType, int nAudioIndex = 0);

//������Ƶ������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetAudioWorkSheet(long lLoginID, int nAlarmType, const ZLNET_IVA_WORKSHEET* pAudioWorksheet, int nAudioIndex = 0);

//��ȡ��Ƶ������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetAudioWorkSheet(long lLoginID, int nAlarmType, ZLNET_IVA_WORKSHEET& audioWorksheet, int nAudioIndex = 0);

//�����豸������1Ϊ����ͳ������㷨�е���������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_ResetDev(long lLoginID, int nChn, int nCommand = 1);

//��������ͳ�ƶ��˱�������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_SetMultiUserParam(long lLoginID, const ZLNET_IVA_STAFF_MULTIUSERPARAM* pMultiParam, int nSCIndex );

//��ȡ����ͳ�ƶ��˱�������
ZLNET_API BOOL CALL_METHOD ZLNET_IVA_GetMultiUserParam(long lLoginID, ZLNET_IVA_STAFF_MULTIUSERPARAM& multiParam, int nSCIndex );

//////////////////////////////////////////////////////////////////////////

//��ȡ�豸������Ϣ
ZLNET_API BOOL CALL_METHOD ZLNET_Dev_Enable(long lLoginID, ZLNET_DEVICE_ENABLE& devEnable);

//��ȡNVRͨ��ģʽ
ZLNET_API BOOL CALL_METHOD ZLNET_Nvr_GetChannelMode(long lLoginID, ZLNET_NVR_CHANNEL_MODE_SUPPORT& chMode);

//����NVRͨ��ģʽ
ZLNET_API BOOL CALL_METHOD ZLNET_Nvr_SetChannelMode(long lLoginID, ZLNET_NVR_CHANNEL_MODE_SUPPORT* pChMode);

//��ȡNVR����ͨ��״̬
ZLNET_API BOOL CALL_METHOD ZLNET_Nvr_GetNvrChnState(long lLoginID, ZLNET_NVR_STATE_NET &chnState);

//��ȡ����IPC��Ƶ��������
ZLNET_API BOOL CALL_METHOD ZLNET_HDIPC_GetVideoParam(long lLoginID, ZLNET_VIDEO_PARAM& videoParam);

//������Ƶ����IPC��Ƶ��������
ZLNET_API BOOL CALL_METHOD ZLNET_HDIPC_SetVideoParam(long lLoginID, ZLNET_VIDEO_PARAM* pVideoParam);

//��ȡUPNP����״̬
ZLNET_API BOOL CALL_METHOD ZLNET_GetUpnpState(long lLoginID, ZLNET_NET_UPNP_STATE& upnpState);

//��ȡRTSP����
ZLNET_API BOOL CALL_METHOD ZLNET_GetRtspCfg(long lLoginID, ZLNET_DEV_RTSP_CONFIG& rtspCfg);

//��ȡwifiʹ��
ZLNET_API BOOL CALL_METHOD ZLNET_GetWifiEnable(long lLoginID, ZLNET_WIFI_ENABLE& wifiEnable);

//����wifiʹ��
ZLNET_API BOOL CALL_METHOD ZLNET_SetWifiEnable(long lLoginID, ZLNET_WIFI_ENABLE* pWifiEnable);

//��ȡwifi���ӷ�ʽ
ZLNET_API BOOL CALL_METHOD ZLNET_GetWifiConnType(long lLoginID, ZLNET_WIFI_CONNECTION_TYPE& wifiType);

//����wifi���ӷ�ʽ
ZLNET_API BOOL CALL_METHOD ZLNET_SetWifiConnType(long lLoginID, ZLNET_WIFI_CONNECTION_TYPE* pWifiType);

//��ȡwifi����
ZLNET_API BOOL CALL_METHOD ZLNET_GetWifiCfg(long lLoginID, ZLNET_DEV_WIFI_CFG& wifiCfg);

//����wifi����
ZLNET_API BOOL CALL_METHOD ZLNET_SetWifiCfg(long lLoginID, ZLNET_DEV_WIFI_CFG* pWifiCfg);

//ɨ��·��������Ϣ
ZLNET_API BOOL CALL_METHOD ZLNET_ScanWifiNetwork(long lLoginID, ZLNETl_WIFI_NETWORK_INFO& networkInfo);

//DDNSע��
ZLNET_API BOOL CALL_METHOD ZLNET_DdnsRegister(long lLoginID, ZLNET_DDNS_REGISTER_INFO* pDdnsRegisterInfo);

//��ȡ˽����͸����
ZLNET_API BOOL CALL_METHOD ZLNET_GetDevStunCfg(long lLoginID, ZLNET_DEV_STUN_CONFIG& devStunCfg);

//��ȡDDNS״̬
ZLNET_API BOOL CALL_METHOD ZLNET_GetDdnsState(long lLoginID, ZLNET_DDNS_STATE& ddnsState);

//����˽����͸����
ZLNET_API BOOL CALL_METHOD ZLNET_SetDevStunCfg(long lLoginID, ZLNET_DEV_STUN_CONFIG* pDevStunCfg);

//��ȡ˽����͸״̬
ZLNET_API BOOL CALL_METHOD ZLNET_GetDevStunState(long lLoginID, ZLNET_DEV_STUN_STATE& devStunState);

//��ȡĬ��ͼ����ɫ
ZLNET_API BOOL CALL_METHOD ZLNET_GetDefaultColor(long lLoginID, ZLNET_COLOR_CFG &defColor);

//��ȡ��̨ģ���������
ZLNET_API BOOL CALL_METHOD ZLNET_GetPtzSimulationCtrlCfg(long lLoginID, ZLNET_485_SIMULATION_CTRL_CFG& ptzSimulation);

//������̨ģ���������
ZLNET_API BOOL CALL_METHOD ZLNET_SetPtzSimulationCtrlCfg(long lLoginID, ZLNET_485_SIMULATION_CTRL_CFG* pPtzSimulation);

//��ȡ�����Ƶ����
ZLNET_API BOOL CALL_METHOD ZLNET_GetDomeCameraVideoParam(long lLoginID, ZLNET_DOME_CAMERA_VIDEO_PARAM& videoParam);

//���������Ƶ����
ZLNET_API BOOL CALL_METHOD ZLNET_SetDomeCameraVideoParam(long lLoginID, ZLNET_DOME_CAMERA_VIDEO_PARAM* pVideoParam);


//��������������Ϣ
ZLNET_API LONG CALL_METHOD ZLNET_ListenRevLink(long lLoginID, fZLRevLink cbRevLink, DWORD dwUser);

//ֹͣ��������������Ϣ
ZLNET_API BOOL CALL_METHOD ZLNET_StopRevLink(long lLoginID);

//���÷������ӷ�������Ϣ(ע��: Ҫ����������Ϣ�Ļ�, һ��Ҫ��ZLNET_ListenRevLink֮�����)
ZLNET_API BOOL CALL_METHOD ZLNET_SetRevLink(long lLoginID, ZLNET_REV_LINK& networkInfo);

//��ȡAEV����
ZLNET_API BOOL CALL_METHOD ZLNET_GetAebGbCfg(long lLoginID, ZLNET_AEB_GB_PROTOCOL& aebGbCfg);

//����AEV����
ZLNET_API BOOL CALL_METHOD ZLNET_SetAebGbCfg(long lLoginID, ZLNET_AEB_GB_PROTOCOL* pAebGbCfg);

//��ȡ������������
ZLNET_API BOOL CALL_METHOD ZLNET_GetKonlanNetCfg(long lLoginID, ZLNET_KONLAN_NET_CONFIG& konlanCfg);

//���ÿ�����������
ZLNET_API BOOL CALL_METHOD ZLNET_SetKonlanNetCfg(long lLoginID, ZLNET_KONLAN_NET_CONFIG* pKonlanCfg);

//��ȡ��������
ZLNET_API BOOL CALL_METHOD ZLNET_GetComType(long lLoginID, ZLNET_COM_TYPE& comType);

//���ô�������
ZLNET_API BOOL CALL_METHOD ZLNET_SetComType(long lLoginID, ZLNET_COM_TYPE* pComType);

//��ȡͨ��¼��״̬
ZLNET_API BOOL CALL_METHOD ZLNET_GetChannelRecordState(long lLoginID, ZLNET_CHANNEL_RECORD_STATE& recordState);

#ifdef __cplusplus
}
#endif

#endif // ZLNETSDK_H