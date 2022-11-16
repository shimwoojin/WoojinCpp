#pragma once
// ������ �����ε�, ���, friend, ���۷���, const, �����Ҵ�, ���ø�
#include "Card.h"
#include "Player.h"
#include "Token.h"

//class Card;
//class Player;
//class Token;

void gotoxy(short, short);

class Splendor
{
	//�÷��̾�, ī��, ��ū
	//Value ����ü, Price ����ü
private:
	Card c1[40];
	Card c2[30];
	Card c3[20];
	Player* p;
	Token* t;
public:
	//������
	Splendor() : c1{}, c2{}, c3{}, p{}, t{} {}
	Splendor(int num);
	~Splendor() { delete[] p; delete t; }

	//���� ����
	void print_action(const short, const short);

	//ī�� ����
	void print_card(int ,const int, const int);
	void print_card2(int ,const int, const int);
	void print_card3(int ,const int, const int);

	//��ū ����
	void print_token(const short, const short);

	//�÷��̾� ����
	void print_player(int, const short,const short);
	void print_bookcard(const short, const short);	//TODO:

	//�÷��̾� �׼�
	void action(int, int);	//TODO:

	//����
	Player* get_player(int player) { return &p[player]; }

	//���� ����
	

};