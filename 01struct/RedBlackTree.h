#pragma once
enum REColor {RED, BLACK};
typedef int KeyType;
// 红黑树的结点结构
typedef struct _rb_node {
	char color; 
	KeyType key;
	struct _rb_node* left;
	struct _rb_node* right;
	struct _rb_node* parent;
} RBNode;

// 红黑树的树头
typedef struct {
	RBNode* root;
	int cnt;
} RBTree;

RBTree* createRBTree();
void releaseRBTree(RBTree* tree);

void insertRBTree(RBTree* tree, KeyType key);
void printRBTree(const RBTree* tree);

RBNode* searchRBTree(const RBTree* tree, KeyType key);
void deleteRBTree(RBTree* tree, KeyType key);