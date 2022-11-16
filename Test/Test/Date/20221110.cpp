#include <iostream>
#include <string>
class Girl
{
public:
	Girl(int age, int weight, int height, std::string name)
		: age(age), weight(weight), height(height), name(name) {}
	virtual void print()
	{
		using namespace std;
		cout << "이름 : " << name << "\n"
			<< "나이 : " << age << "\n"
			<< "키 : " << height << "\n"
			<< "몸무게 : " << weight << endl;
	}
private:
	int age;
	int weight;
	int height;
	std::string name;
};

class Yujeong : public Girl
{
public:
	Yujeong(int age, int weight, int height, std::string name, bool isPretty) 
		: Girl(age, weight, height, name), isPretty(isPretty) {}

	virtual void print() override
	{
		Girl::print();
		std::cout << std::boolalpha;
		std::cout << "예쁜지 : " << isPretty << std::endl;
	}

private:
	bool isPretty;
};

int main()
{
	Girl* yujeong = new Yujeong(25, 56, 167, "이유정", true);
	yujeong->print();

	return 0;
}