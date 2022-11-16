#pragma once

struct Card
{
	int month;
	bool is_special;
};

enum jokbo
{
	gt38 = 1,
	gt18,
	gt13,
	t10,
	t9,
	t8,
	t7,
	t6,
	t5,
	t4=10,
	t3,
	t2,
	t1,
	m12,
	m14,
	m19,
	m110,
	m410,
	m46,
	gg9=20,
	gg8,
	gg7,
	gg6,
	gg5,
	gg4,
	gg3,
	gg2,
	gg1,
	gg0=29,
};


void make_card(Card cards[20]);
void show_card(Card cards[20]);
void shuffle(Card cards[20]);

int what_value(Card*, Card*);