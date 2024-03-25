#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	vector<pii> dp(n, pii(1, 0));
	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				if (dp[j].first + 1 > dp[i].first)
				{
					dp[i].first = dp[j].first + 1;
					dp[i].second = j;
				}
			}
		}
	}

	auto iter = max_element(dp.begin(), dp.end());

	cout << (*iter).first << '\n';

	while ((*iter).first > 1)
	{
		s.push(iter - dp.begin());
		iter = dp.begin() + (*iter).second;
	}

	s.push(iter - dp.begin());

	while (s.empty() == false)
	{
		cout << arr[s.top()] << ' ';
		s.pop();
	}

	return 0;
}