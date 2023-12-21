#include <bits/stdc++.h>
using namespace std;

constexpr pair<int, int> dirs[4] =
{
	{1,0},{-1,0},{0,1},{0,-1}
};

void dfs(const vector<string>& area, int& answer, bool GreenEqulRed)
{
	int size = area.size();
	vector<vector<bool>> visit(size, vector<bool>(size, false));

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (visit[i][j] == false)
			{
				++answer;
				char color = area[i][j];
				visit[i][j] = true;
				queue<pair<int, int>> q;

				q.push({j,i});
				
				while (!q.empty())
				{
					auto front = q.front();
					q.pop();
					
					for (auto dir : dirs)
					{
						int x = front.first + dir.first;
						int y = front.second + dir.second;

						if (x >= 0 && x < size && y >= 0 && y < size)
						{
							if (visit[y][x] == false)
							{
								if (color == 'R')
								{
									if (GreenEqulRed)
									{
										if (area[y][x] == 'G' || area[y][x] == 'R')
										{
											visit[y][x] = true;
											q.push({x,y});
										}
									}
									else
									{
										if (area[y][x] == 'R')
										{
											visit[y][x] = true;
											q.push({ x,y });
										}
									}
								}
								else if (color == 'G')
								{
									if (GreenEqulRed)
									{
										if (area[y][x] == 'G' || area[y][x] == 'R')
										{
											visit[y][x] = true;
											q.push({ x,y });
										}
									}
									else
									{
										if (area[y][x] == 'G')
										{
											visit[y][x] = true;
											q.push({ x,y });
										}
									}
								}
								else
								{
									if (color == area[y][x])
									{
										visit[y][x] = true;
										q.push({ x,y });
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<string> area(n);
	int answer1 = 0, answer2 = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> area[i];
	}

	dfs(area, answer1, false);
	dfs(area, answer2, true);

	cout << answer1 << '\n';
	cout << answer2;

	return 0;
}