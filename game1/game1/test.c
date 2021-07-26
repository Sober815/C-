
#include "game.h"

void game()
{	
	char ret;
	char board[ROW][COL] = {0};
	//³õÊ¼»¯ÆåÅÌ
	InitBoard(board,ROW,COL);
	//ÆåÅÌ´òÓ¡
	DisplayBoard(board,ROW,COL);
	while (1)
	{
		//Íæ¼ÒÏÂÆå
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);//ÅÐ¶ÏÊäÓ®
		if (ret != 'C')
		{
			break;
		}
		//µçÄÔÏÂÆå
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		Iswin(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("Íæ¼ÒÓ®");
	}
	else if (ret == '#')
	{
		printf("µçÄÔÓ®");
	}
	else
	{
		printf("Æ½¾Ö");
	}
}

void meue()
{
	printf("*********************\n");
	printf("*****1.play 0. exit*****\n");
	printf("*********************\n");
	

}

void test()
{	
	int input=0;
	srand((unsigned int)time(NULL));
	meue();
	do
	{
		printf("ÇëÑ¡Ôñ:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1: game();
			break;
		case 0: printf("jieshuyouxi\n");
			break;
		default:
			break;
		}
		
	} while (input);
}

int main()
{

	test();
	return 0;

}