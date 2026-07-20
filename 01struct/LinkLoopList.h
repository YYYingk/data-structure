#pragma once
typedef int element_t;

typedef struct Linknode
{
	element_t data;
	struct Linknode* next;
}Lnode;

typedef struct
{
	Lnode head;
	int num;
	Lnode* rear;
}LinkLoop;

// 静态初始化表头
void initLinkLoop(LinkLoop* link_loop);
// 插入，头插尾插
void insertLinkLoopHeader(LinkLoop* link_loop, element_t v);
void insertLinkLoopRear(LinkLoop* link_loop, element_t v);

// 删除
int deleteLinkLoop(LinkLoop *link_loop, element_t v);
void deleteAllLinkLoop(LinkLoop* link_loop);

// 遍历
void showLinkLoop(const LinkLoop *link_loop);



/* JosephRing的节点结构 */
typedef struct node
{
	int data;
	struct node* next;
}Node;
/* Joseph的表头结构 不包含头结点 */
typedef struct
{
	Node* head;
	Node* tail;
}JosephHead;

// 初始化JosephRing的n个节点
void init_JoseGame(JosephHead *game, int n);
void showData(const JosephHead* game);
// 开始按照k个步长进行游戏
void start_JosephGame(JosephHead* game, int k);