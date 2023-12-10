#include <bits/stdc++.h>

using namespace std;

void find(int n, int r, int c, int y_min ,int x_min, int y_max, int x_max, int& count, bool& bFind)
{
	if (bFind)
	{
		return;
	}

	if (n > 1)
	{
		int x_half = (x_min + x_max) / 2;
		int y_half = (y_min + y_max) / 2;
		int add_size = pow((x_half - x_min), 2);

		if (c >= x_min && c < x_half && r >= y_min && r < y_half)
		{
			find(n - 1, r, c, y_min, x_min, y_half, x_half, count, bFind);
		}
		else
		{
			if (!bFind)
			{
				count += add_size;
			}
		}

		if (c >= x_half && c < x_max && r >= y_min && r < y_half)
		{
			find(n - 1, r, c, y_min, x_half, y_half, x_max, count, bFind);
		}
		else
		{
			if (!bFind)
			{
				count += add_size;
			}
		}

		if (c >= x_min && c < x_half && r >= y_half && r < y_max)
		{
			find(n - 1, r, c, y_half, x_min, y_max, x_half, count, bFind);
		}
		else
		{
			if (!bFind)
			{
				count += add_size;
			}
		}

		if (c >= x_half && c < x_max && r >= y_half && r < y_max)
		{
			find(n - 1, r, c, y_half, x_half, y_max, x_max, count, bFind);
		}
		else
		{
			if (!bFind)
			{
				count += add_size;
			}
		}
	}
	else
	{
		int x = x_min, y = y_min;
		pair<int, int> p{ y,x };
		for (auto ps : { make_pair(y,x), make_pair(y,x + 1), make_pair(y + 1,x), make_pair(y + 1,x + 1) })
		{
			if (ps.first == r && ps.second == c)
			{
				bFind = true;
				return;
			}
			++count;
		}
	}
}

int main()
{
	int count = 0;
	int n, r, c;
	cin >> n >> r >> c;
	int size = pow(2, n);

	bool bFind = false;
	find(n, r, c, 0, 0, size, size, count, bFind);

	cout << count;

	return 0;
}