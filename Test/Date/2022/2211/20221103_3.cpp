#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

class Test
{
public:
	Test() : test(0) {}
	Test(int test) : test(test) {}

	friend std::ostream& operator<<(std::ostream& os, const Test& t)
	{
		os << t.test;
		return os;
	}

	bool operator<(const Test& t) const
	{
		return this->test < t.test;
	}

	bool operator>(const Test& t) const
	{
		return this->test > t.test;
	}

private:
	int test;
};

int main()
{
	using namespace std;
	vector<Test> a(5,Test(2));

	a.push_back(3);
	a.emplace_back(Test(4));
	sort(a.begin(), a.end());
	for_each(a.begin(), a.end(), [](Test& t) {cout << t << endl; });
	for (auto x : a) cout << x << endl;
	
	cout << endl;

	priority_queue<Test, vector<Test>, less<Test>> pq;

	pq.push(Test(2));
	pq.push(Test(3));
	pq.push(Test(4));
	pq.push(Test(5));
	pq.push(Test(6));

	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}



	return 0;
}