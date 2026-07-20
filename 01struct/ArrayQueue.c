#include<stdio.h>
#include"ArrayQueue.h"

void initArrayQueue(ArrayQueue* q)
{
	q->front = 0;
	q->rear = 0;
}

int isFullArrayQueue(const ArrayQueue* q)
{
	return (q->rear + 1) % MaxQueueSize == q->front;
}

int isEmptyArrayQueue(const ArrayQueue* q)
{
	return q->front == q->rear;
}

void enqArrayQueue(ArrayQueue* q, element_t v)
{
	if (isFullArrayQueue(q))
	{
		printf("Queue is full!\n");
		return;
	}
	q->data[q->rear] = v;
	q->rear = (q->rear + 1) % MaxQueueSize;
}

void deArrayQueue(ArrayQueue* q)
{
	if (isEmptyArrayQueue(q))
	{
		printf("Queue is empty!\n");
		return;
	}
	q->front = (q->front + 1) % MaxQueueSize;
}

element_t getfrontArrayQueue(const ArrayQueue* q)
{
	return q->data[q->front];
}