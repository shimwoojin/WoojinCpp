#include <iostream>


int main()
{
	using namespace std;
	std::cout << "�ӳ�" << std::endl;
	const char* word = "hello world!!";
	cout << (void*)word << endl;

	(std::cout << "�ӳ�").put('3') << std::endl;

	cout << 'W' << endl;
	(cout << "�ȳ��ϼ���").write("�ݰ����ϴ�", 8) << endl;
	cout.write("helloworld!!",12)<<endl;

	long val = 12345678;
	cout.write((char*)&val, sizeof(long));

	return 0;
}