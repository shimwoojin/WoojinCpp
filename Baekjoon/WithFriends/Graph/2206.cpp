#include <bits/stdc++.h>
using namespace std;

constexpr pair<int, int> dirs[4] =
{
	{0, 1}, { 0,-1 }, { 1,0 }, { -1,0 }
};

bool Check_OutOfMap(int x_max, int y_max, int x_now, int y_now)
{
	if (x_now < 0 || x_now >= x_max || y_now < 0 || y_now >= y_max)
	{
		return false;
	}

	return true;
}


int bfs(const vector<string>& my_map, int n, int m)
{
	queue<pair<int, int>> q;
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	vector<vector<int>> wall_distances(n, vector<int>(m, 0));
	priority_queue<int, vector<int>, greater<>> pq;
	int answer = 1;
	int no_wall_answer = 0;
	int count = 1;

	pair<int, int> start = { 0, 0 };

	//=================================
	//시작 지점에서 벽까지 거리를 재보기

	q.push(start);
	visit[0][0] = true;

	while (!q.empty())
	{
		queue<pair<int, int>> temp;

		while (!q.empty())
		{
			auto front = q.front();
			int x = front.first;
			int y = front.second;
			q.pop();

			if (my_map[y][x] == '1')
			{
				wall_distances[y][x] = count;
				continue;
			}

			if (x == m - 1 && y == n - 1)
			{
				no_wall_answer = count;
			}

			for (auto dir : dirs)
			{
				pair<int, int> next = { x + dir.first, y + dir.second };

				if (Check_OutOfMap(m, n, next.first, next.second) && visit[next.second][next.first] == false)
				{
					visit[next.second][next.first] = true;
					temp.push(next);
				}
			}
		}

		++count;
		q = move(temp);
	}

	//=================================
	//끝 지점에서 벽까지 거리를 재보기

	for (auto& v : visit)
	{
		v.assign(m, false);
	}
	count = 0;
	start = { m - 1, n - 1 };

	q.push(start);

	while (!q.empty())
	{
		queue<pair<int, int>> temp;

		while (!q.empty())
		{
			auto front = q.front();
			int x = front.first;
			int y = front.second;
			q.pop();

			if (my_map[y][x] == '1')
			{
				if (wall_distances[y][x] != 0)
				{
					pq.push(wall_distances[y][x] + count);
				}
				continue;
			}

			for (auto dir : dirs)
			{
				pair<int, int> next = { x + dir.first, y + dir.second };

				if (Check_OutOfMap(m, n, next.first, next.second))
				{
					if (visit[next.second][next.first] == false)
					{
						visit[next.second][next.first] = true;
						temp.push(next);
					}
				}
			}
		}

		++count;
		q = move(temp);
	}

	if (no_wall_answer != 0)
	{
		if (!pq.empty())
		{
			answer = std::min(pq.top(), no_wall_answer);
		}
		else
		{
			answer = no_wall_answer;
		}
	}
	else
	{
		if (!pq.empty())
		{
			answer = pq.top();
		}
		else
		{
			answer = -1;
		}
	}

	return answer;
}

int main()
{
	//start : 12:15

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<string> my_map(n);

	for (int i = 0; i < n; i++)
	{
		cin >> my_map[i];
	}

	cout << bfs(my_map, n, m) << endl;

	return 0;
}