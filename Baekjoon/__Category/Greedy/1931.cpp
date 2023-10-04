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

	int N, Begin, End;
	vector<pair<int, int>> Schedule;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> Begin >> End;
		Schedule.push_back(make_pair(End, Begin));
	}

	sort(Schedule.begin(), Schedule.end());

	int Time = Schedule[0].first;
	int Count = 1;
	for (int i = 1; i < N; i++)
	{
		if (Time <= Schedule[i].second)
		{
			Count++;
			Time = Schedule[i].first;
		}
	}

	cout << Count;

	return 0;
}