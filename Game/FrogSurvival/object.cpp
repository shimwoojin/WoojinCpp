//object.cpp

#include <windows.h>
#include <iostream>
#include <ctime>
#include <random>

#include "gameFunction.h"
#include "object.h"

#define MINMAP_X 0
#define MINMAP_Y 0
#define MAXMAP_X 55
#define MAXMAP_Y 35

void Object::move()
{
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) loc.x--; //왼쪽
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) loc.x++; //오른쪽
        if (GetAsyncKeyState(VK_UP) & 0x8000) loc.y--;  //위
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) loc.y++;	//아래
        
        move_strict();

        return;
}

void Object::move_strict()
{
    if (loc.x < MINMAP_X) loc.x = MINMAP_X;
    if (loc.x > MAXMAP_X) loc.x = MAXMAP_X;
    if (loc.y < MINMAP_Y) loc.y = MINMAP_Y;
    if (loc.y > MAXMAP_Y) loc.y = MAXMAP_Y;
    return;
}


void Monster::print_object() {
    SetTextColor(3);
    gotoxy(loc.x, loc.y);
    std::cout << "ㆁ" << std::endl;
}

void Monster::move()
{
    enum{up=1,down,right,left};
    int direct = 0;
    make_random(&direct, 1, 4);
    switch (direct)
    {
    case up:    loc.y--; break;
    case down:  loc.y++; break;
    case right: loc.x++; break;
    case left:  loc.x--; break;
    }
    move_strict();
    return;
}

void Player::print_object()
{
    SetTextColor(0);
    gotoxy(loc.x, loc.y);
    std::cout << "ㅱ" << std::endl;
}

void Player::attack(Monster& m)
{
    //w
    if (GetAsyncKeyState(0x57) & 0x8000) {
        print_attack(Direct::up);
        if (m.get_x() >= loc.x - attack_width && m.get_x() <= loc.x + attack_width
            && m.get_y() >= loc.y - attack_range && m.get_y() < loc.y)
            m.dead();
    }
    //s
    if (GetAsyncKeyState(0x53) & 0x8000) {
        print_attack(Direct::down);
        if (m.get_x() >= loc.x - attack_width && m.get_x() <= loc.x + attack_width
            && m.get_y() <= loc.y + attack_range && m.get_y() > loc.y)
            m.dead();                             
    }
    //a
    if (GetAsyncKeyState(0x41) & 0x8000) {
        print_attack(Direct::left);
        if (m.get_y() >= loc.y - attack_width && m.get_y() <= loc.y + attack_width
            && m.get_x() >= loc.x - attack_range && m.get_x() < loc.x)
            m.dead();
    }
    //d
    if (GetAsyncKeyState(0x44) & 0x8000) {
        print_attack(Direct::right);
        if (m.get_y() >= loc.y - attack_width && m.get_y() <= loc.y + attack_width
            && m.get_x() <= loc.x + attack_range && m.get_x() > loc.x) 
            m.dead();    
    }

}

void Player::getItem(Item& item)
{
    if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
        if (item.get_x() == loc.x && item.get_y() == loc.y) {
            item.Use();
            if (item.get_width() == true) { attack_width += 1; }
            if (item.get_range() == true) { attack_range += 3; }
        }
    }
}

int Player::colision_snake(Snake& s)
{
    if (s.get_headX() == loc.x && s.get_headY() == loc.y) {
        Dead();
        if (isLifeOn() == false) { std::cout << "뱀과 충돌!! 게임 종료" << std::endl;  /*exit(0);*/ return 1; }
    }
    for (int i = 0; i < s.get_size(); i++)
    {
        if (s.get_body()[i].x == loc.x && s.get_body()[i].y == loc.y)
        {
            Dead();
            if (isLifeOn() == false) { std::cout << "뱀과 충돌!! 게임 종료" << std::endl; /*exit(0);*/ return 1; }
        }
    }
    return 0;
}

void Player::print_attack(Direct direct)
{

    switch (direct)
    {
    case Direct::up:   
        for (int i = 1; i <= attack_range; i++)
        {
            for (int j = -attack_width; j <= attack_width; j++)
            {
                gotoxy(loc.x + j, loc.y - i);
                std::cout << "+";
            }
        }
        break;
    case Direct::down:
        for (int i = 1; i <= attack_range; i++)
        {
            for (int j = -attack_width; j <= attack_width; j++)
            {
                gotoxy(loc.x + j, loc.y + i);
                std::cout << "+";
            }
        }
        break;
    case Direct::left:
        for (int i = 1; i <= attack_range; i++)
        {
            for (int j = -attack_width; j <= attack_width; j++)
            {
                gotoxy(loc.x - i, loc.y + j);
                std::cout << "+";
            }
        }
        break;
    case Direct::right:
        for (int i = 1; i <= attack_range; i++)
        {
            for (int j = -attack_width; j <= attack_width; j++)
            {
                gotoxy(loc.x + i, loc.y + j);
                std::cout << "+";
            }
        }
        break;
    default:
        break;
    }

}

void Snake::move_strict()
{
    if (head.x < MINMAP_X) head.x = MINMAP_X;
    if (head.x > MAXMAP_X) head.x = MAXMAP_X;
    if (head.y < MINMAP_Y) head.y = MINMAP_Y;
    if (head.y > MAXMAP_Y) head.y = MAXMAP_Y;
    return;
}

void Snake::initialize(int size)
{
    int head_x;
    int head_y;
    make_random(&head_x, 10, 40);
    make_random(&head_y, 5, 35);
    this->size = size;
    body = new Node[size];
    head = { head_y,head_y,&body[0] };
    for (int i = 0; i < size - 1; i++) {
        body[i].x = head.x - i - 1;
        body[i].y = head.y;
        body[i].next = &body[i + 1];
    }

    body[size - 1].x = head.x - size;
    body[size - 1].y = head.y;
    body[size - 1].next = nullptr;

}


void Snake::move()
{
    enum { up = 1, down, right, left };

    int beforeHead_x = head.x;
    int beforeHead_y = head.y;

    //head_move
    int direct = 0;
    make_random(&direct, 1, 4);
    switch (direct)
    {
    case up:    if (head.y - 1 != body[0].y) head.y--; break;
    case down:	if (head.y + 1 != body[0].y) head.y++; break;
    case right:	if (head.x + 1 != body[0].x) head.x++; break;
    case left:	if (head.x - 1 != body[0].x) head.x--; break;
    }
    //

    body_move(beforeHead_x, beforeHead_y);
    move_strict();
    return;
}

void Snake::body_move(const int beforeHeadX, const int beforeHeadY)
{
    body[0].x = beforeHeadX;
    body[0].y = beforeHeadY;
    
    for (int i = size - 1 ; i >=1; i--) {
        body[i].x = body[i - 1].x;
        body[i].y = body[i - 1].y;
    }
}

void Snake::print_object() const
{
    for (int i = 0; i < size; i++)
    {
        SetTextColor(13);
        gotoxy(body[i].x, body[i].y);
        std::cout << "◇" << std::endl;
    }
    gotoxy(head.x, head.y);
    std::cout << "◎" << std::endl;
}

Item::Item() : make(clock()), erase(clock()), exist(true), Object() {
    make_random(&loc.x, 5, 45);
    make_random(&loc.y, 5, 35);
    int option;
    make_random(&option, 0, 5);
    if (option == 1) { width = true, range = false; }
    else { width = false, range = true; }
}

void Item::print_object() {
    EraseItem();
    if (exist == true)
    {
        SetTextColor(12);
        gotoxy(loc.x, loc.y);
        std::cout << "♥" << std::endl;
    }
}

void Item::SetErase() { erase = clock(); }
