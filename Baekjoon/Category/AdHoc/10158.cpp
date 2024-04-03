#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int w, h;
	int p, q;
	int t;
	cin >> w >> h >> p >> q >> t;
	
	int x, y;
	int dir_x = 1, dir_y = 1;
	
	int try_x = t % (w * 2);
	int try_y = t % (h * 2);
	
	while (try_x--)
	{
		if (p == w) dir_x = -1;
		else if (p == 0) dir_x = 1;

		p += dir_x;
	}

	while (try_y--)
	{
		if (q == h) dir_y = -1;
		else if (q == 0) dir_y = 1;

		q += dir_y;
	}

	x = p; y = q;

	cout << x << ' ' << y;


	return 0;
}