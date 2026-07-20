#include<stdio.h>
#include"quickfind.h"

void test01()
{
	int n = 9;
	QuickFindSet* QFset = createQuickkFindSet(n);
	element data[9];
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		data[i] = i;
	}
	initQuickFindSet(QFset, data, n);

	unionQF(QFset, 3, 4);
	unionQF(QFset, 8, 0);
	unionQF(QFset, 2, 3);
	unionQF(QFset, 5, 6);

	if (isSameQF(QFset, 0, 2))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	if (isSameQF(QFset, 2, 4))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	unionQF(QFset, 5, 1);
	unionQF(QFset, 7, 3);
	unionQF(QFset, 1, 6);
	unionQF(QFset, 4, 8);

	if (isSameQF(QFset, 0, 2))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	if (isSameQF(QFset, 2, 4))
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