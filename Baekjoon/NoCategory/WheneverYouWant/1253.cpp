#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int answer = 0;
	int n;
	cin >> n;
	
	vector<int> A(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	for (int i = 0; i < n; i++)
	{
		int now = A[i];
		int left = 0;
		int right = n - 1;

		while (left < right)
		{
			if (A[left] + A[right] == now)
			{
				if (left != i && right != i)
				{
					++answer;
					break;
				}
				else if (left == i) left++;
				else if (right == i) right--;
			}
			else if (A[left] + A[right] > now)
			{
				right--;
			}
			else if (A[left] + A[right] < now)
			{
				left++;
			}
		}
	}

	cout << answer;

	return 0;
}