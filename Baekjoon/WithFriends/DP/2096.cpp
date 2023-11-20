#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//start: 18:42
	//end: 19:16

	int N;
	cin >> N;
	int a, b, c;
	cin >> a >> b >> c;

	int dp_max[3] = { a,b,c };
	int dp_min[3] = { a,b,c };

	for (int i = 1; i < N; i++)
	{
		cin >> a >> b >> c;

		int max1 = dp_max[0];
		int max2 = dp_max[1];
		int max3 = dp_max[2];
		int min1 = dp_min[0];
		int min2 = dp_min[1];
		int min3 = dp_min[2];

		dp_max[0] = max(max1, max2) + a;
		dp_max[1] = max(max(max1, max2), max3) + b;
		dp_max[2] = max(max2, max3) + c;

		dp_min[0] = min(min1, min2) + a;
		dp_min[1] = min(min(min1, min2), min3) + b;
		dp_min[2] = min(min2, min3) + c;
	}

	cout << max(max(dp_max[0], dp_max[1]), dp_max[2]) << " " << min(min(dp_min[0], dp_min[1]), dp_min[2]);

	return 0;
}