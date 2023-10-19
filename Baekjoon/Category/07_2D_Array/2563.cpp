#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int board[100][100] = { 0 };

	int n;
	cin >> n;

	int width = 0;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		for (int j = x; j < x + 10; j++)
		{
			for (int k = y; k < y + 10; k++)
			{
				board[j][k] = 1;
			}
		}
	}

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (board[i][j] == 1)
			{
				++width;
			}
		}
	}

	cout << width;

	return 0;
}