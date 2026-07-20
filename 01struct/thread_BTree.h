#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int Element;
typedef struct treeNode
{
	Element data;
	struct treeNode* left;
	struct treeNode* right;
	int lfTag;			// left为0则指向空，为1则指向前驱
	int riTag;
} BTnode;

typedef struct
{
	BTnode* root;
	int cnt;
}ThreadBTree;

ThreadBTree* createTBTree(BTnode* root);
void releaseTBTree(ThreadBTree* tree);

BTnode* createTBTreenode(Element e);
void insertTBTree(ThreadBTree* root, BTnode* parent, BTnode* left, BTnode* right);
void visitTBTree(BTnode* node);

// 中序线索化的过程
void inOrderThreadingBTree(ThreadBTree* tree);

// 中序线索化的遍历结果
void inOrderTBTree(ThreadBTree* tree);