 #include"MatrixGraph.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static int isEdge(int w)
{
	if (w > 0 && w < INF)
	{
		return 1;
	}
	return 0;
}

void initMGraph(MGraph* graph, char* names[], int num, int directed, int edgeValue)
{
	graph->directed = directed;
	graph->nodeNum = num;
	graph->edgeNum = 0;

	memset(graph->vex, 0, sizeof(graph->vex));
	memset(graph->edges, 0, sizeof(MatrixEdge) * MaxNodeNum * MaxNodeNum);
	for (int i = 0; i < num; i++)
	{
		graph->vex[i].no = i;
		graph->vex[i].show = names[i];
		for (int j = 0; j < num; j++) // 初始化边
		{
			graph->edges[i][j] = edgeValue;
		}
	}
}

void addMGraphEdge(MGraph* graph, int x, int y, int w)
{
	if (x<0 || x>=graph->nodeNum || y<0 || y>=graph->nodeNum)
	{
		return;
	}
	if (!isEdge(graph->edges[x][y]))
	{
		graph->edges[x][y] = w;
		if (graph->directed == 0)
		{
			graph->edges[y][x] = w;
		}
		graph->edgeNum++;
	}
}

void visitMGraphNode(MatrixVertex* node)
{
	printf("\t%s",node->show);
}

static int MGraphVisited[MaxNodeNum];
void initVisited()
{
	memset(MGraphVisited, 0, sizeof(MGraphVisited));
}
void DFSGraph(MGraph* graph, int v)
{
	visitMGraphNode(&graph->vex[v]);
	MGraphVisited[v] = 1;
	for (int i = 0; i < graph->nodeNum; i++)
	{
		if (isEdge(graph->edges[v][i]) && MGraphVisited[i] == 0)
		{  
			DFSGraph(graph, i);
		}
	}
}

void BFSGraph(MGraph* graph, int v)
{
	int queue[MaxNodeNum];
	int rear = 0, front = 0;
	int cur;

	rear = (rear + 1) % MaxNodeNum;
	queue[rear] = v;
	MGraphVisited[v] = 1;
	while (front != rear)
	{
		front = (front + 1) % MaxNodeNum;
		cur = queue[front];

		visitMGraphNode(&graph->vex[cur]);
		for (int i = 0; i < graph->nodeNum; i++)
		{
			if (isEdge(graph->edges[cur][i]) && !MGraphVisited[i]) // 两点右边且没vis过
			{
				rear = (rear + 1) % MaxNodeNum;
				queue[rear] = i;
				MGraphVisited[i] = 1;
			}
		}
	}
}