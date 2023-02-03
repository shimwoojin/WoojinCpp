#include <iostream>
#include <string>

class Parent
{
public:
	static Parent& Get()
	{
		static Parent instance("p1");
		return instance;
	}

	static void Print()
	{
		std::cout << "hello world!" << std::endl;
	}

	virtual void PrintName()
	{
		std::cout << "Parent�� name�� " << name << "�Դϴ�." << std::endl;
	}

protected:
	std::string name;

protected:
	Parent(std::string name)
		: name(name)
	{}
};

class Child : public Parent
{
private:
	Child(std::string name)
		: Parent(name)
	{}

public:
	virtual void PrintName() override
	{
		Parent::PrintName();
		std::cout << "Child�� name�� " << name << "�Դϴ�." << std::endl;
	}

	void Test()
	{
		Parent::PrintName();
	}

};


int main()
{
	Parent::Print();

	Child::Get();

	//Parent parent("woojin");
	//Child child("yujeong");
	//
	//parent.PrintName();
	//child.PrintName();
	//child.Test();

	return 0;
}