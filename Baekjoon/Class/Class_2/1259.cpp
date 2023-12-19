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

typedef long long ll;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	while (true)
	{
		string str;
		cin >> str;

		if (str == "0") break;

		bool pelindrome = true;

		for (int i = 0; i < str.size() / 2; i++)
		{
			if (str[i] == str[str.size() - 1 - i]) pelindrome &= true;
			else pelindrome &= false;
		}

		if (pelindrome) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}

	return 0;
}