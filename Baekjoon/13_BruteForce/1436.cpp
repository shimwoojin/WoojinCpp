#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const string _666 = "666";

void make_4th_666(vector<int>& vec)
{
	for (char i = '0'; i <= '9'; i++)
	{
		string str1 = i + _666;
		string str2 = _666 + i;

		int num = atoi(str1.c_str());
		int num2 = atoi(str2.c_str());

		vec.push_back(num);
		vec.push_back(num2);
	}
}

void make_5th_666(vector<int>& vec)
{
	for (char i = '0'; i <= '9'; i++)
	{
		for (char j = '0'; j <= '9'; j++)
		{
			char ai[] = { i, '\0' };
			char aj[] = { j, '\0' };

			string si = ai;
			string sj = aj;

			string str1 = si + sj + _666;
			string str2 = si + _666 + sj;
			string str3 = _666 + si + sj;
			int num1 = atoi(str1.c_str());
			int num2 = atoi(str2.c_str());
			int num3 = atoi(str3.c_str());

			vec.push_back(num1);
			vec.push_back(num2);
			vec.push_back(num3);
		}
	}
}

void make_6th_666(vector<int>& vec)
{
	for (char i = '0'; i <= '9'; i++)
	{
		for (char j = '0'; j <= '9'; j++)
		{
			for (char k = '0'; k <= '9'; k++)
			{
				char ai[] = { i, '\0' };
				char aj[] = { j, '\0' };
				char ak[] = { k, '\0' };

				string si = ai;
				string sj = aj;
				string sk = ak;

				string str1 = si + sj + sk + _666;
				string str2 = si + sj + _666 + sk;
				string str3 = si + _666 + sj + sk;
				string str4 = _666 + si + sj + sk;
				int num1 = atoi(str1.c_str());
				int num2 = atoi(str2.c_str());
				int num3 = atoi(str3.c_str());
				int num4 = atoi(str4.c_str());

				vec.push_back(num1);
				vec.push_back(num2);
				vec.push_back(num3);
				vec.push_back(num4);
			}
		}
	}
}

void make_7th_666(vector<int>& vec)
{
	for (char i = '0'; i <= '9'; i++)
	{
		for (char j = '0'; j <= '9'; j++)
		{
			for (char k = '0'; k <= '9'; k++)
			{
				for (char l = '0'; l <= '9'; l++)
				{
					char ai[] = { i, '\0' };
					char aj[] = { j, '\0' };
					char ak[] = { k, '\0' };
					char al[] = { l, '\0' };

					string si = ai;
					string sj = aj;
					string sk = ak;
					string sl = al;

					string str1 = sl + si + sj + sk + _666;
					string str2 = sl + si + sj + _666 + sk;
					string str3 = sl + si + _666 + sj + sk;
					string str4 = sl + _666 + si + sj + sk;
					string str5 = _666 + sl + si + sj + sk;

					int num1 = atoi(str1.c_str());
					int num2 = atoi(str2.c_str());
					int num3 = atoi(str3.c_str());
					int num4 = atoi(str4.c_str());
					int num5 = atoi(str5.c_str());

					vec.push_back(num1);
					vec.push_back(num2);
					vec.push_back(num3);
					vec.push_back(num4);
					vec.push_back(num5);
				}
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> vec;

	int n;
	cin >> n;

	make_4th_666(vec);
	make_5th_666(vec);
	make_6th_666(vec);
	make_7th_666(vec);

	sort(vec.begin(), vec.end());

	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	cout << vec[n - 1];

	return 0;
}