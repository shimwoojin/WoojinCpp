#include "Card.h"
#include <iostream>
#include <random>
//#include <stdlib.h>
//#include <time.h>

void Card::set_card1(Card cards[40])
{
	// green_value initialization
	cards[0]  = Card(1,0,0,0,0,0,1,1,2,1);
	cards[1]  = Card(1,0,0,0,0,0,1,1,1,1);
	cards[2]  = Card(1,0,0,0,0,0,2,2,0,1);
	cards[3]  = Card(1,0,0,0,0,1,3,0,0,1);
	cards[4]  = Card(1,0,0,0,0,0,1,2,2,0);
	cards[5]  = Card(1,0,0,0,0,0,1,0,0,2);
	cards[6]  = Card(1,0,0,0,0,0,0,3,0,0);
	cards[7]  = Card(1,0,0,0,0,0,0,0,4,0,1);

	//blue_value initialization
	cards[8]  = Card(0,1,0,0,0,0,0,0,3,0);
	cards[9]  = Card(0,1,0,0,0,1,0,1,1,1);
	cards[10] = Card(0,1,0,0,0,1,0,1,2,1);
	cards[11] = Card(0,1,0,0,0,2,0,2,0,1);
	cards[12] = Card(0,1,0,0,0,2,0,0,2,0);
	cards[13] = Card(0,1,0,0,0,0,0,4,0,0,1);
	cards[14] = Card(0,1,0,0,0,3,1,1,0,0);
	cards[15] = Card(0,1,0,0,0,0,0,0,2,1);

	//red_value initialization
	cards[24] = Card(0,0,1,0,0,1,1,0,1,1);
	cards[25] = Card(0,0,1,0,0,1,1,0,1,2);
	cards[26] = Card(0,0,1,0,0,1,0,0,2,2);
	cards[27] = Card(0,0,1,0,0,0,0,2,0,2);
	cards[28] = Card(0,0,1,0,0,0,0,0,0,4,1);
	cards[29] = Card(0,0,1,0,0,0,0,0,0,3);
	cards[30] = Card(0,0,1,0,0,0,0,1,3,1);
	cards[31] = Card(0,0,1,0,0,1,2,0,0,0);

	//black_value initialization
	cards[16] = Card(0,0,0,1,0,1,1,1,0,1);
	cards[17] = Card(0,0,0,1,0,3,0,0,0,0);
	cards[18] = Card(0,0,0,1,0,0,2,1,0,2);
	cards[19] = Card(0,0,0,1,0,2,0,1,0,0);
	cards[20] = Card(0,0,0,1,0,1,2,1,0,1);
	cards[21] = Card(0,0,0,1,0,0,4,0,0,0,1);
	cards[22] = Card(0,0,0,1,0,2,0,0,0,2);
	cards[23] = Card(0,0,0,1,0,1,0,3,1,0);

	//silver_value initialization
	cards[32] = Card(0,0,0,0,1,0,1,0,1,3);
	cards[33] = Card(0,0,0,0,1,0,3,0,0,0);
	cards[34] = Card(0,0,0,0,1,0,0,2,1,0);
	cards[35] = Card(0,0,0,0,1,0,2,0,2,0);
	cards[36] = Card(0,0,0,0,1,2,2,0,1,0);
	cards[37] = Card(0,0,0,0,1,2,1,1,1,0);
	cards[38] = Card(0,0,0,0,1,1,1,1,1,0);
	cards[39] = Card(0,0,0,0,1,4,0,0,0,0,1);
}

void Card::set_card2(Card cards[30])
{
	// green_value initialization
	cards[0]  = Card(1,0,0,0,0,0,2,0,1,4,2,LV::lv2);
	cards[1]  = Card(1,0,0,0,0,2,0,3,0,3,1,LV::lv2);
	cards[2]  = Card(1,0,0,0,0,6,0,0,0,0,3,LV::lv2);
	cards[3]  = Card(1,0,0,0,0,0,3,0,2,2,1,LV::lv2);
	cards[4]  = Card(1,0,0,0,0,5,0,0,0,0,2,LV::lv2);
	cards[5]  = Card(1,0,0,0,0,3,5,0,0,0,2,LV::lv2);

	//blue_value initialization
	cards[6]  = Card(0,1,0,0,0,0,3,0,0,5,2,LV::lv2);
	cards[7]  = Card(0,1,0,0,0,3,2,0,3,0,1,LV::lv2);
	cards[8]  = Card(0,1,0,0,0,0,5,0,0,0,2,LV::lv2);
	cards[9]  = Card(0,1,0,0,0,0,6,0,0,0,3,LV::lv2);
	cards[10] = Card(0,1,0,0,0,2,2,3,0,0,1,LV::lv2);
	cards[11] = Card(0,1,0,0,0,0,0,1,4,2,2,LV::lv2);

	//red_value initialization
	cards[18] = Card(0,0,1,0,0,0,0,2,3,2,1,LV::lv2);
	cards[19] = Card(0,0,1,0,0,0,3,2,3,0,1,LV::lv2);
	cards[20] = Card(0,0,1,0,0,2,4,0,0,1,2,LV::lv2);
	cards[21] = Card(0,0,1,0,0,0,0,6,0,0,3,LV::lv2);
	cards[22] = Card(0,0,1,0,0,0,0,0,5,0,2,LV::lv2);
	cards[23] = Card(0,0,1,0,0,0,0,0,5,3,2,LV::lv2);

	//black_value initialization
	cards[12] = Card(0,0,0,1,0,0,0,0,0,5,2,LV::lv2);
	cards[13] = Card(0,0,0,1,0,5,0,3,0,0,2,LV::lv2);
	cards[14] = Card(0,0,0,1,0,4,1,2,0,0,2,LV::lv2);
	cards[15] = Card(0,0,0,1,0,3,0,0,2,3,1,LV::lv2);
	cards[16] = Card(0,0,0,1,0,0,0,0,6,0,3,LV::lv2);
	cards[17] = Card(0,0,0,1,0,2,2,0,0,3,1,LV::lv2);

	//silver_value initialization
	cards[24] = Card(0,0,0,0,1,0,0,0,0,6,3,LV::lv2);
	cards[25] = Card(0,0,0,0,1,0,3,3,0,2,1,LV::lv2);
	cards[26] = Card(0,0,0,0,1,3,0,2,2,0,1,LV::lv2);
	cards[27] = Card(0,0,0,0,1,0,0,5,0,0,2,LV::lv2);
	cards[28] = Card(0,0,0,0,1,0,0,5,3,0,2,LV::lv2);
	cards[29] = Card(0,0,0,0,1,1,0,4,2,0,2,LV::lv2);
}

void Card::set_card3(Card cards[20])
{
	// green_value initialization
	cards[0]  = Card(1,0,0,0,0,3,7,0,0,0,5,LV::lv3);
	cards[1]  = Card(1,0,0,0,0,3,6,0,0,3,4,LV::lv3);
	cards[2]  = Card(1,0,0,0,0,0,3,3,3,5,3,LV::lv3);
	cards[3]  = Card(1,0,0,0,0,0,7,0,0,0,4,LV::lv3);

	//blue_value initialization
	cards[4]  = Card(0,1,0,0,0,3,0,3,5,3,3,LV::lv3);
	cards[5]  = Card(0,1,0,0,0,0,3,0,3,6,4,LV::lv3);
	cards[6]  = Card(0,1,0,0,0,0,0,0,0,7,4,LV::lv3);
	cards[7]  = Card(0,1,0,0,0,0,3,0,0,7,5,LV::lv3);

	//red_value initialization
	cards[12] = Card(0,0,1,0,0,3,5,0,3,3,3,LV::lv3);
	cards[13] = Card(0,0,1,0,0,7,0,3,0,0,5,LV::lv3);
	cards[14] = Card(0,0,1,0,0,7,0,0,0,0,4,LV::lv3);
	cards[15] = Card(0,0,1,0,0,6,3,3,0,0,4,LV::lv3);
	
	//black_value initialization
	cards[8]  = Card(0,0,0,1,0,3,0,6,3,0,4,LV::lv3);
	cards[9]  = Card(0,0,0,1,0,0,0,7,3,0,5,LV::lv3);
	cards[10] = Card(0,0,0,1,0,5,3,3,0,3,3,LV::lv3);
	cards[11] = Card(0,0,0,1,0,0,0,7,0,0,4,LV::lv3);

	//silver_value initialization
	cards[16] = Card(0,0,0,0,1,0,0,0,7,3,5,LV::lv3);
	cards[17] = Card(0,0,0,0,1,0,0,3,6,3,4,LV::lv3);
	cards[18] = Card(0,0,0,0,1,3,3,5,3,0,3,LV::lv3);
	cards[19] = Card(0,0,0,0,1,0,0,0,7,0,4,LV::lv3);
}

void Card::shuffle(Card* cards, int num)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 200; i++)
	{

		//std::random_device rd;
		//std::mt19937_64 merssenne(rd());
		//std::uniform_int_distribution<> dice(0, num-1);
		//std::uniform_int_distribution<> dice2(0, num-1);
		//Card temp;
		//temp = cards[dice(merssenne)];
		//cards[dice(merssenne)] = cards[dice2(merssenne)];
		//cards[dice2(merssenne)] = temp;

		int a = rand() % num;
		int b = rand() % num;

		Card temp;
		temp = cards[a];
		cards[a] = cards[b];
		cards[b] = temp;
	}
}

void Card::setting(Card c1[40], Card c2[30], Card c3[20])
{
	set_card1(c1);
	shuffle(c1,40);
	set_card2(c2);
	shuffle(c2,30);
	set_card3(c3);
	shuffle(c3,20);
}
