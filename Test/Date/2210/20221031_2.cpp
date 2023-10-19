#include <iostream>

template <int n1, int n2>
class player
{
public:
	player() {}

	void push_item(std::string s, int n) { if (n >= n1 || n < 0) return; item[n] = s; }
	void push_weapon(std::string s, int n) { if (n >= n2 || n < 0) return; weapon[n] = s; }

	void show_item() { for (int i = 0; i < n1; i++) std::cout << "item : " << item[i] << std::endl; }
	void show_weapon() { for (int i = 0; i < n2; i++) std::cout << "weapon : " << weapon[i] << std::endl; }

private:
	std::string item[n1];
	std::string weapon[n2];
};

int main()
{
	player<5,5> p;

	p.push_item("red potion", 0);
	p.push_item("white potion", 1);
	p.push_item("green potion", 2);
	p.push_item("black potion", 3);
	p.push_item("brown potion", 4);
	p.push_weapon("legend sword", 0);
	p.push_weapon("new sword", 1);
	p.push_weapon("old sword", 2);
	p.push_weapon("red sword", 3);
	p.push_weapon("white sword", 4);

	p.show_item();
	p.show_weapon();



	return 0;
}