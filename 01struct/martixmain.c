#include<stdio.h>
#include<stdlib.h>
#include"MatrixGraph.h"

void testMatrixGraph(MGraph* graph)
{
	char* nodeName[] = { "v1","v2","v3","v4","v5","v6","v7","v8" };
	initMGraph(graph, nodeName, sizeof(nodeName) / sizeof(nodeName[0]), 0, 0);
	addMGraphEdge(graph, 0, 1, 1);
	addMGraphEdge(graph, 0, 2, 1);
	addMGraphEdge(graph, 1, 3, 1);
	addMGraphEdge(graph, 1, 4, 1);
	addMGraphEdge(graph, 2, 5, 1);
	addMGraphEdge(graph, 2, 6, 1);
	addMGraphEdge(graph, 3, 7, 1);
	addMGraphEdge(graph, 4, 7, 1);
	addMGraphEdge(graph, 5, 6, 1);
}

int main()
{
	MGraph g1;
	testMatrixGraph(&g1);

	printf("graph have %d edge!\n", g1.edgeNum);

	DFSGraph(&g1, 0);
	initVisited();
	printf("\n"); 
	BFSGraph(&g1, 0);
	return 0;
}