#pragma once

typedef int Element;

typedef struct _bs_node
{
	Element data;
	struct _bs_node* left;
	struct _bs_node* right;

} BSnode;

typedef struct
{
	BSnode* root;
	int cnt;
	const char* name;
} BSTree;

BSTree* createBSTree(const char* name);
void releaseBSTree(BSTree* tree);

void insertBSTree(BSTree* tree, Element e);
void deleteBSTree(BSTree* tree, Element e);

void visitBSTreeNode(const BSnode* node);
void inOrderBSTree(const BSTree* tree);

int heightBSTree(const BSTree* tree);
BSnode* searchBSTree(const BSTree* tree, Element e);
