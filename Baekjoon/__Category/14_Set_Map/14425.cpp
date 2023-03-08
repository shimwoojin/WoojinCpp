#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	set<string> set;

	int n, m;
	int count = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		
		set.insert(str);
	}

	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;

		if (set.count(str) == 1)
			++count;
	}

	cout << count;

	return 0;
}