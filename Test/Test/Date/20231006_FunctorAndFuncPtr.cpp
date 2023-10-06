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
	
	//functor가 임시변수라면 함수 포인터와 규격을 맞춰주는 것 같음, 임시변수 시점이 지나면 반환값이 bool 매개변수가 int 2개를 받는 타입으로 취급
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