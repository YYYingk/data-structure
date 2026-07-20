#include<stdio.h>
#include<stdlib.h>
#include"linkStack.h"

void test01()
{
	LinkStack stack;
	initLinkStack(&stack);

	for (int i = 0; i < 10; i++)
	{
		pushLinkStack(&stack, i + 100);
	}
	value_t e;
	while (popLinkStack(&stack, &e))
	{
		printf("%d ", e);
	}
	printf("\n");
	popLinkStack(&stack, &e);
}

int main()
{
	test01();

	return 0;
}