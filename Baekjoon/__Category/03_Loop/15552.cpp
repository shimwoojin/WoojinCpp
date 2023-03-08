#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << a + b << "\n";
	}

	return 0;
}