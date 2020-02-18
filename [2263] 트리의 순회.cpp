#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> inOrder;
vector<int> postOrder;
vector<int> preOrder;

void rc(int startIn, int endIn, int startPost, int endPost)
{
    if (startIn > endIn || startPost > endPost)
        return;

    int root = postOrder[endPost];
    preOrder.push_back(root);

    int index = startIn;
    while (inOrder[index] != root)
        index++;

    // ¿ÞÂÊ °³¼ö
    int count = index - startIn;

    // ¿ÞÂÊ
    rc(startIn, index - 1, startPost, startPost + count - 1);
    // ¿À¸¥ÂÊ
    rc(index + 1, endIn, startPost + count, endPost - 1);
}

int main()
{
    scanf("%d", &N);

    int v;
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &v);
        inOrder.push_back(v);
    }
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &v);
        postOrder.push_back(v);
    }

    rc(0, N - 1, 0, N - 1);

    for (auto num : preOrder)
        printf("%d ", num);
}
