#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int x;
	cin >> x;

	int i = 0;
	int start_x = x;
	int before_x = 0;

	while (x > 0)
	{
		before_x += i;
		++i;
		x -= i;
	}

	int delta_x = start_x - before_x;

	if (i % 2 == 0)
	{
		cout << delta_x << "/" << i - delta_x + 1 << "\n";
	}
	else
	{
		cout << i - delta_x + 1 << "/" << delta_x << "\n";
	}

	return 0;
}