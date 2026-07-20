#include"quickunion.h"
#include<stdio.h>
#include<stdlib.h>
// 核心在父节点
QuickUnionSet* createQuickUnionSet(int n)
{
	QuickUnionSet* set = malloc(sizeof(QuickUnionSet));
	if (set == NULL)
	{
		return NULL;
	}
	set->data = malloc(sizeof(element) * n);
	set->parent = malloc(sizeof(int) * n);
	set->size = malloc(sizeof(int) * n);
	set->n = n;
	
	return set;
}

void releaseQuickUnionSet(QuickUnionSet* set)
{
	if (set)
	{
		if (set->data)
		{
			free(set->data);
		}
		if (set->parent)
		{
			free(set->parent);
		}
		if (set->size)
		{
			free(set->size);
		}
		free(set);
	}
}

void initQuickUnionSet(QuickUnionSet* set, const element* data, int n)
{
	for (int i = 0; i < n; i++)
	{
		set->data[i] = data[i];
		set->parent[i] = i;
		set->size[i] = 1;
	}
}

static int findIndex(const QuickUnionSet* set, element e)
{
	for (int i = 0; i < set->n; i++)
	{
		if (set->data[i] == e)
		{
			return i;
		}
	}
	return - 1;
}

//#define PATH_COMPRESS(路径压缩)
#ifndef PATH_COMPRESS
static int findRootIndex(const QuickUnionSet* set, element e)
{
	int curIndex = findIndex(set, e);
	if (curIndex == -1)
	{
		return -1;
	}
	// 向上遍历，直到父节点与自身索引值一致，那么根节点找到
	while (set->parent[curIndex] != curIndex)
	{
		curIndex = set->parent[curIndex]; // 向上遍历，因为父节点一定是在一条线上的
	}
	return curIndex;
}
#else
static SetNode* push(SetNode* stack, int index)
{
	SetNode* node = malloc(sizeof(SetNode));
	node->index = index;
	node->next = stack;
	return node;
}

static SetNode* pop(SetNode* stack, int* index)
{
	SetNode* tmp = stack;
	*index = stack->index;
	stack = stack->next;
	free(tmp);
	return stack;
}

static int findRootIndex(const QuickUnionSet* set, element e)
{
	int curIndex = findIndex(set, e);
	if (curIndex == -1)
	{
		return -1;
	}
	// 找根的路径，经过的所有节点都 入栈，直到找到根
	SetNode* path = NULL;
	while (set->parent[curIndex] != curIndex)
	{
		path = push(path, curIndex);
		curIndex = set->parent[curIndex];// 找他自己
	}
	// 出栈，将出栈的节点的父指针都指向根节点
	while (path)
	{
		int pos;
		path = pop(path, &pos);
		set->parent[pos] = curIndex;
	}
	return curIndex;
}
#endif
int isSamQU(const QuickUnionSet* set, element a, element b)
{
	int aRoot = findRootIndex(set, a);
	int bRoot = findRootIndex(set, b);
	
	if (aRoot == -1 || bRoot == -1)
	{
		return -1;
	}
	return aRoot == bRoot;
}

/* 将元素a和元素b进行合并
*  1、找到a和b的根节点，原本是b的父节点的值
*  2、引入根节点的size有效规则，谁的根节点多，让另外一个接入元素多的组
*/
void unionQU(QuickUnionSet* set, element a, element b)
{
	int aRoot = findRootIndex(set, a);
	int bRoot = findRootIndex(set, b);
	if (aRoot == -1 || bRoot == -1)
	{
		return;
	}
	if (aRoot != bRoot)// a和b不在一个集合里
	{
		// 根据根节点的索引找到size空间里保存的根所在树的总节点数
		int aSize = set->size[aRoot];
		int bSize = set->size[bRoot];
		if(aSize >= bSize) // 将b元素的根节点指向a元素的根节点
		{
			set->parent[bRoot] = aRoot;
			set->size[aRoot] += set->size[bRoot];
		}
		else
		{
			set->parent[aRoot] = bRoot;
			set->size[bRoot] += set->size[aRoot];
		}
	}
}