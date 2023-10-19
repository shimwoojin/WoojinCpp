//multiple_inheritance.cpp

#include <iostream>

//#define TEST1
#define TEST2

#ifdef TEST1
class A 
{
public:
	A() : a(0) {}
	virtual void print() { std::cout << "A class" << std::endl; }
	//virtual ~A() = 0;
private:
	int a;
};
class B : virtual public A 
{
public:
	B() : b(1) { }
	virtual void print() { std::cout << "B class" << std::endl; }
private:
	int b;
};
class C : virtual public A
{
public:
	C() : c(2) { }
	virtual void print() { std::cout << "C class" << std::endl; }
	void onlyC() { std::cout << "only C class have this function" << std::endl; }
private:
	int c;
};
class D : public B, public C
{
public:
	D() : d(3) { }
	virtual void print() { std::cout << "D class" << std::endl; }
	void onlyD() { std::cout << "only D class have this function" << std::endl; }
private:
	int d;
};

int main()
{
	A* a = new A;
	A* b = new B;
	A* c = new C;
	A* d = new D;

	a->print();
	b->print();
	c->print();
	d->print();

	dynamic_cast<C*>(c)->onlyC();
	//static_cast<C*>(c)->onlyC();	//error -> �⺻ Ŭ���� "A"�� ���� �����͸� �Ļ� Ŭ���� "C"�� ���� �����ͷ� ��ȯ�� �� �����ϴ�. �⺻ Ŭ������ ���� Ŭ�����Դϴ�.
	
	dynamic_cast<D*>(d)->onlyD();

	return 0;
}
#endif

#ifdef TEST2
class A
{
public:
	A() : a(0) {}
	virtual void print() { std::cout << "A class" << std::endl; }
	//virtual ~A() = 0;
private:
	int a;
};
class B : public A
{
public:
	B() : b(1) { }
	virtual void print() { std::cout << "B class" << std::endl; }
private:
	int b;
};
class C : public A
{
public:
	C() : c(2) { }
	virtual void print() { std::cout << "C class" << std::endl; }
	void onlyC() { std::cout << "only C class have this function" << std::endl; }
private:
	int c;
};
class D : public B, public C
{
public:
	D() : d(3) { }
	virtual void print() { std::cout << "D class" << std::endl; }
private:
	int d;
};

int main()
{
	A* a = new A;
	A* b = new B;
	A* c = new C;
	//A* d = new D;		//error -> �⺻ Ŭ���� 'A'�� ��ȣ
	D d;


	a->print();
	b->print();
	c->print();
	//d->print();
	d.print();

	dynamic_cast<C*>(c)->onlyC();
	static_cast<C*>(c)->onlyC();

	return 0;
}
#endif