#define _CRT_SECURE_NO_WARNINGS
#include"haffmantree.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

static void selectNode(HuffTree tree, int n, int *s1,int *s2)
{
	int min = 0;
	// 找到第一个父节点为0的编号
	for (int i = 1; i <= n; i++)
	{
		if (tree[i].parent == 0)
		{
			min = i;// 将节点号给他
			break;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (tree[i].parent == 0)
		{
			if (tree[i].weight < tree[min].weight)
			{
				min = i;
			}
		}
	}
	*s1 = min;
	// 开始找第二个最小权值的点
	for (int i = 1; i <= n; i++)
	{
		if (tree[i].parent == 0 && i != *s1)
		{
			min = i;
			break;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (tree[i].parent == 0 && i != *s1)
		{
			if (tree[i].weight < tree[min].weight)
			{
				min = i;
			}
		}
	}
	*s2 = min;
}

HuffTree creatHuffmanTree(const int* w, int n)
{
	HuffTree tree;
	int m = 2 * n -	 1;
	// 1.1 申请2n个单元，从1号索引开始存储
	tree = malloc(sizeof(Huffnode) * (m + 1));
	if (tree == NULL)
	{
		return NULL;
	}
	// 初始化1~2n-1个节点(清空)
	for (int i = 1; i <= m; i++)
	{
		tree[i].parent = tree[i].lChild = tree[i].rChild = 0;
		tree[i].weight = 0;
	}
	// 1.2 再开始设置初始化的权值
	for (int i = 1; i <= n; i++)
	{
		tree[i].weight = w[i - 1];
	}
	// 填充 n + 1 下标到m下标的空间
	int s1, s2;
	for (int i = n + 1; i <= m; i++)
	{
		// 在[1......i-1]范围内，找父节点为0且权值最小的两个点
		selectNode(tree, i - 1, &s1, &s2);
		// 将这2个权值最小的节点，组合到第i个位置上（父节点）
		tree[s1].parent = tree[s2].parent = i;
		tree[i].lChild = s1;
		tree[i].rChild = s2;
		tree[i].weight = tree[s1].weight + tree[s2].weight;
	}
	return tree;
}

HuffmanCode* createhuffmanCode(HuffTree tree, int n)
{
	// 生成n个字符的编码表，每个表项里保存编码的空间首地址
	HuffmanCode* codes = malloc(sizeof(HuffmanCode) * n);
	if (codes == NULL)
	{
		return NULL;
	}
	memset(codes, 0, sizeof(HuffmanCode) * n);
	// 每求一个字符时，倒序构建，n个节点，树的高度最高是n，编码个数最多为n
	char* temp = malloc(sizeof(char) * n);
	int start;			// temp空间的起始位置
	int p;				// 存放当前节点的父节点
	int pos;			// 当前编码的位置
	// 逐个字符求huffman编码
	for (int i = 1; i <= n; i++)
	{
		start = n - 1;
		temp[start] = '\0';
		pos = i;
		p = tree[i].parent;
		while (p)
		{
			--start;
			// 判断当前位置是父节点的左还是右，左0右1
			temp[start] = (tree[p].lChild == pos) ? '0' : '1';
			pos = p; // 继续向上延伸
			p = tree[p].parent;
		}
		// 第i个字符编码分配的空间
		codes[i - 1] = malloc(sizeof(HuffmanCode) * (n - start));
		strcpy(codes[i - 1], &temp[start]);
	}
	return codes;
}

void releaseHuffmanCode(HuffmanCode* codes, int n)
{
	if (codes)
	{
		for (int i = 0; i < n; i++)
		{
			if (codes[i])
			{
				free(codes[i]);
			}
		}
	}
}
