#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> difficulties(n);

	if (n == 0)
	{
		cout << 0;
		return 0;
	}

	double cut = n * 0.15;
	int cut1 = cut;
	int cut2 = cut + 1;
	if (abs(cut1 - cut) >= abs(cut2 - cut))
	{
		cut = cut2;
	}
	else
	{
		cut = cut1;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> difficulties[i];
	}

	sort(difficulties.begin(), difficulties.end());

	int accum = accumulate(difficulties.begin() + cut, difficulties.end() - cut, 0);

	double average = accum / (n - cut * 2);
	int average1 = average;
	int average2 = average + 1;
	if (abs(average1 - average) >= abs(average2 - average))
	{
		average = average2;
	}
	else
	{
		average = average1;
	}

	cout << (int)average;

	return 0;
}