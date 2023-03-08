#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

void Left(vector<vector<int>>& board, int n)
{
	vector<vector<int>> temp;
	temp.assign(n, vector<int>());

	for (int i = 0; i < board.size(); i++)
	{
		int before = 0;

		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] == 0) continue;

			if (board[i][j] == before)
			{
				temp[i].push_back(before * 2);
				before = 0;
			}
			else 
				before = board[i][j];
		}
	}

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = temp[i].size(); board[0].size(); i++)
		{
			temp[i].push_back(0);
		}
	}

	board = temp;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> board;
	board.assign(n, vector<int>());

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;

			board[i].push_back(a);
		}
	}

	Left(board, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}