#include <bits/stdc++.h>
using namespace std;

int dp[1001][3];
int N, cost[1001][3];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 3; ++j)
            scanf("%d", &cost[i][j]);

    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    for (int i = 1; i < N; ++i)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    int answer = min(dp[N - 1][0], dp[N - 1][1]);
    answer = min(answer, dp[N - 1][2]);

    printf("%d", answer);
}
