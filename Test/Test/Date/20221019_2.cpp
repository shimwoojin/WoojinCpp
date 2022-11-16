//operator typename 확인

#include <iostream>
#include <string>

class name
{
private:
	std::string firstname;
	std::string lastname;
public:
	name(){}
	name(std::string firstname, std::string lastname)
	{
		this->firstname = firstname;
		this->lastname = lastname;
	}
	
	explicit operator std::string()	// explicit 키워드를 통해 명시적 형변환만 가능하게 만듬
	{
		return this->lastname;
	}

	name operator+(const name& name_)
	{
		firstname += name_.firstname;
		lastname += name_.lastname;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const name name_);

};

std::ostream& operator<<(std::ostream& os, const name name_)
{
	os << name_.firstname << name_.lastname << "입니다" << std:: endl;
	return os;
}

int main()
{
	std::string myname;

	name name_("shim", "woojin");
	name name2("woojin", "shim");
	name name3 = name_ + name2;

	myname = static_cast<std::string>(name_);

	using namespace std;

	cout<< myname << endl;
	cout << name3 << endl;

	return 0;
}