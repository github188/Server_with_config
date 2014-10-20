/*
 * =====================================================================================
 *       Copyright (C), 2008, islab@ZJU
 *       �ļ���     :  nvr_error.h
 *       �ļ�����   :  File Header
 *       �汾��Ϣ   :  1.0
 *       ��������   :  2010��11��09�� 10ʱ57��28�� CST
 *       �汾��¼   :  none
 *       ������     :  
 *       ������Ϣ   :  ojl (Islab), jinliou@es.zju.edu.cn
 *       ��˾����   :  ZJU Digital ISLab.
 *       ����˵��   :
 * =====================================================================================
 */
#ifndef  NVR_ERROR_INC
#define  NVR_ERROR_INC

#ifdef __cplusplus
extern "C"{
#endif

typedef unsigned short error_type;

/* ƽ̨�����붨�� */
#define NVR_ERROR_MASK 0x01

/* 0x0000~0x0FFFԤ�����ն� */

enum __nvr_error_code_
{
	NVR_ERROR_MSG_TIMEOUT = 0x1001,		/* ��Ϣ��ʱ */
	NVR_ERROR_DB_READ_ERROR,			/* ���ݿ��ȡ���� */
	NVR_ERROR_DB_WRITE_ERROR,			/* ���ݿ�д����� */
	NVR_ERROR_DB_ERROR,					/* ���ݿ�������� */
	NVR_ERROR_INTERNAL_ERROR,			/* ϵͳ�ڲ�����,���ڴ����ʧ��,���в���ʧ�ܵ� */
	NVR_ERROR_INVALID_PARAM,			/* ��Ч���� */
	NVR_ERROR_VMS_UNSUPPORT,            /* ��֧�ָò��� */
	NVR_ERROR_VMS_END,

	NVR_ERROR_TC_MSG_TIMEOUT = 0x1101,	/* ��Ϣ��ʱ */
	NVR_ERROR_CLIENT_VERSION_MISMATCH,	/* Client�汾��ƥ��, �����Client */
	NVR_ERROR_USER_NOEXIST,				/* �û������� */
	NVR_ERROR_PASSWD_ERROR,				/* �û�������� */
	NVR_ERROR_USER_LOCKED,				/* �û������� */

	NVR_ERROR_USER_UNLOGIN,				/* �û�δ��¼ */
	NVR_ERROR_USER_LOGIN,				/* �û��ѵ�¼(���������¼�û�) */
	NVR_ERROR_NO_PERMIT,				/* �޲���Ȩ�� */
	NVR_ERROR_RES_NONEXIST,				/* ��Դ������ */
	NVR_ERROR_ORG_NOEXIST,				/* ��֯������ */

	NVR_ERROR_ROLE_NOEXIST,				/* ��ɫ������ */
	NVR_ERROR_XML_RD_ERROR,				/* XML��ȡ���� */
	NVR_ERROR_XML_WR_ERROR,				/* XMLд����� */
	NVR_ERROR_NAME_EXIST,				/* �����Ѵ���(�û�/��ɫ/��֯��) */
	NVR_ERROR_TRANS_INUSE,				/* ͸��ͨ����ĳ��������ʹ�� */

	NVR_ERROR_PTZ_INUSE,				/* PTZ����ʹ���� */
	NVR_ERROR_CAMERA_WITHOUT_PTZ,		/* ��PTZ����� */
	NVR_ERROR_DEVICE_NOEXIST,			/* �豸������ */
	NVR_ERROR_KERNEL_VERSION,			/* �ն��ں˰汾��ƥ�� */
	NVR_ERROR_RAMDISK_VERSION,			/* �ն�Ӧ�ó���汾��ƥ�� */

	NVR_ERROR_REGISTER_AGAIN,			/* �ն��ظ�ע��(������ʱ�յ�ע������) */
	NVR_ERROR_DEV_VERSION_MISMATCH,		/* �ն˰汾��ƥ��(��һ������δ�ɹ�,ֻ��Ӧ��������) */
	NVR_ERROR_DEVICE_EXIST,				/* �豸�Ѿ����� */
	NVR_ERROR_DEVICE_NONEXIST,			/* �豸������ */
	NVR_ERROR_DEVICE_OFFLINE,			/* �豸������ */

	NVR_ERROR_CAMERA_OFFLINE,			/* ����������� */
	NVR_ERROR_CAMERA_NONEXIST,			/* ����������� */
	NVR_ERROR_CAMERAG_NONEXIST,			/* ������鲻���� */
	NVR_ERROR_MONITOR_NONEXIST,			/* ������������ */
	NVR_ERROR_MONITORG_NONEXIST,		/* �������鲻���� */

	NVR_ERROR_TVWALL_NONEXIST,			/* ����ǽ������ */
    NVR_ERROR_IPSAN_NONEXIST,           /* IPSAN������ */
    NVR_ERROR_IPSAN_WITHOUT_DM,         /* IPSANδָ�������CM��CM������ */
    NVR_ERROR_IPSAN_WITHOUT_VOD,        /* IPSANδָ���㲥��VOD��VOD������ */
    NVR_ERROR_IPSAN_VOL_NONEXIST,       /* IPSAN�еľ����� */

    NVR_ERROR_TRANS_NONEXIST,           /* ͸��ͨ���Ѳ����� */
    NVR_ERROR_EVENT_CONFIRMED,          /* �澯�¼���ȷ�� */
	NVR_ERROR_IPSAN_IN_USE,				/* IPSAN�����о���Դ */
    NVR_ERROR_DEVICE_WITH_VOLUME,       /* �豸���о���Դ */
    NVR_ERROR_ROLE_IN_USE,              /* ��ɫ�����û��� */

	NVR_ERROR_NO_PERMIT_ON_DOMAIN,		/* ��Ȩ���������豸����֯ */
    NVR_ERROR_CM_WITH_IPSAN,            /* ����IPSAN�й��ڸ�CM,����ɾ�����йܹ�ϵ */
    NVR_ERROR_VOD_WITH_IPSAN,           /* ����IPSAN�й��ڸ�VOD,����ɾ�����йܹ�ϵ */
    NVR_ERROR_RES_EXIST,				/* ��Դ�Ѿ����� */
    NVR_ERROR_INVALID_ORG,              /* ��Ч��֯(�������ڸ���֯��������֯������豸) */

    NVR_ERROR_RES_IS_SHARED,			/* ���豸�й�����Դ */
    NVR_ERROR_RES_IS_ATTACHED,			/* ���豸�л�����Դ */
    NVR_ERROR_CAMERA_IN_CAMERAG,        /* ������������������ */
    NVR_ERROR_MONITOR_IN_MONITORG,      /* �����������ڼ��������� */
    NVR_ERROR_CAMERAG_IN_RES,           /* �����������������Դ�� */

    NVR_ERROR_CAMERAG_IN_PATROL,        /* ������������������� */
    NVR_ERROR_MONITORG_IN_RES,          /* ������������������Դ�� */
    NVR_ERROR_MONITORG_IN_PATROL,       /* �������������������� */
    NVR_ERROR_TVWALL_IN_RES,            /* ����ǽ����������Դ�� */
    NVR_ERROR_TVWALL_IN_PATROL,         /* ����ǽ������������ */

    NVR_ERROR_GET_VOD_URL,              /* ��ȡ�㲥URLʧ�� */
	NVR_ERROR_WITH_SHARE_RES,			/* �������й�����Դ */
	NVR_ERROR_LOGIN_FAILE_LOCKED,		/* �û�������¼ʧ���ѱ����� */
	NVR_ERROR_MS_IN_MSG,				/* MS����MSG�� */
	NVR_ERROR_LICENSE_FAILED,			/* license��֤ʧ�� */

	NVR_ERROR_INVALID_LICENSE_KEY,		/* ���кŲ����� */
	NVR_ERROR_INVALID_LICENSE_FILE,		/* license�ļ����� */
	NVR_ERROR_LICENSE_NONEXIST,			/* license�ļ�δ�ҵ� */
	NVR_ERROR_LICENSE_KEY_EXIST,		/* ���к��Ѵ��� */
	NVR_ERROR_INVALID_LICENSE,			/* license������ */

	NVR_ERROR_SPEC_OVERFLOW,			/* �ѳ�����֧�ֵ�������� */
	NVR_ERROR_TRANS_CH_NONEXIST,		/* ͸��ͨ�������� */
	NVR_ERROR_CM_IN_IMS,				/* CM����IMS,����ɾ�� */
	NVR_ERROR_VOD_IN_IMS,				/* VOD����IMS,����ɾ�� */
	NVR_ERROR_RES_WITH_MEDIA_RELATION,	/* �������������м�ع�ϵ,����ֹͣʵ�� */

	NVR_ERROR_MONITOR_IN_PATROL,        /* ���������������� */
	NVR_ERROR_DOMAIN_NONEXIST,			/* ���򲻴��� */
	NVR_ERROR_CAMERAG_CAMERA_RESOLUTION, /* ���������������ֱ��ʲ�ƥ�� */
	NVR_ERROR_MONITORG_MONITOR_RESOLUTION, /* ���������м������ֱ��ʲ�ƥ�� */
	NVR_ERROR_MONITORG_MONITOR_IN_PATROL,/* ������������ǽ�м��������������� */

	NVR_ERROR_MCADDR_USED,				/* �鲥��ַ�Ͷ˿��ѷ��� */
	NVR_ERROR_VOLUME_USED,				/* ���ѷ���,��Ӵ洢������ɾ���þ� */
	NVR_ERROR_TVWALL_MONITOR_RESOLUTION,/* ����ǽ�м������ֱ��ʲ�ƥ�� */
	NVR_ERROR_DEL_INVALID_ORG,              /* ����ɾ������֯������֯��������֯  */
	NVR_ERROR_ORG_HAS_RES,                  /* ����֯��������Դ  */

	NVR_ERROR_DEL_SELF_RES,                  /* ����ɾ���Դ��豸*/
	NVR_ERROR_SET_SELF_RES,                  /* ���������Դ��豸*/
	NVR_ERROR_OPERATE_AUTO_MSG,                  /* ���ܲ�������Ӧmsg */
	NVR_ERROR_NO_PERMIT_PRIORITY,       /* �޲���Ȩ�ޣ��û����ȼ������ý�ɫ���ȼ���  */

	NVR_ERROR_NO_PERMIT_PRIVILEGE,      /* �޲���Ȩ�ޣ����ý�ɫȨ�޲����û�Ȩ���Ӽ���  */
	NVR_ERROR_PHYOUT_CHANGE_CAUSE_ATTACH,      /* ���������ڻ�����Դ���������޸��������ģʽ */
	NVR_ERROR_ATTACH_RES_EXIST_IN_ORG,      /* ��֯���Ѵ��ڸ���Դ�Ļ�����Դ  */
	NVR_ERROR_AL_CLIENT_RS_MULTI_USER,      /* �������������¼���û� */
	NVR_ERROR_IPSAN_IN_IMS,				/* IPSAN����IMS������ɾ��*/

    NVR_ERROR_MONITOR_IN_TV_WALL,       /* �����������ڵ���ǽ��*/

	NVR_ERROR_EMAP_EXIST_SUB_MAP,         /* ����ɾ���ӵ�ͼ��Ϊ�յĵ��ӵ�ͼ  */ 
	NVR_ERROR_EMAP_NOEXIST,            /* ���ӵ�ͼ������ */ 

	                                     /* 0x1156  */
	NVR_ERROR_EMAP_RES_NOEXIST,         /* ���ӵ�ͼ��Դ������  */
	NVR_ERROR_DEVICE_HAS_NO_CAMERA,         /* ���豸���������Դ  */
	NVR_ERROR_LICENSE_REG_FAIL,         /* ��Ч��License */
	NVR_ERROR_LICENSE_REG_AGAIN,        /* License�Ѿ����� */
	NVR_ERROR_TC_END,

	/* ʵ����ش���� 0x02XX */
	NVR_ERROR_MN_DC_PREEMPT_ILLEGAL = 0x1201,	/* DC��ռʧ�ܣ���ռ�Ƿ� */
	NVR_ERROR_MN_DC_PREEMPT_PRIORITY_LOW = 0x1202,	/* DC��ռʧ�ܣ�Ȩ�޲��� */
	NVR_ERROR_MN_EC_PREEMPT_FAILED,			/* EC��ռʧ�� */
	NVR_ERROR_MN_DC_MSG_TIMEOUT,			/* DC�೬ʱ */
	NVR_ERROR_MN_DEV2_MSG_TIMEOUT,			/* ��ƵDEV2�೬ʱ */

	NVR_ERROR_MN_MS_MSG_TIMEOUT,			/* MS��ʱ */
	NVR_ERROR_MN_EC_MSG_TIMEOUT,			/* EC�೬ʱ */
	NVR_ERROR_MN_DEV1_MSG_TIMEOUT,			/* ��ƵDEV1�೬ʱ */
	NVR_ERROR_MN_NOTIFY_DELIVER_MSG_TIMEOUT,	/* ֪ͨ������ʱ */
	NVR_ERROR_MN_NO_PROPER_LINK_MODE,		/* �޺�����·ģʽ */

	NVR_ERROR_MN_RES_ID_ILLEGAL,			/* �Ƿ���ԴID */
	NVR_ERROR_MN_RS_FORCE_END_ILLEGAL,		/* ����ǿ��ֹͣ����������ֹͣ */
	NVR_ERROR_MN_UNKOWN_ERROR,			/* MNδ֪���� */
	NVR_ERROR_MN_PATTERN_NOT_MATCH,		/* ��ʽ��ƥ�� */
	NVR_ERROR_MN_RESOLUTION_NOT_MATCH,		/* �ֱ��ʲ�ƥ�� */

	NVR_ERROR_MN_STREAMING_TYPE_NOT_MATCH,		/* �������Ͳ�ƥ�� */
	NVR_ERROR_MN_USER_END_ILLEGAL,          /* �ϼ���ʵ������ϼ���ֹͣ */
	NVR_ERROR_MN_USER_END_PRIORITY_LOW,     /* �û����ȼ��ϵͣ�ֹͣʧ�� */
	NVR_ERROR_MN_SESSION_IN_PREEMPTED,	/* ������������ռ�У������ظ���ռ */
	NVR_ERROR_MN_SESSION_IN_NEGO,		/* ����������Э���У�������ռ */

	NVR_ERROR_MN_DEV_ALREADY_AUDIO, /* �豸���ڶԽ��У�Э��ʧ�� */
	NVR_ERROR_MN_AUDIO_DEV_SAME,    /* �Խ��豸Ϊ��ͬ�豸�����ɶԽ� */

	NVR_ERROR_MN_END,

	NVR_ERROR_MD_START_FAILED = 0x1401,          /* MD��ʼʵ���ڲ����� */
	NVR_ERROR_MD_END_FAILED,           /* MDֹͣʵ���ڲ����� */
	NVR_ERROR_MD_SESSION_ID_REPEAT,	    /* MD���յ��ظ���session_id */
	NVR_ERROR_MD_SESSION_POS_FULL,	    /* MD��session��̬�������� */
	NVR_ERROR_MD_SESSION_ID_NOT_FOUND,  /* MDδ�ҵ���Ӧ��ת��session */

	NVR_ERROR_MD_PORT_ILLEGAL,          /* MD���յ��Ƿ��Ķ˿� */ 
	NVR_ERROR_MD_DELIVER_FAILED,        /* MD����ʧ�� */
	NVR_ERROR_MD_SRC_ADDR_ILLEGAL, /*MD���յ�ַ�ռ�Ƿ�*/
	NVR_ERROR_MD_SRC_ADDR_UNUSED,     /*MD���ҵ��Ķ�ӦMC�˿ڵ�src_addrδʹ��*/
	NVR_ERROR_MD_SRC_ADDR_SPACE_FULL , /*MD���յ�ַ�ռ�����*/

	NVR_ERROR_MD_DST_ADDR_ILLEGAL, /*MD���͵�ַ�Ƿ�*/
	NVR_ERROR_MD_THREAD_OR_SRC_ADDR_POS_ILLEGAL, /*MD���ҵ����߳�λ�û���src_addrλ�÷Ƿ�*/
	NVR_ERROR_MD_SEND_PORT_FULL, /*MD���Ͷ˿�����*/
	NVR_ERROR_MD_RECV_PORT_FULL, /*MD���ն˿�����*/
	NVR_ERROR_MD_RECV_PORT_ILLEGAL , /*MD���ն˿ڷǷ�*/

	NVR_ERROR_MD_SEND_PORT_ILLEGAL , /*MD���Ͷ˿ڷǷ�*/
	NVR_ERROR_MD_CREATE_SEND_SOCKET_FAILED , /*MD��������socketʧ��*/
	NVR_ERROR_MD_DST_ADDR_SPACE_FULL, /*MDת��Ŀ�ĵ�ַ�ռ�����*/
	NVR_ERROR_MD_ALL_THREAD_FULL, /*MDת���߳�����*/
	NVR_ERROR_MD_MULTICAST_RECV_PORT_USED, /*MD�鲥���ն˿��ѱ�ʹ��*/

	NVR_ERROR_MD_MC_PORT_POS_FULL, /*MD��δʹ�õ�MC�˿�λ��*/
	NVR_ERROR_MD_CREATE_RECV_SOCKET_FAILED, /*MD��������socketʧ��*/
	NVR_ERROR_MD_IP_ADD_MEMBERSHIP_FAILED, /*MD�����鲥��ʧ��*/
	NVR_ERROR_MD_RECV_PORT_UNUSED, /*MD���յ��Ķ˿�δʹ��*/
	NVR_ERROR_MD_SEND_PORT_UNUSED, /*MD���յ��ķ��Ͷ˿�δʹ��*/

	NVR_ERROR_MD_SEND_PORT_POS_FULL, /*MD���Ͷ˿�λ������*/
	NVR_ERROR_MD_RECV_PORT_POS_FULL , /*MD���ն˿�λ������*/
	NVR_ERROR_MD_SESSION_EXIST, /*��·���ڣ������رս��ն˿�ʧ��*/

	NVR_ERROR_MD_END,

	NVR_ERROR_DM_FIND_CAMERA = 0x1601,	/* ��ϣ����δ�ҵ���Ӧ��ϵ�ڵ� */
	NVR_ERROR_DM_ISCSI_LOGOFF,			/* iSCSIδ��¼ */
	NVR_ERROR_DM_INIT_AVHELPER,			/* avhelper�����ʼ��ʧ�� */
	NVR_ERROR_DM_OPEN_VOLUME,			/* ���ʧ�� */
	NVR_ERROR_DM_QUERY_RECORD,			/* ¼�����ʧ�� */

	NVR_ERROR_DM_ISCSI_BLOCKED,			/* ISCSI���� */
	NVR_ERROR_DM_ALLOC_VOLUME,			/* ��ʽ����ʧ�� */
	NVR_ERROR_DM_RECYCLE_VOLUME,		/* ���վ�ʧ�� */
	NVR_ERROR_DM_SYNC_EVENT,			/* �¼�ͬ����������camera�����º�����ʱ��ʧ�� */
	NVR_ERROR_DM_GET_PORTS,				/* ��ȡIPSAN���ݶ˿�ʧ�� */

	NVR_ERROR_DM_FIND_IPSAN,			/* ��ϣ����δ�ҵ��豸�ڵ� */
	NVR_ERROR_DM_TELNET_LOGOFF,			/* telnetδ��¼ */
	NVR_ERROR_DM_WRONG_XMLFILE,			/* telnet��ȡ����xml�ĵ�Ϊ���ĵ������� */
	NVR_ERROR_DM_CMD_EXEC_ERR,			/* IPSAN��������ִ�д��� */
	NVR_ERROR_DM_PORT_NONEXIST,			/* ָ���Ķ˿ڲ����� */

	NVR_ERROR_DM_NVR_UNIX_ERROR,		/* ����NVR SANʱUNIXͨѶ���� */
	NVR_ERROR_DM_NVR_SICK_MSG,			/* �յ�����Ϣ���ֶ�ʧ */
	NVR_ERROR_DM_NVR_NO_SPEC_DISK,		/* NVR��û��ָ���Ĵ��� */
	NVR_ERROR_DM_NVR_NO_SPEC_VDISK,		/* NVR��û��ָ����vdisk */
	NVR_ERROR_DM_NVR_NO_SPEC_VOLUME,	/* NVR��û��ָ���ľ� */

	NVR_ERROR_DM_NVR_NO_SPEC_TARGET,	/* NVR��û��ָ����Target IQN */
	NVR_ERROR_DM_NVR_READ_FILE_ERR,		/* �ļ���ȡ���� */
	NVR_ERROR_DM_NVR_CREATE_MD_DEV,		/* ����md�豸ʧ�� */
	NVR_ERROR_DM_NVR_CREATE_VG_ERR,		/* ������������ʧ�� */
	NVR_ERROR_DM_NVR_CREATE_VOLUME,		/* ������ʧ�� */

	NVR_ERROR_DM_NVR_MSG_NOT_REPLY,		/* ��Ϣδ��Ӧ */
	NVR_ERROR_DM_NVR_MAP_VOLUME,		/* �󶨾���ָ����IQNʧ�� */
	NVR_ERROR_DM_NVR_WRITE_IETD_CONF,	/* дietd�����ļ�ʧ�� */
	NVR_ERROR_DM_NVR_EXPAND_VOLUME,		/* ���������ʧ�� */
	NVR_ERROR_DM_NVR_TOO_MANY_VOL,		/* �������������ֵ */

	NVR_ERROR_DM_NVR_DELETE_LV,			/* ɾ���߼���ʧ�� */
	NVR_ERROR_DM_NVR_DELETE_VG,			/* ɾ������ʧ�� */
	NVR_ERROR_DM_NVR_DELETE_MAP,		/* ɾ����İ󶨹�ϵʧ�� */
	NVR_ERROR_DM_NVR_DELETE_MD,			/* ɾ��md�豸ʧ�� */
	NVR_ERROR_DM_CMD_CREATE_VOL,		/* ����������ִ��ʧ�ܣ���Ϊ�����ظ� */

	NVR_ERROR_DM_CMD_PORT_UNCONNECTED,	/* �����ʱѡ�в����ߵĶ˿� */
	NVR_ERROR_DM_CMD_DEL_VDISK_VOL,		/* vdisk�����о� */
	NVR_ERROR_DM_TOO_MANY_HOST,			/* IPSAN��host���� */
	NVR_ERROR_DM_SICK_VDISK,			/* ѡ������в����� */
	NVR_ERROR_DM_NVR_LACK_DISK,			/* ��ѡ�Ĵ����������� */
	NVR_ERROR_DM_END,

	/* OSIP��ش���� */
	NVR_ERROR_OSIP_UNSUPPORT = 0x1A01,	/* ��֧�ָò��� */
	NVR_ERROR_OSIP_END,

	NVR_ERROR_END
};

#ifdef __cplusplus
}
#endif
#endif   /* ----- #ifndef NVR_ERROR_INC  ----- */


