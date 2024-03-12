#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

struct BabyShark
{
	int x;
	int y;
	int size;
	int eat;
	int distance;
};

int Solution(vector<vector<int>>& space, pii start_loc, int fish_count)
{
	int answer = 0;
	vector<vector<bool>> visit(space.size(), vector<bool>(space[0].size(), false));
	BabyShark baby_shark = { start_loc.first, start_loc.second, 2, 0, 0 };

	while (fish_count > 0)
	{
		int before_fish_count = fish_count;
		visit.assign(space.size(), vector<bool>(space[0].size(), false));
		queue<BabyShark> q;
		priority_queue<pii, vector<pii>, greater<pii>> pq;

		q.push(baby_shark);
		visit[baby_shark.y][baby_shark.x] = true;
		int distance = 0;

		while (q.empty() == false)
		{
			BabyShark shark = q.front();
			q.pop();

			if (distance != shark.distance && !pq.empty())
			{
				int y = pq.top().first;
				int x = pq.top().second;

				space[y][x] = 0;
				answer += shark.distance;
				--fish_count;

				if (baby_shark.size == baby_shark.eat + 1)
				{
					baby_shark = { x, y, baby_shark.size + 1, 0, 0 };
				}
				else
				{
					baby_shark = { x, y, baby_shark.size, baby_shark.eat + 1, 0 };
				}

				break;
			}

			distance = shark.distance;
			shark.distance++;

			if (shark.y - 1 >= 0 && space[shark.y - 1][shark.x] <= shark.size && visit[shark.y - 1][shark.x] == false)
			{
				visit[shark.y - 1][shark.x] = true;
				BabyShark new_shark(shark);
				new_shark.y--;

				if (space[shark.y - 1][shark.x] == 0 || space[shark.y - 1][shark.x] == shark.size)
				{
					q.push(new_shark);
				}
				else
				{
					q.push(new_shark);
					pq.push({ shark.y - 1, shark.x });
				}
			}

			if (shark.x - 1 >= 0 && space[shark.y][shark.x - 1] <= shark.size && visit[shark.y][shark.x - 1] == false)
			{
				visit[shark.y][shark.x - 1] = true;
				BabyShark new_shark(shark);
				new_shark.x--;

				if (space[shark.y][shark.x - 1] == 0 || space[shark.y][shark.x - 1] == shark.size)
				{
					q.push(new_shark);
				}
				else
				{
					q.push(new_shark);
					pq.push({ shark.y, shark.x - 1});
				}
			}

			if (shark.y + 1 < space.size() && space[shark.y + 1][shark.x] <= shark.size && visit[shark.y + 1][shark.x] == false)
			{
				visit[shark.y + 1][shark.x] = true;
				BabyShark new_shark(shark);
				new_shark.y++;

				if (space[shark.y + 1][shark.x] == 0 || space[shark.y + 1][shark.x] == shark.size)
				{
					q.push(new_shark);
				}
				else
				{
					q.push(new_shark);
					pq.push({ shark.y + 1, shark.x });
				}
			}

			if (shark.x + 1 < space[0].size() && space[shark.y][shark.x + 1] <= shark.size && visit[shark.y][shark.x + 1] == false)
			{
				visit[shark.y][shark.x + 1] = true;
				BabyShark new_shark(shark);
				new_shark.x++;

				if (space[shark.y][shark.x + 1] == 0 || space[shark.y][shark.x + 1] == shark.size)
				{
					q.push(new_shark);
				}
				else
				{
					q.push(new_shark);
					pq.push({ shark.y, shark.x + 1 });
				}
			}
		}

		if (before_fish_count == fish_count)
		{
			break;
		}
	}

	return answer;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> space(n, vector<int>(n, 0));
	pii start_loc = { 0, 0 };
	int fish_count = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> space[i][j];
			if (space[i][j] == 9)
			{
				start_loc = { j, i };
				space[i][j] = 0;
			}
			else if (space[i][j] > 0)
			{
				++fish_count;
			}
		}
	}

	cout << Solution(space, start_loc, fish_count);

	return 0;
}