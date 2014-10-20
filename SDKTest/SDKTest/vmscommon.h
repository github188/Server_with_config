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
/* 设备序列号长度 */
#define VMS_DEVICE_SN_LEN			(64)

#define VMS_TASK_PARAM_LEN			(256)

#define VMS_MAX_IQN_LEN				(128)

// 默认服务器监听端口
#define DEFAULT_VMS_PORT			(19999)

/* 设备序列号长度 */
#define VMS_DEVICE_SN_LEN			(64)

/* 一个vdisk所允许拥有的磁盘数量 */
#define VMS_MAX_DISK_NUM_PER_VDISK	(32)

/* 每个资源可以关联的最大资源数量 */
#define VMS_MAX_RES_MAP_NUM			(64)

//2013.6.7添加

#define VMS_MAX_OSD_VALUE			(64)
#define VMS_RESOURCE_ORG_PATH		(64)

/* verdor name "ntech" or "other" */

#define VMS_VENDOR_NAME_LOCAL  "ntech"
#define VMS_VENDOR_NAME_H3C  "H3C"
#define VMS_VENDOR_NAME_ONU  "ONU"
#define VMS_VENDOR_NAME_OTHER  "other"

/* 字符串表示的版本号最大长度 */
#define VMS_VERSION_STR_LEN			(32)

#define VMS_VDISK_NAME_LEN			(32)

/* IPSAN数据端口名称最大长度 */
#define VMS_PORT_NAME_LEN			(16)

/* 能够同一IPSAN的最大VOD数量 */
#define VMS_MAX_VOD_PER_IPSAN		(16)

#define VMS_MAX_IQN_LEN				(128)

/* IPSAN用户名和密码长度 */
#define VMS_IPSAN_USER_LEN			(32)
#define VMS_IPSAN_PASSWD_LEN		(32)

//FTP路径长度
#define VMS_FTP_PATH_LEN			(64)

//
#define VMS_TASK_PARAM_LEN			(256)

/* license长度 */
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

/*语言设置*/
typedef enum
{
	VmsLanguageSetCH = 0,
	VmsLanguageSetEN,

	VmsLanguageSetEnd
} VmsLanguageSet;

//IP地址类型
typedef enum tagVmsIPAddrType
{ 
	VmsIPAddrTypeIPV4, 
	VmsIPAddrTypeIPV6

} VmsIPAddrType;



//摄像机型号
typedef enum
{
	VmsCameraModelNormal = 0,    /* 普通摄像机 */
	VmsCameraModelGun,			/* 枪机 */
	VmsCameraModelBall,			/* 球机 */
	VmsCameraModelIncorporate,	/* 一体机 */
	VmsCameraModelGB,			/* 公板 */
	VmsCameraModelHalfBall,		/* 半球机 */

	VmsCameraModelEnd
} VmsCameraModel;


// 视频流类型
typedef enum
{
	VmsVideoStreamTypeMain = 0,		// 主流
	VmsVideoStreamTypeSub,			// 辅流
	VmsVideoStreamTypeSubSub,		// 次辅流, 终端暂未提供次辅流参数

	VmsVideoStreamTypeEnd
} VmsVideoStreamType;

// 视频流传输类型
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

// 视频码流封装类型*/
typedef enum
{
	VmsMediaPacketTypeRTP = 0,
	VmsMediaPacketTypeTS,
	VmsMediaPacketTypePS,
	VmsMediaPacketTypeES,

	VmsMediaPacketTypeEnd
} VmsMediaPacketType;

// 视频编码格式
typedef enum
{
	VmsVideoCodecFormatH264 = 0,
	VmsVideoCodecFormatH263,
	VmsVideoCodecFormatMJPEG,
	VmsVideoCodecFormatMPEG2,
	VmsVideoCodecFormatMPEG4,

	VmsVideoCodecFormatEnd
} VmsVideoCodecFormat;

// 视频分辨率
typedef enum
{
	VmsVideoResolutionQCIF = 0,			//  TODO: 注释
	VmsVideoResolutionCIF,
	VmsVideoResolution2CIF,
	VmsVideoResolution4CIF,
	VmsVideoResolutionD1,
	VmsVideoResolution720P,
	VmsVideoResolution1080I,
	VmsVideoResolution1080P,
	VmsVideoResolutionUnknown,	// 用于无法判断的第三方码流

	VmsVideoResolutionEnd
} VmsVideoResolution;

// GOP模式
typedef enum
{
	VmsVideoGOPModeI = 0,		// TODO: 注释
	VmsVideoGOPModeIP,
	VmsVideoGOPModeIBP,
	VmsVideoGOPModeIBBP,

	VmsVideoGOPModeEnd
} VmsVideoGOPMode;

// 视频编码模式
typedef enum
{
	VmsVideoECModeCBR = 0,			// TODO: 注释
	VmsVideoECModeVBRBest,
	VmsVideoECModeVBRBetter,
	VmsVideoECModeVBRGood,
	VmsVideoECModeVBRBad,
	VmsVideoECModeVBRWorse,

	VmsVideoECModeEnd
} VmsVideoECMode;

// 视频编码优先级
typedef enum
{
	VmsVideoPriorityFrameRate = 0,		// 帧率优先
	VmsVideoPriorityBitRate,			// 码率优先
	VmsVideoPriorityEnd
} VmsVideoPriority;

// 录像查询类型
typedef enum
{
	VmsRecordSearchTypeAll = 0,
	VmsRecordSearchTypeTime = 0,
	VmsRecordSearchTypeEvent,
	VmsRecordSearchTypeTag,
	VmsRecordSearchTypeManual,

	VmsRecordSearchTypeEnd
} VmsRecordSearchType;

// 录像类型
typedef enum
{
	VmsRecordTypeNormal = 0,
	VmsRecordTypeAlarm,

	VmsRecordTypeEnd
} VmsRecordType;

/*standard: 制式*/
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

/*audio_coding: 音频编码格式*/
typedef enum
{
	VmsAudioG711A = 0,
	VmsAudioG711U,
	VmsAudioG726,
	VmsAudioG729AB,

	VmsAudioCodingEnd
} VmsAudioCoding;

/*audio_track: 音频声道*/
typedef enum
{
	VmsAudioTrackMono = 0,
	VmsAudioTrackStereo,
	VmsAudioTrackLeft,
	VmsAudioTrackRight,

	VmsAudioTrackEnd
} VmsAudioTrack;

/*audio sampling_rate: 音频采样率*/
typedef enum
{
	VmsAudioSample8K = 0,
	VmsAudioSample16K,
	VmsAudioSample32K,
	VmsAudioSample48K,
	VmsAudioSample64K,

	VmsAudioSampleEnd
} VmsAudioSampleRate;

/*audio_bitrate: 音频码率*/
typedef enum
{
	VmsAudioG726_16K = 0,
	VmsAudioG726_24K,
	VmsAudioG726_32K,
	VmsAudioG726_40K,

	VmsAudioBitrateEnd
} VmsAudioBitrate;

/*camera_type: 摄像机类型*/
typedef enum
{
	VmsCameraWithPtz,      /*带云台*/
	VmsCameraWithoutPtz,   /*不带云台*/

	VmsCameraTypeEnd
} VmsCameraType;

/*ptz_protocol: 云台协议*/
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

/*audiocommr_input_method: 音频对讲输入方式*/
typedef enum
{
	VmsAudioMic = 0,
	VmsAudioLineIn,

	VmsAudioMethodEnd
} VmsAudioCommrInputMethod;

/*transchannel_type: 透明通道类型*/
typedef enum
{
	VmsTranschTypeS2S = 0,
	VmsTranschTypeS2IP,

	VmsTranschTypeEnd
} VmsTranschType;

/*transchannel.current_state: 透明通道当前状态*/
typedef enum
{
	VmsTranschStatNeedRecover = 0,
	VmsTranschStatNotNeedRecover,

	VmsTranschStatEnd
} VmsTranschState;

/*transchannel.protocol: 透明通道传输协议*/
typedef enum
{
	VmsTranschUDP = 0,
	VmsTranschTCP,

	VmsTranschEnd
} VmsTranschProtocol;

/*serial_type: 串口类型*/
typedef enum
{
	VmsSerialRS232 = 0,
	VmsSerialRS422,
	VmsSerialRS485,

	VmsSerialTypeEnd
} VmsSerialType;

/*serial_mode: 串口模式*/
typedef enum
{
	VmsSerModeConsole = 0,     /*用作控制台*/
	VmsSerModeTransch,     /*用作透明通道*/
	VmsSerModePtzCtrl,    /*用作云台控制*/
	VmsSerModeExternMoudle,/*扩展模块使用*/
	VmsSerModeScada,         /*电力云台使用*/
	VmsSerModePtzTransch,	/*云台透明通道模式*/

	VmsSerModeEnd
} VmsSerialMode;

/*serial.baudrate: 串口波特率*/
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

/*serial.databit: 串口数据位*/
typedef enum
{
	VmsDatabit5Bit,
	VmsDatabit6Bit,
	VmsDatabit7Bit,
	VmsDatabit8Bit,

	VmsDatabitEnd
} VmsSerialDatabit;

/*serial.stopbit:　串口停止位*/
typedef enum
{
	VmsStopbit1Bit,
	VmsStopBit1P5Bit,
	VmsStopbit2Bit,

	VmsStopbitEnd
} VmsSerialStopbit;

/*serial.paritybit: 串口校验位*/
typedef enum
{
	VmsParitybitNone,     /*无校验*/
	VmsParitybitOdd,      /*奇校验*/
	VmsParitybitEven,     /*偶校验*/
	VmsParitybitSymbol,	 /*标志校验*/
	VmsParitybitBlank,	 /*空格校验*/

	VmsParitybitEnd
} VmsSerialParitybit;

/*serial.flowcontrol: 串口流控*/
typedef enum
{
	VmsSerFlowctrlNone,          /*无*/
	VmsSerFlowctrlSoftware,      /*软件控制*/
	VmsSerFlowctrlHardware,      /*硬件控制*/

	VmsSerFlowctrlEnd
} VmsSerialFlowctrl;

/*sema_in/ouput: trigger_mode*/
typedef enum
{
	VmsSemaLowLevel,           /*低电平*/
	VmsSemaHighLevel,          /*高电平*/

	VmsSemaModeEnd
} VmsSemaTriggerMode;

/*smooth_value: 码流平滑使能开关*/
typedef enum
{
	VmsBitstreamSmoothDisable,
	VmsBitstreamSmoothEnable,

	VmsBitstreamSmoothEnd
} VmsBitstreamSmooth;

/*alarm_type: 告警类型*/
typedef enum
{
	VmsAlarmTypeTempeAlert = 0,       /*温度告警*/
	VmsAlarmTypeVideoLoss,        /*视频丢失*/
	VmsAlarmTypeVideoMotion,      /*运动侦测*/
	VmsAlarmTypeSemaInput,        /*开关量输入*/
	VmsAlarmTypeFanAlert,         /*风扇告警*/
	VmsAlarmTypeStorageFailed,    /*存储失败*/
	VmsAlarmTypeEnv,               /* 环境设备告警  */
	VmsAlarmTypeDiskError,        /*磁盘故障*/
	VmsAlarmTypeVideoRecover,     /*视频恢复*/
	VmsAlarmTypeTempeRecover,     /*温度恢复*/
	VmsAlarmTypeOther,             /*其它*/

	VmsAlarmTypeEnd
} VmsAlarmType;

/*osd_time_format: OSD 时间显示格式*/
typedef enum
{
	VmsTimeFormat1,      /*XX:XX:XX*/
	VmsTimeFormat2,      /*XX:XX:XX p.m.*/
	VmsTimeFormat3,      /*XX:XX:XX PM*/
	VmsTimeFormat4,      /*下午 XX:XX:XX*/

	VmsTimeFormatEnd
} VmsOsdTimeFormat;

/*osd_date_format: OSD 日期显示格式*/
typedef enum
{
	VmsDateFormat1 = 0,   /*XXXX-XX-XX*/
	VmsDateFormat2,       /*XX-XX-XXXX*/
	VmsDateFormat3,       /*XXXX/XX/XX*/
	VmsDateFormat4,       /*XXXX年XX月XX日*/

	VmsDateFormatEnd
} VmsOsdDateFormat;

/*osd_field_type: 场名类型*/
typedef enum
{
	VmsOsdFiledWord = 0,        /*文字*/
	VmsOsdFiledPicture,         /*图片*/

	VmsOsdFiledEnd
} VmsOsdFiledType;

//云台命令
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

	/* 以下命令给长春博弈+sanyo机芯 */
	VmsPtzCmdAutoFocuson, // 自动聚焦
	VmsPtzCmdManualFocuson, // 手动聚焦
	VmsPtzCmdWhiteMode,		// 白平衡模式
	VmsPtzCmdAutoIrison,	// 自动光圈
	VmsPtzCmdManualIrison,	// 手动光圈
	VmsPtzCmdBlacklightOff,	// 背光模式关
	VmsPtzCmdMultiBlacklight,// 多点背光
	VmsPtzCmdCenterBlacklight,// 中心背光
	VmsPtzCmdMaskBlacklight,  // 区域背光
	VmsPtzCmdAgOn,			// 增益开
	VmsPtzCmdAgOff,			// 增益关
	VmsPtzCmdGammaoff,		// 伽马校正关
	VmsPtzCmdGammaon,		// 伽马校正开
	VmsPtzCmdGammasmart1,	// 伽马增加1
	VmsPtzCmdGammasmart2,    // 伽马增加2
	VmsPtzCmdOsdZmrtOff,	// 倍率显示关
	VmsPtzCmdOsdZmrtOn,   // 倍率显示开
	VmsPtzCmdVideooutMode, //分辨率切换
	VmsPtzCmdNtpaChange,	//制式切换

	/* 雅安云台加入新的命令 */
	/* 扫描相关命令 */
	VmsPtzCmdSetScanLeftEdge,
	VmsPtzCmdSetScanRightEdge,
	VmsPtzCmdSetScanSpeed,
	VmsPtzCmdStartScan,
	VmsPtzCmdStopScan,

	/* 巡迹相关 */
	VmsPtzCmdSetTrackStartPoint,
	VmsPtzCmdSetTrackStopPoint,
	VmsPtzCmdStartTrack,
	VmsPtzCmdStopTrack,

	/* 辅助开关 */
	VmsPtzCmdAuxSwitchOn,
	VmsPtzCmdAuxSwitchOff,

	VmsPtzCmd3Dcontrol,//三维定焦

	VmsPtzCmdSum

} VmsPtzCmd;

/*终端类型*/
typedef enum 
{
	VmsTerminalTypeEC,
	VmsTerminalTypeDC,
	VmsTerminalTypeIPC,

	VmsTerminalTypeEnd
} VmsTerminalType;

/* 物理通道输出方式 */
typedef enum
{
	VmsPhyoutModeBnc,		//BNC输出,默认值
	VmsPhyoutModeHdmi1W,	//HDMI一窗格输出
	VmsPhyoutModeHdmi4W		//HDMI四窗格输出
} VmsPhyoutMode;

/* 填充方式,在HDMI四窗格输出模式下有效 */
typedef enum
{
	VmsFillMethodHdmi4Extend,		//拉伸填满(默认值)
	VmsFillMethodHdmi4AddBlack		//加黑边
} VmsFillMethod;

/* 网卡模式*/
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
	Int32	iStatus;		// 0: 成功; 其它:失败
	Int32	iErrCode;		// 参考SdkError.h
	CHAR	szErrDesc[VmsErrorLanguageEnd][VMS_MAX_ERR_DESC_LEN];	// 错误描述
} VmsStatus;

typedef struct tagVmsTime
{
	Uint32	uiYear;		///< 年
	Uint32  uiMonth;	///< 月
	Uint32  uiDay;		///< 日
	Uint32  uiHour;		///< 时
	Uint32  uiMinute;	///< 分
	Uint32  uiSecond;	///< 秒
} VmsTime;

/*日期类型*/
typedef struct tagVmsDate
{
	Uint16 year;	///< 年
	Uint8  month;	///< 月
	Uint8  day;		///< 日
} VmsDate;

//2013.3.21添加
/* 向TC注册的设备类型 */
typedef enum
{
	VmsDevicTypeNVR = 0,
	VmsDevicTypeEC,
	VmsDevicTypeDC,
	VmsDevicTypeIPC,
	VmsDevicTypeMS,
	VmsDevicTypeDM,
	VmsDevicTypeVOD,
	VmsDeviceTypeEM,		/* 第三方告警设备 */
	VmsDeviceTypeIMS,		/* IMS告警设备 */
	VmsDeviceTypeMATP,

	VmsDevicTypeEnd
} VmsDeviceType;

/*设备型号:主要用于区分不同通道的EC*/
typedef enum
{
	VmsDeviceModelEcSD1CH = 0,
	VmsDeviceModelEcSD2CH,
	VmsDeviceModelEcSD4CH,
	VmsDeviceModelEcSD8CH,
	VmsDeviceModelEcSD16CH,

	VmsDeviceModelEnd
} VmsDeviceModelEC;

/*设备型号:主要用于区分不同通道的DC*/
typedef enum
{
	VmsDeviceModelDcSD1CH = 0,
	VmsDeviceModelDcSD2CH,
	VmsDeviceModelDcSD4CH,
	VmsDeviceModelDcSD8CH,
	VmsDeviceModelDcSD16CH,

	VmsDeviceModelDcEnd
} VmsDeviceModelDc;


/*设备型号:主要用于区分不同类型的IPC*/
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

/* 域类型 */
typedef enum
{
	VmsDomainTypeLocal = 0x00,  ///< 本域
	VmsDomainTypeSup,			///< 上级域
	VmsDomainTypeSub,			///< 下级域 
	VmsDomainTypeSibling,		///< 同级域(互为上下级)
	VmsDomainTypeEnd
} VmsDomainType;

/*权限类型*/
#ifdef MINE_PRODUCT
typedef enum {
	VmsPrivTypeLive = 0x01,		///< 实况
	VmsPrivTypePlayback = 0x02,	///< 回放
	VmsPrivTypeMap = 0x04,		///< 地图
	PVmsPrivTypeAlarm = 0x08,	///< 告警
	VmsPrivTypeConfig = 0x10,	///< 配置
	VmsPrivTypeManage = 0x20,	///< 业务管理
	VmsPrivTypeMaintain = 0x40, ///< 系统维护
	VmsPrivTypeEnv = 0x80		///< 环境量相关权限
} VmsPrivType;
#else
typedef enum {
	VmsPrivTypeLive = 0x01,		///< 实况
	VmsPrivTypePlayback = 0x02,	///< 回放
	VmsPrivTypeMap = 0x04,		///< 地图
	PVmsPrivTypeAlarm = 0x08,	///< 告警
	VmsPrivTypeConfig = 0x10,	///< 配置
	VmsPrivTypeManage = 0x20,	///< 业务管理
	VmsPrivTypeMaintain = 0x40  ///< 系统维护
} VmsPrivType;
#endif


/* 磁盘使用类型 */
typedef enum {
	VmsDiskUsedTypeAvail,		///< Avail
	VmsDiskUsedTypeGlobalSP,	///< GLOBAL_SP
	VmsDiskUsedTypeLeftover,	///< LEFTOVER
	VmsDiskUsedTypeVdiskrcon,	///< VDISKRCON
	VmsDiskUsedTypeVdisk,		///< VDISK
	VmsDiskUsedTypeVdiskinit,	///< VDISKINIT
	VmsDiskUsedTypeVdiskSP		///< VDISK_SP
} VmsDiskUsedType;

/* 磁盘接口类型 */
typedef enum {
	VmsDiskTypeSAS,		///< SAS
	VmsDiskTypeSAS_S,	///< SAS_S
	VmsDiskTypeSATA,	///< SATA
	VmsDiskTypeSATA_S	///< SATA_S
} VmsDiskType;

/* 磁盘状态 */
typedef enum {
	VmsDiskStatusUp,			///< Up
	VmsDiskStatusSpunDown,		///< SPUN_DOWN
	VmsDiskStatusWaring,		///< WARNING
	VmsDiskStatusError,			///< ERROR
	VmsDiskStatusNotPresent,	///< NOT_PRESENT
	VmsDiskStatusDisconnect,	///< DISCONNECT
	VmsDiskStatusUnknow			///< UNKNOW
} VmsDiskStatus;

/* 磁盘健康状态 */
typedef enum {
	VmsDiskHealthOk,	///< 健康
	VmsDiskHealthSick	///< 有问题
} VmsDiskHealth;

/* RAID类型 */
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

/* vdisk状态 */
typedef enum {
	VmsVdiskStatusCRIT,		///< CRIT
	VmsVdiskStatusFTDN,		///< FTDN
	VmsVdiskStatusFTOL,		///< FTOL
	VmsVdiskStatusOFFL,		///< OFFL
	VmsVdiskStatusQTCR,		///< QTCR
	VmsVdiskStatusQTOF,		///< QTOF
	VmsVdiskStatusUP		///< UP
} VmsVdiskStatus;


/* IPSAN中卷类型 */
typedef enum 
{
	VmsVolumeTypeData,		///< 数据卷
	VmsVolumeTypeBackup,	///< 备份卷
	VmsVolumeTypeEnd
} VmsVolumeType;

/* IPSAN中卷信息查询条件索引 */
typedef enum tagVmsIPSANVolumeInfoQueryIndex{
	VmsIPSANVolumeInfoQueryDefault = 1,     ///< 默认按ID排序 
	VmsIPSANVolumeInfoQueryCameraID = 2,	///< 卷所分配的摄像机ID
	VmsIPSANVolumeInfoQueryIpsanID = 3,		///< 卷所在的存储设备ID
	VmsIPSANVolumeInfoQueryCameraName = 5,	///< 卷所分配的摄像机名称
	VmsIPSANVolumeInfoQueryVdiskName = 6,	///< 卷所在vdisk名称
	VmsIPSANVolumeInfoQueryVolName = 8,		///< 卷名称
	VmsIPSANVolumeInfoQueryEND
} VmsIPSANVolumeInfoQueryIndex;

////////////////////////////////////////////////////////////////////////
/* 告警源类型 */
typedef enum
{
	VmsAlarmSrcTypeTemp,		   ///< 温度告警
	VmsAlarmSrcTypeVL,		       ///< 视频丢失
	VmsAlarmSrcTypeMotion,	       ///< 运动侦测
	VmsAlarmSrcTypeDI,		       ///< 开关量输入 
	VmsAlarmSrcTypeFanAlert,	   ///< 风扇告警 
	VmsAlarmSrcTypeStorageFailed,  ///< 存储失败
	VmsAlarmSrcTypeDiskError,      ///< 磁盘故障 
	VmsAlarmSrcTypeEmAlarmSrc,	   ///< 第三方告警源
	//ALARMSRCTYPE_ENV,		       ///< 环境设备告警源 
	VmsEnvAlarmSrcTypeTmp,         ///< 环境量温度告警 
	VmsEnvAlarmSrcTypeWindSpeed,   ///< 环境量风速告警 
	VmsEnvAlarmSrcTypeGAS,         ///< 环境量瓦斯浓度告警 
	VmsEnvAlarmSrcTypePowder,      ///< 环境量粉尘浓度告警 
	VmsEnvAlarmSrcTypeCO,          ///< 环境量一氧化碳浓度告警 
	VmsEnvAlarmSrcTypeSmoke,       ///< 环境量烟雾浓度告警 
	VmsEnvAlarmSrcTypeDisplacement,///< 环境量位移告警 
	VmsEnvAlarmSrcTypeWaterDetect, ///< 环境量水浸告警 
	VmsEnvAlarmSrcTypeHumid,       ///< 环境湿度告警 
	VmsEnvAlarmSrcTypInfrared,     ///< 环境量红外对射告警 
	VmsAlarmSrcTypeEnd
} VmsAlarmSrcType;

/* 联动动作类型枚举 */
typedef enum
{
	VmsAlarmActionTypeStorage,		///< 联动存储
	VmsAlarmActionTypePtzPreset,	///< 联动预置点
	VmsAlarmActionTypePtzPatrol,	///< 联动巡航路线
	VmsAlarmActionTypeDO,			///< 联动开关量
	VmsAlarmActionTypeSnapshot,		///< 联动抓拍
	VmsAlarmActionTypeDcRs,			///< 联动监视器
	VmsAlarmActionTypeCliectRs,		///< 联动客户端
	VmsAlarmActionTypeDevAudio,		///< 联动设备间对讲
	VmsAlarmActionTypeClientAudio,	///< 联动客户端与设备间对讲 
	VmsAlarmActionTypeEnd
} VmsAlarmActionType;

/* 存储介质类型 */
typedef enum 
{
	VmsStMediumIPSAN,	///< IPSAN方式
	VmsStMediumNAS,		///< NAS方式
	VmsStMediumLOCAL	///< 本地存储
} VmsStorageMediumType;

/* 存储状态  */
typedef enum tagVmsTermCameraStStatus
{
	TermCameraStStatusNone = 0x00,	///< 0:未存储
	TermCameraStStatusManual ,		///< 0:手动存储 
	TermCameraStStatusPlan ,		///< 0:计划存储
	TermCameraStStatusAlarm ,		///< 0:告警存储
	TermCameraStStatusNoVolum,		///< 0:未分配卷
	TermCameraStStatusEnd,
} VmsTermCameraStStatus;

/* 磁盘满处理策略 */
typedef enum
{
	VmsFullPolicyStopAndAlarm,	///< 停止并报警
	VmsFullPolicyOverwrite		///< 覆盖(默认值)
} VmsFullPolicy;

/*TODO: 摄像机组检索条件索引
typedef enum {
	VmsChannelGroupInfoQueryDefault = 1,  // 默认按组ID排序 
	VmsChannelGroupInfoQueryOrgId = 2,
	VmsChannelGroupInfoQueryName = 4,
	VmsChannelGroupInfoQueryEnd
} VmsChannelGroupInfoQueryIndex;*/

/* 计划类型 */
typedef enum 
{
	VmsPlanTypeWeekly,	///< 周计划
	VmsPlanTypeDaily,	///< 日计划
	VmsPlanTypeEnd
} VmsPlanType;

/* 轮切类型 */
typedef enum
{
	VmsRsPatrolManualPlanPlan = 0x00,	///< 计划
	VmsRsPatrolManualPlanManual,		///< 手动
	VmsRsPatrolManualPlanEnd
} VmsRsPatrolManualPlan;

typedef enum tagVmsPatrolType{
	VmsPatrolTypeMonitor,	///< 摄像机组<-->监视器
	VmsPatrolTypeMonitorG,	///< 摄像机组<-->监视器组
	VmsPatrolTypeTvWall,	///< 摄像机组<-->电视墙
	VmsPatrolTypeEnd
} VmsPatrolType;

////////////////////////////////////////////////////////////////////////
/* 平台型号枚举 */
 typedef enum 
{
	VmsTypeVMS = 0x00,	///< VMS
	VmsTypeNVR,			///< NVR
	VmsTypeEnd
} VmsType;

/* 日志类型 */
typedef enum
{
	VmsOpLogTypeParamSet = 0x01,		///< 参数设置 
	VmsOpLogTypeParamGet = 0x02,		///< 参数查询(未记日志) 
	VmsOpLogTypeParamCmd = 0x03,		///< 命令(部分命令记日志) 
	VmsOpLogTypeParamTrap = 0x04,		///< 未记日志 
	VmsOpLogTypeSysRunningLog = 0x10,	///< 系统运行日志
	VmsOpLogTypeEnd
} VmsOpLogType;

/* 任务信息(目前只有升级任务) */
typedef enum
{
	VmsTaskTypeUpgrade,		///<升级
	VmsTaskTypeEnd
} VmsTaskType;

/* 任务执行状态 */
typedef enum 
{
	VmsTaskStatusInit = 0,   ///< 任务未执行 
	VmsTaskStatusScheduled,  ///< 任务待执行 
	VmsTaskStatusProcessing, ///< 任务执行中 
	VmsTaskStatusFinished,   ///< 任务已完成 
	VmsTaskStatusFailed,     ///< 任务失败 
	VmsTaskStatusRestart,    ///< 任务正在重启 
	VmsTaskStatusEnd
} VmsTaskStatus;

/* 终端升级镜像类型 */
typedef enum
{
	VmsTermUpgradTypeKERNEL = 0x01,		///< 内核
	VmsTermUpgradTypeRAMDISK = 0x02,	///< 文件系统
	VmsTermUpgradTypeFPGA = 0x04,		///< FPGA代码
	VmsTermUpgradTypeCPLD = 0x08		///< CPLD代码
} VmsTermUpgradType;

typedef enum
{
	VmsMNSessionLive = 0,	///< 实时实况
	VmsMNSessionDialog,		///< 对讲
	VmsMNSessionBrd,		///< 广播
	VmsMNSessionPatrolLive,	///< 轮切实况
	VmsMNSessionAlarmLive	///< 告警实况
} VmsMNSessionServiceType;

//状态改变类型
typedef enum tagSubscribeEventType
{
	VmsSubscribeEventDeviceOnline = 0,
	VmsSubscribeEventDeviceOffline,
	VmsSubscribeEventDeviceDel,
	VmsSubscribeEventDevResOnline,
	VmsSubscribeEventDevResOffline,
	VmsSubscribeEventDevResDel
} VmsSubscribeEventType;

// 资源类型
typedef enum tagVmsResType{
	VmsResTypeCamera = 0x00,///< 摄像机资源
	VmsResTypeMonitor,		///< 监视器资源
	VmsResTypeAlarm,		///< 告警源资源
	VmsResTypeDo,			///< 开关量输出
	VmsResTypeSerial,		///< 串口资源
	VmsResTypeAudiocom,		///< 对讲资源
	VmsResTypeEmap,			///< 电子地图资源
	VmsResTypeEnv,			///< 环境量资源
	VmsResTypeEnd
} VmsResType;

/**********************监视器res_sub_type定义**********************/
//  监视器分辨率
typedef enum tagVmsMonitorFormat
{
	VmsMonitorFormatSD = 0x0,
	VmsMonitorFormatHD_1080 = 0x1,
	VmsMonitorFormatHD_720 = 0x2,
	VmsMonitorFormatEND
} VmsMonitorFormat;

//  监视器分割模式
typedef enum tagVmsMonitorSplitMode
{
	VmsMonitorSplitModeBNC_1CH = 0x00,
	VmsMonitorSplitModeHDMI_1CH,
	VmsMonitorSplitModeHDMI_4CH,
	VmsMonitorSplitModeDVI_1CH,
	VmsMonitorSplitModeDVI_4CH,
	VmsMonitorSplitModeEnd
} VmsMonitorSplitMode;


/* 终端状态查询命令号  */
typedef enum tagVmsTermStatusCmdIndex
{
	VmsTermStatusStorage,  ///< 存储状态查询
	VmsTermStatusLive,     ///< 存储状态查询
	VmsTermStatusLoop,     ///< 环网状态查询

	VmsTermStatusEnd
} VmsTermStatusCmdIndex;

/** @brief  节点工作模式定义  */
typedef enum tagVmsNodeWorkmode
{
	VmsNodeWorkmodeMaster,	///< 主节点 
	VmsNodeWorkmodeSlave,	///< 从节点 
	VmsNodeWorkmodeDepend,	///< 挂载节点 
} VmsNodeWorkmode;

/** @brief  节点状态定义  */
typedef enum tagVmsNodeState
{
	VmsNodeStateCS,		///< CS状态，主节点独有 
	VmsNodeStateFS,		///< FS状态，主节点独有 
	VmsNodeStateBS,		///< BS状态，主节点独有 

	VmsNodeStateUP,		///< UP状态，从节点独有 
	VmsNodeStateDOWN	///< DOWN状态，从节点独有 
} VmsNodeState;

/** @brief  光口状态定义  */
typedef enum tagVmsFiberState
{
	VmsFiberDOWN,	///< 光口UP 
	VmsFiberUP		///< 光口DOWN 
} VmsFiberState;

#endif

#endif	// __VMS_COMMON_H__