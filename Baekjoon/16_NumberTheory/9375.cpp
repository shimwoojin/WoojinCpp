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

	for (int i = 0; i < n; i++)
	{
		map<string, vector<string>> fashion;
		set<string> type;
		int m;
		cin >> m;

		for (int j = 0; j < m; j++)
		{
			string name, category;
			cin >> name >> category;

			type.insert(category);
			fashion[category].push_back(name);
		}


	}




	return 0;
}