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

	for (int i = 0; i < 8; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}

	if (vec[0] == 1 && vec[1] == 2 && vec[2] == 3 && vec[3] == 4 &&
		vec[4] == 5 && vec[5] == 6 && vec[6] == 7 && vec[7] == 8)
	{
		cout << "ascending";
	}
	else if (vec[0] == 8 && vec[1] == 7 && vec[2] == 6 && vec[3] == 5 &&
		vec[4] == 4 && vec[5] == 3 && vec[6] == 2 && vec[7] == 1)
	{
		cout << "descending";
	}
	else
	{
		cout << "mixed";
	}




	return 0;
}