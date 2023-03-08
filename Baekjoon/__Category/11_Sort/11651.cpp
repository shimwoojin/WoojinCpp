#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.second > b.second) return false;
	else if (a.second == b.second)
	{
		if (a.first < b.first) return true;
		else return false;
	}
	else return true;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<pair<int, int>> vec;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;

		vec.push_back(make_pair(x, y));
	}

	sort(vec.begin(), vec.end(), compare);

	for (int i = 0; i < n; i++)
	{
		cout << vec[i].first << " " << vec[i].second << "\n";
	}


	return 0;
}