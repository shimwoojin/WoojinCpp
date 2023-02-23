#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, v;
	cin >> a >> b >> v;

	int top = v - a;
	int one_day = a - b;

	if (a == v) cout << "1";
	else if (top % one_day == 0) cout << top / one_day + 1;
	else cout << top / one_day + 2;

	return 0;
}