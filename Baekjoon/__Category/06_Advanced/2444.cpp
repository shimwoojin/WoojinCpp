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

	for (int i = 1; i <= 2 * n - 1; i++)
	{
		for (int j = 1; j <= 2 * n - 1; j++)
		{
			if (j <= abs(n - i)) cout << " ";
			else if (j >= 2 * n - abs(n - i)) continue;
			else cout << "*";
		}
		if(i != 2 * n - 1)
			cout << "\n";
	}


	return 0;
}