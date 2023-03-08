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

typedef long long ll;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	ll n, m;
	vector<ll> vec;
	cin >> n >> m;

	ll max = 0;

	for (ll i = 0; i < n; i++)
	{
		ll a;
		cin >> a;

		vec.push_back(a);
		max = std::max(max, a);
	}

	ll min = 1;
	ll mid = 0;
	ll result = 0;

	while (min <= max)
	{
		mid = (min + max) / 2;

		ll sum = 0;

		for (ll i = 0; i < n; i++)
		{
			if (vec[i] > mid) sum += (vec[i] - mid);
		}

		if (sum >= m)
		{
			min = mid + 1;
			if(result < mid) result = mid;
		}
		else
		{
			max = mid - 1;
		}
	}

	cout << result;

	return 0;
}