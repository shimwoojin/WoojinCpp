#include <bits/stdc++.h>

using namespace std;

bool check(const vector<vector<int>>& box, pair<int, int> next)
{
	int x = next.first;
	int y = next.second;

	if (x < 0 || x >= box[0].size() || y < 0 || y >= box.size())
	{
		return false;
	}

	if (box[y][x] == -1 || box[y][x] == 1)
	{
		return false;
	}

	return true;
}

int dfs(vector<vector<int>>& box, const vector<pair<int, int>>& starts)
{
	const static pair<int, int> dirs[4] =
	{
		{1,0},
		{-1,0},
		{0,-1},
		{0,1}
	};

	queue<tuple<int, int, int>> q;
	int count = 0; 

	for (const auto& start : starts)
	{
		q.push({ start.first, start.second, 0 });
	}

	while (!q.empty())
	{
		tuple<int, int, int> front = q.front();
		q.pop();
		int x = get<0>(front);
		int y = get<1>(front);
		int c = get<2>(front);	//count

		count = max(count, c);

		for (const auto& dir : dirs)
		{
			pair<int, int> next;
			next.first = x + dir.first;
			next.second = y + dir.second;

			if (check(box, next))
			{
				box[next.second][next.first] = 1;
				q.push({ next.first, next.second, c+ 1 });
			}
		}
	}

	return count;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;
	int answer;
	cin >> m >> n;
	vector<vector<int>> box(n, vector<int>(m));
	vector<pair<int, int>> starts;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];

			if (box[i][j] == 1)
			{
				starts.push_back(make_pair(j, i));
			}
		}
	}

	answer = dfs(box, starts);

	bool result = any_of(box.begin(), box.end(), [](const vector<int>& vec) {
		for (auto& ele : vec)
		{
			if (ele == 0)
			{
				return true;
			}
		}
		return false;
		});

	if (result)
	{
		cout << -1;
	}
	else
	{
		cout << answer;
	}

	return 0;
}