#include <iostream>

int main()
{
	struct Padding
	{
		//char a;
		//int c;
		long long b;
	};

	Padding P;
	
	std::cout << sizeof(P) << std::endl;

	return 0;
}