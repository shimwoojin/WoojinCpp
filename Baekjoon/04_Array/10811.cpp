#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> vec;
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		vec.push_back(i + 1);
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		--a; --b;
		int temp_a = a;

		auto temp_vec = vec;

		for (int j = a; j <= b; j++)
		{
			int temp = j - temp_a;
			vec[j] = temp_vec[b - temp];
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << vec[i] << " ";
	}

	return 0;
}