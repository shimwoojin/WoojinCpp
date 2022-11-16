#pragma once
struct Card;

struct Player
{
	Card* cards;
	Card* cards2;
	int money;
	int use_money;
	bool is_play;
	bool is_call;
};

void set_player(Player*, Card*, int);
void show_money(Player*,int);
void show_card(Player*, int, int);