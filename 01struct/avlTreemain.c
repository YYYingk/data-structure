#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"avlTree.h"

void test01()
{
	AVLTree* tree = createAvlTree();
	element data[] = { 10,20,30,40,
					  50,60,68,80,
					  25, 7,55 };
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		insertAVLTree(tree, data[i]);
	}
	printf("InOrder: ");
	inOrderAVLTree(tree);
	printf("tree height: %d\n", heightAVLTree(tree));

	deleteAVLTree(tree, 60);
	printf("InOrder: ");
	inOrderAVLTree(tree);
	printf("tree height: %d\n", heightAVLTree(tree));
}

int main()
{
	test01();

	return 0;
}