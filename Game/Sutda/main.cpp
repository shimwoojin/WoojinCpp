#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "card.h"
#include "player.h"
#include "game.h"

#define START_MONEY 10000
extern int money_before;
extern int money_all;
extern int most_use_money;


int main()
{
	Card cards[20] = {};
	int num_player = 0;
	Player* players;
	make_card(cards);
	shuffle(cards);
	//show_card(cards);
	
	printf("�÷��̾�� �� ����Դϱ� ? :");
	scanf_s("%d", &num_player);
	players = (Player*)calloc(num_player, sizeof(Player));

	for(int i=0;i<num_player;i++) players[i].money = 510'000;
	
	while (true)
	{
		bool startgame = true;		//1,2 ���� while�� ���� ����

		set_player(players, cards, num_player);

		system("cls");

		printf("ù��° ī�带 �����帮�ڽ��ϴ�.\n\n");

		printf("���� �⺻ ���۱��� 10000�� �Դϴ�.\n\n");

		for (int i = 0; i < num_player; i++)
		{
			players[i].money -= START_MONEY;
			players[i].use_money = 10'000;
		}
		money_all = START_MONEY * num_player;
		money_before = START_MONEY;

		Sleep(1500);


		int i = 0;

		while (startgame)		//ù ��° ī�常 ������ ����
		{
			system("cls");								//���� ���� �� �� �ִ� �ൿ ȭ�鿡 ���
			printf("1���� : ī�� 1�常 ������ �����մϴ�\n\n\n");
			printf("�÷��̾� %d�� �����Դϴ�\n\n", i);
			show_money(players, num_player);
			show_card(players, num_player, 1);
			who_use_much_money(players, num_player);
			show_action();
			//========================================	//����ִ� �÷��̾��� �ൿ�� ��
			if (players[i].is_play == true) do_action(&players[i]);
			i++;
			if (i >= num_player) i = 0;
			//========================================	//���� check���� 
			bool check_call = true;						//���� check���
														//���� ī�� open�ϱ� ���� break
			for (int j = 0; j < num_player; j++)
			{
				check_call = check_call && players[j].is_call;
			}
			if (check_call == true) break;
			//========================================	//������ 1�� ź��

			int alive_player = 0;

			for (int j = 0; j < num_player; j++)
			{
				alive_player += players[j].is_play;
			}
			if (alive_player == 1) {
				for (int k = 0; k < num_player; k++)
				{
					{
						if (players[k].is_play == true)
						{
							players[k].money += money_all;
							startgame = false;
							break;
						}
					}
				}
				break;
			}
			//========================================

		}	// while �� (1����)

		//player�� is_call �ʱ�ȭ
		for (int i = 0; i < num_player; i++) players[i].is_call = false;

		system("cls");
		printf("�ι�° ī�带 �����帮�ڽ��ϴ�.\n\n");

		for (int i = 0; i < num_player; i++)
		{
			players[i].cards2 = &cards[num_player + i];
		}
		Sleep(1500);

		while (startgame)		//2����
		{
			system("cls");								//���� ���� �� �� �ִ� �ൿ ȭ�鿡 ���
			printf("2���� : ī�� 2���� ������ �����մϴ�\n\n\n");
			printf("�÷��̾� %d�� �����Դϴ�\n\n", i);
			show_money(players, num_player);
			show_card(players, num_player, 2);
			who_use_much_money(players, num_player);
			show_action();
			//========================================	//����ִ� �÷��̾��� �ൿ�� ��
			if (players[i].is_play == true) do_action(&players[i]);
			i++;
			if (i >= num_player) i = 0;
			//========================================	//���� check���� 
			bool check_call = true;						//���� check���
														//break ��
			for (int j = 0; j < num_player; j++)		//�� �� (�º�)
			{
				check_call = check_call && players[j].is_call;
			}
			if (check_call == true) break;
			//========================================	//������ 1�� ź������check

			int alive_player = 0;

			for (int j = 0; j < num_player; j++) 
				alive_player += (int)players[j].is_play;

			if (alive_player == 1) {
				for (int k = 0; k < num_player; k++)
				{
					if (players[k].is_play == true)
					{
						players[k].money += money_all;
						break;
					}
				}
				break;
			}

		}	//while ��(2����)

		bool match_up = true;		// �и� �º� ���� ����

		for (int i = 0; i < num_player; i++)
			match_up = match_up && players[i].is_call;
		
		int* value;
		int most_value = 0;
		value = (int*)calloc(num_player, sizeof(int));
		Card card1, card2;

		while (match_up)
		{
			for (int i = 0; i < num_player; i++)
				value[i] = what_value(players[i].cards, players[i].cards);

			for (int i = 1; i < num_player; i++)
				if (value[i] < value[i - 1]) most_value = i;


			printf("�÷��̾� %d�� �¸��Դϴ�!!\n", most_value);
			printf("�÷��̾��� money : %d -> %d\n\n", players[most_value].money,
			players[most_value].money + money_all);
			players[most_value].money += money_all;
			Sleep(3000);

			match_up = false;
		}

		free(value);

	}

	free(players);
	return 0;
}