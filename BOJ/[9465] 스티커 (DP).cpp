#include <bits/stdc++.h>
using namespace std;

int N, score[2][100001];
int dp[2][100001];

void Input()
{
    scanf("%d", &N);
    for (int i = 0; i <= 1; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &score[i][j]);
}

void Solve()
{
    dp[0][0] = score[0][0];
    dp[1][0] = score[1][0];
    dp[0][1] = dp[1][0] + score[0][1];
    dp[1][1] = dp[0][0] + score[1][1];

    for (int i = 2; i < N; ++i)
    {
        dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + score[0][i];
        dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + score[1][i];
    }

    printf("%d\n", max(dp[0][N - 1], dp[1][N - 1]));
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(score, 0, sizeof(score));
        memset(dp, 0, sizeof(dp));
        Input();
        Solve();
    }
}
