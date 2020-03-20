#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> graph[10001];
int timeV[10001];
int accumulation[10001];
int inDegree[10001];

void Input()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
    {
        int connectCnt;
        scanf("%d%d", &timeV[i], &connectCnt);

        for (int j = 0; j < connectCnt; ++j)
        {
            int to;
            scanf("%d", &to);
            graph[i].push_back(to);
            inDegree[to]++;
        }
    }
}

void Solve()
{
    queue<int> Q;

    for (int i = 1; i <= N; ++i)
        if (inDegree[i] == 0)
        {
            Q.push(i);
            accumulation[i] = timeV[i];
        }

    while (!Q.empty())
    {
        int from = Q.front();
        Q.pop();

        for (auto to : graph[from])
        {
            if (--inDegree[to] == 0)
                Q.push(to);
            if (accumulation[to] < accumulation[from] + timeV[to])
                accumulation[to] = accumulation[from] + timeV[to];
        }
    }

    sort(accumulation, accumulation + N + 1);
    printf("%d", accumulation[N]);
}

int main()
{
    Input();
    Solve();
}
