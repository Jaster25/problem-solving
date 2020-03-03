#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;

int N, M, start, destination;
vector<pair<int, int>> graph[1001];
int d[1001];

void Input()
{
    scanf("%d%d", &N, &M);
    int from, to, cost;
    for (int i = 0; i < M; ++i)
    {
        scanf("%d%d%d", &from, &to, &cost);
        graph[from].push_back({to, cost});
    }
    scanf("%d%d", &start, &destination);
}

void Solve()
{
    for (int i = 0; i <= N; ++i)
        d[i] = MAX;

    // -weight , vertexNum
    priority_queue<pair<int, int>> PQ;
    PQ.push({0, start});
    d[start] = 0;

    while (!PQ.empty())
    {
        pair<int, int> popped = PQ.top();
        PQ.pop();

        if (d[popped.second] < -popped.first)
            continue;

        for (auto v : graph[popped.second])
        {
            int opposite = v.first;
            int cost = v.second;

            if (d[opposite] > d[popped.second] + cost)
            {
                d[opposite] = d[popped.second] + cost;
                PQ.push({-d[opposite], opposite});
            }
        }
    }

    printf("%d", d[destination]);
}

int main()
{
    Input();
    Solve();
}
