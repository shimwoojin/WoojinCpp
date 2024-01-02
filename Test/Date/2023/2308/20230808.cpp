#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	/*vector<vector<int>> myvec;

	myvec.assign(10, vector<int>());

	myvec[3].push_back(1);

	myvec[7].push_back(3);

	cout << myvec[3][0] << endl;
	cout << myvec[7][0] << endl;*/

	struct XY
	{
		XY(int x, int y)
		{
			this->x = x;
			this->y = y;
		}

		int x;
		int y;
	};
	
	map<XY, int> MyMap;
	
	XY xy(2, 3);

	/*MyMap.emplace(XY(2, 3), 5);

	cout << MyMap.at(XY(2, 3)) << endl;*/
	/*{
		if (MyMap.find(XY(2, 3)) != MyMap.end())
		{
		}
	}*/


	return 0;
}