#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> towers(n, 0);
	stack<int> s;

	for(int i = 0; i < n; i++)
	{
		cin >> towers[i];

		while (s.empty() == false && towers[s.top()] < towers[i]) s.pop();

		if (s.empty() == false) cout << s.top() + 1 << ' ';
		else cout << 0 << ' ';

		s.push(i);
	}

	return 0;
}