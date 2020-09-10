#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M, X;
int dist[1001][1001];
int result[1001];

void Input()
{
    scanf("%d%d%d", &N, &M, &X);
    fill(&dist[0][0], &dist[1001 - 1][1001], INF);
    for (int i = 1; i <= N; ++i)
        dist[i][i] = 0;
    for (int i = 1; i <= M; ++i)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        dist[a][b] = w;
    }
}

void Solve()
{
    // * k: passing node
    for (int k = 1; k <= N; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                if (dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 1; i <= N; ++i)
        if (dist[i][X] != INF && dist[X][i] != INF)
            result[i] = dist[i][X] + dist[X][i];

    sort(result + 1, result + N + 1);

    for (int i = N; i >= 1; --i)
        if (result[i] != INF)
        {
            printf("%d", result[i]);
            return;
        }
}

int main()
{
    Input();
    Solve();
}
