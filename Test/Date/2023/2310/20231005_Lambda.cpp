#include <iostream>

int main()
{
	//int (*Add)(int, int) = [](int a, int b) {return a + b; };
	//auto Add = [](int a, int b) {return a + b; };

	//int Sum = Add(1, 2);

	//std::cout << Sum << std::endl;

	//[a]()
	//{
	//	std::cout << a << std::endl;
	//	//a = 20;	//error
	//}();

	int a = 10;
	int b = 20;

	[&]()
	{
		a = 20;
		b = 30;
	}();

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	return 0;
}