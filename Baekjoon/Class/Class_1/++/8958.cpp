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
		string str;
		cin >> str;

		int add_num = 0;
		int result = 0;

		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == 'O')
			{
				++add_num;
			}
			else
			{
				add_num = 0;
			}

			result += add_num;
		}

		cout << result << "\n";
	}






	return 0;
}