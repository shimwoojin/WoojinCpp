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
	int sum = 0;
	cin >> n >> str;
	

	for (int i = 0; i < n; i++)
	{
		sum += (int)str[i] - 48;
	}

	cout << sum;

	return 0;
}