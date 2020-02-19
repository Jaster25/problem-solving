#include <bits/stdc++.h>
#define MAX 32001
using namespace std;

int N, M;
vector<int> student[MAX];
int inDegree[MAX];
bool visited[MAX];
queue<int> Q;

void topologicalSort()
{
    for (int i = 1; i <= N; ++i)
        if (inDegree[i] == 0)
            Q.push(i);

    while (!Q.empty())
    {
        int popped = Q.front();
        printf("%d ", popped);
        visited[popped] = true;
        Q.pop();

        for (auto connect : student[popped])
        {
            if (--inDegree[connect] == 0)
                Q.push(connect);
        }
    }
}

int main()
{
    scanf("%d%d", &N, &M);

    int a, b;
    for (int i = 0; i < M; ++i)
    {
        scanf("%d%d", &a, &b);
        student[a].push_back(b);
        inDegree[b]++;
    }

    topologicalSort();

    for (int i = 1; i <= N; ++i)
        if (!visited[i])
            printf("%d ", i);
}