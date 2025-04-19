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
	//初始化棋盘
	InitBoard(board, ROW, COL); 
	DisplayBoard(board, ROW, COL);

	int x = Order();
	if (x == 1)
	{
        printf("玩家先手\n");
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
			printf("玩家赢\n");
		}
		else if (ret == '#')
		{
			printf("电脑赢\n");
		}
		else
		{
			printf("平局\n");
		}
	}

	else if (x == 0)
	{
        printf("电脑先手\n");
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
			printf("玩家赢\n");
		}
		else if (ret == '#')
		{
			printf("电脑赢\n");
		}
		else
		{
			printf("平局\n");
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
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}*/
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择---->");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("baka,你选错了\n");
			break;
		}
	} while (input != 0);
	return 0;
}

