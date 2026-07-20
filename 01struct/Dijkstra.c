#include "Dijkstra.h"
#include<stdlib.h>
#include<stdio.h>

void DijkstraMGraph(const MGraph* graph, int start, int dist[], int path[])
{
	int* mark;		// 节点的访问记录
	mark = malloc(sizeof(int) * graph->nodeNum);
	// 1、激活start后，节点距离表dist更新、paths数组的初始化，根节点对应-1
	for (int i = 0; i < graph->nodeNum; i++)
	{
		dist[i] = graph->edges[start][i];
		mark[i] = 0;
		if (dist[i] < INF)
		{
			path[i] = start;
		}
		else
		{
			path[i] = -1;
		}
	}
	mark[start] = 1;
	path[start] = -1;
	dist[start] = 0;
	// 2、从dist里找最小值
	int mini;
	int tmpIndex = 0;
	for (int i = 0; i < graph->nodeNum - 1; i++)
	{
		mini = INF;
		// 从未激活的节点中，找到一个源点的最短路径
		for (int j = 0; j < graph->nodeNum; ++j)
		{
			if (mark[j] == 0 && dist[j] < mini)
			{
				mini = dist[j];
				tmpIndex = j;
			}
		}
		mark[tmpIndex] = 1;
		// 以刚激活的节点，更新源点到其他结点的路径
		for (int j = 0; j < graph->nodeNum; j++)
		{
			if (mark[j] == 0 && dist[tmpIndex] + graph->edges[tmpIndex][j] < dist[j])
			{
				dist[j] = dist[tmpIndex] + graph->edges[tmpIndex][j];
				path[j] = tmpIndex;
			}
		}
	}

	free(mark);
}

// 满递增栈
void showShortPath(int path[], int num, int pos)
{
	int* stack;
	int top = -1;
	stack = malloc(num * sizeof(int));
	if (stack == NULL)
	{
		return;
	}

	// 1、将上一个状态压入栈
	while (path[pos] != -1)
	{
		stack[++top] = pos;
		pos = path[pos];
	}
	stack[++top] = pos;
	//2、弹栈打印 pos到源点路径
	while (top != -1)
	{
		printf("\t%d", stack[top--]);
	}
	printf("\n");

	free(stack);

}