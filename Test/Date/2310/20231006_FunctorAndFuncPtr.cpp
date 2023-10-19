#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

template<typename T>
class MyGreater
{
public:
	bool operator()(const T& a, const T& b)
	{
		return a > b;
	}
};

template<typename T>
class MyLess
{
public:
	std::function<bool(T, T)> operator()()
	{
		return [](T a, T b) {return a < b; };
	}
};

int main()
{
	std::vector<int> Test{ 4, 5, 2, 3, 6, 1 };
	
	//functor�� �ӽú������ �Լ� �����Ϳ� �԰��� �����ִ� �� ����, �ӽú��� ������ ������ ��ȯ���� bool �Ű������� int 2���� �޴� Ÿ������ ���
	std::sort(Test.begin(), Test.end(), MyGreater<int>());

	for (int i = 0; i < Test.size(); i++)
	{
		std::cout << Test[i] << std::endl;
	}

	MyLess<int> Less;

	std::sort(Test.begin(), Test.end(), Less());

	for (int i = 0; i < Test.size(); i++)
	{
		std::cout << Test[i] << std::endl;
	}

	return 0;
}