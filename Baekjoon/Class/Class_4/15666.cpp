#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> answers;

void Solution(set<int>& container, int m, set<int>::iterator iter)
{
	if (answers.size() == m)
	{
		for (int answer : answers)
		{
			cout << answer << " ";
		}
		cout << '\n';

		return;
	}

	for (; iter != container.end(); iter++)
	{
		answers.push_back(*iter);
		Solution(container, m, iter);
		answers.pop_back();
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	set<int> container;

	while (n--)
	{
		int temp;
		cin >> temp;
		container.insert(temp);
	}

	Solution(container, m, container.begin());

	return 0;
}