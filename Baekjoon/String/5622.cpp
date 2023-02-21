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

	int count = 2 * s.size();

	for (int i = 0; i < s.size(); i++)
	{
		if ((int)s[i] >= 65 && (int)s[i] < 68) count += 1;
		else if ((int)s[i] >= 68 && (int)s[i] < 71) count += 2;
		else if ((int)s[i] >= 71 && (int)s[i] < 74) count += 3;
		else if ((int)s[i] >= 74 && (int)s[i] < 77) count += 4;
		else if ((int)s[i] >= 77 && (int)s[i] < 80) count += 5;
		else if ((int)s[i] >= 80 && (int)s[i] < 84) count += 6;
		else if ((int)s[i] >= 84 && (int)s[i] < 87) count += 7;
		else if ((int)s[i] >= 87 && (int)s[i] < 91) count += 8;
	}

	cout << count << "\n";

	return 0;
}