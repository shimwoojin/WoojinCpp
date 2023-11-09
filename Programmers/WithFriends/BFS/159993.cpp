#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool check(int n, int max)
{
    if (n < 0 || n >= max)
    {
        return false;
    }
    return true;
}

int bfs(vector<string> maps, char start, char wall, char end)
{
    int count = 0;
    int size_y = maps.size();
    int size_x = maps[0].size();
    pair<int, int> now;
    queue<pair<int, int>> q;

    for (int i = 0; i < size_y; i++)
    {
        for (int j = 0; j < size_x; j++)
        {
            if (maps[i][j] == start)
            {
                now = make_pair(j, i);
                break;
            }
        }
    }

    q.push(now);
    maps[now.second][now.first] = wall;

    while (!q.empty())
    {
        queue<pair<int, int>> temp;
        ++count;

        while (!q.empty())
        {
            auto front = q.front();
            q.pop();

            vector<pair<int, int>> ways
            {
                make_pair(front.first - 1, front.second),
                make_pair(front.first + 1, front.second),
                make_pair(front.first, front.second - 1),
                make_pair(front.first, front.second + 1)
            };

            for (auto way : ways)
            {
                if (check(way.first, size_x) && check(way.second, size_y))
                {
                    char w = maps[way.second][way.first];

                    if (w == end)
                    {
                        return count;
                    }
                    if (w == wall)
                    {
                        continue;
                    }
                    temp.push(make_pair(way.first, way.second));
                    maps[way.second][way.first] = wall;
                }
            }
        }

        q = move(temp);
    }

    return -1;
}

int solution(vector<string> maps) {
    int answer = 0;

    answer += bfs(maps, 'S', 'X', 'L');
    if (answer != -1)
    {
        int try2 = bfs(maps, 'L', 'X', 'E');

        if (try2 != -1)
        {
            answer += try2;
        }
        else
        {
            answer = try2;
        }
    }

    return answer;
}