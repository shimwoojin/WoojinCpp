#include <iostream>

int main()
{
	//�����ͳ� ���� ���������� ����ȯ���� ������ �ڷ����� �ٲ��� ���ϰ� const�� Ȥ�� volatile���� �ٲ� �� ����
	const int a = 10;
	//int* b = const_cast<int*>(&a);	//error
	int* b = const_cast<int*>(&a);

	*b += 1;
	std::cout << a << std::endl;
	std::cout << *b << std::endl;


	return 0;
}