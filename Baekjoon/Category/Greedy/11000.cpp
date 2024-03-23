#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int answer = 0, rooms = 0;
	int n;
	cin >> n;
	vector<pair<int, int>> classes;
	priority_queue<int, vector<int>, greater<int>> pq;

	while (n--)
	{
		int s, t;
		cin >> s >> t;
		classes.push_back({ s,t });
	}

	sort(classes.begin(), classes.end());

	for (int i = 0; i < classes.size(); i++)
	{
		int start = classes[i].first;
		int end = classes[i].second;
		int before_rooms = rooms;

		pq.push(end);

		while (!pq.empty() && pq.top() <= start)
		{
			pq.pop();
			--rooms;
		}

		++rooms;

		answer = max(answer, rooms);
	}

	cout << answer;

	return 0;
}