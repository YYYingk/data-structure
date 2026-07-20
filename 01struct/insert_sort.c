#include "insert_sort.h"

/* 直接插入排序：
 * 1. 默认第一个元素就是有序，那么从第二个元素开始和前面的有序区的值进行比较
 * 2. 待插入的元素i，和已经有序的区域从后往前依次查找
 */
void insertSort(SortTable* table) {
	for (int i = 1; i < table->length; ++i) {
		if (table->data[i].key < table->data[i - 1].key) {
			// 用j辅助索引来找到待插入元素该放的位置
			int j = i - 1;
			Element temp = table->data[i];
			// 从[0...i-1]
			while (j >= 0 && table->data[j].key > temp.key) {
				table->data[j + 1] = table->data[j];
				j--;
			}
			table->data[j + 1] = temp;
		}
	}
}

void shellSort(SortTable* table) {
	for (int gap = table->length / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < table->length; ++i) {
			Element temp = table->data[i];
			int j;
			for (j = i; j >= gap && table->data[j - gap].key > temp.key; j -= gap) {
				table->data[j] = table->data[j - gap];
			}
			table->data[j] = temp;
		}
	}
}
