#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> graph[10001];
bool visited[10001];
int d[10001];

void Input()
{
    scanf("%d", &N);
    int a, b, c;
    for (int i = 1; i < N; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
}

int maxVertex;
int bfs(int v)
{
    memset(visited, false, sizeof(visited));
    fill(d, &d[10001], 0);

    visited[v] = true;
    queue<int> Q;
    Q.push(v);

    int maxDistance = 0;
    while (!Q.empty())
    {
        int popped = Q.front();
        Q.pop();

        for (auto opposite : graph[popped])
        {
            int opposite_v = opposite.first;
            int opposite_w = opposite.second;
            if (visited[opposite_v])
                continue;

            Q.push(opposite_v);
            visited[opposite_v] = true;
            d[opposite_v] = max(d[popped] + opposite_w, d[opposite_v]);
            if (maxDistance < d[opposite_v])
            {
                maxDistance = d[opposite_v];
                maxVertex = opposite_v;
            }
        }
    }

    return maxDistance;
}

void Solve()
{
    bfs(1);
    printf("%d", bfs(maxVertex));
}

int main()
{
    Input();
    Solve();
}