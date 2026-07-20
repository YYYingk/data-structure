#include "quick_sort.h"

static int partitionSingle(SortTable* table, int startIndex, int endIndex) {
	keyType tmpValue = table->data[startIndex].key;
	int mark = startIndex;

	for (int i = startIndex + 1; i <= endIndex; i++) {
		if (table->data[i].key < tmpValue) {
			mark++;
			swapElement(&table->data[i], &table->data[mark]);
		}
	}
	swapElement(&table->data[startIndex], &table->data[mark]);
	return mark;
}

static void quickSort2(SortTable* table, int startIndex, int endIndex) {
	if (startIndex >= endIndex) {
		return;
	}
	// 找到犄点
	int pivot = partitionSingle(table, startIndex, endIndex);
	quickSort2(table, startIndex, pivot - 1);
	quickSort2(table, pivot + 1, endIndex);
}

static int partitionDouble(SortTable* table, int startIndex, int endIndex) {
	int pivot = startIndex;
	int left = startIndex;
	int right = endIndex;
	// 随机将startIndex和后续的一个随机索引指向的元素进行交换
	while (left != right) {
		// 对二者一直缩进，且及时交换使得pivot双边的值保持左小右大
		while (left < right && table->data[right].key > table->data[pivot].key) { right--; }
		while (left < right && table->data[left].key <= table->data[pivot].key) { left++; }

		if (left < right) {
			swapElement(&table->data[right], &table->data[left]);
		}
	}
	swapElement(&table->data[pivot], &table->data[left]);
	return left;
}

// 用递归思想实现[start, end]区间的排序
static void quickSort1(SortTable* table, int startIndex, int endIndex) {
	if (startIndex >= endIndex) {
		return;
	}
	// 找到犄点
	int pivot = partitionDouble(table, startIndex, endIndex);
	quickSort1(table, startIndex, pivot - 1);
	quickSort1(table, pivot + 1, endIndex);
}

void quickSortV1(SortTable* table) {
	quickSort1(table, 0, table->length - 1);
}

void quickSortV2(SortTable* table) {
	quickSort2(table, 0, table->length - 1);
}