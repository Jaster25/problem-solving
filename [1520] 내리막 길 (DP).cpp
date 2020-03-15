#include <bits/stdc++.h>
using namespace std;

int M, N, MAP[501][501];
int dp[501][501];

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

void Input()
{
    scanf("%d%d", &M, &N);
    for (int i = 1; i <= M; ++i)
        for (int j = 1; j <= N; ++j)
            scanf("%d", &MAP[i][j]);
}

int f(int y, int x)
{
    if (y == 1 && x == 1)
        return 1;

    if (dp[y][x] == -1)
    {
        dp[y][x] = 0;
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny <= M && ny > 0 && nx <= N && nx > 0)
                if (MAP[ny][nx] > MAP[y][x])
                    dp[y][x] += f(ny, nx);
        }
    }

    return dp[y][x];
}

void Solve()
{
    memset(dp, -1, sizeof(dp));
    printf("%d", f(M, N));
}

int main()
{
    Input();
    Solve();
}