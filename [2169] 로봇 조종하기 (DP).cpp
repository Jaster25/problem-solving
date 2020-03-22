#include <bits/stdc++.h>
using namespace std;

int N, M;
int worth[1001][1001];
int dp[1001][1001];
int temp[2][1001];

void Input()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            scanf("%d", &worth[i][j]);
}

void Solve()
{
    dp[1][1] = worth[1][1];
    for (int j = 2; j <= M; ++j)
        dp[1][j] = dp[1][j - 1] + worth[1][j];

    for (int i = 2; i <= N; ++i)
    {
        // ->
        temp[0][1] = dp[i - 1][1] + worth[i][1];
        for (int j = 2; j <= M; ++j)
            temp[0][j] = max(dp[i - 1][j], temp[0][j - 1]) + worth[i][j];

        // <-
        temp[1][M] = dp[i - 1][M] + worth[i][M];
        for (int j = M - 1; j >= 1; --j)
            temp[1][j] = max(dp[i - 1][j], temp[1][j + 1]) + worth[i][j];

        // ->,<- ºñ±³
        for (int j = 1; j <= M; ++j)
            dp[i][j] = max(temp[0][j], temp[1][j]);
    }

    printf("%d", dp[N][M]);
}

int main()
{

    Input();
    Solve();
}
