#pragma once
#include"miniTcommon.h"
#include"MatrixGraph.h"

/* 利用邻接矩阵 生存一个边集数组，利用边集数组实现kruskal算法
*  算法思路
*  a.将所有的边按权值大小进行升序排序，从小到大依次提取边，满足条件
*  b.一旦加入这条边，和之前已经选中的边不能组成环，如果不能，这条边就归入生成树的结果部分
*  c.如果能，舍去，再找下一条，直到筛选出n-1条边。
*/

// 从邻接矩阵中初始化边集数组 返回值表示边集数组的个数
void initEdgeSet(MGraph* graph, EdgeSet* edges);

// 排序边集数组
void sortEdgeSet(EdgeSet* edges, int num);

// kruskal算法
int KruskalMGraph(const EdgeSet* edge, int num, int node_num, EdgeSet* res);