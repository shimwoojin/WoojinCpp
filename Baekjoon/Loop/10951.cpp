#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;

	while(!(cin >> a>>b).eof())
	{
		cout << a + b << endl;
	}

	return 0;
}