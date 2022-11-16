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
	cout << "이름은 " << name << "입니다." << endl;
	cout << "나이는 " << age<< "입니다." << endl;
	cout << "키는 " << height << "입니다." << endl;
}

WorldPlayer::WorldPlayer(unsigned int rating, std::string name, int age, int height) 
	: player(name, age, height) { this->rating = rating; }

WorldPlayer::WorldPlayer(unsigned int rating, const player& p) : player(p), rating(rating) {}

void WorldPlayer::print_info(const player& p)
{
	using std::cout;
	using std::endl;
	cout << "랭킹은 " << rating<< "입니다." << endl;
	//cout << "이름은 " << p.name << "입니다." << endl;
	//cout << "나이는 " << p.age << "입니다." << endl;
	//cout << "키는 " << p.height << "입니다." << endl;
}



int main()
{
	player woojin("shimwoojin", 26, 180);
	woojin.print_info();
	WorldPlayer shimwoojin(1, "shimwoojin", 10, 100);
	WorldPlayer shimwoojin2(2, woojin);

	return 0;
}
