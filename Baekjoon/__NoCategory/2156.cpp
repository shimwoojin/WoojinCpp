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
	vector<int> Wines(N + 3, 0);
	vector<int> Result(N + 3, 0);

	for (int i = 3; i < N + 3; i++)
	{
		cin >> Wines[i];
	}

	for (int i = 3; i < Wines.size(); i++)
	{
		int I_WineDrinking = max(Result[i - 3] + Wines[i - 1] + Wines[i], Result[i - 2] + Wines[i]);
		int I_WineNotDrinking = Result[i - 1];
		Result[i] = max(I_WineDrinking, I_WineNotDrinking);
	}

	cout << Result[Wines.size() - 1];

	return 0;
}