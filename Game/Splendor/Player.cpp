#include "Token.h"
#include "Card.h"
#include "Player.h"
#include <iostream>
#include <vector>

bool Player::get_token(Token& total_token, const int num)
{
	enum token {green='1' ,blue = '2', red = '3', black = '4', silver = '5', gold = '6' };

	if (num == 3)
	{
		int count = 0;
		char tk = 0;
		while (count < 3 && total_token.Green() >= 0 && total_token.Blue() >= 0 &&
			total_token.Red() >= 0 && total_token.Black() >= 0 && total_token.Silver() >= 0
			&& get_token().total() < 10)
		{
			std::cin >> tk;

			switch (tk)
			{
			case green:
				if (total_token.Green() - 1 < 0) return false;
				total_token.Green_sub(1);
				t.Green_add(1);
				break;
			case blue:
				if (total_token.Blue() - 1 < 0) return false;
				total_token.Blue_sub(1);
				t.Blue_add(1);
				break;
			case red:
				if (total_token.Red() - 1 < 0) return false;
				total_token.Red_sub(1);
				t.Red_add(1);
				break;
			case black:
				if (total_token.Black() - 1 < 0) return false;
				total_token.Black_sub(1);
				t.Black_add(1);
				break;
			case silver:
				if (total_token.Silver() - 1 < 0) return false;
				total_token.Silver_sub(1);
				t.Silver_add(1);
				break;
			default:
				break;
			}
			count++;
		}
	}

	if (num == 2)
	{
		if (get_token().total() >= 9) return false;

		char tk = 0;
		std::cin >> tk;


		switch (tk)
		{
		case green:
			if (total_token.Green() < 4) return false;
			total_token.Green_sub(2);
			t.Green_add(2);
			break;
		case blue:
			if (total_token.Blue() < 4) return false;
			total_token.Blue_sub(2);
			t.Blue_add(2);
			break;
		case red:
			if (total_token.Red() < 4) return false;
			total_token.Red_sub(2);
			t.Red_add(2);
			break;
		case black:
			if (total_token.Black() < 4) return false;
			total_token.Black_sub(2);
			t.Black_add(2);
			break;
		case silver:
			if (total_token.Silver() < 4) return false;
			total_token.Silver_sub(2);
			t.Silver_add(2);
			break;
		default:
			break;
		}


	}

	if (num == 1)
	{
		if (get_token().total() >= 10) return false;
		if (total_token.Gold() - 1 < 0) return false;
		if (total_token.Gold() >= 0) {
			total_token.Gold_sub(1);
			t.Gold_add(1);
		}
	}
	return true;
}

bool Player::book_card(Card& card)
{
	book[limit++] = card;
	return true;
}

bool Player::buy_card(Card& card, Token& game_t)
{
	//토큰 소모
	{	
		//그린
		if (card.P_green() <= t.Green() + get_Vgreen()) {
			t.Green_sub(card.P_green() - get_Vgreen());
			game_t.Green_add(card.P_green() - get_Vgreen());
		}
		else {
			if (t.Gold() >= card.P_green() - t.Green() - get_Vgreen())
			{
				t.Green_sub(t.Green() - get_Vgreen());
				game_t.Green_add(t.Green() - get_Vgreen());
				t.Gold_sub(card.P_green() - t.Green() - get_Vgreen());
				game_t.Gold_add(card.P_green() - t.Green() - get_Vgreen());
			}
			else return false;
		}

		if (card.P_blue() <= t.Blue() + get_Vblue()) {
			t.Blue_sub(card.P_blue() - get_Vblue());
			game_t.Blue_add(card.P_blue() - get_Vblue());
		}//블루
		else {
			if (t.Gold() >= card.P_blue() - t.Blue() - get_Vblue())
			{
				t.Blue_sub(t.Blue() - get_Vblue());
				game_t.Blue_add(t.Blue() - get_Vblue());
				t.Gold_sub(card.P_blue() - t.Blue() - get_Vblue());
				game_t.Gold_add(card.P_blue() - t.Blue() - get_Vblue());
			}
			else return false;
		}

		if (card.P_blue() <= t.Red() + get_Vred()) {
			t.Red_sub(card.P_blue() - get_Vred());
			game_t.Red_add(card.P_blue() - get_Vred());
		}//레드
		else {
			if (t.Gold() >= card.P_blue() - t.Red() - get_Vred())
			{
				t.Red_sub(t.Red() - get_Vred());
				game_t.Red_add(t.Red() - get_Vred());
				t.Gold_sub(card.P_blue() - t.Red() - get_Vred());
				game_t.Gold_add(card.P_blue() - t.Red() - get_Vred());
			}
			else return false;
		}

		if (card.P_black() <= t.Black() + get_Vblack()) {
			t.Black_sub(card.P_black() - get_Vblack());
			game_t.Black_add(card.P_black() - get_Vblack());
		}//그린
		else {
			if (t.Gold() >= card.P_black() - t.Black() - get_Vblack())
			{
				t.Black_sub(t.Black() - get_Vblack());
				game_t.Black_add(t.Black() - get_Vblack());
				t.Gold_sub(card.P_black() - t.Black() - get_Vblack());
				game_t.Gold_add(card.P_black() - t.Black() - get_Vblack());
			}
			else return false;
		}

		if (card.P_silver() <= t.Silver() + get_Vsilver()) {
			t.Silver_sub(card.P_silver() - get_Vsilver());
			game_t.Silver_add(card.P_silver() - get_Vsilver());
		}//그린
		else {
			if (t.Gold() >= card.P_silver() - t.Silver() - get_Vsilver())
			{
				t.Silver_sub(t.Silver() - get_Vsilver());
				game_t.Silver_add(t.Silver() - get_Vsilver());
				t.Gold_sub(card.P_silver() - t.Silver() - get_Vsilver());
				game_t.Gold_add(card.P_silver() - t.Silver() - get_Vsilver());
			}
			else return false;
		}
	}

	//카드소유
	c.push_back(card);
	
	return true;
}

int Player::get_Vgreen()	//TODO:
{
	int green = 0;
	//while (c != nullptr) green += (get_card()->P_green());
	for (int i = 0; i < c.size(); i++)
		green += c[i].V_green();

	return green;
}

int Player::get_Vblue()
{
	int blue = 0;
	for (int i = 0; i < c.size(); i++)
		blue += c[i].V_blue();

	return blue;
}

int Player::get_Vred()
{
	int red = 0;
	for (int i = 0; i < c.size(); i++)
		red += c[i].V_red();

	return red;
}

int Player::get_Vblack()
{
	int black = 0;
	for (int i = 0; i < c.size(); i++)
		black += c[i].V_black();

	return black;
}

int Player::get_Vsilver()
{
	int silver = 0;
	for (int i = 0; i < c.size(); i++)
		silver += c[i].V_silver();

	return silver;
}

int Player::get_score()
{
	int score = 0;
	for (int i = 0; i < c.size(); i++)
		score += c[i].Score();

	return score;
}
