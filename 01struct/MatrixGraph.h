#pragma once
#define MaxNodeNum 20
#define INF 1E4
// 邻接矩阵的顶点集合
typedef struct
{
	int no;		// 顶点编号
	char* show; // 显示行为
} MatrixVertex;

typedef int MatrixEdge;
// 图的邻接矩阵表示边的结构
typedef struct
{
	MatrixVertex vex[MaxNodeNum];				// 存储顶点信息
	int nodeNum;								// 约束实际顶点个数
	MatrixEdge edges[MaxNodeNum][MaxNodeNum];	// 存储边的结构，矩阵
	int edgeNum;								// 边的数量
	int directed;								// 是否有向
} MGraph;

void initMGraph(MGraph* graph, char* names[], int num, int directed, int edgeValue);

void addMGraphEdge(MGraph* graph,int x, int y, int w);
void visitMGraphNode(MatrixVertex* node);
void initVisited();

void DFSGraph(MGraph* graph, int v);
void BFSGraph(MGraph* graph, int v);