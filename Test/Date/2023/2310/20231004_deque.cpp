#include <iostream>
#include <deque>

int main()
{
	std::deque<int> dq;

	for (int i = 0; i < 10; i++)
	{
		dq.push_back(i);
	}

	for (int i = 0; i < 10; i++)
	{
		std::cout << dq[0] << std::endl;
		dq.pop_front();
	}

	return 0;
}