#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	cin >> num;

	for (int i = 1; i <= num; i++)
	{
		int a, b;
		cin >> a >> b;

		cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << "\n";
	}

	return 0;
}