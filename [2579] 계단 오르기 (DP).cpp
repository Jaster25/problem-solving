#include <bits/stdc++.h>
using namespace std;
int N, stairs[301];
int dp[301];

void Input()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &stairs[i]);
}

void Solve()
{
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);

    for (int i = 4; i <= N; ++i)
        dp[i] = max(dp[i - 3] + stairs[i - 1] + stairs[i],
                    dp[i - 2] + stairs[i]);

    printf("%d", dp[N]);
}

int main()
{
    Input();
    Solve();
}
