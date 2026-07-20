#include "crossLinkGraph.h"
#include<stdlib.h>
#include<stdio.h>

void setupCrossGraph(CrossGraph* graph)
{
	char* nodenames[] = {"v0", "v1", "v2", "v3"};
	initCrossGraph(graph, nodenames, 4);
	addCrossArc(graph, 0, 3, 1);
	addCrossArc(graph, 1, 0, 1);
	addCrossArc(graph, 1, 2, 1);
	addCrossArc(graph, 2, 0, 1);
	addCrossArc(graph, 2, 1, 1);
}

int main()
{
	int n = 4;
	CrossGraph* graph = createCrossGraph(n);
	if (graph == NULL)
	{
		return -1;
	}
	setupCrossGraph(graph);
	printf("V0的入度：%d\n", inDegreeCrossGraph(graph, 1));
	printf("\nV0的出度：%d\n", outDegreeCrossGraph(graph, 1));

	releaseCrossGraph(graph);

	return 0;
}