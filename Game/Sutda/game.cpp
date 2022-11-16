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
	printf("1. ����\t : �ش� ���忡�� ���ݱ��� ������ ���� �¸��� ��� �����ϰ� ���\n");
	printf("2. ��\t : �� ����� ������ ��ŭ�� ���� �ɰ� ���� �����⸦ ��û\n");
	printf("3. ����\t : �� ���� 50%% ����\n");
	printf("4. ����\t : �� ���� 25%% ����\n");
	printf("5. ����\t : �ջ���� �� ���� 2�� ����\n");
	printf("6. üũ\t : ���� ���� �ʰ� ������ �ѱ�\n");
	printf("7. ��\t : ó���� �´� �⺻ ���� ��ŭ�� ����(������ ����� ����)\n");
	printf("8. Ǯ\t : �� ����ŭ ����\n");
	printf("9. ����\t : ���� �� ����\n");
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
	case DIE:		//����
		die(player);
		break;
	case CALL:		//��
		call(player);
		break;
	case HALF:		//����
		half(player);
		break;
	case QUARTER:		//����
		quarter(player);
		break;
	case DDADANG:		//����
		ddadang(player);
		break;
	case CHECK:		//üũ
		check(player);
		break;
	case BBING:		//��
		bbing(player);
		break;
	case FULL:		//Ǯ
		full(player);
		break;
	case ALLIN:		//����
		allin(player);
		break;
	default:
		break;
	}
}



