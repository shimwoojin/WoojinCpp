#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string str;
	cin >> str;

	char standard = str[0];
	int count = 0;
	
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != standard)
		{
			++count;
			standard = str[i];
		}
	}
	
	if (count % 2 == 0)
	{
		cout << count / 2;
	}
	else
	{
		cout << count / 2 + 1;
	}

	return 0;
}