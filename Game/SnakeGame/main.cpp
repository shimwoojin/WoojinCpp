//main.cpp

#include<iostream>
#include<windows.h>
#include "Object.h"
#include "GameInitialize.h"

int game();

int main()
{
	SetConsoleView();
	CursorView();

	gotoxy(9, 10);
	std::cout << "WELCOME SNAKE GAME!!" << std::endl;
	Sleep(1000);
	system("cls");

	while (1)
	{
		int snakeGame = -1;
		snakeGame = game();
		if (snakeGame == 0) break;
		else
		{
			system("cls");
			gotoxy(12, 10);
			std::cout << "YOU DIE!" << std::endl;
			Sleep(1000);
		}
	}

	std::cout << "지렁이 게임 Clear!!" << std::endl;

	return 0;
}

int game()
{
	Object* snake = new Snake(5);
	std::vector<Item> item;
	//item.push_back(Item());

	while (1)
	{
		//update
		if (item.empty()) item.push_back(Item());
		static_cast<Snake*>(snake)->update(item[0]);

		//게임 조건 체크
		if (static_cast<Snake*>(snake)->getIsDead() == true)
		{
			delete[] snake;
			return 1;
		}
		if (static_cast<Snake*>(snake)->getSize() > 25) break;
		if (item[0].getIsUsed() == true) item.clear();

		//render
		system("cls");
		print_map();
		snake->printObject();
		if (!item.empty()) item[0].printObject();
	}

	delete[] snake;
	return 0;
}
