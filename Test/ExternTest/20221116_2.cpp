#include <iostream>
#include "20221116.h"

extern const int externInt = 10;
extern int externInt2 = 20;

int print()
{
	std::cout << externInt2 << std::endl;
	externInt2++;

	return 0;
}

static int print(int a)
{
	std::cout << "hello world!" << std::endl;
	return 0;
}

void print2()
{
	print(1);
}