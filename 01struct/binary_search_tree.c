 #include<stdio.h>
#include<stdlib.h>
#include "binary_search_tree.h"

BSTree* createBSTree(const char* name)
{
	BSTree* tree = malloc(sizeof(BSTree));
	if (tree == NULL)
	{
		return NULL;
	}
	tree->name = name;
	tree->root = NULL;
	tree->cnt = 0;
	
	return tree;
}

static void freeBSnode(BSTree* tree,BSnode* node)
{
	if (node)
	{
		freeBSnode(tree, node->left);
		freeBSnode(tree, node->right);
		free(node);
		tree->cnt--;
	}
}

void releaseBSTree(BSTree* tree)
{
	if (tree)
	{
		freeBSnode(tree, tree->root);
		printf("there are %d node.\n", tree->cnt);
		free(tree);
	}
}

static BSnode* createBSnode(Element e)
{
	BSnode* node = malloc(sizeof(BSnode));
	if (node == NULL)
	{
		return NULL;
	}
	node->data = e;
	node->left = node->right = NULL;
	return node;
}

static BSnode* insertBSnode(BSTree* tree,BSnode* node, Element e)
{
	if (node == NULL) // 有空就放
	{
		tree->cnt++;
		return createBSnode(e); // 归的条件
	}
	if (e < node->data)
	{
		node->left = insertBSnode(tree,node->left, e);
	}
	else if(e > node->data)
	{
		node->right = insertBSnode(tree,node->right, e);
	}
	return node; // 递归最后的归宿
}

void insertBSTree(BSTree* tree, Element e)
{
#ifdef RECUR
	tree->root = insertBSnode(tree, tree->root, e);
#else 
	//非递归
	BSnode* cur = tree->root;
	BSnode* pre = NULL;
	while (cur)
	{
		pre = cur;
		if (e < cur->data)
		{
			cur = cur->left;
		}
		else if (e > cur->data)
		{
			cur = cur->right;
		}
		else
		{
			return;
		}
	}
	// 可能插入的是第一个根元素
	// 可能插入的是一个普通的位置
	BSnode* node = createBSnode(e);
	if (pre)// 一定是第二种可能性
	{
		if (e < pre->data)
		{
			pre->left = node;
		}
		else if (e > pre->data)
		{
			pre->right = node;
		}
	}
	else
	{
		tree->root = node;
	}
	tree->cnt++;
#endif 
}

static BSnode* maxValueBSnode(BSnode* node)
{
	while (node && node->right)
	{
		node = node->right;
	}
	return node;
}

static BSnode* minValueBSnode(BSnode* node)
{
	while (node && node->left)
	{
		node = node->left;
	}
	return node;
}

static BSnode* deleteBSNode(BSTree* tree, BSnode* node, Element e)
{
	if (node == NULL)
	{
		return NULL;
	}
	if (e < node->data)
	{
		node->left = deleteBSNode(tree, node->left,e);
	}
	else if(e > node->data)
	{
		node->right = deleteBSNode(tree, node->right, e);
	}
	else
	{
		BSnode* tmp;
		if (node->left == NULL)			//度为1或0
		{
			tmp = node->right;
			free(node);
			--tree->cnt;
			return tmp;
		}
		if (node->right == NULL)		//度为1
		{
			tmp = node->left;
			free(node);
			--tree->cnt;
			return tmp;
		}
		// 此时说明待删除的点，度为2，替换当前点的值（后继或前驱）
		// 找前驱：找这个节点的左子树的最大值
		//tmp = maxValueBSnode(node->left);
		//node->data = tmp->data;
		//node->left = deleteBSNode(tree, node->left, node->data); // 转移矛盾，将替换掉的值给删掉。
		// 找后继：找这个节点的右子树的最小值
		tmp = minValueBSnode(node->right);
		node->data = tmp->data;
		node->right = deleteBSNode(tree, node->right, node->data); // 转移矛盾，将替换掉的值给删掉。
	}
	return node;
}
// 找后继节点,右边的最左值
static void deletemininode(BSnode* node)
{
	BSnode* mini = node->right;
	BSnode* pre = node;

	while (mini->left)
	{
		pre = mini;
		mini = mini->left;
	}
	if (pre->data == node->data)
	{
		pre->right = mini->right;
	}
	else
	{
		pre->left = mini->right;
	}
	node->data = mini->data;
	free(mini);
}

void deleteBSTree(BSTree* tree, Element e)
{
#ifdef RECUR
	if (tree)
	{
		tree->root = deleteBSNode(tree, tree->root, e);	
	}
#else
	BSnode* node = tree->root;
	BSnode* pre = NULL;
	while (node)
	{
		if (e < node->data)
		{
			pre = node;
			node = node->left;
		}
		else if (e > node->data)
		{
			pre = node;
			node = node->right;
		}
		else
		{
			break;
		}
	}
	if (node == NULL)
	{
		printf("No %d element\n", e);
		return;
	}
	BSnode* tmp = NULL;
	if (node->left == NULL)
	{
		tmp = node->right;
	}
	else if (node->right == NULL)
	{
		tmp = node->left;
	}
	else
	{
		deletemininode(node);
		tree->cnt--;
		return;
	}
	if (pre)
	{
		if (node->data < pre->data)
		{
			pre->left = tmp;
		}
		else
		{
			pre->right = tmp;
		}
	}
	else
	{
		tree->root = tmp;
	}
	free(node);
	--tree->cnt;
#endif
}

void visitBSnode(BSnode* node)
{
	printf("%d ", node->data);
}

static void inOrderBSnode(const BSnode* node)
{
	if (node)
	{
		inOrderBSnode(node->left);
		visitBSnode(node);
		inOrderBSnode(node->right);
	}
}

void inOrderBSTree(const BSTree* tree)
{
	printf("[%s]Tree: ", tree->name);
	inOrderBSnode(tree->root);
	printf("\n");
}

static int heightBSnode(const BSnode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	int leftheight = heightBSnode(node->left);
	int rightheight = heightBSnode(node->right);
	if (leftheight > rightheight)
	{
		return ++leftheight;
	}
	else
	{
		return ++rightheight;
	} 
}

int heightBSTree(const BSTree* tree)
{
	return heightBSnode(tree->root);
}

BSnode* searchBSTree(const BSTree* tree, Element e)
{
	BSnode* node = tree->root;
	while (node)
	{
		if (e < node->data)
		{
			node = node->left;
		}
		else if (e > node->data)
		{
			node = node->right;
		}
		else
		{
			return node;
		}
	}
	return NULL;
}