#include "BuffQueue.h"
BuffQueue::BuffQueue()
{
	InitializeCriticalSection(&CS);
}
BuffQueue::~BuffQueue(){
	DeleteCriticalSection( & CS);
}
int BuffQueue::getdatanum(){
	EnterCriticalSection( &CS);
	int re=buffqueue.size();
	LeaveCriticalSection( &CS);
	return re;
}

package BuffQueue::popdata(){
	EnterCriticalSection( &CS);
	package pkg=buffqueue.front();
	buffqueue.pop();
	LeaveCriticalSection( &CS);
	return pkg;
}

void BuffQueue::pushdata(package pkg){
	EnterCriticalSection( &CS);
	buffqueue.push(pkg);
	LeaveCriticalSection( &CS);

}
