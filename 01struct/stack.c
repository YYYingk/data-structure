#include<stdio.h>
#include<stdlib.h>
#include"ArrayStack.h"

/* 满递增栈 */
void initArrayStack(ArrayStack* stack)
{
	stack->top = -1;
}

int isEmptyArrayStack(const ArrayStack* stack)
{
	return stack->top == -1;
}

int isFullArrayStack(const ArrayStack* stack)
{
	return stack->top == MaxStack - 1;
}

void pushArrayStack(ArrayStack* stack, BTnode* v)
{
	if (isFullArrayStack(stack))
	{
		printf("stack full!\n");
		return;
	}
	stack->data[++stack->top] = v;
}

void popArrayStack(ArrayStack* stack)
{
	if (isEmptyArrayStack(stack))
	{
		printf("stack empty!\n");
		return;
	}
	//不用管之前位置的data数据，我们访问也是靠top操作
	--stack->top;
}

BTnode* getTopArrayStack(const ArrayStack* stack)
{
	return stack->data[stack->top];
}