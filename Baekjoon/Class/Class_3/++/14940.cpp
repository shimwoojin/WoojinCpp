#include <bits/stdc++.h>
using namespace std;

bool check(pair<int, int> now, const vector<vector<int>>& ground, const vector<vector<int>>& result)
{
	int now_x = now.first;
	int now_y = now.second;

	int max_x = ground[0].size();
	int max_y = ground.size();

	if (now_x < 0 || now_x >= max_x || now_y < 0 || now_y >= max_y)
	{
		return false;
	}

	if (ground[now_y][now_x] == 0)
	{
		return false;
	}

	if (result[now_y][now_x] != 0)
	{
		return false;
	}
	
	return true;
}

void calculate_distance(const vector<vector<int>>& ground, vector<vector<int>>& result, int x, int y)
{
	const static pair<int, int> dirs[4] =
	{
		{1,0},
		{-1,0},
		{0,-1},
		{0,1}
	};

	int count = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	result[y][x] = 1;

	while (!q.empty())
	{
		queue <pair<int, int>> temp;
		s
		while (!q.empty())
		{
			pair<int, int> front = q.front();
			q.pop();

			for (const auto& dir : dirs)
			{
				pair<int, int> next;
				next.first = front.first + dir.first;
				next.second = front.second + dir.second;
				
				if (check(next, ground, result))
				{
					temp.push(next);
					result[next.second][next.first] = count;
				}
			}
		}

		q = move(temp);
		++count;
	}

}

int main()
{
	int n, m;
	int start_x = 0, start_y = 0;
	cin >> n >> m;

	vector<vector<int>> ground(n, vector<int>(m, 0));
	vector<vector<int>> result(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> ground[i][j];

			if (ground[i][j] == 2)
			{
				start_x = j;
				start_y = i;
			}
		}
	}

	calculate_distance(ground, result, start_x, start_y);
	result[start_y][start_x] = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ground[i][j] == 1 && result[i][j] == 0)
			{
				result[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}