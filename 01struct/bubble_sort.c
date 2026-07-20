#include "bubble_sort.h"

/* 冒泡排序，第一次遍历[0...n-1)，第二次遍历[0...n-2) ... 遍历n-1次*/
void bubbleSortV1(SortTable* table) {
	for (int i = 0; i < table->length - 1; ++i) {
		for (int j = 0; j < table->length - 1 - i; ++j) {
			if (table->data[j].key > table->data[j + 1].key) {
				swapElement(&table->data[j + 1], &table->data[j]);
			}
		}
	}
}

/* 引入是否交换的标志，当发现某一轮不需要交换，那么就说明已经有序，退出循环 */
void bubbleSortV2(SortTable* table) {
	for (int i = 0; i < table->length - 1; ++i) {
		int isSorted = 1;
		for (int j = 0; j < table->length - 1 - i; ++j) {
			if (table->data[j].key > table->data[j + 1].key) {
				swapElement(&table->data[j + 1], &table->data[j]);
				isSorted = 0;
			}
		}
		if (isSorted) {
			break;
		}
	}
}

/* 引入newIndex标记交换的索引位置，下次冒泡的时候结束位置就是newIndex */
void bubbleSortV3(SortTable* table) {
	int newIndex;
	int n = table->length;
	do {
		newIndex = 0;
		for (int i = 0; i < n - 1; ++i) {
			if (table->data[i].key > table->data[i + 1].key) {
				swapElement(&table->data[i + 1], &table->data[i]);
				newIndex = i + 1;
			}
		}
		n = newIndex;
	} while (newIndex > 0);
}
