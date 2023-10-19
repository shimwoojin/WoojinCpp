#include <iostream>

class Singleton
{
public:
	static Singleton& getInstance(const char* name)
	{
		static Singleton s(name);
		return s;
	}

	const char* get_name() { return name; }
	void set_name(const char* name) { this->name = name; }
	
private:	//Class�� �⺻ ���� �� �����ϴ� ������, �ı���, ���Կ����ڸ� private���� ������ -> singleton
	Singleton () : name("NULL") {}	//����Ʈ ������
	explicit Singleton (const char* name) : name(name) {}	//�Ű����� ������
	Singleton(const Singleton& ref) { name = ref.name; }				//���� ������
	Singleton& operator=(const Singleton& ref) {}	//���� ������
	~Singleton() {}									//�ı���
	const char* name;
};

int main()
{
	//�̱��� �ν��Ͻ� ù��° ����
	Singleton& s = Singleton::getInstance("shimwoojin");
	std::cout << s.get_name() << std::endl;
	//ù��° ������ �̸����� public �޼��� ����
	s.set_name("woojinshim");
	std::cout << s.get_name() << std::endl;

	//�ι�° �ν��Ͻ� ����
	Singleton& s2 = Singleton::getInstance("shimwoojin2");
	std::cout << s2.get_name() << std::endl;
	//�ι�° ������ �ν��Ͻ����� �޼��� ȣ��
	s2.set_name("woojinshimwoojinshim");
	//s1�� �̸��� s2�� �̸��� ���� -> �̱��� ���� ���� �Ϸ�
	std::cout << s.get_name() << std::endl;
	std::cout << s2.get_name() << std::endl;

	//Singleton s3;					//error
	//Singleton s4("shimwoojin");	//error
	//Singleton s5(s);				//error
	//Singleton s6 = s;				//error

	return 0;
}