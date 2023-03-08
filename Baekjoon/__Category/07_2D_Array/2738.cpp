#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> vec1, vec2;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n * m; i++)
	{
		int a;
		cin >> a;
		vec1.push_back(a);
	}

	for (int i = 0; i < n * m; i++)
	{
		int a;
		cin >> a;
		vec2.push_back(a);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << vec1[i * m + j] + vec2[i * m + j] << " ";
		}
		cout << "\n";
	}


	return 0;
}