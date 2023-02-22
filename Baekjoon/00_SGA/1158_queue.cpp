//20230214

#include <iostream>
#include <queue>

int main()
{
	int N, K;
	std::queue<int> circular;

	std::cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		circular.push(i);
	}

	std::cout << "<";

	while (true)
	{
		static int count = 0;

		count++;

		if (circular.empty() == true) break;
		
		if (count != K)
		{
			circular.push(circular.front());
			circular.pop();
		}
		else
		{
			std::cout << circular.front();
			circular.pop();
			if (circular.empty() == false) std::cout << ", ";
			count = 0;
		}
	}

	std::cout << ">";

	return 0;
}