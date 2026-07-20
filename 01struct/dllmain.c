#include"DoubleLoopList.h"

DLoopList stu_table;
void test01()
{
	initDLoopList(&stu_table);
	for (int i = 0; i < 5; i++)
	{
		insertDLoopLinkHead(&stu_table, i+100);
	}
	showDLoopLink(&stu_table);
	deleteValueDLoopList(&stu_table, 103);
	showDLoopLink(&stu_table);
	deleteAllDLoopList(&stu_table); 
}

int main()
{
	test01();
	return 0;
}