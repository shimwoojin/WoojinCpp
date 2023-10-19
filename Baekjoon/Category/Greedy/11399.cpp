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
	vector<int> Line;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int Temp;
		cin >> Temp;
		Line.push_back(Temp);
	}

	sort(Line.begin(), Line.end());

	int Result = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			Result += Line[j];
		}
	}

	cout << Result;

	return 0;
}