#include <bits/stdc++.h>
using namespace std;

int N, answer;
int T[1500002], P[1500002];
int dp[1500002];

void Input()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d%d", &T[i], &P[i]);
}

void Solve()
{
    for (int i = N; i >= 1; --i)
    {
        if (i + T[i] > N + 1)
            dp[i] = dp[i + 1];
        else
            dp[i] = max(dp[i + 1], P[i] + dp[i + T[i]]);
    }

    printf("%d", dp[1]);
}

int main()
{
    Input();
    Solve();
}
