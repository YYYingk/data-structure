#pragma once
typedef int element_t;
typedef struct dnode
{
	struct dnode* prev;
	element_t data;
	struct dnode* next;
} DNode;

// 带头结点的双向循环链表表头
typedef struct
{
	DNode head;
	int num;
} DLoopList;

void initDLoopList(DLoopList *loop_link);
void insertDLoopLinkHead(DLoopList* loop_link, element_t v);
void insertDLoopLinkRear(DLoopList* loop_link, element_t v);
void showDLoopLink(const DLoopList* loop_link);

void deleteValueDLoopList(DLoopList* loop_link, element_t v);
void deleteAllDLoopList(DLoopList* loop_link);