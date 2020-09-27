#include <bits/stdc++.h>
using namespace std;
#define ll long long

int N;
ll dp[91][2];

void Input()
{
    scanf("%d", &N);
}

void Solve()
{
    dp[1][0] = 0;
    dp[1][1] = 1;

    for (int i = 2; i <= N; ++i)
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    printf("%lld", dp[N][0] + dp[N][1]);
}

int main()
{
    Input();
    Solve();
}
