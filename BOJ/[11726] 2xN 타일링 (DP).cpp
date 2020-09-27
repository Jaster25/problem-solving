#include <bits/stdc++.h>
using namespace std;

int N;
int dp[1001];

void Input()
{
    scanf("%d", &N);
}

int DP(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (dp[n])
        return dp[n];
    return dp[n] = (DP(n - 2) + DP(n - 1)) % 10007;
}

void Solve()
{
    printf("%d", DP(N));
}

int main()
{
    Input();
    Solve();
}
