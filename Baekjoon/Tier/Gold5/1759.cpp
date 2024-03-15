#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

set<string> answers;
vector<char> set_a;
vector<char> set_b;
int l, c;

void Solution(int set_a_count)
{
	int set_b_count = l - set_a_count;

	if (set_a_count <= set_a.size() && set_b_count <= set_b.size() && set_b_count >= 2)
	{
		vector<bool> temp_a(set_a.size() - set_a_count, false);
		vector<bool> temp_b(set_b.size() - set_b_count, false);
		for (int i = 0; i < set_a_count; i++) temp_a.push_back(true);
		for (int i = 0; i < set_b_count; i++) temp_b.push_back(true);

		do
		{
			set<char> combination;
			for (int i = 0; i < temp_b.size(); i++)
			{
				if (temp_b[i] == true)
				{
					combination.insert(set_b[i]);
				}
			}

			do
			{
				for (int i = 0; i < temp_a.size(); i++)
				{
					if (temp_a[i] == true)
					{
						combination.insert(set_a[i]);
					}
				}

				auto iter = combination.begin();
				string answer(combination.size(), '\0');
				for (int i = 0; i < answer.size(); i++)
				{
					answer[i] = *iter;
					iter++;
				}

				answers.insert(answer);

				for (int i = 0; i < temp_a.size(); i++)
				{
					if (temp_a[i] == true)
					{
						combination.erase(set_a[i]);
					}
				}

			} while (next_permutation(temp_a.begin(), temp_a.end()));

		} while (next_permutation(temp_b.begin(), temp_b.end()));
	}
	
	if (set_a_count + 1 <= set_a.size())
	{
		Solution(set_a_count + 1);
	}
}

int main()
{
	cin >> l >> c;

	while (c--)
	{
		char temp;
		cin >> temp;

		if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
		{
			set_a.push_back(temp);
		}
		else
		{
			set_b.push_back(temp);
		}
	}

	sort(set_a.begin(), set_a.begin());
	sort(set_b.begin(), set_b.begin());
	Solution(1);

	for (const auto& answer : answers)
	{
		cout << answer << '\n';
	}

	return 0;
}