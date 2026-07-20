#include "AdjancencyList.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

AGraph* createAGraph(int n)
{
	AGraph* graph = malloc(sizeof(AGraph));
	if (graph == NULL)
	{
		return NULL;
	}
	graph->edgeNum = 0;
	graph->directed = 0;
	graph->nodeNum = n;

	graph->nodes = malloc(sizeof(ArcNode) * n);
	graph->visited = malloc(sizeof(int) * n);
	if (graph->nodes == NULL || graph->visited == NULL)
	{
		free(graph);
		return NULL;
	}
	memset(graph->nodes, 0, sizeof(ArcNode) * n);
	memset(graph->visited, 0, sizeof(int) * n);

	return graph;
}

void initAGraph(AGraph* graph, char* names[], int num, int directed)
{
	graph->directed = directed;
	for (int i = 0; i < num; i++)
	{
		graph->nodes[i].no = i;
		graph->nodes[i].show = names[i];
		graph->nodes[i].firstEdge = NULL;
	}
}

static ArcEdge* createArcEdge(int v, int w)
{
	ArcEdge* edge = malloc(sizeof(ArcEdge));
	if (edge == NULL)
	{
		return NULL;
	}
	edge->no = v;
	edge->w = w;
	edge->next = NULL;
	return edge;
}

void addAGraph(AGraph* graph, int x, int y, int w)
{
	if (x < 0 || x >= graph->nodeNum || y < 0 || y >= graph->nodeNum)
	{
		return;
	}
	if (x == y)
	{
		return;
	}
	ArcEdge* edge = createArcEdge(y, w);
	edge->next = graph->nodes[x].firstEdge;
	graph->nodes[x].firstEdge = edge;
	graph->edgeNum++;
	if (graph->directed == 0)// 双向的话对方也有
	{
		edge = createArcEdge(x, w);
		edge->next = graph->nodes[y].firstEdge;
		graph->nodes[y].firstEdge = edge;
		graph->edgeNum++;
	}
}

void visitAGraphNode(const ArcNode* node)
{
	printf("\t%s", node->show);
}

void DFSAGraph(const AGraph* graph, int v)
{
	ArcEdge* p;
	graph->visited[v] = 1;
	visitAGraphNode(&graph->nodes[v]);
	p = graph->nodes[v].firstEdge;
	while (p)
	{
		if (graph->visited[p->no] == 0)
		{
			DFSAGraph(graph, p->no);
		}
		p = p->next;
	}
}

void BFSAGraph(const AGraph* graph, int v)
{
	int* que = malloc(sizeof(int) * graph->nodeNum);
	int front = 0, rear = 0;
	ArcEdge* p;
	int cur;

	rear = (rear + 1) % graph->nodeNum;
	que[rear] = v;
	graph->visited[v] = 1;
	while (front != rear)
	{
		front = (front + 1) % graph->nodeNum;
		cur = que[front];
		visitAGraphNode(&graph->nodes[cur]);
		
		p = graph->nodes[cur].firstEdge;
		while (p)
		{
			if (graph->visited[p->no] == 0)
			{
				rear = (rear + 1) % graph->nodeNum;
				que[rear] = p->no;
				graph->visited[p->no] = 1;
			}
			p = p->next;
		}
	}

	free(que);
}

void resetAGraphVisited(AGraph* graph)
{
	memset(graph->visited, 0, sizeof(int) * graph->nodeNum);
}