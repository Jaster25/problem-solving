#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M, S, D;
int dist[501];
bool visited[501][501];
vector<pair<int, int>> G[501];
vector<pair<int, int>> trace[501];

void Input()
{
    int U, V, P;
    scanf("%d%d", &N, &M);

    if (N == 0 && M == 0)
        exit(0);

    scanf("%d%d", &S, &D);
    for (int i = 0; i < M; ++i)
    {
        scanf("%d%d%d", &U, &V, &P);
        G[U].push_back(make_pair(V, P));
    }
}

void Dijkstra(int start)
{
    fill(dist, &dist[501], INF);
    dist[start] = 0;
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, start));

    while (!PQ.empty())
    {
        int w = -PQ.top().first;
        int v = PQ.top().second;
        PQ.pop();

        if (dist[v] < w)
            continue;

        for (int i = 0; i < G[v].size(); ++i)
        {
            int nv = G[v][i].first;
            int nw = G[v][i].second;

            if (G[v][i].second == -1)
                continue;

            if (dist[nv] > w + nw)
            {
                dist[nv] = w + nw;
                PQ.push(make_pair(-dist[nv], nv));

                // * update trace
                trace[nv].clear();
                trace[nv].push_back(make_pair(v, dist[nv]));
            }
            else if (dist[nv] == w + nw)
                trace[nv].push_back(make_pair(v, dist[nv]));
        }
    }
}

void BFS(int destination)
{
    queue<int> Q;
    Q.push(destination);

    while (!Q.empty())
    {
        int v = Q.front();
        Q.pop();

        for (int i = 0; i < trace[v].size(); ++i)
        {
            int nv = trace[v][i].first;
            if (visited[v][nv])
                continue;

            visited[v][nv] = true;

            for (int i = 0; i < G[nv].size(); ++i)
                if (G[nv][i].first == v)
                    G[nv][i].second = -1;

            Q.push(nv);
        }
    }
}

void Solve()
{
    Dijkstra(S);
    BFS(D);
    Dijkstra(S);

    if (dist[D] == INF)
        printf("-1\n");
    else
        printf("%d\n", dist[D]);
}

void reset()
{
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; ++i)
    {
        G[i].clear();
        trace[i].clear();
    }
}

int main()
{
    while (1)
    {
        reset();
        Input();
        Solve();
    }
}
