#include <bits/stdc++.h>
using namespace std;

// * MST - Kruskal Alg

int N, M, answer;
int parent[100001];
vector<pair<int, pair<int, int>>> Edge;

int findParent(int x)
{
    if (x == parent[x])
        return x;
    else
        return parent[x] = findParent(parent[x]);
}

bool isSameParent(int a, int b)
{
    int aP = findParent(a);
    int bP = findParent(b);
    if (aP == bP)
        return true;
    return false;
}

void unionParent(int a, int b)
{
    int aP = findParent(a);
    int bP = findParent(b);

    if (aP == bP)
        return;
    parent[bP] = aP;
}

void Input()
{
    scanf("%d%d", &N, &M);

    int a, b, c;
    for (int i = 0; i < M; ++i)
    {
        scanf("%d%d%d", &a, &b, &c);
        Edge.push_back(make_pair(c, make_pair(a, b)));
    }
}

void Solve()
{
    for (int i = 0; i <= N; ++i)
        parent[i] = i;
    sort(Edge.begin(), Edge.end());

    int cnt = 0;
    for (int i = 0; i < Edge.size(); ++i)
    {
        if (cnt >= N - 2)
            break;

        int a = Edge[i].second.first;
        int b = Edge[i].second.second;
        int cost = Edge[i].first;

        if (!isSameParent(a, b))
        {
            unionParent(a, b);
            answer += cost;
            cnt++;
        }
    }

    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}
