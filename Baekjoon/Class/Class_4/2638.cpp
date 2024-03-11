#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Dfs(vector<vector<bool>>& air_zone, const vector<vector<int>>& paper, int x, int y)
{
	queue<pair<int, int>> q;

	if (air_zone[y][x] == false)
	{
		air_zone[y][x] = true;
		q.push({ x, y });
	}

	while (q.empty() == false)
	{
		pair<int, int> front = q.front();
		q.pop();
		int nx = front.first;
		int ny = front.second;

		if (nx - 1 >= 0 && paper[ny][nx - 1] == 0 && air_zone[ny][nx - 1] == false)
		{
			air_zone[ny][nx - 1] = true;
			q.push({ nx - 1, ny });
		}

		if (ny - 1 >= 0 && paper[ny - 1][nx] == 0 && air_zone[ny - 1][nx] == false)
		{
			air_zone[ny - 1][nx] = true;
			q.push({ nx, ny - 1 });
		}

		if (nx + 1 < paper[0].size() && paper[ny][nx + 1] == 0 && air_zone[ny][nx + 1] == false)
		{
			air_zone[ny][nx + 1] = true;
			q.push({ nx + 1, ny });
		}

		if (ny + 1 < paper.size() && paper[ny + 1][nx] == 0 && air_zone[ny + 1][nx] == false)
		{
			air_zone[ny + 1][nx] = true;
			q.push({ nx, ny + 1 });
		}
	}
}

void MakeAirZone(vector<vector<bool>>& air_zone, const vector<vector<int>>& paper)
{
	for (int x = 0; x < air_zone[0].size(); x++)
	{
		int y1 = 0, y2 = air_zone.size() - 1;

		if (air_zone[y1][x] == false)
			Dfs(air_zone, paper, x, y1);
		if (air_zone[y2][x] == false)
			Dfs(air_zone, paper, x, y2);
	}

	for (int y = 1; y < air_zone.size() - 1; y++)
	{
		int x1 = 0, x2 = air_zone[0].size() - 1;
		
		if (air_zone[y][x1] == false)
			Dfs(air_zone, paper, x1, y);
		if (air_zone[y][x2] == false)
			Dfs(air_zone, paper, x2, y);
	}
}

int Solution(vector<vector<int>>& paper)
{
	int answer = 0;
	vector<vector<bool>> air_zone(paper.size(), vector<bool>(paper[0].size(), false));

	while (true)
	{
		vector<pair<int, int>> pending_erases;	//x,y

		air_zone.assign(paper.size(), vector<bool>(paper[0].size(), false));
		MakeAirZone(air_zone, paper);

		for (int i = 0; i < paper.size(); i++)
		{
			for (int j = 0; j < paper[0].size(); j++)
			{
				int nx = j, ny = i, count = 0;

				if (paper[ny][nx] == 0) continue;

				if (nx - 1 >= 0 && air_zone[ny][nx - 1] == true) ++count;
				if (ny - 1 >= 0 && air_zone[ny - 1][nx] == true) ++count;
				if (nx + 1 < paper[0].size() && air_zone[ny][nx + 1] == true) ++count;
				if (ny + 1 < paper.size() && air_zone[ny + 1][nx] == true) ++count;

				if (count >= 2) pending_erases.push_back({ nx, ny });
			}
		}

		if (pending_erases.size() <= 0) break;

		for (auto ele : pending_erases)
		{
			paper[ele.second][ele.first] = 0;
		}

		++answer;
	}

	return answer;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> paper(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> paper[i][j];
		}
	}

	cout << Solution(paper);

	return 0;
}