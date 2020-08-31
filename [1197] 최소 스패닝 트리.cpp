#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<pair<int, pair<int, int>>> edge;
int parent[10001];
int answer;

void Input()
{
    scanf("%d%d", &V, &E);
    int a, b, c;
    for (int i = 0; i < E; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        edge.push_back(make_pair(c, make_pair(a, b)));
    }
    sort(edge.begin(), edge.end());
}

// * union find method
int findParent(int a)
{
    if (parent[a] == a)
        return a;
    else
        return parent[a] = findParent(parent[a]);
}
bool isSameParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if (a != b)
        return false;
    return true;
}
void UnionNode(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if (a != b)
        parent[b] = a;
}

void Solve()
{
    // * for union find
    for (int i = 1; i <= V; ++i)
        parent[i] = i;

    for (int i = 0; i < E; ++i)
    {
        if (!isSameParent(edge[i].second.first, edge[i].second.second))
        {
            UnionNode(edge[i].second.first, edge[i].second.second);
            answer += edge[i].first;
        }
    }
    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}
