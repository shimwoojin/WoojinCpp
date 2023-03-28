#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

void CheckQueenRange(vector<vector<int>>& vec, int row, int column)
{
	for (int i = 0; i < vec.size(); i++)	//가로
	{
		if (i == column) continue;			//본인 제외

		if (vec[row][i] == 0) vec[row][i] = -1;
	}

	for (int i = 0; i < vec.size(); i++)	//세로
	{
		if (i == row) continue;				//본인제외

		if(vec[i][column] == 0) vec[i][column] = -1;
	}

	for (int i = 1; i < vec.size(); i++)	//왼위대각선
	{
		int index_row = row - i;
		int index_column = column - i;

		if (index_row >= vec.size() || index_column >= vec.size() 
			|| index_row < 0 || index_column < 0) break;

		if (vec[index_row][index_column] == 0) vec[index_row][index_column] = -1;
	}

	for (int i = 1; i < vec.size(); i++)	//아래오른대각선
	{
		int index_row = row + i;
		int index_column = column + i;

		if (index_row >= vec.size() || index_column >= vec.size()
			|| index_row < 0 || index_column < 0) break;

		if (vec[index_row][index_column] == 0) vec[index_row][index_column] = -1;
	}

	for (int i = 1; i < vec.size(); i++)	//오른위대각선
	{
		int index_row = row + i;
		int index_column = column - i;

		if (index_row >= vec.size() || index_column >= vec.size()
			|| index_row < 0 || index_column < 0) break;

		if (vec[index_row][index_column] == 0) vec[index_row][index_column] = -1;
	}

	for (int i = 1; i < vec.size(); i++)	//왼아래대각선
	{
		int index_row = row - i;
		int index_column = column + i;

		if (index_row >= vec.size() || index_column >= vec.size()
			|| index_row < 0 || index_column < 0) break;

		if (vec[index_row][index_column] == 0) vec[index_row][index_column] = -1;
	}
}

void CheckQueen(vector<vector<int>> vec, int count, int row, int column, int& result)
{
	if (count == vec.size())
	{
		++result;
		return;
	}

	int next_count = count + 1;

	for (int i = row; i < vec.size(); i++)
	{
		for (int j = column; j < vec.size(); j++)
		{
			if (vec[i][j] == 0)
			{
				vec[i][j] = 1;
				CheckQueenRange(vec, i, j);
				CheckQueen(vec, next_count, i, j, result);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int result = 0;
	int n;
	cin >> n;

	vector<vector<int>> vec(n, vector<int>(n));

	CheckQueen(vec, 0, 0, 0, result);

	cout << result;

	return 0;
}