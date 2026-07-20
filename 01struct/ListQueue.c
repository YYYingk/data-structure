#include<stdio.h>
#include<stdlib.h>
#include"ListQueue.h"

LinkHNode* createLinkQueue()
{
	LinkHNode* queue = malloc(sizeof(LinkHNode));
	if (queue == NULL)
	{
		return NULL;
	}
	queue->front = queue->rear = NULL; 
	queue->cnt = 0;

	return queue;
}

void releaseLinkQueue(LinkHNode* queue)
{
	if (queue == NULL) return;
	LQnode* p = queue->front;
	while(p)
	{
		LQnode* tmp = p;
		p = p->next;
		free(tmp);
		--queue->cnt;
	}
	printf("now queue is %d\n", queue->cnt);
	free(queue);
}

int enLinkQueue(LinkHNode* queue, value_t e)
{
	LQnode* newNode = malloc(sizeof(LQnode));
	if (newNode == NULL)
	{
		return -1;
	}
	newNode->data = e;
	newNode->next = NULL;

	if (queue->rear == NULL)// 对第一次特判
	{
		queue->rear = newNode;
		queue->front = newNode; 
	}
	else
	{
		queue->rear->next = newNode;
		queue->rear = newNode;
	}
	++queue->cnt;
	 
	return 0;
}

int deLinkQueue(LinkHNode* queue, value_t* e)
{
	if (queue->front == NULL)			// 若为空队列的特判
	{
		return -1;
	}
	LQnode* tmp = queue->front;
	*e = tmp->data;
	queue->front = queue->front->next;
	if (queue->front == NULL)	// 最后一个节点的特判
	{
		queue->rear = NULL;
	}
	free(tmp);
	queue->cnt--;
	return 0;
}