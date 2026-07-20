#include "quickfind.h"
#include<stdio.h>
#include<stdlib.h>

QuickFindSet* createQuickkFindSet(int n)
{
	QuickFindSet* set = malloc(sizeof(QuickFindSet));
	if (set == NULL)
	{
		printf("set malloc failed\n");
		return NULL;
	}
	set->data = malloc(sizeof(element) * n);
	set->groupID = malloc(sizeof(int) * n);
	set->n = n;

	return set;
}

void releaseQuickFindSet(QuickFindSet* set)
{
	if (set)
	{
		if (set->data)
		{
			free(set->data);
		}
		if (set->groupID)
		{
			free(set->groupID);
		}
		free(set);
	}
}

void initQuickFindSet(QuickFindSet* set, const element* data, int n)
{
	for (int i = 0; i < n; i++)
	{
		set->data[i] = data[i];
		set->groupID[i] = i;
	}
}

static int findindex(const QuickFindSet* set, element e)
{
	for (int i = 0; i < set->n; i++)
	{
		if (set->data[i] == e)
		{
			return i;
		}
	}
	return -1;
}

int isSameQF(QuickFindSet* set, element a, element b)
{
	int aindex = findindex(set, a); // a的下标
	int bindex = findindex(set, b);
	if (aindex == -1 || bindex == -1)
	{
		return 0;
	}
	return set->groupID[aindex] == set->groupID[bindex];
}

void unionQF(QuickFindSet* set, element a, element b)
{
	// 把b的劳大管的人，都合并到a上面去
	int aindex = findindex(set, a); // a的下标
	int bindex = findindex(set, b);
	int gid = set->groupID[bindex];
	for (int i = 0; i < set->n; i++) // 将b所指的数的劳大及小弟全换成a
	{
		if (set->groupID[i] == gid)
		{
			set->groupID[i] = set->groupID[aindex];
		}
	}
}
