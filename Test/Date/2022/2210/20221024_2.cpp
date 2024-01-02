#include <iostream>

class player
{
private:
	std::string name;
	int age;
	int height;
public:
	player(const std::string& name, int age, int height);
	void print_info();
};

class WorldPlayer : public player
{
private:
	unsigned int rating;
public:
	WorldPlayer(unsigned int rating = 0, std::string name = "none", int age = 0, int height = 0);
	WorldPlayer(unsigned int rating, const player& p);
	unsigned int Rating() { return rating; }
	void ResetRating(unsigned int rating) { this->rating = rating; }
	void print_info(const player&);
};

player::player(const std::string& name, int age, int height) : name(name), age(age), height(height) {}

void player::print_info()
{
	using std::cout;
	using std::endl;
	cout << "�̸��� " << name << "�Դϴ�." << endl;
	cout << "���̴� " << age<< "�Դϴ�." << endl;
	cout << "Ű�� " << height << "�Դϴ�." << endl;
}

WorldPlayer::WorldPlayer(unsigned int rating, std::string name, int age, int height) 
	: player(name, age, height) { this->rating = rating; }

WorldPlayer::WorldPlayer(unsigned int rating, const player& p) : player(p), rating(rating) {}

void WorldPlayer::print_info(const player& p)
{
	using std::cout;
	using std::endl;
	cout << "��ŷ�� " << rating<< "�Դϴ�." << endl;
	//cout << "�̸��� " << p.name << "�Դϴ�." << endl;
	//cout << "���̴� " << p.age << "�Դϴ�." << endl;
	//cout << "Ű�� " << p.height << "�Դϴ�." << endl;
}



int main()
{
	player woojin("shimwoojin", 26, 180);
	woojin.print_info();
	WorldPlayer shimwoojin(1, "shimwoojin", 10, 100);
	WorldPlayer shimwoojin2(2, woojin);

	return 0;
}
