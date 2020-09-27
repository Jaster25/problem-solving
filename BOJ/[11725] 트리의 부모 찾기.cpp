#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int parent[100001];

void bfs(int startV)
{
    queue<int> Q;
    Q.push(startV);
    parent[startV] = 1;

    while (!Q.empty())
    {
        int popped = Q.front();
        Q.pop();
        for (auto v : graph[popped])
        {
            if (parent[v] == 0)
            {
                Q.push(v);
                parent[v] = popped;
            }
        }
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    int v1, v2;
    for (int i = 1; i < N; ++i)
    {
        scanf("%d%d", &v1, &v2);
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    bfs(1);

    for (int i = 2; i <= N; ++i)
        printf("%d\n", parent[i]);
}
