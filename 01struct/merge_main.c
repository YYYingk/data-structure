#include"sort_helper.h"
#include"merge_sort.h"

int main() {
    int n = 10000;
    SortTable* table = generateRandomArray(n, 0, n + 5000);
    testSort("Merge Sort", mergeSort, table);
    releaseSortTable(table);
    return 0;
}