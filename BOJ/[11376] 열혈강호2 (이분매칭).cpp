#include <bits/stdc++.h>
using namespace std;

int N, M, answer;
int work[1001];
vector<int> employee[1001];
bool visited[1001];

void Input()
{
    scanf("%d%d", &N, &M);

    int cnt, num;
    for (int i = 1; i <= N; ++i)
    {
        scanf("%d", &cnt);
        while (cnt--)
        {
            scanf("%d", &num);
            employee[i].push_back(num);
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
        for (int j = 0; j < 2; ++j)
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
