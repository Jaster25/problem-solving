#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[1000001];

int findParent(int a)
{
    if (a == parent[a])
        return a;
    return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b)
{
    int ap = findParent(a);
    int bp = findParent(b);
    if (ap > bp)
        parent[ap] = bp;
    else
        parent[bp] = ap;
}

bool isSameParent(int a, int b)
{
    int ap = findParent(a);
    int bp = findParent(b);
    if (ap == bp)
        return true;
    return false;
}

void Solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        parent[i] = i;

    int order, a, b;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &order, &a, &b);
        if (!order)
            unionParent(a, b);
        else
        {
            if (isSameParent(a, b))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}

int main()
{
    Solve();
}
