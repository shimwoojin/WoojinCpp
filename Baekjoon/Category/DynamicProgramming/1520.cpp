#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using pii = pair<int, int>;

struct Data
{
	int x;
	int y;
};

int Solution(const vector<vector<int>>& path, int x, int y)
{
	int answer = 0;
	stack<Data> s;
	vector<vector<int>> dp(path.size(), vector<int>(path[0].size(), -1));

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = {1, -1, 0, 0};

	s.push({x, y});
	dp[0][0] = 1;

	while (s.empty() == false)
	{
		vector<Data> temp1;
		vector<Data> temp2;
		Data top = s.top();
		s.pop();

		if (top.y == 0 && top.x == 0) continue;

		for (int i = 0; i < 4; i++)
		{
			int nx = top.x + dx[i];
			int ny = top.y + dy[i];

			if (nx >= 0 && nx < path[0].size() && ny >= 0 && ny < path.size())
			{
				if (path[ny][nx] > path[top.y][top.x])
				{
					if (dp[ny][nx] == -1)
					{
						temp1.push_back({nx, ny});
					}
					else
					{
						temp2.push_back({nx, ny});
					}
				}
			}
		}

		if (temp1.empty())
		{
			dp[top.y][top.x] = 0;

			for (auto ele : temp2)
			{
				dp[top.y][top.x] += dp[ele.y][ele.x];
			}
		}
		else
		{
			s.push(top);
			for (auto ele : temp1)
			{
				s.push({ele.x, ele.y});
			}
		}
	}

	answer = dp[y][x];
	return answer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;
	vector<vector<int>> path(m, vector<int>(n, 0));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> path[i][j];
		}
	}

	cout << Solution(path, n - 1, m - 1);

	return 0;
}