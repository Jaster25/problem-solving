#include <bits/stdc++.h>
using namespace std;

int h, w;

// . ±æ, * º®, # ¹®, $ ÁË¼ö

char MAP[102][102];
bool visited[102][102];

int result1[102][102];
int result2[102][102];
int result3[102][102];
int resultSum[102][102];

int p1y, p1x;
int p2y, p2x;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

void Input()
{
    char temp;
    bool isFisrtPrisoner = true;

    scanf("%d%d", &h, &w);
    getchar();

    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            scanf("%c", &temp);
            if (temp == '$')
            {
                MAP[i][j] = '.';
                if (isFisrtPrisoner)
                {
                    isFisrtPrisoner = false;
                    p1y = i;
                    p1x = j;
                }
                else
                {
                    p2y = i;
                    p2x = j;
                }
            }
            else
                MAP[i][j] = temp;
        }
        getchar();
    }
}

void BFS(int (*result)[102], int startY, int startX)
{
    memset(visited, 0, sizeof(visited));

    deque<pair<int, int>> DQ;
    visited[startY][startX] = true;
    DQ.push_back(make_pair(startY, startX));

    while (!DQ.empty())
    {
        int y = DQ.front().first;
        int x = DQ.front().second;
        DQ.pop_front();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 0 && ny <= h + 1 && nx >= 0 && nx <= w + 1)
                if (!visited[ny][nx] && MAP[ny][nx] != '*')
                {
                    visited[ny][nx] = true;
                    switch (MAP[ny][nx])
                    {
                    case '.':
                        result[ny][nx] = result[y][x];
                        DQ.push_front(make_pair(ny, nx));
                        break;
                    case '#':
                        result[ny][nx] = result[y][x] + 1;
                        DQ.push_back(make_pair(ny, nx));
                        break;
                    }
                }
        }
    }
}

void Solve()
{
    BFS(result1, 0, 0);
    BFS(result2, p1y, p1x);
    BFS(result3, p2y, p2x);

    int minDoorCnt = 987654321;
    for (int i = 0; i <= h + 1; ++i)
        for (int j = 0; j <= w + 1; ++j)
        {
            resultSum[i][j] = result1[i][j];
            resultSum[i][j] += result2[i][j];
            resultSum[i][j] += result3[i][j];

            if (MAP[i][j] == '#')
                resultSum[i][j] -= 2;

            if (MAP[i][j] != '*')
                minDoorCnt = min(minDoorCnt, resultSum[i][j]);
        }

    printf("%d\n", minDoorCnt);
}

void reset()
{
    fill(&MAP[0][0], &MAP[101][102], '.');
    memset(result1, 0, sizeof(result1));
    memset(result2, 0, sizeof(result2));
    memset(result3, 0, sizeof(result3));
    memset(resultSum, 0, sizeof(resultSum));
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    while (T--)
    {
        reset();
        Input();
        Solve();
    }
}
