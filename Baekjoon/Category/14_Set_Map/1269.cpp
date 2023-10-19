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

bool set_a[100000001];
bool set_b[100000001];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int count = 0;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		set_a[++a] = true;
	}

	for (int i = 0; i < m; i++)
	{
		int b;
		cin >> b;

		set_b[++b] = true;
	}

	for (int i = 0; i < 100000000; i++)
	{
		if (set_a[i] == true && set_b[i] == true) ++count;
	}

	cout << n + m - 2 * count;

	return 0;
}