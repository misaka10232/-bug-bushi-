#include <stdio.h>
#include "game.h" 

void menu(void)
{
	printf("*****************************\n");
	printf("******1.play    0.exit*******\n");
	printf("*****************************\n");

}

void game(void)
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL); 
	DisplayBoard(board, ROW, COL);

	int x = Order();
	if (x == 1)
	{
        printf("�������\n");
		while (1)
		{
			PlayerMove(board, ROW, COL);
			DisplayBoard(board, ROW, COL);

			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
			{
				break;
			}
			ComputerMove(board, ROW, COL);
			DisplayBoard(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
			{
				break;
			}
		}
		if (ret == '*')
		{
			printf("���Ӯ\n");
		}
		else if (ret == '#')
		{
			printf("����Ӯ\n");
		}
		else
		{
			printf("ƽ��\n");
		}
	}

	else if (x == 0)
	{
        printf("��������\n");
		while (1)
		{
			ComputerMove(board, ROW, COL);		
			DisplayBoard(board, ROW, COL);

			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
			{
				break;
			}
			PlayerMove(board, ROW, COL);
			DisplayBoard(board, ROW, COL);
			ret = IsWin(board, ROW, COL);
			if (ret != 'C')
			{
				break;
			}
		}
		if (ret == '*')
		{
			printf("���Ӯ\n");
		}
		else if (ret == '#')
		{
			printf("����Ӯ\n");
		}
		else
		{
			printf("ƽ��\n");
		}		
	}
	/*while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}*/
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��---->");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("baka,��ѡ����\n");
			break;
		}
	} while (input != 0);
	return 0;
}

