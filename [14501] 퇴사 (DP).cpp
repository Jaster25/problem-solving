#include <bits/stdc++.h>
using namespace std;

int N;
int T[16], P[16];
int dp[17];

void Input()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d%d", &T[i], &P[i]);
}

void Solve()
{
    for (int i = 0; i < N; ++i)
    {
        dp[i + 1] = max(dp[i + 1], dp[i]);
        dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
    }

    printf("%d", dp[N]);
}

int main()
{
    Input();
    Solve();
}
