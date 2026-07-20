#pragma once
typedef int element;

typedef struct avl_node
{
	element data;
	struct avl_node* left;
	struct avl_node* right;
	int height; // 这个节点左右子树高度最大值加1
} AVLNode;

typedef struct
{
	AVLNode* root;
	int cnt;
} AVLTree;

AVLTree* createAvlTree();
void releaseAVLTree(AVLTree* tree);

void visitAVLTree(const AVLNode* node);
void inOrderAVLTree(AVLTree* tree);
int heightAVLTree(AVLTree* tree);

void insertAVLTree(AVLTree* tree, element e);
void deleteAVLTree(AVLTree* tree, element e);