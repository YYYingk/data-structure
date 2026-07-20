#include<stdio.h>
#include"ArrayStack.h"
#include<stdlib.h>
#include"binary_treeTravel.h"

TreeHead* createBinaryTree(TreeNode* root)
{
	TreeHead* Tree = malloc(sizeof(TreeHead));
	if (Tree == NULL)
	{
		fprintf(stderr, "tree malloc failed!\n");
		return NULL;
	}
	if (root)
	{
		Tree->root = root;
		Tree->cnt = 1;
	}
	else
	{
		Tree->root = NULL;
		Tree->cnt = 0;
	}
	return Tree;
}

TreeNode* createBinaryTreeNode(element_t e)
{
	TreeNode* node = malloc(sizeof(TreeNode));
	node->data = e;
	node->left = node->right = NULL;
	return node;
}

void insertBinaryTree(TreeHead* tree, TreeNode* parent, TreeNode* left, TreeNode* right)
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

void visitCruurentTreeNode(const TreeNode* node)
{
	if (node)
	{
		printf("\t%c", node->data);
	}
}

static void preOrderNode(const TreeNode* node) // 递归
{
	if (node)
	{
		visitCruurentTreeNode(node);
		preOrderNode(node->left);
		preOrderNode(node->right);
	}
}

static void inOrderNode(const TreeNode* node)
{
	if (node)
	{
		inOrderNode(node->left);
		visitCruurentTreeNode(node);
		inOrderNode(node->right);
	}
}

static void postOrderNode(const TreeNode* node)
{
	if (node)
	{
		postOrderNode(node->left);
		postOrderNode(node->right);
		visitCruurentTreeNode(node);
	}
}

void preOrderBTree(const TreeHead* tree)
{
	preOrderNode(tree->root);
	printf("\n");
}

void inOrderBTree(const TreeHead* tree)
{
	inOrderNode(tree->root);
	printf("\n");
}

void postOrderBTree(const TreeHead* tree)
{
	postOrderNode(tree->root);
	printf("\n");
}

/* 广度遍历 
1、引入一个任务队列，先把根节点入队列
2、从任务队列中，取出一个节点、处理它（访问）
3、如果2步骤节点，有左就入队，有右就入队
4、重复第2步
*/
void levelOrderBTree(const TreeHead* tree)
{
	// 申请一个任务队列、用顺序存储、循环队列、
	// 不用链式是考虑到此处队列用完就毫无意义了，用链式会牺牲效率
#define MaxQueueSize 8
	TreeNode* queue[MaxQueueSize];
	int rear = 0, front = 0;

	// 初始化系统
	front = rear = 0;
	queue[rear] = tree->root;
	rear = (rear + 1) % MaxQueueSize;

	// 开始循环系统处理事务
	while (rear != front)
	{
		TreeNode* node = queue[front];
		front = (front + 1) % MaxQueueSize;
		visitCruurentTreeNode(node);
		if (node->left)
		{
			queue[rear] = node->left;
			rear = (rear + 1) % MaxQueueSize;
		}
		if (node->right)
		{
			queue[rear] = node->right;
			rear = (rear + 1) % MaxQueueSize;
		}
	}
}


/* 非递归实现先序遍历
* 1、先序的结果是当前节点，再左节点，再右节点，把栈当做任务的暂存空间
* 2、先压右再压左，一旦弹栈，出现的是左节点
* 3、基本步骤
* 3.1、***初始化***
*	先将根节点压栈
* 3.2、***循环处理任务***
*	弹栈后，访问弹栈节点判断节点有右先压右，有左先压左，保证先右后左
*	循环出栈，直到栈内无元素
*/
void preOrderBtreeNoRecursion(const TreeHead* tree)
{
	ArrayStack stack;
	initArrayStack(&stack);
	pushArrayStack(&stack, tree->root);

	TreeNode* node;
	while (!isEmptyArrayStack(&stack))
	{
		node = getTopArrayStack(&stack);
		popArrayStack(&stack);
		visitCruurentTreeNode(node);
		if (node->right)
		{
			pushArrayStack(&stack, node->right);
		}
		if (node->left)
		{
			pushArrayStack(&stack, node->left);
		}
	}
}

/* 以根节点开始，整条左边进栈，从栈中弹出节点，开始访问
* 如果这个节点有右孩子，把右孩子当做新节点
* 再次整条边进栈，再弹栈
*/
void inOrderBtreeNoRecursion(const TreeHead* tree)
{
	ArrayStack stack;
	initArrayStack(&stack);
	pushArrayStack(&stack, tree->root);

	TreeNode* node = tree->root;
	while (stack.top > 0 || node)
	{
		if (node) // 先处理一条边，反复传left，直到最后一个没left
		{
			pushArrayStack(&stack, node);
			node = node->left;
		}
		else
		{
			node = getTopArrayStack(&stack);
			popArrayStack(&stack);
			visitCruurentTreeNode(node);
			node = node->right;
		}
	}
}