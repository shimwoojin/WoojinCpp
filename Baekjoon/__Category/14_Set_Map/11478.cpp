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

	set<string> s;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		string temp;

		for (int j = i; j < str.size(); j++)
		{
			temp += str[j];

			s.insert(temp);
		}
	}

	cout << s.size();

	return 0;
}