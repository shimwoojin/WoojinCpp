#include "Observer.h"
#include <iostream>

void Achivements::onNotify(const class Entity& eneity, Event event)
{
	switch (event)
	{
	case Event::kill:
		std::cout << "적을 죽였습니다!!" << std::endl;
		break;
	case Event::death:
		std::cout << "적에게 죽었습니다.." << std::endl;
		break;
	case Event::level_up:
		std::cout << "레벨업 하였습니다!!" << std::endl;
		break;
	default:
		break;
	}
}