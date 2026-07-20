#include"haffmantree.h"
#include<stdio.h>
#include<stdlib.h>

void test01()
{
	int w[] = { 5,29,7,8,14,23,3,11 };
	char show[] = { 'A', 'B', 'C','D','E','F','G','H' };
	int n = sizeof(w) / sizeof(w[0]);
	HuffTree tree = creatHuffmanTree(w, sizeof(w) / sizeof(w[0]));
	for (int i = 1; i <= 2*n - 1; i++)
	{
		printf("%d---%d---%d---%d\n", tree[i].weight, tree[i].parent, tree[i].lChild, tree[i].rChild);
	}
}

void test02()
{
	int w[] = { 5,29,7,8,14,23,3,11 };
	char show[] = { 'A', 'B', 'C','D','E','F','G','H' };
	int n = sizeof(w) / sizeof(w[0]);
	HuffTree tree = creatHuffmanTree(w, sizeof(w) / sizeof(w[0]));
	HuffmanCode* codes = createhuffmanCode(tree, n);
	for (int i = 0; i < n; i++)
	{
		printf("%c: %s\n", show[i], codes[i]);
	}
	releaseHuffmanCode(codes, n);
}

int main()
{
	test02();
	return 0;
}