#include <iostream>
using namespace std;

class Parent
{
public:
	Parent()
	{
		CanThisCallByOverrideVersion();
	}

	virtual void CanThisCallByOverrideVersion()
	{
		cout << "Parent's Function" << endl;
	}
};

class Child : public Parent
{
public:
	Child()
		: Parent()
	{
	}

	virtual void CanThisCallByOverrideVersion() override
	{
		cout << "Child's Function" << endl;
	}

private:
	bool WhatSizeThisClass;
};

int main()
{
	Parent parent;
	Child child;

	cout << sizeof(parent) << endl << sizeof(child) << endl;

	return 0;
}