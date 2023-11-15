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
	//Ǯ�� ���� : https://velog.io/@961230/%EB%B0%B1%EC%A4%80-2343%EA%B8%B0%ED%83%80-%EB%A0%88%EC%8A%A8-C

	int N, M;
	cin >> N >> M;
	vector<int> records(N, 0);
	int right = 0;	//�̺� Ž���� ���� left, right -> right�� ��� ����� ��, left�� ��� �� �ִ밪�� ���������� ����
	int left = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> records[i];
		right += records[i];
	}

	left = *max_element(records.begin(), records.end());

	while (left <= right)	//left�� right���� Ŀ���� ���� Ż��
	{
		int mid = (right + left) / 2;	//left, right�� �߰����� -> mid�� ��緹���� ���� �ǹ���
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

		if (sum != 0) count++;	//ª�� ��緹���� ���̶� �ִٸ� �̰͵� ������� ��

		if (count > M)
		{
			left = mid + 1;	//count�� M���� ũ�ٴ� �� ��緹���� ���� �� �� ū �������� ������ ���� �ǹ�
		}
		else
		{
			right = mid - 1;	//count�� M���� �۴ٴ� �� ��緹���� ���� �� �� �߰� ��ȭ�� �� �ְ� �߰� �߷��� ���� �ǹ� -> ��緹���� ���� ���� �� �ְ� �� right = mid - 1;
		}
	}

	cout << left;

	return 0;
}