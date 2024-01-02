// Ŭ���� ���ø��� ���ø����� ������ Ŭ����

#include <iostream>

class TempalteTest2;

template <template <typename T> class Thing>
class TemplateTest
{
public:
	TemplateTest() {}
	TemplateTest(Thing<int> a, Thing<double> b) :s1(a), s2(b) {}

	void show() { s1.show(); s2.show(); }

	
private:
	Thing<int> s1;
	Thing<double> s2;
};

template <typename T>
class TemplateTest2
{
public:
	TemplateTest2() : a(10) {}
	TemplateTest2(int a) : a(a) {}
	TemplateTest2(double a) : a(a) {}

	void show() { 
		std::cout << "�̰��� Template2��" << a << "�Դϴ�" << std::endl;
	}

	friend void show_a(const TemplateTest2<T>& t1) { std::cout << "�̰��� friend �Լ���" << t1.a << "�Դϴ�" << std::endl; }

private:
	T a;
};

template <typename T>
using ezTemp = TemplateTest2<T>;

int main()
{
	TemplateTest2<int> a(2);
	TemplateTest2<double> b(2.5);
	TemplateTest<TemplateTest2> t1(a, b);
	t1.show();
	TemplateTest<TemplateTest2> t2;
	t2.show();
	show_a(a);
	show_a(b);

	ezTemp<int> c(3);
	show_a(c);

	return 0;
}