#include <iostream>
#include <vector>

using namespace std;

int main()
{
	long long n;
	long long answer = 0;
	cin >> n;
	vector<long long> lengths(n);
	vector<long long> prices(n);
	for (int i = 1; i < n; i++)
	{
		cin >> lengths[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> prices[i];
	}

	long long now = prices[0];
	answer += prices[0] * lengths[1];

	for (int i = 1; i < n; i++)
	{
		if (now < prices[i])
		{
			answer += now * lengths[i + 1];
		}
		else
		{
			now = prices[i];
			answer += now * lengths[i + 1];
		}
	}

	cout << answer;

	return 0;
}