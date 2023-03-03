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

	int x = 0, y = 0;

	if (x_[0] == x_[1]) x = x_[2];
	if (x_[0] == x_[2]) x = x_[1];
	if (x_[2] == x_[1]) x = x_[0];

	if (y_[0] == y_[1]) y = y_[2];
	if (y_[0] == y_[2]) y = y_[1];
	if (y_[2] == y_[1]) y = y_[0];

	cout << x << " " << y;


	return 0;
}