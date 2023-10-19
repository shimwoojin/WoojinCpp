#include <algorithm>
#include <iostream>

int main()
{
	int a = 5, b = 10;
	int* pa = &a, * pb = &b;
	std::swap(pa,pb);

	std::cout << a << b << std::endl;
	std::cout << *pa << *pb << std::endl;

	return 0;
}