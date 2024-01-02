#include <iostream>
#include <string>

int main()
{
	std::string Test("123");
	int IntNum = std::stoi(Test);

	std::cout << IntNum << std::endl;

	Test = "123.456";
	float FloatNum = std::stof(Test);
	
	std::cout << FloatNum << std::endl;

	return 0;
}