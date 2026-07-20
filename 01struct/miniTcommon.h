#pragma once
/* 边集的结构 */
typedef struct
{
	int begin;		// 边的起点（顶点1）
	int end;		// 边的终点（顶点2）
	int w;			// 边的权值
} EdgeSet;

