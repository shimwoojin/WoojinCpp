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

	vector<pair<int, int>> vec;
	int n;
	cin >> n;

	vec.push_back(make_pair(0, 1));
	vec.push_back(make_pair(1, 0));

	for (int i = 2; i <= 40; i++)
	{
		int first = vec[i - 2].first + vec[i - 1].first;
		int second = vec[i - 2].second + vec[i - 1].second;

		pair<int, int> p = make_pair(first, second);

		vec.push_back(p);
	}


	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		cout << vec[a].second << " " << vec[a].first << "\n";
	}

	return 0;
}