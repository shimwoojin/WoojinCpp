#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;

bool IsInCircle(int x1, int y1, int cx, int cy, int r)
{
	int range = sqrt(pow(x1 - cx, 2) + pow(y1 - cy, 2));

	return range < r;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	struct Planet
	{
		int x;
		int y;
		int r;
	};

	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		vector<Planet> planet;
		int count = 0;
		
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int n;
		cin >> n;

		for (int j = 0; j < n; j++)
		{
			Planet c;
			cin >> c.x >> c.y >> c.r;

			planet.push_back(c);
		}

		for (int i = 0; i < planet.size(); i++)
		{
			if (IsInCircle(x1, y1, planet[i].x, planet[i].y, planet[i].r) == true
				&&
				IsInCircle(x2, y2, planet[i].x, planet[i].y, planet[i].r) == false)
			{
				++count;
			}
			else if (IsInCircle(x2, y2, planet[i].x, planet[i].y, planet[i].r) == true
				&&
				IsInCircle(x1, y1, planet[i].x, planet[i].y, planet[i].r) == false)
			{
				++count;
			}
		}

		cout << count << "\n";
	}




	return 0;
}