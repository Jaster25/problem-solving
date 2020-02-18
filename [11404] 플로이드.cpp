#include <bits/stdc++.h>
#define INF 999999999
using namespace std;

int n, m;
int cost[101][101];

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cost[i][j] = (i == j ? 0 : INF);

    int a, b, c;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        cost[a][b] = min(cost[a][b], c);
    }

    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
            printf("%d ", cost[i][j] == INF ? 0 : cost[i][j]);
        printf("\n");
    }
}
