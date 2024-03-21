#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<int, bool>> liquid(n, pair<int, bool>());
	int gap = 2'000'000'000;
	int max_a = 0, max_b = 0;

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;

		if (temp < 0)
		{
			liquid[i] = { abs(temp), false };
		}
		else
		{
			liquid[i] = { temp, true };
		}
	}

	sort(liquid.begin(), liquid.end());

	for (int i = 0; i < liquid.size() - 1; i++)
	{
		if (liquid[i + 1].first - liquid[i].first < gap && liquid[i + 1].second != liquid[i].second)
		{
			gap = liquid[i + 1].first - liquid[i].first;
			
			if (liquid[i].second == true)
			{
				max_a = -liquid[i + 1].first;
				max_b = liquid[i].first;
			}
			else
			{
				max_a = -liquid[i].first;
				max_b = liquid[i + 1].first;
			}
		}
		else if (liquid[i + 1].first + liquid[i].first < gap && liquid[i + 1].second == liquid[i].second)
		{
			gap = liquid[i + 1].first + liquid[i].first;
			
			if (liquid[i].second == true)
			{
				max_a = min(liquid[i + 1].first, liquid[i].first);
				max_b = max(liquid[i + 1].first, liquid[i].first);
			}
			else
			{
				max_a = -max(liquid[i + 1].first, liquid[i].first);
				max_b = -min(liquid[i + 1].first, liquid[i].first);
			}
		}
	}

	cout << max_a << ' ' << max_b;

	return 0;
}
