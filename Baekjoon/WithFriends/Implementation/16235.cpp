#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <deque>

using namespace std;

bool check(pair<int, int> loc, int n)
{
	if (loc.first > 0 && loc.first <= n && loc.second > 0 && loc.second <= n)
	{
		return true;
	}
	return false;
}

struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator() (const std::pair<T1, T2>& pair) const {
		return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
	}
};

int main()
{
	//start : 17:03

	//봄 : 양분 - 나이, 나이 + 1  -> 자신의 나이만큼 양분을 못 먹으면 나무 사망
	//한 칸에 여러개라면 나이가 어린애부터
	//여름 : 봄에 죽은 나무가 양분이 됨 -> 나이 / 2한 값을 양분에 추가
	//가을 : 나무 나이가 5의 배수인 경우, 인접 8개 칸에 나이 1 나무 생성
	//겨울 : 양분 추가, A[r][c]

	int n, m, k;	//n : 땅 넓이(n * n), m : 겨울에 땅마다 추가할 양분, k : 몇 년 후
	cin >> n >> m >> k;

	vector<vector<int>> add_energies(n + 1, vector<int>(n + 1, 0));	//A[r][c]
	vector<vector<int>> ground(n + 1, vector<int>(n + 1, 5));	//n * n
	//unordered_map<pair<int, int>, deque<int>, pair_hash> trees;	//x, y, z
	map<pair<int, int>, deque<int>> trees;	//x, y, z

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> add_energies[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		//trees.insert(make_pair(make_pair(x, y), deque<int>{z}));
		trees[make_pair(x, y)].push_back(z);
	}

	for (int year = 0; year < k; year++)	//년도
	{
		for (auto& tree : trees)
		{
			int x = tree.first.first;
			int y = tree.first.second;
			deque<int>& years = tree.second;
			int i = 0;

			for (; i < years.size(); i++)
			{
				if (ground[y][x] >= years[i])	//봄
				{
					ground[y][x] -= years[i];
					++years[i];
				}
				//여름
				else
				{
					break;
				}
			}

			for (int j = years.size() - 1; j >= i; --j)
			{
				ground[y][x] += years.back() / 2;
				years.pop_back();
			}
		}

		for (auto& tree : trees)	//가을
		{
			int x = tree.first.first;
			int y = tree.first.second;
			deque<int>& years = tree.second;

			if (years.empty())
			{
				continue;
			}

			vector<pair<int, int>> new_tree_loc
			{
				make_pair(x - 1, y),
				make_pair(x - 1, y - 1),
				make_pair(x - 1, y + 1),
				make_pair(x, y + 1),
				make_pair(x, y - 1),
				make_pair(x + 1, y),
				make_pair(x + 1, y - 1),
				make_pair(x + 1, y + 1)
			};

			for (int year : years)
			{
				if (year % 5 == 0)
				{
					for (const auto& new_loc : new_tree_loc)
					{
						if (check(new_loc, n))
						{
							trees[new_loc].push_front(1);
						}
					}
				}
			}
		}

		for (int y = 1; y <= n; y++)	//겨울
		{
			for (int x = 1; x <= n; x++)
			{
				ground[y][x] += add_energies[x][y];
			}
		}
	}

	int count = 0;
	
	for (const auto& tree : trees)
	{
		count += tree.second.size();
	}

	cout << count << endl;

	return 0;
}

//#include <stdio.h>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <deque>
//
//using namespace std;
//
//int n, m, k;
//
//int a[11][11];
//int nutri[11][11];
//deque<int> trees[11][11];
//
//int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
//int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
//
//int main() {
//	scanf_s("%d %d %d", &n, &m, &k);
//
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			scanf_s("%d", &a[i][j]);
//			nutri[i][j] = 5;
//		}
//	}
//
//	for (int i = 0; i < m; ++i) {
//		int x, y, z;
//		scanf_s("%d %d %d", &x, &y, &z);
//		trees[x][y].push_back(z);
//	}
//
//	for (int t = 0; t < k; ++t) {
//		// 봄
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j <= n; ++j) {
//				int size = trees[i][j].size();
//				// 양분 먹고 나이 +1
//				int k = 0;
//				for (; k < trees[i][j].size(); ++k) {
//					if (nutri[i][j] >= trees[i][j][k]) {
//						nutri[i][j] -= trees[i][j][k];
//						trees[i][j][k]++;
//					}
//					else {
//						break;
//					}
//				}
//				// 여름
//				// 죽은 나무 있는 곳 양분 추가
//				for (int p = trees[i][j].size() - 1; p >= k; --p) {
//					nutri[i][j] += trees[i][j][p] / 2;
//					trees[i][j].pop_back();
//				}
//			}
//		}
//
//		// 가을
//		// 나무 번식
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j <= n; ++j) {
//				if (trees[i][j].size() > 0) {
//					for (int k = 0; k < trees[i][j].size(); ++k) {
//						if (trees[i][j][k] % 5 == 0) {
//							for (int q = 0; q < 8; ++q) {
//								int nx = i + dx[q];
//								int ny = j + dy[q];
//								if (nx < 1 || nx > n || ny < 1 || ny > n)
//									continue;
//								else {
//									trees[nx][ny].push_front(1); // 새로 추가되는 나무를 앞쪽에 넣으면 정렬할 필요 X
//								}
//							}
//						}
//					}
//				}
//				// 겨울
//				// 양분 추가
//				nutri[i][j] += a[i][j];
//			}
//		}
//	}
//
//	int tree_cnt = 0;
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			if (trees[i][j].size() > 0) {
//				tree_cnt += trees[i][j].size();
//			}
//		}
//	}
//
//	printf("%d\n", tree_cnt);
//	return 0;
//}