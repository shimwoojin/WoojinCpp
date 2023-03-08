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

bool isNumber(const string& str)
{
	for (char const& c : str) {
		if (std::isdigit(c) == 0) return false;
	}
	return true;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	map<int, string> map_string;
	map<string, int> map_int;
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		string str;
		cin >> str;

		map_string[i] = str;
		map_int[str] = i;
	}

	for (int i = 1; i <= m; i++)
	{
		string str;
		cin >> str;

		if (isNumber(str) == true)
		{
			double number = atoi(str.c_str());
			auto iter = map_string.find(number);

			cout << (*iter).second << "\n";
		}
		else
		{
			auto iter = map_int.find(str);

			cout << (*iter).second << "\n";
		}

	}


	return 0;
}