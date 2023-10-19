#include <iostream>
#include <functional>
using namespace std;

void Test(int MyInt, float MyFloat, char MyChar)
{
	cout << "MyInt : " << MyInt << "MyFloat : " << MyFloat << "MyChar : " << MyChar << endl;
}

int main()
{
	void (*MyFuncPtr)(int, float, char) = Test;

	MyFuncPtr(1,3.14f,'c');

	//void (*MyFuncPtr2)(int, char) = std::bind(&Test, std::placeholders::_1, 3.14f, std::placeholders::_1);
	
	std::function<void(int, char)> MyFuncPtr3 = std::bind(&Test, std::placeholders::_1, 3.14f, std::placeholders::_2);

	MyFuncPtr3(3, 'c');

	auto AutoFuncPtr = Test;

	AutoFuncPtr(10, 20.5f, 'f');

	return 0;
}