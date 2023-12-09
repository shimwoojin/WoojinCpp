#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, b;
	int max = 0;
	int min = 256;
	cin >> n >> m >> b;

	vector<int> vec(n * m, 0);
	vector<pair<int, int>> results;

	for (int i = 0; i < n * m; i++)
	{
		cin >> vec[i];

		max = std::max(max, vec[i]);
		min = std::min(min, vec[i]);
	}

	sort(vec.rbegin(), vec.rend());

	for (int i = max; i >= min; i--)
	{
		int height = i;
		int blocks = b;
		int time = 0;
		int bSuccess = true;

		for (int v : vec)
		{
			if (v > height)
			{
				time += ((v - height) * 2);
				blocks += (v - height);
			}
			else if(v == height)
			{
				continue;
			}
			else
			{
				int need_block = height - v;
				
				if (blocks >= need_block)
				{
					blocks -= need_block;
					time += need_block;
				}
				else
				{
					bSuccess = false;
					break;
				}
			}
		}

		if (bSuccess)
		{
			results.push_back(make_pair(time, height));
		}
	}

	sort(results.begin(), results.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.first < b.first)
		{
			return true;
		}
		else if (a.first == b.first)
		{
			if (a.second < b.second)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
		});

	cout << results[0].first << " " << results[0].second;

	return 0;
}