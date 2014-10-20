//
//
#ifndef __linux__
    #ifdef TERMNETSDK_EXPORTS
    #define TERMNETSDK_API __declspec(dllexport)
    #else
    #define TERMNETSDK_API __declspec(dllimport)
    #endif
#else
    #define TERMNETSDK_API
#endif

#include <list>

#include "types.h"
#include "SdkError.h"
#include "VmsCommon.h"
#include "TermNetStruct.h"

/*  OS_TYPE_MACRO */
#define OS_TYPE_LINUX 1
#define OS_TYPE_WIN32 2

#ifdef WIN32
#define SDK_OS_TYPE OS_TYPE_WIN32
#else
#define SDK_OS_TYPE OS_TYPE_LINUX
#endif

typedef Int32 (*fDisconnectCallback)(IN LONG lUserId, void *pContext);

/*typedef Int32 (*fVersionUpdateCallback)(IN LONG lUserId, TermVersionUpdate *pVersionUpdateParam, void *pContext);*/

typedef Int32 (*fVersionUpdateReplyCallback)(IN LONG lUserId, IN VmsStatus *pStatus, IN Int32 uiImageType, void *pContext);

/* 
 * =========================================================================
 * 	   Function: TermNetInit() 
 *  Description: 初始化接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: 无
 *	     Output: 无
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others: 
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetInit(void);

/* 
 * =========================================================================
 * 	   Function: TermNetCleanup() 
 *  Description: Cleanup接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: 无
 *	     Output: 无
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others: 
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetCleanup(void);

/* 
 * =========================================================================
 * 	   Function: TermNetRegisterDisconnectCallback() 
 *  Description: 注册掉线回调接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: cbDisconnect -
 *				 pContext	  -
 *	     Output: 无
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others: 
 * =========================================================================
 */
TERMNETSDK_API void TermNetRegisterDisconnectCallback(fDisconnectCallback cbDisconnect, void *pContext);

/* 
 * =========================================================================
 * 	   Function: TermNetImageUpdateCallback() 
 *  Description: 注册镜像升级回调接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: cbDisconnect -
 *				 pContext	  -
 *	     Output: 无
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others: 
 * =========================================================================
 */
TERMNETSDK_API void TermNetImageUpdateCallback(fVersionUpdateReplyCallback cbDisconnect, void *pContext);

#if 0
/* 
 * =========================================================================
 * 	   Function: TermNetRegisterLivePlayStartCallback() 
 *  Description: 注册实况开始回调接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: cbLivePlayStart -
 *				 pContext		 -
 *	     Output: 无
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others: 
 * =========================================================================
 */
TERMNETSDK_API void TermNetRegisterLivePlayStartCallback(fLivePlayStartCallback cbLivePlayStart, void *pContext);
#endif

/* 
 * =========================================================================
 * 	   Function: TermNetLogin() 
 *  Description: Login 接口
 *		  Calls:
 *	  Called By: 
 *	  	  Input: pServerIp	- 终端ip地址
 *	  	  		 iServerPort- 终端端口号
 *	  	  		 pUserName	- 用户登入用户名
 *	  	  		 pPasswd	- 用户登入密码
 *	     Output: plUserId	- 如果是linux平台调用sdk需传入该指针，
 *							  sdk将相应数据返回给调用者,windows平台可以传NULL
 *	     Return: sdk的错误码，参考SdkError.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetLogin(IN CHAR *pServerIp, IN Uint32 iServerPort, IN CHAR *pUserName, IN UCHAR *pPasswd, OUT LONG *plUserId);

/* 
 * =========================================================================
 * 	   Function: TermNetLogout() 
 *  Description: Logout接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId -用户ID
 *	     Output: 无
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others: 
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetLogout(IN LONG lUserId);

/* 
 * =========================================================================
 * 	   Function: TermNetLivePlayStart()
 *  Description: 启动EC实况单播（组播）命令接口函数
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	-用户ID
 *				 pLiveParam	-实况参数，参照TermNettruct.h中关于TermLivePlayParam结构体的说明
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetLivePlayStart(IN LONG lUserId, IN TermLivePlayParam *pLiveParam);

/* 
 * =========================================================================
 * 	   Function: TermNetLivePlayStop()
 *  Description: 结束EC/DC实况命令接口函数
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	-用户ID
 *				 pLiveParam	-实况参数，参照TermNettruct.h中关于TermLivePlayParam结构体的说明
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others: EC和DC结束时的结构体一样，而且SDK_DCLIVE_STOP(0X02)和SDK_ECLIVE_STOP(0X02)
 *				 结束的命令号一样，所以它们结束可以写在同一个接口
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetLivePlayStop(IN LONG lUserId, IN TermLivePlayParam *pLiveParam);

/* 
 * =========================================================================
 * 	   Function: TermNetPtzCtrl()
 *  Description: 云台控制命令接口函数 
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  - 用户ID
 *				 iChannel - 云台的通道号
 *				 iCommand - 云台命令号
 *				 iParam   - 命令的参数值,比如：速度设定命令是为设定的速度值，
 *						   调用预置点时为预置点索引号，调用巡航路线时为巡航路线索引号
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetPtzCtrl(IN LONG lUserId, IN Uint32 iChannel, IN Uint32 iCommand, IN Uint32 iParam);

/* 
 * =========================================================================
 * 	   Function:TermNetPtzStatusQuery()
 *  Description: 云台控制命令接口函数 
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	- 用户ID
 *				 iChannel	- 云台的通道号
 *				 iCommand	- 云台命令号					
 *	     Output: pPtzStatus -云台状态，参考TermNettruct.h中关于TermPtzStatus结构体的说明
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetPtzStatusQuery(IN LONG lUserId, IN Uint32 iChannel, IN Uint32 iCommand, OUT TermPtzStatus *pPtzStatus);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取OSD时间参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	   -用户ID
 *				 iChannel	   -视频通道号
 *	     Output: listOsdTimes  -用户获得的某一个通道内所有OSD时间配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetTimeConfig(IN LONG lUserId, IN Int32 iChannel, OUT TermOsdTimeList &listOsdTimes);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置OSD时间参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	    - 用户ID
 *				 iChannel	    - 视频通道号
 *				 pSetTimeConfig - 传入的用户设置的OSD时间配置信息，详见结构体TermOsdTimeConfig
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetTimeConfig(IN LONG lUserId, IN Int32 iChannel, IN TermOsdTimeConfig *pSetTimeConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取某个通道所有OSD场名参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	    - 用户ID
 *				 iChannel	    - 视频通道号
 *	     Output: listOsdFields  - 用户获得的某个通道所有OSD场名参数配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetFieldConfig(IN LONG lUserId, IN Int32 iChannel, OUT TermOsdFieldList &listOsdFields);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置OSD场名参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - 用户ID
 *				 iChannel	     - 摄像机通道号
 *				 pSetFieldConfig - 传入的用户设置的OSD场名配置信息，详见结构体TermOsdFieldConfig
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetFieldConfig(IN LONG lUserId, IN Int32 iChannel, IN TermOsdFieldConfig *pSetFieldConfig);


/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取某个通道内的辅流或者主流的视频流参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	    - 用户ID
 *				 iChannel	    - 视频通道号
 *				 iStreamIndex	-主辅流标志  0 - 主流 1 - 辅流
 *	     Output: pVideoStreamConfig  - 用户获得的某个通道所有OSD场名参数配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetVideoConfig(IN LONG lUserId, IN Int32 iChannel, IN Int32 iStreamIndex, OUT TermVideoStreamConfig *pVideoStreamConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置视频流参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - 用户ID
 *				 iChannel	     - 视频通道号
 *				 iStreamIndex	 -主辅流标志  0 - 主流 1 - 辅流
 *				 pVideoStreamConfig - 传入的用户设置的视频流配置信息
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
 TERMNETSDK_API Int32 TermNetSetVideoConfig(IN LONG lUserId, IN Int32 iChannel, IN Int32 iStreamIndex, IN TermVideoStreamConfig *pVideoStreamConfig);


/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取某个通道音频流输入参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	    - 用户ID
 *				 iChannel	    - 视频通道号
 *	     Output: pAinChannelConfig  - 用户获得的某个通道音频流输入参数配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetAudioConfig(IN LONG lUserId, IN Int32 iChannel,OUT TermAinChannelConfig *pAinChannelConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置音频流输入参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - 用户ID
 *				 iChannel	     - 摄像机通道号
 *				 pAinChannelConfig - 传入的用户设置的音频输入配置信息，
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetAudioConfig(IN LONG lUserId, IN Int32 iChannel, IN TermAinChannelConfig *pAinChannelConfig);

#if 0
/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取某个通道运动侦测配置参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	    - 用户ID
 *				 iChannel	    - 视频通道号
 *	     Output: listMotionDetecs  - 用户获得的某个通道运动侦测配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetMotionDetecConfig(IN LONG lUserId, IN Int32 iChannel,OUT TermMotionDetecList &listMotionDetecs);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置某个通道运动侦测配置参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - 用户ID
 *				 iChannel	     - 摄像机通道号
 *				 pMotionDetecConfig - 传入的用户设置的运动侦测配置信息，
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetMotionDetecConfig(IN LONG lUserId, IN Int32 iChannel, IN TermMotionDetecConfig *pMotionDetecConfig);
#endif

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取某个通道网络抓拍配置参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	    - 用户ID
 *				 iChannel	    - 视频通道号
 *	     Output: pSnapshotConfig  - 用户获得的某个通道网络抓拍参数配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetSnapshotConfig(IN LONG lUserId, IN Int32 iChannel,OUT TermSnapshotConfig *pSnapshotConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置某个通道网络抓拍配置参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - 用户ID
 *				 iChannel	     - 摄像机通道号
 *				 pSnapshotConfig - 传入的用户设置的网络抓拍配置信息，
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetSnapshotConfig(IN LONG lUserId, IN Int32 iChannel, IN TermSnapshotConfig *pSnapshotConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取某个通道摄像机PTZ配置信息参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	    - 用户ID
 *				 iChannel	    - 视频通道号
 *	     Output: pPtzConfig  - 用户获得的某个通道PTZ配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetPtzConfig(IN LONG lUserId, IN Int32 iChannel,OUT TermPtzConfig *pPtzConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置某个通道摄像机PTZ配置信息参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - 用户ID
 *				 iChannel	     - 摄像机通道号
 *				 pPtzConfig		 - 传入的用户设置的PTZ配置信息
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetPtzConfig(IN LONG lUserId, IN Int32 iChannel, IN TermPtzConfig *pPtzConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置某个通道摄像机看守位函数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - 用户ID
 *				 iChannel	     - 摄像机通道号
 *				 iGuardPosition	 - 传入的用户设置的看守位
 *				 iAutoGuardInterval - 自动回看守时间，60～1800(S)，默认为300
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetGuardPosition(IN LONG lUserId, IN Int32 iChannel, IN Int32 iGuardPosition, IN Int32 iAutoGuardInterval);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取串口配置信息参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	        - 用户ID
 *	     Output: listSerialConfigs	- 用户获得的串口配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetSerialConfig(IN LONG lUserId, OUT TermSerialList &listSerialConfigs);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置串口配置信息参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - 用户ID
 *				 pSerialConfig	 - 传入的用户设置的串口配置信息
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetSerialConfig(IN LONG lUserId, IN TermSerialConfig *pSerialConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取开关量输入配置信息参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	    - 用户ID
 *	     Output: listSemaInputs	- 用户获得的开关量输入配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetSemaInputConfig(IN LONG lUserId, OUT TermSemaInputList &listSemaInputs);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置开关量输入配置信息参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	         - 用户ID
 *				 pSemaInputConfig	 - 传入的用户设置的开关量输入配置信息
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetSemaInputConfig(IN LONG lUserId, IN TermSemaInputConfig *pSemaInputConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取开关量输出配置信息参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	        - 用户ID
 *	     Output: listSemaOutputs	- 用户获得的开关量输出配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetSemaOutputConfig(IN LONG lUserId, OUT TermSemaOutputList &listSemaOutputs);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置开关量输出配置信息参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	         - 用户ID
 *				 pSemaOutputConfig	 - 传入的用户设置的开关量输出配置信息
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetSemaOutputConfig(IN LONG lUserId, IN TermSemaOutputConfig *pSemaOutputConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取温度告警配置信息参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	        - 用户ID
 *	     Output: pTempeAlarmConfig	- 用户获得的温度告警配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetTempeAlarmConfig(IN LONG lUserId, OUT TermTempeAlarmConfig *pTempeAlarmConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置温度告警配置信息参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	         - 用户ID
 *				 pTempeAlarmConfig	 - 传入的用户设置的温度告警配置信息
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetTempeAlarmConfig(IN LONG lUserId, IN TermTempeAlarmConfig *pTempeAlarmConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取音频对讲输出配置信息参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId					- 用户ID
 *	     Output: pAudiocommrOutputConfig	- 用户获得的音频对讲输出配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetAudiocommrOutputConfig(IN LONG lUserId, OUT TermAudiocommrOutputConfig *pAudiocommrOutputConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置音频对讲输出配置信息参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId					 - 用户ID
 *				 pAudiocommrOutputConfig	 - 传入的用户设置的音频对讲输出配置信息
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetAudiocommrOutputConfig(IN LONG lUserId, IN TermAudiocommrOutputConfig *pAudiocommrOutputConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取音频对讲输入配置信息参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId					- 用户ID
 *	     Output: pAudiocommrInputConfig 	- 用户获得的音频对讲输入配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetAudiocommrInputConfig(IN LONG lUserId, OUT TermAudiocommrInputConfig *pAudiocommrInputConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置音频对讲输入配置信息参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId					 - 用户ID
 *				 pAudiocommrInputConfig 	 - 传入的用户设置的音频对讲输入配置信息
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetAudiocommrInputConfig(IN LONG lUserId, IN TermAudiocommrInputConfig *pAudiocommrInputConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取DC配置信息参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId		- 用户ID
 *	     Output: pDecoderConfig	- 用户获得的DC配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetDecoderConfig(IN LONG lUserId, OUT TermDecoderConfig *pDecoderConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置DC配置信息参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId		 - 用户ID
 *				 pDecoderConfig	 - 传入的用户设置的DC配置信息
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetDecoderConfig(IN LONG lUserId, IN TermDecoderConfig *pDecoderConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取EC配置信息参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId		- 用户ID
 *	     Output: pEncoderConfig	- 用户获得的EC配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetEncoderConfig(IN LONG lUserId, OUT TermEncoderConfig *pEncoderConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置EC配置信息参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId		 - 用户ID
 *				 pEncoderConfig	 - 传入的用户设置的EC配置信息
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetEncoderConfig(IN LONG lUserId, IN TermEncoderConfig *pEncoderConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取隐私遮盖配置信息参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId				- 用户ID
 *				 iChannel				- 通道号
 *	     Output: listPrivacyMaskConfigs	- 用户获得的隐私遮盖配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetPrivacyMaskConfig(IN LONG lUserId, IN Int32 iChannel, OUT TermPrivacyMaskConfigList &listPrivacyMaskConfigs);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置隐私遮盖配置信息参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId			 - 用户ID
 *				 pPrivacyMaskConfig	 - 传入的用户设置的隐私遮盖配置信息
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetPrivacyMaskConfig(IN LONG lUserId, IN TermPrivacyMaskConfig *pPrivacyMaskConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取摄像机配置信息参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId				- 用户ID
 *				 iChannel				- 通道号
 *	     Output: pCameraConfig			- 用户获得的摄像机配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetCameraConfig(IN LONG lUserId, IN Int32 iChannel, OUT TermCameraConfig *pCameraConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置摄像机配置信息参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId			 - 用户ID
 *				 iChannel			 - 通道号
 *				 pCameraConfig		 - 传入的用户设置的摄像机配置信息
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetCameraConfig(IN LONG lUserId, IN Int32 iChannel, IN TermCameraConfig *pCameraConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取IPC光学参数配置信息参数接口
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId				- 用户ID
 *				 iChannel				- 通道号
 *	     Output: pIpcOpticalConfig		- 用户获得的IPC光学参数配置信息
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetIpcOpticalConfig(IN LONG lUserId, IN Int32 iChannel, OUT TermIpcOpticalConfig *pIpcOpticalConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  设置IPC光学参数配置信息参数接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId			 - 用户ID
 *				 iChannel			 - 通道号
 *				 pIpcOpticalConfig	 - 传入的用户设置的IPC光学参数配置信息
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetIpcOpticalConfig(IN LONG lUserId, IN Int32 iChannel, IN TermIpcOpticalConfig *pIpcOpticalConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 获取终端设备参数接口 
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId			 - 用户ID
 *	     Output: pDeviceConfig		 - 用户获得的终端设备参数
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetDeviceConfig(IN LONG lUserId, OUT TermDeviceConfig *pDeviceConfig);

//设置终端设备参数接口
TERMNETSDK_API Int32 TermNetSetDeviceConfig(IN LONG lUserId, IN TermDeviceConfig *pDeviceConfig);






/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 启动DC组播或单播实况接口函数
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId - 用户ID
 *	  	  		 pLiveStartInMonitor- 参照TermNetStruct.h中关于结构体TermLivePlayParam的说明
 *	  	 Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetLiveInMonitor(IN LONG lUserId, INOUT TermLivePlayParam *pLiveParam);

/* 
 * =========================================================================
 * 	   Function:   
 *  Description: 设置启动抓图命令接口 
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  用户ID
 *				 iNum 表示抓图通道号
 *	     Output:
 *	     Return:sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetJpegCaptureCmd(IN LONG lUserId, IN UCHAR iNum);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 查询保存的需要恢复的实况
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  -用户ID
 *				 iChannel - 查询保存的实况的通道号,
 *					        如果是0xff表示查询所有通道的保存的实况
 *	  	  		 iMaxItem - 该buf可允许查询的最大个数
 *	  	  		 pRetItem - 实际查询到的实况个数
 *	  	  		 listLiveRecovers - 
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSaveLiveQuery(IN LONG lUserId, IN UCHAR iChannel, IN Int32 iMaxItem, OUT  Int32 *pRetItem, OUT TermLiveRecoverList &listLiveRecovers);

/* 
 * =========================================================================
 * 	   Function: 
 *  Description: 设置终端时间函数  
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  -  用户ID
 *				 pSysTime -  系统时间结构体指针，参照TermNetStruct.h中关于结构体TermSysTime的说明
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetTime(IN LONG lUserId, IN TermSysTime *pSysTime);

/* 
 * =========================================================================
 * 	   Function: 
 *  Description: 获取终端时间函数  
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  -  用户ID
 *	     Output: pSysTime -  系统时间结构体指针，参照TermNetStruct.h中关于结构体TermSysTime的说明
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetTime(IN LONG lUserId, OUT TermSysTime *pSysTime);

/* 
 * =========================================================================
 * 	   Function: 
 *  Description: 系统重启命令接口函数
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId -用户ID
 *	     Output: 无
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetReboot(IN LONG lUserId);

/* 
 * * =========================================================================
 *       Function: 
 *    Description: 终端参数恢复出厂配置接口
 *          Calls:
 *      Called By:
 *          Input: lUserId  用户ID
 *         Output: 无
 *         Return: sdk的错误码，参考Sdkerror.h
 *        Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetFactorySet(IN LONG lUserId);

/* 
 * =========================================================================
 *     Function: 
 *  Description: 终端恢复默认配置函数接口
 *        Calls:
 *    Called By:
 *        Input: lUserId  用户ID
 *       Output: 无
 *       Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetReDefaultConf(IN LONG lUserId);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  日志导出函数
 *		  Calls:
 *	  Called By:
 *	  	  Input:  lUserId	-用户ID
 *				  pIP		- 日志导出tftp服务器的ip
 *	  	  		  pUserName - user_name, required for ftp
 *	  	  		  pPassWord - passwd, required for ftp
 *	     Output:
 *	     Return:
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetLogExport(IN LONG lUserId, IN CHAR *pIP, IN CHAR *pUserName, IN CHAR *pPassWord);

#if 0
/* 
 * =========================================================================
 * 	   Function:  
 *  Description: s2ip模式的透明通道建立接口 
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  -用户ID
 *				 iSerialIndex - 建立s2ip模式透明通道串口端的串口号
 *				 pDstIp - 建立s2ip模式透明通道ip端的ip
 *				 iDstPort - 建立s2ip模式透明通道ip端的port
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetTransSetup(IN LONG lUserId, IN UCHAR iSerialIndex, IN CHAR *pDstIp, IN Uint16 iDstPort);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: s2ip模式的透明通道撤销接口 
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId   -用户ID
 *				 iSerialIndex - 建立s2ip模式透明通道串口端的串口号
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetTransClear(IN LONG lUserId, IN UCHAR iSerialIndex);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: 保存建立的透明通道，保存的透明通道在系统重启后会自动恢复 
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  - 用户ID
 *				 iSerialIndex - 建立s2ip模式透明通道串口端的串口号
 *				 pDstIp - 建立s2ip模式透明通道ip端的ip
 *				 iDstPort - 建立s2ip模式透明通道ip端的port
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetTransSave(IN LONG lUserId, IN UCHAR iSerialIndex, IN CHAR *pDstIp, IN Uint16 iDstPort);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  删除保存的透明通道
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  -用户ID
 *				 iSerialIndex - 建立s2ip模式透明通道串口端的串口号
 *	     Output:
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetTransSaveCancel(IN LONG lUserId, IN UCHAR iSerialIndex);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  查询保存的透明通道接口
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId -用户ID
 *				 iMaxItem - pTransParam可以查询最大的透明通道个数，该参数是输入参数			 
 *	     Output: pTransParam - 保存查询到的透明通道
 *				 pQueryItem	 - 实际上查询到的透明通道的个数
 *	     Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetTransQuery(IN LONG lUserId, IN Int32 iMaxItem, OUT Int32 *pQueryItem, OUT TermTransSaveQuery *pTransParam);
#endif

/* 
 * =========================================================================
 *     Function:  
 *  Description: 对讲开始命令控制函数接口
 *        Calls:
 *    Called By:
 *        Input: lUserId -用户ID
 *				 iStreamType - 对讲音频传输协议 0 - udp 1 - tcp
 *				 pLocalIp - 对讲本地的IP，比如：“192.168.0.1”
 *				 iLocalPort - 对讲本地port
 *       Output: pDstIp   -对讲目的IP
 *				 pDstPort -对讲目的端口号
 *       Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetAudiocomStartCmd(IN LONG lUserId, IN UCHAR iStreamType, IN CHAR *pLocalIp, IN Uint16 iLocalPort, OUT CHAR *pDstIp, OUT Uint16 *pDstPort);

/* 
 * =========================================================================
 *     Function:  
 *  Description: 对讲结束命令控制函数接口
 *        Calls:
 *    Called By:
 *        Input: lUserId -用户ID
 *				 pLocalIp - 对讲本地ip,比如：“192.168.0.1”
 *				 iLocalPort - 对讲本地port
 *       Output:
 *       Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetAudiocomStopCmd(IN LONG lUserId, IN CHAR *pLocalIp, IN Uint16 iLocalPort);

/* 
 * =========================================================================
 *     Function:  
 *  Description: 设备物理信息查处接口
 *        Calls:
 *    Called By:
 *        Input: lUserId -用户ID
 *       Output: pDevInforParam - 获取设备信息的指针
 *       Return: sdk的错误码，参考Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetDevInfor(IN LONG lUserId, OUT TermGetTypeInfo *pDevInforParam);

/* 
 * =========================================================================
 * 	   Function: 
 *  Description:  通过ftp升级内核镜像的函数接口  
 *		  Calls:
 *	  Called By:  
 *	  	  Input:  lUserId	   -  用户ID
 *				  pFtpIp       -  镜像放置的ftp服务器的地址
 *	  	  		  pUser        -  登入ftp服务器的用户名
 *	  	  		  pPasswd      -  登入ftp服务器的密码
 *	  	  		  pKernelName  -  升级内核镜像的名称，如果此处填NULL则采用默认内核升级名称
 *	     Output:
 *	     Return:  sdk的错误码，参考Sdkerror.h
 *       Others:  user passwd kernel_name 字符串长度最长为32
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetKernelUpdate(IN LONG lUserId, IN CHAR *pFtpIp, IN CHAR *pUser, IN CHAR *pPasswd, IN CHAR *pKernelName);

/* 
 * =========================================================================
 * 	   Function: 
 *  Description:  通过ftp升级ramdisk镜像的函数接口  
 *		  Calls:
 *	  Called By:  
 *	  	  Input:  lUserId	    -  用户ID
 *				  pFtpIp        -  镜像放置的ftp服务器的地址
 *	  	  		  pUser         -  登入ftp服务器的用户名
 *	  	  		  pPasswd       -  登入ftp服务器的密码
 *	  	  		  pRamdiskName  -  升级ramdisk镜像的名称，如果此处填NULL则采用默认ramdisk升级名称
 *	     Output:
 *	     Return:  sdk的错误码，参考Sdkerror.h
 *       Others:  user passwd ramdisk_name 字符串长度最大为32
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetRamdiskUpdate(IN LONG lUserId, IN CHAR *pFtpIp, IN CHAR *pUser, IN CHAR *pPasswd, IN CHAR *pRamdiskName);

#if 0
/* 
 * =========================================================================
 * 	   Function: 
 *  Description:  通过ftp升级cpld镜像的函数接口  
 *		  Calls:
 *	  Called By:  
 *	  	  Input:  lUserId	    -  用户ID
 *				  pFtpIp        -  镜像放置的ftp服务器的地址
 *	  	  		  pUser         -  登入ftp服务器的用户名
 *	  	  		  pPasswd       -  登入ftp服务器的密码
 *	  	  		  pCpldName     -  升级cpld镜像的名称，如果此处填NULL则采用默认cpld升级名称
 *	     Output:
 *	     Return:  sdk的错误码，参考Sdkerror.h
 *       Others:  user passwd ramdisk_name 字符串长度最大为32
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetCpldUpdate(IN LONG lUserId, IN CHAR *pFtpIp, IN CHAR *pUser, IN CHAR *pPasswd, IN CHAR *pCpldName);

/* 
 * =========================================================================
 * 	   Function: 
 *  Description:  通过ftp升级fpga镜像的函数接口  
 *		  Calls:
 *	  Called By:  
 *	  	  Input:  lUserId	    -  用户ID
 *				  pFtpIp        -  镜像放置的ftp服务器的地址
 *	  	  		  pUser         -  登入ftp服务器的用户名
 *	  	  		  pPasswd       -  登入ftp服务器的密码
 *	  	  		  pFpgaName     -  升级fpga镜像的名称，如果此处填NULL则采用默认fpga升级名称
 *	     Output:
 *	     Return:  sdk的错误码，参考Sdkerror.h
 *       Others:  user passwd ramdisk_name 字符串长度最大为32
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetFpgaUpdate(IN LONG lUserId, IN CHAR *pFtpIp, IN CHAR *pUser, IN CHAR *pPasswd, IN CHAR *pFpgaName);

/* 
 * =========================================================================
 * 	   Function: 
 *  Description:  通过ftp升级镜像的函数接口,可以选择升级的镜像类型  
 *		  Calls:
 *	  Called By:  
 *	  	  Input:  lUserId	     -  用户ID 
 *				  pVersionUpdate -  参照TermImageUpdateResult结构体
 *	     Output:  pResult 	     -  该参数是输出参数，如果该函数返回成功，镜像的更新
 *				  				    结果会填写在此结构体中
 *	     Return:  
 *       Others:  
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetImageUpdate(IN LONG lUserId, IN TermVersionUpdate *pVersionUpdate, OUT TermImageUpdateResult *pResult);
#endif

/* 
 * =========================================================================
 * 	   Function: 
 *   Description: 终端版本号查询
 *		  Calls:
 *	  Called By:  
 *	  	  Input: lUserId	     -  用户ID 
 *	     Output: pVersionInfo    - 终端版本信息结构体，该参数是输出参数 
 *	     Return: sdk的错误码，参考Sdkerror.h
 *        Others:  
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetVersionQuery(IN LONG lUserId, OUT TermVersionReport *pVersionInfo);

/* 
 * =========================================================================
 * 	   Function: 
 *   Description: 物理通道输出参数信息查询
 *		  Calls:
 *	  Called By:  
 *	  	  Input: lUserId				 -  用户ID 
 *	     Output: pPhyoutChannelConfig    - 物理通道输出参数信息结构体，该参数是输出参数 
 *	     Return: sdk的错误码，参考Sdkerror.h
 *        Others:  
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetPhyoutChannelConfig(IN LONG lUserId, OUT TermPhyoutChannelConfig *pPhyoutChannelConfig);

/* 
 * =========================================================================
 * 	   Function: 
 *   Description: 物理通道输出参数信息配置
 *		  Calls:
 *	  Called By:  
 *	  	  Input: lUserId				 -  用户ID 
 *				 pPhyoutChannelConfig    -  用户输入的物理通道输出参数信息
 *	     Output:  
 *	     Return: sdk的错误码，参考Sdkerror.h
 *        Others:  
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetPhyoutChannelConfig(IN LONG lUserId, IN TermPhyoutChannelConfig *pPhyoutChannelConfig);

/* 
 * =========================================================================
 * 	   Function: 
 *   Description: 终端网卡参数信息查询
 *		  Calls:
 *	  Called By:  
 *	  	  Input: lUserId			-  用户ID 
 *	     Output: pEthernetConfig    -  用户获得的终端网卡参数信息结构体 
 *	     Return: sdk的错误码，参考Sdkerror.h
 *        Others:  
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetEthernetConfig(IN LONG lUserId, OUT TermEthernetConfig *pEthernetConfig);

/* 
 * =========================================================================
 * 	   Function: 
 *   Description: 终端网卡参数信息配置
 *		  Calls:
 *	  Called By:  
 *	  	  Input: lUserId			-  用户ID 
 *				 pEthernetConfig    -  用户输入的终端网卡参数信息结构体
 *	     Output:  
 *	     Return: sdk的错误码，参考Sdkerror.h
 *        Others:  
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetEthernetConfig(IN LONG lUserId, IN TermEthernetConfig *pEthernetConfig);

/* 
 * =========================================================================
 * 	   Function: 
 *   Description: 获取终端设备参数信息
 *		  Calls:
 *	  Called By:  
 *	  	  Input: lUserId				-  用户ID 
 *	     Output: pDeviceCapability      -  用户获得的获取终端设备参数信息 
 *	     Return: sdk的错误码，参考Sdkerror.h
 *        Others:  
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetDeviceCapability(IN LONG lUserId, OUT TermDeviceCapability *pDeviceCapability);

//获取终端设备ip配置信息----add by JLL at 2013.06.27
TERMNETSDK_API Int32 TermNetGetNetIpConfig(IN LONG lUserId, OUT TermNetIpConfig *pNetIpConfig);

//配置终端设备ip配置信息----add by JLL at 2013.06.27
TERMNETSDK_API Int32 TermNetSetNetIpConfig(IN LONG lUserId, IN TermNetIpConfig *pNetIpConfig);
