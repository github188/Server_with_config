#ifndef _PRIORITY_QUEUE_H
#define _PRIORITY_QUEUE_H

#include <windows.h>
/* struct of key vaule */
struct key_value_struct
{
	int key;	// priority
	long id;  //包ID
	int sqnum;
	int timestamp;
	int pkgsize;
	bool isretran;
	int user_id;     //用户id
    //struct timeval send_time;      
	char value[1500];
};
typedef struct key_value_struct KeyValue;

KeyValue *key_value_new(int key, long id, int sqnum, int timestamp, int pkgsize);
void key_value_free(KeyValue *kv, void (*freevalue)(void *));

/* struct for priority queue*/
#define PRIORITY_MAX 1  //最大排前面
#define PRIORITY_MIN 2

class PriorityQueue
{
public:
	KeyValue ** nodes;
	int size;
	int capacity;
	int priority;   //表明这个堆是最大堆还是最小堆，它的值只能是1或者2
public:
	PriorityQueue(int priority);
	void priority_queue_free(void (*freevalue)(void *));
	KeyValue *priority_queue_top();
	KeyValue *priority_queue_dequeue();
	void priority_queue_enqueue( KeyValue *kv);
	int priority_queue_size();
	int priority_queue_empty();
	void priority_queue_print();
	KeyValue *priority_queue_find_by_id( int id);
	int priority_queue_delete_by_id( int id);
	void priority_pop_all();
	bool isInSchedule(KeyValue kv);
private:
	void priority_queue_realloc();
	void priority_queue_adjust_head();
	void priority_queue_adjust_tail();
	int priority_queue_compare(int pos1,int pos2);
	void priority_queue_swap(KeyValue **nodes,int pos1,int pos2);
	void percolateDown( int pos);
	CRITICAL_SECTION CS;
};


#endif
