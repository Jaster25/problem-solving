#include <bits/stdc++.h>
using namespace std;

int N, M;
bool visited[9];
int ar[9];

void Input()
{
    scanf("%d%d", &N, &M);
}

void dfs(int cnt)
{
    if (cnt == M)
    {
        for (int i = 1; i <= M; ++i)
            printf("%d ", ar[i]);
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; ++i)
    {
        if (!visited[i])
        {
            ar[cnt + 1] = i;
            visited[i] = true;

            dfs(cnt + 1);

            visited[i] = false;
        }
    }
}

void Solve()
{
    for (int i = 1; i <= N; ++i)
    {
        visited[i] = true;
        ar[1] = i;

        dfs(1);

        visited[i] = false;
    }
}

int main()
{
    Input();
    Solve();
}
