#include <stdio.h>
#include <iostream>
#include "card.h"
#include "player.h"

extern int money_all;

void set_player(Player* players, Card* cards, int num_player)
{
	for (int i = 0; i < num_player; i++)
	{
		players[i].cards = &cards[i];
		players[i].use_money = 0;
		players[i].is_play = true;
		players[i].is_call = false;
	}
}

void show_money(Player* players,int num_player)
{
	for (int i = 0; i < num_player; i++)
	{
		if (players[i].is_play == true)
		{
			printf("플레이어 %d의 남은 money : %d\n", i, players[i].money);
			printf("플레이어 %d가 이번 판에 사용한 money : %d\n\n", i, players[i].use_money);
		}
	}
	printf("\n");
	printf("현재 누적 게임 머니 : %d\n", money_all);
	printf("\n");
}

void show_card(Player* player,int num_player,int round)
{
	if (round == 1)
	{
		for (int i = 0; i < num_player; i++)
		{
			printf("플레이어 %d의 현재 카드 : %d월 ", i, player[i].cards->month);
			if (player[i].cards->is_special == true) printf("광\n");
			else printf("띠\n");
		}
		printf("\n");
	}

	else if (round == 2)
	{
		for (int i = 0; i < num_player; i++)
		{
			printf("플레이어 %d의 현재 카드 : %d월 ", i, player[i].cards->month);
			if (player[i].cards->is_special == true) printf("광");
			else printf("띠");
			printf(", %d월 ", player[i].cards2->month);
			if (player[i].cards->is_special == true) printf("광\n");
			else printf("띠\n");
		}
		printf("\n");
	}
	else return;
}
