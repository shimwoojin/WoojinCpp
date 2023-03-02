#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> vec;
	vector<int> sum;
	int min = 0, proper = 0;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		vec.push_back(a);
	}

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				int sum_ = vec[i] + vec[j] + vec[k];

				if (sum_ <= m) 
					sum.push_back(sum_);
			}
		}
	}

	sort(sum.begin(), sum.end());
	sum.erase(unique(sum.begin(), sum.end()), sum.end());

	cout << sum[sum.size() - 1];

	return 0;
}