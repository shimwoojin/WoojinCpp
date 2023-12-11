#include <bits/stdc++.h>
using namespace std;

int main()
{
	//start: 18:55
	//end: 19:42

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int answer = 0;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> paper(n, vector<int>(m, 0));
	map<string, function<void(const vector<vector<int>>&)>> bruteforces;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> paper[i][j];
		}
	}

	// 1. 긴 막대기 1 x 4
	//1.1 눕힌 모양
	bruteforces["1x4"] = [n, m, &answer](const vector<vector<int>>& paper) {
		
		for (int i = 0; i < n; i++)
		{
			int count = 0;

			for (int j = 0; j < m - 3; j++)
			{
				count = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i][j + 3];
				answer = max(answer, count);
			}
		}
	};

	//1.2 선 모양
	bruteforces["4x1"] = [n, m, &answer](const vector<vector<int>>& paper) {

		for (int i = 0; i < n - 3; i++)
		{
			int count = 0;

			for (int j = 0; j < m; j++)
			{
				count = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 3][j];
				answer = max(answer, count);
			}
		}
	};

	//2. 정사각형 모양
	bruteforces["2x2"] = [n, m, &answer](const vector<vector<int>>& paper) {

		for (int i = 0; i < n - 1; i++)
		{
			int count = 0;

			for (int j = 0; j < m - 1; j++)
			{
				count = paper[i][j] + paper[i][j + 1] + paper[i + 1][j] + paper[i + 1][j + 1];
				answer = max(answer, count);
			}
		}
	};

	//3. L 모양, L 거울 모양, L 아래로 거울, L 거울의 아래로 거울, 번개 모양, 번개 거울 모양, ㅓ 모양, ㅏ 모양
	bruteforces["3x2"] = [n, m, &answer](const vector<vector<int>>& paper) {

		for (int i = 0; i < n - 2; i++)
		{
			int count1 = 0;	//L 모양
			int count2 = 0;	//L 거울 모양
			int count3 = 0;	//L 아래로 거울
			int count4 = 0;	//L 거울의 아래로 거울
			int count5 = 0;	//번개 모양
			int count6 = 0;	//번개 거울 모양
			int count7 = 0;	//ㅓ 모양
			int count8 = 0;	//ㅏ 모양

			for (int j = 0; j < m - 1; j++)
			{
				count1 = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 2][j + 1];
				count2 = paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1] + paper[i + 2][j];
				count3 = paper[i][j] + paper[i][j + 1] + paper[i + 1][j] + paper[i + 2][j];
				count4 = paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
				count5 = paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
				count6 = paper[i][j + 1] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 2][j];
				count8 = paper[i + 1][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 2][j + 1];
				count7 = paper[i][j] + paper[i + 1][j] + paper[i + 2][j] + paper[i + 1][j + 1];

				answer = max(answer, count1);
				answer = max(answer, count2);
				answer = max(answer, count3);
				answer = max(answer, count4);
				answer = max(answer, count5);
				answer = max(answer, count6);
				answer = max(answer, count7);
				answer = max(answer, count8);
			}
		}
	};

	//4. 3번 눕힌 버전
	bruteforces["2x3"] = [n, m, &answer](const vector<vector<int>>& paper) {

		for (int i = 0; i < n - 1; i++)
		{
			int count1 = 0;	//L 모양
			int count2 = 0;	//L 거울 모양
			int count3 = 0;	//L 아래로 거울
			int count4 = 0;	//L 거울의 아래로 거울
			int count5 = 0;	//번개 모양
			int count6 = 0;	//번개 거울 모양
			int count7 = 0;	//ㅏ 모양
			int count8 = 0;	//ㅏ 모양

			for (int j = 0; j < m - 2; j++)
			{
				count1 = paper[i][j] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
				count2 = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j];
				count3 = paper[i][j + 2] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
				count4 = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 2];
				count5 = paper[i][j] + paper[i][j + 1] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
				count6 = paper[i + 1][j] + paper[i + 1][j + 1] + paper[i][j + 1] + paper[i][j + 2];
				count7 = paper[i][j + 1] + paper[i + 1][j] + paper[i + 1][j + 1] + paper[i + 1][j + 2];
				count8 = paper[i][j] + paper[i][j + 1] + paper[i][j + 2] + paper[i + 1][j + 1];

				answer = max(answer, count1);
				answer = max(answer, count2);
				answer = max(answer, count3);
				answer = max(answer, count4);
				answer = max(answer, count5);
				answer = max(answer, count6);
				answer = max(answer, count7);
				answer = max(answer, count8);
			}
		}
	};

	for (auto& bruteforce : bruteforces)
	{
		bruteforce.second(paper);
	}

	cout << answer;

	return 0;
}