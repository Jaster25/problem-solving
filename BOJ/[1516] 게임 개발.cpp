#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> graph[501];
int inDegree[501];
int duration[501];
int buildTime[501];

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

        for (auto v : graph[popped])
        {
            duration[v] = max(duration[v], duration[popped] + buildTime[v]);
            if (--inDegree[v] == 0)
                Q.push(v);
        }
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", &buildTime[i]);

        int temp;
        scanf("%d", &temp);
        while (temp != -1)
        {
            graph[temp].push_back(i);
            inDegree[i]++;
            scanf("%d", &temp);
        }
    }

    topologicalSort();

    for (int i = 1; i <= N; ++i)
        printf("%d\n", duration[i]);
}