#include <iostream>
//#include <cstring>
#include <string>

int main()
{
	using namespace std;
	char name1[40] = "shimwoojin";
	std::string name2 = "shimwoojin2";

	//sizeof�� strlen�� ���� : �迭 ��ü�� ũ��(capacity)�� sizeof, ���ڿ����� ũ��(����)�� strlen
	cout << sizeof(name1) << endl;
	cout << strlen(name1) << endl;

	cout << name2.size() << endl;

	//c��Ÿ�� ���ڿ��� string ��ü���� ���ڿ� �۾�
	strcpy_s(name1, name2.c_str());
	strcat_s(name1, name2.c_str());
	cout << name1 << endl;
	cout << name2 << endl;

	//cin.get�� cin.getline ���� �׽�Ʈ : get�� ������ ���� ���ܵ�, getline�� ������ ����(���๮�� Ȥ�� ��3�� �Ű�����) ����
	//getline�� ���๮�ڱ��� ���ֵ� �� ���� ���۱��� clear������ ���� ( cin.clear �ؾ� ��)
	char arrtest[20] = {};

	cin.get(arrtest,20).get();
	cout << arrtest << endl;

	char arrtest2[20] = {};

	cout << "���ڿ��� #�� ������ �ű⼭ ����" << endl;
	cin.getline(arrtest2,20,'#');
	cout << arrtest2 << endl;
	//cin.clear();
	//cin.ignore(10);
	//fflush(stdin);

	cin >> name1;
	cout << name1 << endl;

	return 0;
}