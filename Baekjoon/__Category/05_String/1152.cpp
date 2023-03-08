#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s;
	getline(cin, s);

	int count = 0;
	int voca_count = 0;

	for (int i = 0; i < s.size() + 1; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')
		{
			++count;
		}
		else if (count != 0 && s[i] == ' ' || count != 0 && s[i] == '\0')
		{
			voca_count++;
			count = 0;
		}
	}

	cout << voca_count;

	return 0;
}