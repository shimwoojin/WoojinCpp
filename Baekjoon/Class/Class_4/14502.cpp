#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int Solution(vector<vector<int>>& room, int zero_size)
{
	int answer = 0;
	int dirty_zero = 0;
	vector<vector<bool>> visits(room.size(), vector<bool>(room[0].size(), false));

	for (int i = 0; i < room.size(); i++)
	{
		for (int j = 0; j < room[0].size(); j++)
		{
			if (room[i][j] == 2)
			{
				int x = j;
				int y = i;
				queue<pair<int, int>> q;
				visits[y][x] = true;

				q.push({x, y});

				while (q.empty() == false)
				{
					pair<int, int> front = q.front();
					q.pop();

					int nx = front.first;
					int ny = front.second;

					if (nx + 1 < room[0].size() && visits[ny][nx + 1] == false && room[ny][nx + 1] == 0)
					{
						visits[ny][nx + 1] = true;
						q.push({nx + 1, ny});
						++dirty_zero;
					}

					if (ny + 1 < room.size() && visits[ny + 1][nx] == false && room[ny + 1][nx] == 0)
					{
						visits[ny + 1][nx] = true;
						q.push({ nx, ny + 1});
						++dirty_zero;
					}

					if (nx - 1 >= 0 && visits[ny][nx - 1] == false && room[ny][nx - 1] == 0)
					{
						visits[ny][nx - 1] = true;
						q.push({ nx - 1, ny });
						++dirty_zero;
					}

					if (ny - 1 >= 0 && visits[ny - 1][nx] == false && room[ny - 1][nx] == 0)
					{
						visits[ny - 1][nx] = true;
						q.push({ nx, ny - 1 });
						++dirty_zero;
					}
				}
			}
		}
	}

	answer = zero_size - dirty_zero;

	return answer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int answer = 0;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> room(n, vector<int>(m, 0));
	vector<int> zeros;
	vector<bool> permu;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> room[i][j];

			if (room[i][j] == 0)
			{
				zeros.push_back(i * m + j);
			}
		}
	}

	permu.assign(zeros.size() - 3, false);
	permu.push_back(true);
	permu.push_back(true);
	permu.push_back(true);

	do
	{
		vector<pair<int, int>> xy;

		for (int i = 0; i < permu.size(); i++)
		{
			if (permu[i])
			{
				int x = zeros[i] % m;
				int y = zeros[i] / m;

				room[y][x] = 1;
				xy.push_back({ x, y });
			}
		}

		answer = max(answer, Solution(room, zeros.size() - 3));

		for (auto ele : xy)
		{
			room[ele.second][ele.first] = 0;
		}

	} while (next_permutation(permu.begin(), permu.end()));

	cout << answer;

	return 0;
}