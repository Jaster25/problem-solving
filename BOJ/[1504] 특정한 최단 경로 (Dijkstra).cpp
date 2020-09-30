#include <bits/stdc++.h>
using namespace std;

int N, E;
int v1, v2;
bool isImpossible1, isImpossible2;
int answer1, answer2;
vector<pair<int, int>> G[801];

const int INF = 987654321;
int dist[801];

void Input()
{
    scanf("%d%d", &N, &E);
    int a, b, c;
    for (int i = 0; i < E; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }

    scanf("%d%d", &v1, &v2);
}

void Dijkstra(int start)
{
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, start));
    dist[start] = 0;

    while (!PQ.empty())
    {
        int w = -PQ.top().first;
        int v = PQ.top().second;
        PQ.pop();

        for (int i = 0; i < G[v].size(); ++i)
        {
            int nextW = G[v][i].second;
            int nextV = G[v][i].first;
            if (dist[nextV] > w + nextW)
            {
                dist[nextV] = w + nextW;
                PQ.push(make_pair(-dist[nextV], nextV));
            }
        }
    }
}

void Solve()
{
    // * 1>v1>v2>N
    // * 1>v2>v1>N

    // * 1 start
    for (int i = 1; i <= N; ++i)
        dist[i] = INF;
    Dijkstra(1);

    if (dist[v1] == INF)
        isImpossible1 = true;
    else
        answer1 += dist[v1];
    if (dist[v2] == INF)
        isImpossible2 = true;
    else
        answer2 += dist[v2];

    // * v1 start
    for (int i = 1; i <= N; ++i)
        dist[i] = INF;
    Dijkstra(v1);

    if (dist[v2] == INF)
        isImpossible1 = true;
    else
        answer1 += dist[v2];
    if (dist[N] == INF)
        isImpossible2 = true;
    else
        answer2 += dist[N];

    // * v2 start
    for (int i = 1; i <= N; ++i)
        dist[i] = INF;
    Dijkstra(v2);

    if (dist[N] == INF)
        isImpossible1 = true;
    else
        answer1 += dist[N];
    if (dist[v1] == INF)
        isImpossible2 = true;
    else
        answer2 += dist[v1];

    if (isImpossible1 == true && isImpossible2 == true)
        printf("-1");
    else if (isImpossible1 == false && isImpossible2 == false)
        printf("%d", min(answer1, answer2));
    else if (isImpossible1 == false)
        printf("%d", answer1);
    else
        printf("%d", answer2);
}

int main()
{
    Input();
    Solve();
}
