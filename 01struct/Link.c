#include <stdio.h>
#include"LinkList.h"
#include<stdlib.h>

/* 链式表的通用接口 */
static int insertLnode(Lnode* p, element_t v)
{
	Lnode* node = malloc(sizeof(Lnode));
	if (node == NULL)
	{
		return 0;
	}
	node->data = v;
	node->next = p->next;
	p->next = node;
	return 1;
}

static void showLnode(const Lnode *start)
{
	while (start)
	{
		printf("%d ", start->data);
		start = start->next;
	}
	printf("\n");
}

static void deleteLnode(Lnode* p)
{
	Lnode* tmp = p->next;
	p->next = tmp->next;
	free(tmp);
}

/* ======================================== */

void insertHeadTable(LinkTable* table, element_t v)
{
	Lnode* p = &table->head;
	if (insertLnode(p, v))
	{
		++table->num;
	}
}

void insertPosTable(LinkTable* table, int pos, element_t v)
{
	if (pos < 0||pos > table->num)
	{
		return;
	}
	Lnode* p = &table->head;
	int i = 0;				//找到pos-1的位置
	while (i < pos && p != NULL)
	{
		p = p->next;
		++i;
	}

	if (p && insertLnode(p, v))
	{
		++table->num;
	}

}
void insertRearTable(LinkTable* table, element_t v)
{
	Lnode* p = &table->head;
	while (p->next)
	{
		p = p->next;
	}
	if (insertLnode(p, v))
	{
		++table->num;
	}
}

void deleteValueTable(LinkTable* table, element_t v)
{
	Lnode* p = &table->head;		//把头结点的地址，假设作为前置节点p
	// 站在p，往后看他下一个节点的data是否=v
	while (p && p->next)
	{
		if (p->next->data == v)
		{
			break;
		}
		p = p->next;
	}

	//找到v值前面的的节点首地址
	if (p && p->next)
	{
		deleteLnode(p);
		--table->num;
	} 
}

void deleteAllLinkTable(LinkTable* table)
{
	//以头结点为固定点，相当于删除节点的前置节点，一直删除后面的节点，直到头结点后面为空
	Lnode* p = &table->head;
	while (p->next)
	{
		deleteLnode(p);
		--table->num;
	}
	printf("table->num = %d", table->num);
}

void showLinkTable(const LinkTable* table)
{
	printf("table[%d] : ", table->num);
	Lnode* start = table->head.next;
	showLnode(start);
}

void insertHeadList(LinkList* List, element_t v)
{
	//Lnode* node = malloc(10);
	//if (List->ptr_head == NULL)
	//{
	//	List->ptr_head = node;
	//}
	//else
	//{
	//	node->next = List->ptr_head;
	//	List->ptr_head = node;
	//}
	Lnode head;
	head.next = List->ptr_head;

	Lnode* p = &head;
	if (insertLnode(p, v))
	{
		List->ptr_head = head.next;	//更新指针
		++List->num;
	}
}

void insertRearList(LinkList* List, element_t v)
{
	Lnode head;
	head.next = List->ptr_head;

	Lnode* p = &head;
	while (p->next)					//遍历到最后一个节点
	{
		p = p->next;
	}
	if (insertLnode(p, v))
	{
		List->ptr_head = head.next;
		++List->num;
	}
}

void showLinkList(const LinkList* List)
{
	printf("List[%d] : ", List->num);
	Lnode* start = List->ptr_head;
	showLnode(start);
}

void insertPosList(LinkList* List, int pos, element_t v)
{
	if (pos < 0 || pos > List->num)
	{
		return;
	}
	Lnode head;
	head.next = List->ptr_head;

	Lnode* p = &head;
	int i = 0;				//找到pos-1的位置
	while (i < pos && p != NULL)
	{
		p = p->next;
		++i;
	}

	if (p && insertLnode(p, v))
	{
		++List->num;
	}
}

void deleteValueList(LinkList* List, element_t v)
{
	Lnode head;
	head.next = List->ptr_head;

	Lnode* p = &head;		//把头结点的地址，假设作为前置节点p
	// 站在p，往后看他下一个节点的data是否=v
	while (p && p->next)
	{
		if (p->next->data == v)
		{
			break;
		}
		p = p->next;
	}

	//找到v值前面的的节点首地址
	if (p && p->next)
	{
		deleteLnode(p);
		List->ptr_head = head.next;
		--List->num;
	}
}

void deleteAllLinkList(LinkList* List)
{
	Lnode head;
	head.next = List->ptr_head;

	Lnode* p = &head;
	while (p->next)
	{
		deleteLnode(p);
		--List->num;
	}
	printf("List->num = %d", List->num);
	List->ptr_head = NULL;
}


Lnode* insertLink(Lnode *head, element_t v)
{
	Lnode dummy;
	dummy.next = head;

	Lnode* p = &dummy;
	if (insertLnode(p, v))
	{
		return dummy.next;
	}
	return NULL;
}

