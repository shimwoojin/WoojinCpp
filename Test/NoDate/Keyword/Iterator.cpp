#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>

class Test
{
public:
	Test() = default;
	Test(int data) : data(data) {}
	Test& operator=(const Test& test)
	{
		data = test.data;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, const Test& test)
	{
		os << test.data;
		return os;
	}

	bool operator>(const Test& test)
	{
		return data > test.data;
	}

	bool operator<(const Test& test)
	{
		return data < test.data;
	}

	bool operator==(const Test& rhs)
	{
		return data == rhs.getData();
	}

	int getData() const { return data; }


private:
	int data;
};

bool compare(const Test& a, const Test& b)
{
	return a.getData() > b.getData();
}

bool isNotUnique(const Test& a, const Test& b)
{
	std::cout << "ºñ±³Áß" << std::endl;
	return a.getData() == b.getData();
}

int main()
{
	using namespace std;
	//vector<int> vi;
	//vi.push_back(1);
	//vi.push_back(2);
	//vi.push_back(3);
	//vi.push_back(4);
	//vi.push_back(5);
	//vi.push_back(6);
	//vi.push_back(7);
	//vi.push_back(8);
	//vi.push_back(9);

	//vector<int> vi2;

	//copy(vi.begin(), vi.end(), ostream_iterator<int>(cout, " "));
	//copy(vi.rbegin(), vi.rend(), ostream_iterator<int>(cout, " "));

	//list<int> ls = { 10, 20, 30 };

	//copy(ls.rbegin(), ls.rend(), ostream_iterator<int>(cout, " "));

	//stack<int> sck;

	vector<Test> test;
	vector<Test> test2;
	test.push_back(Test(10));
	test.push_back(Test(20));
	test.push_back(Test(30));
	test.push_back(Test(40));
	test.push_back(Test(50));
	test.push_back(Test(60));
	test.push_back(Test(70));
	test.push_back(Test(80));
	test.push_back(Test(90));

	//test2.push_back(Test(10));
	//test2.push_back(Test(20));
	//test2.push_back(Test(30));
	//test2.push_back(Test(40));

	//std::sort(test.begin(), test.end(),compare);

	//test.swap(test2);
	//test2.swap(test);
	//reverse(test.begin(),test.end());
	//Test test2(100);
	//swap(test[0], test[2]);
	//test2.assign(10,0);
	test2.resize(10);
	cout << test2.back() << endl;
	copy(test.begin(), test.end(), test2.begin());
	test2.insert(test2.begin() + 2, 5, 3);
	test2.emplace_back(100);
	test2.shrink_to_fit();
	unique(test2.begin(), test2.end(),isNotUnique);
	cout << test2.capacity() << endl;
	copy(test2.begin(), test2.end(), ostream_iterator<Test>(cout, "]["));


	//cout << test2 << endl;
	//cout << test[0] << endl;
	//cout << test[1] << endl;

	//list<Test> li;
	//li.emplace_back(10);

	return 0;
}