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

	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		int a;
		cin >> a;

		sum += pow(a, 2);
	}

	cout << sum % 10;

	return 0;
}