#include <functional>
#include <iostream>

int main()
{
	std::plus<double> add;
	double y = add(1.5, 2.5);

	int arr[3] = {1, 2, 3};
	int(*parr)[3] = &arr;		//�� �κ� ���� ��Ź�帳�ϴ�

	std::cout << (*parr)[1] << std::endl;

	int* parr2 = arr;			//���� �˰� �ִ� ���

	std::cout << parr2[1] << std::endl;


	return 0;
}