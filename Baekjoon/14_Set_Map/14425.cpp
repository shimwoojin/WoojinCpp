#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	map<int, vector<string>> vec_n;
	int count = 0;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		vec_n[str.size()].push_back(str);
	}

	for (int i = 0; i < m; i++)
	{
		int size;
		string str;
		cin >> str;

		size = str.size();

		for (int i = 0; i < vec_n[size].size(); i++)
		{
			if (vec_n[size][i] == str)
			{
				++count;
				break;
			}
		}
	}

	cout << count;


	return 0;
}