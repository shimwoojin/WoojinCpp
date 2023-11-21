#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool check(int n, int limit)
{
	if (n < 0 || n >= limit)
	{
		return false;
	}
	return true;
}

void UpdateNext(int next[5], int dir, int floor)
{
	if (dir == 1)	//µ¿
	{
		next[1] = 7 - floor;
		next[2] = floor;
	}
	if (dir == 2)	//¼­
	{
		next[1] = floor;
		next[2] = 7 - floor;
	}
	if (dir == 3)	//ºÏ
	{
		next[3] = 7 - floor;
		next[4] = floor;
	}
	if (dir == 4)	//³²
	{
		next[3] = floor;
		next[4] = 7 - floor;
	}
}

int main()
{
	//13:41
	
	int n, m, x, y, k;
	cin >> n >> m >> y >> x >> k;
	vector<vector<int>> maps(n, vector<int>());
	vector<int> dirs;
	map<int, int> dice;
	int next[5] = {-1, 3, 4, 5, 2};
	pair<int, int> dirmap[5]
	{
		make_pair(-1, -1),
		make_pair(1, 0),
		make_pair(-1, 0),
		make_pair(0, -1),
		make_pair(0, 1)
	};

	//µ¿ 1 : x + 1
	//¼­ 2 : x - 1
	//ºÏ 3 : y - 1
	//³² 4 : y + 1

	for (int i = 1; i <= 6; i++)
	{
		dice[i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int a;
			cin >> a;
			maps[i].push_back(a);
		}
	}

	for (int i = 0; i < k; i++)
	{
		int a;
		cin >> a;
		//pair<int, int> dir;

		//if (a == 1)	//µ¿
		//{
		//	dir = make_pair(1, 0);
		//}
		//if (a == 2)	//¼­
		//{
		//	dir = make_pair(-1, 0);
		//}
		//if (a == 3)	//ºÏ
		//{
		//	dir = make_pair(0, 1);
		//}
		//if (a == 4)	//³²
		//{
		//	dir = make_pair(0, -1);
		//}

		dirs.push_back(a);
	}

	int floor = 1;
	dice[floor] = maps[y][x];

	for (auto dir : dirs)
	{
		pair<int, int> move = dirmap[dir];

		if (check(x + move.first, maps[0].size()) && check(y + move.second, maps.size()))
		{
			x += move.first;
			y += move.second;
			int floor_temp = floor;
			floor = next[dir];
			
			if (maps[y][x] == 0)
			{
				maps[y][x] = dice[floor];
			}
			else
			{
				dice[floor] = maps[y][x];
				maps[y][x] = 0;
			}

			UpdateNext(next, dir, floor_temp);

			cout << dice[7 - floor] << "\n";
		}
	}

	return 0;
}