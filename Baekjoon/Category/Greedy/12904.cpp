#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <string>

using namespace std;

string s1, s2;

int Solution()
{
	while (s1.size() < s2.size())
	{
		if (s2.back() == 'B')
		{
			s2.pop_back();
			s2 = string(s2.rbegin(), s2.rend());
		}
		else
		{
			s2.pop_back();
		}
	}

	return s1 == s2;
}

int main()
{
	cin >> s1 >> s2;

	cout << Solution();

	return 0;
}