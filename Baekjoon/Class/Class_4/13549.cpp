#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int bfs(int n, int k)
{
	if (n == k) return 0;

	int answer = 0;
	int big = n > k ? n : k;
	int limit = big * 2 + 1;
	vector<bool> visits(limit, false);
	queue<pii> q;

	q.push(make_pair(n, 0));
	visits[n] = true;

	while (q.empty() == false)
	{
		pii front = q.front();
		q.pop();

		int nexts[2] = { front.first - 1 , front.first + 1 };
		int special_next = front.first * 2;

		while (special_next < limit && special_next != 0)
		{
			if (special_next == k)
			{
				return front.second;
			}

			if (visits[special_next] == false)
			{
				visits[special_next] = true;
				q.push({ special_next, front.second});
			}

			special_next *= 2;
		}

		for (int next : nexts)
		{
			if (next == k)
			{
				return front.second + 1;
			}

			if (next >= 0 && next < limit && visits[next] == false)
			{
				visits[next] = true;
				q.push({ next, front.second + 1});
			}
		}
	}

	return answer;
}

int main()
{
	int n, k;
	cin >> n >> k;

	cout << bfs(n, k);

	return 0;
}