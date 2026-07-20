#pragma once
// 边的结构
typedef struct arcEdge
{
	int no;					// 边顶点编号
	int w;					// 边的权值
	struct arcEdge* next;	// 指向下一条边结构
} ArcEdge;

// 一个顶点的结构
typedef struct
{
	int no;					// 顶点的编号
	char* show;				// 顶点的显示内容
	ArcEdge* firstEdge;		// 当前顶点指向其他顶点的，边的链表首地址

} ArcNode;

// 邻接表来表示图，多个顶点的结构来描述
typedef struct
{
	ArcNode* nodes;			// 图中顶点的集合
	int nodeNum;			// 图中顶点的个数
	int edgeNum;			// 图中边的个数
	int directed;			// 是否有向
	int* visited;			// 图遍历标志
} AGraph;

// 产生n个节点的邻接表
AGraph* createAGraph(int n);
// 释放邻接表
void releaseAGraph(AGraph* graph);
// 初始化邻接表的存储
void initAGraph(AGraph* graph, char* names[],int num,int directed);
/* 向邻接表中添加边
*  graph:  向哪个图添加边
*  x：起始顶点编号
*  y：终点顶点编号
*  w：边的权值
*/
void addAGraph(AGraph* graph, int x, int y, int w);

void visitAGraphNode(const ArcNode* node);
// 深度遍历
void DFSAGraph(const AGraph* grap, int v);
// 广度遍历
void BFSAGraph(const AGraph* graph, int v);

void resetAGraphVisited(AGraph* graph);