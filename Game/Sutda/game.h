#pragma once

enum
{
	DIE = 1,
	CALL,
	HALF,
	QUARTER,
	DDADANG,
	CHECK,
	BBING,
	FULL,
	ALLIN = 9,
};

int who_use_much_money(Player*, int);	//call���� ���� �� ���� ������� ���� ���� ����

void show_action();

int die(Player*);
int call(Player*);
int half(Player*);
int quarter(Player*);
int ddadang(Player*);
int check(Player*);
int bbing(Player*);
int full(Player*);
int allin(Player*);

void do_action(Player*);

