#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

int N, M;
bool visited[MAX];
vector<int> graph[MAX];
vector<int> graphReverse[MAX];
stack<int> ST;

int answer;
int sccSize;
int SCC[MAX];
int sccInDegree[MAX];

void Input()
{
    scanf("%d%d", &N, &M);
    int a, b;
    for (int i = 0; i < M; ++i)
    {
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graphReverse[b].push_back(a);
    }
}

void dfs1(int n)
{
    visited[n] = true;
    for (auto v : graph[n])
        if (!visited[v])
            dfs1(v);
    ST.push(n);
}

void dfs2(int n)
{
    visited[n] = true;
    SCC[n] = sccSize;

    for (auto v : graphReverse[n])
        if (!visited[v])
            dfs2(v);
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
            dfs2(popped);
            sccSize++;
        }
    }

    for (int i = 1; i <= N; ++i)
        for (int j : graph[i])
            if (SCC[i] != SCC[j])
                sccInDegree[SCC[j]]++;

    for (int i = 0; i < sccSize; ++i)
        if (sccInDegree[i] == 0)
            answer++;

    printf("%d\n", answer);
}

int main()
{
    int TC;
    scanf("%d", &TC);
    while (TC--)
    {
        answer = sccSize = 0;
        memset(visited, false, sizeof(visited));
        fill(sccInDegree, &sccInDegree[MAX], 0);
        fill(SCC, &SCC[MAX], 0);
        for (int i = 0; i <= N; ++i)
        {
            graph[i].clear();
            graphReverse[i].clear();
        }

        Input();
        Solve();
    }
}
