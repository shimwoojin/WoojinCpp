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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<vector<int>> Piramid(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int Number;
			cin >> Number;
			Piramid[i].push_back(Number);
		}
	}

	for (int i = N - 1; i >= 1; i--)
	{
		for (int j = 0; j < i; j++)
		{
			Piramid[i - 1][j] += max(Piramid[i][j], Piramid[i][j + 1]);
		}
	}

	cout << Piramid[0][0];

	return 0;
}