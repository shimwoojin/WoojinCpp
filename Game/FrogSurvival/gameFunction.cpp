//gameFunction.cpp

#include <windows.h>
#include <random>
#include "gameFunction.h"

void SetConsoleView()
{
	system("mode con:cols=120 lines=40");
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
	cursorInfo.dwSize = 1; //Ä¿¼­ ±½±â (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ä¿¼­ Visible TRUE(º¸ÀÓ) FALSE(¼û±è)
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