#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<vector<int>> myvec;

	myvec.assign(10, vector<int>());

	myvec[3].push_back(1);

	myvec[7].push_back(3);

	cout << myvec[3][0] << endl;
	cout << myvec[7][0] << endl;


	return 0;
}