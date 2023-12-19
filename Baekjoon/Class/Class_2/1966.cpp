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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int N, M;
		queue<pair<int, int>> queue1;
		queue<pair<int, int>> queue2;
		cin >> N >> M;
		
		for (int j = 0; j < N; j++)
		{
			int a;
			cin >> a;

			queue1.push(make_pair(j, a));
		}

		while (queue1.empty() == false)
		{
			auto temp = queue1;

			auto front = temp.front();
			temp.pop();

			bool IsBiggest = true;

			while (temp.empty() == false)
			{
				auto temp_front = temp.front();
				temp.pop();

				if (temp_front.second > front.second)
				{
					IsBiggest = false;
					break;
				}
			}

			if (IsBiggest == true)
			{
				queue2.push(queue1.front());
				queue1.pop();
			}
			else
			{
				queue1.push(queue1.front());
				queue1.pop();
			}

		}

		int count = 0;

		while (queue2.empty() == false)
		{
			++count;

			if (queue2.front().first == M) break;

			queue2.pop();
		}

		cout << count << "\n";
	}

	return 0;
}