#include <bits/stdc++.h>
using namespace std;

int N, A[1001];
int dp[1001];

void Input()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &A[i]);
}

void DP(int n)
{
    if (dp[n] == 0)
        return;
    for (int i = 1; i <= A[n]; ++i)
    {
        if (n + i > N)
            return;

        if (dp[n + i] != 0)
            dp[n + i] = min(dp[n + i], dp[n] + 1);
        else
            dp[n + i] = dp[n] + 1;
    }
}

void Solve()
{
    dp[1] = 1;
    for (int i = 1; i < N; ++i)
        DP(i);

    if (dp[N] != 0)
        printf("%d", dp[N] - 1);
    else
        printf("-1");
}

int main()
{
    Input();
    Solve();
}
