//operator typename Ȯ��

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
	
	explicit operator std::string()	// explicit Ű���带 ���� ����� ����ȯ�� �����ϰ� ����
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
	os << name_.firstname << name_.lastname << "�Դϴ�" << std:: endl;
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