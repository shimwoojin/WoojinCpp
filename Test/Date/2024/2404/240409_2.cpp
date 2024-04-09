#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <numeric>
#include <random>

//void Test(int val)
//{
//	std::cout << "N" << '\n';
//}

void Test(int& val)
{
	std::cout << "L" << '\n';
}

void Test(int&& val)
{
	std::cout << "R" << '\n';
}

template <typename T>
void Wrapper(T&& t)
{
	Test(std::forward<T>(t));
}

int main()
{
	std::list<int> l(10);
	std::iota(l.begin(), l.end(), 0);

	std::vector<std::reference_wrapper<int>> vec(l.begin(), l.end());

	std::random_shuffle(vec.begin(), vec.end());

	for (int ele : l) std::cout << ele << ' ';
	std::cout << '\n';
	for (int ele : vec) std::cout << ele << ' ';
	for (int& ele : vec) ele *= 2;

	std::vector<int*> vec2;
	int a = 15;
	int b = 20;
	int c = 30;
	
	vec2.push_back(&a);
	vec2.push_back(&b);
	vec2.push_back(&c);

	std::plus<> d;
	c = d(a, b);

	int e = std::exchange(a, b);

	std::vector<int> vec3;
	std::exchange(vec3, { 1,2,3,4,5 });

	std::move(vec.begin(), vec.end(), vec.begin());

	Wrapper(e);
	Wrapper(3);

	return 0;
}