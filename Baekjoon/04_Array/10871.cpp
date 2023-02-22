#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, x;

	cin >> n >> x;

	int* ia = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		cin >> ia[i];
		if (ia[i] < x) cout << ia[i] << " ";
	}

	return 0;
}