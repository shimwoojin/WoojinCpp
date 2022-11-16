#include <iostream>
#include <windows.h>
#include "Splendor.h"
#include "Card.h"


int main()
{
	system("mode con:cols=120 lines=60");

	using std::cin;
	using std::cout;
	using std::endl;

	int num = 0;
	int player = 0;
	int action = 0;
	
	cout << "플레이어의 수를 입력하시오 (2~4)" << endl;
	cin >> num;

	Splendor game(num);

	while(1)
	{
		system("cls");

		{	//화면 출력
			for (int i = 0; i < 4; i++)
				game.print_card(i, 1 + i * 25, 1);
			for (int i = 0; i < 4; i++)
				game.print_card2(i, 1 + i * 25, 10);
			for (int i = 0; i < 4; i++)
				game.print_card3(i, 1 + i * 25, 19);

			game.print_token(1, 29);
			game.print_action(26, 29);

			for (int i = 0; i < num; i++)
				game.print_player(i, 1 + i * 25, 37);
		}

		if (player >= num) player = 0;	//차례 초기화

		//플레이어 행동
		cout << "\n플레이어"<< player<< " 행동 입력 : ";
		cin >> action;
		game.action(player, action);

		//승리조건체크
		if (game.get_player(player)->get_score() >= 15)
		{
			std::cout << "플레이어" << player << "의 승리를 축하합니다!!" << endl;
			break;
		}

		++player;	//다음 차례로
	}

	return 0;
}