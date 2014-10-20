#ifndef IPCAMERA_H
#define IPCAMERA_H

#include<iostream>
#include<vector>
#include <string>
#include <windows.h>
#include"IPCData.h"
#include "BuffQueue.h"
#include "pq.h"
#include "Command.h"

struct Client{
	std::string user;
	std::string psd;
	SOCKADDR_IN addr;
	int num;
};

class IPCInfo{
public:
	std::string    ipc_ip;  //多级时是上一级服务器的ip,单级时是ipc的ip
	int    ipc_port;
	int    server_recv_port;
	std::string    username;
	std::string    password;

	
	PriorityQueue video_pq;
	BuffQueue audio_bq;
	std::vector<Client> video_clients;
	std::vector<Client> audio_clients;
	long login_id;
	bool is_connect_ipc;
	bool is_started;
private:
	CRITICAL_SECTION CS1;    //用于video_clients临界区
	CRITICAL_SECTION CS2;    //用于audio_clients临界区
	CRITICAL_SECTION CS3;    //用于is_started临界区
	
public:

	IPCInfo(std::string ipc_configure,bool connect_ipc):video_pq(2)
	{
		vector<string> ipc_configure_item;
		split(ipc_configure,ipc_configure_item,",");

		InitializeCriticalSection(&CS1);
		InitializeCriticalSection(&CS2);
		InitializeCriticalSection(&CS3);
		ipc_ip = ipc_configure_item[0];
		ipc_port = atoi(ipc_configure_item[1].c_str());
		username = ipc_configure_item[2];
		password = ipc_configure_item[3];
		server_recv_port = atoi(ipc_configure_item[4].c_str());

		is_connect_ipc=connect_ipc;

		is_started=false;
	}

	void serConfigure(std::string ipc_configure)  //配置语句的格式为：ipc_ip,ipc_port,username,password,server_recv_port,1/2(1表示直连，2表示非直连)
	{
		vector<string> ipc_configure_item;
		split(ipc_configure,ipc_configure_item,",");

		ipc_ip = ipc_configure_item[0];
		ipc_port = atoi(ipc_configure_item[1].c_str());
		username = ipc_configure_item[2];
		password = ipc_configure_item[3];
		server_recv_port = atoi(ipc_configure_item[4].c_str());

		if(ipc_configure_item[5]=="1")
			is_connect_ipc=true;
		else
			is_connect_ipc=false;
		//is_connect_ipc=connect_ipc;
	}

	void minVideoClientHeartBeat()
	{
		EnterCriticalSection( &CS1);
		for(int i=0;i<video_clients.size();i++){
			video_clients[i].num--;
		}
		LeaveCriticalSection( &CS1);
	}

	int getVideoClientHeartBeatnum(int i)
	{
		int j=0;
		EnterCriticalSection( &CS1);
		if(i<video_clients.size()){
			j=video_clients[i].num;
		}
		LeaveCriticalSection( &CS1);
		return j;
	}

	

	void addVideoClient(Client client)
	{
		EnterCriticalSection( &CS1);
		//if(!clientExist(client))
		client.num=10000;
		video_clients.push_back(client);
		LeaveCriticalSection( &CS1);
	}
	
	void addAudioClient(Client client)
	{
		EnterCriticalSection( &CS2);
		//if(!clientExist(client))
		client.num=1000;
		audio_clients.push_back(client);
		LeaveCriticalSection( &CS2);
	}



	void removeVideoClient(Client client)
	{
		EnterCriticalSection( &CS1);
		vector<Client>::iterator itr = video_clients.begin();
		int i=0;
		while(itr!=video_clients.end())
		{
			if(video_clients[i].user==client.user)
			{
				video_clients.erase(itr);
				LeaveCriticalSection( &CS1);
				return;
			}
			i++;
			itr++;
		}
		LeaveCriticalSection( &CS1);
	}

	void removeAudioClient(Client client)
	{
		EnterCriticalSection( &CS2);
		vector<Client>::iterator itr = audio_clients.begin();
		int i=0;
		while(itr!=audio_clients.end())
		{
			if(audio_clients[i].user==client.user)
			{
				audio_clients.erase(itr);
				LeaveCriticalSection( &CS2);
				return;
			}
			i++;
			itr++;
		}
		LeaveCriticalSection( &CS2);
	}




	bool hasVideoClients()
	{
		bool flag=false;
		EnterCriticalSection( &CS1);
		if(video_clients.size()>0)
			flag=true;
		LeaveCriticalSection( &CS1);
		return flag;
	}

	bool hasAudioClients()
	{
		bool flag=false;
		EnterCriticalSection( &CS2);
		if(audio_clients.size()>0)
			flag=true;
		LeaveCriticalSection( &CS2);
		return flag;
	}

	int startGetData(std::string server_ip)
	{
		EnterCriticalSection( &CS3);
		if(!is_started)
		{
			if(is_connect_ipc)
			{
				unsigned char* pwd = new  unsigned char[password.size()+1];
				strcpy((char *)pwd,password.c_str());
				//startGetDataFromIPC(string_to_char(ipc_ip) , string_to_char(username) , pwd , string_to_char(server_ip), server_recv_port,ipc_port,ipc_id);
				startGetDataFromIPC(const_cast<char *>(ipc_ip.c_str()) , const_cast<char *>(username.c_str()) , pwd , const_cast<char *>(server_ip.c_str()), server_recv_port,ipc_port,&login_id);
				is_started=true;
				delete pwd;
			}
			else
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

					SOCKADDR_IN addrSrv;
					addrSrv.sin_addr.S_un.S_addr=inet_addr(ipc_ip.c_str());  //服务器的地址
					addrSrv.sin_family=AF_INET;
					addrSrv.sin_port=htons(ipc_port);

					SOCKET sock_request_video;    //客户端socket
					sock_request_video=socket(AF_INET, SOCK_DGRAM,0);
					SOCKADDR_IN addr_recv;
					addr_recv.sin_family = AF_INET;
					addr_recv.sin_port = htons(server_recv_port);     //固定客户端发命令的端口号
					addr_recv.sin_addr.s_addr = htonl(INADDR_ANY);
					bind(sock_request_video,(sockaddr*)&addr_recv,sizeof(SOCKADDR)); 

					
					std::string command="0,"+username+","+password;           
					int ret1=sendto(sock_request_video,command.c_str(),command.length()+1,0,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));//发送指令

					if(ret1)
					{
						std::cout<<"发送摄像机视频数据的请求成功"<<std::endl;
						closesocket(sock_request_video);
					}
					else
					{
						std::cout<<"发送摄像机视频数据的请求失败"<<std::endl;
					}


					SOCKET sock_request_audio;    //客户端socket
					sock_request_audio=socket(AF_INET, SOCK_DGRAM,0);
					SOCKADDR_IN addr_recv_audio;
					addr_recv_audio.sin_family = AF_INET;
					addr_recv_audio.sin_port = htons(server_recv_port+1);     //固定客户端发命令的端口号
					addr_recv_audio.sin_addr.s_addr = htonl(INADDR_ANY);
					int r=bind(sock_request_audio,(sockaddr*)&addr_recv_audio,sizeof(SOCKADDR));
					printf("----first bind:%d\n",r);

					command="5,"+username+","+password;
					int ret2=sendto(sock_request_audio,command.c_str(),command.length()+1,0,(SOCKADDR*)&addrSrv,sizeof(SOCKADDR));//发送指令

					if(ret2)
					{
						std::cout<<"发送摄像机音频数据的请求成功"<<std::endl;
						closesocket(sock_request_audio);
					}
					else
					{
						std::cout<<"发送摄像机音频数据的请求失败"<<std::endl;
					}
					
					is_started=true;
			}

		}
		LeaveCriticalSection( &CS3);	
	}


	int restartGetData(std::string server_ip)
	{
		EnterCriticalSection( &CS3);
		if(!is_started)
		{
			if(is_connect_ipc)
			{
				unsigned char* pwd = new  unsigned char[password.size()+1];
				strcpy((char *)pwd,password.c_str());
				//startGetDataFromIPC(string_to_char(ipc_ip) , string_to_char(username) , pwd , string_to_char(server_ip), server_recv_port,ipc_port,ipc_id);
				restart(const_cast<char *>(ipc_ip.c_str()) , const_cast<char *>(username.c_str()) , pwd , const_cast<char *>(server_ip.c_str()), server_recv_port,ipc_port,&login_id);
				is_started=true;
				delete pwd;
			}
		}
		LeaveCriticalSection( &CS3);
		return 0;
	}

	void stopGetData(std::string server_ip)
	{
		EnterCriticalSection( &CS3);
		if(is_started)
		{
			::stopGetDataFromIPC(login_id,const_cast<char *>(server_ip.c_str()),server_recv_port);
			is_started=false;
		}
		LeaveCriticalSection( &CS3);
	}


	bool isStarted(){
		EnterCriticalSection( &CS3);
		bool reuslt=is_started;
		LeaveCriticalSection( &CS3);
		return reuslt;
	}
	void getVideoClientInfos(vector<Client*>& cls)
	{
		
		EnterCriticalSection( &CS1);
		for(int i=0;i<video_clients.size();i++)
			cls.push_back(&video_clients[i]);
		LeaveCriticalSection( &CS1);
		return;
	}

	void getAudioClientInfos(vector<Client*>& cls)
	{
		
		EnterCriticalSection( &CS2);
		for(int i=0;i<audio_clients.size();i++)
			cls.push_back(&audio_clients[i]);
		LeaveCriticalSection( &CS2);
		return;
	}




	void updateHeartBeat(string username)
	{
		EnterCriticalSection( &CS1);
		for(int i=0;i<video_clients.size();i++)
		{
			if(video_clients[i].user==username)
			{
				video_clients[i].num=10000;
				break;
			}
		}
		LeaveCriticalSection( &CS1);
		return;
	}


private:
	bool videoClientExist(Client client)
	{
		bool flag=false;
		for(int i=0;i<video_clients.size();i++)
		{
			if(video_clients[i].user==client.user)
				return true;
		}
		return flag;
	}
};

#endif