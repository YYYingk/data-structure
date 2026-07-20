#include <stdio.h>
#include "BTree.h"

int main() {
	DiskBTree* bTree = initDiskBTree();

	insertKey(bTree, 8);
	insertKey(bTree, 9);
	insertKey(bTree, 10);
	insertKey(bTree, 11);
	insertKey(bTree, 12);

	PrintBTree(bTree->root, 1);

	releaseDiskBTree(bTree);

	return 0;
}