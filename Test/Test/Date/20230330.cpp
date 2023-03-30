#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	set<pair<int, string>> set_test;
	
	set_test.insert(make_pair(1, "hello"));
	set_test.insert(make_pair(1, "hello"));
	set_test.insert(make_pair(1, "helloworld"));
	set_test.insert(make_pair(2, "hello"));
	set_test.insert(make_pair(2, "helloworld"));

	pair<int, string> pair1 = make_pair(1, "hello");
	pair<int, string> pair2 = make_pair(1, "hello");

	if (pair1 == pair2) cout << "pair1과 pair2는 같습니다" << endl;

	for (auto iter = set_test.begin(); iter != set_test.end(); iter++)
	{
		cout << (*iter).first << " " << (*iter).second << "\n";
	}

	return 0;
}