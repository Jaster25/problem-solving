#include <bits/stdc++.h>
using namespace std;

int N, answer;
int cost[101];
int police[101][101];
int policeReverse[101][101];

bool visited[101];
stack<int> ST;
vector<vector<int>> SCC;
int sccSize;

void Input()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i)
        scanf("%d", &cost[i]);

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            scanf("%1d", &police[i][j]);

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            policeReverse[i][j] = police[j][i];
}

void dfs1(int n)
{
    visited[n] = true;
    for (int i = 1; i <= N; ++i)
        if (police[n][i] && !visited[i])
            dfs1(i);
    ST.push(n);
}

void dfs2(int n)
{
    visited[n] = true;
    for (int i = 1; i <= N; ++i)
        if (policeReverse[n][i] && !visited[i])
            dfs2(i);
    SCC[sccSize].push_back(n);
}

void Solve()
{
    for (int i = 1; i <= N; ++i)
        if (!visited[i])
            dfs1(i);

    memset(visited, false, sizeof(visited));

    while (!ST.empty())
    {
        int popped = ST.top();
        ST.pop();

        if (!visited[popped])
        {
            SCC.resize(sccSize + 1);
            dfs2(popped);
            sccSize++;
        }
    }

    for (auto scc : SCC)
    {
        int minCost = 10000001;
        for (auto n : scc)
            minCost = min(minCost, cost[n]);
        answer += minCost;
    }

    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}
