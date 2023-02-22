#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int count = 0;
	unsigned long long h;
	int a, b, c;
	int da, db, dc;
	cin >> h >> a >> b >> c;

	da = h / a + 1;
	db = h / b + 1;
	dc = h / c + 1;

	for (int i = 0; i < da; i++)
	{
		for (int j = 0; j < db; j++)
		{
			for (int k = 0; k < dc; k++)
			{
				int sum = a * i + b * j + c * k;

				if (sum < h)
				{
					++count;
				}
			}
		}
	}


	cout << count << endl;

	return 0;
}