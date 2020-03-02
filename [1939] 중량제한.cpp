#include <bits/stdc++.h>
using namespace std;

int N, M, from, to;
int MAX;
vector<pair<int, int>> graph[100001];
bool visited[100001];

void Input()
{
    scanf("%d%d", &N, &M);

    int a, b, c;
    for (int i = 0; i < M; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        MAX = max(MAX, c);
    }

    scanf("%d%d", &from, &to);
}

bool BFS(int weight)
{
    memset(visited, false, sizeof(visited));
    visited[from] = true;
    queue<int> Q;
    Q.push(from);

    while (!Q.empty())
    {
        int popped = Q.front();
        Q.pop();
        if (popped == to)
            return true;

        for (auto p : graph[popped])
        {
            int v = p.first;
            int w = p.second;
            if (!visited[v] && weight <= w)
            {
                Q.push(v);
                visited[v] = true;
            }
        }
    }

    return false;
}

void Solve()
{
    int answer;
    int low = 0, high = MAX;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (BFS(mid))
        {
            low = mid + 1;
            answer = mid;
        }
        else
            high = mid - 1;
    }

    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}
