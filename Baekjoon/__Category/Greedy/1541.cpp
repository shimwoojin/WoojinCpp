#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int Result = 0;
	vector<int> Numbers;
	int Number = 0;
	string Expression;
	cin >> Expression;
	string Temp;

	for (int i = 0; i < Expression.size(); i++)
	{
		if (Expression[0] == '-') { Temp.push_back(Expression[0]); continue; }

		if (Expression[i] == '+')
		{
			Number += stoi(Temp);

			Temp.clear();
		}
		else if (Expression[i] == '-')
		{
			Number += stoi(Temp);
			Numbers.push_back(Number);
			Number = 0;

			Temp.clear();
		}
		else
		{
			Temp.push_back(Expression[i]);
		}

		if (i == Expression.size() - 1)
		{
			Number += stoi(Temp);
			Numbers.push_back(Number);
		}
	}

	for (int i = 0; i < Numbers.size(); i++)
	{
		if (i == 0)
		{
			Result += Numbers[i];
		}
		else
		{
			Result -= Numbers[i];
		}
	}

	cout << Result;

	return 0;
}