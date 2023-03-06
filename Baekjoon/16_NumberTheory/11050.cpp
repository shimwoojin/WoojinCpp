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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	int result1 = 1;
	int result2 = 1;

	for (int i = 0; i < k; i++)
	{
		result1 *= (n - i);
		result2 *= (i + 1);
	}

	cout << result1 / result2;


	return 0;
}