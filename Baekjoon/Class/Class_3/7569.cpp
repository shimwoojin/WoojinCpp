#include <bits/stdc++.h>

using namespace std;

bool check(const vector<vector<vector<int>>>& box, tuple<int, int, int> next)
{
	int x = get<0>(next);
	int y = get<1>(next);
	int z = get<2>(next);

	if (x < 0 || x >= box[0][0].size() || y < 0 || y >= box[0].size() || z < 0 || z >= box.size())
	{
		return false;
	}

	if (box[z][y][x] == -1 || box[z][y][x] == 1)
	{
		return false;
	}

	return true;
}

int dfs(vector<vector<vector<int>>>& box, const vector<tuple<int, int, int>>& starts)
{
	const static tuple<int, int, int> dirs[6] =
	{
		{1,0, 0},
		{-1,0, 0},
		{0,-1, 0},
		{0,1, 0},
		{0,0, 1},
		{0,0, -1},
	};

	queue<tuple<int, int, int>> q;
	int count = 0;

	for (const auto& start : starts)
	{
		q.push(start);
	}

	while (!q.empty())
	{
		queue<tuple<int, int, int>> temp;

		while (!q.empty())
		{
			tuple<int, int, int> front = q.front();
			q.pop();

			for (const auto& dir : dirs)
			{
				tuple<int, int, int> next;
				get<0>(next) = get<0>(front) + get<0>(dir);
				get<1>(next) = get<1>(front) + get<1>(dir);
				get<2>(next) = get<2>(front) + get<2>(dir);
				

				if (check(box, next))
				{
					temp.push(next);
					box[get<2>(next)][get<1>(next)][get<0>(next)] = 1;
				}
			}
		}

		if (temp.empty())
		{
			break;
		}
		else
		{
			q = move(temp);
			++count;
		}
	}

	return count;
}

int main()
{
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios_base::sync_with_stdio(0);

	int m, n, h;
	int answer;
	cin >> m >> n >> h;
	vector<vector<vector<int>>> box(h, vector<vector<int>>(n, vector<int>(m)));
	vector<tuple<int, int, int>> starts;

	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> box[k][i][j];

				if (box[k][i][j] == 1)
				{
					starts.push_back(make_tuple(j, i, k));
				}
			}
		}
	}

	answer = dfs(box, starts);

	bool result = any_of(box.begin(), box.end(), [](const vector<vector<int>>& vec) {
		for (auto& ele : vec)
		{
			for (auto& e : ele)
			{
				if (e == 0)
				{
					return true;
				}
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