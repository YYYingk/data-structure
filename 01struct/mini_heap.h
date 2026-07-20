#pragma once
#include"sort_helper.h"
// 定义小顶堆的结构
typedef struct {
	keyType* data;
	int len;			// 堆data的长度
	int capacity;		// 最大容量
} MiniHeap;

MiniHeap* createMiniHeap(int n);
void releaseMiniHeap(MiniHeap* miniheap);

// 插入
void insertMiniHeap(MiniHeap* heap, keyType e);
// 提取
keyType extractMinMiniHeap(MiniHeap* heap);