#include"LinkList.h"
#include<stdio.h>
#include<stdlib.h>

//测试带头结点的链表
void test01()
{
	LinkTable table;
	table.num = 0;
	table.head.next = 0;

	for (int i = 0; i < 5; i++)
	{
		//insertHeadTable(&table, i + 100);
		insertRearTable(&table , i + 100);
	}
	showLinkTable(&table);
	insertPosTable(&table, 2, 500);
	showLinkTable(&table);
	deleteValueTable(&table, 500);
	showLinkTable(&table);
	deleteAllLinkTable(&table);
}

void test02()
{
	LinkList List;
	List.num = 0;
	List.ptr_head = NULL;

	for (int i = 0; i < 5; i++)
	{
		insertHeadList(&List, i + 200);
	}
	insertPosList(&List, 2, 500);
	showLinkList(&List);
	deleteValueList(&List, 204);
	showLinkList(&List);
	deleteAllLinkList(&List);
}

void test03()
{
	Lnode* head = NULL;
	for (int i = 0; i < 5; i++)
	{
		head = insertLink(head, 10 + i);
	}

	Lnode* p = head;
	while (p)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	test01();
	//test02();
	//test02();

	return 0;
}