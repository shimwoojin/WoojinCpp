#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
using pii = pair<int, int>;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	long long answer = 0;
	int n, k;
	cin >> n >> k;
	priority_queue<pii> jewels;
	multiset<int> bags;

	for (int i = 0; i < n; i++)
	{
		int m, v;
		cin >> m >> v;
		jewels.push({ v, m });
	}

	for (int i = 0; i < k; i++)
	{
		int weight;
		cin >> weight;
		bags.insert(weight);
	}

	while (!bags.empty() && !jewels.empty())
	{
		int price = jewels.top().first;
		int weight = jewels.top().second;
		jewels.pop();

		auto iter = bags.lower_bound(weight);

		if (iter != bags.end())
		{
			bags.erase(iter);
			answer += price;
		}
	}

	cout << answer;

	return 0;
}