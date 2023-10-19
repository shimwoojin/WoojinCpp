#include <iostream>

namespace Test1
{
	enum Type
	{
		A,
		B,
		C
	};
}

namespace Test2
{
	enum Type : unsigned int
	{
		A,
		B,
		C
	};
}

int main()
{
	Test1::Type MyEnum1 = Test1::A;
	Test2::Type MyEnum2 = Test2::A;


	return 0;
}