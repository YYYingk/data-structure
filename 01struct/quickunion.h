#pragma once
typedef int element;
typedef struct
{
	element* data;
	int* parent;
	int* size;
	int n;
} QuickUnionSet;

/* Á´Ê½Õ»£¬½Úµã*/
typedef struct set_node
{
	int index;
	struct set_node* next;
} SetNode;

QuickUnionSet* createQuickUnionSet(int n);
void releaseQuickUnionSet(QuickUnionSet* set);
void initQuickUnionSet(QuickUnionSet* set, const element* data, int n);

int isSamQU(const QuickUnionSet* set, element a, element b);
void unionQU(QuickUnionSet* set, element a, element b);