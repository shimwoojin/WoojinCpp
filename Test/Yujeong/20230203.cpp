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
		std::cout << "Parent의 name은 " << name << "입니다." << std::endl;
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
		std::cout << "Child의 name은 " << name << "입니다." << std::endl;
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