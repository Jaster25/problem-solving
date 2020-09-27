#include <bits/stdc++.h>
using namespace std;

int N, M;
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
        ar[cnt + 1] = i;
        dfs(cnt + 1);
    }
}

void Solve()
{
    for (int i = 1; i <= N; ++i)
    {
        ar[1] = i;
        dfs(1);
    }
}

int main()
{
    Input();
    Solve();
}
