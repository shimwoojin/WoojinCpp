#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> vec;
	int arr[42] = { 0 };
	int count = 0;

	for (int i = 0; i < 10; i++)
	{
		int a;
		cin >> a;
		a %= 42;
		vec.push_back(a);
	}

	for (int i = 0; i < 10; i++)
	{
		arr[vec[i]] += 1;
	}


	for (int i = 0; i < 42; i++)
	{
		if (arr[i] != 0) ++count;
	}
	
	cout << count << endl;

	return 0;
}