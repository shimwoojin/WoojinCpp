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
	int count = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int k;
		bool CheckPrime = true;
		cin >> k;

		if (k == 1) continue;

		for (int i = 2; i < k; i++)
		{
			if (k % i == 0) CheckPrime &= false;
		}

		if (CheckPrime == true) ++count;
	}

	cout << count;


	return 0;
}