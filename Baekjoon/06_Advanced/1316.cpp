#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int count = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		int alphabet[26] = { 0 };

		for (int i = 0; i < str.size(); i++)
		{
			if (i == 0)
			{
				++alphabet[(int)str[i] - 97];
			}
			else
			{
				if (str[i - 1] != str[i])
				{
					++alphabet[(int)str[i] - 97];
				}
			}
		}

		bool IsGroupAlpha = true;
		for (int i = 0; i < 26; i++)
		{
			if (alphabet[i] > 1) IsGroupAlpha = false;
		}

		if (IsGroupAlpha == true) ++count;
	}

	cout << count;

	return 0;
}