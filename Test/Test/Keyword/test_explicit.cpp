#include <iostream>

class Test1
{
public:
	Test1() : data(10) {}
	operator int()
	{
		return data;
	}
private:
	int data;
};

class Test2
{
public:
	Test2() = default;
	explicit Test2(int i) : data(i) {}
	int getData() const { return data; }
private:
	int data;
};

int main()
{
	Test1 test1;
	Test2 test2(test1);
	std::cout<<test2.getData() << std::endl;

	return 0;
}