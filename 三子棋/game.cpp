#include "game.h"
#include <stdio.h>
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
			{
				printf(" %c |", board[i][j]);
			}
			else
			{
				printf(" %c ", board[i][j]);
			}
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			if (i < row - 1)
			{
				if (j < col - 1)
				{
					printf("---|");
				}
				else
				{
					printf("---");
				}
			}
		}
		printf("\n");
		//printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		/*if (i < row - 1)
		{
			printf("---|---|---\n");
		}	*/
	}
}


void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家回合\n");
	while (1)
	{
		printf("请输入坐标\n");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标已被占用，选择其他位置");
			}
		}
		else
		{
			printf("坐标非法\n");
		}
	}
}


void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋\n");
	//int x = 0;
	//int y = 0;
	//while (1)
	//{
	//	x = rand() % row;//0-2   1111
	//							
	//	y = rand() % col;
	//	if (board[x][y] == ' ')
	//	{
	//		board[x][y] = '#';
	//		break;
	//	}
	//}
	if (board[row / 2][col / 2] == ' ')
	{
		board[row / 2][col / 2] = '#';
        return;
	}
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		int num = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == '#')
			{
				num++;
			}
		}
		if (num == row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = '#';
					return;
				}
			}
		}
	}
	/*else
	{
		int i = 0;
		int j = 0;
		for (i = 0; i < row; i++)
		{
			int num = 0;
			for (j = 0; j < col; j++)
			{				
				if (board[i][j] == '#')
				{
					num++;
				}			
			}
			if (num == 2)
			{
				for (j = 0; j < col; j++)
				{
					if (board[i][j] == ' ')
					{
						board[i][j] = '#';
						return;
					}
				}
			}
		}
	}*/
	for (j = 0; j < col; j++)
	{
		int num = 0;
		for (i = 0; i < row; i++)
		{
			if (board[i][j] == '#')
			{
				num++;
			}
		}
		if (num == col - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = '#';
					return;
				}
			}
		}
	}
	for (i = 0; i < row; i++)
	{
		int num = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] =='*')
			{
				num++;
			}
		}
		if (num == row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = '#';
					return;
				}
			}
		}
	}
	for (j = 0; j < col; j++)
	{
		int num = 0;
		for (i = 0; i < row; i++)
		{
			if (board[i][j] == '*')
			{
				num++;
			}
		}
		if (num == col - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = '#';
					return;
				}
			}
		}
	}
	int num = 0;
	for (int i = 0 ; i < row && i < col; i++)
	{
		
		if (board[i][i] == '#')
		{
			num++;
		}
	}
	if (num == row - 1)
	{
		for (int i = 0; i < row && i < col; i++)
		{
			if (board[i][i] == ' ')
			{
				board[i][i] = '#';//主动进攻程序（主）
				return;
			}
            
		}
	}
	num = 0;
    for (int i = 0; i < row && i < col; i++)
	{
		if (board[i][col - 1 - i] == '#')
		{
			num++;
		}
	}
	if (num == row - 1)
	{
		for (int i = 0; i < row && i < col; i++)
		{
			if (board[i][col - 1 - i] == ' ')
			{
				board[i][col - 1 - i] = '#';//主动进攻程序（辅）
				return;
			}
		}
	}
	num = 0;
    for (int i = 0; i < row && i < col; i++)
	{
		if (board[i][col - 1 - i] == '*')
		{
			num++;
		}
	}
	if (num == row - 1)
	{
		for (int i = 0; i < row && i < col; i++)
		{
			if (board[i][col - 1 - i] == ' ')
			{
				board[i][col - 1 - i] = '#';//防守程序（辅）
				return;
			}
		}
	}
	num = 0;
    for (int i = 0; i < row && i < col; i++)
	{
		if (board[i][i] == '*')
		{
			num++;
		}
	}
	if (num == row - 1)
	{
		for (int i = 0; i < row && i < col; i++)
		{
			if (board[i][i] == ' ')
			{
				board[i][i] = '#';//防守程序（主）
				return;
			}
		}
	}
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;//0-2   1111								
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}


int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; i < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}


char IsWin(char board[ROW][COL], int row, int col)
{
	char row_win = Row_Win(board, ROW, COL);
	if (row_win != ' ')
	{
		return row_win;
	}
	char col_win = Col_Win(board, ROW, COL);
	if (col_win != ' ')
	{
		return col_win;
	}
	char you_win = You_Win(board, ROW, COL);
	if (you_win != ' ')
	{
		return you_win;
	}
	if (IsFull(board , row , col))
	{
		return 'Q';
	}
	return 'C';
}


char Row_Win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == ' ')
		{
			continue;
		}
		int win = 1;
		int j = 0;
		for (j = 1; j < col; j++)
		{
			if (board[i][j] != board[i][0])
			{
				win = 0;
				break;
			}
		}
		if (win == 1)
		{
			return board[i][0];
		}
	}
	return ' ';
}


char Col_Win(char board[ROW][COL], int row, int col)
{
	int j = 0;
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == ' ')
		{
			continue;
		}
		int win = 1;
		int i = 0;
		for (i = 1; i < row; i++)
		{
			if (board[i][j] != board[0][j])
			{
				win = 0;
				break;
			}
		}
		if (win == 1)
		{
			return board[0][j];
		}
	}
	return ' ';
}


char You_Win(char board[ROW][COL], int row, int col)
{
	if (board[0][0] != ' ') // 确保第一个字符不为空格
	{
		int win = 1;
		for (int i = 1; i < row && i < col; i++) // 遍历主对角线
		{
			if (board[i][i] != board[0][0])
			{
				win = 0;
				break;
			}
		}
		if (win == 1)
		{
			return board[0][0]; // 主对角线满足胜利条件
		}
	}
	if (board[0][col - 1] != ' ') // 确保第一个字符不为空格
	{
		int win = 1;
		for (int i = 1; i < row && i < col; i++) // 遍历副对角线
		{
			if (board[i][col - 1 - i] != board[0][col - 1])
			{
				win = 0;
				break;
			}
		}
		if (win == 1)
		{
			return board[0][col - 1]; // 副对角线满足胜利条件
		}
	}
	return ' '; // 如果没有对角线满足胜利条件，返回空格
}


int Order(void)
{
	int x = 0;
	x = rand() % 10;//0 1 2 3 4 5 6 7 8 9
	if (x < 5)
	{
        return 1;
	}
	if (x >= 5)
	{
		return 0;
	}
}


