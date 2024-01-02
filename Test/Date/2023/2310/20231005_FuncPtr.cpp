#include <iostream>
#include <functional>

void PrintHello(int Num)
{
	std::cout << "Hello" << Num << std::endl;
}

int main()
{
	std::function<void(int)> TestFunctionPtr = PrintHello;
	TestFunctionPtr(1);

	TestFunctionPtr = [](int Num) {
		std::cout << "HelloLambda" << Num << std::endl;
	};

	TestFunctionPtr(2);

	return 0;
}