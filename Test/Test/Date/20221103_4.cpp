#include <functional>
#include <iostream>

int main()
{
	std::plus<double> add;
	double y = add(1.5, 2.5);

	int arr[3] = {1, 2, 3};
	int(*parr)[3] = &arr;		//이 부분 설명 부탁드립니다

	std::cout << (*parr)[1] << std::endl;

	int* parr2 = arr;			//원래 알고 있던 방법

	std::cout << parr2[1] << std::endl;


	return 0;
}