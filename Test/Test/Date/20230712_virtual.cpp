#include <iostream>
using namespace std;

class Parent
{
public:
	virtual void Print()
	{
		cout << "Parent" << endl;
	}
};

class Child : public Parent
{
public:
	virtual void Print() override
	{
		cout << "Child" << endl;
	}
};


int main()
{
	Parent parent;
	Child child;
	
	//parent.Print();
	//child.Print();

	Parent* p1 = &parent;
	Parent* p2 = &child;

	p1->Print();
	p2->Print();

	return 0;
}