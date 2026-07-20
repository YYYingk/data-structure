#include<stdio.h>
#include<stdlib.h>
#include"avlTree.h"

AVLTree* createAvlTree()
{
	AVLTree* tree = malloc(sizeof(AVLTree));
	if (tree == NULL)
	{
		return NULL;
	}
	tree->cnt = 0;
	tree->root = NULL;

	return tree;
}

void releaseAVLTree(AVLTree* tree)
{

}

void visitAVLNode(const AVLNode* node)
{
	if (node)
	{
		printf("\t<%d:%d>", node->data, node->height);
	}
}

static void inOrderAVLNode(AVLNode* node)
{
	if (node)
	{
		inOrderAVLNode(node->left);
		visitAVLNode(node);
		inOrderAVLNode(node->right);
	}
}

void inOrderAVLTree(AVLTree* tree)
{
	if (tree)
	{
		inOrderAVLNode(tree->root);
		printf("\n");
	}
}

int heightAVLTree(AVLTree* tree)
{
	if (tree)
	{
		return tree->root->height;
	}
	return 0;
}

static int maxNum(int a, int b)
{
	return (a > b) ? a : b;
}

static int h(AVLNode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	return node->height;
}

/* 左旋操作
*		px
*		|
*		x
*	  /   \
*	 lx    y
*		  / \
*		 ly  ry
* 
*/

static AVLNode* leftRotate(AVLNode* x)
{
	AVLNode* y = x->right; // 新根节点
	x->right = y->left;
	y->left = x;

	x->height = maxNum(h(x->left),h(x->right)) + 1; // 不可搞乱顺序，因为x降级了，y会被x的高度给影响
	y->height = maxNum(h(y->left), h(y->right)) + 1;
	return y;
}

/* 右旋操作
*		py
*		|
*		y
*	  /   \
*	 x	   ry
*   / \
*  lx  rx
* 
*/

static AVLNode* rightRotate(AVLNode* y)
{
	AVLNode* x = y->left;
	y->left = x->right;
	x->right = y;

	y->height = maxNum(h(y->left), h(y->right)) + 1;
	x->height = maxNum(h(x->left), h(x->right)) + 1;
	return x;
}

static int getBalance(AVLNode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	return h(node->left) - h(node->right);
}

static AVLNode* createAVLNode(int data)
{
	AVLNode* node = malloc(sizeof(AVLNode));
	if (node == NULL)
	{
		return NULL;
	}
	node->data = data;
	node->left = node->right = NULL;
	node->height = 1;
	return node;
}

static AVLNode* insertAVLNode(AVLTree* tree, AVLNode* node, element e)
{
	// 1.递归的初始化位置
	if (node == NULL)
	{
		tree->cnt++;
		return createAVLNode(e);
	}
	// 1.1 递的过程
	if (e < node->data)
	{
		node->left = insertAVLNode(tree, node->left, e);
	}
	else if(e>node->data)
	{
		node->right = insertAVLNode(tree, node->right, e);
	}
	else
	{
		return node;
	}
	// 2 运行到这里的代码，已经到归的过程了，更新这条路线上的节点高度，同时监测平衡因子
	// 2.1更新归过程中节点的高度
	node->height = maxNum(h(node->left), h(node->right)) + 1;
	// 2.2。计算平衡因子
	int balance = getBalance(node);
	if (balance > 1)// 如果失衡
	{
		// 失衡点子节点是L还是R，LL or LR
		if (e > node->left->data) // 左边的节点的右边
		{
			// LR
			node->left = leftRotate(node->left);
		}
		// LL
		return rightRotate(node); // LL的统一处理
	}
	else if (balance < -1)// 如果失衡
	{
		if (e < node->right->data) // 右边的节点的左边
		{
			// RL
			node->right = rightRotate(node->right);
		}
		// RR
		return leftRotate(node);
	}
	return node;
}

void insertAVLTree(AVLTree* tree, element data)
{
	if (tree)
	{
		tree->root = insertAVLNode(tree,tree->root, data);
	}
}

static AVLNode* deleteAVLNode(AVLTree* tree, AVLNode* node, element e)
{
	if (node == NULL)
	{
		return NULL;
	}
	if (e < node->data)
	{
		node->left = deleteAVLNode(tree, node->left, e);
	}
	else if (e > node->data)
	{
		node->right = deleteAVLNode(tree, node->right, e);
	}
	else
	{
		// 找到e值元素
		AVLNode* tmp;
		if (node->left == NULL || node->right == NULL)
		{
			tmp = node->left ? node->left : node->right;
			if (tmp == NULL)
			{
				// 度为0,直接删除
				tree->cnt--;
				free(node);
				return NULL;
			}
			// 度为1，将tmp的值直接替换成node
			node->data = tmp->data;
			node->left = tmp->left;
			node->right = tmp->right;
			tree->cnt--;
			free(tmp);
		}
		else
		{
			// 度为2,找前驱
			tmp = node->left;
			while (tmp->right)
			{
				tmp = tmp->right;
			}
			node->data = tmp->data;
			node->left = deleteAVLNode(tree, node->left, tmp->data);//删除前驱
		}
	}
	// 2. 归的过程中，更新各节点高度和平衡因子
	node->height = 1 + maxNum(h(node->left), h(node->right));
	int balance = getBalance(node);
	if (balance > 1)
	{
		// L
		if (getBalance(node->left) < 0)
		{
			// R
			node->left = leftRotate(node->left);
		}
		return rightRotate(node);
	}
	if (balance < -1)
	{
		// L
		if (getBalance(node->right) > 0)
		{
			// R
			node->right = rightRotate(node->right);
		}
		return leftRotate(node);
	}
	return node;
}

/* 平衡二叉树中删除元素e
* 1. 按照二叉搜索树的规则，递归找到元素e的节点
* 2. 判断度的情况，是否转移矛盾
* 3. 归的过程中，根据平衡因子进行调整
* 
*/
void deleteAVLTree(AVLTree* tree, element e)
{
	if (tree)
	{
		tree->root = deleteAVLNode(tree, tree->root, e);
	}
}
