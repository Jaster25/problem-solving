#include <bits/stdc++.h>
#define INF 999999
using namespace std;

typedef struct
{
    int vertexNum;
    int opposite;
    int weight;
} Node;

int V, E, K;
vector<Node> graph[20001];
int D[20001];

void Dijkstra(int start)
{
    fill(&D[0], &D[V + 1], INF);

    // -weight , vertexNum
    priority_queue<pair<int, int>> Q;

    D[start] = 0;
    Q.push(make_pair(0, start));

    while (!Q.empty())
    {
        pair<int, int> popped = Q.top();
        Q.pop();

        if (D[popped.second] < -popped.first)
            continue;

        for (auto e : graph[popped.second])
        {
            if (D[e.opposite] > D[e.vertexNum] + e.weight)
            {
                D[e.opposite] = D[e.vertexNum] + e.weight;
                Q.push(make_pair(-D[e.opposite], e.opposite));
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &V, &E, &K);

    int u, v, w;
    for (int i = 0; i < E; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        graph[u].push_back(Node{u, v, w});
    }

    Dijkstra(K);

    for (int i = 1; i <= V; ++i)
    {
        if (D[i] != INF)
            printf("%d\n", D[i]);
        else
            printf("INF\n");
    }
}
