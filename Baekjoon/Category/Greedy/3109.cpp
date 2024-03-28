#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using pii = pair<int, int>;

int r, c;
vector<vector<char>> world;
int answer = 0;
int y_dirs[3] = { -1, 0, 1 };
bool bFind = false;

void Solution(int x, int y)
{
	if (x == c - 1)
	{
		world[y][x] = 'x';
		++answer;
		bFind = true;
		return;
	}

	world[y][x] = 'x';

	for (int y_dir : y_dirs)
	{
		int x_next = x + 1;
		int y_next = y + y_dir;

		if (x_next < c && y_next >= 0 && y_next < r && world[y_next][x_next] == '.')
		{
			Solution(x_next, y_next);
			if (bFind)
			{
				return;
			}
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> r >> c;
	world.assign(r, vector<char>(c, 0));

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> world[i][j];
		}
	}

	for (int y = 0; y < r; y++)
	{
		Solution(0, y);
		bFind = false;
	}

	cout << answer;

	return 0;
}