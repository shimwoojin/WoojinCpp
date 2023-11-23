#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

int main()
{
	//start : 19:03
	//end : 19:59

	int total = 0;
	int n;
	cin >> n;

	priority_queue<pair<int, int>> pq;	//day, score
	set<int, greater<int>> days;

	for (int i = 0; i < n; i++)
	{
		int day, score;
		cin >> day >> score;
		pq.push(make_pair(day, score));
		days.insert(day);
	}

	int now = pq.top().first;

	while (!pq.empty() && now > 0)
	{
		pair<int, int> top = pq.top();

		if (top.first != now)
		{
			while (!pq.empty())
			{
				if (pq.top().first == now)
				{
					pq.pop();
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			pq.pop();

			total += top.second;

			while (!pq.empty())
			{
				top = pq.top();

				if (top.first == now)
				{
					pq.pop();
					pq.push(make_pair(now - 1, top.second));
				}
				else
				{
					break;
				}
			}
		}

		--now;
	}

	std::cout << total;

	return 0;
}