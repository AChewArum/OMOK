#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <mmsystem.h>
#include "Draw.h"
#include "Logic.h"
#include "Print.h"

#pragma comment(lib,"winmm.lib")





//�⺻ ������ ��ġ ����


//���� ����
int board_org[6][6] = { 0 };
int board_cpy[6][6] = { 0 };


//ȸ�� ���� ����
int R_ADJ_X = 0;
int R_ADJ_Y = 0;
int R_pan = 0;

//���ӻ�Ȳ ���� ����

int gameStatus = 1;
int WinStatus = 0;
int isTurn = 0;


//����ǥ�� ��ġ
int STATUS_X_TURN = 37;
int STATUS_Y_TURN = 5;


int STATUS_Y_ROTATE = 20;
int STATUS_X_ROTATE = 45;

//���콺 �Է� 
INPUT_RECORD rec;
DWORD dwNOER;
HANDLE CIN = 0;
DWORD mode;
int clickturn = 1;


//���� ����
void gotoxy(short x, short y);
void click(int* xx, int* yy, int* lr);
void rotateBoard(int lr);
void CursorView();
void printLogic();
void setColor(int i);
void printLogic()
{
	gotoxy(54, 10);
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			printf("[%d] ",board_cpy[x][y]);
		}
		gotoxy(54, 11+y);
	}


}



void gotoxy(short x, short y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//���콺 ���
void click(int* xx, int* yy, int* lr)
{
	while (1)
	{
		{
			ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // �ܼ�â �Է��� �޾Ƶ���.
			if (rec.EventType == MOUSE_EVENT) {// ���콺 �̺�Ʈ�� ���

				if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
				{ // ���� ��ư�� Ŭ���Ǿ��� ���
					if (clickturn)
					{
						int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
						int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�

						*xx = mouse_x; //x���� �ѱ�
						*yy = mouse_y; //y���� �ѱ�
						*lr = 1; //���콺 Ŭ�����¸� �ѱ�
						clickturn = 0;
						break;
					}
				}
				else if (rec.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
				{ // ���� ��ư�� Ŭ���Ǿ��� ���
					if (clickturn)
					{
						int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
						int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�

						*xx = mouse_x; //x���� �ѱ�
						*yy = mouse_y; //y���� �ѱ�
						*lr = 2; //���콺 Ŭ�����¸� �ѱ�
						clickturn = 0;
						break;
					}
				}
				else
				{
					clickturn = 1;
				}
			}
		}
	}
}

//��ȸ��
void rotateBoard(int lr) {

	int temp[6][6] = { 0 };

	switch (lr)
	{
	case 1:
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				temp[y][2 - x] = board_cpy[x + R_ADJ_X][y + R_ADJ_Y];
			}
		}
		break;

	case 2:
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < 3; x++)
			{
				temp[2 - y][x] = board_cpy[x + R_ADJ_X][y + R_ADJ_Y];
			}
		}
		break;
	default:
		break;
	}

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			board_cpy[x + R_ADJ_X][y + R_ADJ_Y] = temp[x][y];
		}
	}
}

//����ġ üũ
void checkADJ(int x, int y)
{
	if (x < 41 && y < 15) {
		R_ADJ_X = 0;
		R_ADJ_Y = 0;
		R_pan = 1;
	}
	else if (x < 41 && y > 15)
	{
		R_ADJ_X = 0;
		R_ADJ_Y = 3;
		R_pan = 2;
	}
	else if (x > 41 && y < 15)
	{
		R_ADJ_X = 3;
		R_ADJ_Y = 0;
		R_pan = 3;
	}
	else if (x > 41 && y > 15)
	{
		R_ADJ_X = 3;
		R_ADJ_Y = 3;
		R_pan = 4;
	}
}

//Ŀ�� �����
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 0; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//���� ���� �ʱ�ȭ
void init() {
	system("cls");
	gameStatus = 0;
	WinStatus = 0;
	isTurn = 0;
	for (int y = 0; y < 6; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			board_org[x][y] = { 0 };
			board_cpy[x][y] = { 0 };
		}
	}
	PrintBase();
	initPrint();
	drawboard(board_cpy, board_org);
	CIN = GetStdHandle(STD_INPUT_HANDLE); //���콺 ��Ȱ��ȭ
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
}

//���� �Լ�
int main() {
	system("mode con cols=90 lines=40");

	init();

	int xx, yy, lr;
	while (1)
	{

		CursorView();
		click(&xx, &yy, &lr);
		checkADJ(xx, yy);
		switch (gameStatus)
		{
		case 0:

			gameStatus = 1;
			printStatus(gameStatus);
			printStatus(isTurn);
			printturn(isTurn);
			break;
		case 1:
			if (xx % 4 == 3 && yy % 2 == 0 && xx >= 31 && xx <= 51 && yy >= 10 && yy <= 20)
			{
				if (board_cpy[xx / 4 - 7][yy / 2 + -5] == 0)
				{
					if (isTurn)
					{
						board_cpy[xx / 4 - 7][yy / 2 + -5] = 1;
					}
					else
					{
						board_cpy[xx / 4 - 7][yy / 2 + -5] = 2;
					}

					drawboard(board_cpy, board_org);
					WinStatus = checkWin(board_cpy);
					gameStatus = 2;
					printStatus(gameStatus);
					break;
				}
				else
				{
					printStatus(4);
					break;
				}
			}
			else
			{
				gameStatus = 1;
				break;
			}
		case 2:
			if (xx > 30 && xx < 52 && yy < 21 && yy>9)
			{
				//�� ȸ��
				rotateBoard(lr);

				WinStatus = checkWin(board_cpy);
				

				if (!WinStatus)
				{
					
					setColor(isTurn);
					printLOG(xx, yy, lr, isTurn, R_pan);
					drawboard(board_cpy, board_org);
					isTurn = !isTurn;
					printturn(isTurn);
					gameStatus = 1;
					printStatus(gameStatus);
				}
				break;
			}
			else
			{
				gameStatus = 2;
				break;
			}

		default:
			break;
		}




		if (WinStatus>0 )
		{
			drawboard(board_cpy, board_org);
			if (WinStatus == 1)
			{
				winmessage(1);
			}
			else
			{
				winmessage(0);
			}
			
			_getch();
			init();
		}
	}

}






void setColor(int i)
{
	if (!i)
	{
		system("color f0");
	}
	else
	{
		system("color 0f");
	}
	CIN = GetStdHandle(STD_INPUT_HANDLE); //���콺 ��Ȱ��ȭ
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
}



