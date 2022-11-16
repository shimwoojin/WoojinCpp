#include "GameInitialize.h"
#include <windows.h>
#include <random>
#include <iostream>

void SetConsoleView()
{
	system("mode con:cols=60 lines=25");
	system("title MadeByShimwoojin");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b1110'0000);
}

void SetTextColor(char color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b1110'0000 + color);
}

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void make_random(int* random, int start, int end)
{
	std::random_device rd;
	std::mt19937_64 merssenne(rd());

	std::uniform_int_distribution<> random_(start, end);

	*random = random_(merssenne);
}

void print_map()
{
	using namespace std;
	gotoxy(0, 0);
	for (int i = 0; i < MAPWIDTH; i++)
		cout << "��";
	cout << endl;
	for (int i = 1; i < MAPHEIGHT - 1; i++)
	{
		gotoxy(0, i);
		cout << "��";
		gotoxy(MAPWIDTH - 1, i);
		cout << "��";
	}
	gotoxy(0, MAPHEIGHT - 1);
	for (int i = 0; i < MAPWIDTH; i++)
		cout << "��";
}