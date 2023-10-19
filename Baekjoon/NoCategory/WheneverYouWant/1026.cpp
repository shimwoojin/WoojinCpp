#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> A(N), B(N), SortB(N), CopyB(N), IndexB(N), ResultA(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> B[i];
	}

	SortB = B;
	CopyB = B;
	sort(SortB.begin(), SortB.end());
	
	for (int i = 0; i < SortB.size(); i++)
	{
		auto FIter = find(B.begin(), B.end(), SortB[i]);
		int Index = FIter - B.begin();
		B[Index] = -1;
		
		IndexB[Index] = i;
	}

	sort(A.begin(), A.end(), greater<int>());

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (IndexB[j] == i)
			{
				ResultA[j] = A[i];
				break;
			}
		}
	}

	int Sum = 0;

	for (int i = 0; i < N; i++)
	{
		Sum += ResultA[i] * CopyB[i];
	}

	cout << Sum;

	return 0;
}