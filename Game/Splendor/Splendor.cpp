#include <iostream>
#include <windows.h>
#include "Splendor.h"
#include "Card.h"
#include "Player.h"
#include "Token.h"

void gotoxy(short x, short y) {
	COORD pos = { x,y }; //x, y 좌표 설정
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //커서 설정
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
	cout << "  <<행동>>" << endl;
	gotoxy(x, y+1);
	cout << "1. 토큰 가져오기" << endl;
	gotoxy(x, y+2);
	cout << "2. 카드 찜하기" << endl;
	gotoxy(x, y+3);
	cout << "3. 카드 구매하기" << endl;
	
}

void Splendor::print_card(int i, const int x, const int y)
{
	using std::cout;
	using std::endl;
	gotoxy(x, y);
	cout << "==================" << endl;
	gotoxy(x, y+1);
	if (c1[i].V_green() != 0)		cout << "+1 그린      " << c1[i].Score() << "점" << endl;
	if (c1[i].V_blue() != 0)		cout << "+1 블루      " << c1[i].Score() << "점" << endl;
	if (c1[i].V_red() != 0)			cout << "+1 레드      " << c1[i].Score() << "점" << endl;
	if (c1[i].V_black() != 0)		cout << "+1 블랙      " << c1[i].Score() << "점" << endl;
	if (c1[i].V_silver() != 0)		cout << "+1 실버      " << c1[i].Score() << "점" << endl;
	gotoxy(x, y+2);
	cout << "==================" << endl;
	gotoxy(x, y+3);
	if (c1[i].P_green() != 0) cout << "그린 : " << c1[i].P_green() << endl;
	gotoxy(x, y + 4);
	if (c1[i].P_blue() != 0) cout << "블루 : " << c1[i].P_blue() << endl;
	gotoxy(x, y + 5);
	if (c1[i].P_red() != 0) cout << "레드 : " << c1[i].P_red() << endl;
	gotoxy(x, y + 6);
	if (c1[i].P_black() != 0) cout << "블랙 : " << c1[i].P_black() << endl;
	gotoxy(x, y + 7);
	if (c1[i].P_silver() != 0) cout << "실버 : " << c1[i].P_silver() << endl;
}

void Splendor::print_card2(int i, const int x, const int y)
{
	using std::cout;
	using std::endl;
	gotoxy(x, y);
	cout << "==================" << endl;
	gotoxy(x, y + 1);
	if (c2[i].V_green() != 0)		cout << "+1 그린      " << c2[i].Score() << "점" << endl;
	if (c2[i].V_blue() != 0)		cout << "+1 블루      " << c2[i].Score() << "점" << endl;
	if (c2[i].V_red() != 0)			cout << "+1 레드      " << c2[i].Score() << "점" << endl;
	if (c2[i].V_black() != 0)		cout << "+1 블랙      " << c2[i].Score() << "점" << endl;
	if (c2[i].V_silver() != 0)		cout << "+1 실버      " << c2[i].Score() << "점" << endl;
	gotoxy(x, y + 2);
	cout << "==================" << endl;
	gotoxy(x, y + 3);
	if (c2[i].P_green() != 0) cout << "그린 : " << c2[i].P_green() << endl;
	gotoxy(x, y + 4);
	if (c2[i].P_blue() != 0) cout << "블루 : " << c2[i].P_blue() << endl;
	gotoxy(x, y + 5);
	if (c2[i].P_red() != 0) cout << "레드 : " << c2[i].P_red() << endl;
	gotoxy(x, y + 6);
	if (c2[i].P_black() != 0) cout << "블랙 : " << c2[i].P_black() << endl;
	gotoxy(x, y + 7);
	if (c2[i].P_silver() != 0) cout << "실버 : " << c2[i].P_silver() << endl;
}

void Splendor::print_card3(int i, const int x, const int y)
{
	using std::cout;
	using std::endl;
	gotoxy(x, y);
	cout << "==================" << endl;
	gotoxy(x, y + 1);
	if (c3[i].V_green() != 0)		cout << "+1 그린      " << c3[i].Score() << "점" << endl;
	if (c3[i].V_blue() != 0)		cout << "+1 블루      " << c3[i].Score() << "점" << endl;
	if (c3[i].V_red() != 0)			cout << "+1 레드      " << c3[i].Score() << "점" << endl;
	if (c3[i].V_black() != 0)		cout << "+1 블랙      " << c3[i].Score() << "점" << endl;
	if (c3[i].V_silver() != 0)		cout << "+1 실버      " << c3[i].Score() << "점" << endl;
	gotoxy(x, y + 2);
	cout << "==================" << endl;
	gotoxy(x, y + 3);
	if (c3[i].P_green() != 0) cout << "그린 : " << c3[i].P_green() << endl;
	gotoxy(x, y + 4);
	if (c3[i].P_blue() != 0) cout << "블루 : " << c3[i].P_blue() << endl;
	gotoxy(x, y + 5);
	if (c3[i].P_red() != 0) cout << "레드 : " << c3[i].P_red() << endl;
	gotoxy(x, y + 6);
	if (c3[i].P_black() != 0) cout << "블랙 : " << c3[i].P_black() << endl;
	gotoxy(x, y + 7);
	if (c3[i].P_silver() != 0) cout << "실버 : " << c3[i].P_silver() << endl;
}

void Splendor::print_token(const short x, const short y)
{
	using std::cout;
	using std::endl;

	gotoxy(x, y);
	cout << "  <<토큰>>" << endl;
	gotoxy(x, y + 1);
	cout << "1) 그린 : " << t->Green() << endl;
	gotoxy(x, y + 2);
	cout << "2) 블루 : " << t->Blue() << endl;
	gotoxy(x, y + 3);
	cout << "3) 레드 : " << t->Red() << endl;
	gotoxy(x, y + 4);
	cout << "4) 블랙 : " << t->Black() << endl;
	gotoxy(x, y + 5);
	cout << "5) 실버 : " << t->Silver() << endl;
	gotoxy(x, y + 6);
	cout << "6) 골드 : " << t->Gold() << endl;

}

void Splendor::print_player(int num, const short x, const short y)
{
	using std::cout;
	using std::endl;
	
	gotoxy(x, y);
	cout << "플레이어 " << num << "의 토큰 : " << p[num].get_token().total() << endl;
	gotoxy(x, y+1);
	cout << "그린 : " << p[num].get_token().Green() << endl;
	gotoxy(x, y+2);
	cout << "블루 : " << p[num].get_token().Blue() << endl;
	gotoxy(x, y+3);
	cout << "레드 : " << p[num].get_token().Red() << endl;
	gotoxy(x, y+4);
	cout << "블랙 : " << p[num].get_token().Black() << endl;
	gotoxy(x, y+5);
	cout << "실버 : " << p[num].get_token().Silver() << endl;
	gotoxy(x, y+6);
	cout << "골드 : " << p[num].get_token().Gold() << endl;
	
	gotoxy(x, y+8);
	cout << "플레이어 " << num << "의 자원 : " << endl;
	gotoxy(x, y + 9);
	cout << "그린 : " << p[num].get_Vgreen() << endl;
	gotoxy(x, y + 10);
	cout << "블루 : " << p[num].get_Vblue() << endl;
	gotoxy(x, y + 11);
	cout << "레드 : " << p[num].get_Vred() << endl;
	gotoxy(x, y + 12);
	cout << "블랙 : " << p[num].get_Vblack() << endl;
	gotoxy(x, y + 13);
	cout << "실버 : " << p[num].get_Vsilver() << endl;
	gotoxy(x, y + 15);
	cout << "점수 : " << p[num].get_score() << endl;
	
	

	
}

void Splendor::action(int player, int action)
{
	static int c1_count = 4, c2_count = 4, c3_count = 4;

	if (action == 1)	//토큰 가져오기
	{
		std::cout << "토큰 갯수 : ";
		int token_num = 0;
		std::cin >> token_num;
		if (token_num == 1) return;
		p[player].get_token(*t, token_num);
	}
	else if (action == 2)	//카드 예약하기
	{
		int row, column;
		std::cout << "몇 행 몇 열의 카드 예약할까요 ? ";
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
	else if (action == 3)	//카드 구매하기
	{
		int row, column;
		std::cout << "몇 행 몇 열의 카드를 구매할까요 ? ";
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
