/*
 * =====================================================================================
 *       Copyright (C), 2010, islab@ZJU
 *
 *       FileName:  types.h
 *
 *		   Author:  liuqw (Islab)
 *			 Date:	2013年03月04日 11时19分56秒 CST
 *        Version:  1.0.1
 *
 *    Description:  终端系统的基本类型定义
 *		   Others:
 *  Function List:
 *			1.-------
 *        History: 
 *			hucm  2013.03.04  Use for TermSDK
 *
 * =====================================================================================
 */

#ifndef  TYPES_INC
#define  TYPES_INC

#ifdef __cplusplus
extern "C"{
#endif

#include <stdlib.h>

/* 判断大小端 */
#ifdef PLATFORM_NVR
#define BIG_ENDIAN_CPU
#else
#undef BIG_ENDIAN_CPU
#endif

#ifndef TRUE
#define FALSE 0
#define TRUE  1
#endif

#define false 0
#define true  1

//typedef unsigned char           BOOL;
typedef int						BOOL;

typedef unsigned char           UCHAR;
typedef char             		CHAR;
typedef signed char             SCHAR;

typedef unsigned short          USHORT;
typedef short              	SHORT;
typedef signed short              SSHORT;

typedef unsigned int            UINT;
typedef int              		INT;
typedef signed int              SINT;

typedef unsigned long           ULONG;
typedef long             		LONG;
typedef signed long             SLONG;

typedef unsigned long long      ULONGLONG;
typedef long long        		LONGLONG;
typedef signed long long        SLONGLONG;

typedef unsigned char           Uint8;
typedef char             		Int8;
typedef signed char             Sint8;

typedef unsigned short          Uint16;
typedef short            		Int16;
typedef signed short            Sint16;

typedef unsigned int            Uint32;
typedef int              		Int32;
typedef signed int              Sint32;

#ifdef IS_64BIT_OS
typedef unsigned long           Uint64;
typedef long             		Int64;
typedef signed long             Sint64;

#else
typedef unsigned long long      Uint64;
typedef long long        		Int64;
#endif
typedef float	                FLOAT;
typedef double                  DOUBLE;


/* 仅终端使用 */
typedef Uint8  BBitmap8_t;

/* 单个摄像机所支持的VL告警最大数量 */
#define MAX_AREA_MASK			(1024)

#define MAX_OSD_VALUE			(64)

#define STRING_LEN_32			(32)

#define MAX_NAME_LEN32			(STRING_LEN_32)
/* D018再合入字符串长度修改 */
#define MAX_NAME_LEN64			(STRING_LEN_32)
//#define MAX_NAME_LEN64			(STRING_LEN_64)

#define MAX_DESC_LEN			(64)

/* IP地址长度(兼容IPV6) */
#define IPADDR_LEN (16)

/* 密码为MD5加密后密码(128bit) */
//#define PASSWD_LEN (16)
/* 最后填充'\0' */
#define PASSWD_LEN (32)

#define IN 
#define OUT
#define INOUT

#ifdef __cplusplus
}
#endif
#endif   /* ----- #ifndef TYPES_INC  ----- */

