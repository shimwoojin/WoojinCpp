#include <iostream>

template <typename T>
class Test
{
public:
	Test(T test) : test(test) {}


private:
	T test;
};

int main()
{
	Test<int> t(1);
	/*Test t(1);*/	//error
	



	return 0;
}