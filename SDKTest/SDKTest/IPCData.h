#ifndef IPCData
#define IPCData
#include "TermNetSDK.h"
#include "TermNetStruct.h"
#include "VmsCommon.h"
#include <iostream>
#include <windows.h>

using namespace std;

int startGetDataFromIPC(char* ipc_ip,char* usr,unsigned char* psd,char* local_ip,int recv_port,int ipc_port,long* login_id)
{
	int ret=TermNetInit();
	
	if(ret != SDK_ERROR_SUC)
	{
		printf("SDK��ʼ��ʧ��!\n");
		return -1;
	}
	ret = TermNetLogin(ipc_ip, ipc_port,usr,psd,login_id);
	if(ret != SDK_ERROR_SUC)
	{
		printf("��½ʧ��!\n");
		return -1;
	}

	TermLivePlayParam *pLiveParam=new TermLivePlayParam;
	memset(pLiveParam,0,sizeof(TermLivePlayParam));

	//char term_ip[16]="192.168.1.6";
	//strcpy(pLiveParam->szRecvAddr,term_ip);
	strcpy(pLiveParam->szRecvAddr,local_ip);

	pLiveParam->uiChannelId=0;
	pLiveParam->uiMainSubFlag=0;
	pLiveParam->uiTransMode=0;
	pLiveParam->uiStreamType=0;
	pLiveParam->uiRecvPort=recv_port;
	pLiveParam->uiMcFlag=0;

	ret=TermNetLivePlayStart(*login_id,pLiveParam);
	if(ret != SDK_ERROR_SUC)
	{
		printf("δ�ܻ�ȡ��Ƶ��!\n");
		return -1;
	}
	else
	{
		printf("��Ƶ�������ɹ�!\n");
	}
	return 0;
}

int restart(char* ipc_ip,char* usr,unsigned char* psd,char* local_ip,int recv_port,int ipc_port,long* login_id)
{
	int ret = TermNetLogin(ipc_ip, ipc_port,usr,psd,login_id);
	if(ret != SDK_ERROR_SUC)
	{
		printf("��½ʧ��!\n");
		return -1;
	}

	TermLivePlayParam *pLiveParam=new TermLivePlayParam;
	memset(pLiveParam,0,sizeof(TermLivePlayParam));

	//char term_ip[16]="192.168.1.6";
	//strcpy(pLiveParam->szRecvAddr,term_ip);
	strcpy(pLiveParam->szRecvAddr,local_ip);

	pLiveParam->uiChannelId=0;
	pLiveParam->uiMainSubFlag=0;
	pLiveParam->uiTransMode=0;
	pLiveParam->uiStreamType=0;
	pLiveParam->uiRecvPort=recv_port;
	pLiveParam->uiMcFlag=0;

	ret=TermNetLivePlayStart(*login_id,pLiveParam);
	if(ret != SDK_ERROR_SUC)
	{
		printf("δ�ܻ�ȡ��Ƶ��!\n");
		return -1;
	}
	else
	{
		printf("��Ƶ�������ɹ�!\n");
	}
	return 0;
}










int stopGetDataFromIPC(const long  login_id,char* local_ip,int recv_port)
{
	int ret;

	TermLivePlayParam *pLiveParam=new TermLivePlayParam;
	memset(pLiveParam,0,sizeof(TermLivePlayParam));

	//char term_ip[16]="192.168.1.6";
	strcpy(pLiveParam->szRecvAddr,local_ip);

	pLiveParam->uiChannelId=0;
	pLiveParam->uiMainSubFlag=0;
	pLiveParam->uiStreamType=0;
	pLiveParam->uiRecvPort=recv_port;

    ret =TermNetLivePlayStop(login_id,pLiveParam);
	delete pLiveParam;
	if(ret != SDK_ERROR_SUC)
	{
		printf("ʵ������ʧ��!\n");
		return -1;
	}
	else
	{
		printf("ʵ�������ɹ�!\n");
	}
	ret=TermNetLogout(login_id);
	if(ret != SDK_ERROR_SUC)
	{
		printf("�˳�ʧ��!\n");
		return -1;
	}
	else
	{
		printf("�˳��ɹ�!\n");
	}	

	return 0;
}


int controlPTZ(const long  login_id,int command){   //��̨����ָ�ʼת��ֱ�����յ�ָֹͣ��
	int ret;
	printf("��̨����\n");
	switch (command){
	case 1: ret=TermNetPtzCtrl(login_id,0,VmsPtzCmdTiltUp,0) ;break;
	case 2: ret=TermNetPtzCtrl(login_id,0,VmsPtzCmdTiltDown,0) ;break;
	case 3: ret=TermNetPtzCtrl(login_id,0,VmsPtzCmdPanRight,0) ;break;
	case 4: ret=TermNetPtzCtrl(login_id,0,VmsPtzCmdPanLeft,0) ;break;
	case 5: ret=TermNetPtzCtrl(login_id,0,VmsPtzCmdZoomTele,0) ;break;
	case 6: ret=TermNetPtzCtrl(login_id,0,VmsPtzCmdZoomWide,0) ;break;
	}
	
	if(ret !=SDK_ERROR_SUC)
	{
		printf("��̨����ʧ��\n");
		return -1;
	}
	printf("��̨���ƽ���\n");
	Sleep(300);
	switch (command){
	case 1: ret=TermNetPtzCtrl(login_id,0,VmsPtzCmdTiltUpStop,0) ;break;
	case 2: ret=TermNetPtzCtrl(login_id,0,VmsPtzCmdTiltDownStop,0) ;break;
	case 3: ret=TermNetPtzCtrl(login_id,0,VmsPtzCmdPanRightStop,0) ;break;
	case 4: ret=TermNetPtzCtrl(login_id,0,VmsPtzCmdPanLeftStop,0) ;break;
	case 5: ret=TermNetPtzCtrl(login_id,0,VmsPtzCmdZoomTeleStop,0) ;break;
	case 6: ret=TermNetPtzCtrl(login_id,0,VmsPtzCmdZoomWideStop,0) ;break;
	}
	return 0;
}


//OSD����
void osdSetTextWithXY(const long  login_id,std::string text , int x, int y)
{
	printf("OSD����\n");
	TermOsdFieldConfig uiFiledConfig;
	memset(&uiFiledConfig, 0, sizeof(TermOsdFieldConfig));

	uiFiledConfig.uiIndex = 0;
	uiFiledConfig.uiMainSubFlag = 0;
	uiFiledConfig.uiIsEnable = 1;
	uiFiledConfig.uiOsdColor = 3;
	uiFiledConfig.uiStartX = x*63360/1920;
	uiFiledConfig.uiStartY = y*8640/1080;
	uiFiledConfig.uiOsdTransparence = 7;
	memcpy(uiFiledConfig.szOsdMainValue, text.c_str(), text.length());
	memcpy(uiFiledConfig.szOsdSubValue, text.c_str(), text.length());
	TermNetSetFieldConfig(login_id, 0, &uiFiledConfig);
}

#endif