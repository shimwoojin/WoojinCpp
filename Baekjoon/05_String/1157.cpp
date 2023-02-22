#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;

	int arr[26];

	for (int i = 0; i < 26; i++)
	{
		arr[i] = -1;
	}

	for (int i = 0; i < s.size(); i++)
	{
		if ((int)s[i] - 97 < 0)	//´ë¹®ÀÚ
		{
			arr[(int)s[i] - 65] += 1;
		}
		else
		{
			arr[(int)s[i] - 97] += 1;
		}
	}

	int max = 0;
	int count = 0;
	int index = 0;

	for (int i = 0; i < 26; i++)
	{
		if (max <= arr[i])
		{
			max = arr[i];
			index = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (max == arr[i]) count++;
	}

	if (count == 1)
	{
		cout << (char)(index + 65);
	}
	else
		cout << "?";

	return 0;
}