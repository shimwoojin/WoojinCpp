#include <iostream>
#include <string>
class Marine {
	int hp; // ���� ü��
	int coord_x, coord_y; // ���� ��ġ
	int damage; // ���ݷ�
	bool is_dead;
public:
	Marine(); // �⺻ ������
	Marine(int x, int y); // x, y ��ǥ�� ���� ����
	int attack(); // �������� �����Ѵ�.
	void be_attacked(int damage_earn); // �Դ� ������
	void move(int x, int y); // ���ο� ��ġ
	void show_status(); // ���¸� �����ش�.
};
Marine::Marine() {
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
}
Marine::Marine(int x, int y) 
	: Marine()
{
	coord_x = x;
	coord_y = y;
	/*coord_x = x;
	coord_y = y;
	hp = 50;
	damage = 5;
	is_dead = false;*/
}
void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
		<< std::endl;
	std::cout << " HP : " << hp << std::endl;
}
int main() {
	Marine* marines[100];
	marines[0] = new Marine(2, 3);
	marines[1] = new Marine(3, 5);
	marines[0]->show_status();
	marines[1]->show_status();
	std::cout << std::endl << "���� 1 �� ���� 2 �� ����! " << std::endl;
	marines[0]->be_attacked(marines[1]->attack());
	marines[0]->show_status();
	marines[1]->show_status();
	delete marines[0];
	delete marines[1];

	std::cout << sizeof(Marine) << std::endl;

	{
		Marine marine;
	}
	std::cout << "�� �������� ����鼭 marine�� �Ҹ��� ȣ���" << std::endl;
}