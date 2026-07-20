#include"LinkLoopList.h"
#include<stdio.h>

void test01()
{
	LinkLoop link_loop;
	initLinkLoop(&link_loop);

	for (int i = 0; i < 10; i++)
	{
		//insertLinkLoopHeader(&link_loop, i + 100);
		insertLinkLoopRear(&link_loop, i + 100);
	}
	showLinkLoop(&link_loop);
	deleteLinkLoop(&link_loop, 104);
	showLinkLoop(&link_loop);
	deleteAllLinkLoop(&link_loop);
}

void JosephGameTest()
{
	JosephHead game1 = { NULL,NULL };
	init_JoseGame(&game1, 10);
	showData(&game1);
	printf("start game : \n");
	start_JosephGame(&game1, 3);
}

int main()
{
	//test01();
	JosephGameTest();
	return 0;
}