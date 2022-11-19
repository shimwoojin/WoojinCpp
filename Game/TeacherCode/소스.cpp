#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<vector>
using namespace std;


// 0.0 1.0  2.0
// ㅁ
enum Object
{
	Player,
	Enemy,
	Bu
};

enum Dir
{
	Up = 'w',
	Left = 'a',
	Right = 'd',
	Down = 's',
};


void gotoxy(int x , int y)
{
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void print_object(Object obj)
{
	switch (obj)
	{
	case Player:
		cout << "ㅁ";
		break;
	case Enemy:
		cout << "ㅇ";
		break;

	case Bu:
		cout << "★";
		break;
	}
}

class Bullet
{
public:
	Bullet(int x, int y, Dir dir)
		: x(x)
		, y(y)
		, dir(dir)
	{

	}

	void Update()
	{
		Move();
	}

	void Render()
	{
		gotoxy(x, y);
		print_object(Bu);
	}

	void Move()
	{
		switch (dir)
		{
		case Up:
			y--;
			break;
		case Down:
			y++;
			break;
		}
	}

public:
	Dir dir;
	int x;
	int y;
};


class Character
{
public:
	Character(Object shape, int x = 0, int y = 0)
		: x(x)
		, y(y)
		, shape(shape)
	{
		pre_move_time = clock();
	}

	void Shoot()
	{
		int bullet_x = x; 
		int bullet_y = y;
		Dir dir;
		if (shape == Player)
			dir = Up;
		else
			dir = Down;

		bullets.emplace_back(bullet_x, bullet_y, dir);
	}

	void Update()
	{
		time_t pre_time;
		time_t cur_time;
		char input = '\0';

		if (shape == Player)
		{
			// 입력 루프
			pre_time = clock();
			while (1)
			{
				cur_time = clock();
				time_t time = cur_time - pre_time;

				if (_kbhit())
				{
					input = _getch();

					switch (input)
					{
					case Up:
						AddMove(0, -1);
						break;

					case Left:
						AddMove(-1, 0);
						break;

					case Right:
						AddMove(+1, 0);
						break;

					case Down:
						AddMove(0, +1);
						break;

					case 'f': 
					case 'F':
						Shoot();
						break;
					}
					break;
				}

				if (time > 100) break;
			} // while (1) 입력 루프
			
		}
		else if(shape == Enemy)
		{
			time_t cur_time = clock();

			if (cur_time - pre_move_time > 300)
			{
				AddMove(0, +1);
				pre_move_time = clock();
			}
		}

		for (auto& ele : bullets)
			ele.Update();

		for (auto iter = bullets.begin(); iter != bullets.end(); )
		{
			if (iter->y > 13 || iter->y < 0)
			{
				iter = bullets.erase(iter);
			}
			else
				iter++;
		}
	}

	void Render()
	{
		gotoxy(x, y);
		print_object(shape);

		for (auto& ele : bullets)
			ele.Render();
	}

	void Shot()
	{

	}

	bool CollsionTset(const Character& other)
	{
		bool b = true;
		b &= x == other.x;
		b &= y == other.y;

		return b;
	}

	bool AddMove(int x, int y)
	{
		bool result = true;

		if (this->x + x >= 0 && this->x + x <= 20) this->x += x;
		else result = false;

		this->y += y;

		return result;
	}



	void SetMove(int x, int t)
	{
		this->x = x;
		this->y = y;
	}

public:
	vector<Bullet> bullets;
	Object shape;

	time_t	pre_move_time;

	int x;
	int y;
};


int main()
{
	Character player(Player, 10, 10);
	vector<Character> enemy;
	enemy.push_back(Character(Enemy, 5));
	enemy.push_back(Character(Enemy, 7));
	enemy.push_back(Character(Enemy, 9));
	enemy.push_back(Character(Enemy, 10));
	

	while (1)
	{
		//===========================================
		//[캐릭터 업데이트]
		//===========================================
		player.Update();

		for (auto& ele : enemy)
			ele.Update();


		//===========================================
		//[캐릭터 충돌처리]
		//===========================================

		// 0 2 3  
		// iterator : 컨테이너의 원소 가리키는 포인터
		for (auto iter = enemy.begin(); iter != enemy.end(); )
		{
			if (player.CollsionTset(*iter) == true)
			{
				iter = enemy.erase(iter);
			}
			else
				iter++;
		}

		//===========================================
		//[적이 맵 범위 벗어나면 삭제]
		//===========================================
		for (auto iter = enemy.begin(); iter != enemy.end(); )
		{
			if (iter->y > 13)
			{
				iter = enemy.erase(iter);
			}
			else
				iter++;
		}

		//===========================================
		//[게임 화면 출력 부분]
		//===========================================
		system("cls");

		player.Render();

		for (auto& ele : enemy)
			ele.Render();


	} // while (1) 메인 게임 루프 


	return 0;
}