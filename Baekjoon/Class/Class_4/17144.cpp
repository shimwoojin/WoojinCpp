#include <iostream>
#include <vector>
using namespace std;

void Diffuse(vector<vector<int>>& room)
{
	vector<vector<int>> temp(room.size(), vector<int>(room[0].size(), 0));

	for (int i = 0; i < room.size(); i++) 
	{
		for (int j = 0; j < room[0].size(); j++)
		{
			if (room[i][j] == -1 || room[i][j] == 0)
			{
				continue;
			}

			int fragment = room[i][j] / 5;
			int count = 0;

			if (i + 1 < room.size() && room[i + 1][j] != -1)
			{
				temp[i + 1][j] += fragment;
				++count;
			}

			if (j + 1 < room[0].size() && room[i][j + 1] != -1)
			{
				temp[i][j + 1] += fragment;
				++count;
			}

			if (i - 1 >= 0 && room[i - 1][j] != -1)
			{
				temp[i - 1][j] += fragment;
				++count;
			}

			if (j - 1 >= 0 && room[i][j - 1] != -1)
			{
				temp[i][j - 1] += fragment;
				++count;
			}

			room[i][j] -= fragment * count;
		}
	}

	for (int i = 0; i < room.size(); i++)
	{
		for (int j = 0; j < room[0].size(); j++)
		{
			room[i][j] += temp[i][j];
		}
	}
}

void AirFresher(vector<vector<int>>& room, const vector<int>& minus_ones)
{
	int low_y = minus_ones[0] > minus_ones[1] ? minus_ones[1] : minus_ones[0];
	int high_y = minus_ones[0] > minus_ones[1] ? minus_ones[0] : minus_ones[1];

	for (int i = high_y + 2; i < room.size(); i++)
	{
		room[i - 1][0] = room[i][0];
	}

	for (int i = 1; i < room[0].size(); i++)
	{
		room[room.size() - 1][i - 1] = room[room.size() - 1][i];
	}

	for (int i = room.size() - 1; i > high_y; i--)
	{
		room[i][room[0].size() - 1] = room[i - 1][room[0].size() - 1];
	}

	for (int i = room[0].size() - 1; i >= 2; i--)
	{
		room[high_y][i] = room[high_y][i - 1];
	}
	room[high_y][1] = 0;

	for (int i = low_y - 1; i >= 1; i--)
	{
		room[i][0] = room[i - 1][0];
	}

	for (int i = 1; i < room[0].size(); i++)
	{
		room[0][i - 1] = room[0][i];
	}

	for (int i = 0; i < low_y; i++)
	{
		room[i][room[0].size() - 1] = room[i + 1][room[0].size() - 1];
	}

	for (int i = room[0].size() - 1; i >= 2; i--)
	{
		room[low_y][i] = room[low_y][i - 1];
	}
	room[low_y][1] = 0;
}

int Answer(const vector<vector<int>>& room)
{
	int answer = 0;

	for (int i = 0; i < room.size(); i++)
	{
		for (int j = 0; j < room[0].size(); j++)
		{
			if (room[i][j] != -1)
			{
				answer += room[i][j];
			}
		}
	}

	return answer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int r, c, t;
	cin >> r >> c >> t;
	vector<vector<int>> room(r, vector<int>(c, 0));
	vector<int> minus_ones;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> room[i][j];

			if (room[i][j] == -1)
			{
				minus_ones.push_back(i);
			}
		}
	}

	while (t--)
	{
		Diffuse(room);
		AirFresher(room, minus_ones);
	}

	cout << Answer(room);

	return 0;
}