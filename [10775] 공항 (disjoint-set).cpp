#include <bits/stdc++.h>
using namespace std;

int g, p, answer;
int parent[100001];

int findParent(int a)
{
    if (a == parent[a])
        return a;
    return parent[a] = findParent(parent[a]);
}

void Solve()
{
    scanf("%d%d", &g, &p);

    for (int i = 1; i <= g; ++i)
        parent[i] = i;

    int temp, tempP;
    for (int i = 1; i <= p; ++i)
    {
        scanf("%d", &temp);
        tempP = findParent(temp);
        if (!tempP)
            break;
        parent[tempP]--;
        answer++;
    }

    printf("%d", answer);
}

int main()
{
    Solve();
}
