#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;

bool compare(string a, string b)
{
	if (a.size() > b.size()) return false;
	else if (a.size() == b.size())
	{
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i] > b[i]) return false;
			else if (a[i] == b[i]) continue;
			else return true;
		}
		return false;
	}
	else return true;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<string> vec;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		vec.push_back(str);
	}

	sort(vec.begin(), vec.end(), compare);
	vec.erase(unique(vec.begin(), vec.end()), vec.end());	//unique�� �ߺ��� ���Ҹ� �ڷ� �̷��ִ� ����
	//erase�� ���� �� �� �־��� ���� unique�� ��ȯ���� �ߺ��� �͵��� ���� iterator�� ������
		
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i];
		if (i != vec.size() - 1) cout << "\n";
	}
	return 0;
}