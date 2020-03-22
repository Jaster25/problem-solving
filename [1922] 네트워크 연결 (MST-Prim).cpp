#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int a, b, w;
};

struct cmp
{
    bool operator()(Node t, Node u)
    {
        return t.w > u.w;
    }
};

int N, M, answer;
vector<pair<int, int>> graph[1001];
bool visited[1001];

void Input()
{
    scanf("%d%d", &N, &M);
    int a, b, w;
    for (int i = 0; i < M; ++i)
    {
        scanf("%d%d%d", &a, &b, &w);
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
}

void Solve()
{
    queue<int> q;
    priority_queue<Node, vector<Node>, cmp> pq;

    q.push(1);
    visited[1] = true;
    for (auto e : graph[1])
        pq.push({1, e.first, e.second});

    while (q.size() < N)
    {
        Node popped = pq.top();
        pq.pop();

        if (!visited[popped.b])
        {
            q.push(popped.b);
            visited[popped.b] = true;

            for (auto e : graph[popped.b])
                pq.push({popped.b, e.first, e.second});

            answer += popped.w;
        }
    }

    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}
