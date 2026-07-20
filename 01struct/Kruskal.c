#include"Kruskal.h"
#include<string.h>
#include<stdlib.h>

void initEdgeSet(MGraph* graph, EdgeSet* edges)   // 将邻接矩阵交给edge统计
{
	int k = 0;
	for (int i = 0; i < graph->nodeNum; i++) // 遍历每个顶点
	{
		for (int j = i + 1; j < graph->nodeNum; j++) // 遍历上三角
		{
			if (graph->edges[i][j] > 0)
			{
				edges[k].begin = i;
				edges[k].end = j;
				edges[k].w = graph->edges[i][j];
				k++;
			}
		}
	}
}

void sortEdgeSet(EdgeSet* edges, int num)  // 排序
{
	EdgeSet tmp;
	for (int i = 0; i < num; i++) // 遍历每个顶点
	{
		for (int j = i + 1; j < num; j++) // 遍历上三角
		{
			if (edges[j].w < edges[i].w)
			{
				memcpy(&tmp, &edges[i], sizeof(EdgeSet));
				memcpy(&edges[i], &edges[j], sizeof(EdgeSet));
				memcpy(&edges[j], &tmp, sizeof(EdgeSet));
			}
		}
	}
}

static int getRoot(const int* uSet, int a)
{
	while (uSet[a] != a)
	{
		a = uSet[a];
	}
	return a;
}

int KruskalMGraph(const EdgeSet* edge, int num, int node_num, EdgeSet* res)
{
	int* uSet;
	int cnt = 0;
	int sum = 0;
	// 1.初始化并查集
	uSet = malloc(sizeof(int) * node_num);
	if (uSet == NULL)
	{
		return -1;
	}
	for (int i = 0; i < node_num; i++)
	{
		uSet[i] = i;
	}
	// 2、从已经排序好的边集中，找到最小的边，且不构成环
	for (int i = 0; i < num; i++)
	{
		int a = getRoot(uSet, edge[i].begin);
		int b = getRoot(uSet, edge[i].end);
		if (a != b)
		{
			// 不构成环
			uSet[a] = b;
			res[cnt].begin = edge[i].begin;
			res[cnt].end = edge[i].end;
			res[cnt].w = edge[i].w;
			sum += edge[i].w;
			cnt++;
			if (cnt == node_num - 1)
			{
				break;
			}
		}
	}
	free(uSet);
	return sum;
}