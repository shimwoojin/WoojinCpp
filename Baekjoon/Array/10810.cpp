#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	int* pa = (int*)malloc(sizeof(int) * n);

	for (int l = 0; l < n; l++)
	{
		pa[l] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		for (int k = a - 1; k <= b - 1; k++)
		{
			pa[k] = c;
		}
	}

	for(int j = 0; j < n; j++)
	{
		cout << pa[j] << " ";
	}


	free(pa);

	return 0;
}