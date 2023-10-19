#include <iostream>


int main()
{
	using namespace std;
	std::cout << "¾Ó³É" << std::endl;
	const char* word = "hello world!!";
	cout << (void*)word << endl;

	(std::cout << "¾Ó³É").put('3') << std::endl;

	cout << 'W' << endl;
	(cout << "¾È³çÇÏ¼¼¿ä").write("¹Ý°©½À´Ï´Ù", 8) << endl;
	cout.write("helloworld!!",12)<<endl;

	long val = 12345678;
	cout.write((char*)&val, sizeof(long));

	return 0;
}