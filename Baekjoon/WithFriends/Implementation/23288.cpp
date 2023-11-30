#include <iostream>
#include <vector>
#include <queue>

using namespace std;

constexpr pair<int, int> dirs[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };	//�� �� �� ��

bool check_can_move(pair<int, int> move, int max_x, int max_y)
{
	int move_x = move.first;
	int move_y = move.second;

	if (move_x < 0 || move_x >= max_x || move_y < 0 || move_y >= max_y)
	{
		return false;
	}

	return true;
}

void AllocateMapScore(vector<vector<pair<int, int>>>& my_map)
{
	int max_x = my_map[0].size();
	int max_y = my_map.size();

	for (int i = 0; i < max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
		{
			vector<pair<int, int>> changes;
			int count = 0;

			if (my_map[i][j].second == -1)	//���� ������ ���ٸ�
			{
				queue<pair<int, int>> bfs_q;
				int must_same = my_map[i][j].first;

				bfs_q.push(make_pair(j, i));
				changes.push_back(make_pair(j, i));	//j = x, i = y
				my_map[i][j].second = 0;

				while (!bfs_q.empty())
				{
					queue<pair<int, int>> temp;

					while (!bfs_q.empty())
					{
						pair<int, int> front = bfs_q.front();
						bfs_q.pop();
						++count;
						
						for (auto dir : dirs)
						{
							pair<int, int> move{ front.first + dir.first, front.second + dir.second };
							
							if (check_can_move(move, max_x, max_y))
							{
								if (my_map[move.second][move.first].first == must_same && my_map[move.second][move.first].second == -1)
								{
									temp.push(move);
									changes.push_back(move);
									my_map[move.second][move.first].second = 0;
								}
							}
						}
					}

					if (temp.size() > 0)
					{
						bfs_q = move(temp);
					}
				}

				for (const auto& change : changes)
				{
					my_map[change.second][change.first].second = count;
				}
			}
		}
	}
}

int main()
{
	//start : 20:42
	//end : 22:03

	//(r,c) -> (y,x)
	
	int answer = 0;
	int n, m, k;
	cin >> n >> m >> k;

	vector<vector<pair<int, int>>> my_map(n, vector<pair<int, int>>(m, make_pair(-1, -1)));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> my_map[i][j].first;
		}
	}

	AllocateMapScore(my_map);

	int x = 0, y = 0;

	int dice_floor = 6;
	int dice_dir[4] = { 3, 4, 5, 2 };	//�� �� �� ��
	int dir_index = 0;	//��

	for (int i = 0; i < k; i++)
	{
		pair<int, int> move = dirs[dir_index];

		if (check_can_move({ x + move.first, y + move.second }, m, n))
		{
			x += move.first;
			y += move.second;
		}
		else
		{
			x -= move.first;
			y -= move.second;

			if (dir_index % 2 == 0)
			{
				++dir_index;
			}
			else
			{
				--dir_index;
			}
		}

		int floor_before = dice_floor;
		dice_floor = dice_dir[dir_index];	//�ٴ� ����

		switch (dir_index)	//�ֻ��� ������ ���� �������� ���� ����
		{
		case 0:	//��
		{
			dice_dir[0] = 7 - floor_before;
			dice_dir[1] = floor_before;
			break;
		}
		case 1:	//��
		{
			dice_dir[0] = floor_before;
			dice_dir[1] = 7 - floor_before;
			break;
		}
		case 2:	//��
		{
			dice_dir[2] = 7 - floor_before;
			dice_dir[3] = floor_before;
			break;
		}
		case 3:	//��
		{
			dice_dir[2] = floor_before;
			dice_dir[3] = 7 - floor_before;
			break;
		}
		}

		if (dice_floor > my_map[y][x].first)	// A > B
		{
			//90�� �ð� ����
			//��(0) -> ��(2), ��(2) -> ��(1), ��(1) -> ��(3), ��(3) -> ��(0)
			if (dir_index == 0)
			{
				dir_index = 2;
			}
			else if (dir_index == 2)
			{
				dir_index = 1;
			}
			else if (dir_index == 1)
			{
				dir_index = 3;
			}
			else if (dir_index == 3)
			{
				dir_index = 0;
			}
		}
		else if (dice_floor < my_map[y][x].first)	// A < B
		{
			//90�� �ݽð� ����
			//��(0) -> ��(3), ��(2) -> ��(0) -> ��(1) -> ��(2), ��(3) -> ��(1)
			if (dir_index == 0)
			{
				dir_index = 3;
			}
			else if (dir_index == 2)
			{
				dir_index = 0;
			}
			else if (dir_index == 1)
			{
				dir_index = 2;
			}
			else if (dir_index == 3)
			{
				dir_index = 1;
			}
		}
		// A == B
		else
		{

		}

		answer += my_map[y][x].first * my_map[y][x].second;
	}

	cout << answer;

	return 0;
}