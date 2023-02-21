#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	int arr[26];

	for (int i = 0; i < 26; i++)
	{
		arr[i] = -1;
	}

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (arr[(int)s[i] - 97] == -1) 
		{
			arr[(int)s[i] - 97] = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << arr[i] << " ";
	}


	return 0;
}