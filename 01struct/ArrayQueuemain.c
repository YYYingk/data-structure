#include<stdio.h>
#include"ArrayQueue.h"

void test01()
{
	ArrayQueue q;
	initArrayQueue(&q);
	for (int i = 1; i < 5; i++)
	{
		enqArrayQueue(&q, i * 10);
	}
	enqArrayQueue(&q, 50);
	printf("Queue front is %d\n", getfrontArrayQueue(&q));
	deArrayQueue(&q);
	deArrayQueue(&q);
	printf("Queue front is %d\n", getfrontArrayQueue(&q));

	while (!isEmptyArrayQueue(&q))
	{
		printf("Queue front is %d\n", getfrontArrayQueue(&q));
		deArrayQueue(&q);
	}
	printf("=======================\n");
	deArrayQueue(&q);
}

int main()
{
	test01();
	return 0;
}