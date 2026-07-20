#pragma once

#include"AdjancencyList.h"

/* 拓扑排序
*  返回1表示有向有环， 0表示无环， -1表示出错
*/
int TopologicSortAGraph(AGraph* graph);