#include <iostream>
#include "Monster.h"

Monster* Ghost::clone()
{
	std::cout << "Ghost°¡ CloneµÊ" << std::endl;
	std::cout << "health : " << health_ << std::endl;
	std::cout << "speed_" << speed_ << std::endl;
	return new Ghost(health_, speed_);
}

//Monster* Spawner::spawnMonster()
//{
//	std::cout << "Ghost°¡ »ý¼ºµÊ" << std::endl;
//	return spawn_();
//}

Monster* spawnGhost()
{
	return new Ghost(15, 3);
}