#pragma once
/* 链式表 数据结构定义 先定义节点 */
typedef int element_t;
typedef struct link_node
{
	element_t data;
	struct link_node* next;
} Lnode;

/* 带头结点的链表 */
typedef struct
{
	Lnode head;
	int num;
} LinkTable;

/* 带头指针的链表 */
typedef struct
{
	Lnode* ptr_head;
	int num;
} LinkList;

/* 带头节点的单向链表 接口 */
void insertHeadTable(LinkTable *table, element_t v);				// 头插
void insertRearTable(LinkTable* table, element_t v);				// 尾插
void insertPosTable(LinkTable* table, int pos, element_t v);		// 在指定pos位置插入

void deleteValueTable(LinkTable* table, element_t v);				//删除指定值
void deleteAllLinkTable(LinkTable* table);							//删除所有数据节点
void showLinkTable(const LinkTable* table);							//显示

/* 带头指针的链表 接口 */
void insertHeadList(LinkList *List, element_t v);					// 头插
void insertRearList(LinkList *List, element_t v);					// 尾插
void insertPosList(LinkList* List, int pos, element_t v);			// 在指定pos位置插入

void deleteValueList(LinkList* List, element_t v);					// 删除指定值
void deleteAllLinkList(LinkList* List);
void showLinkList(const LinkList* List);							// 显示


Lnode *insertLink(Lnode *head, element_t v);
