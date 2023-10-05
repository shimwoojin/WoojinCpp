#include <iostream>

class Parent
{
public:
	virtual bool IsRightTypeID(const int InClassID) { return InClassID == ClassID; }
	virtual void TestPrint() { std::cout << "Parent" << std::endl; }

	static const int ClassID = 0;
};

class Child : public Parent
{
public:
	virtual bool IsRightTypeID(const int InClassID) { return InClassID == ClassID; }
	virtual void TestPrint() { std::cout << "Child" << std::endl; }
	static const int ClassID = 1;
};

class Child2 : public Parent
{
public:
	virtual bool IsRightTypeID(const int InClassID) { return InClassID == ClassID; }
	virtual void TestPrint() { std::cout << "Child2" << std::endl; }
	static const int ClassID = 2;
};

int main()
{
	Parent* P1 = new Child;
	Parent* P2 = new Child2;

	if (P1->IsRightTypeID(Child::ClassID))
	{
		Child* C1 = static_cast<Child*>(P1);
		C1->TestPrint();
	}

	if (P2->IsRightTypeID(Child2::ClassID))
	{
		Child2* C2 = static_cast<Child2*>(P2);
		C2->TestPrint();
	}

	return 0;
}