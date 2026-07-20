#pragma once
#define MaxStack 16
//typedef int element_t;

//#include"binary_treeTravel.h"
typedef void* BTnode;

typedef struct
{
	BTnode* data[MaxStack];
	int top;	// 数据行为，用下标即可
} ArrayStack;

void initArrayStack(ArrayStack* stack);

int isEmptyArrayStack(const ArrayStack* stack);
int isFullArrayStack(const ArrayStack* stack);

void pushArrayStack(ArrayStack* stack, BTnode* v);
void popArrayStack(ArrayStack* stack);
BTnode* getTopArrayStack(const ArrayStack* stack);