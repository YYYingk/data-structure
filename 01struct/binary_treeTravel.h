#pragma once
typedef int element_t;
typedef struct tree_node
{
	element_t data;
	struct tree_node* left;
	struct tree_node* right;
} TreeNode;

typedef struct
{
	TreeNode* root;
	int cnt;
} TreeHead;

TreeHead* createBinaryTree(TreeNode* root);
void releaseBinaryTree(TreeHead* tree);

TreeNode* createBinaryTreeNode(element_t e);
void insertBinaryTree(TreeHead* tree, TreeNode* parent, TreeNode* left, TreeNode* right);

void preOrderBTree(const TreeHead* tree);		// Ç°Çý±éÀú
void inOrderBTree(const TreeHead* tree);
void postOrderBTree(const TreeHead* tree);
void visitCruurentTreeNode(const TreeNode* node);

void levelOrderBTree(const TreeHead* tree);
void preOrderBtreeNoRecursion(const TreeHead* tree);
void inOrderBtreeNoRecursion(const TreeHead* tree);