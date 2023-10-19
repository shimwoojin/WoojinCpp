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

void QuadTree(const vector<string>& InputVec, string& OutputString, int x, int y, int N)
{
	int TempCount = 0;

	for (int i = x; i < x + N; i++)
	{
		for (int j = y; j < y + N; j++)
		{
			if (InputVec[i][j] == '1')
			{
				++TempCount;
			}
		}
	}

	if (TempCount == N * N) OutputString += '1';
	else if (TempCount == 0) OutputString += '0';
	else
	{
		OutputString += '(';

		QuadTree(InputVec, OutputString, x, y, N / 2);
		QuadTree(InputVec, OutputString, x, y + N / 2, N / 2);
		QuadTree(InputVec, OutputString, x + N / 2, y, N / 2);
		QuadTree(InputVec, OutputString, x + N / 2, y + N / 2, N / 2);

		OutputString += ')';
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;

	vector<string> Vec;
	Vec.assign(num, string());

	for (int i = 0; i < num; i++)
	{
		string Temp;
		cin >> Temp;
		Vec[i] = Temp;
	}

	string Result;

	QuadTree(Vec, Result, 0, 0, num);

	cout << Result;

	return 0;
}