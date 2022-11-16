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
			printf("�÷��̾� %d�� ���� money : %d\n", i, players[i].money);
			printf("�÷��̾� %d�� �̹� �ǿ� ����� money : %d\n\n", i, players[i].use_money);
		}
	}
	printf("\n");
	printf("���� ���� ���� �Ӵ� : %d\n", money_all);
	printf("\n");
}

void show_card(Player* player,int num_player,int round)
{
	if (round == 1)
	{
		for (int i = 0; i < num_player; i++)
		{
			printf("�÷��̾� %d�� ���� ī�� : %d�� ", i, player[i].cards->month);
			if (player[i].cards->is_special == true) printf("��\n");
			else printf("��\n");
		}
		printf("\n");
	}

	else if (round == 2)
	{
		for (int i = 0; i < num_player; i++)
		{
			printf("�÷��̾� %d�� ���� ī�� : %d�� ", i, player[i].cards->month);
			if (player[i].cards->is_special == true) printf("��");
			else printf("��");
			printf(", %d�� ", player[i].cards2->month);
			if (player[i].cards->is_special == true) printf("��\n");
			else printf("��\n");
		}
		printf("\n");
	}
	else return;
}
