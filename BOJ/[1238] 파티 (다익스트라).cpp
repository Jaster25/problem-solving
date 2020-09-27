#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M, X;
int dist[1001], result[1001];
vector<pair<int, int>> graph[1001];

void Input()
{
    scanf("%d%d%d", &N, &M, &X);
    int a, b, w;
    for (int i = 0; i < M; ++i)
    {
        scanf("%d%d%d", &a, &b, &w);
        graph[a].push_back(make_pair(w, b));
    }
}

void Dijkstra(int start)
{
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int w = -pq.top().first;
        int v = pq.top().second;
        pq.pop();

        for (int i = 0; i < graph[v].size(); ++i)
        {
            int nW = graph[v][i].first;
            int nV = graph[v][i].second;
            if (dist[nV] > w + nW)
            {
                dist[nV] = w + nW;
                pq.push(make_pair(-dist[nV], nV));
            }
        }
    }
}

void Solve()
{
    // * students -> party
    for (int i = 1; i <= N; ++i)
    {
        fill(dist, dist + 1001, INF);
        Dijkstra(i);
        result[i] += dist[X];
    }

    // * party -> students
    fill(dist, dist + 1001, INF);
    Dijkstra(X);

    for (int i = 1; i <= N; ++i)
        result[i] += dist[i];

    sort(result + 1, result + N + 1);

    printf("%d ", result[N]);
}

int main()
{
    Input();
    Solve();
}
