#pragma once

#include <vector>
#include "Token.h"
#include "Card.h"

#define LIMIT 3

//class Card;
//class Token;

class Player
{
private:
	Token t;
	std::vector<Card> c;
	Card book[LIMIT];
	bool order;
	int limit;
public:
	Player() : t{}, c{}, book{},order(false), limit(0) {};

	//행동
	bool get_token(Token& total_token, const int num);
	bool book_card(Card& card);
	bool buy_card(Card& card, Token&);

	//리턴값
	bool order_on() { order = true; return order; }
	bool order_off() { order = false; return order; }
	Token& get_token() { return t; }
	int get_Vgreen();
	int get_Vblue();
	int get_Vred();
	int get_Vblack();
	int get_Vsilver();
	int get_score();

	

	//수동
};