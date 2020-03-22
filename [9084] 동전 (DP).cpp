#include <bits/stdc++.h>
using namespace std;

int N, M;
int coin[21];
int dp[10001];

void Input()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        scanf("%d", &coin[i]);
    scanf("%d", &M);
}

void Solve()
{
    dp[0] = 1;
    for (int i = 0; i < N; ++i)
        for (int j = coin[i]; j <= M; ++j)
            dp[j] += dp[j - coin[i]];

    printf("%d\n", dp[M]);
}

int main()
{
    int TC;
    scanf("%d", &TC);
    while (TC--)
    {
        memset(coin, 0, sizeof(coin));
        memset(dp, 0, sizeof(dp));
        Input();
        Solve();
    }
}
