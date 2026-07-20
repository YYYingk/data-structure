#include "crossLinkGraph.h"
#include<stdlib.h>
#include<stdio.h>

CrossGraph* createCrossGraph(int n)
{
	CrossGraph* graph = malloc(sizeof(CrossGraph));
	if (graph == NULL)
	{
		return NULL;
	}
	graph->nodes = malloc(sizeof(CrossaVertex) * n);
	if (graph->nodes == NULL)
	{
		free(graph);
		return NULL;
	}
	graph->numEdeg = 0;
	graph->numVertex = n;
	return graph;
}

void releaseCrossGraph(CrossGraph* graph)
{
	int numEdges = 0;
	if (graph)
	{
		if (graph->nodes)
		{
			for (int i = 0; i < graph->numVertex; i++)
			{
				ArcBox* box = graph->nodes[i].firstout;
				ArcBox* tmp;
				while (box)
				{
					tmp = box;
					box = box->headNext;
					free(tmp);
					numEdges++;
				}
			}
			printf("release %d edge\n", numEdges);
			free(graph->nodes);
		}
		free(graph);
	}
}

void initCrossGraph(CrossGraph* graph, const char* names[], int num)
{
	for (int i = 0; i < num; i++)
	{
		graph->nodes[i].no = i;
		graph->nodes[i].show = names[i];
		graph->nodes[i].firstin = graph->nodes[i].firstout = NULL;
	}
}

void addCrossArc(CrossGraph* graph, int tail, int head, int w)
{
	ArcBox* box = malloc(sizeof(ArcBox));
	if (box == NULL)
	{
		return NULL;
	}
	box->w = w;
	// 从出度关系上进行插入（头插）
	box->tailVertex = tail;
	box->tailNext = graph->nodes[tail].firstout;
	graph->nodes[tail].firstout = box;
	// 从入度关系上进行插入（头插）
	box->headVertex = head;
	box->headNext = graph->nodes[head].firstin;
	graph->nodes[head].firstin = box;
}

int inDegreeCrossGraph(const CrossGraph* graph, int no)
{
	int cnt = 0;
	ArcBox* box = graph->nodes[no].firstin;
	while (box)
	{
		cnt++;
		box = box->headNext;
	}
	return cnt;
}

int outDegreeCrossGraph(const CrossGraph* graph, int no)
{
	int cnt = 0;
	ArcBox* box = graph->nodes[no].firstout;
	while (box)
	{
		cnt++;
		box = box->tailNext;
	}
	return cnt;
}
