#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

bool CheckAllSame(vector<vector<int>> MyVec, int& blue, int& white);
void DivideVector(vector<vector<int>> Origin, vector < vector<int>>& Div1, vector < vector<int>>& Div2, vector < vector<int>>& Div3, vector < vector<int>>& Div4);

void FindSquare(vector<vector<int>> MyVec, int& blue, int& white)
{
	if (CheckAllSame(MyVec, blue, white) == false)
	{
		vector<vector<int>> div1, div2, div3, div4;
		DivideVector(MyVec, div1, div2, div3, div4);

		FindSquare(div1, blue, white);
		FindSquare(div2, blue, white);
		FindSquare(div3, blue, white);
		FindSquare(div4, blue, white);
	}
}

bool CheckAllSame(vector<vector<int>> MyVec, int& blue, int& white)
{
	int FirstNumber = MyVec[0][0];

	for (int i = 0; i < MyVec.size(); i++)
	{
		for (int j = 0; j < MyVec.size(); j++)
		{
			if (FirstNumber != MyVec[i][j])
			{
				return false;
			}
		}
	}

	if (FirstNumber == 1)
	{
		++blue;
	}
	else
	{
		++white;
	}

	return true;
}

void DivideVector(vector<vector<int>> Origin, vector < vector<int>>& Div1, vector < vector<int>>& Div2, vector < vector<int>>& Div3, vector < vector<int>>& Div4)
{
	if (Origin.size() <= 1) return;

	int Size = Origin.size();
	int HalfSize = Size / 2;

	Div1.assign(HalfSize, vector<int>());
	Div2.assign(HalfSize, vector<int>());
	Div3.assign(HalfSize, vector<int>());
	Div4.assign(HalfSize, vector<int>());

	for (int i = 0; i < HalfSize; i++)
	{
		for (int j = 0; j < HalfSize; j++)
		{
			Div1[i].push_back(Origin[i][j]);
		}
	}

	for (int i = 0; i < HalfSize; i++)
	{
		for (int j = HalfSize; j < Size; j++)
		{
			Div2[i].push_back(Origin[i][j]);
		}
	}

	for (int i = HalfSize; i < Size; i++)
	{
		for (int j = 0; j < HalfSize; j++)
		{
			Div3[i - HalfSize].push_back(Origin[i][j]);
		}
	}

	for (int i = HalfSize; i < Size; i++)
	{
		for (int j = HalfSize; j < Size; j++)
		{
			Div4[i - HalfSize].push_back(Origin[i][j]);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int num;
	int temp;
	int blue = 0, white = 0;
	
	cin >> num;

	vector<vector<int>> Vec;

	Vec.assign(num, vector<int>());

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cin >> temp;
			
			Vec[i].push_back(temp);
		}
	}

	FindSquare(Vec, blue, white);

	cout << white << "\n" << blue;

	return 0;
}