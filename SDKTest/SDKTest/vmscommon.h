#ifndef __VMS_COMMON_H__
#define __VMS_COMMON_H__

#define VMS_MAX_IPADDR_LEN			(32)
#define VMS_MAX_VENDOR_LEN			(32)

#define VMS_MAX_ERR_DESC_LEN		(128)

#define VMS_MAX_NAME_LEN			(128)
#define VMS_MAX_DESC_LEN			(128)

#define VMS_MAX_FILE_PATH			(128)
#define VMS_MAX_URL_LEN				(256)

/* Macros for terminal params */
#define VMS_MAX_TIME_OSD_NUM		(1)
#define VMS_MAX_FIELD_OSD_NUM		(4)

//
/* �豸���кų��� */
#define VMS_DEVICE_SN_LEN			(64)

#define VMS_TASK_PARAM_LEN			(256)

#define VMS_MAX_IQN_LEN				(128)

// Ĭ�Ϸ����������˿�
#define DEFAULT_VMS_PORT			(19999)

/* �豸���кų��� */
#define VMS_DEVICE_SN_LEN			(64)

/* һ��vdisk������ӵ�еĴ������� */
#define VMS_MAX_DISK_NUM_PER_VDISK	(32)

/* ÿ����Դ���Թ����������Դ���� */
#define VMS_MAX_RES_MAP_NUM			(64)

//2013.6.7���

#define VMS_MAX_OSD_VALUE			(64)
#define VMS_RESOURCE_ORG_PATH		(64)

/* verdor name "ntech" or "other" */

#define VMS_VENDOR_NAME_LOCAL  "ntech"
#define VMS_VENDOR_NAME_H3C  "H3C"
#define VMS_VENDOR_NAME_ONU  "ONU"
#define VMS_VENDOR_NAME_OTHER  "other"

/* �ַ�����ʾ�İ汾����󳤶� */
#define VMS_VERSION_STR_LEN			(32)

#define VMS_VDISK_NAME_LEN			(32)

/* IPSAN���ݶ˿�������󳤶� */
#define VMS_PORT_NAME_LEN			(16)

/* �ܹ�ͬһIPSAN�����VOD���� */
#define VMS_MAX_VOD_PER_IPSAN		(16)

#define VMS_MAX_IQN_LEN				(128)

/* IPSAN�û��������볤�� */
#define VMS_IPSAN_USER_LEN			(32)
#define VMS_IPSAN_PASSWD_LEN		(32)

//FTP·������
#define VMS_FTP_PATH_LEN			(64)

//
#define VMS_TASK_PARAM_LEN			(256)

/* license���� */
#define VMS_MAX_LICENSE_KEY_LEN		(32)

#define VMS_PASSWD_LEN				(32)
#define VMS_EMAIL_LEN				(32)
#define VMS_PHONE_NO_LEN			(20)

#define VMS_ROLE_TYPE_LEN			(32)

#define VMS_MAX_AREA_MASK			(1024)

#define VMS_MACDDR_LEN				(16)

#define VMS_MAX_LIST_LEN			(32)

//20130710
#define VMS_MAX_DEV_CHANNEL_NUM		(32)
#define VMS_MAX_PRESET_POSITION_NUM	(128)
#define VMS_PPPOE_NAME_PASSWD_LEN	(128)
#define VMS_DAYS_OF_WEEK			(7)
#define VMS_HOURS_OF_DAY			(24)
#define VMS_MACDDR_LEN				(16)
#define VMS_IFC_NAME_LEN			(16)




/*ErrorLanguage set*/
typedef enum
{
	VmsErrorLanguageEN = 0,
	VmsErrorLanguageCH,

	VmsErrorLanguageEnd
} VmsErrorLanguage;

/*��������*/
typedef enum
{
	VmsLanguageSetCH = 0,
	VmsLanguageSetEN,

	VmsLanguageSetEnd
} VmsLanguageSet;

//IP��ַ����
typedef enum tagVmsIPAddrType
{ 
	VmsIPAddrTypeIPV4, 
	VmsIPAddrTypeIPV6

} VmsIPAddrType;



//������ͺ�
typedef enum
{
	VmsCameraModelNormal = 0,    /* ��ͨ����� */
	VmsCameraModelGun,			/* ǹ�� */
	VmsCameraModelBall,			/* ��� */
	VmsCameraModelIncorporate,	/* һ��� */
	VmsCameraModelGB,			/* ���� */
	VmsCameraModelHalfBall,		/* ����� */

	VmsCameraModelEnd
} VmsCameraModel;


// ��Ƶ������
typedef enum
{
	VmsVideoStreamTypeMain = 0,		// ����
	VmsVideoStreamTypeSub,			// ����
	VmsVideoStreamTypeSubSub,		// �θ���, �ն���δ�ṩ�θ�������

	VmsVideoStreamTypeEnd
} VmsVideoStreamType;

// ��Ƶ����������
typedef enum
{
	VmsTransTypeUDP = 0,
	VmsTransTypeTCP,

	VmsTransTypeEnd
} VmsTransType;

typedef enum
{
	VmsStreamDirectionSendRecv = 0,
	VmsStreamDirectionSendOnly,
	VmsStreamDirectionRecvOnly,

	VmsStreamDirectionEnd
} VmsStreamDirection;

// ��Ƶ������װ����*/
typedef enum
{
	VmsMediaPacketTypeRTP = 0,
	VmsMediaPacketTypeTS,
	VmsMediaPacketTypePS,
	VmsMediaPacketTypeES,

	VmsMediaPacketTypeEnd
} VmsMediaPacketType;

// ��Ƶ�����ʽ
typedef enum
{
	VmsVideoCodecFormatH264 = 0,
	VmsVideoCodecFormatH263,
	VmsVideoCodecFormatMJPEG,
	VmsVideoCodecFormatMPEG2,
	VmsVideoCodecFormatMPEG4,

	VmsVideoCodecFormatEnd
} VmsVideoCodecFormat;

// ��Ƶ�ֱ���
typedef enum
{
	VmsVideoResolutionQCIF = 0,			//  TODO: ע��
	VmsVideoResolutionCIF,
	VmsVideoResolution2CIF,
	VmsVideoResolution4CIF,
	VmsVideoResolutionD1,
	VmsVideoResolution720P,
	VmsVideoResolution1080I,
	VmsVideoResolution1080P,
	VmsVideoResolutionUnknown,	// �����޷��жϵĵ���������

	VmsVideoResolutionEnd
} VmsVideoResolution;

// GOPģʽ
typedef enum
{
	VmsVideoGOPModeI = 0,		// TODO: ע��
	VmsVideoGOPModeIP,
	VmsVideoGOPModeIBP,
	VmsVideoGOPModeIBBP,

	VmsVideoGOPModeEnd
} VmsVideoGOPMode;

// ��Ƶ����ģʽ
typedef enum
{
	VmsVideoECModeCBR = 0,			// TODO: ע��
	VmsVideoECModeVBRBest,
	VmsVideoECModeVBRBetter,
	VmsVideoECModeVBRGood,
	VmsVideoECModeVBRBad,
	VmsVideoECModeVBRWorse,

	VmsVideoECModeEnd
} VmsVideoECMode;

// ��Ƶ�������ȼ�
typedef enum
{
	VmsVideoPriorityFrameRate = 0,		// ֡������
	VmsVideoPriorityBitRate,			// ��������
	VmsVideoPriorityEnd
} VmsVideoPriority;

// ¼���ѯ����
typedef enum
{
	VmsRecordSearchTypeAll = 0,
	VmsRecordSearchTypeTime = 0,
	VmsRecordSearchTypeEvent,
	VmsRecordSearchTypeTag,
	VmsRecordSearchTypeManual,

	VmsRecordSearchTypeEnd
} VmsRecordSearchType;

// ¼������
typedef enum
{
	VmsRecordTypeNormal = 0,
	VmsRecordTypeAlarm,

	VmsRecordTypeEnd
} VmsRecordType;

/*standard: ��ʽ*/
typedef enum
{
	/* SD standard */
	VmsStadnardPAL = 0,
	VmsStadnardNTSC,

	/* HD standard */
	VmsStadnard720P25,
	VmsStadnard720P30,
	VmsStadnard720P50,
	VmsStadnard720P60,
	VmsStadnard1080I50,
	VmsStadnard1080P25,
	VmsStadnard1080I60,
	VmsStadnard1080P30,
	VmsStadnard1080P50,
	VmsStadnard1080P60,

	VmsStadnardEnd
} VmsStandard;

/*audio_coding: ��Ƶ�����ʽ*/
typedef enum
{
	VmsAudioG711A = 0,
	VmsAudioG711U,
	VmsAudioG726,
	VmsAudioG729AB,

	VmsAudioCodingEnd
} VmsAudioCoding;

/*audio_track: ��Ƶ����*/
typedef enum
{
	VmsAudioTrackMono = 0,
	VmsAudioTrackStereo,
	VmsAudioTrackLeft,
	VmsAudioTrackRight,

	VmsAudioTrackEnd
} VmsAudioTrack;

/*audio sampling_rate: ��Ƶ������*/
typedef enum
{
	VmsAudioSample8K = 0,
	VmsAudioSample16K,
	VmsAudioSample32K,
	VmsAudioSample48K,
	VmsAudioSample64K,

	VmsAudioSampleEnd
} VmsAudioSampleRate;

/*audio_bitrate: ��Ƶ����*/
typedef enum
{
	VmsAudioG726_16K = 0,
	VmsAudioG726_24K,
	VmsAudioG726_32K,
	VmsAudioG726_40K,

	VmsAudioBitrateEnd
} VmsAudioBitrate;

/*camera_type: ���������*/
typedef enum
{
	VmsCameraWithPtz,      /*����̨*/
	VmsCameraWithoutPtz,   /*������̨*/

	VmsCameraTypeEnd
} VmsCameraType;

/*ptz_protocol: ��̨Э��*/
typedef enum
{
	VmsPtzProtoAlec = 0,
	VmsPtzProtoAlecD,
	VmsPtzProtoAlecP,
	VmsPtzProtoMinkingD,
	VmsPtzProtoMinkingP,
	VmsPtzProtoPelcoD,
	VmsPtzProtoPelcoP,
	VmsPtzProtoVisca,
	VmsPtzProtoYaanSony,
	VmsPtzProtoYaanSanyO,
	VmsPtzProtoCbytSanyO,

	VmsPtzProtoEND
} VmsPtzProtocol;

/*audiocommr_input_method: ��Ƶ�Խ����뷽ʽ*/
typedef enum
{
	VmsAudioMic = 0,
	VmsAudioLineIn,

	VmsAudioMethodEnd
} VmsAudioCommrInputMethod;

/*transchannel_type: ͸��ͨ������*/
typedef enum
{
	VmsTranschTypeS2S = 0,
	VmsTranschTypeS2IP,

	VmsTranschTypeEnd
} VmsTranschType;

/*transchannel.current_state: ͸��ͨ����ǰ״̬*/
typedef enum
{
	VmsTranschStatNeedRecover = 0,
	VmsTranschStatNotNeedRecover,

	VmsTranschStatEnd
} VmsTranschState;

/*transchannel.protocol: ͸��ͨ������Э��*/
typedef enum
{
	VmsTranschUDP = 0,
	VmsTranschTCP,

	VmsTranschEnd
} VmsTranschProtocol;

/*serial_type: ��������*/
typedef enum
{
	VmsSerialRS232 = 0,
	VmsSerialRS422,
	VmsSerialRS485,

	VmsSerialTypeEnd
} VmsSerialType;

/*serial_mode: ����ģʽ*/
typedef enum
{
	VmsSerModeConsole = 0,     /*��������̨*/
	VmsSerModeTransch,     /*����͸��ͨ��*/
	VmsSerModePtzCtrl,    /*������̨����*/
	VmsSerModeExternMoudle,/*��չģ��ʹ��*/
	VmsSerModeScada,         /*������̨ʹ��*/
	VmsSerModePtzTransch,	/*��̨͸��ͨ��ģʽ*/

	VmsSerModeEnd
} VmsSerialMode;

/*serial.baudrate: ���ڲ�����*/
typedef enum
{
	VmsBaudrate1200 = 0,
	VmsBaudrate2400,
	VmsBaudrate4800,
	VmsBaudrate9600,
	VmsBaudrate14400,
	VmsBaudrate19200,
	VmsBaudrate38400,
	VmsBaudrate57600,
	VmsBaudrate115200,

	VmsBaudrateEnd
} VmsSerialBandrate;

/*serial.databit: ��������λ*/
typedef enum
{
	VmsDatabit5Bit,
	VmsDatabit6Bit,
	VmsDatabit7Bit,
	VmsDatabit8Bit,

	VmsDatabitEnd
} VmsSerialDatabit;

/*serial.stopbit:������ֹͣλ*/
typedef enum
{
	VmsStopbit1Bit,
	VmsStopBit1P5Bit,
	VmsStopbit2Bit,

	VmsStopbitEnd
} VmsSerialStopbit;

/*serial.paritybit: ����У��λ*/
typedef enum
{
	VmsParitybitNone,     /*��У��*/
	VmsParitybitOdd,      /*��У��*/
	VmsParitybitEven,     /*żУ��*/
	VmsParitybitSymbol,	 /*��־У��*/
	VmsParitybitBlank,	 /*�ո�У��*/

	VmsParitybitEnd
} VmsSerialParitybit;

/*serial.flowcontrol: ��������*/
typedef enum
{
	VmsSerFlowctrlNone,          /*��*/
	VmsSerFlowctrlSoftware,      /*�������*/
	VmsSerFlowctrlHardware,      /*Ӳ������*/

	VmsSerFlowctrlEnd
} VmsSerialFlowctrl;

/*sema_in/ouput: trigger_mode*/
typedef enum
{
	VmsSemaLowLevel,           /*�͵�ƽ*/
	VmsSemaHighLevel,          /*�ߵ�ƽ*/

	VmsSemaModeEnd
} VmsSemaTriggerMode;

/*smooth_value: ����ƽ��ʹ�ܿ���*/
typedef enum
{
	VmsBitstreamSmoothDisable,
	VmsBitstreamSmoothEnable,

	VmsBitstreamSmoothEnd
} VmsBitstreamSmooth;

/*alarm_type: �澯����*/
typedef enum
{
	VmsAlarmTypeTempeAlert = 0,       /*�¶ȸ澯*/
	VmsAlarmTypeVideoLoss,        /*��Ƶ��ʧ*/
	VmsAlarmTypeVideoMotion,      /*�˶����*/
	VmsAlarmTypeSemaInput,        /*����������*/
	VmsAlarmTypeFanAlert,         /*���ȸ澯*/
	VmsAlarmTypeStorageFailed,    /*�洢ʧ��*/
	VmsAlarmTypeEnv,               /* �����豸�澯  */
	VmsAlarmTypeDiskError,        /*���̹���*/
	VmsAlarmTypeVideoRecover,     /*��Ƶ�ָ�*/
	VmsAlarmTypeTempeRecover,     /*�¶Ȼָ�*/
	VmsAlarmTypeOther,             /*����*/

	VmsAlarmTypeEnd
} VmsAlarmType;

/*osd_time_format: OSD ʱ����ʾ��ʽ*/
typedef enum
{
	VmsTimeFormat1,      /*XX:XX:XX*/
	VmsTimeFormat2,      /*XX:XX:XX p.m.*/
	VmsTimeFormat3,      /*XX:XX:XX PM*/
	VmsTimeFormat4,      /*���� XX:XX:XX*/

	VmsTimeFormatEnd
} VmsOsdTimeFormat;

/*osd_date_format: OSD ������ʾ��ʽ*/
typedef enum
{
	VmsDateFormat1 = 0,   /*XXXX-XX-XX*/
	VmsDateFormat2,       /*XX-XX-XXXX*/
	VmsDateFormat3,       /*XXXX/XX/XX*/
	VmsDateFormat4,       /*XXXX��XX��XX��*/

	VmsDateFormatEnd
} VmsOsdDateFormat;

/*osd_field_type: ��������*/
typedef enum
{
	VmsOsdFiledWord = 0,        /*����*/
	VmsOsdFiledPicture,         /*ͼƬ*/

	VmsOsdFiledEnd
} VmsOsdFiledType;

//��̨����
typedef enum
{
	VmsPtzCmdNull = 0X00,

	VmsPtzCmdIrisCloseStop,	
	VmsPtzCmdIrisClose,
	VmsPtzCmdIrisOpenStop,
	VmsPtzCmdIrisOpen,
	VmsPtzCmdFocusNearStop,

	VmsPtzCmdFocusNear,
	VmsPtzCmdFocusFarStop,
	VmsPtzCmdFocusFar,
	VmsPtzCmdZoomTeleStop,
	VmsPtzCmdZoomTele,

	VmsPtzCmdZoomWideStop,
	VmsPtzCmdZoomWide,
	VmsPtzCmdTiltUp,
	VmsPtzCmdTiltDown,
	VmsPtzCmdPanRight,

	VmsPtzCmdPanLeft,
	VmsPtzCmdLeftUp,
	VmsPtzCmdLeftDown,
	VmsPtzCmdRightUp,
	VmsPtzCmdRightDown,

	VmsPtzCmdTiltUpStop,
	VmsPtzCmdTiltDownStop,
	VmsPtzCmdPanRightStop,
	VmsPtzCmdPanLeftStop,
	VmsPtzCmdLeftUpStop,

	VmsPtzCmdLeftDownStop, 
	VmsPtzCmdRightUpStop,
	VmsPtzCmdRightDownStop,
	VmsPtzCmdSetPreset,
	VmsPtzCmdCallPreset,

	VmsPtzCmdDelPreset,
	VmsPtzCmdDoCruise,
	VmsPtzCmdStopCruise,
	VmsPtzCmdBrushOn,
	VmsPtzCmdBrushOff,

	VmsPtzCmdLightOn,
	VmsPtzCmdLightOff,
	VmsPtzCmdInfraredOn,
	VmsPtzCmdInfraredOff,
	VmsPtzCmdHeaterOn,

	VmsPtzCmdHeaterOff,
	VmsPtzCmdSetPanSpeed,
	VmsPtzCmdSetTiltSpeed,
	VmsPtzCmdSetFouceSpeed,
	VmsPtzCmdSetZoomSpeed,

	VmsPtzCmdLock,
	VmsPtzCmdUnlock,
	VmsPtzCmdRunParamGet,

	/* �����������������+sanyo��о */
	VmsPtzCmdAutoFocuson, // �Զ��۽�
	VmsPtzCmdManualFocuson, // �ֶ��۽�
	VmsPtzCmdWhiteMode,		// ��ƽ��ģʽ
	VmsPtzCmdAutoIrison,	// �Զ���Ȧ
	VmsPtzCmdManualIrison,	// �ֶ���Ȧ
	VmsPtzCmdBlacklightOff,	// ����ģʽ��
	VmsPtzCmdMultiBlacklight,// ��㱳��
	VmsPtzCmdCenterBlacklight,// ���ı���
	VmsPtzCmdMaskBlacklight,  // ���򱳹�
	VmsPtzCmdAgOn,			// ���濪
	VmsPtzCmdAgOff,			// �����
	VmsPtzCmdGammaoff,		// ٤��У����
	VmsPtzCmdGammaon,		// ٤��У����
	VmsPtzCmdGammasmart1,	// ٤������1
	VmsPtzCmdGammasmart2,    // ٤������2
	VmsPtzCmdOsdZmrtOff,	// ������ʾ��
	VmsPtzCmdOsdZmrtOn,   // ������ʾ��
	VmsPtzCmdVideooutMode, //�ֱ����л�
	VmsPtzCmdNtpaChange,	//��ʽ�л�

	/* �Ű���̨�����µ����� */
	/* ɨ��������� */
	VmsPtzCmdSetScanLeftEdge,
	VmsPtzCmdSetScanRightEdge,
	VmsPtzCmdSetScanSpeed,
	VmsPtzCmdStartScan,
	VmsPtzCmdStopScan,

	/* Ѳ����� */
	VmsPtzCmdSetTrackStartPoint,
	VmsPtzCmdSetTrackStopPoint,
	VmsPtzCmdStartTrack,
	VmsPtzCmdStopTrack,

	/* �������� */
	VmsPtzCmdAuxSwitchOn,
	VmsPtzCmdAuxSwitchOff,

	VmsPtzCmd3Dcontrol,//��ά����

	VmsPtzCmdSum

} VmsPtzCmd;

/*�ն�����*/
typedef enum 
{
	VmsTerminalTypeEC,
	VmsTerminalTypeDC,
	VmsTerminalTypeIPC,

	VmsTerminalTypeEnd
} VmsTerminalType;

/* ����ͨ�������ʽ */
typedef enum
{
	VmsPhyoutModeBnc,		//BNC���,Ĭ��ֵ
	VmsPhyoutModeHdmi1W,	//HDMIһ�������
	VmsPhyoutModeHdmi4W		//HDMI�Ĵ������
} VmsPhyoutMode;

/* ��䷽ʽ,��HDMI�Ĵ������ģʽ����Ч */
typedef enum
{
	VmsFillMethodHdmi4Extend,		//��������(Ĭ��ֵ)
	VmsFillMethodHdmi4AddBlack		//�Ӻڱ�
} VmsFillMethod;

/* ����ģʽ*/
typedef enum 
{
	VmsNet10MbpsHalf = 0,
	VmsNet10MbpsFull = 1,
	VmsNet100MbpsHalf = 2,
	VmsNet100MbpsFull = 3,
	VmsNet1000MbpsHalf = 4,
	VmsNet1000MbpsFull = 5,
	VmsNetAUTO_NEGOTIATE = 6
} VmsNetworkSpeedDuplex;



typedef struct tagVmsStatus
{
	Int32	iStatus;		// 0: �ɹ�; ����:ʧ��
	Int32	iErrCode;		// �ο�SdkError.h
	CHAR	szErrDesc[VmsErrorLanguageEnd][VMS_MAX_ERR_DESC_LEN];	// ��������
} VmsStatus;

typedef struct tagVmsTime
{
	Uint32	uiYear;		///< ��
	Uint32  uiMonth;	///< ��
	Uint32  uiDay;		///< ��
	Uint32  uiHour;		///< ʱ
	Uint32  uiMinute;	///< ��
	Uint32  uiSecond;	///< ��
} VmsTime;

/*��������*/
typedef struct tagVmsDate
{
	Uint16 year;	///< ��
	Uint8  month;	///< ��
	Uint8  day;		///< ��
} VmsDate;

//2013.3.21���
/* ��TCע����豸���� */
typedef enum
{
	VmsDevicTypeNVR = 0,
	VmsDevicTypeEC,
	VmsDevicTypeDC,
	VmsDevicTypeIPC,
	VmsDevicTypeMS,
	VmsDevicTypeDM,
	VmsDevicTypeVOD,
	VmsDeviceTypeEM,		/* �������澯�豸 */
	VmsDeviceTypeIMS,		/* IMS�澯�豸 */
	VmsDeviceTypeMATP,

	VmsDevicTypeEnd
} VmsDeviceType;

/*�豸�ͺ�:��Ҫ�������ֲ�ͬͨ����EC*/
typedef enum
{
	VmsDeviceModelEcSD1CH = 0,
	VmsDeviceModelEcSD2CH,
	VmsDeviceModelEcSD4CH,
	VmsDeviceModelEcSD8CH,
	VmsDeviceModelEcSD16CH,

	VmsDeviceModelEnd
} VmsDeviceModelEC;

/*�豸�ͺ�:��Ҫ�������ֲ�ͬͨ����DC*/
typedef enum
{
	VmsDeviceModelDcSD1CH = 0,
	VmsDeviceModelDcSD2CH,
	VmsDeviceModelDcSD4CH,
	VmsDeviceModelDcSD8CH,
	VmsDeviceModelDcSD16CH,

	VmsDeviceModelDcEnd
} VmsDeviceModelDc;


/*�豸�ͺ�:��Ҫ�������ֲ�ͬ���͵�IPC*/
typedef enum
{
	VmsDeviceModelIPCVC1120_EB,
	VmsDeviceModelIPCVC1120_2F,
	VmsDeviceModelIPCVC1220_EB,
	VmsDeviceModelIPCVC1220_2F,
	VmsDeviceModelIPCVC6120_F,
	VmsDeviceModelIPCVC6120_2F,
	VmsDeviceModelIPCVC6110_F,
	VmsDeviceModelIPCVC6110_2F,
	VmsDeviceModelIPCVC6210_F,
	VmsDeviceModelIPCVC6210_2F,

	VmsDeviceModelIPCEnd
} VmsDeviceModelIpc;


#if 1

/* ������ */
typedef enum
{
	VmsDomainTypeLocal = 0x00,  ///< ����
	VmsDomainTypeSup,			///< �ϼ���
	VmsDomainTypeSub,			///< �¼��� 
	VmsDomainTypeSibling,		///< ͬ����(��Ϊ���¼�)
	VmsDomainTypeEnd
} VmsDomainType;

/*Ȩ������*/
#ifdef MINE_PRODUCT
typedef enum {
	VmsPrivTypeLive = 0x01,		///< ʵ��
	VmsPrivTypePlayback = 0x02,	///< �ط�
	VmsPrivTypeMap = 0x04,		///< ��ͼ
	PVmsPrivTypeAlarm = 0x08,	///< �澯
	VmsPrivTypeConfig = 0x10,	///< ����
	VmsPrivTypeManage = 0x20,	///< ҵ�����
	VmsPrivTypeMaintain = 0x40, ///< ϵͳά��
	VmsPrivTypeEnv = 0x80		///< ���������Ȩ��
} VmsPrivType;
#else
typedef enum {
	VmsPrivTypeLive = 0x01,		///< ʵ��
	VmsPrivTypePlayback = 0x02,	///< �ط�
	VmsPrivTypeMap = 0x04,		///< ��ͼ
	PVmsPrivTypeAlarm = 0x08,	///< �澯
	VmsPrivTypeConfig = 0x10,	///< ����
	VmsPrivTypeManage = 0x20,	///< ҵ�����
	VmsPrivTypeMaintain = 0x40  ///< ϵͳά��
} VmsPrivType;
#endif


/* ����ʹ������ */
typedef enum {
	VmsDiskUsedTypeAvail,		///< Avail
	VmsDiskUsedTypeGlobalSP,	///< GLOBAL_SP
	VmsDiskUsedTypeLeftover,	///< LEFTOVER
	VmsDiskUsedTypeVdiskrcon,	///< VDISKRCON
	VmsDiskUsedTypeVdisk,		///< VDISK
	VmsDiskUsedTypeVdiskinit,	///< VDISKINIT
	VmsDiskUsedTypeVdiskSP		///< VDISK_SP
} VmsDiskUsedType;

/* ���̽ӿ����� */
typedef enum {
	VmsDiskTypeSAS,		///< SAS
	VmsDiskTypeSAS_S,	///< SAS_S
	VmsDiskTypeSATA,	///< SATA
	VmsDiskTypeSATA_S	///< SATA_S
} VmsDiskType;

/* ����״̬ */
typedef enum {
	VmsDiskStatusUp,			///< Up
	VmsDiskStatusSpunDown,		///< SPUN_DOWN
	VmsDiskStatusWaring,		///< WARNING
	VmsDiskStatusError,			///< ERROR
	VmsDiskStatusNotPresent,	///< NOT_PRESENT
	VmsDiskStatusDisconnect,	///< DISCONNECT
	VmsDiskStatusUnknow			///< UNKNOW
} VmsDiskStatus;

/* ���̽���״̬ */
typedef enum {
	VmsDiskHealthOk,	///< ����
	VmsDiskHealthSick	///< ������
} VmsDiskHealth;

/* RAID���� */
typedef enum {
	VmsRAID0 = 0,
	VmsRAID1 = 1,
	VmsRAID3 = 3,
	VmsRAID5 = 5,
	VmsRAID6 = 6,
	VmsRAID10 = 10,
	VmsRAID50 = 50,
	VmsNRAID = 100,
	VmsJBOD = 200,
	VmsRAIDUnknow
} VmsRaidLevel;

/* vdisk״̬ */
typedef enum {
	VmsVdiskStatusCRIT,		///< CRIT
	VmsVdiskStatusFTDN,		///< FTDN
	VmsVdiskStatusFTOL,		///< FTOL
	VmsVdiskStatusOFFL,		///< OFFL
	VmsVdiskStatusQTCR,		///< QTCR
	VmsVdiskStatusQTOF,		///< QTOF
	VmsVdiskStatusUP		///< UP
} VmsVdiskStatus;


/* IPSAN�о����� */
typedef enum 
{
	VmsVolumeTypeData,		///< ���ݾ�
	VmsVolumeTypeBackup,	///< ���ݾ�
	VmsVolumeTypeEnd
} VmsVolumeType;

/* IPSAN�о���Ϣ��ѯ�������� */
typedef enum tagVmsIPSANVolumeInfoQueryIndex{
	VmsIPSANVolumeInfoQueryDefault = 1,     ///< Ĭ�ϰ�ID���� 
	VmsIPSANVolumeInfoQueryCameraID = 2,	///< ��������������ID
	VmsIPSANVolumeInfoQueryIpsanID = 3,		///< �����ڵĴ洢�豸ID
	VmsIPSANVolumeInfoQueryCameraName = 5,	///< ������������������
	VmsIPSANVolumeInfoQueryVdiskName = 6,	///< ������vdisk����
	VmsIPSANVolumeInfoQueryVolName = 8,		///< ������
	VmsIPSANVolumeInfoQueryEND
} VmsIPSANVolumeInfoQueryIndex;

////////////////////////////////////////////////////////////////////////
/* �澯Դ���� */
typedef enum
{
	VmsAlarmSrcTypeTemp,		   ///< �¶ȸ澯
	VmsAlarmSrcTypeVL,		       ///< ��Ƶ��ʧ
	VmsAlarmSrcTypeMotion,	       ///< �˶����
	VmsAlarmSrcTypeDI,		       ///< ���������� 
	VmsAlarmSrcTypeFanAlert,	   ///< ���ȸ澯 
	VmsAlarmSrcTypeStorageFailed,  ///< �洢ʧ��
	VmsAlarmSrcTypeDiskError,      ///< ���̹��� 
	VmsAlarmSrcTypeEmAlarmSrc,	   ///< �������澯Դ
	//ALARMSRCTYPE_ENV,		       ///< �����豸�澯Դ 
	VmsEnvAlarmSrcTypeTmp,         ///< �������¶ȸ澯 
	VmsEnvAlarmSrcTypeWindSpeed,   ///< ���������ٸ澯 
	VmsEnvAlarmSrcTypeGAS,         ///< ��������˹Ũ�ȸ澯 
	VmsEnvAlarmSrcTypePowder,      ///< �������۳�Ũ�ȸ澯 
	VmsEnvAlarmSrcTypeCO,          ///< ������һ����̼Ũ�ȸ澯 
	VmsEnvAlarmSrcTypeSmoke,       ///< ����������Ũ�ȸ澯 
	VmsEnvAlarmSrcTypeDisplacement,///< ������λ�Ƹ澯 
	VmsEnvAlarmSrcTypeWaterDetect, ///< ������ˮ���澯 
	VmsEnvAlarmSrcTypeHumid,       ///< ����ʪ�ȸ澯 
	VmsEnvAlarmSrcTypInfrared,     ///< �������������澯 
	VmsAlarmSrcTypeEnd
} VmsAlarmSrcType;

/* ������������ö�� */
typedef enum
{
	VmsAlarmActionTypeStorage,		///< �����洢
	VmsAlarmActionTypePtzPreset,	///< ����Ԥ�õ�
	VmsAlarmActionTypePtzPatrol,	///< ����Ѳ��·��
	VmsAlarmActionTypeDO,			///< ����������
	VmsAlarmActionTypeSnapshot,		///< ����ץ��
	VmsAlarmActionTypeDcRs,			///< ����������
	VmsAlarmActionTypeCliectRs,		///< �����ͻ���
	VmsAlarmActionTypeDevAudio,		///< �����豸��Խ�
	VmsAlarmActionTypeClientAudio,	///< �����ͻ������豸��Խ� 
	VmsAlarmActionTypeEnd
} VmsAlarmActionType;

/* �洢�������� */
typedef enum 
{
	VmsStMediumIPSAN,	///< IPSAN��ʽ
	VmsStMediumNAS,		///< NAS��ʽ
	VmsStMediumLOCAL	///< ���ش洢
} VmsStorageMediumType;

/* �洢״̬  */
typedef enum tagVmsTermCameraStStatus
{
	TermCameraStStatusNone = 0x00,	///< 0:δ�洢
	TermCameraStStatusManual ,		///< 0:�ֶ��洢 
	TermCameraStStatusPlan ,		///< 0:�ƻ��洢
	TermCameraStStatusAlarm ,		///< 0:�澯�洢
	TermCameraStStatusNoVolum,		///< 0:δ�����
	TermCameraStStatusEnd,
} VmsTermCameraStStatus;

/* ������������� */
typedef enum
{
	VmsFullPolicyStopAndAlarm,	///< ֹͣ������
	VmsFullPolicyOverwrite		///< ����(Ĭ��ֵ)
} VmsFullPolicy;

/*TODO: ������������������
typedef enum {
	VmsChannelGroupInfoQueryDefault = 1,  // Ĭ�ϰ���ID���� 
	VmsChannelGroupInfoQueryOrgId = 2,
	VmsChannelGroupInfoQueryName = 4,
	VmsChannelGroupInfoQueryEnd
} VmsChannelGroupInfoQueryIndex;*/

/* �ƻ����� */
typedef enum 
{
	VmsPlanTypeWeekly,	///< �ܼƻ�
	VmsPlanTypeDaily,	///< �ռƻ�
	VmsPlanTypeEnd
} VmsPlanType;

/* �������� */
typedef enum
{
	VmsRsPatrolManualPlanPlan = 0x00,	///< �ƻ�
	VmsRsPatrolManualPlanManual,		///< �ֶ�
	VmsRsPatrolManualPlanEnd
} VmsRsPatrolManualPlan;

typedef enum tagVmsPatrolType{
	VmsPatrolTypeMonitor,	///< �������<-->������
	VmsPatrolTypeMonitorG,	///< �������<-->��������
	VmsPatrolTypeTvWall,	///< �������<-->����ǽ
	VmsPatrolTypeEnd
} VmsPatrolType;

////////////////////////////////////////////////////////////////////////
/* ƽ̨�ͺ�ö�� */
 typedef enum 
{
	VmsTypeVMS = 0x00,	///< VMS
	VmsTypeNVR,			///< NVR
	VmsTypeEnd
} VmsType;

/* ��־���� */
typedef enum
{
	VmsOpLogTypeParamSet = 0x01,		///< �������� 
	VmsOpLogTypeParamGet = 0x02,		///< ������ѯ(δ����־) 
	VmsOpLogTypeParamCmd = 0x03,		///< ����(�����������־) 
	VmsOpLogTypeParamTrap = 0x04,		///< δ����־ 
	VmsOpLogTypeSysRunningLog = 0x10,	///< ϵͳ������־
	VmsOpLogTypeEnd
} VmsOpLogType;

/* ������Ϣ(Ŀǰֻ����������) */
typedef enum
{
	VmsTaskTypeUpgrade,		///<����
	VmsTaskTypeEnd
} VmsTaskType;

/* ����ִ��״̬ */
typedef enum 
{
	VmsTaskStatusInit = 0,   ///< ����δִ�� 
	VmsTaskStatusScheduled,  ///< �����ִ�� 
	VmsTaskStatusProcessing, ///< ����ִ���� 
	VmsTaskStatusFinished,   ///< ��������� 
	VmsTaskStatusFailed,     ///< ����ʧ�� 
	VmsTaskStatusRestart,    ///< ������������ 
	VmsTaskStatusEnd
} VmsTaskStatus;

/* �ն������������� */
typedef enum
{
	VmsTermUpgradTypeKERNEL = 0x01,		///< �ں�
	VmsTermUpgradTypeRAMDISK = 0x02,	///< �ļ�ϵͳ
	VmsTermUpgradTypeFPGA = 0x04,		///< FPGA����
	VmsTermUpgradTypeCPLD = 0x08		///< CPLD����
} VmsTermUpgradType;

typedef enum
{
	VmsMNSessionLive = 0,	///< ʵʱʵ��
	VmsMNSessionDialog,		///< �Խ�
	VmsMNSessionBrd,		///< �㲥
	VmsMNSessionPatrolLive,	///< ����ʵ��
	VmsMNSessionAlarmLive	///< �澯ʵ��
} VmsMNSessionServiceType;

//״̬�ı�����
typedef enum tagSubscribeEventType
{
	VmsSubscribeEventDeviceOnline = 0,
	VmsSubscribeEventDeviceOffline,
	VmsSubscribeEventDeviceDel,
	VmsSubscribeEventDevResOnline,
	VmsSubscribeEventDevResOffline,
	VmsSubscribeEventDevResDel
} VmsSubscribeEventType;

// ��Դ����
typedef enum tagVmsResType{
	VmsResTypeCamera = 0x00,///< �������Դ
	VmsResTypeMonitor,		///< ��������Դ
	VmsResTypeAlarm,		///< �澯Դ��Դ
	VmsResTypeDo,			///< ���������
	VmsResTypeSerial,		///< ������Դ
	VmsResTypeAudiocom,		///< �Խ���Դ
	VmsResTypeEmap,			///< ���ӵ�ͼ��Դ
	VmsResTypeEnv,			///< ��������Դ
	VmsResTypeEnd
} VmsResType;

/**********************������res_sub_type����**********************/
//  �������ֱ���
typedef enum tagVmsMonitorFormat
{
	VmsMonitorFormatSD = 0x0,
	VmsMonitorFormatHD_1080 = 0x1,
	VmsMonitorFormatHD_720 = 0x2,
	VmsMonitorFormatEND
} VmsMonitorFormat;

//  �������ָ�ģʽ
typedef enum tagVmsMonitorSplitMode
{
	VmsMonitorSplitModeBNC_1CH = 0x00,
	VmsMonitorSplitModeHDMI_1CH,
	VmsMonitorSplitModeHDMI_4CH,
	VmsMonitorSplitModeDVI_1CH,
	VmsMonitorSplitModeDVI_4CH,
	VmsMonitorSplitModeEnd
} VmsMonitorSplitMode;


/* �ն�״̬��ѯ�����  */
typedef enum tagVmsTermStatusCmdIndex
{
	VmsTermStatusStorage,  ///< �洢״̬��ѯ
	VmsTermStatusLive,     ///< �洢״̬��ѯ
	VmsTermStatusLoop,     ///< ����״̬��ѯ

	VmsTermStatusEnd
} VmsTermStatusCmdIndex;

/** @brief  �ڵ㹤��ģʽ����  */
typedef enum tagVmsNodeWorkmode
{
	VmsNodeWorkmodeMaster,	///< ���ڵ� 
	VmsNodeWorkmodeSlave,	///< �ӽڵ� 
	VmsNodeWorkmodeDepend,	///< ���ؽڵ� 
} VmsNodeWorkmode;

/** @brief  �ڵ�״̬����  */
typedef enum tagVmsNodeState
{
	VmsNodeStateCS,		///< CS״̬�����ڵ���� 
	VmsNodeStateFS,		///< FS״̬�����ڵ���� 
	VmsNodeStateBS,		///< BS״̬�����ڵ���� 

	VmsNodeStateUP,		///< UP״̬���ӽڵ���� 
	VmsNodeStateDOWN	///< DOWN״̬���ӽڵ���� 
} VmsNodeState;

/** @brief  ���״̬����  */
typedef enum tagVmsFiberState
{
	VmsFiberDOWN,	///< ���UP 
	VmsFiberUP		///< ���DOWN 
} VmsFiberState;

#endif

#endif	// __VMS_COMMON_H__