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

int Solution(const vector<vector<int>>& path)
{
	int answer = 0;
	stack<Data> s;
	vector<vector<int>> dp(path.size(), vector<int>(path[0].size(), -1));

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = {1, -1, 0, 0};

	s.push({0, 0});
	dp[0][0] = 1;

	while (s.empty() == false)
	{
		Data top = s.top();
		s.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = top.x + dx[i];
			int ny = top.y + dy[i];

			if (nx >= 0 && nx < path[0].size() && ny >= 0 && ny < path.size())
			{
				if (path[ny][nx] > path[top.y][top.x])
				{

				}
			}
		}
	}

	return answer;
}

int main()
{
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

	cout << Solution(path);

	return 0;
}