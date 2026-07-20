#include "AdjancencyList.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void setupGraph(AGraph* graph)
{
	char* names[] = { "A","B","C","D","E" };
	initAGraph(graph, names, sizeof(names) / sizeof(names[0]), 1);

	addAGraph(graph, 0, 4, 1);
	addAGraph(graph, 0, 3, 1);
	addAGraph(graph, 0, 1, 1);
	addAGraph(graph, 1, 4, 1);
	addAGraph(graph, 1, 2, 1);
	addAGraph(graph, 2, 0, 1);
	addAGraph(graph, 3, 2, 1);
}

int main()
{
	int n = 5;
	AGraph* graph = createAGraph(n);
	setupGraph(graph);

	printf("图的边数: %d\n", graph->edgeNum);
	printf("图的深度遍历：");
	DFSAGraph(graph, 0);
	printf("\n");
	resetAGraphVisited(graph);

	printf("图的广度遍历：");
	BFSAGraph(graph, 0);

	return 0;
}