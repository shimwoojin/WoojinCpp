#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <string>
#include <functional>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	unordered_map<string, function<void(int&, int)>> m;
	set<int> s;
	vector<int> bit_map(21);
	int bit_mask = 0;
	int all_bit = (int)pow(2, 21) - 1;

	for (int i = 0; i < 21; i++)
	{
		bit_map[i] = pow(2, i);
	}

	m["add"] = [&](int& bit_mask, int n) {
		bit_mask = bit_mask | bit_map[n];
	};

	m["remove"] = [&](int& bit_mask, int n) {
		bit_mask = bit_mask & ~bit_map[n];
	};

	m["check"] = [&](int& bit_mask, int n) {
		if (bit_mask & bit_map[n])
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	};

	m["toggle"] = [&](int& bit_mask, int n) {
		if (bit_mask & (int)pow(2, n))
		{
			bit_mask = bit_mask & ~bit_map[n];
		}
		else
		{
			bit_mask = bit_mask | bit_map[n];
		}
	};

	m["all"] = [&](int& bit_mask, int n) {
		bit_mask = bit_mask | (all_bit);
	};

	m["empty"] = [&](int& bit_mask, int n) {
		bit_mask = 0;
	};

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		int num = 0;
		cin >> str;

		if (str == "all" || str == "empty")
		{
			
		}
		else
		{
			cin >> num;
		}

		m[str](bit_mask, num);
	}

	return 0;
}