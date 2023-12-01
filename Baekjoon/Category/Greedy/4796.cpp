#include <iostream>
using namespace std;

int main()
{
	int count = 0;

	while (true)
	{
		++count;

		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}

		int answer = 0;
		int quotient = c / b;
		int remainder = c % b;

		if (remainder >= a)
		{
			answer = quotient * a + a;
		}
		else
		{
			answer = quotient * a + remainder;
		}

		cout << "Case " << count << ": " << answer << endl;
	}

	return 0;
}