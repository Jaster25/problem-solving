#include <bits/stdc++.h>
using namespace std;

int N, M;
int MAP[101][101];

int dist[101][101];
const int INF = 987654321;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

void Input()
{
    scanf("%d%d", &M, &N);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            scanf("%1d", &MAP[i][j]);
}

void Solve()
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            dist[i][j] = INF;
    dist[1][1] = 0;

    queue<pair<int, int>> Q;
    Q.push(make_pair(1, 1));

    while (!Q.empty())
    {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 1 && ny <= N && nx >= 1 && nx <= M)
            {
                if (MAP[ny][nx] == 0)
                {
                    if (dist[ny][nx] > dist[y][x])
                    {
                        dist[ny][nx] = dist[y][x];
                        Q.push(make_pair(ny, nx));
                    }
                }
                else
                {
                    if (dist[ny][nx] > dist[y][x] + 1)
                    {
                        dist[ny][nx] = dist[y][x] + 1;
                        Q.push(make_pair(ny, nx));
                    }
                }
            }
        }
    }

    printf("%d", dist[N][M]);
}

int main()
{
    Input();
    Solve();
}
