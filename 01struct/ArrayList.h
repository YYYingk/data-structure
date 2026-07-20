#pragma once

/* 顺序表 数据结构定义 */
typedef int element_t;
typedef struct
{
	element_t* data; // 指向顺序表的数据正文区域
	int capacity;	 // 顺序表数据正文的最大容量，索引不能取到该值 [0, capacity)
	int len;		 // 数据正文区含有数据数量，尾插法的引索结点
}ArrayList;


/* 顺序表 初始化接口 */
void initArrayList(ArrayList* table, int num);	// 初始化一个表，有表头，需要初始化正文数据
void deleteArrayList(ArrayList*);				// 清除一个表的正文数据内容


ArrayList* creatArrayList(int num);				// 创建一个表，包含表头区和正文数据区
void releaseArrayList(ArrayList* table);		// 释放表头和正文数据区


/* 顺序表 插入接口 尾插法，任意位置插入 */
void push_backArrayList(ArrayList* table, element_t val);
void insertArrayList(ArrayList* table, int pos, int val);


/* 顺序表 遍历显示窗口 */
void showArrayList(const ArrayList* table);


/* 顺序表 查找元素接口，返回索引号 */
int findArrayList(const ArrayList* table, element_t val);


/* 顺序表 删除操作接口，删除某个值 */
void deleteValueArrayList(ArrayList* table, element_t val);