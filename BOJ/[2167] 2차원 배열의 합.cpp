#include <bits/stdc++.h>
using namespace std;
#define BLANK 10001

int N, M, K;
int ar[301][301];
int DP[301][301];

int dp(int a, int b)
{
    if (a < 1 || a >= 301 || b < 1 || b >= 301)
        return 0;

    if (DP[a][b] != BLANK)
        return DP[a][b];

    if (a == 0)
        return DP[a][b] = dp(a, b - 1) + ar[a][b];
    else if (b == 0)
        return DP[a][b] = dp(a - 1, b) + ar[a][b];
    else
        return DP[a][b] = dp(a - 1, b) + dp(a, b - 1) - dp(a - 1, b - 1) + ar[a][b];
}

int sum(int i, int j, int x, int y)
{
    return dp(x, y) - dp(i - 1, y) - dp(x, j - 1) + dp(i - 1, j - 1);
}

int main()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            scanf("%d", &ar[i][j]);

    fill(&DP[0][0], &DP[301][301], BLANK);

    scanf("%d", &K);
    while (K--)
    {
        int i, j, x, y;
        scanf("%d%d%d%d", &i, &j, &x, &y);
        printf("%d\n", sum(i, j, x, y));
    }
}
