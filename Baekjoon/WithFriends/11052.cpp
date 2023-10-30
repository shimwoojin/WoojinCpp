#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> vec(N + 1);
	vector<int> result;
	result.push_back(0);

	for (int i = 1; i < N + 1; i++)
	{
		cin >> vec[i];
	}

	for (int i = 1; i < N + 1; i++)
	{
		result.push_back(vec[i]);

		for (int j = 1; j < result.size(); j++)
		{
			int realSize = result.size() - 1;
			int quotient = realSize / j;
			int remainder = realSize % j;
			result[i] = max(result[j] * quotient + result[remainder], result[i]);
		}
	}

	cout << result[N];

	return 0;
}