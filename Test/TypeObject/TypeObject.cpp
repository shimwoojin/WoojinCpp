#include "TypeObject.h"
#include <iostream>

int main()
{
	Breed breed(50, "Monster�� ���� ��");
	Monster* monster = breed.newMonster();

	std::cout << monster->getAttack() << std::endl;

	return 0;
}