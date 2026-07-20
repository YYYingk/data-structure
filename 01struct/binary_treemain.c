#include<stdio.h>
#include"binary_treeTravel.h"

TreeHead* initTree()
{
	TreeNode* nodeA = createBinaryTreeNode('A');
	TreeNode* nodeB = createBinaryTreeNode('B');
	TreeNode* nodeC = createBinaryTreeNode('C');
	TreeNode* nodeD = createBinaryTreeNode('D');
	TreeNode* nodeE = createBinaryTreeNode('E');
	TreeNode* nodeF = createBinaryTreeNode('F');
	TreeNode* nodeG = createBinaryTreeNode('G');
	TreeNode* nodeH = createBinaryTreeNode('H');
	TreeNode* nodeK = createBinaryTreeNode('K');

	TreeHead* tree = createBinaryTree(nodeA);
	insertBinaryTree(tree, nodeA, nodeB, nodeE);
	insertBinaryTree(tree, nodeB, NULL, nodeC);
	insertBinaryTree(tree, nodeE, NULL, nodeF);
	insertBinaryTree(tree, nodeC, nodeD, NULL);
	insertBinaryTree(tree, nodeF, nodeG, NULL);
	insertBinaryTree(tree, nodeG, nodeH, nodeK);
	return tree;
}

void test01() // Éî¶È±éÀú£¨µÝ¹é£©
{
	TreeHead* tree = initTree();
	printf("tree count : %d\n", tree->cnt);
	printf("PreOrder travel: ");
	preOrderBTree(tree);
	printf("inOrder travel: ");
	inOrderBTree(tree);
	printf("postOrder travel: ");
	postOrderBTree(tree);

	printf("LevelOrder travel: ");
	levelOrderBTree(tree);
}

void test02()
{
	TreeHead* tree = initTree();
	printf("tree count : %d\n", tree->cnt);
	printf("NoRecursion preOrder travel: ");
	preOrderBtreeNoRecursion(tree);
	printf("\n");
	printf("NoRecursion inOrder travel: ");
	inOrderBtreeNoRecursion(tree);
	printf("\n");
}

int main()
{
	test02();

	return 0;
}