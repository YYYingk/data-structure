#include"Kruskal.h"
#include"Prim.h"
#include<stdlib.h>
#include<stdio.h>

void setupMGraph(MGraph* graph, int edgeValue)
{
					 //0    1    2    3    4    5    6	
	char* names[] = { "A", "B", "C", "D", "E", "F", "G" };
	initMGraph(graph, names, sizeof(names) / sizeof(names[0]), 0, edgeValue);

	addMGraphEdge(graph, 0, 1, 12);
	addMGraphEdge(graph, 0, 5, 16);
	addMGraphEdge(graph, 0, 6, 14);
	addMGraphEdge(graph, 1, 2, 10);
	addMGraphEdge(graph, 1, 5, 7);
	addMGraphEdge(graph, 2, 3, 3);
	addMGraphEdge(graph, 2, 4, 5);
	addMGraphEdge(graph, 2, 5, 6);
	addMGraphEdge(graph, 3, 4, 4);
	addMGraphEdge(graph, 4, 5, 2);
	addMGraphEdge(graph, 4, 6, 8);
	addMGraphEdge(graph, 5, 6, 9);
}

void showEdges(EdgeSet* edges, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("<%d>---<%d>---<%d>\n", edges[i].begin, edges[i].end, edges[i].w);
	}
}

void test01()
{
	MGraph graph;
	EdgeSet* edges;
	EdgeSet* res;

	setupMGraph(&graph, 0);  
	edges = malloc(sizeof(EdgeSet) * graph.edgeNum);
	if (edges == NULL)
	{
		return;
	}
	initEdgeSet(&graph, edges);
	sortEdgeSet(edges, graph.edgeNum);
	showEdges(edges, graph.edgeNum);

	res = malloc(sizeof(EdgeSet) * (graph.nodeNum - 1));
	int sum = KruskalMGraph(edges, graph.edgeNum, graph.nodeNum, res);
	for (int i = 0; i < graph.nodeNum - 1; i++)
	{
		printf("edge %d: <%s>---<%d>---<%s>\n", i + 1, graph.vex[res[i].begin].show, res[i].w, graph.vex[res[i].end].show);
	}
	printf("%d", sum);
	free(res);
	free(edges);
}


void test02()
{
	MGraph graph;
	EdgeSet* res;

	setupMGraph(&graph, INF);
	res = malloc(sizeof(EdgeSet) * graph.edgeNum);
	if (res == NULL)
	{
		return NULL;
	}
	int sum = 0;
	sum = PrimMGraph(&graph, 0, res);
	printf("total min weight : %d\n", sum);
	for (int i = 0; i < graph.nodeNum - 1; i++)
	{
		printf("edge %d: <%s>---<%d>---<%s>\n", i + 1, graph.vex[res[i].begin].show, res[i].w, graph.vex[res[i].end].show);
	}
}

int main()
{
	test01();

	return 0;
}