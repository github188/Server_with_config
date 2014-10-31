#include <stdio.h>
#include "IPCData.h"
#include "Log.h"
#include "IPCamera.h"
#include "Command.h"
#include "rtp.h"
#include "RestoreBuffer.h"
#include <iostream>
#include <string> 
#include <fstream>
#include "ServerInfo.h"
#pragma comment(lib,"ws2_32.lib")
//command,retranPort

int TimeOut=1000;
int buffer=50000;

//2014.10.16  Serge ，config data
std::string serverIP="";
std::string ipcIP="";
//IPC端口
int ipcPort=0;
int serverRecPort=0;
//传输端口
int clientCommandPort=0;
//重传端口
int retranport=0;
//控制端口
int commandport=0;
//负载均衡服务器配置项 2014.10.31  Serge
std::string balanceServerIP="";
int  balanceListenPort=0;
int bitRate=0;
int	frame_rate=0;
int	resolution=0;



void readConfig(void);

IPCInfo ipcInfo(" ,0, , ,0",true);
//IPCInfo ipcInfo("192.168.1.10,20000,admin,admin123,20000",true);
//IPCInfo ipcInfo("192.168.1.104,34000,test,test,30000",false);
//serverIP
//extern std::string serverIp;


CRITICAL_SECTION CS;
CRITICAL_SECTION SendLock;

long id=0;
int restoresize=10000;
RestoreBuffer rsb;

/* 2014-05-16: Jasmine, udp_connection_test; added...*/
SOCKET mServSock;
///////////////////////////////////////////////////////

/*接受摄像头视频流数据*/
DWORD WINAPI StartGetIPCData(LPVOID lpParameter)
{
	ipcInfo.startGetData(serverIP);

	WORD wVersionRequested; 
    WSADATA wsaData; 
    int err; 
    wVersionRequested = MAKEWORD(1,1); 
    err = WSAStartup(wVersionRequested,&wsaData); 
    if ( err != 0 ) { 
        return -1; 
    } 
    if ( LOBYTE( wsaData.wVersion ) != 1 || 
        HIBYTE( wsaData.wVersion ) != 1) { 
            WSACleanup( ); 
            return -1; 
    } 

    SOCKET sockSrv=socket(AF_INET,SOCK_DGRAM,0);      //接收摄像头视频流数据的socket
    SOCKADDR_IN addrSrv;
    addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
    addrSrv.sin_family=AF_INET;
    addrSrv.sin_port=htons(ipcInfo.server_recv_port);
    bind(sockSrv,(sockaddr*)&addrSrv,sizeof(SOCKADDR)); 

	int len=sizeof(SOCKADDR); 
	int count=0;
	int timestmp=0;
	int topsqnum;
	int priority=0;
	int number=0;
	//int videoNum=0;
	while(1) 
    { 
		SOCKADDR_IN addr; 
		setsockopt(sockSrv,SOL_SOCKET,SO_RCVTIMEO,(char*)&TimeOut,sizeof(TimeOut));
		setsockopt(sockSrv,SOL_SOCKET,SO_RCVBUF ,(char*)&buffer,sizeof(buffer));
        char recvbuf[1500]; 
        int size=recvfrom(sockSrv,recvbuf,1500,0,(SOCKADDR*)&addr,&len);

		if(size<0)
		{
			printf("Video receive error\n");
			if(ipcInfo.is_connect_ipc)
			{
				ipcInfo.stopGetData(serverIP);    
				ipcInfo.is_started=false;   //
				ipcInfo.restartGetData(serverIP);
			}
		}
		//else
			//printf("package size :%d\n",size);
	
		//需要冲突保护
		//EnterCriticalSection( &CS);

		if(!ipcInfo.is_connect_ipc && size>0)
		{
			number++;
			if(number%1000==0)
			{
				SOCKADDR_IN addr;
				addr.sin_addr.S_un.S_addr=inet_addr(ipcInfo.ipc_ip.c_str());  //服务器的地址
				addr.sin_family=AF_INET;
				addr.sin_port=htons(ipcInfo.ipc_port);

				string command="3,"+ipcInfo.username+","+ipcInfo.password;

				sendto(sockSrv,command.c_str(),command.length()+1,0,(SOCKADDR*)&addr,sizeof(SOCKADDR));
			}
		}
		/*else
		{
			std::cout<<"get no video data."<<std::endl;
		}*/


		if(ipcInfo.hasVideoClients())
		{
			if(size>0)
			{
				if(ipcInfo.is_connect_ipc)
				{
					id++;
					priority++;
					//cout<<"package id::"<<priority<<endl;
					PRTP_header rtp_header = (PRTP_header)(recvbuf);
					int newtmp=rtp_header->timestamp;
					if(newtmp!=timestmp)
					{
						topsqnum=rtp_header->seq/256;
						timestmp=newtmp;
					}
					//printf("get data and have clients\n");
					KeyValue*  pkg=new KeyValue();

					pkg->key=priority;  //这里的优先级有待修改
					pkg->id=id;
					pkg->sqnum=rtp_header->seq/256;
					pkg->timestamp=rtp_header->timestamp;
					pkg->pkgsize=size;
					pkg->isretran=false;
					memcpy(pkg->value,&id,sizeof(long));
					memcpy(pkg->value+sizeof(long),&topsqnum,sizeof(int));
					memcpy(pkg->value+sizeof(long)+sizeof(int),recvbuf,size);
					//memcpy(pkg->value,recvbuf,size);
					//printf("addr:%p\n",&pkg);
					ipcInfo.video_pq.priority_queue_enqueue(pkg);
		
					//printf("sqnum: %d  timestamp:%d\n",rtp_header->seq/256,(rtp_header->timestamp & 0x0000ffff)/256);
					RestoreCell rc;
					rc.id=id;
					rc.sqnum=rtp_header->seq/256;
					if(rc.sqnum-count!=1&&rc.sqnum!=0)printf("miss %d %d\n",rc.sqnum,count);
					count=rc.sqnum;

					rc.timestamp=rtp_header->timestamp;
					rc.size=size;
					memcpy(rc.data,&id,sizeof(long));
					memcpy(rc.data+sizeof(long),&topsqnum,sizeof(int));
					memcpy(rc.data+sizeof(long)+sizeof(int),recvbuf,size);
					rc.isempty=false;
					rsb.writeData(&rc);
				}
				else
				{
					memcpy(&id,recvbuf,sizeof(long));
					
					memcpy(&priority,recvbuf+sizeof(long),sizeof(int));
					
					memcpy(&topsqnum,recvbuf+sizeof(long)+sizeof(int),sizeof(int));
					//printf("topsqnum:%d\n",topsqnum);
					//id++;
					//priority++;
					//cout<<"package id::"<<priority<<endl;
					PRTP_header rtp_header = (PRTP_header)(recvbuf+sizeof(long)+2*sizeof(int));
					/*int newtmp=rtp_header->timestamp;
					if(newtmp!=timestmp)
					{
						topsqnum=rtp_header->seq/256;
						timestmp=newtmp;
					}*/
					//printf("get data and have clients\n");

					//std::cout<<"id:"<<id<<std::endl;
					std::cout<<"priority size:"<<ipcInfo.video_pq.priority_queue_size()<<std::endl;

					KeyValue*  pkg=new KeyValue();

					pkg->key=priority;  //这里的优先级有待修改
					pkg->id=id;
					pkg->sqnum=rtp_header->seq/256;
					pkg->timestamp=rtp_header->timestamp;
					pkg->pkgsize=size-sizeof(long)-2*sizeof(int);
					pkg->isretran=false;
					memcpy(pkg->value,&id,sizeof(long));
					memcpy(pkg->value+sizeof(long),&topsqnum,sizeof(int));
					memcpy(pkg->value+sizeof(long)+sizeof(int),recvbuf+sizeof(long)+2*sizeof(int),size-sizeof(long)-2*sizeof(int));
					//memcpy(pkg->value,recvbuf,size);
					//printf("addr:%p\n",&pkg);
					ipcInfo.video_pq.priority_queue_enqueue(pkg);

		
					//printf("sqnum: %d  timestamp:%d\n",rtp_header->seq/256,(rtp_header->timestamp & 0x0000ffff)/256);
					RestoreCell rc;
					rc.id=id;
					rc.sqnum=rtp_header->seq/256;
					if(rc.sqnum-count!=1&&rc.sqnum!=0)printf("miss %d %d\n",rc.sqnum,count);
					count=rc.sqnum;

					rc.timestamp=rtp_header->timestamp;
					rc.size=size-sizeof(int);
					memcpy(rc.data,&id,sizeof(long));
					memcpy(rc.data+sizeof(long),&topsqnum,sizeof(int));
					memcpy(rc.data+sizeof(long)+sizeof(int),recvbuf+sizeof(long)+2*sizeof(int),size-sizeof(long)-2*sizeof(int));
					rc.isempty=false;
					rsb.writeData(&rc);

				}
			}
			else
			{
				
				printf("video---------get no data and have clients\n");
			}
		}
		else
		{

			//printf("no clients:video------------%d\n",ipcInfo.video_pq.priority_queue_size());
			//videoNum++;
			//std::cout<<"video num:"<<videoNum<<std::endl;
			ipcInfo.video_pq.priority_pop_all();
			//break;
		}
		//LeaveCriticalSection( &CS);
	}
	return 0;
}

DWORD WINAPI StartGetIPCAudioData(LPVOID lpParameter)
{
	WORD wVersionRequested; 
    WSADATA wsaData; 
    int err; 
    wVersionRequested = MAKEWORD(1,1); 
    err = WSAStartup(wVersionRequested,&wsaData); 
    if ( err != 0 ) { 
        return -1; 
    } 
    if ( LOBYTE( wsaData.wVersion ) != 1 || 
        HIBYTE( wsaData.wVersion ) != 1) { 
            WSACleanup( ); 
            return -1; 
    } 

	while(!ipcInfo.is_started)
	{
		Sleep(1);
	}
    SOCKET audioListener=socket(AF_INET,SOCK_DGRAM,0);      
    SOCKADDR_IN addrAudio;
    addrAudio.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
    addrAudio.sin_family=AF_INET;
    addrAudio.sin_port=htons(ipcInfo.server_recv_port+1);
	int ret=bind(audioListener,(sockaddr*)&addrAudio,sizeof(SOCKADDR)); 
	printf("second bind:%d\n",ret);
  

	setsockopt(audioListener,SOL_SOCKET,SO_RCVTIMEO,(char*)&TimeOut,sizeof(TimeOut));

	int len=sizeof(SOCKADDR); 
	int audioCount=0;

	while(1) 
    { 
		SOCKADDR_IN addr; 
		char audioBuff[1500];

        int audioSize=recvfrom(audioListener,audioBuff,1500,0,(SOCKADDR*)&addr,&len);

		if(audioSize<0)
			printf("audio recieve error\n");
	
		if(ipcInfo.hasAudioClients())
		{
			if(audioSize>0)
			{
				if(ipcInfo.is_connect_ipc)  //和摄像机直连
				{
					audioCount++;

					package audioPkg;

					memcpy(audioPkg.buff,&id,sizeof(long));
					memcpy(audioPkg.buff+sizeof(long),audioBuff,audioSize);

					audioPkg.buffsize=audioSize;
					ipcInfo.audio_bq.pushdata(audioPkg);
				}
				else
				{
					audioCount++;

					package audioPkg;

					memcpy(audioPkg.buff,audioBuff,audioSize);
					audioPkg.buffsize=audioSize-sizeof(long);

					ipcInfo.audio_bq.pushdata(audioPkg);
				}
			}
			else
			{
				printf("audio---------get no data and have clients\n");
			}
		}
		else
		{
			//printf("no clients：audio\n");
			ipcInfo.audio_bq.popall();
		}
		//LeaveCriticalSection( &CS);
	}
	return 0;
}

DWORD WINAPI SendIPC_VideoData(LPVOID lpParameter)
{
	/*
	WORD wVersionRequested; 
    WSADATA wsaData; 
    int err; 
    wVersionRequested = MAKEWORD(1,1); 
    err = WSAStartup(wVersionRequested,&wsaData); 
    if ( err != 0 ) { 
        return -1; 
    } 
    if ( LOBYTE( wsaData.wVersion ) != 1 || 
        HIBYTE( wsaData.wVersion ) != 1) { 
            WSACleanup( ); 
            return -1; 
    } 

    SOCKET sockSrv=socket(AF_INET,SOCK_DGRAM,0);
	*/
	int len=sizeof(SOCKADDR); 	
	
	while(1) 
    { 
		vector<Client*> cls;
		vector<Client> clsr;
		
		ipcInfo.minVideoClientHeartBeat();

		// send retran data... 
		if(ipcInfo.hasVideoClients() && retransQueue.priority_queue_size()>0){    //替换成优先级队列
			KeyValue* pkg= retransQueue.priority_queue_dequeue();
			ipcInfo.getVideoClientInfos(cls);
			for(int i=0;i<cls.size();i++){
				int tuid = atoi(&(*cls[i]->user.c_str()));
				//printf("id1:%d id2:%d\n",tuid,pkg.uid);
				if(tuid==pkg->user_id){
				   printf("send retans data");
				   /* Jasmine, commented */
				   // sendto(sockSrv,pkg->value,pkg->pkgsize+sizeof(long)+sizeof(int),0,(SOCKADDR*)&cls[i]->addr,sizeof(SOCKADDR));
				   /* Jasmine, commented */
				   sendto(mServSock,pkg->value,pkg->pkgsize+sizeof(long)+sizeof(int),0,(SOCKADDR*)&cls[i]->addr,sizeof(SOCKADDR));
				   break;
				}
			}
			key_value_free(pkg,NULL);
			continue;
		}

		if(ipcInfo.hasVideoClients() && ipcInfo.video_pq.priority_queue_size()>0)
		{
			KeyValue* pkg= ipcInfo.video_pq.priority_queue_dequeue();
			ipcInfo.getVideoClientInfos(cls);
			//printf("%d\n",cls.size());
			
			for(int i=0;i<cls.size();i++)
			{
				//printf("clientsize %d\n",cls.size());
				if(ipcInfo.getVideoClientHeartBeatnum(i)<=0)
				{
					clsr.push_back(*cls[i]);
				}

				EnterCriticalSection( &SendLock);

				/* Jasmine, commented */
				// sendto(sockSrv,pkg->value,pkg->pkgsize+sizeof(long)+sizeof(int),0,(SOCKADDR*)&cls[i]->addr,sizeof(SOCKADDR));
				/* Jasmine, commented */
				sendto(mServSock,pkg->value,pkg->pkgsize+sizeof(long)+sizeof(int),0,(SOCKADDR*)&cls[i]->addr,sizeof(SOCKADDR));
				
				LeaveCriticalSection( &SendLock);
				
				/* Jasmine 2014-05-14: udp_connection_test */
				// printf("send data to %s , port %d  \n",inet_ntoa(cls[i]->addr.sin_addr),ntohs(cls[i]->addr.sin_port));
				
			}
			key_value_free(pkg,NULL);
			//Sleep(1);   //12.11   解决了上传码率只有下载码率的三分之一左右的问题
			if(!clsr.empty())
			{
				for(int i=0;i<clsr.size();i++)
				{
					printf("remove %s\n",clsr[i].user.c_str());
					ipcInfo.removeVideoClient(clsr[i]);      //11.26     不能注释
					ipcInfo.removeAudioClient(clsr[i]);
				}
				clsr.clear();
			}
		}
		else{
			if(!ipcInfo.hasVideoClients())ipcInfo.video_pq.priority_pop_all();
			Sleep(1);
		}

	}
	return 0;
}

DWORD WINAPI SendIPC_AudioData(LPVOID lpParameter)
{
	/* jasmine, old socket......
	WORD wVersionRequested; 
    WSADATA wsaData; 
    int err; 
    wVersionRequested = MAKEWORD(1,1); 
    err = WSAStartup(wVersionRequested,&wsaData); 
    if ( err != 0 ) { 
        return -1; 
    } 
    if ( LOBYTE( wsaData.wVersion ) != 1 || 
        HIBYTE( wsaData.wVersion ) != 1) { 
            WSACleanup( ); 
            return -1; 
    } 

    SOCKET sockSrv=socket(AF_INET,SOCK_DGRAM,0);
	
	int len=sizeof(SOCKADDR); 	
	
	while(1) 
    { 
		vector<Client*> cls;
		
		if(ipcInfo.hasAudioClients() && ipcInfo.audio_bq.getdatanum()>0)
		{
			package audioPkg=ipcInfo.audio_bq.popdata();     //从音频缓冲区取数据发往客户端
			ipcInfo.getAudioClientInfos(cls);
			//printf("%d\n",cls.size());
			
			for(int i=0;i<cls.size();i++)
			{
				//printf("clientsize %d\n",cls.size());

				EnterCriticalSection( &SendLock);
				//* Jasmine, commented
				sendto(sockSrv,audioPkg.buff,audioPkg.buffsize+sizeof(long),0,(SOCKADDR*)&cls[i]->addr,sizeof(SOCKADDR));
				// Jasmine, added
				// sendto(mServSock,audioPkg.buff,audioPkg.buffsize+sizeof(long),0,(SOCKADDR*)&cls[i]->addr,sizeof(SOCKADDR));

				LeaveCriticalSection( &SendLock);
			}
			
			//Sleep(1);
		}
		else{
			if(!ipcInfo.hasAudioClients())ipcInfo.audio_bq.popall();
			Sleep(1);
		}

	}
	*/
	int len=sizeof(SOCKADDR); 	
	
	while(1) 
    { 
		vector<Client*> cls;
		
		if(ipcInfo.hasAudioClients() && ipcInfo.audio_bq.getdatanum()>0)
		{
			package audioPkg=ipcInfo.audio_bq.popdata();     //从音频缓冲区取数据发往客户端
			ipcInfo.getAudioClientInfos(cls);
			//printf("%d\n",cls.size());
			
			for(int i=0;i<cls.size();i++)
			{
				//printf("clientsize %d\n",cls.size());

				EnterCriticalSection( &SendLock);
				//* Jasmine, commented, old socket version
				// sendto(sockSrv,audioPkg.buff,audioPkg.buffsize+sizeof(long),0,(SOCKADDR*)&cls[i]->addr,sizeof(SOCKADDR));
				// Jasmine, added
				sendto(mServSock,audioPkg.buff,audioPkg.buffsize+sizeof(long),0,(SOCKADDR*)&cls[i]->addr,sizeof(SOCKADDR));

				LeaveCriticalSection( &SendLock);
			}
			
			//Sleep(1);
		}
		else{
			if(!ipcInfo.hasAudioClients())ipcInfo.audio_bq.popall();
			Sleep(1);
		}

	}
	return 0;
}


DWORD WINAPI GetDataFromRFID(LPVOID lpParameter){
	//TODO
	return 0;
}

struct trancomm{
	char  commd[1500];
	int size;
	SOCKADDR_IN addrClient;
};

int countnum=0;

void treatApplyVideoData(SOCKADDR_IN addrClient,string user,string psd){
	printf("sending normal data to port :%d \n",ntohs(addrClient.sin_port));
	Client client;
	client.addr=addrClient;
	client.user=user;
	client.psd=psd;
	//需要冲突保护
	//EnterCriticalSection( &CS);
	ipcInfo.addVideoClient(client);
	//LeaveCriticalSection( &CS);
}


void treatApplyAudioData(SOCKADDR_IN addrClient,string user,string psd)
{
	Client client;
	client.addr=addrClient;
	client.user=user;
	client.psd=psd;
	//需要冲突保护
	//EnterCriticalSection( &CS);
	ipcInfo.addAudioClient(client);
	//LeaveCriticalSection( &CS);
}

void treatStopIPCData(SOCKADDR_IN addrClient,string user,string psd){
	Client client;
	client.addr=addrClient;
	client.user=user;
	client.psd=psd;
	EnterCriticalSection( &CS);
	ipcInfo.removeVideoClient(client);
	ipcInfo.removeAudioClient(client);
	printf("treat stop\n");
	LeaveCriticalSection( &CS);
	//printf("finish treat stop\n");
}

int command;
DWORD WINAPI controlPTZthread(LPVOID lpParameter){
	controlPTZ(ipcInfo.login_id,command);
	return 0;
}

void treatPTZControl(string cmmd)
{
	if(ipcInfo.is_connect_ipc)
	{
		DWORD  ThreadID;
		HANDLE hThread1;
		command=atoi(cmmd.c_str());
		hThread1=CreateThread(NULL,0,controlPTZthread,0,0,&ThreadID);
		CloseHandle(hThread1);
	}
	else
	{
		SOCKET sock_send_command;    //客户端socket
		sock_send_command=socket(AF_INET, SOCK_DGRAM,0);

		SOCKADDR_IN addrSrv;
		addrSrv.sin_addr.S_un.S_addr=inet_addr(ipcInfo.ipc_ip.c_str());  //服务器的地址
		addrSrv.sin_family=AF_INET;
		addrSrv.sin_port=htons(ipcInfo.ipc_port);
        
		string command="2,"+ipcInfo.username+","+ipcInfo.password+","+cmmd;
		sendto(sock_send_command,command.c_str(),command.length()+1,0,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	}
	//实际上需要放在新线程执行
	
}


void treatHeartBeat(string username){
	//printf("updata user:%s\n",username.c_str());
	ipcInfo.updateHeartBeat(username);
}

void osdSetText(const long  login_id,std::string text)
{

	
	if(ipcInfo.is_connect_ipc)
	{
		printf("OSD设置\n");
		TermOsdFieldConfig uiFiledConfig;
		memset(&uiFiledConfig, 0, sizeof(TermOsdFieldConfig));

		uiFiledConfig.uiIndex = 0;
		uiFiledConfig.uiMainSubFlag = 0;
		uiFiledConfig.uiIsEnable = 1;
		uiFiledConfig.uiOsdColor = 3;
		uiFiledConfig.uiStartX = 40*63360/1920;
		uiFiledConfig.uiStartY = 100*8640/1080;
		uiFiledConfig.uiOsdTransparence = 7;
		memcpy(uiFiledConfig.szOsdMainValue, text.c_str(), text.length());
		memcpy(uiFiledConfig.szOsdSubValue, text.c_str(), text.length());
		TermNetSetFieldConfig(login_id, 0, &uiFiledConfig);
	}
	else
	{
		SOCKET sock_send_command;    //客户端socket
		sock_send_command=socket(AF_INET, SOCK_DGRAM,0);

		SOCKADDR_IN addrSrv;
		addrSrv.sin_addr.S_un.S_addr=inet_addr(ipcInfo.ipc_ip.c_str());  //服务器的地址
		addrSrv.sin_family=AF_INET;
		addrSrv.sin_port=htons(ipcInfo.ipc_port);
        
		string command="4,"+ipcInfo.username+","+ipcInfo.password+","+text;
		sendto(sock_send_command,command.c_str(),command.length()+1,0,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));
	}



}


int treatCommand(string commd,int size,SOCKADDR_IN addrClient)
{
	string str=commd.substr(0,size);
	vector<string> _str;
	::split(str,_str);
	Command comheadn=Command(atoi(_str[0].c_str()));
	printf("commad: %d, uid: %s, text: %s \n",comheadn, _str[1].c_str(), _str[2].c_str());
	switch(comheadn){
	case applyIPCData:treatApplyVideoData(addrClient,_str[1],_str[2]);break;
	case stopIPCData:treatStopIPCData(addrClient,_str[1],_str[2]);break;
	case controlMove:treatPTZControl(_str[3]);break;
	case heartBeat:treatHeartBeat(_str[1]);break;
	case osdSet: osdSetText(ipcInfo.login_id,_str[3]);break;
	case applyIPCAudioData:treatApplyAudioData(addrClient,_str[1],_str[2]);break;
	defualt: break;
	}
	return 0;
}


DWORD WINAPI GettingCommandFromClient(LPVOID lpParameter){
	WORD wVersionRequested; 
    WSADATA wsaData; 
    int err; 
    wVersionRequested = MAKEWORD(1,1); 
    err = WSAStartup(wVersionRequested,&wsaData); 
    if ( err != 0 ) { 
        return -1; 
    } 
    if ( LOBYTE( wsaData.wVersion ) != 1 || 
        HIBYTE( wsaData.wVersion ) != 1) { 
            WSACleanup( ); 
            return -1; 
    } 

	/* 2014-05-16: Jasmine: udp_conenction_test; commented */
	/*
    mServSock=socket(AF_INET,SOCK_DGRAM,0);

    SOCKADDR_IN addrSrv;
    addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
    addrSrv.sin_family=AF_INET;
    addrSrv.sin_port=htons(ClientCommandPort);

    bind(mServSock,(sockaddr*)&addrSrv,sizeof(SOCKADDR)); 
	*/
    
    int len=sizeof(SOCKADDR); 
	int bufsize = 0;

	while(1) 
    { 
		SOCKADDR_IN addrClient; 
		printf("start recv\n");
		char recvbuf[200];
		//::setsockopt(sockconn,SOL_SOCKET,SO_RCVTIMEO,(char*)&TimeOut,sizeof(TimeOut));   
        /* 2014-05-17: Jasmine changed ...*/
		// char recvbuf[200]; 
        // int size=recvfrom(sockSrv,recvbuf,200,0,(SOCKADDR*)&addrClient,&len);
		bufsize = recvfrom(mServSock,recvbuf,200,0,(SOCKADDR*)&addrClient,&len);
		// printf("welcome %s to UPD server port %d\n",inet_ntoa(addrClient.sin_addr),addrClient.sin_port);
		if( bufsize > 0){
			//treat recv cmd
			string str=recvbuf;
			printf("command:%s, buffer_size: %d \n",recvbuf, bufsize);
			treatCommand(str,bufsize,addrClient);
		}
		/*
		void treatApplyVideoData(SOCKADDR_IN addrClient,string user,string psd){
			printf("sending normal data to port :%d \n",ntohs(addrClient.sin_port));
			Client client;
			client.addr=addrClient;
			client.user=user;
			client.psd=psd;
			//需要冲突保护
			EnterCriticalSection( &CS);
			ipcInfo.addVideoClient(client);
			LeaveCriticalSection( &CS);
		}
		*/
    } 
	return 0;
}

//Serge 2014.10.31
DWORD WINAPI  connectToBalanceServer(LPVOID lpParameter)
{
	WORD wVersionRequested;
    WSADATA wsaData;
    int err;
	wVersionRequested = MAKEWORD(1, 1);
    err = WSAStartup(wVersionRequested, &wsaData);
    if (err != 0) {                                 
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }
    if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1) {
        printf("Could not find a usable version of Winsock.dll\n");
        WSACleanup();
        return 1;
    }
    else
        printf("The Winsock 1.1 dll was found okay\n");

	SOCKET sockServerToBanlance=socket(AF_INET,SOCK_DGRAM,0);


	SOCKADDR_IN addrBalanSrv;
	addrBalanSrv.sin_addr.S_un.S_addr=inet_addr(balanceServerIP.c_str());
	addrBalanSrv.sin_family = AF_INET;
	addrBalanSrv.sin_port = balanceListenPort;
	serverConnectRequst temp;
	temp.bitRate=bitRate;
	//login list
	temp.flag=1;
	temp.frame_rate=frame_rate;
	temp.resolution=resolution;
	temp.serverCommandPort=commandport;
	temp.serverDataPort=clientCommandPort;
	temp.serverIp=serverIP;
	temp.serverRetranPort=retranport;
	char sendbuf[200];
	
	while(1)
	{
		for(int i=0;i<200;i++)
		{
			sendbuf[i]=((char*)(&temp))[i];
		}
		sendto(sockServerToBanlance,sendbuf,200,0,(SOCKADDR *)&addrBalanSrv,sizeof(addrBalanSrv));
		Sleep(10000);
	}
	return 1;
}

//配置项文件 serge 2014.10.16 
//裁剪字符串两边空格
std::string& trim(std::string &s)   
{  
    if (s.empty())   
    {  
        return s;  
    }  
  
    s.erase(0,s.find_first_not_of(" "));  
    s.erase(s.find_last_not_of(" ") + 1);  
    return s;  
}  
//读取配置文件
void readConfig(void)
{
	ifstream finC;
	finC.open("config.cfg");

	string tempStr="";

	if(finC.is_open())
	{
		
		while(getline(finC,tempStr))
		{
			if(trim(tempStr).size()<=0)
			{ continue; }
			else if(trim(tempStr).size()>0)
			{
				if(tempStr[0]=='#')
					{
						//输出配置注释
					//	cout<<"notation :"<<tempStr<<endl;
						continue ;
					}
				string temp1=tempStr;
				string temp2=tempStr;
				temp1.erase(temp1.find_first_of(" "));  
				temp2.erase(0,temp2.find_first_of(' ')); 
				trim(temp1);
				trim(temp2);
				//cout<<temp2<<endl;
				//在此添加配置项
				//设置服务器IP
				if(temp1 == "SERVER_IP")
				{
					serverIP = temp2;
					cout<<"SET SERVER IP = "<<serverIP<<endl;
				}
				if(temp1 == "IPC_IP")
				{
					ipcIP = temp2;
					cout<<"SET IPC IP = "<<ipcIP<<endl;
				}
				if(temp1 == "IPC_PORT")
				{
					ipcPort = atoi(temp2.data());
					cout<<"SET IPCPORT = "<<ipcPort<<endl;
				}
				if(temp1 == "SERVER_RECIEVE_PORT")
				{
					serverRecPort = atoi(temp2.data());
					cout<<"SET SERVER_REC_PORT = "<<serverRecPort<<endl;
				}
				if(temp1 == "CLIENT_COMMAND_PORT")
				{
					clientCommandPort = atoi(temp2.data());
					cout<<"SET CLIENTCOMMANDPORT = "<<clientCommandPort<<endl;
				}
				if(temp1 == "RETRAN_PORT")
				{
					retranport = atoi(temp2.data());
					cout<<"SET RETRAN_PORT = "<<retranport<<endl;
				}
				if(temp1 == "COMMAND_PORT")
				{
					commandport = atoi(temp2.data());
					cout<<"SET COMMAND_PORT = "<<commandport<<endl;
				}
					if(temp1 == "BALANCE_SERVER_IP")
				{
					balanceServerIP =temp2;
					cout<<"SET BALANCE_SERVER_IP = "<<balanceServerIP<<endl;
				}
				if(temp1 == "BALANCE_LISTEN_PORT")
				{
					balanceListenPort = atoi(temp2.data());
					cout<<"SET BALANCE_LISTEN_PORT = "<<balanceListenPort<<endl;
				}
				if(temp1 == "FRAME_RATE")
				{
					frame_rate = atoi(temp2.data());
					cout<<"SET FRAME_RATE = "<<frame_rate<<endl;
				}
				if(temp1 == "RESOLUTION")
				{
					resolution = atoi(temp2.data());
					cout<<"SET RESOLUTION = "<<resolution<<endl;
				}
				if(temp1 == "BITRATE")
				{
					bitRate = atoi(temp2.data());
					cout<<"SET BITRATE = "<<bitRate<<endl;
				}
			}
		}

		finC.close();
		//检测读取文件是否正常
		if(serverIP=="")
			cout<<"read config error,SERVER IP is blank\n";
		if(ipcIP=="")
			cout<<"read config error,ipcIP is NULL\n";
		if(ipcPort==0)
			cout<<"read config error,ipcPort is 0\n";
		if(serverRecPort==0)
			cout<<"read config error,serverRecPort is 0\n";	
		if(clientCommandPort==0)
			cout<<"read config error,clientCommandPort is 0\n";
		if(retranport==0)
			cout<<"read config error,retranport is 0\n";
		if(commandport==0)
			cout<<"read config error,commandport is 0\n";
		if(balanceServerIP=="")
			cout<<"read config error,balanceServerIP is blank\n";
		if(balanceListenPort==0)
			cout<<"read config error,balanceListenPort is 0\n";
		if(frame_rate==0)
			cout<<"read config error,frame_rate is 0\n";
		if(resolution==0)
			cout<<"read config error,resolution is 0\n";
		if(bitRate==0)
			cout<<"read config error,bitRate is 0\n";
	}
	else
	{
		cout<<"can not open config\n";
		return;
	}
}

int main(int argc,char *argv[])
{
	//配置文件读取
	readConfig();
	//ipcInfo=IPCInfo("192.168.1.10,20000,admin,admin123,20000",true);
	char str1[20],str2[20];
	itoa(ipcPort,str1,10);
	itoa(serverRecPort,str2,10);
	string temp_para;
	temp_para=ipcIP+","+str1+",admin,admin123,"+str2;
	ipcInfo=IPCInfo(temp_para,true);

	//start
	if(argc==2)
	{
		string ipc_configure=argv[1];
		ipcInfo.serConfigure(ipc_configure);
	}


	WORD wVersionRequested; 
    WSADATA wsaData; 
    int err; 
    wVersionRequested = MAKEWORD(1,1); 
    err = WSAStartup(wVersionRequested,&wsaData); 
    if ( err != 0 ) { 
        return -1; 
    } 
    if ( LOBYTE( wsaData.wVersion ) != 1 || 
        HIBYTE( wsaData.wVersion ) != 1) { 
            WSACleanup( ); 
            return -1; 
    }

	/* 2014-05-16: Jasmine; udp_connection_test; added...*/
    mServSock=socket(AF_INET,SOCK_DGRAM,0);

    SOCKADDR_IN addrSrv;
    addrSrv.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
    addrSrv.sin_family=AF_INET;
    addrSrv.sin_port=htons(clientCommandPort);

    bind(mServSock,(sockaddr*)&addrSrv,sizeof(SOCKADDR)); 
	//////////////////////////////////////////////////////

	SOCKET sock_send_svr_register;
    sock_send_svr_register=socket(AF_INET,SOCK_DGRAM,0);

	SOCKADDR_IN loginSvrAddr;
	loginSvrAddr.sin_addr.S_un.S_addr=inet_addr("192.168.1.101");  //Login服务器的地址
    loginSvrAddr.sin_family=AF_INET;
    loginSvrAddr.sin_port=htons(65000);

	
	string svrRegisterInfo="";
	svrRegisterInfo=svrRegisterInfo+ipcInfo.ipc_ip+";"+serverIP+":"+intToStr(clientCommandPort);
	sendto(sock_send_svr_register,svrRegisterInfo.c_str(),svrRegisterInfo.length()+1,0,(SOCKADDR*)&loginSvrAddr,sizeof(SOCKADDR));//发送指令

	HANDLE hThread1;
	HANDLE hThread2;
	HANDLE hThread3;
	HANDLE hThread4;
	HANDLE hThread5;
	HANDLE hThread6;
	HANDLE hThread7;

    DWORD  ThreadID1;
	DWORD  ThreadID2;
	DWORD  ThreadID3;
    DWORD  ThreadID4;
	DWORD  ThreadID5;
    DWORD  ThreadID6;
	DWORD  ThreadID7;


	InitializeCriticalSection(&CS);
	InitializeCriticalSection(&SendLock);

	rsb.init(restoresize);

	hThread1=CreateThread(NULL,0,GettingCommandFromClient,0,0,&ThreadID1);
	hThread2=CreateThread(NULL,0,SendIPC_VideoData,0,0,&ThreadID2);
	hThread4=CreateThread(NULL,0,StartGetIPCData,0,0,&ThreadID4);

	hThread5=CreateThread(NULL,0,StartGetIPCAudioData,0,0,&ThreadID5);
	hThread6=CreateThread(NULL,0,SendIPC_AudioData,0,0,&ThreadID6);

	hThread7=CreateThread(NULL,0,RetranTreat,0,0,&ThreadID7);
	
	hThread3=CreateThread(NULL,0,connectToBalanceServer,0,0,&ThreadID3);

	WaitForSingleObject(hThread1,INFINITE);
	Sleep(-1);
	//system("PAUSE");
	//CloseHandle(hThread1);
	
}



