#include <bits/stdc++.h>
using namespace std;

int N, M, temp;
int course[1001];
int parent[201];

int findParent(int a)
{
    if (a == parent[a])
        return a;
    return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    parent[a] = b;
}

void Solve()
{
    scanf("%d%d", &N, &M);

    for (int i = 1; i <= N; ++i)
        parent[i] = i;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            scanf("%d", &temp);
            if (temp)
                unionParent(i, j);
        }

    // * starting point
    scanf("%d", &course[0]);

    for (int i = 1; i < M; ++i)
    {
        scanf("%d", &course[i]);
        if (findParent(course[i - 1]) != findParent(course[i]))
        {
            printf("NO");
            return;
        }
    }
    printf("YES");
}

int main()
{
    Solve();
}
