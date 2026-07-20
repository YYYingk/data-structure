#include<stdio.h>
#include<stdlib.h>
#include"ArrayList.h"

void testTable(ArrayList* table)
{
	//插入五个元素
	for (int i = 0; i < 5; i++)
	{
		push_backArrayList(table, i + 100);
	}
	showArrayList(table);
	//再插入一个
	insertArrayList(table, 0, 500);
	insertArrayList(table, 2, 300);
	//显示表里的所有元素
	showArrayList(table);

	deleteValueArrayList(table, 102);
	showArrayList(table);
}
void test01()
{
	ArrayList table;
	initArrayList(&table, 5);
	testTable(&table);
	deleteArrayList(&table);
}
void test02()
{
	ArrayList* table;
	table = creatArrayList(5);
	testTable(table);
	releaseArrayList(table);
}
int main()
{
	test01();
	printf("====================================");
	test02();

	return 0;
}
//数组：运行前就已经确定了容量，不能扩容
//顺序表：前驱后继

//数据结构就是研究逻辑和存储结构
//元素的逻辑关系
//基础结构上，不断进行约束