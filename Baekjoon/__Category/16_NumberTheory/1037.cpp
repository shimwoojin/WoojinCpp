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

	int result = 0;
	vector<int> vec;
	int n;
	cin >> n;
	int min = 0, max = 0;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		vec.push_back(a);
	}

	min = vec[0];
	max = vec[0];

	if (n != 1)
	{
		for (auto ele : vec)
		{
			min = std::min(min, ele);
			max = std::max(max, ele);
		}

		result = min * max;
	}
	else result = vec[0] * vec[0];

	cout << result;


	return 0;
}