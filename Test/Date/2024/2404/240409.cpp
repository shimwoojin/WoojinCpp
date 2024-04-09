#include <algorithm>
#include <iostream>
#include <iterator>
#include <type_traits>

template<class A>
std::enable_if_t<std::rank_v<A> == 1>
print_1d(const A& a)
{
	std::copy(a, a + std::extent_v<A>,
		std::ostream_iterator<std::remove_extent_t<A>>(std::cout, " "));
	std::cout << '\n';
}

template<typename T>
std::enable_if_t<std::is_same_v<T, std::string>, T> PrintHello(T&& out)
{
	std::cout << std::forward<T>(out);

	return out;
}

int Test(int a)
{
	return 0;
}

class OperatorTest
{
public:
	OperatorTest(int data) : data(data) {}

	operator int&()
	{
		return data;
	}

private:
	int data;
};

template<typename T>
void ChangeV1(T t)
{
	t++;
}

template<typename T>
void ChangeV2(T&& t)
{
	std::forward<T>(t)++;
}

int main()
{
	int a[][3] = { {1, 2, 3}, {4, 5, 6} };
	//  print_1d(a); // compile-time error
	print_1d(a[1]);

	PrintHello(std::string("as"));

	//std::ref();
	int asd = 10;
	std::reference_wrapper<int> b = asd;
	b.get() = 20;

	int& c = b;

	c = 30;

	asd;

	OperatorTest OT(1);

	int& d = OT;

	d = 40;

	OT;

	int t = 20;
	ChangeV1(t);

	ChangeV1(std::ref(t));

	ChangeV2(t);
	ChangeV2(std::ref(t));

	int* pt = std::addressof(t);

	*pt = 10;

	t;
}

//int main()
//{
//	int a = 10;
//	std::add_const<int>::type b = a;
//
//	A test;
//	A& test2 = test;
//
//	std::add_lvalue_reference<decltype(test2)>::type test3 = test;
//
//	return 0;
//}