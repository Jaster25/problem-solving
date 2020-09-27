#include <bits/stdc++.h>
using namespace std;

int N, M, MAP[102][102];
int visited[102][102];
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

queue<pair<int, int>> Q;

void Input()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; ++j)
            scanf("%1d", &MAP[i][j]);
}

void BFS()
{
    int y, x;
    while (!Q.empty())
    {
        y = Q.front().first;
        x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 1 && ny <= N && nx >= 1 && nx <= M)
                if (MAP[ny][nx])
                    if (!visited[ny][nx])
                    {
                        visited[ny][nx] = visited[y][x] + 1;
                        Q.push(make_pair(ny, nx));
                    }
        }
    }
}

void Solve()
{
    visited[1][1] = 1;
    Q.push(make_pair(1, 1));
    BFS();

    printf("%d", visited[N][M]);
}

int main()
{
    Input();
    Solve();
}
