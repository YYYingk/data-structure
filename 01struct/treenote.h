#pragma once
typedef int element;

typedef struct node
{
	int child_id;
	struct node* next;
};

typedef struct tree_node
{
	char name[16];
	int parent_id;
	struct node* childs;
};
struct tree_node tree1[10];