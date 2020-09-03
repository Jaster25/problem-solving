#include <bits/stdc++.h>
using namespace std;

int N, M, S, E;
int number[2001];
bool dp[2001][2001];

void Input()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &number[i]);
}

void Solve()
{
    // * base condition
    // * S == 1
    for (int i = 1; i <= N; ++i)
        dp[i][i] = true;
    // * S == 2
    for (int i = 1; i < N; ++i)
        if (number[i] == number[i + 1])
            dp[i][i + 1] = true;

    for (int i = 2; i < N; ++i)
        for (int j = 1; j <= N - i; ++j)
            if (dp[j + 1][j + i - 1] && number[j] == number[j + i])
                dp[j][j + i] = true;

    int T, s, e;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &s, &e);
        printf("%d\n", dp[s][e]);
    }
}

int main()
{
    Input();
    Solve();
}
