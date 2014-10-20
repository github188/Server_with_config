#include <queue>
#include <windows.h>
class package{
public: 
	int buffsize;
	char buff[1500];
};

class BuffQueue{
private:
	std::queue<package> buffqueue;
	CRITICAL_SECTION CS;
public:
	BuffQueue();
	void pushdata(package pkg);
	package popdata();
	int getdatanum();
	void popall(){
		EnterCriticalSection( &CS);
		while(buffqueue.size()>0)
		buffqueue.pop();
	LeaveCriticalSection( &CS);
	}
	~BuffQueue();
};

