#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

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