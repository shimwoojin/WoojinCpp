#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a;
	cin >> a;

	int* pa = (int*)malloc(sizeof(int) * a);

	int min, max;
	for (int i = 0; i < a; i++)
	{
		cin >> pa[i];

		if (i == 0)
		{
			min = pa[0];
			max = pa[0];
		}

		if (min > pa[i]) min = pa[i];
		if (max < pa[i]) max = pa[i];
	}
	cout << min << " " << max << endl;


	free(pa);

	return 0;
}