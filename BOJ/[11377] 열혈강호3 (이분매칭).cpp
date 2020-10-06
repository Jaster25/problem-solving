#include <bits/stdc++.h>
using namespace std;

int N, M, T, t, answer;
int work[1001];
vector<int> employee[1001];
bool visited[1001];

void Input()
{
    scanf("%d%d%d", &N, &M, &T);

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
    {
        memset(visited, 0, sizeof(visited));
        if (DFS(i))
            answer++;
    }

    for (int i = 1; i <= N; ++i)
    {
        memset(visited, 0, sizeof(visited));
        if (DFS(i))
        {
            answer++;
            t++;
        }

        if (t == T)
            break;
    }
    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}
