#include "RedBlackTree.h"
#include<stdlib.h>
#include<stdio.h>

/* 将x进行左旋,将左，右父节点都进行更新
*		 px							px
*		 |						    |
*	  	 x							y
*		/ \       ------->		   / \
*	   lx  y					  x   ry
*		  / \					 / \
*		 ly ry					lx  ly
*/
static void leftRotate(RBTree* tree, RBNode* x) {
	RBNode* y = x->right;
	x->right = y->left;
	if (y->left != NULL) { // 检查是否为空，是否有段错误
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent != NULL) {
		if (x->parent->left == x) { // 判断对于x的父结点来说x是其的左还是右，然后用y来替换
			x->parent->left = y;
		}
		else {
			x->parent->right = y;
		}
	}
	else {
		tree->root = y;
	}
	y->left = x;
	x->parent = y;
}

/* 将x进行右旋,将左，右父节点都进行更新
*		 px							px
*		 |						    |
*	  	 x							y
*		/ \       ------->		   / \
*	   y   rx					  ly  x
*	  / \					         / \
*    ly ry				     	    ry rx
*/
static void rightRotate(RBTree* tree, RBNode* x) {
	RBNode* y = x->left;
	x->left = y->right;
	if (y->right != NULL) { // 检查是否为空，是否有段错误
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x->parent != NULL) {
		if (x->parent->right == x) { // 判断对于x的父结点来说x是其的左还是右，然后用y来替换
			x->parent->right = y;
		}
		else {
			x->parent->left = y;
		}
	}
	else {
		tree->root = y;
	}
	y->right = x;
	x->parent = y;
}

RBTree* createRBTree() {
	RBTree* tree = malloc(sizeof(RBTree));
	tree->root = NULL;
	tree->cnt = 0;

	return tree;
}

static void destroyRBNode(RBTree* tree, RBNode* node) {
	if (node != NULL) {
		destroyRBNode(tree, node->left);
		destroyRBNode(tree, node->right);
		free(node);
		tree->cnt--;
	}
}

void releaseRBTree(RBTree* tree) {
	destroyRBNode(tree, tree->root);
	printf("release tree count = %d\n", tree->cnt);
	free(tree);
}

static RBNode* createRBNode(KeyType key) {
	RBNode* node = malloc(sizeof(RBNode));
	node->left = node->right = node->parent = NULL;
	node->key = key;
	node->color = RED;
	return node;
}

/* 1、插入节点，如果父节点是黑色，那么不需要调整
*  2、如果父节点是红色，此时优菈两个红红结点，进行调整
*	2.1、叔叔结点是红色
*		重新着色，叔叔结点变为黑色（g->红色，p->黑色，u->黑色），转为2.2的大逻辑判断
*	2.2、叔叔结点是黑色
*		2.2.1、cur左孩子，par也是左
*			g右旋，g->红色，p->黑色
*		2.2.2、cur右孩子，par是左
*			p左旋，cur和par交换，然后重复2.2.1
*		2.2.3、cur右孩子，par也是右
*			g左旋，g->红色，p->黑色
*		2.2.4、cur左孩子，par是右
*			p右旋，cur和par交换，重复2.2.3
*/ 
static void insertFixup(RBTree* tree, RBNode* node) {
	RBNode* parent, * grandParent;
	RBNode* uncle;
	RBNode* tmp;
	// 先将三者赋值
	parent = node->parent;
	while (parent && parent->color == RED) {
		// 违反红红结点
		grandParent = parent->parent;
		if (parent == grandParent->left) {
			uncle = grandParent->right;
		}
		else {
			uncle = grandParent->left;
		}
		if (uncle && uncle->color == RED) {
			uncle->color = BLACK;
			parent->color = BLACK;
			grandParent->color = RED;
			// 转移矛盾，再交给局部根节点去判断其上层与根节点的情况
			node = grandParent;
			parent = grandParent->parent;
			continue;
		}
		if (grandParent->left == parent) {		// L
			// LR
			if (parent->right == node) {
				leftRotate(tree, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}
			// LL
			rightRotate(tree, grandParent);
			// 旋转完后，需要调整颜色
			grandParent->color = RED;
			parent->color = BLACK;
		}
		else { 		// R
			// RL
			if (parent->left == node) {
				rightRotate(tree, parent);
				tmp = parent;
				parent = node;
				node = tmp;
			}
			// RR
			leftRotate(tree, grandParent);
			// 旋转完后，需要调整颜色
			grandParent->color = RED;
			parent->color = BLACK;
		}
	}
	tree->root->color = BLACK;
}

void insertRBTree(RBTree* tree, KeyType key) {
	// 1、先创建一个红色的节点
	RBNode* node = createRBNode(key);
	// 2、根据二叉搜索树的规则，找到待插入的结点
	RBNode* cur = tree->root;
	RBNode* pre = NULL;
	while (cur) {
		pre = cur;
		if (key < cur->key) {
			cur = cur->left;
		}
		else if (key > cur->key) {
			cur = cur->right;
		}
		else {
			printf("insert %d have exist!\n", key);
			return;
		}
	}
	// 3、在对应位置上插入，如果是根，更新tree
	node->parent = pre;
	if (pre) {
		if (key < pre->key) {
			pre->left = node;
		}
		else {
			pre->right = node;
		}
	}
	else { // pre不存在只能说明。pre一来就是空，即
		tree->root = node;
	}
	// 此时我们红黑树的结构就没有问题了，但颜色有问题，故我们进入第四步
	// 4、修正红黑树
	insertFixup(tree, node);
	tree->cnt++;
}

static void printRBNode(RBNode* node, int key, int dir) {
	if (node) {
		if (dir == 0) {
			printf("%2d[B] is root\n", node->key);
		}
		else {
			printf("%2d[%c] is %2d`s %s\n", node->key, (node->color == RED) ? 'R' : 'B', key,
				(dir == 1) ? "right child" : "left child");
		}
		printRBNode(node->left, node->key, -1);
		printRBNode(node->right, node->key, 1);
	}
}

void printRBTree(const RBTree* tree) {
	printRBNode(tree->root, tree->root->key, 0);
}

static void deleteFixup(RBTree* tree, RBNode* x, RBNode* parent) {
	RBNode* w;
	while (tree->root != x && (!x || x->color == BLACK)) {
		if (parent->left == x) {		// x是父节点的左孩子
			w = parent->right;			// w是x的兄弟节点
			if (w->color == RED) {
				// case1：x的兄弟节点是红色
				w->color = BLACK;
				parent->color = RED;
				leftRotate(tree, parent);
				w = parent->right;
			}
			// 兄弟节点是黑色
			if ((!w->left || w->left->color == BLACK) && (!w->right || w->right->color == BLACK)) {
				// case2：x的兄弟是黑色， x的兄弟的两个孩子都是黑色的
				w->color = RED;
				x = parent;
				parent = x->parent;
			}
			else {
				if (!w->right || w->right->color == BLACK) {
					// case3：兄弟节点是黑色，x的兄弟节点的左孩子
					w->left->color = BLACK;
					w->color = RED;
					rightRotate(tree, w);
					w = parent->right;
				}
				// case4：x的兄弟节点是黑色，x的兄弟节点右孩子是红色
				w->color = parent->color;
				parent->color = BLACK;
				w->right->color = BLACK;
				leftRotate(tree, parent);
				x = tree->root;
				break;
			}
		}
		else {
			w = parent->left;
			if (w->color == RED) {
				// case1：x的兄弟节点是红色
				w->color = BLACK;
				parent->color = RED;
				rightRotate(tree, parent);
				w = parent->left;
			}
			// 兄弟节点是黑色
			if ((!w->left || w->left->color == BLACK) && (!w->right || w->right->color == BLACK)) {
				// case2：x的兄弟是黑色， x的兄弟的两个孩子都是黑色的
				w->color = RED;
				x = parent;
				parent = x->parent;
			}
			else {
				if (!w->left || w->left->color == BLACK) {
					// case3：兄弟节点是黑色，且w的左孩子是
					w->right->color = BLACK;
					w->color = RED;
					leftRotate(tree, w);
					w = parent->left;
				}
				// case4：x的兄弟节点是黑色，x的兄弟节点右孩子是红色
				w->color = parent->color;
				parent->color = BLACK;
				w->left->color = BLACK;
				rightRotate(tree, parent);
				x = tree->root;
				break;
			}
		}
	}
	if (x) {
		x->color = BLACK;
	}
}

static void deleteRBNode(RBTree* tree, RBNode* node) {
	RBNode* y;	// 真正删除的节点
	RBNode* x;  // 替换节点
	RBNode* parent; // 替换结点是NULL,无法再访问到父节点
	if (node->left == NULL || node->right == NULL) {
		y = node;
	}
	else {		// 度为2，需要找后继
		y = node->right;
		while (y->left) {
			y = y->left;
		}
	}
	// 真正删除的节点首地址找到了，确定替换节点
	if (y->left) {
		x = y->left;
	}
	else {
		x = y->right;
	}
	parent = y->parent;
	// 更新替换节点和原父节点的关系
	if (x) {
		x->parent = parent;
	}
	if (y->parent == NULL) {
		tree->root = x;
	}
	else if (y == y->parent->left) { // 判读y在y->p的左还是右，并取x
		y->parent->left = x;
	}
	else {
		y->parent->right = x;
	}
	// 更新有左右孩子的根节点为后继结点的值，处理度为2的情况
	if (y != node) {
		node->key = y->key;
	}
	// 如果删除的节点为黑色，那么就需要调整
	if (y->color == BLACK) {
		deleteFixup(tree, x, parent);
	}
	// 调整完成，或者删除节点是红色，直接释放
	free(y);
}

RBNode* searchRBTree(const RBTree* tree, KeyType key) {
	RBNode* node = tree->root;
	while (node) {
		if (key < node->key) {
			node = node->left;
		}
		else if (key > node->key) {
			node = node->right;
		}
		else {
			return node;
		}
	}
	return NULL;
}

void deleteRBTree(RBTree* tree, KeyType key) {
	RBNode* node = searchRBTree(tree, key);
	if (node) {
		deleteRBNode(tree, node);
		tree->cnt--;
	}
}
