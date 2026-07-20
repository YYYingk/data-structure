#include<stdio.h>
#include<stdlib.h>
#include"thread_BTree.h"

ThreadBTree* createTBTree(BTnode* root)
{
	ThreadBTree* tree = malloc(sizeof(ThreadBTree));
	if (tree == NULL)
	{
		fprintf(stderr, "create failed!\n");
		return NULL;
	}
	if (root)
	{
		tree->root = root;
		tree->cnt = 1;
	}
	else
	{
		tree->root = NULL;
		tree->cnt = 0;
	}
	return tree;
}

BTnode* createTBTreenode(Element e)
{
	BTnode* node = malloc(sizeof(BTnode));
	if (node == NULL)
	{
		fprintf(stderr, "create failed!\n");
		return NULL;
	}
	node->data = e;
	node->left = node->right = NULL;
	node->lfTag = node->riTag = 0;

	return node;
}

void insertTBTree(ThreadBTree* tree, BTnode* parent, BTnode* left, BTnode* right)
{
	if (tree && parent)
	{
		parent->left = left;
		parent->right = right;
		if (left)
		{
			tree->cnt++;
		}
		if (right)
		{
			tree->cnt++;
		}
	}
}

void visitTBTree(BTnode* node)
{
	if (node)
	{
		printf("\t%c", node->data);
	}
}

static BTnode* pre = NULL;
static void inOrderThreading(BTnode* node)//*************
{
	if (node)
	{
		inOrderThreading(node->left);// 先递归左
		if (node->left == NULL)
		{
			node->left = pre;
			node->lfTag = 1;
		}
		if (pre && pre->right == NULL)
		{
			// 因为有前面的递归，所以此处总是在node的后驱上，所以pre会紧跟node
			pre->right = node;
			pre->riTag = 1;
		}
		pre = node;// 暂存上个节点
		inOrderThreading(node->right);// 再递归右
	}
}

void inOrderThreadingBTree(ThreadBTree* tree)
{
	if (tree)
	{
		inOrderThreading(tree->root);
	}
}

void inOrderTBTree(ThreadBTree* tree)
{
	BTnode* node = tree->root;
	while (node)
	{
		// 一直往左走
		while (node->lfTag == 0)
		{
			node = node->left;
		}
		// 找到中序线索化的结果起点
		visitTBTree(node);
		// 一直往右走进行中序线索化的结果展示
		while (node->riTag && node->right)
		{
			node = node->right;
			visitTBTree(node);
		}
		// 将这个不是右线索化的节点，当做新节点，再进行循环
		node = node->right;
	}
}

static void freeBTnode(ThreadBTree* tree,BTnode* node)
{
	if (node)
	{
		if (node->lfTag == 0)
			freeBTnode(tree, node->left);
		if (node->riTag == 0)
			freeBTnode(tree, node->right);
		free(node);
		tree->cnt--;
	}
}

void releaseTBTree(ThreadBTree* tree)
{
	if (tree->root)
	{
		freeBTnode(tree, tree->root);
	}
}