#include <iostream>
#include <typeinfo>

class Parent
{
	virtual void Print() {}
};

class Child : public Parent
{

};

class Child2 : public Parent
{

};

int main()
{
	Parent* P = new Child;
	Parent* P2 = new Child2;

	Child* C1 = dynamic_cast<Child*>(P);
	Child* C2 = static_cast<Child*>(P);
	Child* C3 = static_cast<Child*>(P2);
	Child* C4 = dynamic_cast<Child*>(P2);

	if (C1)
	{
		std::cout << "C1" << std::endl;
	}

	if (C2)
	{
		std::cout << "C2" << std::endl;
	}

	if (C3)
	{
		std::cout << "C3" << std::endl;
	}

	if (C4)
	{
		std::cout << "C4" << std::endl;
	}

	//std::cout << typeid(*P).name() << std::endl;

	return 0;
}