#include "TopoSort.h"
#include<stdlib.h>
#include<string.h>

int TopologicSortAGraph(AGraph* graph)
{
	int cnt = 0;
	// 定义一个入度记录表，便于发现入度为0时，放入缓存区
	int* inDegree;
	inDegree = malloc(sizeof(int) * graph->nodeNum);
	if (inDegree == NULL) {
		return -1;
	}

	memset(inDegree, 0, sizeof(int) * graph->nodeNum);
	// 初始化入度记录表
	for (int i = 0; i < graph->nodeNum; i++) {
		if (graph->nodes[i].firstEdge) { // 说明i结点开始有边 
			ArcEdge* edge = graph->nodes[i].firstEdge;
			while (edge) {
				++inDegree[edge->no];
				edge = edge->next;
			}
		}
	}

	// 查找入度记录表，度为0的点，设计一个链式栈的缓存区，更新入度记录表时，发现0就立刻放入栈
	int* stack = malloc(sizeof(int) * graph->nodeNum);
	if (stack == NULL) {
		return -1;
		free(inDegree);
	}
	int top = -1;
	for (int i = 0; i < graph->nodeNum; i++) {
		if (inDegree[i] == 0) {
			stack[++top] = i;
		}
	}

	// 根据任务栈里的数据，弹出第一个任务，将这个任务对应的节点相关的入边个数删除
	// 更细入度记录表，如果在更新过程中，发现入度为0，直接入栈
	int index;
	while (top != -1) {
		index = stack[top--];
		cnt++;
		visitAGraphNode(&graph->nodes[index]);

		// 更新入度信息
		ArcEdge* edge = graph->nodes[index].firstEdge;
		while (edge) {
			--inDegree[edge->no];
			if (inDegree[edge->no] == 0) {
				stack[++top] = edge->no;
			}
			edge = edge->next;
		}
	}

	
	free(inDegree);
	free(stack);
	if (cnt == graph->nodeNum) return 0;
	else return 1;
}
