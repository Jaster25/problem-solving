#include <bits/stdc++.h>
using namespace std;

int N, blockCnt;
int visited[26][26];
int MAP[26][26];
int houseCnt[26 * 26];

void Input()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            scanf("%1d", &MAP[i][j]);
}

pair<int, int> findNextBlock()
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (MAP[i][j] && !visited[i][j])
                return make_pair(i, j);
    return make_pair(0, 0);
}

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
void DFS(int y, int x)
{
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 1 && ny <= N && nx >= 1 && nx <= N)
            if (MAP[ny][nx])
                if (!visited[ny][nx])
                {
                    visited[ny][nx] = blockCnt;
                    houseCnt[blockCnt]++;
                    DFS(ny, nx);
                }
    }
}

void Solve()
{
    while (findNextBlock() != make_pair(0, 0))
    {
        pair<int, int> next = findNextBlock();
        visited[next.first][next.second] = ++blockCnt;
        houseCnt[blockCnt]++;
        DFS(next.first, next.second);
    }

    sort(houseCnt + 1, houseCnt + blockCnt + 1);

    printf("%d\n", blockCnt);
    for (int i = 1; i <= blockCnt; ++i)
        printf("%d\n", houseCnt[i]);
}

int main()
{
    Input();
    Solve();
}
