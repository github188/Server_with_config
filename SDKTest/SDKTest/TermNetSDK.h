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
 *  Description: ��ʼ���ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: ��
 *	     Output: ��
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others: 
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetInit(void);

/* 
 * =========================================================================
 * 	   Function: TermNetCleanup() 
 *  Description: Cleanup�ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: ��
 *	     Output: ��
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others: 
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetCleanup(void);

/* 
 * =========================================================================
 * 	   Function: TermNetRegisterDisconnectCallback() 
 *  Description: ע����߻ص��ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: cbDisconnect -
 *				 pContext	  -
 *	     Output: ��
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others: 
 * =========================================================================
 */
TERMNETSDK_API void TermNetRegisterDisconnectCallback(fDisconnectCallback cbDisconnect, void *pContext);

/* 
 * =========================================================================
 * 	   Function: TermNetImageUpdateCallback() 
 *  Description: ע�᾵�������ص��ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: cbDisconnect -
 *				 pContext	  -
 *	     Output: ��
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others: 
 * =========================================================================
 */
TERMNETSDK_API void TermNetImageUpdateCallback(fVersionUpdateReplyCallback cbDisconnect, void *pContext);

#if 0
/* 
 * =========================================================================
 * 	   Function: TermNetRegisterLivePlayStartCallback() 
 *  Description: ע��ʵ����ʼ�ص��ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: cbLivePlayStart -
 *				 pContext		 -
 *	     Output: ��
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others: 
 * =========================================================================
 */
TERMNETSDK_API void TermNetRegisterLivePlayStartCallback(fLivePlayStartCallback cbLivePlayStart, void *pContext);
#endif

/* 
 * =========================================================================
 * 	   Function: TermNetLogin() 
 *  Description: Login �ӿ�
 *		  Calls:
 *	  Called By: 
 *	  	  Input: pServerIp	- �ն�ip��ַ
 *	  	  		 iServerPort- �ն˶˿ں�
 *	  	  		 pUserName	- �û������û���
 *	  	  		 pPasswd	- �û���������
 *	     Output: plUserId	- �����linuxƽ̨����sdk�贫���ָ�룬
 *							  sdk����Ӧ���ݷ��ظ�������,windowsƽ̨���Դ�NULL
 *	     Return: sdk�Ĵ����룬�ο�SdkError.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetLogin(IN CHAR *pServerIp, IN Uint32 iServerPort, IN CHAR *pUserName, IN UCHAR *pPasswd, OUT LONG *plUserId);

/* 
 * =========================================================================
 * 	   Function: TermNetLogout() 
 *  Description: Logout�ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId -�û�ID
 *	     Output: ��
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others: 
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetLogout(IN LONG lUserId);

/* 
 * =========================================================================
 * 	   Function: TermNetLivePlayStart()
 *  Description: ����ECʵ���������鲥������ӿں���
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	-�û�ID
 *				 pLiveParam	-ʵ������������TermNettruct.h�й���TermLivePlayParam�ṹ���˵��
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetLivePlayStart(IN LONG lUserId, IN TermLivePlayParam *pLiveParam);

/* 
 * =========================================================================
 * 	   Function: TermNetLivePlayStop()
 *  Description: ����EC/DCʵ������ӿں���
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	-�û�ID
 *				 pLiveParam	-ʵ������������TermNettruct.h�й���TermLivePlayParam�ṹ���˵��
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others: EC��DC����ʱ�Ľṹ��һ��������SDK_DCLIVE_STOP(0X02)��SDK_ECLIVE_STOP(0X02)
 *				 �����������һ�����������ǽ�������д��ͬһ���ӿ�
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetLivePlayStop(IN LONG lUserId, IN TermLivePlayParam *pLiveParam);

/* 
 * =========================================================================
 * 	   Function: TermNetPtzCtrl()
 *  Description: ��̨��������ӿں��� 
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  - �û�ID
 *				 iChannel - ��̨��ͨ����
 *				 iCommand - ��̨�����
 *				 iParam   - ����Ĳ���ֵ,���磺�ٶ��趨������Ϊ�趨���ٶ�ֵ��
 *						   ����Ԥ�õ�ʱΪԤ�õ������ţ�����Ѳ��·��ʱΪѲ��·��������
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetPtzCtrl(IN LONG lUserId, IN Uint32 iChannel, IN Uint32 iCommand, IN Uint32 iParam);

/* 
 * =========================================================================
 * 	   Function:TermNetPtzStatusQuery()
 *  Description: ��̨��������ӿں��� 
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	- �û�ID
 *				 iChannel	- ��̨��ͨ����
 *				 iCommand	- ��̨�����					
 *	     Output: pPtzStatus -��̨״̬���ο�TermNettruct.h�й���TermPtzStatus�ṹ���˵��
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetPtzStatusQuery(IN LONG lUserId, IN Uint32 iChannel, IN Uint32 iCommand, OUT TermPtzStatus *pPtzStatus);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡOSDʱ������ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	   -�û�ID
 *				 iChannel	   -��Ƶͨ����
 *	     Output: listOsdTimes  -�û���õ�ĳһ��ͨ��������OSDʱ��������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetTimeConfig(IN LONG lUserId, IN Int32 iChannel, OUT TermOsdTimeList &listOsdTimes);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ����OSDʱ������ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	    - �û�ID
 *				 iChannel	    - ��Ƶͨ����
 *				 pSetTimeConfig - ������û����õ�OSDʱ��������Ϣ������ṹ��TermOsdTimeConfig
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetTimeConfig(IN LONG lUserId, IN Int32 iChannel, IN TermOsdTimeConfig *pSetTimeConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡĳ��ͨ������OSD���������ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	    - �û�ID
 *				 iChannel	    - ��Ƶͨ����
 *	     Output: listOsdFields  - �û���õ�ĳ��ͨ������OSD��������������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetFieldConfig(IN LONG lUserId, IN Int32 iChannel, OUT TermOsdFieldList &listOsdFields);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ����OSD���������ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - �û�ID
 *				 iChannel	     - �����ͨ����
 *				 pSetFieldConfig - ������û����õ�OSD����������Ϣ������ṹ��TermOsdFieldConfig
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetFieldConfig(IN LONG lUserId, IN Int32 iChannel, IN TermOsdFieldConfig *pSetFieldConfig);


/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡĳ��ͨ���ڵĸ���������������Ƶ�������ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	    - �û�ID
 *				 iChannel	    - ��Ƶͨ����
 *				 iStreamIndex	-��������־  0 - ���� 1 - ����
 *	     Output: pVideoStreamConfig  - �û���õ�ĳ��ͨ������OSD��������������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetVideoConfig(IN LONG lUserId, IN Int32 iChannel, IN Int32 iStreamIndex, OUT TermVideoStreamConfig *pVideoStreamConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ������Ƶ�������ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - �û�ID
 *				 iChannel	     - ��Ƶͨ����
 *				 iStreamIndex	 -��������־  0 - ���� 1 - ����
 *				 pVideoStreamConfig - ������û����õ���Ƶ��������Ϣ
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
 TERMNETSDK_API Int32 TermNetSetVideoConfig(IN LONG lUserId, IN Int32 iChannel, IN Int32 iStreamIndex, IN TermVideoStreamConfig *pVideoStreamConfig);


/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡĳ��ͨ����Ƶ����������ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	    - �û�ID
 *				 iChannel	    - ��Ƶͨ����
 *	     Output: pAinChannelConfig  - �û���õ�ĳ��ͨ����Ƶ���������������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetAudioConfig(IN LONG lUserId, IN Int32 iChannel,OUT TermAinChannelConfig *pAinChannelConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ������Ƶ����������ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - �û�ID
 *				 iChannel	     - �����ͨ����
 *				 pAinChannelConfig - ������û����õ���Ƶ����������Ϣ��
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetAudioConfig(IN LONG lUserId, IN Int32 iChannel, IN TermAinChannelConfig *pAinChannelConfig);

#if 0
/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡĳ��ͨ���˶�������ò����ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	    - �û�ID
 *				 iChannel	    - ��Ƶͨ����
 *	     Output: listMotionDetecs  - �û���õ�ĳ��ͨ���˶����������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetMotionDetecConfig(IN LONG lUserId, IN Int32 iChannel,OUT TermMotionDetecList &listMotionDetecs);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ����ĳ��ͨ���˶�������ò����ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - �û�ID
 *				 iChannel	     - �����ͨ����
 *				 pMotionDetecConfig - ������û����õ��˶����������Ϣ��
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetMotionDetecConfig(IN LONG lUserId, IN Int32 iChannel, IN TermMotionDetecConfig *pMotionDetecConfig);
#endif

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡĳ��ͨ������ץ�����ò����ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	    - �û�ID
 *				 iChannel	    - ��Ƶͨ����
 *	     Output: pSnapshotConfig  - �û���õ�ĳ��ͨ������ץ�Ĳ���������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetSnapshotConfig(IN LONG lUserId, IN Int32 iChannel,OUT TermSnapshotConfig *pSnapshotConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ����ĳ��ͨ������ץ�����ò����ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - �û�ID
 *				 iChannel	     - �����ͨ����
 *				 pSnapshotConfig - ������û����õ�����ץ��������Ϣ��
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetSnapshotConfig(IN LONG lUserId, IN Int32 iChannel, IN TermSnapshotConfig *pSnapshotConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡĳ��ͨ�������PTZ������Ϣ�����ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	    - �û�ID
 *				 iChannel	    - ��Ƶͨ����
 *	     Output: pPtzConfig  - �û���õ�ĳ��ͨ��PTZ������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetPtzConfig(IN LONG lUserId, IN Int32 iChannel,OUT TermPtzConfig *pPtzConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ����ĳ��ͨ�������PTZ������Ϣ�����ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - �û�ID
 *				 iChannel	     - �����ͨ����
 *				 pPtzConfig		 - ������û����õ�PTZ������Ϣ
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetPtzConfig(IN LONG lUserId, IN Int32 iChannel, IN TermPtzConfig *pPtzConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ����ĳ��ͨ�����������λ�����ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - �û�ID
 *				 iChannel	     - �����ͨ����
 *				 iGuardPosition	 - ������û����õĿ���λ
 *				 iAutoGuardInterval - �Զ��ؿ���ʱ�䣬60��1800(S)��Ĭ��Ϊ300
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetGuardPosition(IN LONG lUserId, IN Int32 iChannel, IN Int32 iGuardPosition, IN Int32 iAutoGuardInterval);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡ����������Ϣ�����ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	        - �û�ID
 *	     Output: listSerialConfigs	- �û���õĴ���������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetSerialConfig(IN LONG lUserId, OUT TermSerialList &listSerialConfigs);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ���ô���������Ϣ�����ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	     - �û�ID
 *				 pSerialConfig	 - ������û����õĴ���������Ϣ
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetSerialConfig(IN LONG lUserId, IN TermSerialConfig *pSerialConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡ����������������Ϣ�����ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	    - �û�ID
 *	     Output: listSemaInputs	- �û���õĿ���������������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetSemaInputConfig(IN LONG lUserId, OUT TermSemaInputList &listSemaInputs);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ���ÿ���������������Ϣ�����ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	         - �û�ID
 *				 pSemaInputConfig	 - ������û����õĿ���������������Ϣ
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetSemaInputConfig(IN LONG lUserId, IN TermSemaInputConfig *pSemaInputConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡ���������������Ϣ�����ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	        - �û�ID
 *	     Output: listSemaOutputs	- �û���õĿ��������������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetSemaOutputConfig(IN LONG lUserId, OUT TermSemaOutputList &listSemaOutputs);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ���ÿ��������������Ϣ�����ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	         - �û�ID
 *				 pSemaOutputConfig	 - ������û����õĿ��������������Ϣ
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetSemaOutputConfig(IN LONG lUserId, IN TermSemaOutputConfig *pSemaOutputConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡ�¶ȸ澯������Ϣ�����ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId	        - �û�ID
 *	     Output: pTempeAlarmConfig	- �û���õ��¶ȸ澯������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetTempeAlarmConfig(IN LONG lUserId, OUT TermTempeAlarmConfig *pTempeAlarmConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  �����¶ȸ澯������Ϣ�����ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId	         - �û�ID
 *				 pTempeAlarmConfig	 - ������û����õ��¶ȸ澯������Ϣ
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetTempeAlarmConfig(IN LONG lUserId, IN TermTempeAlarmConfig *pTempeAlarmConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡ��Ƶ�Խ����������Ϣ�����ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId					- �û�ID
 *	     Output: pAudiocommrOutputConfig	- �û���õ���Ƶ�Խ����������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetAudiocommrOutputConfig(IN LONG lUserId, OUT TermAudiocommrOutputConfig *pAudiocommrOutputConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ������Ƶ�Խ����������Ϣ�����ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId					 - �û�ID
 *				 pAudiocommrOutputConfig	 - ������û����õ���Ƶ�Խ����������Ϣ
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetAudiocommrOutputConfig(IN LONG lUserId, IN TermAudiocommrOutputConfig *pAudiocommrOutputConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡ��Ƶ�Խ�����������Ϣ�����ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId					- �û�ID
 *	     Output: pAudiocommrInputConfig 	- �û���õ���Ƶ�Խ�����������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetAudiocommrInputConfig(IN LONG lUserId, OUT TermAudiocommrInputConfig *pAudiocommrInputConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ������Ƶ�Խ�����������Ϣ�����ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId					 - �û�ID
 *				 pAudiocommrInputConfig 	 - ������û����õ���Ƶ�Խ�����������Ϣ
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetAudiocommrInputConfig(IN LONG lUserId, IN TermAudiocommrInputConfig *pAudiocommrInputConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡDC������Ϣ�����ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId		- �û�ID
 *	     Output: pDecoderConfig	- �û���õ�DC������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetDecoderConfig(IN LONG lUserId, OUT TermDecoderConfig *pDecoderConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ����DC������Ϣ�����ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId		 - �û�ID
 *				 pDecoderConfig	 - ������û����õ�DC������Ϣ
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetDecoderConfig(IN LONG lUserId, IN TermDecoderConfig *pDecoderConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡEC������Ϣ�����ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId		- �û�ID
 *	     Output: pEncoderConfig	- �û���õ�EC������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetEncoderConfig(IN LONG lUserId, OUT TermEncoderConfig *pEncoderConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ����EC������Ϣ�����ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId		 - �û�ID
 *				 pEncoderConfig	 - ������û����õ�EC������Ϣ
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetEncoderConfig(IN LONG lUserId, IN TermEncoderConfig *pEncoderConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡ��˽�ڸ�������Ϣ�����ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId				- �û�ID
 *				 iChannel				- ͨ����
 *	     Output: listPrivacyMaskConfigs	- �û���õ���˽�ڸ�������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetPrivacyMaskConfig(IN LONG lUserId, IN Int32 iChannel, OUT TermPrivacyMaskConfigList &listPrivacyMaskConfigs);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ������˽�ڸ�������Ϣ�����ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId			 - �û�ID
 *				 pPrivacyMaskConfig	 - ������û����õ���˽�ڸ�������Ϣ
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetPrivacyMaskConfig(IN LONG lUserId, IN TermPrivacyMaskConfig *pPrivacyMaskConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡ�����������Ϣ�����ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId				- �û�ID
 *				 iChannel				- ͨ����
 *	     Output: pCameraConfig			- �û���õ������������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetCameraConfig(IN LONG lUserId, IN Int32 iChannel, OUT TermCameraConfig *pCameraConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ���������������Ϣ�����ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId			 - �û�ID
 *				 iChannel			 - ͨ����
 *				 pCameraConfig		 - ������û����õ������������Ϣ
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetCameraConfig(IN LONG lUserId, IN Int32 iChannel, IN TermCameraConfig *pCameraConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡIPC��ѧ����������Ϣ�����ӿ�
 *		  Calls: 
 *	  Called By:
 *	  	  Input: lUserId				- �û�ID
 *				 iChannel				- ͨ����
 *	     Output: pIpcOpticalConfig		- �û���õ�IPC��ѧ����������Ϣ
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetIpcOpticalConfig(IN LONG lUserId, IN Int32 iChannel, OUT TermIpcOpticalConfig *pIpcOpticalConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ����IPC��ѧ����������Ϣ�����ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId			 - �û�ID
 *				 iChannel			 - ͨ����
 *				 pIpcOpticalConfig	 - ������û����õ�IPC��ѧ����������Ϣ
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetIpcOpticalConfig(IN LONG lUserId, IN Int32 iChannel, IN TermIpcOpticalConfig *pIpcOpticalConfig);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ȡ�ն��豸�����ӿ� 
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId			 - �û�ID
 *	     Output: pDeviceConfig		 - �û���õ��ն��豸����
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetDeviceConfig(IN LONG lUserId, OUT TermDeviceConfig *pDeviceConfig);

//�����ն��豸�����ӿ�
TERMNETSDK_API Int32 TermNetSetDeviceConfig(IN LONG lUserId, IN TermDeviceConfig *pDeviceConfig);






/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ����DC�鲥�򵥲�ʵ���ӿں���
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId - �û�ID
 *	  	  		 pLiveStartInMonitor- ����TermNetStruct.h�й��ڽṹ��TermLivePlayParam��˵��
 *	  	 Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetLiveInMonitor(IN LONG lUserId, INOUT TermLivePlayParam *pLiveParam);

/* 
 * =========================================================================
 * 	   Function:   
 *  Description: ��������ץͼ����ӿ� 
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  �û�ID
 *				 iNum ��ʾץͼͨ����
 *	     Output:
 *	     Return:sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetJpegCaptureCmd(IN LONG lUserId, IN UCHAR iNum);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ��ѯ�������Ҫ�ָ���ʵ��
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  -�û�ID
 *				 iChannel - ��ѯ�����ʵ����ͨ����,
 *					        �����0xff��ʾ��ѯ����ͨ���ı����ʵ��
 *	  	  		 iMaxItem - ��buf�������ѯ��������
 *	  	  		 pRetItem - ʵ�ʲ�ѯ����ʵ������
 *	  	  		 listLiveRecovers - 
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSaveLiveQuery(IN LONG lUserId, IN UCHAR iChannel, IN Int32 iMaxItem, OUT  Int32 *pRetItem, OUT TermLiveRecoverList &listLiveRecovers);

/* 
 * =========================================================================
 * 	   Function: 
 *  Description: �����ն�ʱ�亯��  
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  -  �û�ID
 *				 pSysTime -  ϵͳʱ��ṹ��ָ�룬����TermNetStruct.h�й��ڽṹ��TermSysTime��˵��
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetTime(IN LONG lUserId, IN TermSysTime *pSysTime);

/* 
 * =========================================================================
 * 	   Function: 
 *  Description: ��ȡ�ն�ʱ�亯��  
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  -  �û�ID
 *	     Output: pSysTime -  ϵͳʱ��ṹ��ָ�룬����TermNetStruct.h�й��ڽṹ��TermSysTime��˵��
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetTime(IN LONG lUserId, OUT TermSysTime *pSysTime);

/* 
 * =========================================================================
 * 	   Function: 
 *  Description: ϵͳ��������ӿں���
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId -�û�ID
 *	     Output: ��
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetReboot(IN LONG lUserId);

/* 
 * * =========================================================================
 *       Function: 
 *    Description: �ն˲����ָ��������ýӿ�
 *          Calls:
 *      Called By:
 *          Input: lUserId  �û�ID
 *         Output: ��
 *         Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *        Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetFactorySet(IN LONG lUserId);

/* 
 * =========================================================================
 *     Function: 
 *  Description: �ն˻ָ�Ĭ�����ú����ӿ�
 *        Calls:
 *    Called By:
 *        Input: lUserId  �û�ID
 *       Output: ��
 *       Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetReDefaultConf(IN LONG lUserId);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ��־��������
 *		  Calls:
 *	  Called By:
 *	  	  Input:  lUserId	-�û�ID
 *				  pIP		- ��־����tftp��������ip
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
 *  Description: s2ipģʽ��͸��ͨ�������ӿ� 
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  -�û�ID
 *				 iSerialIndex - ����s2ipģʽ͸��ͨ�����ڶ˵Ĵ��ں�
 *				 pDstIp - ����s2ipģʽ͸��ͨ��ip�˵�ip
 *				 iDstPort - ����s2ipģʽ͸��ͨ��ip�˵�port
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetTransSetup(IN LONG lUserId, IN UCHAR iSerialIndex, IN CHAR *pDstIp, IN Uint16 iDstPort);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: s2ipģʽ��͸��ͨ�������ӿ� 
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId   -�û�ID
 *				 iSerialIndex - ����s2ipģʽ͸��ͨ�����ڶ˵Ĵ��ں�
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetTransClear(IN LONG lUserId, IN UCHAR iSerialIndex);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description: ���潨����͸��ͨ���������͸��ͨ����ϵͳ��������Զ��ָ� 
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  - �û�ID
 *				 iSerialIndex - ����s2ipģʽ͸��ͨ�����ڶ˵Ĵ��ں�
 *				 pDstIp - ����s2ipģʽ͸��ͨ��ip�˵�ip
 *				 iDstPort - ����s2ipģʽ͸��ͨ��ip�˵�port
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetTransSave(IN LONG lUserId, IN UCHAR iSerialIndex, IN CHAR *pDstIp, IN Uint16 iDstPort);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ɾ�������͸��ͨ��
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId  -�û�ID
 *				 iSerialIndex - ����s2ipģʽ͸��ͨ�����ڶ˵Ĵ��ں�
 *	     Output:
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetTransSaveCancel(IN LONG lUserId, IN UCHAR iSerialIndex);

/* 
 * =========================================================================
 * 	   Function:  
 *  Description:  ��ѯ�����͸��ͨ���ӿ�
 *		  Calls:
 *	  Called By:
 *	  	  Input: lUserId -�û�ID
 *				 iMaxItem - pTransParam���Բ�ѯ����͸��ͨ���������ò������������			 
 *	     Output: pTransParam - �����ѯ����͸��ͨ��
 *				 pQueryItem	 - ʵ���ϲ�ѯ����͸��ͨ���ĸ���
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetTransQuery(IN LONG lUserId, IN Int32 iMaxItem, OUT Int32 *pQueryItem, OUT TermTransSaveQuery *pTransParam);
#endif

/* 
 * =========================================================================
 *     Function:  
 *  Description: �Խ���ʼ������ƺ����ӿ�
 *        Calls:
 *    Called By:
 *        Input: lUserId -�û�ID
 *				 iStreamType - �Խ���Ƶ����Э�� 0 - udp 1 - tcp
 *				 pLocalIp - �Խ����ص�IP�����磺��192.168.0.1��
 *				 iLocalPort - �Խ�����port
 *       Output: pDstIp   -�Խ�Ŀ��IP
 *				 pDstPort -�Խ�Ŀ�Ķ˿ں�
 *       Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetAudiocomStartCmd(IN LONG lUserId, IN UCHAR iStreamType, IN CHAR *pLocalIp, IN Uint16 iLocalPort, OUT CHAR *pDstIp, OUT Uint16 *pDstPort);

/* 
 * =========================================================================
 *     Function:  
 *  Description: �Խ�����������ƺ����ӿ�
 *        Calls:
 *    Called By:
 *        Input: lUserId -�û�ID
 *				 pLocalIp - �Խ�����ip,���磺��192.168.0.1��
 *				 iLocalPort - �Խ�����port
 *       Output:
 *       Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetAudiocomStopCmd(IN LONG lUserId, IN CHAR *pLocalIp, IN Uint16 iLocalPort);

/* 
 * =========================================================================
 *     Function:  
 *  Description: �豸������Ϣ�鴦�ӿ�
 *        Calls:
 *    Called By:
 *        Input: lUserId -�û�ID
 *       Output: pDevInforParam - ��ȡ�豸��Ϣ��ָ��
 *       Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetDevInfor(IN LONG lUserId, OUT TermGetTypeInfo *pDevInforParam);

/* 
 * =========================================================================
 * 	   Function: 
 *  Description:  ͨ��ftp�����ں˾���ĺ����ӿ�  
 *		  Calls:
 *	  Called By:  
 *	  	  Input:  lUserId	   -  �û�ID
 *				  pFtpIp       -  ������õ�ftp�������ĵ�ַ
 *	  	  		  pUser        -  ����ftp���������û���
 *	  	  		  pPasswd      -  ����ftp������������
 *	  	  		  pKernelName  -  �����ں˾�������ƣ�����˴���NULL�����Ĭ���ں���������
 *	     Output:
 *	     Return:  sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:  user passwd kernel_name �ַ��������Ϊ32
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetKernelUpdate(IN LONG lUserId, IN CHAR *pFtpIp, IN CHAR *pUser, IN CHAR *pPasswd, IN CHAR *pKernelName);

/* 
 * =========================================================================
 * 	   Function: 
 *  Description:  ͨ��ftp����ramdisk����ĺ����ӿ�  
 *		  Calls:
 *	  Called By:  
 *	  	  Input:  lUserId	    -  �û�ID
 *				  pFtpIp        -  ������õ�ftp�������ĵ�ַ
 *	  	  		  pUser         -  ����ftp���������û���
 *	  	  		  pPasswd       -  ����ftp������������
 *	  	  		  pRamdiskName  -  ����ramdisk��������ƣ�����˴���NULL�����Ĭ��ramdisk��������
 *	     Output:
 *	     Return:  sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:  user passwd ramdisk_name �ַ����������Ϊ32
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetRamdiskUpdate(IN LONG lUserId, IN CHAR *pFtpIp, IN CHAR *pUser, IN CHAR *pPasswd, IN CHAR *pRamdiskName);

#if 0
/* 
 * =========================================================================
 * 	   Function: 
 *  Description:  ͨ��ftp����cpld����ĺ����ӿ�  
 *		  Calls:
 *	  Called By:  
 *	  	  Input:  lUserId	    -  �û�ID
 *				  pFtpIp        -  ������õ�ftp�������ĵ�ַ
 *	  	  		  pUser         -  ����ftp���������û���
 *	  	  		  pPasswd       -  ����ftp������������
 *	  	  		  pCpldName     -  ����cpld��������ƣ�����˴���NULL�����Ĭ��cpld��������
 *	     Output:
 *	     Return:  sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:  user passwd ramdisk_name �ַ����������Ϊ32
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetCpldUpdate(IN LONG lUserId, IN CHAR *pFtpIp, IN CHAR *pUser, IN CHAR *pPasswd, IN CHAR *pCpldName);

/* 
 * =========================================================================
 * 	   Function: 
 *  Description:  ͨ��ftp����fpga����ĺ����ӿ�  
 *		  Calls:
 *	  Called By:  
 *	  	  Input:  lUserId	    -  �û�ID
 *				  pFtpIp        -  ������õ�ftp�������ĵ�ַ
 *	  	  		  pUser         -  ����ftp���������û���
 *	  	  		  pPasswd       -  ����ftp������������
 *	  	  		  pFpgaName     -  ����fpga��������ƣ�����˴���NULL�����Ĭ��fpga��������
 *	     Output:
 *	     Return:  sdk�Ĵ����룬�ο�Sdkerror.h
 *       Others:  user passwd ramdisk_name �ַ����������Ϊ32
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetFpgaUpdate(IN LONG lUserId, IN CHAR *pFtpIp, IN CHAR *pUser, IN CHAR *pPasswd, IN CHAR *pFpgaName);

/* 
 * =========================================================================
 * 	   Function: 
 *  Description:  ͨ��ftp��������ĺ����ӿ�,����ѡ�������ľ�������  
 *		  Calls:
 *	  Called By:  
 *	  	  Input:  lUserId	     -  �û�ID 
 *				  pVersionUpdate -  ����TermImageUpdateResult�ṹ��
 *	     Output:  pResult 	     -  �ò������������������ú������سɹ�������ĸ���
 *				  				    �������д�ڴ˽ṹ����
 *	     Return:  
 *       Others:  
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetImageUpdate(IN LONG lUserId, IN TermVersionUpdate *pVersionUpdate, OUT TermImageUpdateResult *pResult);
#endif

/* 
 * =========================================================================
 * 	   Function: 
 *   Description: �ն˰汾�Ų�ѯ
 *		  Calls:
 *	  Called By:  
 *	  	  Input: lUserId	     -  �û�ID 
 *	     Output: pVersionInfo    - �ն˰汾��Ϣ�ṹ�壬�ò������������ 
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *        Others:  
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetVersionQuery(IN LONG lUserId, OUT TermVersionReport *pVersionInfo);

/* 
 * =========================================================================
 * 	   Function: 
 *   Description: ����ͨ�����������Ϣ��ѯ
 *		  Calls:
 *	  Called By:  
 *	  	  Input: lUserId				 -  �û�ID 
 *	     Output: pPhyoutChannelConfig    - ����ͨ�����������Ϣ�ṹ�壬�ò������������ 
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *        Others:  
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetPhyoutChannelConfig(IN LONG lUserId, OUT TermPhyoutChannelConfig *pPhyoutChannelConfig);

/* 
 * =========================================================================
 * 	   Function: 
 *   Description: ����ͨ�����������Ϣ����
 *		  Calls:
 *	  Called By:  
 *	  	  Input: lUserId				 -  �û�ID 
 *				 pPhyoutChannelConfig    -  �û����������ͨ�����������Ϣ
 *	     Output:  
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *        Others:  
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetPhyoutChannelConfig(IN LONG lUserId, IN TermPhyoutChannelConfig *pPhyoutChannelConfig);

/* 
 * =========================================================================
 * 	   Function: 
 *   Description: �ն�����������Ϣ��ѯ
 *		  Calls:
 *	  Called By:  
 *	  	  Input: lUserId			-  �û�ID 
 *	     Output: pEthernetConfig    -  �û���õ��ն�����������Ϣ�ṹ�� 
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *        Others:  
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetEthernetConfig(IN LONG lUserId, OUT TermEthernetConfig *pEthernetConfig);

/* 
 * =========================================================================
 * 	   Function: 
 *   Description: �ն�����������Ϣ����
 *		  Calls:
 *	  Called By:  
 *	  	  Input: lUserId			-  �û�ID 
 *				 pEthernetConfig    -  �û�������ն�����������Ϣ�ṹ��
 *	     Output:  
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *        Others:  
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetSetEthernetConfig(IN LONG lUserId, IN TermEthernetConfig *pEthernetConfig);

/* 
 * =========================================================================
 * 	   Function: 
 *   Description: ��ȡ�ն��豸������Ϣ
 *		  Calls:
 *	  Called By:  
 *	  	  Input: lUserId				-  �û�ID 
 *	     Output: pDeviceCapability      -  �û���õĻ�ȡ�ն��豸������Ϣ 
 *	     Return: sdk�Ĵ����룬�ο�Sdkerror.h
 *        Others:  
 * =========================================================================
 */
TERMNETSDK_API Int32 TermNetGetDeviceCapability(IN LONG lUserId, OUT TermDeviceCapability *pDeviceCapability);

//��ȡ�ն��豸ip������Ϣ----add by JLL at 2013.06.27
TERMNETSDK_API Int32 TermNetGetNetIpConfig(IN LONG lUserId, OUT TermNetIpConfig *pNetIpConfig);

//�����ն��豸ip������Ϣ----add by JLL at 2013.06.27
TERMNETSDK_API Int32 TermNetSetNetIpConfig(IN LONG lUserId, IN TermNetIpConfig *pNetIpConfig);
