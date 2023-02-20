#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	int sum = 0;
	for (int i = 0; i < b; i++)
	{
		int c, d;
		cin >> c >> d;
		sum += c * d;
	}

	if (a == sum) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}