/*
 * =====================================================================================
 *       Copyright (C), 2008, islab@ZJU
 *       �ļ���     :  nvr_config.h
 *       �ļ�����   :  File Header
 *       �汾��Ϣ   :  1.0
 *       ��������   :  2011��03��02�� 17ʱ15��09�� CST
 *       �汾��¼   :  none
 *       ������     :  
 *       ������Ϣ   :  ojl (Islab), jinliou@es.zju.edu.cn
 *       ��˾����   :  ZJU Digital ISLab.
 *       ����˵��   :
 * =====================================================================================
 */
#ifndef  NVR_CONFIG_INC
#define  NVR_CONFIG_INC

#ifdef __cplusplus
extern "C"{
#endif

/* ƽ̨���ú� */
/* ����������Чֵ(����Ϊ��������) */
#define INVALID_VALUE_NUMBER    -1
#define INVALID_VALUE_STRING    ""

/* ���ݿ����ʱ����(����/����) */
#define ASC_ORDER 				(0)
#define DSC_ORDER 				(1)

/*************************************************************/
/*                  �ն��豸����                             */
/*************************************************************/
/* ����������֧�ֵ������������� */
#define TERM_MAX_CHANNEL_NUM (16)
/* �����豸�¶ȸ澯Դ���� */
#define TERM_MAX_TEMP_NUM   (1)

/* ����DSP��ͨ������ */
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

/* ��������־ƫ�� */
#define MAIN_SUB_FLAG_SHIFT RID_NUMBER_CNT_SHIFT

/* �����������֧�ֵ�Motion����������� */
#define MAX_MOTION_AREA_PER_CHANNEL    (4)
#define MOTION_AREA_INDX_SHIFT RID_NUMBER_CNT_SHIFT

/* �����������֧�ֵ�VL�澯������� */
#define MAX_VL_NUM_PER_CHANNEL  (1)

#define MAX_AREA_MASK			(1024)

#define MAX_OSD_VALUE			(64)

/* ������������е�OSD�������� add by ojl @ 2011-08-29 */
#define MAX_OSD_FIELD_PER_CHANNEL (4)

/* ���������֧�ֵ�Ѳ��·������ */
#define MAX_CRUISE_PATH_PER_CHANNEL (16)
#define CRUISE_PATH_INDX_SHIFT RID_NUMBER_CNT_SHIFT

#define MAX_NAME_LEN32			(STRING_LEN_32)
/* D018�ٺ����ַ��������޸� */
#define MAX_NAME_LEN64			(STRING_LEN_32)
//#define MAX_NAME_LEN64			(STRING_LEN_64)
#define MAX_LIST_LEN			(32)
#define MAX_DESC_LEN			(64)

/* Ϊ4�������������Ԥ��[x]+'\0',����ż�� */
#define CLIENT_MAX_NAME_LEN		(MAX_NAME_LEN64 - 4)

/* �豸���кų��� */
#define DEVICE_SN_LEN   (64)

/* verdor name "ntech" or "other" */
#define VENDOR_NAME_LEN  (6)
#define VENDOR_NAME_LOCAL  "ntech"
#define VENDOR_NAME_H3C  "H3C"
#define VENDOR_NAME_ONU  "ONU"
#define VENDOR_NAME_OTHER  "other"

/* IP��ַ����(����IPV6) */
#define IPADDR_LEN (16)
#define MACDDR_LEN (16)

/* IPSAN�û��������볤�� */
#define IPSAN_USER_LEN    (32)
#define IPSAN_PASSWD_LEN  (32)

#define FTP_PATH_LEN (64)

/* �ַ�����ʾ�İ汾����󳤶� */
#define VERSION_STR_LEN (32)

#define VDISK_NAME_LEN (32)

/* �ܹ�ͬһIPSAN�����VOD���� */
#define MAX_VOD_PER_IPSAN (16)

#define MAX_IQN_LEN	(128)

#define ROLE_TYPE_LEN (32)

#define TASK_PARAM_LEN (256)

#define RESOURCE_ORG_PATH (64)
#define SHARE_DOMAIN_LIST (32)

/* (MSG,�������,��������,����ǽ)����Ԫ��������� */
#define MAX_GROUP_ELEMENT_NUM (256)

/* ����ΪMD5���ܺ�����(128bit) */
//#define PASSWD_LEN (16)
/* ������'\0' */
#define PASSWD_LEN (32)
//#define PASSWD_LEN ( 128 )
#define EMAIL_LEN 32
#define PHONE_NO_LEN 20

#define ISCSI_DEFAULT_PORT (3260)

#define IN 
#define OUT
#define INOUT

/* �޸����⡢���������������ʱ�����ն�ͬ���޸� */
/* ��������������� */
#define MAX_ALARM_EXC_NUM (16)

/* ���������������(������������) */
#define MAX_ALARM_ACTION_NUM (128)

/* �ն���������Ķ���������� */
#define MAX_TERM_ALARM_ACTION_NUM (16)

/* ѭ������������ */
#define MAX_TRY_COUNT (5)

/* �ն˲������group���� */
#ifndef MINE_PRODUCT
#define MAX_TERM_PARAM_GROUP_CNT (1024)
#else
#define MAX_TERM_PARAM_GROUP_CNT (1024 * 2)
#endif

/* �㲥URL��󳤶� */
#define MAX_RTSP_URL_LEN (256)

/* IPSAN���ݶ˿�������󳤶� */
#define PORT_NAME_LEN 4

/* IPSAN�����ݶ˿�������� */
#define MAX_PORT_NUM  8

/* ֧�ֵ������������ */
#define MAX_NET_IFC_NUM 8
/* ϵͳ��CPU������� */
#define MAX_CPU_COUNT 32
/* ϵͳ������������ */
#define MAX_DISK_COUNT 1024

/* license���� */
#define MAX_LICENSE_KEY_LEN 32

/* ϵͳ��ʹ�õ��ļ�ʷ��󳤶� */
#define MAX_FILE_PATH_LEN 128

/*Ȩ������*/
typedef enum __ENUM_PRIVILEGE_TYPE__{
    PRIV_LIVE = 0x01,		/*ʵ��*/
    PRIV_PLAYBACK = 0x02,	/*�ط�*/
    PRIV_MAP = 0x04,		/*��ͼ*/
    PRIV_ALARM = 0x08,		/*�澯*/
    PRIV_CONFIG = 0x10,		/*����*/
    PRIV_MANAGE = 0x20,		/*ҵ�����*/
    PRIV_MAINTAIN = 0x40 	/*ϵͳά��*/
}enum_priv_type;

typedef enum __addr_type{    
    IPADDR_TYPE_IPV4,    
    IPADDR_TYPE_IPV6
}enum_ipaddr_type;

typedef enum __patrol_type__{
    PATROL_TYPE_MONITOR,	/* �������<-->������ */
    PATROL_TYPE_MONITORG,	/* �������<-->�������� */
    PATROL_TYPE_TVWALL,		/* �������<-->����ǽ */
    PATROL_TYPE_END
}patrol_type;

typedef enum
{
    Ret_OK = 0,						//�ɹ�
    Ret_ERROR_UNKNOWN = -1,			//δ֪����
    Ret_ERROR_BADPARAM = -2,		//�Ƿ�����
    Ret_ERROR_NULLPTR= -3,			//��ָ��
    Ret_ERROR_OUTOFRANGE = -4,		//������Χ����
    Ret_ERROR_INVALID_HANDLE = -5,	//�Ƿ����
    Ret_ERROR_NORESOURCES = -6,		//û����Դ
    Ret_ERROR_OFFLINE = -7,			//�豸����Դ������
    Ret_ERROR_VERSION_MISMATCH = -8,//�豸ֻ��Ӧ��������
    Ret_ERROR_NO_PRIVI = -9,		//û�в���Ȩ��
    Ret_ERROR_NONEXIST = -10,		//�������󲻴���
    Ret_ERROR_EXIST = -11,			//���������Ѿ�����
    Ret_ERROR_MULTI_ENTRY = -12,	//���ڶ����������
    Ret_ERROR_OVERFLOW = -13,       //���������
    Ret_ERROR_CAMERA_WITHOUT_PTZ = -14,//����̨�����
    Ret_END
}ret_status;

/* IPSAN�о����� */
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

/* �����û�ID */
enum __super_user_id__
{
    SUPER_USERID_ADMIN = 0xFFFFFFFE,     /* admin(��Ӧrole_id:0x7FFFFFFE) */
    SUPER_USERID_ALARM = 0xFFFFFFFD,     /* �澯ʹ�õ�user_id(role_id:0x7FFFFFFD) */
    SUPER_USERID_DOMAIN = 0xFFFFFFFC,    /* ���ͨ��ʹ�õ�user_id */
    SUPER_USERID_PLAN = 0xFFFFFFFB,      /* �ƻ�ʹ�õ�user_id */
    SUPER_USERID_END
};

/* �����û���ɫID */
enum __super_role_id__
{
    SUPER_ROLEID_ADMIN = 0x7FFFFFFE,     /* admin(��Ӧrole_id:0x7FFFFFFE) */
    SUPER_ROLEID_ALARM = 0x7FFFFFFD,     /* �澯ʹ�õ�user_id(role_id:0x7FFFFFFD) */
    SUPER_ROLEID_DOMAIN = 0x7FFFFFFC,    /* ���ͨ��ʹ�õ�user_id */
    SUPER_ROLEID_PLAN = 0x7FFFFFFB,      /* �ƻ�ʹ�õ�user_id */
    SUPER_ROLEID_END
};

/* �����û����ȼ� */
enum __super_user_priority__
{
    SUPER_PRIORITY_ADMIN = 64,      /* admin */
    SUPER_PRIORITY_ALARM = 65,      /* �澯 */
    SUPER_PRIORITY_DOMAIN = 32,             /* ���ͨ�� */
    SUPER_PRIORITY_PLAN = 1,                /* �ƻ� */
    SUPER_PRIORITY_END
};

/* �����û�ӵ������Ȩ�� */
#define SUPER_PRIVILEGE 0xFFFFFFF

/* MSG����Ӧ��ID */
#define MSG_AUTO_ID (-1)

/* �����ļ����� */
#ifdef PLATFORM_NVR
#define VMS_CONF_FILE "/tmp/config/inuse/nvr_capability_config"
#else
#define VMS_CONF_FILE "vms_config"
#endif
#define VMS_DOMAIN_ID "domain_id"

/* Ԥ������ID */
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


