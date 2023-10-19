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
	
	for (int i = 0; i < n; i++)
	{
		int h, w, m;
		cin >> h >> w >> m;

		int yy = 0;
		int xx = 0;

		if (m % h == 0)
		{
			yy = h;
			xx = m / h;
		}
		else
		{
			yy = m % h;
			xx = m / h + 1;
		}

		cout << yy * 100 + xx;

		if (i != n - 1) cout << "\n";
	}

	return 0;
}