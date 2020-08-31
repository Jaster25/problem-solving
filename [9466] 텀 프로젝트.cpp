#include <bits/stdc++.h>
using namespace std;

int T, n;
int student[100001];
bool visited[100001];
bool isDone[100001];
int cnt;

void Input()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", &student[i]);
}

void DFS(int a)
{
    visited[a] = true;

    int want = student[a];
    if (!visited[want])
        DFS(want);
    else if (!isDone[want])
    {
        while (want != a)
        {
            want = student[want];
            cnt++;
        }
        cnt++;
    }

    isDone[a] = true;
}

void Solve()
{
    cnt = 0;
    memset(visited, false, sizeof(visited));
    memset(isDone, false, sizeof(isDone));

    for (int i = 1; i <= n; ++i)
        if (!visited[i])
            DFS(i);

    printf("%d\n", n - cnt);
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        Input();
        Solve();
    }
}
