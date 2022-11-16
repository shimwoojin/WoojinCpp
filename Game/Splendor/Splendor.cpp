#include <iostream>
#include <windows.h>
#include "Splendor.h"
#include "Card.h"
#include "Player.h"
#include "Token.h"

void gotoxy(short x, short y) {
	COORD pos = { x,y }; //x, y ��ǥ ����
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //Ŀ�� ����
}

Splendor::Splendor(int num)
{
	Card start;
	start.setting(c1, c2, c3);

	if (num == 2)
	{
		p = new Player[2];
		t = new Token(2);
	}

	else if (num == 3)
	{
		p = new Player[3];
		t = new Token(3);
	}

	else if (num == 4)
	{
		p = new Player[4];
		t = new Token(4);
	}

	else
	{
		exit(1);
	}
}

void Splendor::print_action(const short x, const short y)
{
	using std::cout;
	using std::endl;
	
	gotoxy(x, y);
	cout << "  <<�ൿ>>" << endl;
	gotoxy(x, y+1);
	cout << "1. ��ū ��������" << endl;
	gotoxy(x, y+2);
	cout << "2. ī�� ���ϱ�" << endl;
	gotoxy(x, y+3);
	cout << "3. ī�� �����ϱ�" << endl;
	
}

void Splendor::print_card(int i, const int x, const int y)
{
	using std::cout;
	using std::endl;
	gotoxy(x, y);
	cout << "==================" << endl;
	gotoxy(x, y+1);
	if (c1[i].V_green() != 0)		cout << "+1 �׸�      " << c1[i].Score() << "��" << endl;
	if (c1[i].V_blue() != 0)		cout << "+1 ���      " << c1[i].Score() << "��" << endl;
	if (c1[i].V_red() != 0)			cout << "+1 ����      " << c1[i].Score() << "��" << endl;
	if (c1[i].V_black() != 0)		cout << "+1 ��      " << c1[i].Score() << "��" << endl;
	if (c1[i].V_silver() != 0)		cout << "+1 �ǹ�      " << c1[i].Score() << "��" << endl;
	gotoxy(x, y+2);
	cout << "==================" << endl;
	gotoxy(x, y+3);
	if (c1[i].P_green() != 0) cout << "�׸� : " << c1[i].P_green() << endl;
	gotoxy(x, y + 4);
	if (c1[i].P_blue() != 0) cout << "��� : " << c1[i].P_blue() << endl;
	gotoxy(x, y + 5);
	if (c1[i].P_red() != 0) cout << "���� : " << c1[i].P_red() << endl;
	gotoxy(x, y + 6);
	if (c1[i].P_black() != 0) cout << "�� : " << c1[i].P_black() << endl;
	gotoxy(x, y + 7);
	if (c1[i].P_silver() != 0) cout << "�ǹ� : " << c1[i].P_silver() << endl;
}

void Splendor::print_card2(int i, const int x, const int y)
{
	using std::cout;
	using std::endl;
	gotoxy(x, y);
	cout << "==================" << endl;
	gotoxy(x, y + 1);
	if (c2[i].V_green() != 0)		cout << "+1 �׸�      " << c2[i].Score() << "��" << endl;
	if (c2[i].V_blue() != 0)		cout << "+1 ���      " << c2[i].Score() << "��" << endl;
	if (c2[i].V_red() != 0)			cout << "+1 ����      " << c2[i].Score() << "��" << endl;
	if (c2[i].V_black() != 0)		cout << "+1 ��      " << c2[i].Score() << "��" << endl;
	if (c2[i].V_silver() != 0)		cout << "+1 �ǹ�      " << c2[i].Score() << "��" << endl;
	gotoxy(x, y + 2);
	cout << "==================" << endl;
	gotoxy(x, y + 3);
	if (c2[i].P_green() != 0) cout << "�׸� : " << c2[i].P_green() << endl;
	gotoxy(x, y + 4);
	if (c2[i].P_blue() != 0) cout << "��� : " << c2[i].P_blue() << endl;
	gotoxy(x, y + 5);
	if (c2[i].P_red() != 0) cout << "���� : " << c2[i].P_red() << endl;
	gotoxy(x, y + 6);
	if (c2[i].P_black() != 0) cout << "�� : " << c2[i].P_black() << endl;
	gotoxy(x, y + 7);
	if (c2[i].P_silver() != 0) cout << "�ǹ� : " << c2[i].P_silver() << endl;
}

void Splendor::print_card3(int i, const int x, const int y)
{
	using std::cout;
	using std::endl;
	gotoxy(x, y);
	cout << "==================" << endl;
	gotoxy(x, y + 1);
	if (c3[i].V_green() != 0)		cout << "+1 �׸�      " << c3[i].Score() << "��" << endl;
	if (c3[i].V_blue() != 0)		cout << "+1 ���      " << c3[i].Score() << "��" << endl;
	if (c3[i].V_red() != 0)			cout << "+1 ����      " << c3[i].Score() << "��" << endl;
	if (c3[i].V_black() != 0)		cout << "+1 ��      " << c3[i].Score() << "��" << endl;
	if (c3[i].V_silver() != 0)		cout << "+1 �ǹ�      " << c3[i].Score() << "��" << endl;
	gotoxy(x, y + 2);
	cout << "==================" << endl;
	gotoxy(x, y + 3);
	if (c3[i].P_green() != 0) cout << "�׸� : " << c3[i].P_green() << endl;
	gotoxy(x, y + 4);
	if (c3[i].P_blue() != 0) cout << "��� : " << c3[i].P_blue() << endl;
	gotoxy(x, y + 5);
	if (c3[i].P_red() != 0) cout << "���� : " << c3[i].P_red() << endl;
	gotoxy(x, y + 6);
	if (c3[i].P_black() != 0) cout << "�� : " << c3[i].P_black() << endl;
	gotoxy(x, y + 7);
	if (c3[i].P_silver() != 0) cout << "�ǹ� : " << c3[i].P_silver() << endl;
}

void Splendor::print_token(const short x, const short y)
{
	using std::cout;
	using std::endl;

	gotoxy(x, y);
	cout << "  <<��ū>>" << endl;
	gotoxy(x, y + 1);
	cout << "1) �׸� : " << t->Green() << endl;
	gotoxy(x, y + 2);
	cout << "2) ��� : " << t->Blue() << endl;
	gotoxy(x, y + 3);
	cout << "3) ���� : " << t->Red() << endl;
	gotoxy(x, y + 4);
	cout << "4) �� : " << t->Black() << endl;
	gotoxy(x, y + 5);
	cout << "5) �ǹ� : " << t->Silver() << endl;
	gotoxy(x, y + 6);
	cout << "6) ��� : " << t->Gold() << endl;

}

void Splendor::print_player(int num, const short x, const short y)
{
	using std::cout;
	using std::endl;
	
	gotoxy(x, y);
	cout << "�÷��̾� " << num << "�� ��ū : " << p[num].get_token().total() << endl;
	gotoxy(x, y+1);
	cout << "�׸� : " << p[num].get_token().Green() << endl;
	gotoxy(x, y+2);
	cout << "��� : " << p[num].get_token().Blue() << endl;
	gotoxy(x, y+3);
	cout << "���� : " << p[num].get_token().Red() << endl;
	gotoxy(x, y+4);
	cout << "�� : " << p[num].get_token().Black() << endl;
	gotoxy(x, y+5);
	cout << "�ǹ� : " << p[num].get_token().Silver() << endl;
	gotoxy(x, y+6);
	cout << "��� : " << p[num].get_token().Gold() << endl;
	
	gotoxy(x, y+8);
	cout << "�÷��̾� " << num << "�� �ڿ� : " << endl;
	gotoxy(x, y + 9);
	cout << "�׸� : " << p[num].get_Vgreen() << endl;
	gotoxy(x, y + 10);
	cout << "��� : " << p[num].get_Vblue() << endl;
	gotoxy(x, y + 11);
	cout << "���� : " << p[num].get_Vred() << endl;
	gotoxy(x, y + 12);
	cout << "�� : " << p[num].get_Vblack() << endl;
	gotoxy(x, y + 13);
	cout << "�ǹ� : " << p[num].get_Vsilver() << endl;
	gotoxy(x, y + 15);
	cout << "���� : " << p[num].get_score() << endl;
	
	

	
}

void Splendor::action(int player, int action)
{
	static int c1_count = 4, c2_count = 4, c3_count = 4;

	if (action == 1)	//��ū ��������
	{
		std::cout << "��ū ���� : ";
		int token_num = 0;
		std::cin >> token_num;
		if (token_num == 1) return;
		p[player].get_token(*t, token_num);
	}
	else if (action == 2)	//ī�� �����ϱ�
	{
		int row, column;
		std::cout << "�� �� �� ���� ī�� �����ұ�� ? ";
		std::cin >> row;
		std::cin >> column;
		Card card;
		if (row == 1) {
			card = c1[column - 1]; c1[column - 1] = c1[c1_count++];
			if (c1_count >= 40) return;
		}
		if (row == 2) {
			card = c2[column - 1]; c2[column - 1] = c2[c2_count++];
			if (c2_count >= 30) return;
		}
		if (row == 3) {
			card = c3[column - 1]; c3[column - 1] = c3[c3_count++];
			if (c3_count >= 20) return;
		}
		p[player].book_card(card);
		p[player].get_token(*t, 1);
	}
	else if (action == 3)	//ī�� �����ϱ�
	{
		int row, column;
		std::cout << "�� �� �� ���� ī�带 �����ұ�� ? ";
		std::cin >> row;
		std::cin >> column;
		Card card;
		if (row == 1) {
			card = c1[column - 1]; c1[column - 1] = c1[c1_count++];
			if (c1_count >= 40) return;
		}
		if (row == 2) {
			card = c2[column - 1]; c2[column - 1] = c2[c2_count++];
			if (c2_count >= 30) return;
		}
		if (row == 3) {
			card = c3[column - 1]; c3[column - 1] = c3[c3_count++];
			if (c3_count >= 20) return;
		}

		p[player].buy_card(card, *t);

	}

	else return;
}
