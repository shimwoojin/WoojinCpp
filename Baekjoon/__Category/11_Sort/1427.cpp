#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;

bool compare(char a, char b)
{
	return a > b;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	cin >> str;

	sort(str.begin(), str.end(), compare);

	cout << str;

	return 0;
}