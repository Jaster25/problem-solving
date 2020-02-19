#include <bits/stdc++.h>
#define MAX 32001
using namespace std;

vector<int> compare[MAX];
int inDegree[MAX];
bool visited[MAX];
priority_queue<int, vector<int>, greater<int>> Q;
int N, M, A, B;

void topologicalSort()
{
    for (int i = 1; i <= N; ++i)
        if (inDegree[i] == 0)
            Q.push(i);

    while (!Q.empty())
    {
        int popped = Q.top();
        visited[popped] = true;
        printf("%d ", popped);
        Q.pop();

        for (auto connect : compare[popped])
            if (--inDegree[connect] == 0)
                Q.push(connect);
    }
}

int main()
{
    scanf("%d%d", &N, &M);
    while (M--)
    {
        scanf("%d%d", &A, &B);
        compare[A].push_back(B);
        inDegree[B]++;
    }

    topologicalSort();

    for (int i = 1; i <= N; ++i)
        if (!visited[i])
            printf("%d ", i);
}