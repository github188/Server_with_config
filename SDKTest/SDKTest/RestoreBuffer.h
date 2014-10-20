#include <vector>
#include <windows.h>
#include "pq.h"

class RestoreCell{
public:
	int sqnum;
	int timestamp;
	char data[1500];
	int size;
	long id;
	bool isempty;
};

class RestoreBuffer{
private:
	std::vector<RestoreCell> m_restore_cells;
	CRITICAL_SECTION CS;
	int m_size;
public:
	void init(int size=60000);
	void writeData(RestoreCell*);
	int applyData(long id,int sqnum,int timestamp,RestoreCell*);
	void clearBuffer();

};

extern RestoreBuffer rsb;
extern DWORD WINAPI RetranTreat(LPVOID lpParameter);
extern PriorityQueue retransQueue;