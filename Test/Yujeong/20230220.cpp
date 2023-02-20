#include <iostream>
using namespace std;

int main()
{
	int a = 10;
	int b = 20;
	int* pa = &a;

	//1.
	*pa = 5;

	//2.
	pa = &b;

	return 0;
}