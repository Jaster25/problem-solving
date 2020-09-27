#include <bits/stdc++.h>
using namespace std;

int n;
int ar[501][501];
int dp[501][501];

int f(int a, int b)
{
    if (dp[a][b] != -1)
        return dp[a][b];

    if (b == 0)
        return dp[a][b] = f(a - 1, b) + ar[a][b];
    else if (b == a)
        return dp[a][b] = f(a - 1, b - 1) + ar[a][b];
    else
        return dp[a][b] = max(f(a - 1, b - 1), f(a - 1, b)) + ar[a][b];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
        {
            scanf("%d", &ar[i][j]);
            dp[i][j] = -1;
        }

    memset(dp, -1, sizeof(dp));

    dp[0][0] = ar[0][0];

    int MAX = 0;
    for (int i = 0; i < n; ++i)
        MAX = max(MAX, f(n - 1, i));

    printf("%d", MAX);
}
