#include "mini_heap.h"
#include <stdio.h>
#include <stdlib.h> 

MiniHeap* createMiniHeap(int n) {
	MiniHeap* heap = malloc(sizeof(MiniHeap));
	if (heap == NULL) {
		return NULL;
	}
	heap->data = malloc(sizeof(keyType) * (n + 1)); // 完全二叉树从1号下标开始存储
	heap->len = 0;

	return heap;
}

void releaseMiniHeap(MiniHeap* miniheap) {
	if (miniheap) {
		if (miniheap->data) {
			free(miniheap->data);
			miniheap->data = NULL;
		}
		free(miniheap);
	}
}

static void shiftup(MiniHeap* miniheap, int k) {
	keyType tmp;
	// k/2表示父节点，k表示子节点
	while (k > 1 && miniheap->data[k / 2] > miniheap->data[k]) {
		tmp = miniheap->data[k];
		miniheap->data[k] = miniheap->data[k / 2];
		miniheap->data[k / 2] = tmp;
		k /= 2;
	}
}

void insertMiniHeap(MiniHeap* heap, keyType e) {
	if (heap->len + 1 > heap->capacity) {
		return;
	}
	heap->data[++heap->len] = e;
	// 上浮
	shiftup(heap, heap->len);

}

static void shiftDown(MiniHeap* miniheap, int k) {
	keyType tmp;
	while (2 * k <= miniheap->len) { // 保证有左孩子
		int index = 2 * k;
		if (index + 1 <= miniheap->len && miniheap->data[index + 1] < miniheap->data[index]) {
			++index;
		}
		if (miniheap->data[k] <= miniheap->data[index]) {
			break;
		}
		tmp = miniheap->data[k];
		miniheap->data[k] = miniheap->data[index];
		miniheap->data[index] = tmp;
		k = index;
	}
}

keyType extractMinMiniHeap(MiniHeap* heap) {
	if (heap->len == 0) {
		return 0;
	}
	keyType ret = heap->data[1];
	heap->data[1] = heap->data[heap->len--];
	shiftDown(heap, 1);
	return ret;
}
