#include"quickunion.h"
#include<stdio.h>
#include<stdlib.h>

void test01()
{
	int n = 9;
	QuickUnionSet* QUset = createQuickUnionSet(n);
	element data[9];
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		data[i] = i;
	}
	initQuickUnionSet(QUset, data, n);

	unionQU(QUset, 3, 4);
	unionQU(QUset, 8, 0);
	unionQU(QUset, 2, 3);
	unionQU(QUset, 5, 6);

	if (isSamQU(QUset, 0, 2))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	unionQU(QUset, 5, 1);
	unionQU(QUset, 7, 3);
	unionQU(QUset, 1, 6);
	unionQU(QUset, 4, 8);

	if (isSamQU(QUset, 0, 2))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
}

int main()
{
	test01();
	return 0;
}