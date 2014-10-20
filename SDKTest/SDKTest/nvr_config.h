/*
 * =====================================================================================
 *       Copyright (C), 2008, islab@ZJU
 *       文件名     :  nvr_config.h
 *       文件描述   :  File Header
 *       版本信息   :  1.0
 *       创建日期   :  2011年03月02日 17时15分09秒 CST
 *       版本记录   :  none
 *       编译器     :  
 *       作者信息   :  ojl (Islab), jinliou@es.zju.edu.cn
 *       公司机构   :  ZJU Digital ISLab.
 *       功能说明   :
 * =====================================================================================
 */
#ifndef  NVR_CONFIG_INC
#define  NVR_CONFIG_INC

#ifdef __cplusplus
extern "C"{
#endif

/* 平台配置宏 */
/* 检索条件无效值(不作为检索条件) */
#define INVALID_VALUE_NUMBER    -1
#define INVALID_VALUE_STRING    ""

/* 数据库检索时排序(升序/降序) */
#define ASC_ORDER 				(0)
#define DSC_ORDER 				(1)

/*************************************************************/
/*                  终端设备能力                             */
/*************************************************************/
/* 单个编码器支持的最大摄像机数量 */
#define TERM_MAX_CHANNEL_NUM (16)
/* 单个设备温度告警源数量 */
#define TERM_MAX_TEMP_NUM   (1)

/* 单个DSP上通道数量 */
#define CHANNEL_NUM_PER_DSP (4)
#define TERM_EC_MAX_DO_NUM     (16)
#define TERM_EC_MAX_DI_NUM     (16)
#define TERM_EC_MAX_SERIAL_NUM (8)
#define TERM_EC_PRIVACY_MASK_NUM (4)

#define TERM_DC_AUDIO_OUT_NUM (4)
#define TERM_DC_MAX_DO_NUM     (16)
#define TERM_DC_MAX_DI_NUM     (16)
#define TERM_DC_MAX_SERIAL_NUM (8)
#define TERM_DEV_ENV_MAX_NUM (64)

#define RID_NUMBER_CNT_SHIFT (5)

/* 主辅流标志偏移 */
#define MAIN_SUB_FLAG_SHIFT RID_NUMBER_CNT_SHIFT

/* 单个摄像机所支持的Motion区域最大数量 */
#define MAX_MOTION_AREA_PER_CHANNEL    (4)
#define MOTION_AREA_INDX_SHIFT RID_NUMBER_CNT_SHIFT

/* 单个摄像机所支持的VL告警最大数量 */
#define MAX_VL_NUM_PER_CHANNEL  (1)

#define MAX_AREA_MASK			(1024)

#define MAX_OSD_VALUE			(64)

/* 单个摄像机运行的OSD场名数量 add by ojl @ 2011-08-29 */
#define MAX_OSD_FIELD_PER_CHANNEL (4)

/* 单个摄像机支持的巡航路径数量 */
#define MAX_CRUISE_PATH_PER_CHANNEL (16)
#define CRUISE_PATH_INDX_SHIFT RID_NUMBER_CNT_SHIFT

#define MAX_NAME_LEN32			(STRING_LEN_32)
/* D018再合入字符串长度修改 */
#define MAX_NAME_LEN64			(STRING_LEN_32)
//#define MAX_NAME_LEN64			(STRING_LEN_64)
#define MAX_LIST_LEN			(32)
#define MAX_DESC_LEN			(64)

/* 为4窗格监视器名称预留[x]+'\0',并凑偶数 */
#define CLIENT_MAX_NAME_LEN		(MAX_NAME_LEN64 - 4)

/* 设备序列号长度 */
#define DEVICE_SN_LEN   (64)

/* verdor name "ntech" or "other" */
#define VENDOR_NAME_LEN  (6)
#define VENDOR_NAME_LOCAL  "ntech"
#define VENDOR_NAME_H3C  "H3C"
#define VENDOR_NAME_ONU  "ONU"
#define VENDOR_NAME_OTHER  "other"

/* IP地址长度(兼容IPV6) */
#define IPADDR_LEN (16)
#define MACDDR_LEN (16)

/* IPSAN用户名和密码长度 */
#define IPSAN_USER_LEN    (32)
#define IPSAN_PASSWD_LEN  (32)

#define FTP_PATH_LEN (64)

/* 字符串表示的版本号最大长度 */
#define VERSION_STR_LEN (32)

#define VDISK_NAME_LEN (32)

/* 能够同一IPSAN的最大VOD数量 */
#define MAX_VOD_PER_IPSAN (16)

#define MAX_IQN_LEN	(128)

#define ROLE_TYPE_LEN (32)

#define TASK_PARAM_LEN (256)

#define RESOURCE_ORG_PATH (64)
#define SHARE_DOMAIN_LIST (32)

/* (MSG,摄像机组,监视器组,电视墙)组中元素最大数量 */
#define MAX_GROUP_ELEMENT_NUM (256)

/* 密码为MD5加密后密码(128bit) */
//#define PASSWD_LEN (16)
/* 最后填充'\0' */
#define PASSWD_LEN (32)
//#define PASSWD_LEN ( 128 )
#define EMAIL_LEN 32
#define PHONE_NO_LEN 20

#define ISCSI_DEFAULT_PORT (3260)

#define IN 
#define OUT
#define INOUT

/* 修改例外、联动动作最大数量时需与终端同步修改 */
/* 联动例外最大数量 */
#define MAX_ALARM_EXC_NUM (16)

/* 联动动作最大数量(所有联动动作) */
#define MAX_ALARM_ACTION_NUM (128)

/* 终端联动自身的动作最大数量 */
#define MAX_TERM_ALARM_ACTION_NUM (16)

/* 循环尝试最大次数 */
#define MAX_TRY_COUNT (5)

/* 终端参数最大group数量 */
#ifndef MINE_PRODUCT
#define MAX_TERM_PARAM_GROUP_CNT (1024)
#else
#define MAX_TERM_PARAM_GROUP_CNT (1024 * 2)
#endif

/* 点播URL最大长度 */
#define MAX_RTSP_URL_LEN (256)

/* IPSAN数据端口名称最大长度 */
#define PORT_NAME_LEN 4

/* IPSAN的数据端口最大数量 */
#define MAX_PORT_NUM  8

/* 支持的最大网卡数量 */
#define MAX_NET_IFC_NUM 8
/* 系统中CPU最大数量 */
#define MAX_CPU_COUNT 32
/* 系统中最大磁盘数量 */
#define MAX_DISK_COUNT 1024

/* license长度 */
#define MAX_LICENSE_KEY_LEN 32

/* 系统中使用的文件史最大长度 */
#define MAX_FILE_PATH_LEN 128

/*权限类型*/
typedef enum __ENUM_PRIVILEGE_TYPE__{
    PRIV_LIVE = 0x01,		/*实况*/
    PRIV_PLAYBACK = 0x02,	/*回放*/
    PRIV_MAP = 0x04,		/*地图*/
    PRIV_ALARM = 0x08,		/*告警*/
    PRIV_CONFIG = 0x10,		/*配置*/
    PRIV_MANAGE = 0x20,		/*业务管理*/
    PRIV_MAINTAIN = 0x40 	/*系统维护*/
}enum_priv_type;

typedef enum __addr_type{    
    IPADDR_TYPE_IPV4,    
    IPADDR_TYPE_IPV6
}enum_ipaddr_type;

typedef enum __patrol_type__{
    PATROL_TYPE_MONITOR,	/* 摄像机组<-->监视器 */
    PATROL_TYPE_MONITORG,	/* 摄像机组<-->监视器组 */
    PATROL_TYPE_TVWALL,		/* 摄像机组<-->电视墙 */
    PATROL_TYPE_END
}patrol_type;

typedef enum
{
    Ret_OK = 0,						//成功
    Ret_ERROR_UNKNOWN = -1,			//未知错误
    Ret_ERROR_BADPARAM = -2,		//非法参数
    Ret_ERROR_NULLPTR= -3,			//空指针
    Ret_ERROR_OUTOFRANGE = -4,		//超出范围限制
    Ret_ERROR_INVALID_HANDLE = -5,	//非法句柄
    Ret_ERROR_NORESOURCES = -6,		//没有资源
    Ret_ERROR_OFFLINE = -7,			//设备或资源不在线
    Ret_ERROR_VERSION_MISMATCH = -8,//设备只响应升级命令
    Ret_ERROR_NO_PRIVI = -9,		//没有操作权限
    Ret_ERROR_NONEXIST = -10,		//操作对象不存在
    Ret_ERROR_EXIST = -11,			//操作对象已经存在
    Ret_ERROR_MULTI_ENTRY = -12,	//存在多个操作对象
    Ret_ERROR_OVERFLOW = -13,       //缓冲区溢出
    Ret_ERROR_CAMERA_WITHOUT_PTZ = -14,//非云台摄像机
    Ret_END
}ret_status;

/* IPSAN中卷类型 */
enum __volume_type_
{
    VOLUME_TYPE_DATA,
    VOLUME_TYPE_BACKUP,
    VOLUME_TYPE_END
};

//typedef ret_status succeed_type;
#define succeed_type ret_status
#define succeed_type_succeed Ret_OK
#define succeed_type_failed Ret_ERROR_UNKNOWN

#if 0
typedef enum __succeed_type
{
    succeed_type_failed = -1,
    succeed_type_succeed = 0
}succeed_type;
#endif

/* 超级用户ID */
enum __super_user_id__
{
    SUPER_USERID_ADMIN = 0xFFFFFFFE,     /* admin(对应role_id:0x7FFFFFFE) */
    SUPER_USERID_ALARM = 0xFFFFFFFD,     /* 告警使用的user_id(role_id:0x7FFFFFFD) */
    SUPER_USERID_DOMAIN = 0xFFFFFFFC,    /* 域间通信使用的user_id */
    SUPER_USERID_PLAN = 0xFFFFFFFB,      /* 计划使用的user_id */
    SUPER_USERID_END
};

/* 超级用户角色ID */
enum __super_role_id__
{
    SUPER_ROLEID_ADMIN = 0x7FFFFFFE,     /* admin(对应role_id:0x7FFFFFFE) */
    SUPER_ROLEID_ALARM = 0x7FFFFFFD,     /* 告警使用的user_id(role_id:0x7FFFFFFD) */
    SUPER_ROLEID_DOMAIN = 0x7FFFFFFC,    /* 域间通信使用的user_id */
    SUPER_ROLEID_PLAN = 0x7FFFFFFB,      /* 计划使用的user_id */
    SUPER_ROLEID_END
};

/* 超级用户优先级 */
enum __super_user_priority__
{
    SUPER_PRIORITY_ADMIN = 64,      /* admin */
    SUPER_PRIORITY_ALARM = 65,      /* 告警 */
    SUPER_PRIORITY_DOMAIN = 32,             /* 域间通信 */
    SUPER_PRIORITY_PLAN = 1,                /* 计划 */
    SUPER_PRIORITY_END
};

/* 超级用户拥有所有权限 */
#define SUPER_PRIVILEGE 0xFFFFFFF

/* MSG自适应的ID */
#define MSG_AUTO_ID (-1)

/* 配置文件定义 */
#ifdef PLATFORM_NVR
#define VMS_CONF_FILE "/tmp/config/inuse/nvr_capability_config"
#else
#define VMS_CONF_FILE "vms_config"
#endif
#define VMS_DOMAIN_ID "domain_id"

/* 预留的域ID */
#define VMS_DOMAIN_RESERVED1 0
#define VMS_DOMAIN_RESERVED2 65535

#define STRING_LEN_16 16
#define STRING_LEN_32 32
#define STRING_LEN_64 64
#define STRING_LEN_128 128

#ifdef __cplusplus
}
#endif
#endif   /* ----- #ifndef NVR_CONFIG_INC  ----- */


