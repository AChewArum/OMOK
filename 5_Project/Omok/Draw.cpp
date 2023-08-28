#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define MAIN_X_ADJ 31
#define MAIN_Y_ADJ 10
extern void gotoxy(short x, short y);


void drawBoardBG()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoxy(MAIN_X_ADJ , MAIN_Y_ADJ);
	for (int y = 0; y < 6 * 2 - 1; y++)
	{
		for (int x = 0; x < 6 * 3 + 3; x++)
		{
			gotoxy(MAIN_X_ADJ + x, MAIN_Y_ADJ + y);
			if (y % 2 == 0) {
				if (x / 10 == 1 && x % 10 == 0 || x / 10 == 1 && x % 10 == 1 || x / 10 == 0 && x % 10 == 9)
				{
					printf(" ");
				}
				else if (x % 4 == 0)
				{
					printf("┼");
				}
				else {
					printf("─");
				}
			}
			else
			{
				if (x % 4 == 0)
				{
					if (y % 3 == 2)
					{
						printf(" ");
					}
					else {
						
						printf("│ ");
					}
				}
				else
				{
					printf(" ");
				}
			}
		}
	}
}



//오목판 출력
void drawboard(int board[6][6], int destboard[6][6]) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	drawBoardBG();
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			gotoxy(x * 4 + 31, y * 2 + 10);
			if (board[x][y] == 1)
			{
				printf("●");
			}
			else if (board[x][y] == 2)
			{
				printf("○");
			}
			else if (board[x][y] == 0)
			{
				if (x == 5)
				{
					printf("┼　");
				}
				else {
					if (x % 3 == 2)
					{
						printf("┼");
					}
					else
					{
						printf("┼─");
					}
				}
				destboard[x][y] = board[x][y];
			}
		}
	}
}