#include <iostream>
#include <functional>
#include <typeinfo>
#include <algorithm>

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

template<typename Fn>
void CallableTest(Fn fn)
{
	fn();
}

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

	auto LambdaTest = +[]() {};		//+가 있으면 함수 포인터로
	LambdaTest = []() {};

	auto LambdaTest2 = []() {};	//+가 없으면 class lambda
	//LambdaTest2 = []() {};	//Error

	auto t = FunctorTest();
	t();

	cout << typeid(FnPtr).name() << endl;
	cout << typeid(FnPtr2).name() << endl;
	cout << typeid(LambdaTest).name() << endl;
	cout << typeid(LambdaTest2).name() << endl;
	cout << typeid(t).name() << endl;

	CallableTest([](){
		cout << "CallableTest1" << std::endl;
		});

	CallableTest(FnPtr);
	CallableTest(FnPtr2);

	return 0;
}