#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M, X;
vector<pair<int, int>> graph[1001];
int dist[1001], result[1001];

void Input()
{
    scanf("%d%d%d", &N, &M, &X);
    int v1, v2, w;
    for (int i = 0; i < M; ++i)
    {
        scanf("%d%d%d", &v1, &v2, &w);
        graph[v1].push_back(make_pair(v2, w));
    }
}

void Dijkstra(int start)
{
    priority_queue<pair<int, int>> PQ;
    dist[start] = 0;
    PQ.push(make_pair(0, start));

    while (!PQ.empty())
    {
        int w = -PQ.top().first;
        int other = PQ.top().second;
        PQ.pop();

        for (int i = 0; i < graph[other].size(); ++i)
        {
            int next = graph[other][i].first;
            int nextW = graph[other][i].second;
            if (dist[next] > w + nextW)
            {
                dist[next] = w + nextW;
                PQ.push(make_pair(-dist[next], next));
            }
        }
    }
}

void Solve()
{
    // * home -> party
    for (int i = 1; i <= N; ++i)
    {
        fill(dist, &dist[1001], INF);
        Dijkstra(i);
        result[i] = dist[X];
    }

    // * party -> home
    fill(dist, &dist[1001], INF);
    Dijkstra(X);

    for (int i = 1; i <= N; ++i)
        result[i] += dist[i];

    sort(&result[1], &result[N + 1]);
    printf("%d", result[N]);
}

int main()
{
    Input();
    Solve();
}
