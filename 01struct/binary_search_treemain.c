#include"binary_search_tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void test01()
{
	int data[] = { 55,33,100,22,80,45,130,8,120,40,123 };
	BSTree* tree = createBSTree("stu01");
	if (tree == NULL)
	{
		return;
	}
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		insertBSTree(tree, data[i]);
	}
	inOrderBSTree(tree);
	printf("Tree node: %d, height: %d\n", tree->cnt, heightBSTree(tree));
}

static void lineFindTest(const Element* data, size_t n, int cnt, Element value)
{
	for (int i = 0; i < cnt; i++)
	{
		for (int j = 0; j < n; ++j)
		{
			if (data[i] == value)
			{
				printf("!!!Linear Find!!!\n");
				return;
			}
		}
	}
}

static void binaryFindTest(BSTree* tree, int cnt, Element value)
{
	BSnode* node = NULL;
	for (int i = 0; i < cnt; i++)
	{
		node = searchBSTree(tree, value);
		if (node)
		{
			printf("!!!BSTree Find!!!\n");
			return;
		}
	}
}

void test02()
{
	size_t n = 100000;
	Element m = n + 5000;
	int cnt = 10000;
	// 创建n个元素，取值在1~m之间
	Element* data = malloc(n * sizeof(Element));
	if (data == NULL) {
		fprintf(stderr, "malloc failed!\n");
		return;
	}
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		data[i] = rand() % m + 1;
	}
	// 线性查找
	clock_t start = clock();
	lineFindTest(data, n, cnt, m + 5);
	clock_t end = clock();
	printf("Linear Find time: %lf sec\n", (double)(end - start) / CLOCKS_PER_SEC);
	// 二分搜索树的查找
	BSTree* tree = createBSTree("stu02");
	for (int i = 0; i < n; i++)
	{
		insertBSTree(tree, data[i]);
	}
	printf("tree height: %d\n", heightBSTree(tree));
	start = clock();
	binaryFindTest(tree, cnt, m+5);
	end = clock();
	printf("BinaryFind time: %lf sec\n", (double)(end - start) / CLOCKS_PER_SEC);

	free(data);
} 

void test03()
{
	int data[] = { 55,33,100,22,80,45,130,8,120,121,122 };
	BSTree* tree = createBSTree("stu01");
	if (tree == NULL)
	{
		return;
	}
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		insertBSTree(tree, data[i]);
	}
	printf("tree height: %d\n", heightBSTree(tree));
	printf("inOrder travelsal: \n");
	inOrderBSTree(tree);
	printf("\n");

	//deleteBSTree(tree, 100);
	//inOrderBSTree(tree);
	releaseBSTree(tree);
	return;
}


int main()
{
	test03();

	return 0;
}