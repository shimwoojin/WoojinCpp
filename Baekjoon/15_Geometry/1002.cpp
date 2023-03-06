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

int CalculateMarinePos(int x1, int y1, int x2, int y2, int r1, int r2)
{
	int xy_distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x1, y1, x2, y2, r1, r2;
		cin >> x1 >> y1 >> x2 >> y2 >> r1 >> r2;

		cout << CalculateMarinePos(x1, y1, x2, y2, r1, r2) << "\n";
	}

	return 0;
}