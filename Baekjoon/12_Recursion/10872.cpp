#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int Factorial(int n)
{
	if (n >= 1)
	{
		int result = n * Factorial(n - 1);
		return result;
	}
	else return 1;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	cout << Factorial(n);


	return 0;
}