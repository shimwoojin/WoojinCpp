#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int ia[100] = { 0 };
	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> ia[i];
	}

	int num2;
	cin >> num2;

	int count = 0;

	for (int i = 0; i < num; i++)
	{
		if (ia[i] == num2) ++count;
	}

	cout << count << "\n";

	return 0;
}