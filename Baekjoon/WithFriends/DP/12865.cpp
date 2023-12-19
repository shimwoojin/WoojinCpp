#include <bits/stdc++.h>
using namespace std;

int main()
{
	//start : 12:30
	//end : 12:50

	int n, k;
	int answer = 0;
	cin >> n >> k;
	
	vector<pair<int, int>> bag;
	map<int, int> dp;

	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;

		bag.push_back(make_pair(w, v));
	}

	sort(bag.begin(), bag.end());

	for (const auto& b : bag)
	{
		map<int, int> temp;

		int weight = b.first;
		int value = b.second;

		for (const auto& ele : dp)
		{
			int new_weight = ele.first + weight;
			int new_value = ele.second + value;

			if (new_weight <= k)
			{
				temp[new_weight] = new_value;
			}
		}

		for (const auto& ele : temp)
		{
			dp[ele.first] = max(dp[ele.first], ele.second);
		}

		dp[weight] = max(dp[weight], value);
	}

	for (int i = 1; i <= k; i++)
	{
		answer = max(dp[i], answer);
	}

	cout << answer;

	return 0;
}