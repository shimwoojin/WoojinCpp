#include <bits/stdc++.h>
using namespace std;

bool check(pair<int, int> next, const vector<string>& campus, int x_max, int y_max)
{
	int x = next.first;
	int y = next.second;

	if (x < 0 || x >= x_max || y < 0 || y >= y_max)
	{
		return false;
	}

	if (campus[y][x] == 'X')
	{
		return false;
	}

	return true;
}

int bfs(vector<string>& campus)
{
	int answer = 0;

	int x_max = campus[0].size();
	int y_max = campus.size();
	int x_start = 0;
	int y_start = 0;

	constexpr pair<int, int> dirs[4] =
	{
		{0, 1}, {0, -1}, {1, 0}, {-1, 0}
	};

	for (int i = 0; i < y_max; i++)
	{
		for (int j = 0; j < x_max; j++)
		{
			if (campus[i][j] == 'I')
			{
				x_start = j;
				y_start = i;
				break;
			}
		}
	}

	queue<pair<int, int>> q;
	vector<vector<bool>> visit(y_max, vector<bool>(x_max, false));

	q.push(make_pair(x_start, y_start));
	visit[y_start][x_start] = true;

	while (!q.empty())
	{
		auto front = q.front();
		q.pop();

		int x = front.first;
		int y = front.second;

		if (campus[y][x] == 'P')
		{
			++answer;
		}
		
		for (auto dir : dirs)
		{
			pair<int, int> next = { x + dir.first , y + dir.second };

			if (check(next, campus, x_max, y_max) && visit[next.second][next.first] == false)
			{
				q.push(next);
				visit[next.second][next.first] = true;
			}
		}
	}

	return answer;
}

int main()
{
	int n, m;
	cin >> n >> m;

	vector<string> campus(n);

	for (int i = 0; i < n; i++)
	{
		cin >> campus[i];
	}

	int answer = bfs(campus);

	if (answer)
	{
		cout << answer << '\n';
	}
	else
	{
		cout << "TT" << '\n';
	}

	return 0;
}