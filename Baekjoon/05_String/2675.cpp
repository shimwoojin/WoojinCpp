#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int n;
		string s;
		cin >> n >> s;

		for (int j = 0; j < s.size(); j++)
		{
			for (int k = 0; k < n; k++)
			{
				cout << s[j];
			}
		}
		cout << endl;
	}


	return 0;
}