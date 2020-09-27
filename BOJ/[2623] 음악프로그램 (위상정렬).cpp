#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> graph[1001];
int inDegree[1001];
bool visited[1001];
vector<int> topologicalSort;

void Input()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= M; ++i)
    {
        int cnt;
        scanf("%d", &cnt);

        int from, to;
        scanf("%d", &from);

        while (--cnt)
        {
            scanf("%d", &to);
            graph[from].push_back(to);
            inDegree[to]++;
            from = to;
        }
    }
}

void dfs(int from)
{
    topologicalSort.push_back(from);

    for (auto to : graph[from])
        if (--inDegree[to] == 0 && !visited[to])
        {
            visited[to] = true;
            dfs(to);
        }
}

void Solve()
{
    queue<int> Q;
    for (int i = 1; i <= N; ++i)
        if (!visited[i] && inDegree[i] == 0)
        {
            visited[i] = true;
            dfs(i);
        }

    if (topologicalSort.size() == N)
        for (auto n : topologicalSort)
            printf("%d\n", n);
    else
        printf("0");
}

int main()
{
    Input();
    Solve();
}