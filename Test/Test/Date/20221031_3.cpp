#include <vector>
#include <iostream>

int main()
{
	std::vector<int> A(10);
	A.push_back(16);
	A.push_back(15);
	A.push_back(12);
	A.push_back(13);
	A.push_back(14);
	A.push_back(11);
	std::cout << A.capacity() << std::endl;

	for (int i = 0; i < A.size(); i++) std::cout << A[i] << std::endl;

	std::cout << A.front() << std::endl;
	std::cout << A.back() << std::endl;
	//A.rbegin();
	for (int i = 0; i < A.size(); i++) std::cout << A[i] << std::endl;
	A.insert(A.begin()+2, 3);
	for (int i = 0; i < A.size(); i++) std::cout << A[i] << std::endl;
	std::cout << A[6] << std::endl;
	

	return 0;
}