#include <bits/stdc++.h>
using namespace std;

//308ms
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

//시간 줄이기

//int dp[100001];
//
// //8ms
//int main()
//{
//	int n, k;
//	int answer = 0;
//	cin >> n >> k;
//
//	priority_queue<pair<int, int>> pq;
//	
//	for (int i = 0; i < n; i++)
//	{
//		int w, v;
//		cin >> w >> v;
//
//		pq.push(make_pair(w, v));
//	}
//
//	//무게가 무거운 물건부터 확인
//	while (!pq.empty())
//	{
//		int w = pq.top().first;
//		int v = pq.top().second;
//		pq.pop();
//		
//		//핵심 로직 -> 음.. 이해가 잘 안 됨
//		for (int i = k; i >= w; i--)
//		{
//			dp[i] = max(dp[i], dp[i - w] + v);
//		}
//	}
//
//	answer = dp[k];
//
//	cout << answer;
//
//	return 0;
//}