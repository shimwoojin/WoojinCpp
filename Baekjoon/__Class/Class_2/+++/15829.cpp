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
	cin >> n;

	string str;
	cin >> str;

	ll result = 0;

	for (int i = 0; i < n; i++)
	{
		result += ((ll)str[i] - 96) * pow(31, i);
	}

	cout << result;


	return 0;
}