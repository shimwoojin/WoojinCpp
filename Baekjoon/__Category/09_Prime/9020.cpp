#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int m;
		int half_m;
		bool IsContinue = true;
		cin >> m;

		half_m = m / 2;

		for (int j = half_m; j >= 2; j--)
		{
			if (IsContinue == false) break;

			bool CheckPrime = true;

			for (int k = 2; k < j; k++)
			{
				if (j % k == 0) CheckPrime &= false;
			}

			if (CheckPrime == true)
			{
				int second_num = m - j;
				bool CheckPrime2 = true;

				for (int k = 2; k < second_num; k++)
				{
					if (second_num % k == 0) CheckPrime2 &= false;
				}

				if (CheckPrime2 == true)
				{
					cout << j << " " << second_num << "\n";
					IsContinue = false;
				}

			}
		}
	}




	return 0;
}