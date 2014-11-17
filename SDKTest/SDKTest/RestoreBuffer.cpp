#include "RestoreBuffer.h"

void RestoreBuffer::init(int size){
	m_size=size;
	m_restore_cells=std::vector<RestoreCell>(m_size);
	int j=0;
	while(j<m_size){
		//m_restore_cells[j]=RestoreCell();
		m_restore_cells[j].isempty=true;
		j++;
	}
	InitializeCriticalSection(&CS);
	return;
}

void RestoreBuffer::writeData(RestoreCell* rc){
	EnterCriticalSection( &CS);
	int tid=rc->id%m_size;
	if(!m_restore_cells[tid].isempty){
		//printf("replace %d\n",tid);
	}
	m_restore_cells[tid].id=rc->id;
	m_restore_cells[tid].size=rc->size;
	m_restore_cells[tid].sqnum=rc->sqnum;
	m_restore_cells[tid].timestamp=rc->timestamp;
	memcpy(m_restore_cells[tid].data,rc->data,rc->size+sizeof(long)+sizeof(int));
	m_restore_cells[tid].isempty=false;
	LeaveCriticalSection( &CS);
}



//�˴�������Ѱ�ҵ�id�Ƕ�ʧ����Ϊ��������һ��id
//Ӧ�ø�Ϊ����һ������������
int RestoreBuffer::applyData(long id,int sqnum,int timestamp,RestoreCell* rc){
	
	
	int tid=id%m_size;
	//printf("find %d %d tid:%d\n",sqnum,timestamp,tid);
	EnterCriticalSection( &CS);
	if(m_size<0){
		LeaveCriticalSection( &CS);
		return -1;
	}
	if(m_restore_cells[tid].isempty){
		LeaveCriticalSection( &CS);
		return -1;
	}
	//LeaveCriticalSection( &CS);
	int up,low;
	int flag=0;
	up=tid+1;
	low=tid;
	if(up>=m_size)up=0;
	while(up!=low){
			if(m_restore_cells[up].timestamp==timestamp&&m_restore_cells[up].sqnum== sqnum){
				rc->size=m_restore_cells[up].size;
				memcpy(rc->data,m_restore_cells[up].data,m_restore_cells[up].size+sizeof(long)+sizeof(int));
			    rc->timestamp=m_restore_cells[up].timestamp;
			    rc->sqnum=m_restore_cells[up].sqnum;
				rc->id=m_restore_cells[up].id;
				LeaveCriticalSection( &CS);
				return 0;
		    }
			up++;
			if(up>=m_size)up=0;
		
	}
	LeaveCriticalSection( &CS);
	return -1;
	
}


void RestoreBuffer::clearBuffer(){
	EnterCriticalSection( &CS);
	for(int i=0;i++;i<m_size){
		m_restore_cells[i].isempty=true;
	}
	LeaveCriticalSection( &CS);
}