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

	ll result = 0;
	ll numbers[3] = {0};

	for (int i = 0; i < 3; i++)
	{
		ll a;
		cin >> a;

		numbers[i] = a;
	}

	result = numbers[0] * numbers[1] * numbers[2];

	string str = to_string(result);

	int num_count[10]{0};

	for (int i = 0; i < str.size(); i++)
	{
		num_count[str[i] - '0']++;
	}

	for (auto ele : num_count)
	{
		cout << ele << "\n";
	}

	return 0;
}