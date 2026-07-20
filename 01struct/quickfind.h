#pragma once
typedef int element;
typedef struct
{
	element* data;	// 存放具体数据，利用引索来建立数据元素间的关系
	int* groupID;	// 每个元素的组编号，利用索引找到组
	int n;			// 并查集中元素的个数
} QuickFindSet;

QuickFindSet* createQuickkFindSet(int n);
void releaseQuickFindSet(QuickFindSet* set);
void initQuickFindSet(QuickFindSet *set, const element *data,int n);

// 查，判断俩个元素是不是一个组
int isSameQF(QuickFindSet* set, element a, element b);
// 并，合并两个元素
void unionQF(QuickFindSet* set, element a, element b);

