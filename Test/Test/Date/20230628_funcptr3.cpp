#include <iostream>
#include <functional>

void Hello()
{
	std::cout << "Hello!" << std::endl;
}

const int& ShowTwoIntAndReturnFirst(const int& first, const int& second)
{
	std::cout << "first : " << first << ", second : " << second << std::endl;

	return first;
}

int main()
{
	//���ø� ���ڿ� ��ȯ��, �Ű������� Ÿ�Ը� �Ѱ��ָ� ��
	std::function<void()> funcptr1 = Hello;
	std::function<const int&(const int&, const int&)> funcptr2 = ShowTwoIntAndReturnFirst;

	funcptr1();
	std::cout << funcptr2(10, 20) << std::endl;

	return 0;
}