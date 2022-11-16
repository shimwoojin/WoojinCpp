#include "Token.h"
#include <iostream>

Token::Token(int player)
{
	if (player == 2) {
		green = blue = black = red = silver = 4;
		gold = 5;
	}
	else if (player == 3)
	{
		green = blue = black = red = silver = gold = 5;
	}
	else if (player == 4)
	{
		green = blue = black = red = silver = 7;
		gold = 5;
	}
	else
	{
		green = blue = black = red = silver = 0;
		gold = 0;
	}
}
