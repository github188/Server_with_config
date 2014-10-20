#ifndef _SDK_ERROR_H_
#define _SDK_ERROR_H_

#include "term_error_define.h"
#define SDK_ERROR_MASK		(0x02)
/* Common Error Codes 0..65535 */
//最高位为1的错误号产生自SDK，其余错误号第一个字节标识来自nvr的不同模块
typedef enum tagSdkErrCode
{
	SDK_ERROR_SUC					= 0x8000, 	/* success*/
	SDK_ERROR_UNKNOWN 				= 0x8001, 	/* There was an error, but we don't know specifics */
	SDK_ERROR_OUTOFRESOURCES 		= 0x8002, 	/* no resource left for this operation */
	SDK_ERROR_BADPARAM 				= 0x8003, 	/* parameter value invalid */
	SDK_ERROR_NULLPTR 				= 0x8004, 	/* required pointer parameter was a NULL pointer */
	SDK_ERROR_OUTOFRANGE 			= 0x8005,   /* parameter out of range */
	SDK_ERROR_DESTRUCTED 			= 0x8006,  	/* operation attempted on a destructed object */
	SDK_ERROR_NOTSUPPORTED 			= 0x8007,  	/* request not supported under current configuration */
	SDK_ERROR_UNINITIALIZED 		= 0x8008,  	/* object uninitialized */
	SDK_ERROR_TRY_AGAIN 			= 0x8009,	/* incomplete operation, used by semaphore's try lock */
	SDK_ERROR_ILLEGAL_ACTION 		= 0x800A, 	/* the requested action is illegal */
	SDK_ERROR_NETWORK_PROBLEM 		= 0x800B, 	/* action failed due to network problems */
	SDK_ERROR_INVALID_HANDLE 		= 0x800C, 	/* a handle passed to a function is illegal */
	SDK_ERROR_NOT_FOUND 			= 0x800D, 	/* the requested item cannot be found */
	SDK_ERROR_INSUFFICIENT_BUFFER 	= 0x800E, 	/* the buffer is too small */
	SDK_ERROR_SOCKETINIT			= 0x800F,	/* error socket init*/
	SDK_ERROR_SOCKETCREATE			= 0x8010,	/* error socket create */
	SDK_ERROR_SOCKETINUSE			= 0x8011,	/* bind socket already in use */
	SDK_ERROR_SOCKETBIND			= 0x8012,	/* error socket bind */
	SDK_ERROR_SETBUFFER				= 0x8013,	/* error set socket buffer */
	SDK_ERROR_SETLINGER				= 0x8014,	/* error set socket linger */
	SDK_ERROR_REUSEADDR				= 0x8015,	/* error reuse socket address */
	SDK_ERROR_SETBLOCK				= 0x8016,	/* error set socket block status */
	SDK_ERROR_SOCKETCONNECT			= 0x8017,	/* error set socket connect */
	SDK_ERROR_SOCKETACCEPT			= 0x8018,	/* error socket accept */
	SDK_ERROR_SOCKETLISTEN			= 0x8019,	/* error socket listen */
	SDK_ERROR_SOCKSHUTDOWN			= 0x801A,	/* error socket shutdown */
	SDK_ERROR_SOCKWRITE				= 0x801B,	/* error socket write */
	SDK_ERROR_SOCKREAD				= 0x801C,	/* error socket read */
	SDK_ERROR_SOCKSETSENDO			= 0x801D,	/* error set socket send time out*/
	SDK_ERROR_SOCKSETRECVO			= 0x801E,	/* error set socket recv time out*/

	SDK_ERROR_CREATETHREAD			= 0x801F,	/* error on create a posix thread */
	SDK_ERROR_POSIXSEM				= 0x8020,	/* error on operation on a posix sem*/
	SDK_ERROR_MSGCONTENT			= 0x8021,	/* wrong message formate or 
connent*/
	SDK_ERROR_STATEMACHINE			= 0x8022,	/* sdk in wrong state */
	SDK_ERROR_MSGTIMEOUT			= 0x8023,	/* msg request not get reply in time */
	SDK_ERROR_MSGSEQNOTFOUND		= 0x8024,	/* can not find msg reply in msg context list */
	SDK_ERROR_MSGCATFAILED			= 0x8025,	/* catnecate msg together failed*/
	
	SDK_ERROR_LOGIN					= 0x8026,	/* user login failed */
	SDK_ERROR_LOGOOUT				= 0x8027,	/* user logout failed */
	SDK_ERROR_UPLOADFAILED			= 0x8028,	/* upload file failed */
	SDK_ERROR_DOWNLOADFAILED		= 0x8029,	/* download file failed */

	SDK_ERROR_END,
}SdkErrCode;

#endif //_SDK_ERROR_H_

