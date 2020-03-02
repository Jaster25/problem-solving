#include <bits/stdc++.h>
using namespace std;

int X, N;
int dp[1000001];

int f(int n)
{
    if (n == 1)
        return 0;
    if (dp[n] != 0)
        return dp[n];

    dp[n] = f(n - 1) + 1;

    if (n % 2 == 0)
        dp[n] = min(f(n / 2) + 1, dp[n]);

    if (n % 3 == 0)
        dp[n] = min(f(n / 3) + 1, dp[n]);

    return dp[n];
}

int main()
{
    scanf("%d", &N);
    printf("%d", f(N));
}