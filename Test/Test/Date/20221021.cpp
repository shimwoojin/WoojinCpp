//20221021 - 과제, new와 malloc 차이

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <type_traits>

struct Test
{
	int a;
	int b;
	std::string str;
};

struct Test2
{
	int a;
	int b;
	const char* str;
	//std::string str;
};

int main()
{
	Test* test = new Test;

	std::cout << "Test구조체의 크기 : " << sizeof(Test) << std::endl;
	std::cout << "Test가 POD인지 : " << std::boolalpha << std::is_pod<Test>::value << std::endl;

	test->a = 10;
	test->b = 20;
	test->str = "Hello!!";
	std::cout << "test->a : " << test->a << std::endl;
	std::cout << "test->b : " << test->b << std::endl;
	std::cout << "test->str : " << test->str << std::endl;

	std::cout << std::endl << std::endl;

	Test2* test2 = (Test2*)malloc(sizeof(Test2));

	std::cout << "Test2 구조체의 크기 : " << sizeof(Test2) << std::endl;
	std::cout << "Test2가 POD인지 : " << std::boolalpha << std::is_pod<Test2>::value << std::endl;
	
	test2->a = 10;
	test2->b = 20;
	test2->str = "Hello world!!";
	test2->str = "Hello C++!!";		// 문자열의 값 변화가 아닌 새 문자열의 주소 대입 
	
	std::cout << "test2->a : " << test2->a << std::endl;
	std::cout << "test2->b : " << test2->b << std::endl;
	std::cout << "test2->str : " << test2->str << std::endl;

	free (test2);
	delete test;


	return 0;
}