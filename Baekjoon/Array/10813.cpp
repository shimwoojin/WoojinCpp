#include <iostream>
using namespace std;

void swap(int* a, int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int* pa = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		pa[i] = i + 1;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;

		cin >> a >> b;

		swap(pa[a - 1], pa[b - 1]);
	}

	for (int i = 0; i < n; i++)
	{
		cout << pa[i];
		if (i != n - 1) cout << " ";
	}


	free(pa);

	return 0;
}