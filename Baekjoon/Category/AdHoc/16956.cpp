#include <iostream>
#include <vector>
using namespace std;

int dir_x[4] = {0, 0, -1, 1};
int dir_y[4] = {1, -1, 0, 0};

int Solution(const vector<vector<char>>& world)
{
	int max_y = world.size();
	int max_x = world[0].size();

	for (int i = 0; i < max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
		{
			if (world[i][j] == 'S')
			{
				for (int k = 0; k < 4; k++)
				{
					int next_x = j + dir_x[k];
					int next_y = i + dir_y[k];

					if (next_x >= 0 && next_x < max_x && next_y >= 0 && next_y < max_y && world[next_y][next_x] == 'W')
					{
						return 0;
					}
				}
			}
		}
	}

	return 1;
}

void BuildAndPrint(vector<vector<char>>& world)
{
	int max_y = world.size();
	int max_x = world[0].size();

	for (int i = 0; i < max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
		{
			if (world[i][j] == 'S')
			{
				for (int k = 0; k < 4; k++)
				{
					int next_x = j + dir_x[k];
					int next_y = i + dir_y[k];

					if (next_x >= 0 && next_x < max_x && next_y >= 0 && next_y < max_y && world[next_y][next_x] != 'S')
					{
						world[next_y][next_x] = 'D';
					}
				}
			}
		}
	}

	for (int i = 0; i < max_y; i++)
	{
		for (int j = 0; j < max_x; j++)
		{
			cout << world[i][j];
		}
		cout << '\n';
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int r, c;
	cin >> r >> c;

	vector<vector<char>> world(r, vector<char>(c, '.'));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> world[i][j];
		}
	}

	int answer = Solution(world);

	cout << answer << '\n';

	if (answer == 1)
	{
		BuildAndPrint(world);
	}

	return 0;
}