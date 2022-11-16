//Object.cpp

#include "Object.h"
#include "GameInitialize.h"
#include <iostream>
#include <windows.h>
#include <ctime>
#include <vector>

void Snake::printObject() const
{
	using namespace std;
	gotoxy(position.x, position.y);
	cout << "∂" << endl;
	for (int i = 0; i < size; i++)
	{
		gotoxy(body[i].x, body[i].y);
		cout << "∞" << endl;
	}
}

void Snake::update(Item& item)
{
	time_t pre_time;
	time_t cur_time;
	pre_time = clock();
	while (1) 
	{
		cur_time = clock();
		time_t time = cur_time - pre_time;
		setDirect();
		if (time > (100 - static_cast<time_t>(size))) break;
	}
	move();
	isCollision(item);
	isOutOfBound();
	isCollision();
	if(item.getIsUsed() == true) bodyAddOne();
}

void Snake::move()
{
	position_before.y = position.y;
	position_before.x = position.x;
	switch (direct)
	{
	case Snake::Direct::up:
		position.y -= 1;
		break;
	case Snake::Direct::down:
		position.y += 1;
		break;
	case Snake::Direct::left:
		position.x -= 1;
		break;
	case Snake::Direct::right:
		position.x += 1;
		break;
	default:
		break;
	}
	bodyFollowHead();
}

void Snake::bodyAddOne()
{
	if (body[size - 1].y == body[size - 2].y)
	{
		if (body[size - 1].x < body[size - 2].x)
			body.push_back(Position{ body[size - 1].x - 1, body[size - 1].y });
		else body.push_back(Position{ body[size - 1].x + 1, body[size - 1].y });
	}
	else
	{
		if (body[size - 1].y < body[size - 2].y)
			body.push_back(Position{ body[size - 1].x, body[size - 1].y -1});
		else body.push_back(Position{ body[size - 1].x, body[size - 1].y + 1 });
	}
	sizeUp(1);
}

void Snake::isCollision(Item& item)
{
	if (item.getX() == position.x && item.getY() == position.y)
	{
		item.setIsUsed(true);
		item.setVisible(false);
	}
}

bool Snake::isCollision()
{
	for (int i = 0; i < size; i++)
	{
		if (position.x == body[i].x && position.y == body[i].y)
		{
			is_dead = true;
			return true;
		}
	}
	return false;
}

void Snake::setDirect()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) direct = Direct::left; //왼쪽
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) direct = Direct::right; //오른쪽
	if (GetAsyncKeyState(VK_UP) & 0x8000) direct = Direct::up;  //위
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) direct = Direct::down;	//아래
}

bool Snake::isOutOfBound()
{
	if (position.x > MAPWIDTH - 2 || position.x < 1 || position.y>MAPHEIGHT - 2 || position.y < 1)
	{
		is_dead = true;
		return true;
	}
	return false;
}

void Snake::makeBody(int size)
{
	body.assign(size, { 0,0 });
	body[0].x = position.x - 1;
	body[0].y = position.y;
	//body[0].next = &body[1];
	for (int i = 1; i < size; i++)
	{
		body[i].x = body[i - 1].x - 1;
		body[i].y = body[i - 1].y;
		/*if (i < size - 1) body[i].next = &body[i + 1];
		 else body[i].next = nullptr;*/
	}
}

void Snake::bodyFollowHead()
{
	for (int i = size - 1; i >= 1; i--)
	{
		body[i].x = body[i - 1].x;
		body[i].y = body[i - 1].y;
	}
	body[0].x = position_before.x;
	body[0].y = position_before.y;
}

Item::Item() : Object(), isUsed(false), visible(true)
{
	make_random(&position.x, 1, MAPWIDTH-2);
	make_random(&position.y, 1, MAPHEIGHT-2);
}

void Item::printObject() const
{
	if (visible == true)
	{
		gotoxy(position.x, position.y);
		std::cout << "♪" << std::endl;
	}
}