#include <iostream>
#include <map>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	map<string, int> test;

	test["hello1"] = 1;
	test["hello2"] = 2;
	test["hello3"] = 3;
	test["hello4"] = 4;
	test["hello5"] = 5;
	test["hello6"] = 6;

	cout << test["hello1"] << endl;
	cout << test["hello2"] << endl;
	cout << test["hello3"] << endl;
	cout << test["hello4"] << endl;
	cout << test["hello5"] << endl;
	cout << test["hello6"] << endl;

	test.emplace("hello7", 7);
	test.emplace("hello8", 8);
	test.emplace("hello9", 9);

	cout << test["hello7"] << endl;
	cout << test["hello8"] << endl;
	cout << test["hello9"] << endl;

	test.insert(make_pair("hello10", 10));
	test.insert(make_pair("hello11", 11));
	test.insert(make_pair("hello12", 12));

	//test.erase(test.begin(), test.end());

	test.erase(test.find("hello10"));
	test.erase("hello11");

	//cout << test["hello10"] << endl;
	//cout << test["hello11"] << endl;
	//cout << test["hello12"] << endl;

	for (auto iter = test.begin(); iter != test.end(); iter++)
	{
		cout << (*iter).first << " " << (*iter).second << endl;
		//cout << iter->first << " " << iter->second << endl;
	}

	return 0;
}