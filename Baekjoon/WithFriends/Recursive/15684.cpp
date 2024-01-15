//#include <bits/stdc++.h>
//using namespace std;
//
//int answer = INT_MAX;
//
//bool Check(const vector<vector<bool>>& ladder, int x, int y)
//{
//	if (ladder[y][x - 1] == false && ladder[y][x] == false && ladder[y][x + 1] == false)
//	{
//		return true;
//	}
//
//	return false;
//}
//
//bool CanAnswer(const vector<vector<bool>>& ladder, int n, int h)
//{
//	for (int i = 1; i <= n; i++)
//	{
//		int length = i;
//		int width = 1;
//
//		while (width <= h)
//		{
//			if (ladder[width][length])
//			{
//				++length;
//			}
//			else if (ladder[width][length - 1])
//			{
//				--length;
//			}
//
//			++width;
//		}
//
//		if (length != i)
//		{
//			return false;
//		}
//	}
//
//	return true;
//}
//
//void BackTracking(vector<vector<bool>>& ladder, int n, int h, int x, int y, int count)
//{
//	if (count > 3 && y == h + 2)
//	{
//		return;
//	}
//
//	if (CanAnswer(ladder, n, h))
//	{
//		answer = min(answer, count);
//	}
//
//	for (int i = y; i <= h; i++)
//	{
//		for (int j = 1; j < n; j++)
//		{
//			if (y == i && j < x)
//			{
//				continue;
//			}
//
//			if (Check(ladder, j, i))
//			{
//				ladder[i][j] = true;
//
//				if (j == n - 1)
//				{
//					BackTracking(ladder, n, h, 1, i + 1, count + 1);
//				}
//				else
//				{
//					BackTracking(ladder, n, h, j + 1, i, count + 1);
//				}
//
//				ladder[i][j] = false;
//			}
//		}
//	}
//}
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int n, m, h;
//	cin >> n >> m >> h;
//	vector<vector<bool>> ladder(h + 1, vector<bool>(n + 1, false));
//
//	int repeat = m;
//	
//	while (repeat--)
//	{
//		int a, b;
//		cin >> a >> b;
//
//		ladder[a][b] = true;
//	}
//
//	BackTracking(ladder, n, h, 1, 1, 0);
//
//	if (answer == INT_MAX)
//	{
//		cout << -1;
//	}
//	else
//	{
//		cout << answer;
//	}
//
//	return 0;
//}

#include<iostream>
#include<vector>

int n, m, h;
bool Hline[31][11];
std::vector<std::pair<int, int>> pos;

bool check() {
    for (int i = 1; i <= n; ++i) {
        int nowVline = i;
        for (int j = 1; j <= h; ++j) {
            if (nowVline != n && Hline[j][nowVline]) nowVline++;
            else if (nowVline != 1 && Hline[j][nowVline - 1]) nowVline--;
        }
        if (nowVline != i) return false;
    }
    return true;
}

bool ladder(int lad, int idx) {

    if (lad == 0) return check();

    for (int i = idx; i < pos.size(); ++i) {
        int h = pos[i].first;
        int v = pos[i].second;
        if (!Hline[h][v] && !Hline[h][v - 1] && !Hline[h][v + 1]) {
            Hline[h][v] = true;
            if (ladder(lad - 1, i + 1)) return true;
            Hline[h][v] = false;
        }
    }

    return false;
}

int main() {

    std::cin >> n >> m >> h;

    for (int i = 0; i < m; ++i) {
        int a, b;
        std::cin >> a >> b;
        Hline[a][b] = true;
    }

    for (int i = 1; i <= n - 1; ++i)
        for (int j = 1; j <= h; ++j)
            if (!Hline[j][i] && !Hline[j][i - 1] && !Hline[j][i + 1]) {
                pos.push_back({ j,i });

                while (j + 2 < h && !Hline[j + 2][i] && !Hline[j + 2][i - 1] && !Hline[j + 2][i + 1]) j++;
            }

    //.

    int ladnum = 0;
    while (ladnum <= 3 && !ladder(ladnum, 0)) ladnum++;
    if (ladnum > 3) std::cout << "-1";
    else std::cout << ladnum;
}