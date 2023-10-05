#include <iostream>

template<typename T>
T Add(T a, T b) { return a + b; }

template<>
char Add<char>(char a, char b) { std::cout << "char template specialization" << std::endl; return 'a'; }

int main()
{
	int a = Add(1, 2);
	char b = Add('c', 'b');

	std::cout << a << " " << b << std::endl;

	return 0;
}