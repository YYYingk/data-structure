#include"DoubleLoopList.h"
#include<stdio.h>
#include<stdlib.h>

void initDLoopList(DLoopList* loop_link, element_t v)
{
	loop_link->head.next = &loop_link->head;
	loop_link->head.prev = &loop_link->head;
	loop_link->num = 0;
}

/* 定义通用的辅助函数接口 插入，删除 */
static void addDNode(DNode* new_node, DNode *prev, DNode *next)
{
	next->prev = new_node;
	new_node->next = next;
	new_node->prev = prev;
	prev->next = new_node;
}

static void delDNode(DNode* prev, DNode* next)
{
	next->prev = prev;
	prev->next = next;
}

void insertDLoopLinkHead(DLoopList* loop_link, element_t v)
{
	DNode* new_node = malloc(sizeof(DNode));
	new_node->data = v;
	addDNode(new_node, &loop_link->head, loop_link->head.next);
	++loop_link->num;
}

void insertDLoopLinkRear(DLoopList* loop_link, element_t v)
{
	DNode* new_node = malloc(sizeof(DNode));
	new_node->data = v;
	addDNode(new_node, loop_link->head.prev, &loop_link->head);
	++loop_link->num;
}

void showDLoopLink(const DLoopList* loop_link)
{
	DNode* p = loop_link->head.next;
	printf("table[%d] : ", loop_link->num);
	while (p != &loop_link->head)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

void deleteValueDLoopList(DLoopList* loop_link, element_t v)
{
	DNode* p = loop_link->head.next;
	while (p != &loop_link->head)
	{
		if (p->data == v)
		{
			delDNode(p->prev,p->next);
			free(p);
			--loop_link->num;
			return;
		}
		p = p->next;
	}
	printf("Not found\n");
}

void deleteAllDLoopList(DLoopList* loop_link)
{
	DNode* p = loop_link->head.next;
	while (p != &loop_link->head)
	{
		DNode* tmp = p->next;
		free(p);
		p = tmp;
		--loop_link->num;
	}
	loop_link->head.next = &loop_link->head;
	loop_link->head.prev = &loop_link->head;
	printf("table num : %d", loop_link->num);
}