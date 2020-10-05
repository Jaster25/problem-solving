#include <bits/stdc++.h>
using namespace std;

int N, M, answer;
vector<int> employee[1001];
int work[1001];
bool visited[1001];

void Input()
{
    scanf("%d%d", &N, &M);

    int num, temp;
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", &num);
        for (int j = 0; j < num; ++j)
        {
            scanf("%d", &temp);
            employee[i].push_back(temp);
        }
    }
}

bool DFS(int e)
{
    for (int i = 0; i < employee[e].size(); ++i)
    {
        int w = employee[e][i];

        if (visited[w])
            continue;
        visited[w] = true;

        if (work[w] == 0 || DFS(work[w]))
        {
            work[w] = e;
            return true;
        }
    }
    return false;
}

void Solve()
{
    for (int i = 1; i <= N; ++i)
    {
        memset(visited, 0, sizeof(visited));
        if (DFS(i))
            answer++;
    }

    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}
