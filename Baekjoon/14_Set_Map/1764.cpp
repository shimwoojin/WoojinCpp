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

	multiset<string> name;
	vector<string> vec;

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		name.insert(str);
	}

	for (int i = 0; i < m; i++)
	{
		string str;
		cin >> str;

		name.insert(str);
	}

	int count = 0;

	for (auto iter = name.begin(); iter != name.end(); iter++)
	{
		if (name.count(*iter) == 2)
		{
			vec.push_back(*iter);
			++count;
			++iter;
		}
	}

	cout << count << "\n";

	for (auto ele : vec)
	{
		cout << ele << "\n";
	}


	return 0;
}