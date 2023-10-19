#include <iostream>
#include <map>

int main()
{
	std::map<char, int> MyMap;

	MyMap['c'] = 1;

	std::cout << MyMap['c'] << std::endl;

	return 0;
}