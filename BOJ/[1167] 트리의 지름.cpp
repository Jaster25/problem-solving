#include <bits/stdc++.h>
using namespace std;

int V, furthestVertex;
vector<pair<int, int>> graph[100001];
bool visited[100001];
int d[100001];

void Input()
{
    scanf("%d", &V);

    int vertex, opposite, weight;
    for (int i = 0; i < V; ++i)
    {
        scanf("%d", &vertex);
        while (1)
        {
            scanf("%d", &opposite);
            if (opposite == -1)
                break;
            scanf("%d", &weight);

            graph[vertex].push_back({opposite, weight});
            graph[opposite].push_back({vertex, weight});
        }
    }
}

int dfs(int n)
{
    fill(visited, &visited[100001], 0);
    fill(d, &d[100001], 0);
    int maxDistance = 0;

    visited[n] = true;
    stack<int> S;
    S.push(n);

    while (!S.empty())
    {
        int popped = S.top();
        S.pop();

        for (auto v : graph[popped])
        {
            int oppositeV = v.first;
            int oppositeW = v.second;
            if (visited[oppositeV])
                continue;

            visited[oppositeV] = true;
            S.push(oppositeV);

            d[oppositeV] = d[popped] + oppositeW;
            if (maxDistance < d[oppositeV])
            {
                maxDistance = d[oppositeV];
                furthestVertex = oppositeV;
            }
        }
    }

    return maxDistance;
}

void Solve()
{
    dfs(1);
    printf("%d", dfs(furthestVertex));
}

int main()
{
    Input();
    Solve();
}
