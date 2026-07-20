#include "Prim.h"
#include<stdlib.h>
#include<stdio.h>

int PrimMGraph(const MGraph* graph, int start, EdgeSet* res)
{
	int* cost = malloc(sizeof(int) * graph->nodeNum);	// 图中各顶点的权值数组
	int* mark = malloc(sizeof(int) * graph->nodeNum);	// 图中顶点激活的状态
	int* visited = malloc(sizeof(int) * graph->nodeNum);	// 从哪个顶点开始访问，-1表示没有被访问
	int sum = 0;
	int mini;
	// 1.更新第一个结点激活的状态
	for (int i = 0; i < graph->nodeNum; i++)
	{
		cost[i] = graph->edges[start][i];
		mark[i] = 0;
		//1.1 更新visited数组，是从哪个结点访问的
		if (cost[i] < INF)
		{
			visited[i] = start;
		}
		else
		{
			visited[i] = -1;
		}
	}
	mark[start] = 1;
	int k = 0;
	// 2、动态激活结点，找最小值
	for (int i = 0; i < graph->nodeNum;++i)
	{
		int min = INF;
		k = 0;
		for (int j = 0; j < graph->nodeNum; j++)
		{
			if (mark[j] == 0 && cost[j] < min)
			{
				min = cost[j];
				k = j;
			}
		}
		mark[k] = 1;
		res[i].begin = visited[k];
		res[i].end = k;
		res[i].w = min;
		sum += min;
		// 每激活一个顶点，需要更新cost数组
		for (int j = 0; j < graph->nodeNum; j++)
		{
			if (mark[j] == 0 && graph->edges[k][j] < cost[j])
			{
				cost[j] = graph->edges[k][j];
				visited[j] = k;
			}
		}
	}

	free(cost);
	free(mark);
	free(visited);

	return sum;
}