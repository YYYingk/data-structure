#pragma once
// 十字链表的边结构
typedef struct arcBox
{
	int tailVertex;				// 弧尾编号，tailVertex作为顶点的出度信息
	struct arcBox* tailNext;	// 下一个以该tailVertex作为狐尾的下一条边
	int headVertex;				// 弧头编号，以headVertex作为顶点的入度信息
	struct arcBox* headNext;	// 下一个以该head作为弧头的下一条边
	int w;						// 弧的权值
} ArcBox;

// 十字链表的顶点结构
typedef struct
{
	int no;
	const char* show;
	ArcBox* firstin;	// 该结点的入度
	ArcBox* firstout;	// 该结点的出度
} CrossaVertex;

// 利用十字链表的结构实现图的结构
typedef struct
{
	CrossaVertex* nodes;
	int numVertex;
	int numEdeg;
} CrossGraph;

CrossGraph* createCrossGraph(int n);
void releaseCrossGraph(CrossGraph* graph);

void initCrossGraph(CrossGraph* graph, const char* names[], int num);
void addCrossArc(CrossGraph* graph, int tail, int head, int w);	// 有向边，从tail指向head

// 计算no编号的节点入度
int inDegreeCrossGraph(const CrossGraph* graph, int no);
// 计算no编号的节点出度
int outDegreeCrossGraph(const CrossGraph* graph, int no);