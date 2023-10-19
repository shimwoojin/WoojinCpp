#include <iostream>

class Parent
{
public:
	virtual void PrintMyName() = 0;

	virtual ~Parent()
	{
		std::cout << "Parent Deconstructor" << std::endl;
	}
};

class Child1 : public Parent
{
public:
	virtual void PrintMyName()
	{
		std::cout << "Child1" << std::endl;
	}

	/*virtual */~Child1()
	{
		std::cout << "Child1 Deconstructor" << std::endl;
	}
};

class Child2 : public Parent
{
public:
	virtual void PrintMyName()
	{
		std::cout << "Child2" << std::endl;
	}

	/*virtual */~Child2()
	{
		std::cout << "Child2 Deconstructor" << std::endl;
	}
};

int main()
{
	{
		//Parent P;	//error

		Parent* P1 = new Child1;
		Child2 C2;
		Parent& P2 = C2;

		P1->PrintMyName();
		P2.PrintMyName();

		delete P1;
	}

	return 0;
}