#pragma once

#define ROW 3

#define COL 3

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

void InitBoard(char board[ROW][COL], int row, int col);
// 初始化棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);
// 显示棋盘
void PlayerMove(char board[ROW][COL], int row, int col);
// 玩家下棋
void ComputerMove(char board[ROW][COL], int row, int col);
// 电脑下棋
char IsWin(char board[ROW][COL], int row, int col);
// 判断输赢
char Row_Win(char board[ROW][COL], int row, int col);
// 判断行
char Col_Win(char board[ROW][COL], int row, int col);
// 判断列
char You_Win(char board[ROW][COL], int row, int col);
// 判断对角线
int Order(void);
// 随机数先手后手