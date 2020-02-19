#include <bits/stdc++.h>
using namespace std;

int N, rootNode, removeNode;
int cnt;
vector<int> tree[51];

void Traversal(int index)
{
    if (tree[index].size() == 0 || tree[index].size() == 1 && tree[index][0] == removeNode)
        cnt++;
    for (auto n : tree[index])
        if (n != removeNode)
            Traversal(n);
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        int p;
        scanf("%d", &p);
        if (p == -1)
            rootNode = i;
        else
            tree[p].push_back(i);
    }
    scanf("%d", &removeNode);

    if (removeNode != rootNode)
        Traversal(rootNode);

    printf("%d", cnt);
}