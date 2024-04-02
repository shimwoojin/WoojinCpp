#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	int x1, y1, r1, x2, y2, r2;
	cin >> t;

	while (t--)
	{
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double distance = sqrt(pow((double)x1 - x2, 2) + pow((double)y1 - y2, 2));

		if (distance > 0)
		{
			if (r1 + r2 > distance)
			{
				if (abs(r1 - r2) == distance)
				{
					cout << 1 << '\n';
				}
				else if (abs(r1 - r2) > distance)
				{
					cout << 0 << '\n';
				}
				else
				{
					cout << 2 << '\n';
				}
			}
			else if (r1 + r2 == distance)
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else
		{
			if (r1 == r2)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
	}


	return 0;
}