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

	int x, y, w, h;
	cin >> x >> y >> w >> h;

	int result = min(min(abs(x - w), abs(y - h)), min(abs(x), abs(y)));

	cout << result;


	return 0;
}