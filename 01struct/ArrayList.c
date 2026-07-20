#include"ArrayList.h"
#include<stdlib.h>
#include<stdio.h>

void initArrayList(ArrayList* table, int num)
{
	table->data = (int *)malloc(sizeof(element_t) * num);
	if (table->data == NULL)
	{
		table->capacity = 0;
		return;
	}
	table->capacity = num;
	table->len = 0;
}

void deleteArrayList(ArrayList* table)
{
	if (table->data)
	{
		free(table->data);
		table->data = NULL;
	}
	table->capacity = 0;
	table->len = 0;
}

ArrayList* creatArrayList(int num)
{
	ArrayList* table = malloc(sizeof(ArrayList));
	if (table == NULL)
	{
		return NULL;
	}
	initArrayList(table, num);
	return table;
}

void releaseArrayList(ArrayList* table)
{
	if (table)
	{
		deleteArrayList(table);
		free(table);
	}

}

static int enlarger(ArrayList *table)
{
	//1、申请一块原空间的两倍大小
	element_t* temp = (int*)malloc(sizeof(element_t) * (table->capacity * 2));
	if (temp == NULL)
	{
		return -1;
	}
	//2、把原空间的内容拷贝到新空间，原空间[0, len)范围拷贝新空间的[0, len)范围
	for (int i = 0; i < table->len; i++)
	{
		temp[i] = table->data[i];
	}
	//释放原空间 + 更新表头
	table->capacity *= 2;
	free(table->data);
	table->data = temp;
	printf("enlaige success!\n");
	return 0;
}

void push_backArrayList(ArrayList* table, element_t val)
{
	// 判断是否溢出，若溢出，则扩容

	if (table->len >= table->capacity && enlarger(table) != 0)
	{
		printf("bush back failed\n");
		return;
	}
	table->data[table->len] = val;
	++table->len;
}

void insertArrayList(ArrayList* table, int pos, element_t val) {
	// 1. 判断输入参数有效性
	if (pos < 0 || pos > table->len) {
		printf("pos invalid!\n");
		return;
	}
	// 2. 判断是否需要扩容
	if (table->len >= table->capacity && enlarger(table)) {
		return;
	}
	// 3. 把原来的[pos, len-1]的元素搬移到[pos + 1, len]这个位置，i表示要搬移的数据，搬移到i+1的位置上
	for (int i = table->len - 1; i >= pos; --i) {
		table->data[i + 1] = table->data[i];
	}
	// 4. 放入新元素
	table->data[pos] = val;
	++table->len;
}

void showArrayList(const ArrayList* table)
{
	for (int i = 0; i < table->len; i++)
	{
		printf("%d\t", table->data[i]);
	}
	printf("\n");
}

int findArrayList(const ArrayList* table, element_t val)
{
	for (int i = 0; i < table->len; i++)
	{
		if (table->data[i] == val)
		{
			return i;
		}
	}
	return -1;
}

void deleteValueArrayList(ArrayList* table, element_t val)
{
	//1、先找到val位置
	int pos = findArrayList(table, val);
	if (pos == -1)
	{
		printf("No element found\n");
		return;
	}
	//2、将[pos+1, len)区间的数据搬移到[pos， len-1)
	for (int i = pos + 1; i < table->len; i++)
	{
		table->data[i - 1] = table->data[i];
		--table->len;
	}
}

//扩容，下标