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
	
	cout << "�÷��̾��� ���� �Է��Ͻÿ� (2~4)" << endl;
	cin >> num;

	Splendor game(num);

	while(1)
	{
		system("cls");

		{	//ȭ�� ���
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

		if (player >= num) player = 0;	//���� �ʱ�ȭ

		//�÷��̾� �ൿ
		cout << "\n�÷��̾�"<< player<< " �ൿ �Է� : ";
		cin >> action;
		game.action(player, action);

		//�¸�����üũ
		if (game.get_player(player)->get_score() >= 15)
		{
			std::cout << "�÷��̾�" << player << "�� �¸��� �����մϴ�!!" << endl;
			break;
		}

		++player;	//���� ���ʷ�
	}

	return 0;
}