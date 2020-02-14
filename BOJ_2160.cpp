#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10001
using namespace std;

vector<int> graph[MAX];
bool visited[MAX];
int N, M, V;

void reset()
{
    fill(visited, &visited[10000], false);
    printf("\n");
}

void dfs(int v)
{
    visited[v] = true;
    printf("%d ", v);
    for (int i = 0; i < graph[v].size(); i++)
    {
        if (!visited[graph[v][i]])
        {
            visited[graph[v][i]] = true;
            dfs(graph[v][i]);
        }
    }
}

void bfs()
{
    queue<int> Q;
    Q.push(V);
    visited[V] = true;

    int v;
    while (!Q.empty())
    {
        v = Q.front();
        Q.pop();
        printf("%d ", v);

        for (int i = 0; i < graph[v].size(); i++)
        {
            if (!visited[graph[v][i]])
            {
                visited[graph[v][i]] = true;
                Q.push(graph[v][i]);
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &N, &M, &V);

    int v1, v2;
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &v1, &v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    for (int i = 0; i < N; ++i)
        sort(graph[i].begin(), graph[i].end());

    dfs(V);
    reset();
    bfs();
}