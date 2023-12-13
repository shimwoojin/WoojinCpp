#include <bits/stdc++.h>
using namespace std;

int operator+(pair<int, int> a, pair<int, int> b)
{
	return a.second + b.second;
}

int main()
{
	int n, k;
	int answer = 0;
	cin >> n >> k;
	
	vector<pair<int, int>> bag;
	vector<pair<int, int>> dp(k + 1, make_pair(0,0));

	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;

		bag.push_back(make_pair(w, v));
	}

	sort(bag.begin(), bag.end());

	for (const auto& b : bag)
	{
		int weight = b.first;
		int value = b.second;

		if (dp[weight].first < value)
		{
			int temp = dp[weight].second;
			dp[weight].first = value;
			dp[weight].second = temp;
		}


	}


	cout << answer;

	return 0;
}