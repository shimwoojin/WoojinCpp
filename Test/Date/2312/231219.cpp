#include <iostream>
#include <functional>
#include <typeinfo>

void Hello()
{
	std::cout << "Hello"<< std::endl;
}

struct FunctorTest
{
	void operator()()
	{
		std::cout << "FunctorTest" << std::endl;
	}
};

int main()
{
	using namespace std;

	void (*FnPtr)() = Hello;
	FnPtr();

	{
		FnPtr = []() {
			std::cout << "Lambda" <<std::endl;
			};
		FnPtr();

		FnPtr = +[]() {
			std::cout << "Lambda +Version" << std::endl;
			};
		FnPtr();
	}

	//FnPtr = FunctorTest();	//Error
	std::function<void()> FnPtr2 = FunctorTest();

	auto LambdaTest = +[]() {};		//+�� ������ �Լ� �����ͷ�
	LambdaTest = []() {};

	auto LambdaTest2 = []() {};	//+�� ������ class lambda
	//LambdaTest2 = []() {};	//Error

	auto t = FunctorTest();
	t();

	cout << typeid(FnPtr).name() << endl;
	cout << typeid(FnPtr2).name() << endl;
	cout << typeid(LambdaTest).name() << endl;
	cout << typeid(LambdaTest2).name() << endl;
	cout << typeid(t).name() << endl;

	return 0;
}