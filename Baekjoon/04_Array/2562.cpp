#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int arr[9] = { 0 };

	int max = 0, count = 0;

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];

		if (arr[i] > max)
		{
			max = arr[i];
			count = i + 1;
		}
	}

	cout << max << '\n' << count;


	return 0;
}