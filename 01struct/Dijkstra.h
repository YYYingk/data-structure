#pragma once
#include"MatrixGraph.h"

/* Dijkstra算法，以strat为顶点，dist记录图中每个顶点到单一源点的最短路径
*  path数组记录每个结点从哪里访问的
*/
void DijkstraMGraph(const MGraph* graphm, int strat, int dist[], int path[]);
/* 从path信息打印出pos编号的订单 到 源点的最短路径 */
void showShortPath(int path[], int num , int pos);