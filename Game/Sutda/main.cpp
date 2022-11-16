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
	
	printf("플레이어는 총 몇명입니까 ? :");
	scanf_s("%d", &num_player);
	players = (Player*)calloc(num_player, sizeof(Player));

	for(int i=0;i<num_player;i++) players[i].money = 510'000;
	
	while (true)
	{
		bool startgame = true;		//1,2 라운드 while문 제어 변수

		set_player(players, cards, num_player);

		system("cls");

		printf("첫번째 카드를 나눠드리겠습니다.\n\n");

		printf("게임 기본 시작금은 10000원 입니다.\n\n");

		for (int i = 0; i < num_player; i++)
		{
			players[i].money -= START_MONEY;
			players[i].use_money = 10'000;
		}
		money_all = START_MONEY * num_player;
		money_before = START_MONEY;

		Sleep(1500);


		int i = 0;

		while (startgame)		//첫 번째 카드만 가지고 게임
		{
			system("cls");								//가진 돈과 할 수 있는 행동 화면에 출력
			printf("1라운드 : 카드 1장만 가지고 게임합니다\n\n\n");
			printf("플레이어 %d의 차례입니다\n\n", i);
			show_money(players, num_player);
			show_card(players, num_player, 1);
			who_use_much_money(players, num_player);
			show_action();
			//========================================	//살아있는 플레이어라면 행동을 함
			if (players[i].is_play == true) do_action(&players[i]);
			i++;
			if (i >= num_player) i = 0;
			//========================================	//전원 check인지 
			bool check_call = true;						//전원 check라면
														//다음 카드 open하기 위해 break
			for (int j = 0; j < num_player; j++)
			{
				check_call = check_call && players[j].is_call;
			}
			if (check_call == true) break;
			//========================================	//최후의 1인 탄생

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

		}	// while 끝 (1라운드)

		//player의 is_call 초기화
		for (int i = 0; i < num_player; i++) players[i].is_call = false;

		system("cls");
		printf("두번째 카드를 나눠드리겠습니다.\n\n");

		for (int i = 0; i < num_player; i++)
		{
			players[i].cards2 = &cards[num_player + i];
		}
		Sleep(1500);

		while (startgame)		//2라운드
		{
			system("cls");								//가진 돈과 할 수 있는 행동 화면에 출력
			printf("2라운드 : 카드 2장을 가지고 게임합니다\n\n\n");
			printf("플레이어 %d의 차례입니다\n\n", i);
			show_money(players, num_player);
			show_card(players, num_player, 2);
			who_use_much_money(players, num_player);
			show_action();
			//========================================	//살아있는 플레이어라면 행동을 함
			if (players[i].is_play == true) do_action(&players[i]);
			i++;
			if (i >= num_player) i = 0;
			//========================================	//전원 check인지 
			bool check_call = true;						//전원 check라면
														//break 후
			for (int j = 0; j < num_player; j++)		//패 비교 (승부)
			{
				check_call = check_call && players[j].is_call;
			}
			if (check_call == true) break;
			//========================================	//최후의 1인 탄생인지check

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

		}	//while 끝(2라운드)

		bool match_up = true;		// 패를 승부 보기 위함

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


			printf("플레이어 %d의 승리입니다!!\n", most_value);
			printf("플레이어의 money : %d -> %d\n\n", players[most_value].money,
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