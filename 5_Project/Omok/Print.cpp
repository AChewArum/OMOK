#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <windows.h>



extern void gotoxy(short x, short y);

int gameCount = 1;
int STATUS_X_LOG = 37;
int STATUS_Y_LOG = 20;



void initPrint()
{
	gameCount = 1;
}

void winmessage(int i) {
	system("cls");
	gotoxy(STATUS_X_LOG - 2, STATUS_Y_LOG -2);
	printf("『게임 종료』");
	gotoxy(STATUS_X_LOG, STATUS_Y_LOG);
	if (i) {
		printf("WHITE WIN");
	}
	else {
		printf("BLACK WIN");
	}
	gotoxy(STATUS_X_LOG-10, STATUS_Y_LOG+6);
	printf("아무 키보드 키를 입력해서 재시작");
}

void printStatus(int i)
{

	gotoxy(STATUS_X_LOG - 3, STATUS_Y_LOG + 3);
	switch (i)
	{
	case 0:
		gotoxy(STATUS_X_LOG - 9, STATUS_Y_LOG + 3);
		printf("                                          ");
		gotoxy(STATUS_X_LOG - 3, STATUS_Y_LOG + 3);
		printf("『오목   배치』");
		break;
	case 1:
		printf("『오목   배치』");
		break;
	case 2:
		printf("『판     회전』");
		break;
	case 4:
		printf("『재배치 바람』");
		break;
		break;
	}
}

//로그 출력
void printLOG(int x, int y, int lr, int i, int pan)
{
	static int logline = 0;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

	if (logline > 5)
	{
		logline = 0;
	}
	if (lr == 1)
	{
		gotoxy(0, STATUS_Y_LOG + 12 + logline);
		if (i == 0)
		{

			printf("[%d]회차 [흑]이 [%d,%d] 지점에 돌을 놓고 [%d]번째 판을 [%s] 방향으로 회전 시켰습니다.  \n", gameCount, x / 4 - 6, y / 2 - 4, pan, "왼쪽");

		}

		else if (i == 1)
		{
			printf("[%d]회차 [백]이 [%d,%d] 지점에 돌을 놓고 [%d]번째 판을 [%s] 방향으로 회전 시켰습니다.  \n", gameCount, x / 4 - 6, y / 2 - 4, pan, "왼쪽");

		}
	}
	else if (lr == 2)
	{
		gotoxy(0, STATUS_Y_LOG + 12 + logline);
		if (i == 0)
		{

			printf("[%d]회차 [흑]이 [%d,%d] 지점에 돌을 놓고 [%d]번째 판을 [%s] 방향으로 회전 시켰습니다.\n", gameCount, x / 4 - 6, y / 2 - 4, pan, "오른쪽");

		}

		else if (i == 1)
		{
			printf("[%d]회차 [백]이 [%d,%d] 지점에 돌을 놓고 [%d]번째 판을 [%s] 방향으로 회전 시켰습니다.\n", gameCount, x / 4 - 6, y / 2 - 4, pan, "오른쪽");
		}
	}

	logline++;
	gameCount++;


}

void printturn(int i)
{

	gotoxy(STATUS_X_LOG - 2, STATUS_Y_LOG + 6);
	if (i)
	{
		printf("『백의 차례』");
	}
	else
	{
		printf("『흑의 차례』");
	}
}

void PrintBase() {
	gotoxy(STATUS_X_LOG - 6, STATUS_Y_LOG + 3);
	printf("『마우스 클릭시 시작』");
	gotoxy(STATUS_X_LOG - 2, STATUS_Y_LOG - 20);
	printf("『게임 방법』");
	gotoxy(STATUS_X_LOG - 11, STATUS_Y_LOG - 19);
	printf("1. 판의 교차점을 클릭하여 알 놓기");
	gotoxy(STATUS_X_LOG - 15, STATUS_Y_LOG - 18);
	printf("2. 돌리고 싶은 판(3*3) 안을 클릭하여 회전");
	gotoxy(STATUS_X_LOG - 11, STATUS_Y_LOG - 17);
	printf("※클릭한 버튼의 방향으로 회전");
	gotoxy(STATUS_X_LOG - 2, STATUS_Y_LOG - 15);
	printf("『승리 조건』");
	gotoxy(STATUS_X_LOG - 16, STATUS_Y_LOG - 14);
	printf("『알을 놓았을 때 알이 일렬로 5개이상 있을시』");
	gotoxy(STATUS_X_LOG - 20, STATUS_Y_LOG - 13);
	printf("『판을 회전시켰을 때 알이 일렬로 5개이상 있을시』");

	//로그창
	gotoxy(STATUS_X_LOG + 1, STATUS_Y_LOG + 10);
	printf("[ L O G ]");
	gotoxy(0, STATUS_Y_LOG + 11);
	printf("------------------------------------------------------------------------------------------");
}
