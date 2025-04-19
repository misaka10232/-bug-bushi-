#pragma once

#define ROW 3

#define COL 3

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

void InitBoard(char board[ROW][COL], int row, int col);
// ��ʼ������
void DisplayBoard(char board[ROW][COL], int row, int col);
// ��ʾ����
void PlayerMove(char board[ROW][COL], int row, int col);
// �������
void ComputerMove(char board[ROW][COL], int row, int col);
// ��������
char IsWin(char board[ROW][COL], int row, int col);
// �ж���Ӯ
char Row_Win(char board[ROW][COL], int row, int col);
// �ж���
char Col_Win(char board[ROW][COL], int row, int col);
// �ж���
char You_Win(char board[ROW][COL], int row, int col);
// �ж϶Խ���
int Order(void);
// ��������ֺ���