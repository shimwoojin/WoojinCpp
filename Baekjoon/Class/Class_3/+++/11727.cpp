#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n + 1, 0);
	
	vec[1] = 1;
	vec[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		vec[i] = vec[i - 1] + 2*vec[i - 2];
		vec[i] %= 10007;
	}

	cout << vec[n];

	return 0;
}