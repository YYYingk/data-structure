#include "heap_sort.h"
#include"mini_heap.h"

void miniHeapSort(SortTable* table)
{
	MiniHeap* heap = createMiniHeap(table->length);
	for (int i = 0; i < table->length; i++)
	{
		insertMiniHeap(heap, table->data[i].key);
	}
	for (int i = 0; i < table->length; i++)
	{
		table->data[i].key = extractMinMiniHeap(heap);
	}
	releaseMiniHeap(heap);
}
