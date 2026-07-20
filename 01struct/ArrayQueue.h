#pragma once
#include<stdio.h>
typedef int element_t;
#define MaxQueueSize 5

typedef struct
{
	element_t data[MaxQueueSize];
	int front;
	int rear;
} ArrayQueue;

void initArrayQueue(ArrayQueue* q);

int isFullArrayQueue(ArrayQueue* q);
int isEmptyArrayQueue(ArrayQueue* q);

void enqArrayQueue(ArrayQueue* q, element_t v);
void deArrayQueue(ArrayQueue* q);
element_t getfrontArrayQueue(ArrayQueue* q);
