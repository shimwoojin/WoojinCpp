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
	float score_sum = 0;		//학점 * 등급 누적
	int denominator = 0;	//학점 누적

	for (int i = 0; i < 20; i++)
	{
		getline(cin, str);

		int count = 0;
		int grade = 0;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == ' ' && count == 0)
			{
				grade = (int)str[j + 1] - 48;
				denominator += grade;
				++count;
			}
			else if (str[j] == ' ' && count == 1)
			{
				if (str[j + 1] == 'A' && str[j + 2] == '+')
				{
					score_sum += (grade * 4.5);
				}
				else if (str[j + 1] == 'A' && str[j + 2] == '0')
				{
					score_sum += (grade * 4.0);
				}
				else if (str[j + 1] == 'B' && str[j + 2] == '+')
				{
					score_sum += (grade * 3.5);
				}
				else if (str[j + 1] == 'B' && str[j + 2] == '0')
				{
					score_sum += (grade * 3.0);
				}
				else if (str[j + 1] == 'C' && str[j + 2] == '+')
				{
					score_sum += (grade * 2.5);
				}
				else if (str[j + 1] == 'C' && str[j + 2] == '0')
				{
					score_sum += (grade * 2.0);
				}
				else if (str[j + 1] == 'D' && str[j + 2] == '+')
				{
					score_sum += (grade * 1.5);
				}
				else if (str[j + 1] == 'D' && str[j + 2] == '0')
				{
					score_sum += (grade * 1.0);
				}
				else if (str[j + 1] == 'P')
				{
					denominator -= grade;
				}
				else if (str[j + 1] == 'F')
				{
					score_sum += 0.0f;
				}
			}
		}
	}

	cout << fixed;
	cout.precision(6);

	cout << score_sum / denominator;


	return 0;
}