
#include "game.h"

void game()
{	
	char ret;
	char board[ROW][COL] = {0};
	//��ʼ������
	InitBoard(board,ROW,COL);
	//���̴�ӡ
	DisplayBoard(board,ROW,COL);
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = Iswin(board, ROW, COL);//�ж���Ӯ
		if (ret != 'C')
		{
			break;
		}
		//��������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		Iswin(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("���Ӯ");
	}
	else if (ret == '#')
	{
		printf("����Ӯ");
	}
	else
	{
		printf("ƽ��");
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
		printf("��ѡ��:>\n");
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