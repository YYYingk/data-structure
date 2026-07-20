#include "LinkLoopList.h"
#include<stdio.h>
#include<stdlib.h>

static void insertLinkLoop(LinkLoop* link_loop, Lnode* p, element_t v)
{
	Lnode* node = (Lnode*)malloc(sizeof(Lnode));
	if (node == NULL)
	{
		return;
	}
	node->data = v;
	
	node->next = p->next;
	p->next = node;
	if (link_loop->rear == p)//判断是否是第一个元素插入
	{
		link_loop->rear = node;
	}
	++link_loop->num;
}

static void delLinkLoop(LinkLoop* link_loop, Lnode* p)
{
	if (!p || p->next == &link_loop->head)
	{
		return;
	}
	Lnode* tmp = p->next;
	p->next = tmp->next;
	if (tmp == link_loop->rear)//若p下一个节点是尾指针则将尾指针交给p
	{
		link_loop->rear = p;
	}
	free(tmp);
	--link_loop->num;
}

void initLinkLoop(LinkLoop* link_loop)
{
	link_loop->head.next = &link_loop->head;
	link_loop->rear = &link_loop->head;
	link_loop->num = 0;
}

void insertLinkLoopHeader(LinkLoop* link_loop, element_t v)
{
	Lnode* p = link_loop->rear->next;//&link_loop->head也可
	insertLinkLoop(link_loop, p, v);
}

void insertLinkLoopRear(LinkLoop* link_loop, element_t v)
{
	Lnode* p = link_loop->rear;
	insertLinkLoop(link_loop, p, v);
}

int deleteLinkLoop(LinkLoop* link_loop, element_t v)
{
	Lnode* p = &link_loop->head;
	while (p->next != &link_loop->head)
	{
		if (p->next->data == v)
		{
			delLinkLoop(link_loop, p);
			return 1;		//找到
		}
		p = p->next;
	}
	return 0;		//没找到
}

void deleteAllLinkLoop(LinkLoop* link_loop)
{
	Lnode* p = &link_loop->head;
	while (p->next != &link_loop->head)
	{
		delLinkLoop(link_loop, p);
	}
	link_loop->rear = &link_loop->head;
	printf("list num = %d\n", link_loop->num);
}

void showLinkLoop(const LinkLoop* link_loop)
{
	Lnode* p = link_loop->head.next;
	printf("loop_table[%d] : ", link_loop->num);
	while (p != &link_loop->head) //开头已经不是head了
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}




void init_JoseGame(JosephHead* game, int n)
{
	Node* node = NULL;
	for (int i = 1; i <= n; i++)
	{
		node = (Node*)malloc(sizeof(Node));
		node->data = i;
		if (game->head == NULL)//第一次插入
		{
			game->head = game->tail = node;
		}
		else
		{
			game->tail->next = node;//连接
			game->tail = node;
		}
		game->tail->next = game->head;//回头
	}
}

void showData(const JosephHead* game)
{
	Node* p = game->head;
	do {
		printf("%d\t", p->data);
		p = p->next;
	} while (p != game->head);
	printf("\n");
}

void start_JosephGame(JosephHead* game, int k)
{
//	Node* p = game->head;
//	while (1)
//	{
//		int i = 0;
//		for (i = 1; i < k - 1; i++)
//		{
//			p = p->next;
//		}
//		if (p->next->next == p)
//		{
//			printf("end : %d", p->data);
//			break;
//		}
//		Node* tmp = p->next;
//		p->next = tmp->next;
//		p = p->next;
//	}
	Node* fap = game->head; // 指向正在报数的人
	Node* slp = NULL;		// 
	while (fap->next != fap)
	{
		slp = fap;
		// 按照k值报数
		for (int i = 1; i < k; i++)
		{
			slp = fap;
			fap = fap->next;
		}
		// 使用slp删除后一个节点fap
		slp->next = fap->next;
		printf("%d ", fap->data);
		free(fap);
		fap = slp->next;
	}
	printf("\n the last Person : %d\n", fap->data);
	free(fap);
	game->head = game->head = NULL;
}