#include <iostream>
#include <string>

int main()
{
	std::string Test;
	int IntNumber = 123;
	float FloatNumber = 123.456f;
	double DoubleNumber = 456.789;
	char TestChar = 'c';

	Test = std::to_string(IntNumber);
	std::cout << Test << std::endl;
	Test = std::to_string(FloatNumber);
	std::cout << Test << std::endl;
	Test = std::to_string(DoubleNumber);
	std::cout << Test << std::endl;
	Test = std::to_string(TestChar);
	std::cout << Test << std::endl;

	return 0;
}