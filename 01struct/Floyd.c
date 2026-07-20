#include"MatrixGraph.h"
#include<stdio.h>
#define Max_Size 10

static int dist[Max_Size][Max_Size];
static int path[Max_Size][Max_Size];

void initMatG(MGraph* graph) {
	char* nodenames[] = { "V0", "V1", "V2", "V3" };
	initMGraph(graph, nodenames, sizeof(nodenames) / sizeof(nodenames[0]), 1, INF);
	for (int i = 0; i < graph->nodeNum; i++) {
		graph->edges[i][i] = 0;
	}
	addMGraphEdge(graph, 0, 1, 1);
	addMGraphEdge(graph, 0, 3, 4);
	addMGraphEdge(graph, 1, 2, 9);
	addMGraphEdge(graph, 1, 3, 2);
	addMGraphEdge(graph, 2, 0, 3);
	addMGraphEdge(graph, 2, 1, 5);
	addMGraphEdge(graph, 2, 3, 8);
	addMGraphEdge(graph, 3, 2, 6);
}

void shortPathFloyd(const MGraph* graph) {
	// ≥ı ºªØ
	for (int i = 0; i < graph->nodeNum; i++) {
		for (int j = 0; j < graph->nodeNum; ++j) {
			dist[i][j] = graph->edges[i][j];
			if (dist[i][j] < INF && i != j) {
				path[i][j] = i;
			} else {
				path[i][j] = -1;
			}
		}
	}
	// floyd
	for (int k = 0; k < graph->nodeNum; k++) {
		for (int i = 0; i < graph->nodeNum; i++) {
			for (int j = 0; j < graph->nodeNum; j++) {
				if (dist[i][k] < INF && dist[k][j] < INF && 
					dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}

void printPath(int i, int j) {
	if (i == j) {
		printf("%d ", i);
		return;
	}
	int k = path[i][j];
	printPath(i, k);
	printf("%d ", j);
}

int main() {
	MGraph graph;
	initMatG(&graph);

	shortPathFloyd(&graph);
	for (int i = 0; i < graph.nodeNum; i++) {
		for (int j = 0; j < graph.nodeNum; j++) {
			printf("%2d ", dist[i][j]);
		}
		printf("\n");
	}
	printf("========================\n");
	for (int i = 0; i < graph.nodeNum; i++) {
		for (int j = 0; j < graph.nodeNum; j++) {
			printf("%2d ", path[i][j]);
		}
		printf("\n");
	}
	printf("========================\n");
	printPath(1, 0);
	return 0;
}