//main.cpp

#include <iostream>
#include <windows.h>
#include <time.h>

#include "gameFunction.h"
#include "object.h"

int game(const int, const int, const int, const int, const int);
int timeCheck(time_t* start, int limit_time);

int main()
{
	SetConsoleView();
    CursorView();

    while (1)
    {
        system("cls");
        SetTextColor(0);
        gotoxy(20, 20);
        std::cout << "환영합니다!! FrogSurvival!!" << std::endl;
        gotoxy(20, 21);
        std::cout << "1. 게임진행 2. 종료" << std::endl;
        gotoxy(20, 23);
        std::cout << "입력 : ";
        int iscontinue = 0;
        std::cin >> iscontinue;
        
        
        if (iscontinue == 1) {
            int stage1 = game(5, 2, 1, 0, 30); //몬스터 5마리, 아이템 2개, 뱀 1마리, 게임스피드 70 - 0*2 ms, 제한시간 30초
            if (stage1 == 1) continue;
            int stage2 = game(7, 2, 2, 1, 28);
            if (stage2 == 1) continue;
            int stage3 = game(9, 2, 2, 2, 26);
            if (stage3 == 1) continue;
            int stage4 = game(11, 3, 3, 3, 24);
            if (stage4 == 1) continue;
            int stage5 = game(13, 3, 3, 4, 22);
            if (stage5 == 1) continue;
            else if (stage5 == 0) break;
        }
        else if (iscontinue == 2) exit(0);
        else continue;
    }
    gotoxy(20, 23);
    std::cout << "축하합니다!! 모든 스테이지를 클리어하셨습니다!!" << std::endl;
	return 0;
}

int game(const int num_monster, const int num_item, const int num_snake, 
            const int game_speed, const int limit_time)
{
    Player p;
    Snake* s = new Snake[num_snake];
    Monster* m = new Monster[num_monster];
    Item* It = new Item[num_item];
    time_t start = clock();
    time_t end = 0;

    while (1) {
        system("cls");
        SetTextColor(0);

        //캐릭터 행동 입력 받기
        for (int i = 0; i < num_item; i++)
            p.getItem(It[i]);
        for (int i = 0; i < num_monster; i++)
            p.attack(m[i]);
        p.move();

        //캐릭터 외 물체들 행동 정의
        for (int i = 0; i < num_monster; i++)
            m[i].move();
        for (int i = 0; i < num_snake; i++)
            s[i].move();
        for (int i = 0; i < num_snake; i++)
        {
            int iscolision = p.colision_snake(s[i]);
            if (iscolision == 1) {
                delete[] s;
                delete[] It;
                delete[] m;
                return 1;
            }
        }
        
        //화면 출력
        p.print_object();
        for (int i = 0; i < num_snake; i++) s[i].print_object();
        for (int i = 0; i < num_item; i++) It[i].print_object();
        for (int i = 0; i < num_monster; i++) if (m[i].isLifeOn() == true) m[i].print_object();

        //게임 승리 조건 체크
        bool isAnyMonster = false;
        for (int i = 0; i < num_monster; i++)
            isAnyMonster = isAnyMonster || m[i].isLifeOn();

        if (isAnyMonster == false)
        {
            system("cls");
            SetTextColor(0);
            gotoxy(20, 20);
            std::cout << "축하합니다. 게임을 클리어하셨습니다!!" << std::endl;
            gotoxy(20, 21);
            std::cout << "다음 스테이지로 넘어가는 중.." << std::endl;
            Sleep(1000);
            break;
        }

        //게임 실패 조건 체크
        int Tc = timeCheck(&start, limit_time);
        if (Tc == 1) {
            delete[] s;
            delete[] It;
            delete[] m;
            return 1;
        }

        Sleep(70 - game_speed*2);
    }

    delete[] s;
    delete[] It;
    delete[] m;

    return 0;
}

int timeCheck(time_t* start, int limit_time)
{
    time_t end = 0;
    end = clock();
    int limitTime = limit_time;
    limitTime -= static_cast<int>((end - *start) / 1000);
    gotoxy(50, 1);
    std::cout << limitTime << "초" << std::endl;
    if (limitTime <= 0) { 
        gotoxy(20, 10);
        std::cout << "타임 오바" << std::endl;
        return 1; }

    return 0;
}