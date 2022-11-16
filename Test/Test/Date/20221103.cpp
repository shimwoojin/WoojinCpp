#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
	int arr[10] = { 1,2,3,4,6,5,7,8,9,10 };

	std::sort(arr, arr + 10);

	for (int i = 0; i < 10; i++)
		std::cout << arr[i] << std::endl;

	std::vector<int> arr2(10);

	std::copy(arr, arr + 10, arr2.begin());

	for (int i = 0; i < 10; i++)
		std::cout << arr2[i] << std::endl;

	std::ostream_iterator<int, char> out_iter(std::cout, " ");
	*out_iter++ = 15;
	std::cout << std::endl;

	std::copy(arr, arr + 10, out_iter);
	std::cout << std::endl;

	std::copy(arr2.rbegin(), arr2.rend(), out_iter);
	std::cout << std::endl;

	std::vector<int>::reverse_iterator ri;
	for (ri = arr2.rbegin(); ri != arr2.rend(); ++ri)
		std::cout << *ri << ' ';

	return 0;
}