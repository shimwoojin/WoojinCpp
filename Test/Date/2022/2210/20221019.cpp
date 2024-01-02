//유정이 섯다 과제코드

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

typedef enum {
	start,
	일월, 이월, 삼월, 사월, 오월, 육월, 칠월, 팔월, 구월, 십월,
	일월광, 이월_, 삼월광, 사월특, 오월_, 육월_, 칠월특, 팔월광, 구월특, 십월_,
	end = 십월_
}card_num;

typedef enum {
	망통 = 30, 한끗_, 한끗, 두끗, 세끗, 네끗, 다섯끗, 여섯끗, 일곱끗, 여덟끗, 갑오,
	세륙, 장사, 장삥, 구삥, 독사, 알리, 사구,
	일땡, 이땡, 삼땡, 사땡, 오땡, 육땡, 칠땡, 팔땡, 구땡, 멍텅구리사구, 삼칠땡잡이, 장땡,
	일팔광땡, 일삼광땡, 암행어사, 삼팔광땡
}card_jokbo;

void shuffle_card(int card[end]);
int check_card(int card_1, int card_2);
void print_card_name(int name);
void print_jokbo_name(int jokbo);
int check_jokbo(int user, int com);

int main()
{
	int card[end] = { 0 };

	int user_jokbo = 0;
	int com_jokbo = 0;

	char start_game = 0;

	int win_count_u = 0;	//user win 횟수
	int win_count_c = 0;	//com win 횟수

	bool game_continue = true;

	while (game_continue)
	{
		system("cls");
		shuffle_card(card);

		int user_card_1 = card[0];
		int user_card_2 = card[1];
		int com_card_1 = card[2];
		int com_card_2 = card[3];

		user_jokbo = check_card(user_card_1, user_card_2);
		com_jokbo = check_card(com_card_1, com_card_2);

		printf("당신의 패는 ");
		print_card_name(user_card_1); print_card_name(user_card_2);
		print_jokbo_name(user_jokbo);
		printf("입니다\n");

		printf("도전하시겠습니까?( y / n ) ");
		scanf_s(" %c", &start_game, sizeof(char));

		if (start_game == 'n')
		{
			printf("게임을 종료합니다\n");
			return 0;
		}

		printf("컴퓨터의 패는 ");
		print_card_name(com_card_1); print_card_name(com_card_2);
		print_jokbo_name(com_jokbo);
		printf("입니다\n");

		if (user_jokbo == 사구 || user_jokbo == 멍텅구리사구 || com_jokbo == 사구 || com_jokbo == 사구)
		{
			printf("게임이 무효입니다\n");
			Sleep(2000);
			continue;
		}
		if (user_jokbo > com_jokbo)
			printf("당신의 %d번째 승리입니다.", ++win_count_u);

		else
			printf("컴퓨터의 %d번째 승리입니다.", ++win_count_c);

		if (win_count_u == 5 || win_count_c == 5)
		{
			game_continue = false;
			printf("\n\n\n");
			printf("게임이 끝났습니다 감사합니다^0^\n\n");
		}

		printf("\n\n");
		printf("다음 게임이 준비중입니다...\n");
		Sleep(2000);

	}
	return 0;
}

void shuffle_card(int card[end])
{
	for (int i = start; i < end; i++)
	{
		card[i] = i + 1;
	}

	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		int a = rand() % 20;
		int b = rand() % 20;

		int temp = card[a];
		card[a] = card[b];
		card[b] = temp;
	}
}

int check_card(int card_1, int card_2)
{
	int check_num = (card_1 + card_2) % 10;

	switch (check_num) {
	case 0:
		if ((card_1 == 십월 && card_2 == 십월_) || (card_1 == 십월_ && card_2 == 십월))
			return 장땡;

		else if ((card_1 == 오월 && card_2 == 오월_) || (card_1 == 오월_ && card_2 == 오월))
			return 오땡;

		else if ((card_1 == 일월 && card_2 == 구월) || (card_1 == 일월 && card_2 == 구월특) ||
			(card_1 == 구월 && card_2 == 일월) || (card_1 == 구월특 && card_2 == 일월) ||
			(card_1 == 구월 && card_2 == 일월광) || (card_1 == 구월특 && card_2 == 일월광) ||
			(card_1 == 일월광 && card_2 == 구월) || (card_1 == 일월광 && card_2 == 구월특))
			return 구삥;

		else if ((card_1 == 사월 && card_2 == 육월) || (card_1 == 사월 && card_2 == 육월_) ||
			(card_1 == 육월 && card_2 == 사월) || (card_1 == 육월_ && card_2 == 사월) ||
			(card_1 == 육월 && card_2 == 사월특) || (card_1 == 육월_ && card_2 == 사월특) ||
			(card_1 == 사월특 && card_2 == 육월) || (card_1 == 사월특 && card_2 == 육월_))
			return 세륙;

		else if ((card_1 == 삼월광 && card_2 == 칠월특) || (card_1 == 칠월특 && card_2 == 삼월광))
			return 삼칠땡잡이;

		else
			return 망통;

	case 1:
		if ((card_1 == 삼월광 && card_2 == 팔월광) || (card_1 == 팔월광 && card_2 == 삼월광))
			return 삼팔광땡;

		else if ((card_1 == 일월 && card_2 == 십월) || (card_1 == 일월 && card_2 == 십월_) ||
			(card_1 == 일월광 && card_2 == 십월) || (card_1 == 일월광 && card_2 == 십월_))
			return 장삥;

		if ((card_1 == 사월특 && card_2 == 칠월특) || (card_1 == 칠월특 && card_2 == 사월특))
			return 암행어사;
		else

			return 한끗;

	case 2:
		if ((card_1 == 육월 && card_2 == 육월_) || (card_1 == 육월_ && card_2 == 육월))
			return 육땡;

		else if ((card_1 == 일월 && card_2 == 일월광) || (card_1 == 일월광 && card_2 == 일월))
			return 일땡;

		else
			return 두끗;

	case 3:
		if ((card_1 == 일월 && card_2 == 이월) || (card_1 == 일월 && card_2 == 이월_) ||
			(card_1 == 이월 && card_2 == 일월) || (card_1 == 이월_ && card_2 == 일월) ||
			(card_1 == 일월광 && card_2 == 이월) || (card_1 == 일월광 && card_2 == 이월_) ||
			(card_1 == 이월 && card_2 == 일월광) || (card_1 == 이월_ && card_2 == 일월광))
			return 알리;

		else if ((card_1 == 사월특 && card_2 == 구월특) || (card_1 == 구월특 && card_2 == 사월특))
			return 멍텅구리사구;

		else if ((card_1 == 사월 && card_2 == 구월) || (card_1 == 사월 && card_2 == 구월특) ||
			(card_1 == 구월 && card_2 == 사월) || (card_1 == 구월특 && card_2 == 사월) ||
			(card_1 == 사월특 && card_2 == 구월) || (card_1 == 구월 && card_2 == 사월특))
			return 사구;

		else
			return 세끗;

	case 4:
		if ((card_1 == 삼월광 && card_2 == 일월광) || (card_1 == 일월광 && card_2 == 삼월광))
			return 일삼광땡;

		else if ((card_1 == 이월 && card_2 == 이월_) || (card_1 == 이월_ && card_2 == 이월))
			return 이땡;

		else if ((card_1 == 칠월 && card_2 == 칠월특) || (card_1 == 칠월특 && card_2 == 칠월))
			return 칠땡;

		else if ((card_1 == 사월 && card_2 == 십월) || (card_1 == 사월 && card_2 == 십월_) ||
			(card_1 == 십월 && card_2 == 사월) || (card_1 == 십월_ && card_2 == 사월) ||
			(card_1 == 십월 && card_2 == 사월특) || (card_1 == 십월_ && card_2 == 사월특) ||
			(card_1 == 사월특 && card_2 == 십월) || (card_1 == 사월특 && card_2 == 십월_))
			return 장사;

		else
			return 네끗;

	case 5:
		if ((card_1 == 사월 && card_2 == 일월) || (card_1 == 사월 && card_2 == 일월광) ||
			(card_1 == 일월 && card_2 == 사월) || (card_1 == 일월광 && card_2 == 사월) ||
			(card_1 == 일월 && card_2 == 사월특) || (card_1 == 일월광 && card_2 == 사월특) ||
			(card_1 == 사월특 && card_2 == 일월) || (card_1 == 사월특 && card_2 == 일월광))
			return 독사;
		else
			return 다섯끗;
	case 6:
		if ((card_1 == 팔월 && card_2 == 팔월광) || (card_1 == 팔월광 && card_2 == 팔월))
			return 팔땡;

		else if ((card_1 == 삼월 && card_2 == 팔월광) || (card_1 == 삼월광 && card_2 == 삼월))
			return 삼땡;

		else
			return 여섯끗;

	case 7:
		return 일곱끗;

	case 8:
		if ((card_1 == 사월 && card_2 == 사월특) || (card_1 == 사월특 && card_2 == 사월))
			return 사땡;

		else if ((card_1 == 구월 && card_2 == 구월특) || (card_1 == 구월특 && card_2 == 구월))
			return 구땡;

		else
			return 여덟끗;

	case 9:
		if ((card_1 == 팔월광 && card_2 == 일월광) || (card_1 == 일월광 && card_2 == 팔월광))
			return 일팔광땡;

		else
			return 갑오;

	default:
		printf("족보에 없는 조합입니다.\n");
		break;
	}
}

void print_card_name(int name)
{
	switch (name)
	{
	case 1: printf(" 일월 "); break;
	case 2: printf(" 이월 "); break;
	case 3: printf(" 삼월 "); break;
	case 4: printf(" 사월 "); break;
	case 5: printf(" 오월 "); break;
	case 6: printf(" 육월 "); break;
	case 7: printf(" 칠월 "); break;
	case 8: printf(" 팔월 "); break;
	case 9: printf(" 구월 "); break;
	case 10: printf(" 십월 "); break;
	case 11: printf(" 일월광 "); break;
	case 12: printf(" 이월 "); break;
	case 13: printf(" 삼월광 "); break;
	case 14: printf(" 사월특 "); break;
	case 15: printf(" 오월 "); break;
	case 16: printf(" 육월 "); break;
	case 17: printf(" 칠월특 "); break;
	case 18: printf(" 팔월광 "); break;
	case 19: printf(" 구월특 "); break;
	case 20: printf(" 십월 "); break;

	default:
		printf("사용하지 않는 카드입니다\n");
		break;
	}
}

void print_jokbo_name(int jokbo)
{
	switch (jokbo)
	{
	case 30: printf(" 망통"); break;
	case 31: printf(" 한끗_"); break;
	case 32: printf(" 한끗"); break;
	case 33: printf(" 두끗"); break;
	case 34: printf(" 세끗"); break;
	case 35: printf(" 넷끗"); break;
	case 36: printf(" 다섯끗"); break;
	case 37: printf(" 여섯끗"); break;
	case 38: printf(" 일곱끗"); break;
	case 39: printf(" 여덟끗"); break;
	case 40: printf(" 갑오"); break;
	case 41: printf(" 세륙"); break;
	case 42: printf(" 장사"); break;
	case 43: printf(" 장삥"); break;
	case 44: printf(" 구삥"); break;
	case 45: printf(" 독사"); break;
	case 46: printf(" 알리"); break;
	case 47: printf(" 사구"); break;
	case 48: printf(" 일땡"); break;
	case 49: printf(" 이땡"); break;
	case 50: printf(" 삼땡"); break;
	case 51: printf(" 사땡"); break;
	case 52: printf(" 오땡"); break;
	case 53: printf(" 육땡"); break;
	case 54: printf(" 칠땡"); break;
	case 55: printf(" 팔땡"); break;
	case 56: printf(" 구땡"); break;
	case 57: printf(" 멍텅구리사구"); break;
	case 58: printf(" 삼칠땡잡이"); break;
	case 59: printf(" 장땡"); break;
	case 60: printf(" 일팔광땡"); break;
	case 61: printf(" 일삼광땡"); break;
	case 62: printf(" 암행어사"); break;
	case 63: printf(" 삼팔광땡"); break;

	default:
		printf("족보에 없는 조합입니다.");
		break;
	}
}

int check_jokbo(int user, int com)
{
	if (user == 암행어사)
	{
		if (com == 삼팔광땡 || com <= 장땡)
			user = 한끗_;
	}

	else if (user == 삼칠땡잡이)
	{
		if (com >= 장땡 || com <= 알리)
			user = 망통;
	}

	else if (user == 멍텅구리사구)
	{
		if (com >= 장땡)
			user = 세끗;
	}

	else if (user == 사구)
	{
		if (com >= 일땡)
			user = 세끗;
	}

	return user;
}