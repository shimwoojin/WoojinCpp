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

	vector<int> vec;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;

		vec.push_back(a);
	}

	int min = vec[0];
	int max = vec[0];

	for (auto ele : vec)
	{
		min = std::min(min, ele);
		max = std::max(max, ele);
	}





	return 0;
}