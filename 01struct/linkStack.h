#pragma once
typedef int value_t;
typedef struct stack_node
{
	value_t data;
	struct stack_node* next;
} StackNode;

typedef struct
{
	StackNode* top;
	int count;
} LinkStack;

void initLinkStack(LinkStack* stack);
int pushLinkStack(LinkStack* stack, value_t e);
int popLinkStack(LinkStack* stack, value_t *e);
value_t getTopLinkStack(const LinkStack* stack);