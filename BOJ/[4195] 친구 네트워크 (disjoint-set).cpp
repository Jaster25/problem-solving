#include <bits/stdc++.h>
using namespace std;

int F, peopleCnt;
int parent[200002], friendCnt[200002];
map<string, int> friendList;

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
    if (ap != bp)
    {
        parent[ap] = bp;
        friendCnt[bp] += friendCnt[ap];
        friendCnt[ap] = 1;
    }
}

void Solve()
{
    scanf("%d", &F);
    for (int i = 0; i <= 2 * F; ++i)
    {
        parent[i] = i;
        friendCnt[i] = 1;
    }

    char f1[21], f2[21];
    for (int i = 0; i < F; ++i)
    {
        scanf("%s%s", &f1, &f2);
        if (!friendList.count(f1))
            friendList[f1] = peopleCnt++;
        if (!friendList.count(f2))
            friendList[f2] = peopleCnt++;

        unionParent(friendList[f1], friendList[f2]);
        printf("%d\n", friendCnt[parent[friendList[f2]]]);
    }
}

void Reset()
{
    peopleCnt = 1;
    memset(parent, 0, sizeof(parent));
    memset(friendCnt, 0, sizeof(friendCnt));
    friendList.clear();
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        Reset();
        Solve();
    }
}
