#include <stdio.h>
#include "mini_heap.h"
#include "heap_sort.h"
#include "quick_sort.h"

void test01() {
    int data[] = { 9, 3, 7, 6, 5, 1, 10, 2 };
    int n = 20;
    MiniHeap* miniHeap = createMiniHeap(n);
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        insertMiniHeap(miniHeap, data[i]);
    }
    printf("extra: ");
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        printf("%d ", extractMinMiniHeap(miniHeap));
    }
    printf("\n");
    releaseMiniHeap(miniHeap);
}

void test02() {
    int n = 10000;
    SortTable* table1 = generateRandomArray(n, 0, n + 5000);
    SortTable* table2 = copySortTable(table1);

    testSort("Heap Sort", miniHeapSort, table1);
    testSort("quick Sort", quickSortV1, table2);
    releaseSortTable(table1);
    releaseSortTable(table2);
}

int main() {
    test02();

    return 0;
}