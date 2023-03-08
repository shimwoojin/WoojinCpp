#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<string> vec_str;
	string temp;
	string result;

	vec_str.reserve(5);

	for (int i = 0; i < 5; i++)
	{
		getline(cin, temp);
		vec_str.push_back(temp);
	}

	for (int i = 0; i < 15; i++)
	{
		if (i < vec_str[0].size())
		{
			result += vec_str[0][i];
		}
		if (i < vec_str[1].size())
		{
			result += vec_str[1][i];
		}
		if (i < vec_str[2].size())
		{
			result += vec_str[2][i];
		}
		if (i < vec_str[3].size())
		{
			result += vec_str[3][i];
		}
		if (i < vec_str[4].size())
		{
			result += vec_str[4][i];
		}
	}

	cout << result;

	return 0;
}