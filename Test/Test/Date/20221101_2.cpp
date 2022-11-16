#include <iostream>

int main()
{
	//포인터나 참조 형식으로의 형변환에서 원래의 자료형은 바꾸지 못하고 const성 혹은 volatile성만 바꿀 수 있음
	const int a = 10;
	//int* b = const_cast<int*>(&a);	//error
	int* b = const_cast<int*>(&a);

	*b += 1;
	std::cout << a << std::endl;
	std::cout << *b << std::endl;


	return 0;
}