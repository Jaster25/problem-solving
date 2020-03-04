#include <bits/stdc++.h>
#define mod 1000000000
using namespace std;

int N, answer;
int full = (1 << 10) - 1;
int dp[101][10][1 << 10];

void Input()
{
    scanf("%d", &N);
}

void Solve()
{
    for (int i = 1; i <= 9; ++i)
        dp[1][i][1 << i] = 1;

    for (int i = 2; i <= N; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
            for (int k = 0; k <= full; ++k)
            {
                if (j == 0)
                    dp[i][0][k | (1 << 0)] = (dp[i][0][k | (1 << 0)] + dp[i - 1][1][k]) % mod;
                else if (j == 9)
                    dp[i][9][k | (1 << 9)] = (dp[i][9][k | (1 << 9)] + dp[i - 1][8][k]) % mod;
                else
                {
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % mod;
                    dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % mod;
                }
            }
        }
    }

    for (int i = 0; i <= 9; ++i)
        answer = (answer + dp[N][i][full]) % mod;

    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}