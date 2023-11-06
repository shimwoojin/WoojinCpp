#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;

	string str;
	cin >> str;

	bool FirstB = false;
	int Count1 = 0;

	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (FirstB)
		{
			if (str[i] == 'R')
			{
				++Count1;
			}
		}
		else
		{
			if (str[i] == 'B')
			{
				FirstB = true;
			}
		}
	}

	bool FirstR = false;
	int Count2 = 0;

	for (int i = str.size() - 1; i >= 0; i--)
	{
		if (FirstR)
		{
			if (str[i] == 'B')
			{
				++Count2;
			}
		}
		else
		{
			if (str[i] == 'R')
			{
				FirstR = true;
			}
		}
	}

	bool FirstB2 = false;
	int Count3 = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (FirstB2)
		{
			if (str[i] == 'R')
			{
				++Count3;
			}
		}
		else
		{
			if (str[i] == 'B')
			{
				FirstB2 = true;
			}
		}
	}

	bool FirstR2 = false;
	int Count4 = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if (FirstR2)
		{
			if (str[i] == 'B')
			{
				++Count4;
			}
		}
		else
		{
			if (str[i] == 'R')
			{
				FirstR2 = true;
			}
		}
	}

	cout << min(min(Count1, Count2), min(Count3, Count4));

	return 0;
}