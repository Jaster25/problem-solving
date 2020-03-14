#include <bits/stdc++.h>
using namespace std;

#define MAX 10001

int V, E;
vector<int> graph[MAX];
vector<int> graphReverse[MAX];
bool visited[MAX];
stack<int> ST;

int sccSize;
vector<vector<int>> scc;

bool cmp(vector<int> x, vector<int> y)
{
    return x[0] < y[0];
}

void dfs(int n)
{
    visited[n] = true;

    for (auto v : graph[n])
        if (!visited[v])
            dfs(v);
    ST.push(n);
}

void dfs2(int n)
{
    visited[n] = true;
    scc[sccSize - 1].push_back(n);

    for (auto v : graphReverse[n])
        if (!visited[v])
            dfs2(v);
}

int main()
{
    scanf("%d%d", &V, &E);
    for (int i = 0; i < E; ++i)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graphReverse[b].push_back(a);
    }

    for (int i = 1; i <= V; ++i)
        if (!visited[i])
            dfs(i);

    memset(visited, false, sizeof(visited));

    while (!ST.empty())
    {
        int popped = ST.top();
        ST.pop();

        if (visited[popped])
            continue;

        scc.resize(++sccSize);
        dfs2(popped);
    }

    for (int i = 0; i < sccSize; ++i)
        sort(scc[i].begin(), scc[i].end());
    sort(scc.begin(), scc.end(), cmp);

    printf("%d\n", sccSize);

    for (auto i : scc)
    {
        for (auto j : i)
            printf("%d ", j);
        printf("-1\n");
    }
}
