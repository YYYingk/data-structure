#include<stdio.h>
#include<stdlib.h>
#include"ListQueue.h"

void test01()
{
	LinkHNode* q = createLinkQueue();

	for (int i = 1; i < 5; i++)
	{
		enLinkQueue(q, i * 10);
	}
	value_t e;
	deLinkQueue(q, &e);
	printf("dequeue element : %d\n", e);
	deLinkQueue(q, &e);
	printf("dequeue element : %d\n", e);

	enLinkQueue(q, 50);
	enLinkQueue(q, 60);

	while (!deLinkQueue(q, &e))
	{
		printf("dequeue element : %d\n", e);
	}
	deLinkQueue(q, &e);

	releaseLinkQueue(q);
}

int main()
{
	test01();

	return 0;
}