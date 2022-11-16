#pragma once

class Token
{
private:
	int green, blue, red, black, silver, gold;
public:
	Token() : green(0), blue(0), red(0), black(0), silver(0), gold(0) {}
	Token(int player);

	int total() { return green + blue + red + black + silver + gold; }
	int Green() { return green; }
	int Green_sub(int num) { green -= num; return green - num; }
	int Green_add(int num) { green += num; return green + num; }
	int Blue() { return blue; }
	int Blue_sub(int num) { blue -= num; return blue - num; }
	int Blue_add(int num) { blue += num; return blue + num; }
	int Red() { return red; }
	int Red_sub(int num) { red -= num; return red - num; }
	int Red_add(int num) { red += num; return red + num; }
	int Black() { return black; }
	int Black_sub(int num) { black -= num; return black - num; }
	int Black_add(int num) { black += num; return black + num; }
	int Silver() { return silver; }
	int Silver_sub(int num) { silver -= num; return silver - num; }
	int Silver_add(int num) { silver += num; return silver + num; }
	int Gold() { return gold; }
	int Gold_sub(int num) { gold -= num; return gold - num; }
	int Gold_add(int num) { gold += num; return gold + num; }


};