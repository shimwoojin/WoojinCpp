#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int num[10001] = { 0 };
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		++num[a];
	}

	for (int i = 1; i < 10001; i++)
	{
		for (int j = 0; j < num[i]; j++)
		{
			cout << i << "\n";
		}
	}

	return 0;
}