#include <iostream>
#include <functional>

class MyFunctor
{
public:
	int operator()()
	{
		return ++Num;
	}

private:
	int Num = 0;
};

int main()
{
	MyFunctor MF;
	MyFunctor AS = MyFunctor();
	std::function<int()> FunctorPtr = MyFunctor();

	int a = MF();	// a = 1
	std::cout << a << std::endl;

	int b = FunctorPtr();
	b = FunctorPtr();
	b = FunctorPtr();
	std::cout << b << std::endl;	//b = 3

	return 0;
}