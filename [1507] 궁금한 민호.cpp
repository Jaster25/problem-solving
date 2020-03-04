#include <bits/stdc++.h>
using namespace std;

int N, M;
int graph[21][21];
bool road[21][21];

void Input()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            scanf("%d", &graph[i][j]);
}

void Solve()
{
    memset(road, true, sizeof(road));

    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (i == j || j == k || i == k)
                    continue;

                // 불가능한 경우
                if (graph[i][j] > graph[i][k] + graph[k][j])
                {
                    printf("-1");
                    return;
                }
                else if (graph[i][j] == graph[i][k] + graph[k][j])
                    road[i][j] = false;
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (road[i][j])
                result += graph[i][j];
    printf("%d", result / 2);
}

int main()
{
    Input();
    Solve();
}