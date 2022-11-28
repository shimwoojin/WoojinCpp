#include <iostream>

static void ACount()
{
	static int a = 0;
	std::cout << "a : " << a << std::endl;
	a++;
}

void usingACount()
{
	ACount();
	ACount();
	ACount();
	ACount();
	ACount();
}

