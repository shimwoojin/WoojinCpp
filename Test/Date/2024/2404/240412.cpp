// ÂüÁ¶ : https://junstar92.tistory.com/322 

#include <iostream>
#include <string>

using namespace std::string_literals;

_NODISCARD inline unsigned long long operator ""s(unsigned long long temp)
{
	return 10;
}

unsigned long long operator "" _asdasd(unsigned long long temp)
{
	std::cout << temp << std::endl;
	return temp;
}

class CrazyGrammar
{
public:
	CrazyGrammar(int data) : data(data) {}

	CrazyGrammar& operator<(CrazyGrammar& rhs)
	{
		rhs.data += this->data;
		return rhs;
	}

	CrazyGrammar& operator>(CrazyGrammar& rhs)
	{
		this->data += rhs.data;
		return *this;
	}

public:
	int data;
};

int main()
{
	const char* test_char = "abcdefg";
	const char* test_char2 = "123456";
	int* p_int = new int;

	int a = 1s;

	auto string_literal = "ABCDEFG"s;

	//delete[] "asdasdasd";

	CrazyGrammar CG(5);
	CrazyGrammar CG2(10);

	CG<CG2>CG;

	std::cout << CG2.data << std::endl;

	auto literal_overloading = 123_asdasd;

	return 0;
}