#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int Fibonacci(int first, int second, int n)
{
	if (n == 0) return 0;

	if (n > 1)
	{
		int result = first + Fibonacci(second, first + second, --n);
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

	cout << Fibonacci(0, 1, n);

	return 0;
}