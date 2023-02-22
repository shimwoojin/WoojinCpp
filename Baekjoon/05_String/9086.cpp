#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		cout << str[0] << str[str.size() - 1] << "\n";
	}

	return 0;
}