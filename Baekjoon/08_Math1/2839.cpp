#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	if (n >= 12)
	{
		if (n % 5 == 1)
		{
			cout << n / 5 + 1;
		}
		else if (n % 5 == 2)
		{
			cout << n / 5 + 2;
		}
		else if (n % 5 == 3)
		{
			cout << n / 5 + 1;
		}
		else if (n % 5 == 4)
		{
			cout << n / 5 + 2;
		}
		else if (n % 5 == 0)
		{
			cout << n / 5;
		}
	}
	else
	{
		if (n == 3)
		{
			cout << 1;
		}
		else if (n == 4)
		{
			cout << -1;
		}
		else if (n == 5)
		{
			cout << 1;
		}
		else if (n == 6)
		{
			cout << 2;
		}
		else if (n == 7)
		{
			cout << -1;
		}
		else if (n == 8)
		{
			cout << 2;
		}
		else if (n == 9)
		{
			cout << 3;
		}
		else if (n == 10)
		{
			cout << 2;
		}
		else if (n == 11)
		{
			cout << 3;
		}
	}


	return 0;
}