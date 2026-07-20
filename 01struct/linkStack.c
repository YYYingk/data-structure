#include<stdio.h>
#include<stdlib.h>
#include"linkStack.h"

void initLinkStack(LinkStack* stack)
{
	stack->count = 0;
	stack->top = NULL;
}

int pushLinkStack(LinkStack* stack, value_t e)
{
	StackNode* new_node = malloc(sizeof(StackNode));
	if (new_node == NULL)
	{
		return 0;
	}

	new_node->data = e;
	new_node->next = stack->top;
	stack->top = new_node;
	++stack->count;

	return 1;
}

int popLinkStack(LinkStack* stack, value_t* e)
{
	if (stack->top == NULL)
	{
		printf("stack empty!\n");
		return 0;
	}
	*e = stack->top->data;
	StackNode* tmp = stack->top;
	stack->top = tmp->next;
	free(tmp);
	--stack->count;

	return 1;
}

value_t getTopLinkStack(const LinkStack* stack)
{
	return stack->top->data;
}