#include <iostream>

class Test
{
public:
	Test() : data(0) {}
	Test(int data) : data(data) {}
	int getData() const { return data; }
private:
	int data;
};

Test* makeTest(int i)
{
	std::cout << "货肺款 Test 积己" << std::endl;
	return new Test(i);
}

int main()
{
	const int SIZE = 10;
	Test* TestArr[SIZE];

	for (int i = 0; i < SIZE; i++)
		TestArr[i] = makeTest(i);

	delete TestArr[0];
	TestArr[0] = nullptr;
	delete TestArr[3];
	TestArr[3] = nullptr;
	delete TestArr[5];
	TestArr[5] = nullptr;

	for (int i = 0; i < SIZE; i++)
	{
		if (TestArr[i] != nullptr)
			std::cout << TestArr[i]->getData() << std::endl;
	}

	for (int i = 0; i < SIZE; i++)
	{
		if (TestArr[i] == nullptr)
			TestArr[i] = makeTest(i);
	}

	for (int i = 0; i < SIZE; i++)
	{
		if(TestArr[i]!=nullptr)
			std::cout << TestArr[i]->getData() << std::endl;
	}

	for (int i = SIZE-1; i >= 0; i--)
		delete TestArr[i];
	
	return 0;
}