#include"RedBlackTree.h"

int main() {
	int data[] = { 55, 40, 65, 60, 75, 57, 63, 56 };
	RBTree* rbTree = createRBTree();
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		insertRBTree(rbTree, data[i]);
	}
	//printRBTree(rbTree);
	deleteRBTree(rbTree, 57);
	printRBTree(rbTree);
	releaseRBTree(rbTree);
	return 0;
}