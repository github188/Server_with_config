#ifndef _TERM_NET_STRUCT_
#define _TERM_NET_STRUCT_

#include <vector>

#include "VmsCommon.h"

#pragma pack( push , 1)

/** @brief 1.ʵ����ʼ*/
typedef struct tagTermLivePlayParam
{
	Uint32	uiChannelId;		///< ʵ����Ƶ������ͨ��
	Uint32	uiMainSubFlag;		///< ��������־���ο�ö�� #VmsVideoStreamType
	Uint32	uiTransMode;		///< ����ģʽ �ο�ö�� #VmsTransType
	Uint32	uiStreamType;		///< ������ʽ  �ο�ö�� #VmsMediaPacketType
	CHAR	szRecvAddr[VMS_MAX_IPADDR_LEN];		///< �鲥/������IP��ַ,���ΪDC�����Ļ���Ϊ��������
	Uint32	uiRecvPort;			///< �鲥/�����Ķ˿ں�,���ΪDC�����Ļ���Ϊ��������
	Uint32	uiMcFlag;			///< �Ƿ�Ϊ�鲥,0Ϊ������1Ϊ�鲥	
} TermLivePlayParam;

/** @brief 2.ʵ���ָ����ýṹ��*/
typedef struct tagTermLiveRecover
{
	Uint32      uiEnable;		///< �Ƿ���Ҫ�ָ��ı�׼
	Uint32      uiChannelId;	///< ͨ����            
	Uint32      uiSubIndex;		///< ʵ���Ǹ�ͨ���ڼ�·
	Uint32      uiMainSubFlag;	///< ���������ο�ö�� #VmsVideoStreamType
	Uint32		uiDstIp[VMS_MAX_IPADDR_LEN];	///< Ŀ��IP,�����ĸ��ֽڷ�ʽ�洢��
	Uint32      uiDstPort;		///< Ŀ��port          
	Uint32      uiTransMode;	///< ����ģʽ,�ο�ö�� #VmsTransType
	Uint32      uiStreamingType;///< ��������,�ο�ö�� #VmsMediaPacketType 
	Uint32      uiMcFlag;		///< �Ƿ��鲥          
} TermLiveRecover;

typedef std::vector<TermLiveRecover> TermLiveRecoverList;

/** @brief 3.��̨״̬����*/
typedef struct tagTermPtzStatus
{
	Uint32   uiPanSpeed;		///< ˮƽת��0-255
	Uint32   uiTiltSpeed;		///< ��ֱ�ٶ�0-255
	Uint32   uiFocusSpeed;		///< �۽��ٶ�0-255
	Uint32   uiZoomSpeed;		///< �䱶�ٶ�0-255
	Uint32   uiLockStatus;		///< ������0-�ر� 1-��
	Uint32   uiLightStatus;		///< ���⣬0-�ر� 1-��
	Uint32   uiInfraredStatus;	///< ���⣬0-�ر� 1-��
	Uint32   uiBrushStatus;		///< ��ˢ��0-�ر� 1-��
	Uint32   uiHeatStatus;		///< ���ȣ�0-�ر� 1-��
} TermPtzStatus;

/** @brief 4.OSDʱ������*/
typedef struct tagTermOsdTimeConfig
{
	Uint32	 uiIndex;			///<  ����OSD����,ĿǰΪ0, ֧���ܹ�1��ʱ��OSD.
	Uint32	 uiMainSubFlag;		///<  ���������ο�ö�� #VmsVideoStreamType
	Uint32   uiIsEnable;		///< ��ʾʱ�䣬0-����ʾ��1-��ʾ
	Uint32   uiOsdTimeFormat;	///< ʱ���ʽ���ο�ö�� #VmsOsdTimeFormat
	Uint32   uiOsdDateFormat;	///< ���ڸ�ʽ���ο�ö�� #VmsOsdDateFormat
	Uint32   uiStartX;			///< ��ʼX����ȣ�Ϊ63360�е�X�ݣ�
	Uint32   uiStartY;			///< ��ʼY���߶ȣ�Ϊ8640�е�Y�ݣ�
	Uint32   uiOsdColor;		///< ��ɫ��0-7����-->�죩
	Uint32   uiOsdTransparence;	///< ͸���ȣ�ȡֵ��Χ1~8��Ĭ��ֵ8
	Uint32   uiOsdTimeFreq;		///< ʱ��Ƶ��
} TermOsdTimeConfig;

typedef std::vector<TermOsdTimeConfig> TermOsdTimeList;

/** @brief 5.OSD������Ϣ*/
typedef struct tagTermOsdFieldConfig
{
	Uint32	uiIndex;			///<  ����OSD����,ĿǰΪ0-3, ֧���ܹ�4������OSD.
	Uint32	uiMainSubFlag;		///<  ���������ο�ö�� #VmsVideoStreamType
	Uint32	uiIsEnable;			///<  ��ʾ������Ϣ��0-����ʾ��1-��ʾ
	Uint32  uiOsdColor;			///<  ��ɫ��0-7����-->�죩
	Uint32  uiOsdTransparence;	///<  ͸���ȣ�1-8
	Uint32  uiStartX;			///<  ��ʼX����ȣ�Ϊ63360�е�X�ݣ�
	Uint32  uiStartY;			///<  ��ʼY���߶ȣ�Ϊ8640�е�Y�ݣ�
	Uint32  uiSwitchInterval;	///<  0:����ʹ����ֵ�����л�;1��30��S��
	CHAR    szOsdMainValue[VMS_MAX_OSD_VALUE]; ///< ��ֵ����
	CHAR    szOsdSubValue[VMS_MAX_OSD_VALUE];  ///< ��ֵ����
	Uint32  uiOsdMainType;		///<  0 - �����ַ���,1 - ��������
	Uint32  uiOsdSubType;		///<  0 - �����ַ���,1 - ��������
} TermOsdFieldConfig;

typedef std::vector<TermOsdFieldConfig> TermOsdFieldList;

/** @brief 6.ϵͳʱ����������ṹ��*/
typedef struct tagTermSysTime
{
	Uint32  uiYear;		///< ��
	UCHAR	uiMonth;	///< ��
	UCHAR   uiDay;		///< ��
	UCHAR   uiHour;		///< ʱ
	UCHAR   uiMin;		///< ��
	UCHAR   uiSec;		///< ��
	UCHAR	reserved[3];
} TermSysTime;

/** @brief 7.͸��ͨ������������Ϣ��ѯ*/
typedef struct tagTermTransSaveQuery
{
	Uint32   uiIpAddr[VMS_MAX_IPADDR_LEN];	///<  ע���ǰ����ֽ�ip��ʽ�洢��
	Uint32   uiIpPort;				///< �˿ں�
	Uint32   uiSerialIndex;			///< ��������
	Uint32   uiEnable;				///< ʹ��״̬
} TermTransSaveQuery;

/** @brief 8.��ȡ�ն��豸������������Ϣ*/
typedef struct tagTermGetTypeInfo
{
	Uint32  uiCameraType[VMS_MAX_DEV_CHANNEL_NUM];	///< ��������� 0 -����̨ 1- ������̨
	Uint32  uiPlayerParam[VMS_MAX_DEV_CHANNEL_NUM*2];///< ��16λ������ʽ����16λ����ֱ���, ʵ��ֻʹ��channel_num��,
								///< ��32���ֽڱ�ʾ������������������32���ֽڱ�ʾ��������������
	Uint32  uiDeviceType;		///< �豸���ͣ�0 - EC, 1 -DC, 2- IPC �ο�ö�� #VmsTerminalType
	CHAR    szTypeName[32];		///< �豸���� VG1001/VG1004/VC6210...
	Uint32  uiChannelNum;		///< ͨ������
	Uint32  uiPhyId;			///< 
	Uint32  uiDeviceModel;		///< �豸�ͺ���, ǰ16λ�������ֲ�ͬЭ��(��ͨΪ0x0000, ����Ϊ0x0001), ��16λ��дDEVICE_NAME 
} TermGetTypeInfo;

/** @brief 9.�汾����(��ʱδ�õ�)*/
typedef struct tagTermVersionUpdate
{
	Uint32  uiTaskId;             ///< ����ID(�ն�������ɺ��践��)
	Uint32  uiDevId;              ///< �豸ID(�ն�������ɺ��践��)
	Uint16  uiImageType;          ///< �������ͣ��ο�ö�� #VmsTermUpgradType
	Uint16  uiAddrType;           ///< FTP������IP��ַ����(IPV4/IPV6)���ο�ö�� #VmsIPAddrType
	CHAR    szFtpservIp[VMS_MAX_IPADDR_LEN]; ///< FTP������IP
	CHAR    szUserName[VMS_MAX_NAME_LEN];       ///< FTP�������û���
	CHAR    szPassWord[VMS_PASSWD_LEN];       ///< FTP����������
	CHAR    szKernelName[VMS_MAX_NAME_LEN];     ///< �ں˾�������
	CHAR    szRamdiskName[VMS_MAX_NAME_LEN];    ///< �ļ�ϵͳ��������
} TermVersionUpdate;

/** @brief 10 �汾�Ų�ѯ��������ģʽ(��ʱδ�õ�) */
typedef struct tagTermVersionReport
{
	CHAR   szKernelVersion[VMS_MAX_NAME_LEN];	///< version string
	CHAR   szRamdiskVersion[VMS_MAX_NAME_LEN];  ///< version string
} TermVersionReport;


/** @brief 11.��Ƶ������*/
typedef struct tagTermVideoStreamConfig
{
	Uint32   uiEnableStream;	///< ʹ������0 - ��1 - ��
    Uint32   uiStreamTranType;	///< ���������ͣ��ο�ö�� #VmsTransType
    Uint32   uiStreamType;		///< ������װ���ͣ��ο�ö�� #VmsMediaPacketType
    Uint32   uiEncodeFormat;	///< �����ʽ���ο�ö�� #VmsVideoCodecFormat
    Uint32   uiResolution;		///< �ֱ��ʣ��ο�ö�� #VmsVideoResolution
    Uint32   uiFrameRate;		///< ֡��,
    Uint32   uiBitRate;			///< ����
    Uint32   uiIFrameInterval;	///< I֡�����1- 50
    Uint32   uiImageQuality;	///< ͼ������,��VBRģʽ�¿���
	Uint32   uiEncodeMode;		///< ����ģʽ,VBR��CBR,ϵͳĬ����CBR,�ο�ö�� #VmsVideoECMode
	Uint32   uiPriority;		///< ���ȼ�,�ο�ö�� #VmsVideoPriority (CBRģʽ����Ч:���������ȡ�ͼ����������)
    Uint32   uiSmoothValue;		///< ����ƽ�����ο�ö�� #VmsBitstreamSmooth
    Uint32   uiGopMode;			///< GOPģʽ,�ο�ö�� #VmsVideoGOPMode
    // FIXME
    Uint32   uiQualityLevel;	///< �����ȼ�����ʱ���ã�
	Uint32   uiAddrType;		///< �鲥��ַ���ͣ�0-IPV4��1-IPV6

    Uint32   uiMulticastPort;	///< �鲥�˿ںţ�����ģʽ�²����޸�
    Uint32   uiMulticastAddr[VMS_MAX_IPADDR_LEN];	///< �鲥IP��ַ������ģʽ�²����޸�
} TermVideoStreamConfig;

/** @brief 12.��Ƶ����ͨ��*/
typedef struct tagTermAinChannelConfig
{
	Uint32    uiIsSilent;		///< �Ƿ���,0 - ������,1 - ����
	Uint32    uiIsEnable;		///< ʹ��,0 - ��ʹ��,1 - ʹ��
	Uint32    uiAudioCoding;	///< ��Ƶ����,�ο�ö�� #VmsAudioCoding
	Uint32    uiAudioTrack;		///< ��Ƶ����,�ο�ö�� #VmsAudioTrack ,������ϵͳĬ��Ϊ��������
	Uint32	  uiSamplingRate;	///< ������,G726ʱ��Ч:�ο�ö�� #VmsAudioSampleRate
	CHAR      szAudioinDesc[VMS_MAX_DESC_LEN]; ///< ��Ƶ��������
	Uint32    uiIncrements;		///< ����ֵ,0 - 255
	Uint32    uiAudioBitrate;	///< ����,G726ʱ��Ч���ο�ö�� #VmsAudioBitrate
} TermAinChannelConfig;


/** @brief 13.��Ƶ���ͨ��*/
typedef struct tagTermAoutChannelConfig
{
	Uint32    uiIsSilent;		///< �Ƿ���,0 - ������,1 - ����
	Uint32    uiIsEnable;		///< ʹ��,0 - ��ʹ��,1 - ʹ��
	Uint32	  uiAudioCoding;	///< ��Ƶ����,�ο�ö�� #VmsAudioCoding
	Uint32    uiAudioTrack;		///< ��Ƶ����,�ο�ö�� #VmsAudioTrack
	CHAR      szAudiooutDesc[VMS_MAX_DESC_LEN]; ///< ��Ƶ��������
	Uint32    uiIncrements;		///< �������,0 - 255
} TermAoutChannelConfig;

/** @brief14.�˶��������*/
typedef struct tagTermMotionDetecConfig
{
	Uint8		uiVinChannelIndex;	///< ͨ����
	Uint8		uiMotionAreaIndex;	///< ��������,0 - 3
	Uint8		bIsEnable;			///< �Ƿ�ʹ��
	Uint8		uiSensitivity;		///< ������,1��5
	CHAR		szAreaName[VMS_MAX_NAME_LEN];  ///< ������
	BBitmap8_t  uiAreaMask[VMS_MAX_AREA_MASK]; ///< ����鶨��,1��16x16���ռ1bit
} TermMotionDetecConfig;

typedef std::vector<TermMotionDetecConfig> TermMotionDetecList;

/** @brief 15.ץͼ�������� */
typedef struct tagTermSnapshotConfig
{
	Uint8    uiFtpservIp[VMS_MAX_IPADDR_LEN];	///< FTP������IP 
	CHAR     szUsername[VMS_MAX_NAME_LEN];		///< FTP�������û���
	CHAR     szPassword[VMS_PASSWD_LEN];		///< FTP����������
	CHAR     szPath[VMS_MAX_URL_LEN];           ///< FTP����Ŀ¼
	Uint32   uiNum;                     ///< ץͼ����1~5��
	Uint32   uiTimeval;                 ///< ץͼ���50~500ms
} TermSnapshotConfig;

/** @brief 16. �����PTZ��Ϣ*/
typedef struct tagTermPtzConfig
{
	Uint32   uiPtzAddrCode;			///< ��̨��ַ�룬��̨�����ʱ��Ч��0��255
	Uint32   uiAutoGuardInterval;	///< �Զ��ؿ���ʱ�䣬60��1800(S)��Ĭ��Ϊ300
	CHAR     szPresetName[VMS_MAX_PRESET_POSITION_NUM][VMS_MAX_NAME_LEN]; ///< Ԥ�õ�����
	Uint8	 uiPresetList[VMS_MAX_PRESET_POSITION_NUM];		///< Ԥ�õ������б�0--δ���á�1--����
	Uint32   uiSerialIndex;			///< �󶨵Ĵ��ڱ��
	Uint32   uiGuardPosition;		///< ����λ��0~127
	Uint32   uiPtzProtocol;			///< ��̨����Э��(��̨�����ʱ��Ч)���ο�ö�� #VmsPtzProtocol
	Uint32   uiPtzTranslateMode;	///< ��̨Э�鷭��ģʽ
} TermPtzConfig;

/** @brief 17.IPC��ѧ����*/
typedef struct tagTermIpcOpticalConfig
{
	Uint32   uiCustomData1;
	Uint32   uiCustomData2;
	Uint32   uiCustomData3;
	Uint32   uiCustomData4;
	Uint32   uiCustomData5;
	Uint32   uiUsrAreaLeft;
	Uint32   uiuUsrAreaUp;
	Uint32   uiUsrAreaRight;
	Uint32   uiUsrAreaDown;
	Uint32   uiExposureArea;///< �ع�����
	Uint32   uiBrightness;///< ����
	Uint32   uiContrast;///< �Աȶ�
	Uint32   uiSaturation;///< ���Ͷ�
	Uint32   uiColorTone;///< 
	Uint32   uiSharpness;///< ���
	Uint32   uiWdrEnable;///< 
	Uint32   uiWdrLevel;///< 
	Uint32   uiMirrorFlip;///< ����
	Uint32   uiAwbType;///< �龰ģʽ
	Uint32   uiAwbMode;
	Uint32   uiGetAwbRGain;
	Uint32   uiGetAwbGGain;
	Uint32   uiGetAwbBGain;
	Uint32   uiSetAwbRGain;
	Uint32   uiSetAwbGGain;
	Uint32   uiSetAwbBGain;
	Uint32   uiFlickerCtrl;///< ��Ƶ��ʽ
	Uint32   uiExposureCtrl;///< �ع����
	Uint32   uiExposureValue;///< �ع�ֵ
	Uint32   uiIrisType;///< ��Ȧ����
	Uint32   uiMaxExposureTime;///< ����ع�ʱ��
	Uint32   uiMinExposureTime;///< ��С�ع�ʱ��
	Uint32   uiMaxGain;///< �������
	Uint32   uiMinGain;///< ��С����
	Uint32   uiMaxAnalogGain;///< 
	Uint32   uiMinAnalogGain;///< 
	Uint32   uiMaxDigitalGain;
	Uint32   uiMinDigitalGain;
	Uint32   uiGetExposureTime;
	Uint32   uiGetGain;
	Uint32   uiGetAnalogGain;
	Uint32   uiGetDigitalGain;
	Uint32   uiSetExposureTime;
	Uint32   uiSetGain;
	Uint32   uiSetAnalogGain;
	Uint32   uiSetDigitalGain;
	Uint32   uiIndoorOutdoor;
	Uint32   uiNightSceneEnhanceEnable;
	Uint32   uiNightSceneEnhanceLevel;
	Uint32   uiColorMonoChroma;
	Uint32   uiBlcEnable;
	Uint32   uiBlcLevel;
	Uint32   uiLightLinkMode;
	Uint32   uiLambInEn;
	Uint32   uiLambOutEn;
	Uint32   uiIrCut;
	Uint32   uiExposureSensitivity;///< �ع�������
	Uint32   uiExposurePriority;///< 
	Uint32   uiCurColorTemperature;
	Uint32   uiColorSensitivity;
	Uint32   uiColorTransferTime;
} TermIpcOpticalConfig;

/** @brief 18.���ڻ�����Ϣ*/
typedef struct tagTermSerialConfig
{
	Uint32   uiIndex;					///< ��������	  
	CHAR     szSerialName[VMS_MAX_NAME_LEN];///< ��������
	Uint32   uiSerialType;				///< �������ͣ��ο�ö�� #VmsSerialType
	Uint32   uiSerialMode;				///< ����ģʽ���ο�ö�� #VmsSerialMode 
	Uint32   uiBaudRate;				///< ������,�ο�ö�� #VmsSerialBandrate 
	Uint32   uiDataBit;					///< ����λ���ο�ö�� #VmsSerialDatabit
	Uint32   uiStopBit;					///< ֹͣλ���ο�ö�� #VmsSerialStopbit
	Uint32   uiParityBit;				///< У��λ���ο�ö�� #VmsSerialParitybit
	Uint32   uiFlowControl;				///< ���أ��ο�ö�� #VmsSerialFlowctrl 
} TermSerialConfig;

typedef std::vector<TermSerialConfig> TermSerialList;

/** @brief 19.�������澯����*/
typedef struct tagTermSemaInputConfig
{
	Uint32	 uiIndex;							///< �������澯��������
	CHAR     szSemaName[VMS_MAX_NAME_LEN];		///< ����������
	CHAR     szSemaInputDesc[VMS_MAX_DESC_LEN];	///< ���뿪��������
	Uint32   uiIsEnable;					///< �Ƿ�ʹ��
	Uint32   uiTriggerMode;					///< ���뿪�����澯������ʽ:0 ������1 ����
	Uint32   uiEnableDetect;				///< ��·���ʹ��
	Uint32   uiWorkMode;					///< ����ģʽ���ο�ö�� #VmsSemaTriggerMode
} TermSemaInputConfig;

typedef std::vector<TermSemaInputConfig> TermSemaInputList;


/** @brief 20.�������澯���*/
typedef struct tagTermSemaOutputConfig
{
	Uint32	 uiIndex;						///< �������澯�������
	CHAR     szSemaName[VMS_MAX_NAME_LEN];		///< ����������
	CHAR     szSemaOutputDesc[VMS_MAX_DESC_LEN];///< ����������澯����
	Uint32   uiSemaOutputTime;				///< �������澯�����ʱ��
	Uint32   uiIsEnable;					///< �Ƿ�ʹ��
	Uint32   uiTriggerMode;					///< ����������澯������ʽ:0 ������1 ����
	Uint32   uiEnableDetect;				///< ��·���ʹ��
	Uint32   uiWorkMode;					///< ����ģʽ���ο�ö�� #VmsSemaTriggerMode
} TermSemaOutputConfig;

typedef std::vector<TermSemaOutputConfig> TermSemaOutputList;

/** @brief 21. EC��Ϣ*/
typedef struct tagTermEncoderConfig
{
	Uint32   uiLanguageSet;		 ///< �������ã��ο�ö�� #VmsLanguageSet
	Uint32   uiEnableLocalcache; ///< ���ñ��ػ���
	Uint32   uiEncodeSet;		 ///< ���ײ�:�ο�ö�� #VmsVideoStreamType
	Uint32   uiStandard;		 ///< ��ʽ��P��N���ο�ö�� #VmsStandard
	Uint32   uiAudiocommrId;	 ///< �����Խ���Դid
	Uint32   uiAudiobroadcastId; ///< �����㲥��Դid
	Uint32   uiEnableAlarm;		 ///< �澯ʹ��
	Uint32   uiIsMulticast;		 ///< �Ƿ�֧���鲥
	//FIXME
	Uint32   uiKeepaliveInterval;///< ������ʱ��
	Uint32   uiIsAutofit;		 ///< ��Ӧ����
} TermEncoderConfig;

/** @brief 22. DC��Ϣ*/
typedef struct tagTermDecoderConfig
{
	Uint32   uiLanguageSet;		 ///< �������ã��ο�ö�� #VmsLanguageSet
	Uint32   uiEncodeSet;		 ///< ���ײ�:�ο�ö�� #VmsVideoStreamType
	Uint32   uiStandard;		 ///< ��ʽ��P��N��,�ο�ö�� #VmsStandard
	Uint32   uiEnableAlarm;		 ///< �澯ʹ��
	Uint32   uiKeepaliveInterval;///< ������ʱ��
	Uint32   uiIsMulticast;		 ///< �Ƿ�֧���鲥
	Uint32   uiIsAutofit;		 ///< ��Ӧ����
} TermDecoderConfig;

/** @brief 23. �¶ȸ澯����*/
typedef struct tagTermTempeAlarmConfig
{
	Uint32   uiTempeAlarmUpper;	///< �¶ȸ澯����
	Uint32   uiTempeAlarmLower;	///< �¶ȸ澯����
	CHAR     szTempeAlarmDesc[VMS_MAX_DESC_LEN]; ///< �¶ȸ澯����
	Uint32   uiIsEnable;		///< �Ƿ�ʹ��
} TermTempeAlarmConfig;

/** @brief 24. ��Ƶ�Խ���������*/
typedef struct tagTermAudiocommrInputConfig
{
	Uint32    uiAudiocommrRes;			///< ��Ƶ��Դ��ʶ
	Uint32    uiIsSilent;				///< �Ƿ���
	Uint32    uiAudiocommrInputMethod;	///< ��Ƶ���뷽ʽ(MIC/LINE),�ο�ö�� #VmsAudioCommrInputMethod
	Uint32    uiAudiocommrEncodeFormat;	///< ��Ƶ�����ʽ,�ο�ö�� #VmsAudioCoding
	CHAR      szAudiocommrResDesc[VMS_MAX_DESC_LEN]; ///< ��Ƶ��Դ����
	Uint32    uiAudiocommrSampleRate;	///< �����ʣ�ȡֵ8K
	Uint32    uiAudiocommrBitrate;		///< ��Ƶ���ʣ������ʽΪG726ʱ��Ч,�ο�ö�� #VmsAudioBitrate
	Uint32    uiAudiocommrInputIncrements;	///< �������棺ȡֵ��Χ0~255��Ĭ��ֵ128
	Uint32    uiAudiocommrInputTrack;	///< ��Ƶ��������,�ο�ö�� #VmsAudioTrack
} TermAudiocommrInputConfig;

/** @brief 25.��Ƶ�Խ��������*/
typedef struct tagTermAudiocommrOutputConfig
{
	Uint32   uiAudiocommrRes;			///< ��Ƶ��Դ��ʶ
	Uint32   uiIsSilent;				///< �Ƿ���
	Uint32   uiAudiocommrOutputMethod;	///< ��Ƶ�����ʽ(MIC/LINE),�ο�ö�� #VmsAudioCommrInputMethod
	Uint32   uiAudiocommrEncodeFormat;	///< ��Ƶ�����ʽ,�ο�ö�� #VmsAudioCoding
	CHAR     szAudiocommrResDesc[VMS_MAX_DESC_LEN]; ///< ��Ƶ��Դ����
	Uint32   uiAudiocommrBitrate;		///< ����֡�ʣ�ȡֵ8K
	Uint32   uiAudiocommrOutputIncrements; ///< ������棺ȡֵ��Χ0~255��Ĭ��ֵ128
	Uint32   uiAudiocommrOutputTrack;	 ///< ��������,�ο�ö�� #VmsAudioTrack
} TermAudiocommrOutputConfig;

/** @brief 26.��˽�ڸ�����*/
typedef struct tagTermPrivacyMaskConfig
{
	Uint32   uiVinChannelIndex;	///< ��Ƶ����ͨ������
	Uint32   uiMaskAreaIndex;	///< �ڸ�����,0 - 3
	Uint32   uiIsEnable;		///< �Ƿ�ʹ��
	Uint32   uiMaskColor;		///< �ڸ���ɫ,0 - 7
	Uint32   uiTopLeftX;		///< ����x����
	Uint32   uiTopLeftY;		///< ����y����
	Uint32   uiBottomRightX;	///< ����x����
	Uint32   uiBottomRightY;	///< ����y����
} TermPrivacyMaskConfig;

typedef std::vector<TermPrivacyMaskConfig> TermPrivacyMaskConfigList;

/** @brief 27. ���������*/
typedef struct tagTermCameraConfig
{
	Uint32  uiLongitude;	///< ����
	Uint32  uiLatitude;		///< γ��
	CHAR    szCameraName[VMS_MAX_NAME_LEN];	///< �������
	CHAR    szCameraDesc[VMS_MAX_DESC_LEN];	///< ��ע
	Uint32  uiIsEnable;		///< ʹ��
	Uint32  uiBrightness;	///< ����,0 - 255
	Uint32  uiContrast;		///< �Աȶ�,0 - 255
	Uint32  uiSaturation;	///< ���Ͷ�,0 - 255
	Uint32  uiTone;			///< ɫ��,0 - 255
	Uint32  uiWhiteBlance;	///< ��ƽ��,��IPC��Ч,��Ŀǰ��Ч��
	Uint32  uiCameraType;	///< ���������,�ο�ö�� #VmsCameraType
} TermCameraConfig;

/** @brief 28.�ն��豸�����ṹ��*/
typedef struct tagTermDeviceConfig
{
	Uint8    uiVmServerIpaddr[VMS_MAX_IPADDR_LEN];	///< VM������ip
	Uint32   uiVmServerPort;				///< VM�������˿ں�
	Uint32   uiDeviceRunMode;				///< �豸����ģʽ 0 -�й�ģʽ  1 -��������ģʽ
	Uint32   uiIpVersion;					///< ip���ͣ�
	CHAR     uiDeviceId[VMS_DEVICE_SN_LEN];	///< �豸ID��

	CHAR     szRnId[VMS_MAX_NAME_LEN];			///< ��ID
	Uint32   uiRnEnable;					///< ����ʹ��
	Uint32   uiRnNodeMode;					///< �ڵ㹤��ģʽ 0-�� 1-�� 
	Uint32   uiRnTimeoutCount;				///<  

	Uint32   uiVlanEnable;					///< 
	Uint32   uiNetDefaultVid;				///< ����1��Ĭ��vid
	Uint32   uiCpuDefaultVid;				///< cpu��Ĭ��vid
	Uint32   uiNet2DefaultVid;				///< ����2��Ĭ��vid
	Uint32   uiNet3DefaultVid;				///< ����3��Ĭ��vid
} TermDeviceConfig;

/** @brief 29. ����ͨ�����*/
typedef struct tagTermPhyoutChannelConfig
{
	Uint8		uiPhyoutMode;		///< ����ͨ�������ʽ���ο�ö�� #VmsPhyoutMode
	Uint8		uiFillMethod;		///< ��䷽ʽ����HDMI�Ĵ������ģʽ����Ч,�ο�ö�� #VmsFillMethod
	Uint8		uiDecodeFormat;		///< �����ʽ����ʱ���ã�
	Uint8		uiAudioFormat;		///< ��Ƶ��ʽ����ʱ���ã�
	Uint8		uiAudioTrack;		///< �������ã���ʱ���ã�
	UCHAR		bIsSilent;			///< ������ʶ����ʱ���ã�
	Uint8		uiVolume;			///< �����������ʱ���ã�
	Uint8		uiOutputIndex;		///< ��Ƶ���ѡ����Ƶ����ӿں���Ƶ�ӿڵĶ�Ӧ��ϵ���������ʽΪHDMI�Ĵ������ʱ����ֵ��ʾ�����ĸ�ͨ������Ƶ��Ϊ���
	Uint8		uiStreamType;		///< ��Ƶ������װ���ͣ��ο�VmsMediaPacketType
	Uint8		uiResolution;		///< ֧�ֵ����ֱ��ʣ�����ȡֵ�ο���������VmsVideoResolution
	Uint16		uiSmoothValue;		///< 
	CHAR		szMonitorName[VMS_MAX_NAME_LEN];	///< ����������
	CHAR		szMonitorDesc[VMS_MAX_DESC_LEN];	///< ����������
} TermPhyoutChannelConfig;

/** @brief 30.�ն������������ýṹ��*/
typedef struct tagTermEthernetConfig
{
	Uint32  uiMode;			///< ����ģʽ���ο�ö��VmsNetworkSpeedDuplex
	Uint32  uiMtu;			///< MTU����,576~1500
	Uint8   uiEthIndex;		///< ����������
	Uint8	reserved[3];
} TermEthernetConfig;

/** @brief 31.�ն��豸������Ϣ�ṹ�� */
typedef struct tagTermDeviceCapability
{
	CHAR 		szSerialNumber[VMS_DEVICE_SN_LEN];		///< �豸���к�
	Uint32		uiCameraType[VMS_MAX_DEV_CHANNEL_NUM];	///< ��������� 0 -����̨ 1- ������̨���ο�ö�� #VmsCameraType
	Uint32		uiDeviceType;							///< �豸���ͣ�0 - EC, 1 -DC, 2- IPC �ο�ö�� #VmsTerminalType
	CHAR		szDeviceModelName[VMS_MAX_NAME_LEN];	///< �豸���� VG1001/VG1004/VC6210...
	Uint32      uiSerialNum;            ///< ���ڸ���
	Uint32      uiVideoInChannelNum;    ///< ��Ƶ����ͨ������
	Uint32      uiVideoOutChannelNum;   ///< ��Ƶ���ͨ������
	Uint32      uiAudioInChannelNum;    ///< ��Ƶ����ͨ������
	Uint32      uiAudioOutChannelNum;   ///< ��Ƶ���ͨ������
	Uint32      uiSemaInputNum;         ///< �������������
	Uint32      uiSemaOutputNum;        ///< �������������
	Uint32      uiPrivacyMaskNum;       ///< ֧�ֵ���˽�ڱθ���
	Uint32      uiMotionAreaNum;        ///< ֧�ֵ��ƶ�������
	Uint32      uiOsdTimeNum;           ///< ʱ��OSD����
	Uint32      uiOsdFieldNum;          ///< ����OSD����
	Uint32      uiPhyoutSplitMaxNum;    ///< ֧�ֵ���������
} TermDeviceCapability;

/** @brief 31.ip��Ϣ���ýṹ�� */
typedef struct tagTermNetIpConfig
{
	Uint8  iIp[VMS_MAX_IPADDR_LEN];		///< IP��ַ
	Uint8  iMask[VMS_MAX_IPADDR_LEN];	///< ��������
	Uint8  iGateway[VMS_MAX_IPADDR_LEN];///< ����

	CHAR   szPppoeUsername[VMS_PPPOE_NAME_PASSWD_LEN];	///< ��ʱ����������޸ı��ṹ�壬�Ȼ�ȡ����ԭֵ����
	CHAR   szPppoePasswd[VMS_PPPOE_NAME_PASSWD_LEN];	///< ��ʱ����������޸ı��ṹ�壬�Ȼ�ȡ����ԭֵ����

	Uint8  iGetIpMode;	///< ��ȡ��ʽ����ʱ����������޸ı��ṹ�壬�Ȼ�ȡ����ԭֵ����
	Uint8  iEthIdx;		///< �������к�
	Uint8  iIpVersion;	///< IP��ַ����(IPV4/IPV6)���ο�ö�� #VmsIPAddrType
	Uint8  reserved;
} TermNetIpConfig;

#pragma pack(pop)
#endif    //  _TERM_NET_STRUCT_