#include <iostream>
#include <map>
using namespace std;

struct MapArray
{
	MapArray(int row, int column)
	{
		this->row = row;
		this->column = column;
	}

	int row;
	int column;

	bool operator<(const MapArray& Rhs) const
	{
		if (this->row < Rhs.row)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};


int main()
{
	typedef int Data;

	map<MapArray, Data> MapAsArray;

	MapAsArray.emplace(MapArray(2, 5), 10);

	cout << MapAsArray[MapArray(2, 5)] << endl;

	MapAsArray[MapArray(2, 5)] = 5;

	cout << MapAsArray[MapArray(2, 5)] << endl;

	return 0;
}
