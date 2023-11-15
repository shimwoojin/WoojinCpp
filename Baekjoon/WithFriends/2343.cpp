#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

//int main()
//{
//	//start 20:10
//	//end 21:05
//
//	int N, M;
//	cin >> N >> M;
//	vector<int> records(N, 0);
//	vector<pair<int, int>> cuts;
//
//	for (int i = 0; i < N; i++)
//	{
//		cin >> records[i];
//	}
//
//	float sum = accumulate(records.begin(), records.end(), 0);
//	float avg = sum / M;
//	float avgAlpha = 0;
//	int forAvg = 0;
//
//	for (int i = 0; i < N; i++)
//	{
//		forAvg += records[i];
//
//		if (forAvg >= avg)
//		{
//			cuts.push_back(make_pair(forAvg, i));
//			forAvg = 0;
//		}
//	}
//
//	while (true)
//	{
//		float avgMin = avg - avgAlpha;
//		float avgMax = avg + avgAlpha;
//
//		for (int i = 0; i < cuts.size(); i++)
//		{
//			int cutAvg = cuts[i].first;
//
//			if (avgMin > cutAvg)
//			{
//				++cuts[i].second;
//
//				cuts[i].first += records[cuts[i].second];
//				if (i + 1 < cuts.size())
//				{
//					cuts[i + 1].first -= records[cuts[i].second];
//				}
//			}
//			else if(avgMax < cutAvg)
//			{
//				cuts[i].first -= records[cuts[i].second];
//				if (i + 1 < cuts.size())
//				{
//					cuts[i + 1].first += records[cuts[i].second];
//				}
//
//				--cuts[i].second;
//			}
//		}
//
//		int start_index = cuts[cuts.size() - 1].second + 1;
//		int acceptAvg = 0;
//
//		for (int i = start_index; i < records.size(); i++)
//		{
//			acceptAvg += records[i];
//			if (acceptAvg <= avgMax && acceptAvg >= avgMin)
//			{
//				cuts.push_back(make_pair(acceptAvg, i));
//				acceptAvg = 0;
//			}
//		}
//
//		if (cuts.size() == M)
//		{
//			pair<int, int> max = *max_element(cuts.begin(), cuts.end());
//			cout << max.first;
//			break;
//		}
//
//		avgAlpha++;
//	}
//
//	return 0;
//}

int main()
{
	//풀이 참조 : https://velog.io/@961230/%EB%B0%B1%EC%A4%80-2343%EA%B8%B0%ED%83%80-%EB%A0%88%EC%8A%A8-C

	int N, M;
	cin >> N >> M;
	vector<int> records(N, 0);
	int right = 0;	//이분 탐색을 위한 left, right -> right는 모든 요소의 합, left는 요소 중 최대값을 시작점으로 잡음
	int left = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> records[i];
		right += records[i];
	}

	left = *max_element(records.begin(), records.end());

	while (left <= right)	//left가 right보다 커지는 순간 탈출
	{
		int mid = (right + left) / 2;	//left, right의 중간지점 -> mid가 블루레이의 합을 의미함
		int sum = 0, count = 0;

		for (int i = 0; i < N; i++)
		{
			if (sum + records[i] > mid)
			{
				sum = 0;
				count++;
			}
			sum += records[i];
		}

		if (sum != 0) count++;	//짧은 블루레이의 합이라도 있다면 이것도 더해줘야 함

		if (count > M)
		{
			left = mid + 1;	//count가 M보다 크다는 건 블루레이의 합이 좀 더 큰 범위에서 잡혀야 함을 의미
		}
		else
		{
			right = mid - 1;	//count가 M보다 작다는 건 블루레이의 합이 좀 더 잘게 분화될 수 있게 잘게 잘려야 함을 의미 -> 블루레이의 합을 낮출 수 있게 끔 right = mid - 1;
		}
	}

	cout << left;

	return 0;
}