#include <bits/stdc++.h>
using namespace std;

queue<pair<int, int>> Q;
int tomato[1001][1001];
int day[1001][1001];
int N, M;

void bfs()
{
    while (!Q.empty())
    {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        int dy[4] = {1, -1, 0, 0};
        int dx[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < N && nx >= 0 && nx < M)
            {
                if (tomato[ny][nx] == 0 && day[ny][nx] == 0)
                {
                    Q.push(make_pair(ny, nx));
                    tomato[ny][nx] = 1;
                    day[ny][nx] = day[y][x] + 1;
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d", &M, &N);

    int y, x;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &tomato[i][j]);

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            if (tomato[i][j] == 1)
            {
                Q.push(make_pair(i, j));
                day[i][j] = 1;
            }

    bfs();

    int MAX = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (tomato[i][j] == 0)
            {
                printf("-1");
                return 0;
            }
            else if (tomato[i][j] == 1)
                MAX = max(MAX, day[i][j] - 1);
        }
    }

    printf("%d", MAX);
}