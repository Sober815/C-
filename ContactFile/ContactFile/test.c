#include "contact.h"


void menu()
{
	printf("/*******************************\n/");
	printf("/*****1.add   2.del***************\n/");
	printf("/****3.search 4.modify*************\n/");
	printf("/****5.show  6.sort****************\n/");
	printf("/****7.save  0.exit************\n/");
	printf("/*******************************\n/");



}


int main()
{
	//����һ��ͨѶ¼
	struct contact con;
	//��ʼ��ͨ��¼
	Initcontact(&con);


	int input;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			FreeContact(&con);
			printf("�˳�ͨѶ¼\n");
			break;

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
			SortContact(&con);
			break;
		case save:
			SaveContact(&con);
			break;
		default:
			break;
		}
	} while (input);
	

	return 0;


}

