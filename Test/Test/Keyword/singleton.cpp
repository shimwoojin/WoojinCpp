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
	
private:	//Class의 기본 생성 시 제공하는 생성자, 파괴자, 대입연산자를 private으로 재정의 -> singleton
	Singleton () : name("NULL") {}	//디폴트 생성자
	explicit Singleton (const char* name) : name(name) {}	//매개변수 생성자
	Singleton(const Singleton& ref) { name = ref.name; }				//복사 생성자
	Singleton& operator=(const Singleton& ref) {}	//대입 연산자
	~Singleton() {}									//파괴자
	const char* name;
};

int main()
{
	//싱글톤 인스턴스 첫번째 선언
	Singleton& s = Singleton::getInstance("shimwoojin");
	std::cout << s.get_name() << std::endl;
	//첫번째 선언한 이름으로 public 메서드 동작
	s.set_name("woojinshim");
	std::cout << s.get_name() << std::endl;

	//두번째 인스턴스 선언
	Singleton& s2 = Singleton::getInstance("shimwoojin2");
	std::cout << s2.get_name() << std::endl;
	//두번째 선언한 인스턴스에서 메서드 호출
	s2.set_name("woojinshimwoojinshim");
	//s1의 이름과 s2의 이름이 같음 -> 싱글톤 패턴 검증 완료
	std::cout << s.get_name() << std::endl;
	std::cout << s2.get_name() << std::endl;

	//Singleton s3;					//error
	//Singleton s4("shimwoojin");	//error
	//Singleton s5(s);				//error
	//Singleton s6 = s;				//error

	return 0;
}