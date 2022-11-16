#pragma once
// 연산자 오버로딩, 상속, friend, 래퍼런스, const, 동적할당, 템플릿
#include "Card.h"
#include "Player.h"
#include "Token.h"

//class Card;
//class Player;
//class Token;

void gotoxy(short, short);

class Splendor
{
	//플레이어, 카드, 토큰
	//Value 구조체, Price 구조체
private:
	Card c1[40];
	Card c2[30];
	Card c3[20];
	Player* p;
	Token* t;
public:
	//생성자
	Splendor() : c1{}, c2{}, c3{}, p{}, t{} {}
	Splendor(int num);
	~Splendor() { delete[] p; delete t; }

	//게임 정보
	void print_action(const short, const short);

	//카드 정보
	void print_card(int ,const int, const int);
	void print_card2(int ,const int, const int);
	void print_card3(int ,const int, const int);

	//토큰 정보
	void print_token(const short, const short);

	//플레이어 정보
	void print_player(int, const short,const short);
	void print_bookcard(const short, const short);	//TODO:

	//플레이어 액션
	void action(int, int);	//TODO:

	//리턴
	Player* get_player(int player) { return &p[player]; }

	//게임 종료
	

};