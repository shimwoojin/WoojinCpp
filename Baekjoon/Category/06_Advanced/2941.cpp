#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	int count = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == 'c')
		{
			if (i != str.size() - 1 && str[i + 1] == '=')
			{
				++count;
				++i;
			}
			else if (i != str.size() - 1 && str[i + 1] == '-')
			{
				++count;
				++i;
			}
			else ++count;
		}
		else if (str[i] == 'd')
		{
			if (i != str.size() - 1 && str[i + 1] == '-')
			{
				++count;
				++i;
			}
			else if (i < str.size() - 2 && str[i + 1] == 'z' && str[i + 2] == '=')
			{
				++count;
				i += 2;
			}
			else ++count;
		}
		else if (str[i] == 'l')
		{
			if (i != str.size() - 1 && str[i + 1] == 'j')
			{
				++count;
				++i;
			}
			else ++count;
		}
		else if (str[i] == 'n')
		{
			if (i != str.size() - 1 && str[i + 1] == 'j')
			{
				++count;
				++i;
			}
			else ++count;
		}
		else if (str[i] == 's')
		{
			if (i != str.size() - 1 && str[i + 1] == '=')
			{
				++count;
				++i;
			}
			else ++count;
		}
		else if (str[i] == 'z')
		{
			if (i != str.size() - 1 && str[i + 1] == '=')
			{
				++count;
				++i;
			}
			else ++count;
		}
		else ++count;
	}

	cout << count;

	return 0;
}