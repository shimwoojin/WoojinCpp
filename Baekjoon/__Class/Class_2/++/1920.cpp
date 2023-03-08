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

	int n;
	set<int> set;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		set.insert(a);
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		
		if (set.find(a) != set.end()) cout << 1 << "\n";
		else cout << 0 << "\n";
	}

	return 0;
}