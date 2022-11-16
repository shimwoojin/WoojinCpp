// string ����غ���

#include <iostream>
#include <string>

int main()
{
	using std::string; using std::cout; using std::endl;

	/*
		string Ŭ������ Ư¡
		- ������ ���� null���� ���� x
		- �迭ó�� �ٷ� �� ����
		- ���ڿ� ��ġ�� ���� + �����ڷ� ����(������ �����ε�)
		- ���ڿ� ������ �������� ����
		- �پ��� ��� �Լ� ����
	*/
	
	string str1 = "Hello world!";
	string str2 = "C++";

	/*
		string�� �ε��� ����
		- �迭ó�� ���� : ��ȯ�Ǵ� ���ڴ� char��
		- .at(index) : ��ȯ�Ǵ� ���ڴ� char��
	*/

	cout << "�迭ó�� ���� : " << str1[0] << endl;
	cout << ".at �Լ� ��� : " << str1.at(0) << endl;

	/*
		���ڿ��� �� �հ� �� �� ���� ��ȯ
		- str.front() : �� �� ���� ��ȯ
		- str.back() :  �� �� ���� ��ȯ
	*/
	
	cout << "str1.front() : " << str1.front() << endl;
	cout << "str1.back() : " << str1.back() << endl;
	cout << "str2.back() : " << str2.back() << endl;
	cout << "str2.back() : " << str2.back() << endl;

	/*
		���ڿ��� ���� ��ȯ
		- str.size()
		- str.length()
	*/
	
	cout << "str1.size() : " << str1.size() << endl;
	cout << "str2.length() : " << str2.length() << endl;
	
	/*
		���� -> ���ڿ�, ���ڿ� -> ����
		- to_string() : ���� -> ���ڿ�
		- stoi, stod, stof, stof : ���ڿ� -> ���� (int, double, float, long int)
	*/

	// ���� -> ���ڿ�

	int a = 10;
	string str3;
	str3 = std::to_string(a);

	cout << "���ڸ� ���ڷ� : " << str3 << endl;
	cout << "���ڸ� ���ڷ� : " << std::to_string(a) << endl;

	// ���ڿ� -> ����

	string str_i = "11";
	string str_d = "12.3456";
	string str_f = "12.3456";
	string str_li = "2300000000";

	int after_i = std::stoi(str_i);
	int after_d = std::stod(str_d);
	int after_f = std::stof(str_f);
	int after_li = std::stof(str_li);

	// cout ��� �����Ͽ� double, float, long int �� ��� ����
	cout << after_i << " " << after_d << " " << after_f << " " << after_li << endl;

	/*
		���ڿ��� capacity
		capacity�� �� ��ü�� �Ҵ�� �޸� bytes ũ��� ��ü�� ���� ���ڿ� ũ�⿡ ����Ͽ�
		�˳��ϰ� �˾Ƽ� ����
		- str.capacity() : capacity �� Ȯ�� (byteũ��)
		- str.reserve(n) : ���ڿ� ��ü�� �̸� n bytes ũ�� �Ҵ�
	*/

	cout << "str1.capacity() : " << str1.capacity() << endl;
	str1.reserve(50);
	cout << "str1.capacity() : " << str1.capacity() << endl;
	//cout << "str1�� 50��° �ε��� : " << str1[50] << endl;
	//error!

	/*
		�� �� ������ �Լ���
		- str.empty() : size Ȥ�� length���� 0���� �ƴ��� Ȯ��
		- swap(str1,str2) : swap
		- str.clear() : ���ڿ� ����, capacity���� ����
		- str.append(str2) : +�����ڶ� ���� ���
		- str.find(str2) : str���� ���ڿ� str2�� ã�� ������ �ε��� ��ȯ
		- str.substr() : ������ �Ϻκ� ��ȯ (��ȯ�� string)
		- str.replace(idx,len,str2) : ���ڿ��� Ư�� �ε������� ���� ���̸�ŭ str2�� ����
	*/

	cout << "str1.empty() : " << str1.empty() << endl;
	swap(str1, str2);
	cout << "str2�� swap �� str1 : " << str1 << endl;
	cout << "swap �� str1�� length : " << str1.length() << endl;
	cout << "swap �� str2�� size : " << str2.size() << endl;
	cout << "swap �� str1�� capacity : " << str1.capacity() << endl;
	cout << "swap �� str2�� capacity : " << str2.capacity() << endl;
	str1.clear();
	cout << "str1.clear() �� empty���� : " << str1.empty() << endl;
	cout << "str1.clear() �� capacity : " << str1.capacity() << endl;
	cout << "str_i, str_d�� append ��� : " << str_i.append(str_d) << endl;
	cout << "str_i, str_d�� +������ ���� : " << str_i+str_d << endl;
	// �Ƹ� lvalue�� rvalue�� �����ε� ?
	cout << "str_i, str_d�� +������ �� ���� ���� : " << str_i+str_d << endl;
	cout << "str2.find(\"world\") : " << str2.find("world") << endl;	//str2 ���� ���� : Hello world!
	cout << "str2.substr(3, 5)  : " << str2.substr(3, 5) << endl;	//3��° �ε������� 5���� ��ŭ
	cout << "str2.substr(0, str2.size()) : " << str2.substr(0, str2.size()) << endl;	//ó������ ������
	str2.replace(str2.begin() + 1, str2.end() - 2, "TEST");
	cout << "str2.replace(str2.begin() + 1, str2.end() - 2, \"TEST\") : " << str2 << endl;
	return 0;
}