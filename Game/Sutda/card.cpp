#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "card.h"

void make_card(Card cards[20])
{
	for (int i = 0; i < 20; i++)
	{
		cards[i].month = i % 10 + 1;
		cards[i].is_special = i / 10;
	}
}

void show_card(Card cards[20])
{
	for (int i = 0; i < 20; i++)
	{
		printf("¸î ¿ù : %d\n", cards[i].month);
		printf("±¤ : %d\n", cards[i].is_special);
	}
}

void shuffle(Card cards[20])
{
	srand(time(NULL));
	for (int i = 0; i < 200; i++)
	{
		int a = rand() % 20;
		int b = rand() % 20;
		Card temp = cards[a];
		cards[a] = cards[b];
		cards[b] = temp;
	}
}

int what_value(Card* c1, Card* c2)
{

	if (c1->is_special == 1 && c1->month == 1)			//±¤¶¯
	{
		if (c2->is_special == 1 && c2->month == 3) return gt13;
		if (c2->is_special == 1 && c2->month == 8) return gt18;
	}
	if (c1->is_special == 1 && c1->month == 3)
	{
		if (c2->is_special == 1 && c2->month == 1) return gt13;
		if (c2->is_special == 1 && c2->month == 8) return gt38;
	}
	if (c1->is_special == 1 && c1->month == 8)
	{
		if (c2->is_special == 1 && c2->month == 1) return gt18;
		if (c2->is_special == 1 && c2->month == 3) return gt38;
	}

	if (c1->month == c2->month)		// ¶¯
	{
		if (c1->month == 10) return t10;
		if (c1->month == 9) return t9;
		if (c1->month == 8) return t8;
		if (c1->month == 7) return t7;
		if (c1->month == 6) return t6;
		if (c1->month == 5) return t5;
		if (c1->month == 4) return t4;
		if (c1->month == 3) return t3;
		if (c1->month == 2) return t2;
		if (c1->month == 1) return t1;
	}

	//Áß°£Á·º¸
	if ((c1->month == 1 && c2->month == 2) || (c2->month == 1 && c1->month == 2)) return m12;
	if ((c1->month == 1 && c2->month == 4) || (c2->month == 1 && c1->month == 4)) return m14;
	if ((c1->month == 1 && c2->month == 9) || (c2->month == 1 && c1->month == 9)) return m19;
	if ((c1->month == 1 && c2->month == 10) || (c2->month == 1 && c1->month == 10)) return m110;
	if ((c1->month == 4 && c2->month == 10) || (c2->month == 4 && c1->month == 10)) return m410;
	if ((c1->month == 4 && c2->month == 6) || (c2->month == 4 && c1->month == 6)) return m46;

	//²ý
	if ((c1->month + c2->month) % 10 == 9) return gg9;
	if ((c1->month + c2->month) % 10 == 8) return gg8;
	if ((c1->month + c2->month) % 10 == 7) return gg7;
	if ((c1->month + c2->month) % 10 == 6) return gg6;
	if ((c1->month + c2->month) % 10 == 5) return gg5;
	if ((c1->month + c2->month) % 10 == 4) return gg4;
	if ((c1->month + c2->month) % 10 == 3) return gg3;
	if ((c1->month + c2->month) % 10 == 2) return gg2;
	if ((c1->month + c2->month) % 10 == 1) return gg1;
	if ((c1->month + c2->month) % 10 == 0) return gg0;

	//Æ¯¼ö Á·º¸
	

	return 0;
}


