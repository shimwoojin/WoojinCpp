#include <stdio.h>
#include "player.h"
#include "game.h"

#define START_MONEY 10000

int money_before = START_MONEY;
int money_all = 0;
int most_use_money = 0;


int who_use_much_money(Player* player, int num_player)
{
	most_use_money = player[0].use_money;
	for (int i = 1; i < num_player; i++)
		if(player[i].use_money>player[i-1].use_money)
			most_use_money = player[i].use_money;
	return 0;
}

void show_action()
{
	printf("=======================================\n");
	printf("1. 다이\t : 해당 라운드에서 지금까지 투자한 돈과 승리를 모두 포기하고 기권\n");
	printf("2. 콜\t : 앞 사람이 베팅한 만큼의 돈을 걸고 판을 끝내기를 신청\n");
	printf("3. 하프\t : 깔린 돈의 50%% 베팅\n");
	printf("4. 쿼터\t : 깔린 돈의 25%% 베팅\n");
	printf("5. 따당\t : 앞사람이 건 돈의 2배 베팅\n");
	printf("6. 체크\t : 돈을 걸지 않고 순서를 넘김\n");
	printf("7. 삥\t : 처음에 냈던 기본 단위 만큼만 베팅(선잡은 사람만 가능)\n");
	printf("8. 풀\t : 깔린 돈만큼 베팅\n");
	printf("9. 올인\t : 가진 돈 전부\n");
	printf("=======================================\n");
}

int die(Player* player)
{
	player->is_play = false;
	player->is_call = true;
	return 0;
}

int call(Player* player)
{
	player->money -= (most_use_money - player->use_money);
	player->use_money += (most_use_money - player->use_money);
	money_all += (most_use_money - player->use_money);
	//money_before = money_before;
	player->is_call = true;
	return (most_use_money - player->use_money);
}

int half(Player* player)
{
	player->is_call = false;
	player->money -= money_all/2;
	player->use_money += money_all/2;
	money_all += money_all / 2;
	money_before = money_all/2;
	return money_all/2;
}

int quarter(Player* player)
{
	player->is_call = false;
	player->money -= money_all / 4;
	player->use_money += money_all/4;
	money_all += money_all / 4;
	money_before = money_all/4;
	return money_all/4;
}

int ddadang(Player* player)
{
	player->is_call = false;
	player->money -= money_before * 2;
	player->use_money += money_before*2;
	money_all += money_before * 2;
	money_before = money_before * 2;
	return money_before * 2;
}

int check(Player* player)
{
	player->is_call = false;
	return 0;
}

int bbing(Player* player)
{
	player->is_call = false;
	player->money -= START_MONEY;
	player->use_money += START_MONEY;
	money_all += START_MONEY;
	money_before = START_MONEY;
	return START_MONEY;
}

int full(Player* player)
{
	player->is_call = false;
	player->money -= money_all;
	player->use_money += money_all;
	money_all += money_all;
	money_before = money_all;
	return money_all;
}

int allin(Player* player)
{
	player->is_call = false;
	player->use_money += (player->money);
	money_all += (player->money);
	money_before = (player->money);
	player->money -= player->money;
	return player->money;
}

void do_action(Player* player)
{
	int action = 0;
	scanf_s("%d", &action);
	switch (action)
	{
	case DIE:		//다이
		die(player);
		break;
	case CALL:		//콜
		call(player);
		break;
	case HALF:		//하프
		half(player);
		break;
	case QUARTER:		//쿼터
		quarter(player);
		break;
	case DDADANG:		//따당
		ddadang(player);
		break;
	case CHECK:		//체크
		check(player);
		break;
	case BBING:		//삥
		bbing(player);
		break;
	case FULL:		//풀
		full(player);
		break;
	case ALLIN:		//올인
		allin(player);
		break;
	default:
		break;
	}
}



