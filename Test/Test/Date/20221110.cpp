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
		cout << "�̸� : " << name << "\n"
			<< "���� : " << age << "\n"
			<< "Ű : " << height << "\n"
			<< "������ : " << weight << endl;
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
		std::cout << "������ : " << isPretty << std::endl;
	}

private:
	bool isPretty;
};

int main()
{
	Girl* yujeong = new Yujeong(25, 56, 167, "������", true);
	yujeong->print();

	return 0;
}