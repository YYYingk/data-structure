#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int element;
// 定义huffman树的节点结构，采用顺序存储，下标索引来标识不同的节点
typedef struct
{
	int weight;
	int parent;
	int lChild;
	int rChild;
} Huffnode, *HuffTree;// tree:首地址，node：结构体

// 已知n个字符权值表，创建huffmantree
HuffTree creatHuffmanTree(const int* w, int n);

typedef char* HuffmanCode;
// 依据huffman树，产生n个huffman编码
HuffmanCode* createhuffmanCode(HuffTree tree, int n);

void releaseHuffmanCode(HuffmanCode* codes, int n);
