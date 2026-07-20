#include<stdio.h>
#include"thread_BTree.h"

ThreadBTree* setupTree()
{
	BTnode* nodeA = createTBTreenode('A');
	BTnode* nodeB = createTBTreenode('B');
	BTnode* nodeC = createTBTreenode('C');
	BTnode* nodeD = createTBTreenode('D');
	BTnode* nodeE = createTBTreenode('E');
	BTnode* nodeF = createTBTreenode('F');
	BTnode* nodeG = createTBTreenode('G');
	BTnode* nodeH = createTBTreenode('H');
	BTnode* nodeK = createTBTreenode('K');

	ThreadBTree* tree = createTBTree(nodeA);
	insertTBTree(tree, nodeA, nodeB, nodeE);
	insertTBTree(tree, nodeB, NULL, nodeC);
	insertTBTree(tree, nodeE, NULL, nodeF);
	insertTBTree(tree, nodeC, nodeD, NULL);
	insertTBTree(tree, nodeF, nodeG, NULL);
	insertTBTree(tree, nodeG, nodeH, nodeK);

	return tree;
}

void test01()
{
	ThreadBTree* tree = setupTree();
	printf("tree node: %d\n", tree->cnt);
	inOrderThreadingBTree(tree);
	printf("show: ");
	inOrderTBTree(tree);
	releaseTBTree(tree);
}

int main()
{
	test01();

	return 0;
}