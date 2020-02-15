#include <bits/stdc++.h>
using namespace std;

int N;
vector<char> tree[27];

void preOrder(int v)
{
    printf("%c", v + 'A');
    if (!tree[v].empty() && tree[v][0] != '.')
        preOrder(tree[v][0] - 'A');
    if (!tree[v].empty() && tree[v][1] != '.')
        preOrder(tree[v][1] - 'A');
};

void inOrder(int v)
{
    if (!tree[v].empty() && tree[v][0] != '.')
        inOrder(tree[v][0] - 'A');
    printf("%c", v + 'A');
    if (!tree[v].empty() && tree[v][1] != '.')
        inOrder(tree[v][1] - 'A');
};

void postOrder(int v)
{
    if (!tree[v].empty() && tree[v][0] != '.')
        postOrder(tree[v][0] - 'A');
    if (!tree[v].empty() && tree[v][1] != '.')
        postOrder(tree[v][1] - 'A');
    printf("%c", v + 'A');
};

int main()
{
    scanf("%d", &N);
    getchar();

    char p, l, r;
    for (int i = 0; i < N; ++i)
    {
        scanf("%c %c %c", &p, &l, &r);
        getchar();
        tree[p - 'A'].push_back(l);
        tree[p - 'A'].push_back(r);
    }

    preOrder(0);
    printf("\n");
    inOrder(0);
    printf("\n");
    postOrder(0);
}
