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
	printf("������ ���᡻");
	gotoxy(STATUS_X_LOG, STATUS_Y_LOG);
	if (i) {
		printf("WHITE WIN");
	}
	else {
		printf("BLACK WIN");
	}
	gotoxy(STATUS_X_LOG-10, STATUS_Y_LOG+6);
	printf("�ƹ� Ű���� Ű�� �Է��ؼ� �����");
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
		printf("������   ��ġ��");
		break;
	case 1:
		printf("������   ��ġ��");
		break;
	case 2:
		printf("����     ȸ����");
		break;
	case 4:
		printf("�����ġ �ٶ���");
		break;
		break;
	}
}

//�α� ���
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

			printf("[%d]ȸ�� [��]�� [%d,%d] ������ ���� ���� [%d]��° ���� [%s] �������� ȸ�� ���׽��ϴ�.  \n", gameCount, x / 4 - 6, y / 2 - 4, pan, "����");

		}

		else if (i == 1)
		{
			printf("[%d]ȸ�� [��]�� [%d,%d] ������ ���� ���� [%d]��° ���� [%s] �������� ȸ�� ���׽��ϴ�.  \n", gameCount, x / 4 - 6, y / 2 - 4, pan, "����");

		}
	}
	else if (lr == 2)
	{
		gotoxy(0, STATUS_Y_LOG + 12 + logline);
		if (i == 0)
		{

			printf("[%d]ȸ�� [��]�� [%d,%d] ������ ���� ���� [%d]��° ���� [%s] �������� ȸ�� ���׽��ϴ�.\n", gameCount, x / 4 - 6, y / 2 - 4, pan, "������");

		}

		else if (i == 1)
		{
			printf("[%d]ȸ�� [��]�� [%d,%d] ������ ���� ���� [%d]��° ���� [%s] �������� ȸ�� ���׽��ϴ�.\n", gameCount, x / 4 - 6, y / 2 - 4, pan, "������");
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
		printf("������ ���ʡ�");
	}
	else
	{
		printf("������ ���ʡ�");
	}
}

void PrintBase() {
	gotoxy(STATUS_X_LOG - 6, STATUS_Y_LOG + 3);
	printf("�����콺 Ŭ���� ���ۡ�");
	gotoxy(STATUS_X_LOG - 2, STATUS_Y_LOG - 20);
	printf("������ �����");
	gotoxy(STATUS_X_LOG - 11, STATUS_Y_LOG - 19);
	printf("1. ���� �������� Ŭ���Ͽ� �� ����");
	gotoxy(STATUS_X_LOG - 15, STATUS_Y_LOG - 18);
	printf("2. ������ ���� ��(3*3) ���� Ŭ���Ͽ� ȸ��");
	gotoxy(STATUS_X_LOG - 11, STATUS_Y_LOG - 17);
	printf("��Ŭ���� ��ư�� �������� ȸ��");
	gotoxy(STATUS_X_LOG - 2, STATUS_Y_LOG - 15);
	printf("���¸� ���ǡ�");
	gotoxy(STATUS_X_LOG - 16, STATUS_Y_LOG - 14);
	printf("������ ������ �� ���� �Ϸķ� 5���̻� �����á�");
	gotoxy(STATUS_X_LOG - 20, STATUS_Y_LOG - 13);
	printf("������ ȸ�������� �� ���� �Ϸķ� 5���̻� �����á�");

	//�α�â
	gotoxy(STATUS_X_LOG + 1, STATUS_Y_LOG + 10);
	printf("[ L O G ]");
	gotoxy(0, STATUS_Y_LOG + 11);
	printf("------------------------------------------------------------------------------------------");
}
