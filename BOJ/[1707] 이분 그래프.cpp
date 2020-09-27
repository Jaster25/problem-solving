#include <bits/stdc++.h>
using namespace std;

enum
{
    EMPTY = 0,
    RED = 1,
    BLUE = -1
};

int V, E;
vector<int> graph[20001];
int color[20001];

void Input()
{
    for (int i = 1; i <= V; ++i)
    {
        color[i] = EMPTY;
        graph[i].clear();
    }

    scanf("%d%d", &V, &E);
    int a, b;
    for (int i = 0; i < E; ++i)
    {
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void Solve()
{
    queue<int> Q;

    for (int i = 1; i <= V; ++i)
    {
        if (color[i] != EMPTY)
            continue;

        Q.push(i);
        color[i] = RED;

        while (!Q.empty())
        {
            int popped = Q.front();
            Q.pop();

            for (auto v : graph[popped])
            {
                if (color[v] == EMPTY)
                {
                    color[v] = -1 * color[popped];
                    Q.push(v);
                }
                else if (color[v] == color[popped])
                {
                    puts("NO");
                    return;
                }
            }
        }
    }

    puts("YES");
}

int main()
{
    int TC;
    scanf("%d", &TC);
    while (TC--)
    {
        Input();
        Solve();
    }
}