#include <iostream>

void ACount();
void usingACount();

class Test
{
public:
	Test() { testCount++; }
	void howManyTest() { std::cout << "Test클래스의 count : " << testCount << std::endl; }

private:
	static int testCount;
};

int Test::testCount;	//.cpp

int main()
{
	//usingACount();
	//usingACount();
	//usingACount();

	Test test1;
	test1.howManyTest();
	Test test2;
	test2.howManyTest();
	Test test3;
	test3.howManyTest();
	Test test4;
	test4.howManyTest();

	return 0;
}