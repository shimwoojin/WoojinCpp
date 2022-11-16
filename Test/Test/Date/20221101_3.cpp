#include <iostream>
#include <string>

int main()
{
	int a = 10;
	unsigned long b = reinterpret_cast<unsigned long>(&a);
	std::cout << b << std::endl;


	std::string two(20,'#');
	const char* three = "hello!";
	two[0] = '!';
	std::string one = two + three;
	std::cout << two << std::endl;
	std::cout << one << std::endl;

	return 0;
}