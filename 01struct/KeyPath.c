#include"KeyPath.h"
#include<stdio.h>
#include<stdlib.h>

static int topologicalOrder(const AGraph* graph, int* ETV, int* LTV) {
	int* inDegree = malloc(sizeof(int) * graph->nodeNum);
	memset(inDegree, 0, sizeof(int) * graph->nodeNum);
	//1、初始化图中所有顶点的入度记录表
	for (int i = 0; i < graph->nodeNum; i++) {
		if (graph->nodes[i].firstEdge) {
			ArcEdge* edge = graph->nodes[i].firstEdge;
			while (edge) {
				++inDegree[edge->no];
				edge = edge->next;
			}
		}
	}
	// 2、将入度为0的节点入栈，出栈的时候
	int top = -1;
	int* stack = malloc(sizeof(int) * graph->nodeNum);
	if (stack == NULL) {
		free(inDegree);
		return -1;
	}
	int* topOut = malloc(sizeof(int) * graph->nodeNum);
	if (stack == NULL) {
		free(stack);
		free(inDegree);
		return -1;
	}
	// 2.1、将初始化的入度为0的顶点编号压入栈，此点就是源点
	for (int i = 0; i < graph->nodeNum; i++) {
		if (inDegree[i] == 0) {
			stack[++top] = i;
			break;			// 关键路径默认只有一个源点
		}
	}
	// 2.2、不断弹栈，不断更新入度记录表
	int tmp = 0;			// 从栈上弹出的顶点编号
	int index = 0;			// 记录排序结果的情况
	while (top != -1) {
		tmp = stack[top--];
		topOut[index++] = tmp;
		ArcEdge* edge = graph->nodes[tmp].firstEdge; // 取节点
		while (edge) { // 遍历出度
			--inDegree[edge->no];
			if (inDegree[edge->no] == 0) { // 若删除前一个节点后，后一个节点的入度为0，那就入栈
				stack[++top] = edge->no;
			}
			// 此处为什么是大于，因为一个节点的前面的入度可能不一样，但因为此时记录的是最早时间，故我们需要等前面所有人都到才能开始行动。
			if (ETV[tmp] + edge->w > ETV[edge->no]) { // 更新ETV，看该结点的出度结点权值与原结点的ETV值相
				ETV[edge->no] = ETV[tmp] + edge->w;
			}
			edge = edge->next;
		}
	}
	free(inDegree);
	free(stack);
	if (index < graph->nodeNum) { // 有环
		free(topOut);
		return -1;
	}
	tmp = topOut[--index];
	// 3、更新LTV
	for (int i = 0; i < graph->nodeNum; i++) {
		LTV[i] = ETV[tmp];
	}
	while (index) {
		int getTopNo = topOut[--index];
		ArcEdge* edge = graph->nodes[getTopNo].firstEdge;
		while (edge) {
			// 后一个节点的最早时间减该边的权值，就为该节点的最晚时间
			// 至于为什么是小于，是因为一定要保证前一个结点对于所有出度的情况均满足
			// 比如0到2的权值为4，而到2的最晚时间却为6，此时我们就会有2小时的闲鱼时间，也就是0的最晚开始时间是2
			// But, 我们0到1的权值是6小时，而到1的最晚时间也是6小时，此时如果再将0从2小时开始，那么我们就会发现明显不能满足1的最晚时间
			// 故，我们需要考虑到每种情况，所以我们这边是小于。同上，大于也是此理
			if (LTV[edge->no] - edge->w < LTV[getTopNo]) { 
				LTV[getTopNo] = LTV[edge->no] - edge->w;
			}
			edge = edge->next;
		}
	}
	free(topOut);
}

static void showTable(int* table, int n, const char* name) {
	printf("%s", name);
	for (int i = 0; i < n; i++) {
		printf(" %d", table[i]);
	}
	printf("\n");
}

void KeyPath(const AGraph* graph) {
	// 1、计算顶点的ETV和LTV
	int* ETV = malloc(sizeof(int) * graph->nodeNum);
	int* LTV = malloc(sizeof(int) * graph->nodeNum);
	memset(ETV, 0, sizeof(int) * graph->nodeNum);
	memset(LTV, 0, sizeof(int) * graph->nodeNum);
	topologicalOrder(graph, ETV, LTV);
	showTable(ETV, graph->nodeNum, "ETV: ");
	showTable(LTV, graph->nodeNum, "LTV: ");
	// 2、计算边的ETE和LTE，直接输出关键路径
	for (int i = 0; i < graph->nodeNum; i++) {
		ArcEdge* edge = graph->nodes[i].firstEdge;
		while (edge) {
			// 每个边最早发生时间就是边的弧尾的ETV
			// 每个边的最晚发生时间就是边的弧头的LTV减去当前的边权值
			if (ETV[i] == LTV[edge->no] - edge->w) {
				printf("<%s>---%d---<%s>\n",
					graph->nodes[i].show, edge->w, graph->nodes[edge->no].show);
			}
			edge = edge->next;
		}
	}
	free(ETV);
	free(LTV);
}