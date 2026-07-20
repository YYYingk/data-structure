#include "Dijkstra.h"
#include<stdlib.h>
#include<stdio.h>

void setupMGraph(MGraph* graph)
{
	char* names[] = { "0", "1", "2", "3", "4", "5", "6" };
	initMGraph(graph, names, sizeof(names) / sizeof(names[0]), 1, INF);

	addMGraphEdge(graph, 0, 1, 4);
	addMGraphEdge(graph, 0, 2, 6);
	addMGraphEdge(graph, 0, 3, 6);
	addMGraphEdge(graph, 1, 4, 7);
	addMGraphEdge(graph, 1, 2, 1);
	addMGraphEdge(graph, 2, 4, 6);
	addMGraphEdge(graph, 2, 5, 4);
	addMGraphEdge(graph, 3, 2, 2);
	addMGraphEdge(graph, 3, 5, 5);
	addMGraphEdge(graph, 4, 6, 6);
	addMGraphEdge(graph, 5, 4, 1);
	addMGraphEdge(graph, 5, 6, 8);
}

int main()
{
	MGraph graph;
	setupMGraph(&graph);

	int* dist = malloc(sizeof(int) * graph.nodeNum);
	int* path = malloc(sizeof(int) * graph.nodeNum);
	DijkstraMGraph(&graph, 0, dist, path);

	printf("to 6 node: ");
	showShortPath(path, graph.nodeNum, 6);
	printf("to 3 node: ");
	showShortPath(path, graph.nodeNum, 3);

	free(dist);
	free(path);
	return 0;
}