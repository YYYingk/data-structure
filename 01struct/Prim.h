#pragma once
#include"MatrixGraph.h"
#include"miniTcommon.h"

/* graph: 表示指向邻接矩阵的图结构
*  start: 表示激活的第一个顶点坐标
*  res: 表示最小生成树的激活情况
*/
int PrimMGraph(const MGraph* graph, int start,EdgeSet *res);
