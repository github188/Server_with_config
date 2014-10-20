#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pq.h"

KeyValue *key_value_new(int key, long id, int sqnum, int timestamp, int pkgsize)
{
	KeyValue *pkv = (KeyValue *)malloc(sizeof(KeyValue));
	pkv->key = key;
	pkv->id = id;
	pkv->sqnum = sqnum;
	pkv->timestamp = timestamp;
	pkv->pkgsize = pkgsize;
	pkv->isretran=false;
	return pkv;
}



void key_value_free(KeyValue *kv, void (*freevalue)(void*))
{
	if(kv)
	{
		if(freevalue)
		{
			freevalue(kv->value);
		}
		free(kv);
	}
}

//初始化一个队列
PriorityQueue::PriorityQueue(int priority)
{
	InitializeCriticalSection(&CS);
	capacity = 11;
	size = 0;
	priority = priority;
	nodes = (KeyValue **)malloc(sizeof(KeyValue *)*capacity);
}

void PriorityQueue::priority_queue_free(void (*freevalue)(void *))
{
	int i;
	for(i = 0; i< size; ++i)
			key_value_free(nodes[i],freevalue);
	free(nodes);
}

KeyValue *PriorityQueue::priority_queue_top()
{
	if(size > 0)
		return nodes[0];
	return NULL;
}

KeyValue *PriorityQueue::priority_queue_dequeue()
{
	EnterCriticalSection( &CS);
	//printf("11111111111");
	KeyValue *pkv = NULL;
	if(size > 0)
	{
		//printf("------------------------current top id:%p,size:%d\n",priority_queue_top(),priority_queue_size());
		pkv = nodes[0];
		priority_queue_adjust_head();
		//printf("current top id:%p\n",priority_queue_top());
	}
	//printf("22222222222");
	LeaveCriticalSection( &CS);
	return pkv;
}

void PriorityQueue::priority_queue_enqueue(KeyValue *kv)
{
	EnterCriticalSection( &CS);
	//printf("33333333333");
	nodes[size] = kv;
	priority_queue_adjust_tail();
	if(size >= capacity)
		priority_queue_realloc();
	//printf("44444444444");
	LeaveCriticalSection( &CS);
}

int PriorityQueue::priority_queue_size()
{
	return size;
}

int PriorityQueue::priority_queue_empty()
{
	return size <= 0;
}

void PriorityQueue::priority_queue_print()
{
	int i;
	KeyValue *kv;
	printf("data in the pq->nodes\n");
	for(i = 0; i < size; ++i)
		printf("%d ", nodes[i]->key);
	printf("\n");
	
	printf("dequeue all data\n");
	while(!priority_queue_empty())
	{
            	kv = priority_queue_dequeue();
            	printf("%d ", kv->key);
      	}
      	printf("\n");
}

KeyValue *PriorityQueue::priority_queue_find_by_id(int id)
{
	KeyValue *kv = NULL;
	int i;

	for(i = 0; i< size; i++)
	{
		if(nodes[i]->id == id){
			kv = nodes[i];
			break;
		}
	}
	return kv;
}

int PriorityQueue::priority_queue_delete_by_id( int id)
{
	int i;
	int result = -1;
        for(i = 0; i< size; i++)
        {
                if(nodes[i]->id == id){
                        result = i;
                        break;
                }
        }
	if(result == -1) return result;
	else{
		priority_queue_swap(nodes, result, size -1);
		size--;
		percolateDown( result);
	}
	return result;
}

void PriorityQueue::percolateDown(int pos)
{
	int child;
	KeyValue *tmp = nodes[pos];

	for(; pos*2 + 2 <= size; pos = child ){
		child = pos*2 +1;
		if(child != size-1 && priority_queue_compare(child+1, child)==1)
			child++;
		if(priority_queue_compare(child,pos)) nodes[pos]=nodes[child];
		else break;
	}
	nodes[pos] = tmp;
}

void PriorityQueue::priority_queue_realloc()
{
	capacity = capacity * 2;
	nodes = (KeyValue **)realloc(nodes, sizeof(KeyValue *)* capacity);
}

void PriorityQueue::priority_queue_adjust_head()
{
	int i,j,parent,left,right;

	i=0,j=0;
	parent = left = right = 0;

	priority_queue_swap(nodes, 0, size - 1);
	//key_value_free(nodes[size-1],freevalue);
	//printf("swap id:%d\n",nodes[size-1]->id);
	nodes[size-1]=NULL;
	//printf("node id:%d",nodes[size-1]->id);
	size--;
	while(i<(size -1)/2)
	{
		parent = i;
		left = 2*i;
		right = left + 1;
		j = left;
		if(priority_queue_compare(left,right)>0)
			j++;
		if(priority_queue_compare(parent,j)>0)
		{
			priority_queue_swap(nodes,i,j);
			i = j;
		}
		else break;
	}
}

void PriorityQueue::priority_queue_adjust_tail()
{
	int i, parent, child;

	i = size - 1;
	size++;
	while(i>0)
	{
		child = i;
		parent = (child -1)/2;

		if(priority_queue_compare(parent, child) > 0)
		{
			priority_queue_swap(nodes, child, parent);
			i = parent;
		}
		else break;
	}
}

int PriorityQueue::priority_queue_compare(int pos1, int pos2)
{
      int adjust = -1;
      int r = nodes[pos1]->key - nodes[pos2]->key;
      if(priority == PRIORITY_MAX)
            r *= adjust;
      return r;
}

void PriorityQueue::priority_queue_swap(KeyValue **nodes, int pos1, int pos2)
{
      KeyValue *temp = nodes[pos1];
      nodes[pos1] = nodes[pos2];
      nodes[pos2] = temp;
}

void PriorityQueue::priority_pop_all()
{
	while(size>0)
		priority_queue_dequeue();
}

bool PriorityQueue::isInSchedule(KeyValue pv)
{
	/*for(int i=0;i<buffqueue.size();i++){
		if(buffqueue.ge)
	}*/
	return false;
}