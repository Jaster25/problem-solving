#include <bits/stdc++.h>
using namespace std;

int T, N, K, W;
vector<int> graph[1001];
int inDegree[1001];
int duration[1001];
int buildTime[1001];

void topologicalSort()
{
    queue<int> Q;
    for (int i = 1; i <= N; ++i)
        if (inDegree[i] == 0)
        {
            duration[i] = buildTime[i];
            Q.push(i);
        }

    while (!Q.empty())
    {
        int popped = Q.front();
        Q.pop();

        if (popped == W)
            return;

        for (auto v : graph[popped])
        {
            duration[v] = max(duration[v], duration[popped] + buildTime[v]);
            if (--inDegree[v] == 0)
                Q.push(v);
        }
    }
}

void reset()
{
    for (int i = 0; i <= 1000; ++i)
    {
        graph[i].clear();
        inDegree[i] = 0;
        duration[i] = 0;
        buildTime[i] = 0;
    }
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        reset();
        scanf("%d%d", &N, &K);
        for (int i = 1; i <= N; ++i)
            scanf("%d", &buildTime[i]);

        int x, y;
        for (int i = 1; i <= K; ++i)
        {
            scanf("%d%d", &x, &y);
            graph[x].push_back(y);
            inDegree[y]++;
        }

        scanf("%d", &W);

        topologicalSort();

        printf("%d\n", duration[W]);
    }
}
