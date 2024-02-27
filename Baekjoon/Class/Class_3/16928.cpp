#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
using pii = pair<int, int>;

int bfs(const vector<int>& ladders, const vector<int>& snakes)
{
	int answer = 0;
	int start = 1;
	vector<bool> visits(101, false);
	queue<pii> que;

	visits[start] = true;
	que.push(make_pair(start, 0));

	while (!que.empty())
	{
		pii front = que.front();
		que.pop();

		int nums[6];
		for (int i = 1; i <= 6; i++)
		{
			nums[i - 1] = front.first + i;
		}

		if (nums[5] >= 100)
		{
			answer = front.second + 1;
			break;
		}

		for (int num : nums)
		{
			if (ladders[num] != -1)
			{
				visits[num] = true;
				int fast = ladders.at(num);
				if (visits[fast] == false)
				{
					visits[fast] = true;
					que.push(make_pair(fast, front.second + 1));
				}
			}
			else if (snakes[num] != -1)
			{
				visits[num] = true;
				int slow = snakes.at(num);
				if (visits[slow] == false)
				{
					visits[slow] = true;
					que.push(make_pair(slow, front.second + 1));
				}
			}
			else
			{
				if (visits[num] == false)
				{
					visits[num] = true;
					que.push(make_pair(num, front.second + 1));
				}
			}
		}

	}

	return answer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<int> ladders(101, -1);
	vector<int> snakes(101, -1);

	while (n--)
	{
		int x, y;
		cin >> x >> y;
		ladders[x] = y;
	}

	while (m--)
	{
		int u, v;
		cin >> u >> v;
		snakes[u] = v;
	}

	cout << bfs(ladders, snakes);

	return 0;
}