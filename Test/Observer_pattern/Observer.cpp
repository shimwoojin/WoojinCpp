#include "Observer.h"
#include <iostream>

void Achivements::onNotify(const class Entity& eneity, Event event)
{
	switch (event)
	{
	case Event::kill:
		std::cout << "���� �׿����ϴ�!!" << std::endl;
		break;
	case Event::death:
		std::cout << "������ �׾����ϴ�.." << std::endl;
		break;
	case Event::level_up:
		std::cout << "������ �Ͽ����ϴ�!!" << std::endl;
		break;
	default:
		break;
	}
}