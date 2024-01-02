#include <iostream>
#include <type_traits>

int main()
{
	//std::conditional<true, int, float>::type a;
	//std::conditional<false, int, float>::type b;
	
	_STD conditional_t<true, int, float> a;
	_STD conditional_t<false, int, float> b;

	a = 3.14f;
	b = 3.14f;

	_STD cout << a << " " << b << _STD endl;

	return 0;
}