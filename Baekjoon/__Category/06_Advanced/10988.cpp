#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string str;
	string temp;
	cin >> str;

	temp = str;
	
	for (int i = 0; i < str.size(); i++)
	{
		temp[i] = str[str.size() - 1 - i];
	}

	if (temp == str) cout << "1";
	else cout << "0";

	return 0;
}