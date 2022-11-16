//const_cast ��� ����

#include <iostream>

int main()
{
	int test = 10;
	int test2 = 100;
	int test3 = 1000;
	const int* const p_test = &test;

	//*p_test = 20; //error, ���� ���� ����
	//p_test = &test2;	//error, �ּҿ� ���� ����

	int* p_test_to_p = const_cast<int*>(p_test);

	*p_test_to_p = 20;
	std::cout << test << std::endl;
	std::cout << *p_test_to_p << std::endl;

	p_test_to_p = &test3;
	std::cout << *p_test_to_p << std::endl;
	

	return 0;
} 