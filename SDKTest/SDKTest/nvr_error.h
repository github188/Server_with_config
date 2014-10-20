/*
 * =====================================================================================
 *       Copyright (C), 2008, islab@ZJU
 *       文件名     :  nvr_error.h
 *       文件描述   :  File Header
 *       版本信息   :  1.0
 *       创建日期   :  2010年11月09日 10时57分28秒 CST
 *       版本记录   :  none
 *       编译器     :  
 *       作者信息   :  ojl (Islab), jinliou@es.zju.edu.cn
 *       公司机构   :  ZJU Digital ISLab.
 *       功能说明   :
 * =====================================================================================
 */
#ifndef  NVR_ERROR_INC
#define  NVR_ERROR_INC

#ifdef __cplusplus
extern "C"{
#endif

typedef unsigned short error_type;

/* 平台错误码定义 */
#define NVR_ERROR_MASK 0x01

/* 0x0000~0x0FFF预留给终端 */

enum __nvr_error_code_
{
	NVR_ERROR_MSG_TIMEOUT = 0x1001,		/* 消息超时 */
	NVR_ERROR_DB_READ_ERROR,			/* 数据库读取错误 */
	NVR_ERROR_DB_WRITE_ERROR,			/* 数据库写入错误 */
	NVR_ERROR_DB_ERROR,					/* 数据库操作错误 */
	NVR_ERROR_INTERNAL_ERROR,			/* 系统内部错误,如内存分配失败,队列插入失败等 */
	NVR_ERROR_INVALID_PARAM,			/* 无效参数 */
	NVR_ERROR_VMS_UNSUPPORT,            /* 不支持该操作 */
	NVR_ERROR_VMS_END,

	NVR_ERROR_TC_MSG_TIMEOUT = 0x1101,	/* 消息超时 */
	NVR_ERROR_CLIENT_VERSION_MISMATCH,	/* Client版本不匹配, 请更新Client */
	NVR_ERROR_USER_NOEXIST,				/* 用户不存在 */
	NVR_ERROR_PASSWD_ERROR,				/* 用户密码错误 */
	NVR_ERROR_USER_LOCKED,				/* 用户已锁定 */

	NVR_ERROR_USER_UNLOGIN,				/* 用户未登录 */
	NVR_ERROR_USER_LOGIN,				/* 用户已登录(不允许多点登录用户) */
	NVR_ERROR_NO_PERMIT,				/* 无操作权限 */
	NVR_ERROR_RES_NONEXIST,				/* 资源不存在 */
	NVR_ERROR_ORG_NOEXIST,				/* 组织不存在 */

	NVR_ERROR_ROLE_NOEXIST,				/* 角色不存在 */
	NVR_ERROR_XML_RD_ERROR,				/* XML读取错误 */
	NVR_ERROR_XML_WR_ERROR,				/* XML写入错误 */
	NVR_ERROR_NAME_EXIST,				/* 名称已存在(用户/角色/组织等) */
	NVR_ERROR_TRANS_INUSE,				/* 透明通道的某个串口已使用 */

	NVR_ERROR_PTZ_INUSE,				/* PTZ正在使用中 */
	NVR_ERROR_CAMERA_WITHOUT_PTZ,		/* 非PTZ摄像机 */
	NVR_ERROR_DEVICE_NOEXIST,			/* 设备不存在 */
	NVR_ERROR_KERNEL_VERSION,			/* 终端内核版本不匹配 */
	NVR_ERROR_RAMDISK_VERSION,			/* 终端应用程序版本不匹配 */

	NVR_ERROR_REGISTER_AGAIN,			/* 终端重复注册(仍在线时收到注册命令) */
	NVR_ERROR_DEV_VERSION_MISMATCH,		/* 终端版本不匹配(上一次升级未成功,只响应升级命令) */
	NVR_ERROR_DEVICE_EXIST,				/* 设备已经存在 */
	NVR_ERROR_DEVICE_NONEXIST,			/* 设备不存在 */
	NVR_ERROR_DEVICE_OFFLINE,			/* 设备不在线 */

	NVR_ERROR_CAMERA_OFFLINE,			/* 摄像机不在线 */
	NVR_ERROR_CAMERA_NONEXIST,			/* 摄像机不存在 */
	NVR_ERROR_CAMERAG_NONEXIST,			/* 摄像机组不存在 */
	NVR_ERROR_MONITOR_NONEXIST,			/* 监视器不存在 */
	NVR_ERROR_MONITORG_NONEXIST,		/* 监视器组不存在 */

	NVR_ERROR_TVWALL_NONEXIST,			/* 电视墙不存在 */
    NVR_ERROR_IPSAN_NONEXIST,           /* IPSAN不存在 */
    NVR_ERROR_IPSAN_WITHOUT_DM,         /* IPSAN未指定管理的CM或CM不在线 */
    NVR_ERROR_IPSAN_WITHOUT_VOD,        /* IPSAN未指定点播的VOD或VOD不在线 */
    NVR_ERROR_IPSAN_VOL_NONEXIST,       /* IPSAN中的卷不存在 */

    NVR_ERROR_TRANS_NONEXIST,           /* 透明通道已不存在 */
    NVR_ERROR_EVENT_CONFIRMED,          /* 告警事件已确认 */
	NVR_ERROR_IPSAN_IN_USE,				/* IPSAN中仍有卷资源 */
    NVR_ERROR_DEVICE_WITH_VOLUME,       /* 设备仍有卷资源 */
    NVR_ERROR_ROLE_IN_USE,              /* 角色已与用户绑定 */

	NVR_ERROR_NO_PERMIT_ON_DOMAIN,		/* 无权操作外域设备或组织 */
    NVR_ERROR_CM_WITH_IPSAN,            /* 存在IPSAN托管于该CM,请先删除其托管关系 */
    NVR_ERROR_VOD_WITH_IPSAN,           /* 存在IPSAN托管于该VOD,请先删除其托管关系 */
    NVR_ERROR_RES_EXIST,				/* 资源已经存在 */
    NVR_ERROR_INVALID_ORG,              /* 无效组织(不允许在根组织和外域组织下添加设备) */

    NVR_ERROR_RES_IS_SHARED,			/* 该设备有共享资源 */
    NVR_ERROR_RES_IS_ATTACHED,			/* 该设备有划归资源 */
    NVR_ERROR_CAMERA_IN_CAMERAG,        /* 摄像机仍在摄像机组中 */
    NVR_ERROR_MONITOR_IN_MONITORG,      /* 监视器组仍在监视器组中 */
    NVR_ERROR_CAMERAG_IN_RES,           /* 摄像机组仍在轮切资源中 */

    NVR_ERROR_CAMERAG_IN_PATROL,        /* 摄像机组仍正在轮切中 */
    NVR_ERROR_MONITORG_IN_RES,          /* 监视器组仍在轮切资源中 */
    NVR_ERROR_MONITORG_IN_PATROL,       /* 监视器组仍正在轮切中 */
    NVR_ERROR_TVWALL_IN_RES,            /* 电视墙在仍轮切资源中 */
    NVR_ERROR_TVWALL_IN_PATROL,         /* 电视墙正仍在轮切中 */

    NVR_ERROR_GET_VOD_URL,              /* 获取点播URL失败 */
	NVR_ERROR_WITH_SHARE_RES,			/* 外域仍有共享资源 */
	NVR_ERROR_LOGIN_FAILE_LOCKED,		/* 用户连续登录失败已被锁定 */
	NVR_ERROR_MS_IN_MSG,				/* MS仍在MSG中 */
	NVR_ERROR_LICENSE_FAILED,			/* license验证失败 */

	NVR_ERROR_INVALID_LICENSE_KEY,		/* 序列号不可用 */
	NVR_ERROR_INVALID_LICENSE_FILE,		/* license文件错误 */
	NVR_ERROR_LICENSE_NONEXIST,			/* license文件未找到 */
	NVR_ERROR_LICENSE_KEY_EXIST,		/* 序列号已存在 */
	NVR_ERROR_INVALID_LICENSE,			/* license不可用 */

	NVR_ERROR_SPEC_OVERFLOW,			/* 已超过所支持的最大数量 */
	NVR_ERROR_TRANS_CH_NONEXIST,		/* 透明通道不存在 */
	NVR_ERROR_CM_IN_IMS,				/* CM属于IMS,不能删除 */
	NVR_ERROR_VOD_IN_IMS,				/* VOD属于IMS,不能删除 */
	NVR_ERROR_RES_WITH_MEDIA_RELATION,	/* 摄像机或监视器有监控关系,请先停止实况 */

	NVR_ERROR_MONITOR_IN_PATROL,        /* 监视器正在轮切中 */
	NVR_ERROR_DOMAIN_NONEXIST,			/* 外域不存在 */
	NVR_ERROR_CAMERAG_CAMERA_RESOLUTION, /* 摄像机组中摄像机分辨率不匹配 */
	NVR_ERROR_MONITORG_MONITOR_RESOLUTION, /* 监视器组中监视器分辨率不匹配 */
	NVR_ERROR_MONITORG_MONITOR_IN_PATROL,/* 监视器组或电视墙中监视器正在轮切中 */

	NVR_ERROR_MCADDR_USED,				/* 组播地址和端口已分配 */
	NVR_ERROR_VOLUME_USED,				/* 卷已分配,请从存储配置中删除该卷 */
	NVR_ERROR_TVWALL_MONITOR_RESOLUTION,/* 电视墙中监视器分辨率不匹配 */
	NVR_ERROR_DEL_INVALID_ORG,              /* 不能删除根组织或本域组织或外域组织  */
	NVR_ERROR_ORG_HAS_RES,                  /* 该组织下仍有资源  */

	NVR_ERROR_DEL_SELF_RES,                  /* 不能删除自带设备*/
	NVR_ERROR_SET_SELF_RES,                  /* 不能设置自带设备*/
	NVR_ERROR_OPERATE_AUTO_MSG,                  /* 不能操作自适应msg */
	NVR_ERROR_NO_PERMIT_PRIORITY,       /* 无操作权限，用户优先级比配置角色优先级低  */

	NVR_ERROR_NO_PERMIT_PRIVILEGE,      /* 无操作权限，配置角色权限不在用户权限子集中  */
	NVR_ERROR_PHYOUT_CHANGE_CAUSE_ATTACH,      /* 监视器存在划归资源，不允许修改物理输出模式 */
	NVR_ERROR_ATTACH_RES_EXIST_IN_ORG,      /* 组织中已存在该资源的划归资源  */
	NVR_ERROR_AL_CLIENT_RS_MULTI_USER,      /* 不联动允许多点登录的用户 */
	NVR_ERROR_IPSAN_IN_IMS,				/* IPSAN属于IMS，不能删除*/

    NVR_ERROR_MONITOR_IN_TV_WALL,       /* 监视器组仍在电视墙中*/

	NVR_ERROR_EMAP_EXIST_SUB_MAP,         /* 不能删除子地图不为空的电子地图  */ 
	NVR_ERROR_EMAP_NOEXIST,            /* 电子地图不存在 */ 

	                                     /* 0x1156  */
	NVR_ERROR_EMAP_RES_NOEXIST,         /* 电子地图资源不存在  */
	NVR_ERROR_DEVICE_HAS_NO_CAMERA,         /* 该设备无摄像机资源  */
	NVR_ERROR_LICENSE_REG_FAIL,         /* 无效的License */
	NVR_ERROR_LICENSE_REG_AGAIN,        /* License已经激活 */
	NVR_ERROR_TC_END,

	/* 实况相关错误号 0x02XX */
	NVR_ERROR_MN_DC_PREEMPT_ILLEGAL = 0x1201,	/* DC抢占失败，抢占非法 */
	NVR_ERROR_MN_DC_PREEMPT_PRIORITY_LOW = 0x1202,	/* DC抢占失败，权限不足 */
	NVR_ERROR_MN_EC_PREEMPT_FAILED,			/* EC抢占失败 */
	NVR_ERROR_MN_DC_MSG_TIMEOUT,			/* DC侧超时 */
	NVR_ERROR_MN_DEV2_MSG_TIMEOUT,			/* 音频DEV2侧超时 */

	NVR_ERROR_MN_MS_MSG_TIMEOUT,			/* MS超时 */
	NVR_ERROR_MN_EC_MSG_TIMEOUT,			/* EC侧超时 */
	NVR_ERROR_MN_DEV1_MSG_TIMEOUT,			/* 音频DEV1侧超时 */
	NVR_ERROR_MN_NOTIFY_DELIVER_MSG_TIMEOUT,	/* 通知引流超时 */
	NVR_ERROR_MN_NO_PROPER_LINK_MODE,		/* 无合适链路模式 */

	NVR_ERROR_MN_RES_ID_ILLEGAL,			/* 非法资源ID */
	NVR_ERROR_MN_RS_FORCE_END_ILLEGAL,		/* 不可强制停止，请走正常停止 */
	NVR_ERROR_MN_UNKOWN_ERROR,			/* MN未知错误 */
	NVR_ERROR_MN_PATTERN_NOT_MATCH,		/* 制式不匹配 */
	NVR_ERROR_MN_RESOLUTION_NOT_MATCH,		/* 分辨率不匹配 */

	NVR_ERROR_MN_STREAMING_TYPE_NOT_MATCH,		/* 码流类型不匹配 */
	NVR_ERROR_MN_USER_END_ILLEGAL,          /* 上级域实况请从上级域停止 */
	NVR_ERROR_MN_USER_END_PRIORITY_LOW,     /* 用户优先级较低，停止失败 */
	NVR_ERROR_MN_SESSION_IN_PREEMPTED,	/* 本连接已在抢占中，不可重复抢占 */
	NVR_ERROR_MN_SESSION_IN_NEGO,		/* 本连接正在协商中，不可抢占 */

	NVR_ERROR_MN_DEV_ALREADY_AUDIO, /* 设备已在对讲中，协商失败 */
	NVR_ERROR_MN_AUDIO_DEV_SAME,    /* 对讲设备为相同设备，不可对讲 */

	NVR_ERROR_MN_END,

	NVR_ERROR_MD_START_FAILED = 0x1401,          /* MD开始实况内部错误 */
	NVR_ERROR_MD_END_FAILED,           /* MD停止实况内部错误 */
	NVR_ERROR_MD_SESSION_ID_REPEAT,	    /* MD接收到重复的session_id */
	NVR_ERROR_MD_SESSION_POS_FULL,	    /* MD的session静态链表已满 */
	NVR_ERROR_MD_SESSION_ID_NOT_FOUND,  /* MD未找到相应的转发session */

	NVR_ERROR_MD_PORT_ILLEGAL,          /* MD接收到非法的端口 */ 
	NVR_ERROR_MD_DELIVER_FAILED,        /* MD引流失败 */
	NVR_ERROR_MD_SRC_ADDR_ILLEGAL, /*MD接收地址空间非法*/
	NVR_ERROR_MD_SRC_ADDR_UNUSED,     /*MD查找到的对应MC端口的src_addr未使用*/
	NVR_ERROR_MD_SRC_ADDR_SPACE_FULL , /*MD接收地址空间已满*/

	NVR_ERROR_MD_DST_ADDR_ILLEGAL, /*MD发送地址非法*/
	NVR_ERROR_MD_THREAD_OR_SRC_ADDR_POS_ILLEGAL, /*MD查找到的线程位置或者src_addr位置非法*/
	NVR_ERROR_MD_SEND_PORT_FULL, /*MD发送端口已满*/
	NVR_ERROR_MD_RECV_PORT_FULL, /*MD接收端口已满*/
	NVR_ERROR_MD_RECV_PORT_ILLEGAL , /*MD接收端口非法*/

	NVR_ERROR_MD_SEND_PORT_ILLEGAL , /*MD发送端口非法*/
	NVR_ERROR_MD_CREATE_SEND_SOCKET_FAILED , /*MD创建发送socket失败*/
	NVR_ERROR_MD_DST_ADDR_SPACE_FULL, /*MD转发目的地址空间已满*/
	NVR_ERROR_MD_ALL_THREAD_FULL, /*MD转发线程已满*/
	NVR_ERROR_MD_MULTICAST_RECV_PORT_USED, /*MD组播接收端口已被使用*/

	NVR_ERROR_MD_MC_PORT_POS_FULL, /*MD无未使用的MC端口位置*/
	NVR_ERROR_MD_CREATE_RECV_SOCKET_FAILED, /*MD创建接收socket失败*/
	NVR_ERROR_MD_IP_ADD_MEMBERSHIP_FAILED, /*MD加入组播组失败*/
	NVR_ERROR_MD_RECV_PORT_UNUSED, /*MD接收到的端口未使用*/
	NVR_ERROR_MD_SEND_PORT_UNUSED, /*MD接收到的发送端口未使用*/

	NVR_ERROR_MD_SEND_PORT_POS_FULL, /*MD发送端口位置已满*/
	NVR_ERROR_MD_RECV_PORT_POS_FULL , /*MD接收端口位置已满*/
	NVR_ERROR_MD_SESSION_EXIST, /*链路存在，单独关闭接收端口失败*/

	NVR_ERROR_MD_END,

	NVR_ERROR_DM_FIND_CAMERA = 0x1601,	/* 哈希表中未找到对应关系节点 */
	NVR_ERROR_DM_ISCSI_LOGOFF,			/* iSCSI未登录 */
	NVR_ERROR_DM_INIT_AVHELPER,			/* avhelper句柄初始化失败 */
	NVR_ERROR_DM_OPEN_VOLUME,			/* 卷打开失败 */
	NVR_ERROR_DM_QUERY_RECORD,			/* 录像检索失败 */

	NVR_ERROR_DM_ISCSI_BLOCKED,			/* ISCSI断线 */
	NVR_ERROR_DM_ALLOC_VOLUME,			/* 格式化卷失败 */
	NVR_ERROR_DM_RECYCLE_VOLUME,		/* 回收卷失败 */
	NVR_ERROR_DM_SYNC_EVENT,			/* 事件同步，即查找camera的最新和最老时间失败 */
	NVR_ERROR_DM_GET_PORTS,				/* 获取IPSAN数据端口失败 */

	NVR_ERROR_DM_FIND_IPSAN,			/* 哈希表中未找到设备节点 */
	NVR_ERROR_DM_TELNET_LOGOFF,			/* telnet未登录 */
	NVR_ERROR_DM_WRONG_XMLFILE,			/* telnet获取到的xml文档为空文档或不完整 */
	NVR_ERROR_DM_CMD_EXEC_ERR,			/* IPSAN管理命令执行错误 */
	NVR_ERROR_DM_PORT_NONEXIST,			/* 指定的端口不存在 */

	NVR_ERROR_DM_NVR_UNIX_ERROR,		/* 操作NVR SAN时UNIX通讯错误 */
	NVR_ERROR_DM_NVR_SICK_MSG,			/* 收到的信息部分丢失 */
	NVR_ERROR_DM_NVR_NO_SPEC_DISK,		/* NVR中没有指定的磁盘 */
	NVR_ERROR_DM_NVR_NO_SPEC_VDISK,		/* NVR中没有指定的vdisk */
	NVR_ERROR_DM_NVR_NO_SPEC_VOLUME,	/* NVR中没有指定的卷 */

	NVR_ERROR_DM_NVR_NO_SPEC_TARGET,	/* NVR中没有指定的Target IQN */
	NVR_ERROR_DM_NVR_READ_FILE_ERR,		/* 文件读取错误 */
	NVR_ERROR_DM_NVR_CREATE_MD_DEV,		/* 创建md设备失败 */
	NVR_ERROR_DM_NVR_CREATE_VG_ERR,		/* 创建磁盘阵列失败 */
	NVR_ERROR_DM_NVR_CREATE_VOLUME,		/* 创建卷失败 */

	NVR_ERROR_DM_NVR_MSG_NOT_REPLY,		/* 消息未回应 */
	NVR_ERROR_DM_NVR_MAP_VOLUME,		/* 绑定卷至指定的IQN失败 */
	NVR_ERROR_DM_NVR_WRITE_IETD_CONF,	/* 写ietd配置文件失败 */
	NVR_ERROR_DM_NVR_EXPAND_VOLUME,		/* 扩大卷容量失败 */
	NVR_ERROR_DM_NVR_TOO_MANY_VOL,		/* 卷数量超过最大值 */

	NVR_ERROR_DM_NVR_DELETE_LV,			/* 删除逻辑卷失败 */
	NVR_ERROR_DM_NVR_DELETE_VG,			/* 删除卷组失败 */
	NVR_ERROR_DM_NVR_DELETE_MAP,		/* 删除卷的绑定关系失败 */
	NVR_ERROR_DM_NVR_DELETE_MD,			/* 删除md设备失败 */
	NVR_ERROR_DM_CMD_CREATE_VOL,		/* 创建卷命令执行失败，多为卷名重复 */

	NVR_ERROR_DM_CMD_PORT_UNCONNECTED,	/* 分配卷时选中不在线的端口 */
	NVR_ERROR_DM_CMD_DEL_VDISK_VOL,		/* vdisk中仍有卷 */
	NVR_ERROR_DM_TOO_MANY_HOST,			/* IPSAN中host已满 */
	NVR_ERROR_DM_SICK_VDISK,			/* 选择的阵列不可用 */
	NVR_ERROR_DM_NVR_LACK_DISK,			/* 所选的磁盘数量不足 */
	NVR_ERROR_DM_END,

	/* OSIP相关错误号 */
	NVR_ERROR_OSIP_UNSUPPORT = 0x1A01,	/* 不支持该操作 */
	NVR_ERROR_OSIP_END,

	NVR_ERROR_END
};

#ifdef __cplusplus
}
#endif
#endif   /* ----- #ifndef NVR_ERROR_INC  ----- */


