#include <iostream>

int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[10] = { 0 };

	std::copy(arr1, arr1 + 10, arr2);

	for(auto ele : arr2)
	{ 
		std::cout << ele << std::endl;
	}

	return 0;
}