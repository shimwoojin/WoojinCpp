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

	int least = 1, most = 1;
	vector<int> vec;
	int n1, n2;
	cin >> n1 >> n2;

	for (int i = 2; i <= n1; i++)
	{
		if (n1 % i == 0)
		{
			vec.push_back(i);
		}
	}

	for (auto ele : vec)
	{
		if (n2 % ele == 0) least = ele;
	}

	most = least * (n1 / least) * (n2 / least);

	cout << least << "\n" << most;

	return 0;
}