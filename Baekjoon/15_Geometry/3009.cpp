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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int x_[3], y_[3];

	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y;

		x_[i] = x;
		y_[i] = y;
	}

	int vec_x1 = x_[1] - x_[0];
	int vec_y1 = y_[1] - y_[0];
	
	int vec_x2 = x_[2] - x_[0];
	int vec_y2 = y_[2] - y_[0];

	cout << x_[1] + vec_x2 << " " << y_[1] + vec_y2;

	return 0;
}