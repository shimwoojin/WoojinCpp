#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<std::string> str;
	str.push_back("hello1");
	str.push_back("hello2");
	str.push_back("hello3");
	str.push_back("hello4");
	str.push_back("hello5");
	str.push_back("hello6");
	str.push_back("hello7");
	str.push_back("hello8");
	str.push_back("hello9");
	str.push_back("hello10");

	std::string str2[10] = {};
	for_each(str.begin(), str.end(),
		[&str2](std::string& s) 
		{
			static int i = 0;
			std::cout << s << " " << std::endl;
			str2[i] = s;
			i++;
		}
	);

	for (int i = 0; i < 10; i++)
		std::cout << str2[i] << std::endl;


	return 0;
}