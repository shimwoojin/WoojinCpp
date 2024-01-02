#include <iostream>
#include <functional>

class Test
{
public:
	Test() {}

	void PrintHello()
	{
		std::cout << "Hello" << std::endl;
	}
};

int main()
{
	Test T;
	Test* PointerT = new Test;

	void (Test:: * MemberFuncPtr)() = &Test::PrintHello;
	std::function<void(Test&)> MemberFuncPtr2 = &Test::PrintHello;

	(T.*MemberFuncPtr)();
	(PointerT->*MemberFuncPtr)();
	MemberFuncPtr2(T);

	delete PointerT;

	return 0;
}