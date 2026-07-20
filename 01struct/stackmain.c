#include<stdio.h>
#include<stdlib.h>
#include"ArrayStack.h"
/* ÂúµİÔöÕ» */
void test01()
{
	ArrayStack s;
	initArrayStack(&s);
	for (int i = 0; i < 5; i++)
	{
		pushArrayStack(&s, i + 100);
	}
	pushArrayStack(&s, 500);

	while (!isEmptyArrayStack(&s))
	{
		printf("%d ", getTopArrayStack(&s));
		popArrayStack(&s);
	}
	printf("\n");
	popArrayStack(&s);
}

int main()
{
	test01();

	return 0;
}