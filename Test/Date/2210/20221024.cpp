//��ӿ��� ������ �����ε��� ���� ��
//��ӿ��� friend �Լ��� ���� ���

#include<iostream>
#include "dma.h"

int main()
{
	using std::cout;
	using std::endl;

	baseDMA shirt("Portabelly", 8);
	lacksDMA balloon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo Keys", 5);

	cout << "baseDMA ��ü�� ����Ѵ�:\n";
	cout << shirt << endl;
	cout << "lacsDMA ��ü�� ����Ѵ�:\n";
	cout << balloon << endl;
	cout << "hasDMA ��ü�� ����Ѵ�:\n";
	cout << map << endl;
	lacksDMA balloon2(balloon);
	cout << "lacksDMA ���� ��� : \n";
	cout << balloon2 << endl;
	hasDMA map2;
	map2 = map;
	cout << "hasDMA ���� ���:\n";
	cout << map2 << endl;

	return 0;
}


