#include "contact.h"


void menu()
{
	printf("/*******************************\n/");
	printf("/*****1.add   2.del***************\n/");
	printf("/****3.search 4.modify*************\n/");
	printf("/****5.show  6.sort****************\n/");
	printf("/********0.exit************\n/");
	printf("/*******************************\n/");



}


int main()
{
	//创建一个通讯录
	struct contact con;
	//初始化通信录
	Initcontact(&con);


	int input;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			Addcontact(&con);
			break;
		case del:
			Delcontact(&con);
			break;
		case search:
			SearchContact(&con);
			break;
		case modify:
			ModifyContact(&con);
			break;
		case show:
			Showcontact(&con);
			break;
		case sort:
			break;
		default:
			break;
		}
	} while (input);
	

	return 0;


}

