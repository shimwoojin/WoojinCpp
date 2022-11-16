#pragma once

#include <iostream>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define WIDTH 30
#define HEIGHT 20

typedef struct _weapon
{
    char name[50];
    int damage;
    int range;
}Weapon;

Weapon weapon_table[3] = {
{ "오래된 칼", 10,1 },
{ "오래된 활", 10,2 },
{ "최신 활", 10,3 },
};

typedef struct _level
{
    int lv;
    int exp;
}Level;

Level lv_table[5] = {
    { 1,50 },
    { 2,100 },
    { 3,150 },
    { 4,200 },
    { 5,250 }
};

typedef struct _Player
{
    char name[50];
    Level* p_level;
    int exp;
    int hp;
    int attack;
    float critical;
    float atk_ignore;
    Weapon* equip_weapon;
}Player;

typedef struct _monster
{
    char name[50];
    int hp;
    int attack;
    int exp;
    float atk_ignore;
}Monster;

const Monster m_table[3] = {
{ "WhiteGoblin",100,20,50,0.0 },
{ "BlackGoblin",120,25,75,0.0 },
{ "GreenGoblin",150,30,100,0.0 }
};

typedef enum
{
    blank = 0,
    wall,
    player,
    monster,
    heal,
    weapon
} object;

typedef enum
{
    up = 'w',
    down = 's',
    left = 'a',
    right = 'd',
    attack = 32,     // space바
} move_dir;

typedef struct
{
    int x;
    int y;
} location;

int map[HEIGHT][WIDTH] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,3,0,0,3,0,0,0,3,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},//5
    {1,4,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,5,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},//10
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1},
    {1,3,0,0,0,0,0,0,0,1,1,3,0,0,0,0,0,0,0,1,1,3,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},//15
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1},
    {1,3,0,0,0,0,0,0,0,1,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},//20
};

void move(location* const p, const location* const dir, Player*);
void print_p_info(Player* player);
void mini_rpg(Player* player);
void print_map();
Player init_player();
void Attack(location* const p, Player* player);
void level_up(Player*);

void mini_rpg(Player* player)
{
    location p;
    p.x = 1;
    p.y = 1;

    location dir;
    dir.x = 0;
    dir.y = 0;

    move_dir key;

    while (1)
    {
        print_map();
        print_p_info(player);

        if (player->p_level->lv == 5)       //승리 or 패배 조건 체크
        {
            printf("플레이어의 레벨이 5가 되었습니다! 게임 승리입니다!\n");
            break;
        }
        else if (player->hp <= 0)
        {
            printf("플레이어의 체력이 0이 되었습니다..다음에 도전하세요!\n");
            break;
        }

        key = (move_dir)_getch();

        switch (key)
        {
        case up:
            dir.x = 0;
            dir.y = -1;
            break;

        case down:
            dir.x = 0;
            dir.y = 1;
            break;

        case left:
            dir.x = -1;
            dir.y = 0;
            break;

        case right:
            dir.x = 1;
            dir.y = 0;
            break;

        case attack:
            dir.x = 0;
            dir.y = 0;
            Attack(&p, player);
            printf("2초만 기다리세요..\n");
            Sleep(2000);

            break;

        default:
            break;
        }
        move(&p, &dir,player);
        level_up(player);
        

    }






}

void print_map()
{
    system("cls");

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            switch (map[y][x])
            {
            case blank:
            {
                printf("  ");
            }break;
            case wall:
            {
                printf("■");
            }break;
            case player:
            {
                printf("나");
            }break;
            case monster:
            {
                printf("몬");
            }break;
            case heal:
            {
                printf("힐");
            }break;
            case weapon:
            {
                printf("웨");
            }break;
            default:
                break;
            }
        }
        printf("\n");
    }

}

void move(location* const p, const location* const dir, Player* _player)
{
    location dest;
    dest.x = p->x + dir->x;
    dest.y = p->y + dir->y;

    object dest_obj = (object)map[dest.y][dest.x];

    switch (dest_obj)
    {
    case blank:
        map[p->y][p->x] = blank;
        map[dest.y][dest.x] = player;
        p->x = dest.x;
        p->y = dest.y;
        break;

    case wall:
    case player:
        break;
    case monster:
        break;
    case heal:
        _player->hp += 200;
    case weapon:
    {   srand(time(NULL));
        int n = rand() % 3;
        _player->equip_weapon = &weapon_table[n];
    }
    default:
        break;
    }
}

Player init_player()
{

    Player p1 = {
        {NULL},
        &lv_table[0],
        0,
        200,
        50,
        0.3,
        0.2,
        &weapon_table[0]
    };
    printf("이름을 입력하시오 : ");
    scanf_s("%s", p1.name, sizeof(p1.name));

    //p1.attack += p1.equip_weapon->damage;

    return p1;
}


void Attack(location* const p,Player* player)
{
    srand(time(NULL));
    int n = rand() % 3;      //Random 몬스터
    Monster m = m_table[n];

    
        for (int i = 1; i <= player->equip_weapon->range; i++)  //위쪽에 무기 거리만큼 안에 몬스터 있으면
        {
            if (map[p->y - i][p->x] == monster)
            {
                printf("%s를 만났습니다.\n", m.name);
                printf("전투를 진행하겠습니다...\n");
                Sleep(1000);
                while (player->hp >= 0 && m.hp >= 0)
                {
                    m.hp -= (player->attack + player->equip_weapon->damage);
                    player->hp -= m.attack;
                    if (m.hp <= 0)
                    {
                        printf("%s가 죽었습니다!\n", m.name);
                        player->exp += m.exp;
                        map[p->y - i][p->x] = blank;
                        return;
                    }
                    else if (player->hp <= 0)
                    {
                        printf("%s가 죽었습니다!\n", player->name);
                        return;
                    }
                }
            }
        }

        for (int i = 1; i <= player->equip_weapon->range; i++)  //아래쪽에 무기 거리만큼 안에 몬스터 있으면
        {
            if (map[p->y + i][p->x] == monster)
            {
                printf("%s를 만났습니다.\n", m.name);
                printf("전투를 진행하겠습니다...\n");
                Sleep(1000);
                while (player->hp >= 0 && m.hp >= 0)
                {
                    m.hp -= (player->attack + player->equip_weapon->damage);
                    player->hp -= m.attack;
                    if (m.hp <= 0)
                    {
                        printf("%s가 죽었습니다!\n", m.name);
                        player->exp += m.exp;
                        map[p->y + i][p->x] = blank;
                        return;
                    }
                    else if (player->hp <= 0)
                    {
                        printf("%s가 죽었습니다!\n", player->name);
                        return;
                    }
                }
            }
        }

        for (int i = 1; i <= player->equip_weapon->range; i++)  //오른쪽에 무기 거리만큼 안에 몬스터 있으면
        {
            if (map[p->y][p->x + i] == monster)
            {
                printf("%s를 만났습니다.\n", m.name);
                printf("전투를 진행하겠습니다...\n");
                Sleep(1000);
                while (player->hp >= 0 && m.hp >= 0)
                {
                    m.hp -= (player->attack + player->equip_weapon->damage);
                    player->hp -= m.attack;
                    if (m.hp <= 0)
                    {
                        printf("%s가 죽었습니다!\n", m.name);
                        player->exp += m.exp;
                        map[p->y][p->x + i] = blank;
                        return;
                    }
                    else if (player->hp <= 0)
                    {
                        printf("%s가 죽었습니다!\n", player->name);
                        return;
                    }
                }
            }
        }

        for (int i = 1; i <= player->equip_weapon->range; i++)  //왼쪽에 무기 거리만큼 안에 몬스터 있으면
        {
            if (map[p->y][p->x - i] == monster)
            {
                printf("%s를 만났습니다.\n", m.name);
                printf("전투를 진행하겠습니다...\n");
                Sleep(1000);
                while (player->hp >= 0 && m.hp >= 0)
                {
                    m.hp -= (player->attack + player->equip_weapon->damage);
                    player->hp -= m.attack;
                    if (m.hp <= 0)
                    {
                        printf("%s가 죽었습니다!\n", m.name);
                        player->exp += m.exp;
                        map[p->y][p->x - i] = blank;
                        return;
                    }
                    else if (player->hp <= 0)
                    {
                        printf("%s가 죽었습니다!\n", player->name);
                        return;
                    }
                }
            }
        }
       
    
}

void level_up(Player* p)
{
    if ((p->p_level->lv) == 1 && (p->exp) >= (p->p_level->exp))      // 플레이어의 레벨이 1이고 플레이어의 경험치가 1레벨의 요구 경험치보다 높으면
    {
        p->p_level = &lv_table[1];                                   // 다음 레벨로
        p->exp = 0;                                                  // 경험치는 0으로 초기화
    }
    else if ((p->p_level->lv) == 2 && (p->exp) >= (p->p_level->exp))      
    {
        p->p_level = &lv_table[2];
        p->exp = 0;
    }
    else if ((p->p_level->lv) == 3 && (p->exp) >= (p->p_level->exp))      
    {
        p->p_level = &lv_table[3];
        p->exp = 0;
    }
    else if ((p->p_level->lv) == 4 && (p->exp) >= (p->p_level->exp))      
    {
        p->p_level = &lv_table[4];
        p->exp = 0;
    }
}

void print_p_info(Player* player)
{
    printf("플레이어의 이름 : %s\n", player->name);
    printf("플레이어의 LV : %d\n", player->p_level->lv);
    printf("레벨업까지 요구 경험치량 : %d\n", player->p_level->exp);
    printf("플레이어의 현재 exp : %d\n", player->exp);
    printf("플레이어의 hp : %d\n", player->hp);
    printf("플레이어의 기본 공격력 : %d\n", player->attack);
    //printf("플레이어의 크리티컬 확률 : %.2f\n", player->critical);
    //printf("플레이어의 회피 확률 : %.2f\n", player->atk_ignore);
    printf("착용 무기 : %s\n", player->equip_weapon->name);
    printf("무기 공격력: %d\n", player->equip_weapon->damage);
    printf("무기 사거리: %d\n", player->equip_weapon->range);
    printf("\n");
}