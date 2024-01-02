//상속에서 연산자 오버로딩에 대한 것
//상속에서 friend 함수에 대한 사용

#include<iostream>
#include "dma.h"

int main()
{
	using std::cout;
	using std::endl;

	baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);

	cout << "baseDMA 객체를 출력한다:\n";
	cout << shirt << endl;
	cout << "lacsDMA 객체를 출력한다:\n";
	cout << balloon << endl;
	cout << "hasDMA 객체를 출력한다:\n";
	cout << map << endl;
	lacksDMA balloon2(balloon);
	cout << "lacksDMA 복사 결과 : \n";
	cout << balloon2 << endl;
	hasDMA map2;
	map2 = map;
	cout << "hasDMA 대입 결과:\n";
	cout << map2 << endl;

	return 0;
}


