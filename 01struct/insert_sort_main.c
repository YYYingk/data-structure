#include "insert_sort.h"

int main() {
	int n = 10000;
	SortTable* table1 = generateRandomArray(n, 0, n + 5000);
	SortTable* table2 = generateLinearArray(n, 10);
	SortTable* table3 = copySortTable(table1);

	testSort("insertSort", insertSort, table1);
	testSort("LinearInsert", insertSort, table2);
	testSort("shellSort", shellSort, table3);

	releaseSortTable(table1);
	releaseSortTable(table2);
	releaseSortTable(table3);
	return 0;
}