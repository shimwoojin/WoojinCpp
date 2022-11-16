#pragma once

struct Value
{
	int green;
	int blue;
	int red;
	int black;
	int silver;
};

struct Price
{
	int green;
	int blue;
	int red;
	int black;
	int silver;
};

class Card
{
public:
	enum class LV { lv1 = 1, lv2, lv3 };
private:
	Value v;
	Price p;
	int score;
	LV lv;
	//setting
	void set_card1(Card cards[40]);
	void set_card2(Card cards[30]);
	void set_card3(Card cards[20]);
	void shuffle(Card* cards,int);
public:
	Card(int Vg = 0, int Vb = 0, int Vr = 0, int Vbl = 0, int Vs = 0,
		int Pg = 0, int Pb = 0, int Pr = 0, int Pbl = 0, int Ps = 0,
		int score = 0, LV lv = LV::lv1) : v{ Vg,Vb,Vr,Vbl,Vs }, p{ Pg, Pb, Pr, Pbl, Ps },
		score{ score }, lv(lv) {};
	void setting(Card c1[40], Card c2[30], Card c3[20]);
	int Score() { return score; }
	int V_green() { return v.green; }
	int V_blue() { return v.blue; }
	int V_red() { return v.red; }
	int V_black() { return v.black; }
	int V_silver() { return v.silver; }
	int P_green() { return p.green; }
	int P_blue() { return p.blue; }
	int P_red() { return p.red; }
	int P_black() { return p.black; }
	int P_silver() { return p.silver; }
	
};