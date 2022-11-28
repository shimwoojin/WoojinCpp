#include "TypeObject.h"
#include <iostream>

int main()
{
	Breed breed(50, "Monster가 공격 중");
	Monster* monster = breed.newMonster();

	std::cout << monster->getAttack() << std::endl;

	return 0;
}