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

	int n;
	cin >> n;

	int first;
	cin >> first;
	vector<int> vec;

	for (int i = 2; i <= first; i++)
	{
		if (first % i == 0) vec.push_back(i);
	}

	for (int i = 0; i < n - 1; i++)
	{
		int least = 1;
		int a;
		cin >> a;

		for (auto ele : vec)
		{
			if (a % ele == 0) least = ele;
		}

		cout << first / least << "/" << a / least << "\n";
	}


	return 0;
}