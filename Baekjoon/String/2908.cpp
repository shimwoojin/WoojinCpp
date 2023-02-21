#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s1, s2;

	cin >> s1 >> s2;

	int a, b;

	a = ((int)s1[2] - 48) * 100 + ((int)s1[1] - 48) * 10 + ((int)s1[0] - 48) * 1;
	b = ((int)s2[2] - 48) * 100 + ((int)s2[1] - 48) * 10 + ((int)s2[0] - 48) * 1;

	int c = a > b ? a : b;

	cout << c;

	return 0;
}