#pragma once
typedef int value_t;

typedef struct que_node
{
	value_t data;
	struct que_node* next;
} LQnode;

typedef struct
{
	LQnode* front;
	LQnode* rear;
	int cnt;
} LinkHNode;

// 在栈内对队列初始化
LinkHNode* createLinkQueue();
void releaseLinkQueue(LinkHNode* queue);

int enLinkQueue(LinkHNode* queue, value_t e);
int deLinkQueue(LinkHNode* queue, value_t* e);