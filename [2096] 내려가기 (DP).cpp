#include <bits/stdc++.h>
using namespace std;

int N;
int board[3 + 1];
int dp[2][3 + 1][2];

void Input_Solve()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            dp[0][j][0] = dp[1][j][0];
            dp[0][j][1] = dp[1][j][1];
            scanf("%d", &board[j]);
        }

        if (i == 1)
            for (int j = 1; j <= 3; ++j)
                dp[1][j][0] = dp[1][j][1] = board[j];
        else
        {
            // 최대 점수
            dp[1][1][0] = max(dp[1 - 1][1][0], dp[1 - 1][2][0]) + board[1];
            dp[1][2][0] = max(dp[1 - 1][3][0], max(dp[1 - 1][2][0], dp[1 - 1][1][0])) + board[2];
            dp[1][3][0] = max(dp[1 - 1][3][0], dp[1 - 1][2][0]) + board[3];

            // 최소 점수
            dp[1][1][1] = min(dp[1 - 1][1][1], dp[1 - 1][2][1]) + board[1];
            dp[1][2][1] = min(dp[1 - 1][3][1], min(dp[1 - 1][2][1], dp[1 - 1][1][1])) + board[2];
            dp[1][3][1] = min(dp[1 - 1][3][1], dp[1 - 1][2][1]) + board[3];
        }
    }

    int MAX = max(max(dp[1][1][0], dp[1][2][0]), dp[1][3][0]);
    int MIN = min(min(dp[1][1][1], dp[1][2][1]), dp[1][3][1]);

    printf("%d %d", MAX, MIN);
}

int main()
{
    Input_Solve();
}
