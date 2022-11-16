#include <iostream>
#include "Observer.h"
#include "Subject.h"

class Entity{};

int main()
{
	Entity ent;
	Observer* ach = new Achivements[10];
	Subject sub;
	for (int i = 0; i < 10; i++)
		sub.addObserver(&ach[i]);
	sub.notify(ent, Event::kill);
	sub.notify(ent, Event::death);

	delete[] ach;
	return 0;
}