#include <bits/stdc++.h>
using namespace std;

int N, M, answer;
int parent[1001];
bool visited[1001];
vector<int> graph[1001];

void Input()
{
    scanf("%d%d", &N, &M);

    int u, v;
    for (int i = 0; i < M; ++i)
    {
        scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int n)
{
    answer--;
    for (int j = 0; j < graph[n].size(); ++j)
        if (!visited[graph[n][j]])
        {
            visited[graph[n][j]] = true;
            dfs(graph[n][j]);
        }
}

void Solve()
{
    answer = N;
    for (int i = 1; i <= N; ++i)
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i);
            answer++;
        }

    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}
