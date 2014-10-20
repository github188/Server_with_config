#ifndef _TERM_NET_STRUCT_
#define _TERM_NET_STRUCT_

#include <vector>

#include "VmsCommon.h"

#pragma pack( push , 1)

/** @brief 1.实况开始*/
typedef struct tagTermLivePlayParam
{
	Uint32	uiChannelId;		///< 实况视频的输入通道
	Uint32	uiMainSubFlag;		///< 主辅流标志，参考枚举 #VmsVideoStreamType
	Uint32	uiTransMode;		///< 传输模式 参考枚举 #VmsTransType
	Uint32	uiStreamType;		///< 码流形式  参考枚举 #VmsMediaPacketType
	CHAR	szRecvAddr[VMS_MAX_IPADDR_LEN];		///< 组播/单播的IP地址,如果为DC单播的话，为传出参数
	Uint32	uiRecvPort;			///< 组播/单播的端口号,如果为DC单播的话，为传出参数
	Uint32	uiMcFlag;			///< 是否为组播,0为单播，1为组播	
} TermLivePlayParam;

/** @brief 2.实况恢复配置结构体*/
typedef struct tagTermLiveRecover
{
	Uint32      uiEnable;		///< 是否需要恢复的标准
	Uint32      uiChannelId;	///< 通道号            
	Uint32      uiSubIndex;		///< 实况是该通道第几路
	Uint32      uiMainSubFlag;	///< 主辅流，参考枚举 #VmsVideoStreamType
	Uint32		uiDstIp[VMS_MAX_IPADDR_LEN];	///< 目的IP,按照四个字节方式存储的
	Uint32      uiDstPort;		///< 目的port          
	Uint32      uiTransMode;	///< 传输模式,参考枚举 #VmsTransType
	Uint32      uiStreamingType;///< 码流类型,参考枚举 #VmsMediaPacketType 
	Uint32      uiMcFlag;		///< 是否组播          
} TermLiveRecover;

typedef std::vector<TermLiveRecover> TermLiveRecoverList;

/** @brief 3.云台状态参数*/
typedef struct tagTermPtzStatus
{
	Uint32   uiPanSpeed;		///< 水平转速0-255
	Uint32   uiTiltSpeed;		///< 垂直速度0-255
	Uint32   uiFocusSpeed;		///< 聚焦速度0-255
	Uint32   uiZoomSpeed;		///< 变倍速度0-255
	Uint32   uiLockStatus;		///< 锁定，0-关闭 1-打开
	Uint32   uiLightStatus;		///< 补光，0-关闭 1-打开
	Uint32   uiInfraredStatus;	///< 红外，0-关闭 1-打开
	Uint32   uiBrushStatus;		///< 雨刷，0-关闭 1-打开
	Uint32   uiHeatStatus;		///< 加热，0-关闭 1-打开
} TermPtzStatus;

/** @brief 4.OSD时间设置*/
typedef struct tagTermOsdTimeConfig
{
	Uint32	 uiIndex;			///<  场名OSD索引,目前为0, 支持总共1个时间OSD.
	Uint32	 uiMainSubFlag;		///<  主辅流，参考枚举 #VmsVideoStreamType
	Uint32   uiIsEnable;		///< 显示时间，0-不显示，1-显示
	Uint32   uiOsdTimeFormat;	///< 时间格式，参考枚举 #VmsOsdTimeFormat
	Uint32   uiOsdDateFormat;	///< 日期格式，参考枚举 #VmsOsdDateFormat
	Uint32   uiStartX;			///< 起始X（宽度，为63360中的X份）
	Uint32   uiStartY;			///< 起始Y（高度，为8640中的Y份）
	Uint32   uiOsdColor;		///< 颜色，0-7（黑-->红）
	Uint32   uiOsdTransparence;	///< 透明度：取值范围1~8，默认值8
	Uint32   uiOsdTimeFreq;		///< 时间频率
} TermOsdTimeConfig;

typedef std::vector<TermOsdTimeConfig> TermOsdTimeList;

/** @brief 5.OSD场名信息*/
typedef struct tagTermOsdFieldConfig
{
	Uint32	uiIndex;			///<  场名OSD索引,目前为0-3, 支持总共4个场名OSD.
	Uint32	uiMainSubFlag;		///<  主辅流，参考枚举 #VmsVideoStreamType
	Uint32	uiIsEnable;			///<  显示场名信息，0-不显示，1-显示
	Uint32  uiOsdColor;			///<  颜色，0-7（黑-->红）
	Uint32  uiOsdTransparence;	///<  透明度，1-8
	Uint32  uiStartX;			///<  起始X（宽度，为63360中的X份）
	Uint32  uiStartY;			///<  起始Y（高度，为8640中的Y份）
	Uint32  uiSwitchInterval;	///<  0:代表使用主值，不切换;1～30（S）
	CHAR    szOsdMainValue[VMS_MAX_OSD_VALUE]; ///< 主值内容
	CHAR    szOsdSubValue[VMS_MAX_OSD_VALUE];  ///< 辅值内容
	Uint32  uiOsdMainType;		///<  0 - 配置字符串,1 - 本地数据
	Uint32  uiOsdSubType;		///<  0 - 配置字符串,1 - 本地数据
} TermOsdFieldConfig;

typedef std::vector<TermOsdFieldConfig> TermOsdFieldList;

/** @brief 6.系统时间设置命令结构体*/
typedef struct tagTermSysTime
{
	Uint32  uiYear;		///< 年
	UCHAR	uiMonth;	///< 月
	UCHAR   uiDay;		///< 日
	UCHAR   uiHour;		///< 时
	UCHAR   uiMin;		///< 分
	UCHAR   uiSec;		///< 秒
	UCHAR	reserved[3];
} TermSysTime;

/** @brief 7.透明通道保存配置信息查询*/
typedef struct tagTermTransSaveQuery
{
	Uint32   uiIpAddr[VMS_MAX_IPADDR_LEN];	///<  注意是按四字节ip方式存储的
	Uint32   uiIpPort;				///< 端口号
	Uint32   uiSerialIndex;			///< 串口索引
	Uint32   uiEnable;				///< 使能状态
} TermTransSaveQuery;

/** @brief 8.获取终端设备的物理类型信息*/
typedef struct tagTermGetTypeInfo
{
	Uint32  uiCameraType[VMS_MAX_DEV_CHANNEL_NUM];	///< 摄像机类型 0 -带云台 1- 不带云台
	Uint32  uiPlayerParam[VMS_MAX_DEV_CHANNEL_NUM*2];///< 高16位代表制式，低16位代表分辨率, 实际只使用channel_num个,
								///< 高32个字节表示主流播放器参数，低32个字节表示辅流播放器参数
	Uint32  uiDeviceType;		///< 设备类型，0 - EC, 1 -DC, 2- IPC 参考枚举 #VmsTerminalType
	CHAR    szTypeName[32];		///< 设备名字 VG1001/VG1004/VC6210...
	Uint32  uiChannelNum;		///< 通道个数
	Uint32  uiPhyId;			///< 
	Uint32  uiDeviceModel;		///< 设备型号名, 前16位用于区分不同协议(普通为0x0000, 电力为0x0001), 后16位填写DEVICE_NAME 
} TermGetTypeInfo;

/** @brief 9.版本升级(暂时未用到)*/
typedef struct tagTermVersionUpdate
{
	Uint32  uiTaskId;             ///< 任务ID(终端升级完成后需返回)
	Uint32  uiDevId;              ///< 设备ID(终端升级完成后需返回)
	Uint16  uiImageType;          ///< 镜像类型，参考枚举 #VmsTermUpgradType
	Uint16  uiAddrType;           ///< FTP服务器IP地址类型(IPV4/IPV6)，参考枚举 #VmsIPAddrType
	CHAR    szFtpservIp[VMS_MAX_IPADDR_LEN]; ///< FTP服务器IP
	CHAR    szUserName[VMS_MAX_NAME_LEN];       ///< FTP服务器用户名
	CHAR    szPassWord[VMS_PASSWD_LEN];       ///< FTP服务器密码
	CHAR    szKernelName[VMS_MAX_NAME_LEN];     ///< 内核镜像名称
	CHAR    szRamdiskName[VMS_MAX_NAME_LEN];    ///< 文件系统镜像名称
} TermVersionUpdate;

/** @brief 10 版本号查询，走命令模式(暂时未用到) */
typedef struct tagTermVersionReport
{
	CHAR   szKernelVersion[VMS_MAX_NAME_LEN];	///< version string
	CHAR   szRamdiskVersion[VMS_MAX_NAME_LEN];  ///< version string
} TermVersionReport;


/** @brief 11.视频流配置*/
typedef struct tagTermVideoStreamConfig
{
	Uint32   uiEnableStream;	///< 使能流，0 - 否，1 - 是
    Uint32   uiStreamTranType;	///< 流传输类型，参考枚举 #VmsTransType
    Uint32   uiStreamType;		///< 码流封装类型，参考枚举 #VmsMediaPacketType
    Uint32   uiEncodeFormat;	///< 编码格式，参考枚举 #VmsVideoCodecFormat
    Uint32   uiResolution;		///< 分辨率，参考枚举 #VmsVideoResolution
    Uint32   uiFrameRate;		///< 帧率,
    Uint32   uiBitRate;			///< 码率
    Uint32   uiIFrameInterval;	///< I帧间隔，1- 50
    Uint32   uiImageQuality;	///< 图像质量,在VBR模式下可设
	Uint32   uiEncodeMode;		///< 编码模式,VBR、CBR,系统默认是CBR,参考枚举 #VmsVideoECMode
	Uint32   uiPriority;		///< 优先级,参考枚举 #VmsVideoPriority (CBR模式下有效:连贯性优先、图像质量优先)
    Uint32   uiSmoothValue;		///< 码流平滑，参考枚举 #VmsBitstreamSmooth
    Uint32   uiGopMode;			///< GOP模式,参考枚举 #VmsVideoGOPMode
    // FIXME
    Uint32   uiQualityLevel;	///< 质量等级（暂时不用）
	Uint32   uiAddrType;		///< 组播地址类型：0-IPV4；1-IPV6

    Uint32   uiMulticastPort;	///< 组播端口号，单播模式下不能修改
    Uint32   uiMulticastAddr[VMS_MAX_IPADDR_LEN];	///< 组播IP地址，单播模式下不能修改
} TermVideoStreamConfig;

/** @brief 12.音频输入通道*/
typedef struct tagTermAinChannelConfig
{
	Uint32    uiIsSilent;		///< 是否静音,0 - 不静音,1 - 静音
	Uint32    uiIsEnable;		///< 使能,0 - 不使能,1 - 使能
	Uint32    uiAudioCoding;	///< 音频编码,参考枚举 #VmsAudioCoding
	Uint32    uiAudioTrack;		///< 音频声道,参考枚举 #VmsAudioTrack ,（这里系统默认为左声道）
	Uint32	  uiSamplingRate;	///< 采样率,G726时有效:参考枚举 #VmsAudioSampleRate
	CHAR      szAudioinDesc[VMS_MAX_DESC_LEN]; ///< 音频输入描述
	Uint32    uiIncrements;		///< 增益值,0 - 255
	Uint32    uiAudioBitrate;	///< 码率,G726时有效：参考枚举 #VmsAudioBitrate
} TermAinChannelConfig;


/** @brief 13.音频输出通道*/
typedef struct tagTermAoutChannelConfig
{
	Uint32    uiIsSilent;		///< 是否静音,0 - 不静音,1 - 静音
	Uint32    uiIsEnable;		///< 使能,0 - 不使能,1 - 使能
	Uint32	  uiAudioCoding;	///< 音频编码,参考枚举 #VmsAudioCoding
	Uint32    uiAudioTrack;		///< 音频声道,参考枚举 #VmsAudioTrack
	CHAR      szAudiooutDesc[VMS_MAX_DESC_LEN]; ///< 音频输入描述
	Uint32    uiIncrements;		///< 输出增益,0 - 255
} TermAoutChannelConfig;

/** @brief14.运动侦测配置*/
typedef struct tagTermMotionDetecConfig
{
	Uint8		uiVinChannelIndex;	///< 通道号
	Uint8		uiMotionAreaIndex;	///< 区域索引,0 - 3
	Uint8		bIsEnable;			///< 是否使能
	Uint8		uiSensitivity;		///< 灵敏度,1～5
	CHAR		szAreaName[VMS_MAX_NAME_LEN];  ///< 区域名
	BBitmap8_t  uiAreaMask[VMS_MAX_AREA_MASK]; ///< 区域块定义,1个16x16宏块占1bit
} TermMotionDetecConfig;

typedef std::vector<TermMotionDetecConfig> TermMotionDetecList;

/** @brief 15.抓图参数配置 */
typedef struct tagTermSnapshotConfig
{
	Uint8    uiFtpservIp[VMS_MAX_IPADDR_LEN];	///< FTP服务器IP 
	CHAR     szUsername[VMS_MAX_NAME_LEN];		///< FTP服务器用户名
	CHAR     szPassword[VMS_PASSWD_LEN];		///< FTP服务器密码
	CHAR     szPath[VMS_MAX_URL_LEN];           ///< FTP保存目录
	Uint32   uiNum;                     ///< 抓图数量1~5张
	Uint32   uiTimeval;                 ///< 抓图间隔50~500ms
} TermSnapshotConfig;

/** @brief 16. 摄像机PTZ信息*/
typedef struct tagTermPtzConfig
{
	Uint32   uiPtzAddrCode;			///< 云台地址码，云台摄像机时有效：0～255
	Uint32   uiAutoGuardInterval;	///< 自动回看守时间，60～1800(S)，默认为300
	CHAR     szPresetName[VMS_MAX_PRESET_POSITION_NUM][VMS_MAX_NAME_LEN]; ///< 预置点名称
	Uint8	 uiPresetList[VMS_MAX_PRESET_POSITION_NUM];		///< 预置点启用列表，0--未启用。1--启用
	Uint32   uiSerialIndex;			///< 绑定的串口编号
	Uint32   uiGuardPosition;		///< 看守位，0~127
	Uint32   uiPtzProtocol;			///< 云台控制协议(云台摄像机时有效)，参考枚举 #VmsPtzProtocol
	Uint32   uiPtzTranslateMode;	///< 云台协议翻译模式
} TermPtzConfig;

/** @brief 17.IPC光学参数*/
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
	Uint32   uiExposureArea;///< 曝光区域
	Uint32   uiBrightness;///< 亮度
	Uint32   uiContrast;///< 对比度
	Uint32   uiSaturation;///< 饱和度
	Uint32   uiColorTone;///< 
	Uint32   uiSharpness;///< 锐度
	Uint32   uiWdrEnable;///< 
	Uint32   uiWdrLevel;///< 
	Uint32   uiMirrorFlip;///< 镜像
	Uint32   uiAwbType;///< 情景模式
	Uint32   uiAwbMode;
	Uint32   uiGetAwbRGain;
	Uint32   uiGetAwbGGain;
	Uint32   uiGetAwbBGain;
	Uint32   uiSetAwbRGain;
	Uint32   uiSetAwbGGain;
	Uint32   uiSetAwbBGain;
	Uint32   uiFlickerCtrl;///< 视频制式
	Uint32   uiExposureCtrl;///< 曝光控制
	Uint32   uiExposureValue;///< 曝光值
	Uint32   uiIrisType;///< 光圈类型
	Uint32   uiMaxExposureTime;///< 最大曝光时间
	Uint32   uiMinExposureTime;///< 最小曝光时间
	Uint32   uiMaxGain;///< 最大增益
	Uint32   uiMinGain;///< 最小增益
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
	Uint32   uiExposureSensitivity;///< 曝光灵敏度
	Uint32   uiExposurePriority;///< 
	Uint32   uiCurColorTemperature;
	Uint32   uiColorSensitivity;
	Uint32   uiColorTransferTime;
} TermIpcOpticalConfig;

/** @brief 18.串口基本信息*/
typedef struct tagTermSerialConfig
{
	Uint32   uiIndex;					///< 串口索引	  
	CHAR     szSerialName[VMS_MAX_NAME_LEN];///< 串口名称
	Uint32   uiSerialType;				///< 串口类型：参考枚举 #VmsSerialType
	Uint32   uiSerialMode;				///< 串口模式：参考枚举 #VmsSerialMode 
	Uint32   uiBaudRate;				///< 波特率,参考枚举 #VmsSerialBandrate 
	Uint32   uiDataBit;					///< 数据位：参考枚举 #VmsSerialDatabit
	Uint32   uiStopBit;					///< 停止位：参考枚举 #VmsSerialStopbit
	Uint32   uiParityBit;				///< 校验位：参考枚举 #VmsSerialParitybit
	Uint32   uiFlowControl;				///< 流控：参考枚举 #VmsSerialFlowctrl 
} TermSerialConfig;

typedef std::vector<TermSerialConfig> TermSerialList;

/** @brief 19.开关量告警输入*/
typedef struct tagTermSemaInputConfig
{
	Uint32	 uiIndex;							///< 开关量告警输入索引
	CHAR     szSemaName[VMS_MAX_NAME_LEN];		///< 开关量名称
	CHAR     szSemaInputDesc[VMS_MAX_DESC_LEN];	///< 输入开关量描述
	Uint32   uiIsEnable;					///< 是否使能
	Uint32   uiTriggerMode;					///< 输入开关量告警触发方式:0 常开、1 常闭
	Uint32   uiEnableDetect;				///< 线路检测使能
	Uint32   uiWorkMode;					///< 工作模式，参考枚举 #VmsSemaTriggerMode
} TermSemaInputConfig;

typedef std::vector<TermSemaInputConfig> TermSemaInputList;


/** @brief 20.开关量告警输出*/
typedef struct tagTermSemaOutputConfig
{
	Uint32	 uiIndex;						///< 开关量告警输出索引
	CHAR     szSemaName[VMS_MAX_NAME_LEN];		///< 开关量名称
	CHAR     szSemaOutputDesc[VMS_MAX_DESC_LEN];///< 输出开关量告警描述
	Uint32   uiSemaOutputTime;				///< 开关量告警输出打开时间
	Uint32   uiIsEnable;					///< 是否使能
	Uint32   uiTriggerMode;					///< 输出开关量告警触发方式:0 常开、1 常闭
	Uint32   uiEnableDetect;				///< 线路检测使能
	Uint32   uiWorkMode;					///< 工作模式，参考枚举 #VmsSemaTriggerMode
} TermSemaOutputConfig;

typedef std::vector<TermSemaOutputConfig> TermSemaOutputList;

/** @brief 21. EC信息*/
typedef struct tagTermEncoderConfig
{
	Uint32   uiLanguageSet;		 ///< 语言设置，参考枚举 #VmsLanguageSet
	Uint32   uiEnableLocalcache; ///< 启用本地缓存
	Uint32   uiEncodeSet;		 ///< 流套餐:参考枚举 #VmsVideoStreamType
	Uint32   uiStandard;		 ///< 制式（P、N）参考枚举 #VmsStandard
	Uint32   uiAudiocommrId;	 ///< 语音对讲资源id
	Uint32   uiAudiobroadcastId; ///< 语音广播资源id
	Uint32   uiEnableAlarm;		 ///< 告警使能
	Uint32   uiIsMulticast;		 ///< 是否支持组播
	//FIXME
	Uint32   uiKeepaliveInterval;///< 保活间隔时间
	Uint32   uiIsAutofit;		 ///< 适应策略
} TermEncoderConfig;

/** @brief 22. DC信息*/
typedef struct tagTermDecoderConfig
{
	Uint32   uiLanguageSet;		 ///< 语言设置，参考枚举 #VmsLanguageSet
	Uint32   uiEncodeSet;		 ///< 流套餐:参考枚举 #VmsVideoStreamType
	Uint32   uiStandard;		 ///< 制式（P、N）,参考枚举 #VmsStandard
	Uint32   uiEnableAlarm;		 ///< 告警使能
	Uint32   uiKeepaliveInterval;///< 保活间隔时间
	Uint32   uiIsMulticast;		 ///< 是否支持组播
	Uint32   uiIsAutofit;		 ///< 适应策略
} TermDecoderConfig;

/** @brief 23. 温度告警配置*/
typedef struct tagTermTempeAlarmConfig
{
	Uint32   uiTempeAlarmUpper;	///< 温度告警上限
	Uint32   uiTempeAlarmLower;	///< 温度告警下限
	CHAR     szTempeAlarmDesc[VMS_MAX_DESC_LEN]; ///< 温度告警描述
	Uint32   uiIsEnable;		///< 是否使能
} TermTempeAlarmConfig;

/** @brief 24. 音频对讲输入配置*/
typedef struct tagTermAudiocommrInputConfig
{
	Uint32    uiAudiocommrRes;			///< 音频资源标识
	Uint32    uiIsSilent;				///< 是否静音
	Uint32    uiAudiocommrInputMethod;	///< 音频输入方式(MIC/LINE),参考枚举 #VmsAudioCommrInputMethod
	Uint32    uiAudiocommrEncodeFormat;	///< 音频编码格式,参考枚举 #VmsAudioCoding
	CHAR      szAudiocommrResDesc[VMS_MAX_DESC_LEN]; ///< 音频资源描述
	Uint32    uiAudiocommrSampleRate;	///< 采样率：取值8K
	Uint32    uiAudiocommrBitrate;		///< 音频码率：编码格式为G726时有效,参考枚举 #VmsAudioBitrate
	Uint32    uiAudiocommrInputIncrements;	///< 输入增益：取值范围0~255；默认值128
	Uint32    uiAudiocommrInputTrack;	///< 音频声道设置,参考枚举 #VmsAudioTrack
} TermAudiocommrInputConfig;

/** @brief 25.音频对讲输出配置*/
typedef struct tagTermAudiocommrOutputConfig
{
	Uint32   uiAudiocommrRes;			///< 音频资源标识
	Uint32   uiIsSilent;				///< 是否静音
	Uint32   uiAudiocommrOutputMethod;	///< 音频输出方式(MIC/LINE),参考枚举 #VmsAudioCommrInputMethod
	Uint32   uiAudiocommrEncodeFormat;	///< 音频编码格式,参考枚举 #VmsAudioCoding
	CHAR     szAudiocommrResDesc[VMS_MAX_DESC_LEN]; ///< 音频资源描述
	Uint32   uiAudiocommrBitrate;		///< 播放帧率：取值8K
	Uint32   uiAudiocommrOutputIncrements; ///< 输出增益：取值范围0~255；默认值128
	Uint32   uiAudiocommrOutputTrack;	 ///< 声道设置,参考枚举 #VmsAudioTrack
} TermAudiocommrOutputConfig;

/** @brief 26.隐私遮盖配置*/
typedef struct tagTermPrivacyMaskConfig
{
	Uint32   uiVinChannelIndex;	///< 视频输入通道索引
	Uint32   uiMaskAreaIndex;	///< 遮盖索引,0 - 3
	Uint32   uiIsEnable;		///< 是否使能
	Uint32   uiMaskColor;		///< 遮盖颜色,0 - 7
	Uint32   uiTopLeftX;		///< 左上x坐标
	Uint32   uiTopLeftY;		///< 左上y坐标
	Uint32   uiBottomRightX;	///< 右下x坐标
	Uint32   uiBottomRightY;	///< 右下y坐标
} TermPrivacyMaskConfig;

typedef std::vector<TermPrivacyMaskConfig> TermPrivacyMaskConfigList;

/** @brief 27. 摄像机配置*/
typedef struct tagTermCameraConfig
{
	Uint32  uiLongitude;	///< 经度
	Uint32  uiLatitude;		///< 纬度
	CHAR    szCameraName[VMS_MAX_NAME_LEN];	///< 摄像机名
	CHAR    szCameraDesc[VMS_MAX_DESC_LEN];	///< 备注
	Uint32  uiIsEnable;		///< 使能
	Uint32  uiBrightness;	///< 亮度,0 - 255
	Uint32  uiContrast;		///< 对比度,0 - 255
	Uint32  uiSaturation;	///< 饱和度,0 - 255
	Uint32  uiTone;			///< 色调,0 - 255
	Uint32  uiWhiteBlance;	///< 白平衡,对IPC有效,（目前无效）
	Uint32  uiCameraType;	///< 摄像机类型,参考枚举 #VmsCameraType
} TermCameraConfig;

/** @brief 28.终端设备参数结构体*/
typedef struct tagTermDeviceConfig
{
	Uint8    uiVmServerIpaddr[VMS_MAX_IPADDR_LEN];	///< VM服务器ip
	Uint32   uiVmServerPort;				///< VM服务器端口号
	Uint32   uiDeviceRunMode;				///< 设备运行模式 0 -托管模式  1 -独立运行模式
	Uint32   uiIpVersion;					///< ip类型，
	CHAR     uiDeviceId[VMS_DEVICE_SN_LEN];	///< 设备ID号

	CHAR     szRnId[VMS_MAX_NAME_LEN];			///< 环ID
	Uint32   uiRnEnable;					///< 环网使能
	Uint32   uiRnNodeMode;					///< 节点工作模式 0-主 1-从 
	Uint32   uiRnTimeoutCount;				///<  

	Uint32   uiVlanEnable;					///< 
	Uint32   uiNetDefaultVid;				///< 网口1的默认vid
	Uint32   uiCpuDefaultVid;				///< cpu的默认vid
	Uint32   uiNet2DefaultVid;				///< 网口2的默认vid
	Uint32   uiNet3DefaultVid;				///< 网口3的默认vid
} TermDeviceConfig;

/** @brief 29. 物理通道输出*/
typedef struct tagTermPhyoutChannelConfig
{
	Uint8		uiPhyoutMode;		///< 物理通道输出方式：参考枚举 #VmsPhyoutMode
	Uint8		uiFillMethod;		///< 填充方式，在HDMI四窗格输出模式下有效,参考枚举 #VmsFillMethod
	Uint8		uiDecodeFormat;		///< 解码格式（暂时不用）
	Uint8		uiAudioFormat;		///< 音频格式（暂时不用）
	Uint8		uiAudioTrack;		///< 声道设置（暂时不用）
	UCHAR		bIsSilent;			///< 静音标识（暂时不用）
	Uint8		uiVolume;			///< 输出音量（暂时不用）
	Uint8		uiOutputIndex;		///< 音频输出选择，音频输出接口和视频接口的对应关系：当输出方式为HDMI四窗格输出时，该值表示采用哪个通道的音频作为输出
	Uint8		uiStreamType;		///< 视频码流封装类型：参考VmsMediaPacketType
	Uint8		uiResolution;		///< 支持的最大分辨率：具体取值参考码流参数VmsVideoResolution
	Uint16		uiSmoothValue;		///< 
	CHAR		szMonitorName[VMS_MAX_NAME_LEN];	///< 监视器名称
	CHAR		szMonitorDesc[VMS_MAX_DESC_LEN];	///< 监视器描述
} TermPhyoutChannelConfig;

/** @brief 30.终端网卡参数配置结构体*/
typedef struct tagTermEthernetConfig
{
	Uint32  uiMode;			///< 网卡模式，参考枚举VmsNetworkSpeedDuplex
	Uint32  uiMtu;			///< MTU设置,576~1500
	Uint8   uiEthIndex;		///< 网卡索引号
	Uint8	reserved[3];
} TermEthernetConfig;

/** @brief 31.终端设备参数信息结构体 */
typedef struct tagTermDeviceCapability
{
	CHAR 		szSerialNumber[VMS_DEVICE_SN_LEN];		///< 设备序列号
	Uint32		uiCameraType[VMS_MAX_DEV_CHANNEL_NUM];	///< 摄像机类型 0 -带云台 1- 不带云台，参考枚举 #VmsCameraType
	Uint32		uiDeviceType;							///< 设备类型，0 - EC, 1 -DC, 2- IPC 参考枚举 #VmsTerminalType
	CHAR		szDeviceModelName[VMS_MAX_NAME_LEN];	///< 设备名字 VG1001/VG1004/VC6210...
	Uint32      uiSerialNum;            ///< 串口个数
	Uint32      uiVideoInChannelNum;    ///< 视频输入通道个数
	Uint32      uiVideoOutChannelNum;   ///< 视频输出通道个数
	Uint32      uiAudioInChannelNum;    ///< 音频输入通道个数
	Uint32      uiAudioOutChannelNum;   ///< 音频输出通道个数
	Uint32      uiSemaInputNum;         ///< 开关量输入个数
	Uint32      uiSemaOutputNum;        ///< 开关量输出个数
	Uint32      uiPrivacyMaskNum;       ///< 支持的隐私遮蔽个数
	Uint32      uiMotionAreaNum;        ///< 支持的移动侦测个数
	Uint32      uiOsdTimeNum;           ///< 时间OSD个数
	Uint32      uiOsdFieldNum;          ///< 场名OSD个数
	Uint32      uiPhyoutSplitMaxNum;    ///< 支持的最大分屏数
} TermDeviceCapability;

/** @brief 31.ip信息配置结构体 */
typedef struct tagTermNetIpConfig
{
	Uint8  iIp[VMS_MAX_IPADDR_LEN];		///< IP地址
	Uint8  iMask[VMS_MAX_IPADDR_LEN];	///< 子网掩码
	Uint8  iGateway[VMS_MAX_IPADDR_LEN];///< 网关

	CHAR   szPppoeUsername[VMS_PPPOE_NAME_PASSWD_LEN];	///< 暂时保留，如果修改本结构体，先获取，再原值传入
	CHAR   szPppoePasswd[VMS_PPPOE_NAME_PASSWD_LEN];	///< 暂时保留，如果修改本结构体，先获取，再原值传入

	Uint8  iGetIpMode;	///< 获取方式，暂时保留，如果修改本结构体，先获取，再原值传入
	Uint8  iEthIdx;		///< 网卡序列号
	Uint8  iIpVersion;	///< IP地址类型(IPV4/IPV6)，参考枚举 #VmsIPAddrType
	Uint8  reserved;
} TermNetIpConfig;

#pragma pack(pop)
#endif    //  _TERM_NET_STRUCT_