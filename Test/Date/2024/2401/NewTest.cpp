#include <iostream>
#include <vector>

class A
{
public:
	A() : a(0) {}
	A(int a) : a(a) {}

public:
	int a;
};

template<typename T>
void* operator new(size_t size, std::vector<T>& Container)
{
	Container.emplace_back();	//기본 생성자 없으면 에러
	return &Container.back();
}

int main()
{
	std::vector<A> Container;

	new (Container) A(3);

	std::cout << Container.front().a;	//3

	//Container.resize(Container.size() + 1);	//기본 생성자 없으면 에러

	return 0;
}