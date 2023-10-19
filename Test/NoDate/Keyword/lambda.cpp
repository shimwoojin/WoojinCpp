#include <iostream>

int main()
{
	auto a = [] (int a, int b) { return a+b; }(10,20);

	std::cout << a << std::endl;
	
	auto b = [](int a, int b) { return a + b; };

	std::cout << b(30,40) << std::endl;

	return 0;
}