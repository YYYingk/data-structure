#include "bubble_sort.h"
#include "quick_sort.h"

void test01() {
	int n = 10000;
	SortTable* table1 = generateRandomArray(n, 0, n + 5000);
	SortTable* table2 = copySortTable(table1);
	SortTable* table3 = copySortTable(table1);

	testSort("bubbleSortV1", bubbleSortV1, table1);
	testSort("bubbleSortV2", bubbleSortV2, table2);
	testSort("bubbleSortV3", bubbleSortV3, table3);

	releaseSortTable(table1);
	releaseSortTable(table2);
	releaseSortTable(table3);
}

void test02() {
	int n = 10000;
	SortTable* table1 = generateRandomArray(n, 0, n + 5000);
	SortTable *table2 = copySortTable(table1);
	//SortTable* table2 = generateLinearArray(n, 10);
	SortTable* table3 = copySortTable(table1);

	testSort("bubble SortV3", bubbleSortV3, table1);
	testSort("quick SortV1", quickSortV1, table2);
	testSort("quick SortV2", quickSortV2, table3);

	releaseSortTable(table1);
	releaseSortTable(table2);
	releaseSortTable(table3);
}

int main() {
	test02();

	return 0;
}