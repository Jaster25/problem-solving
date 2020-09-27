#include <bits/stdc++.h>
using namespace std;

int N, M, year;
int iceberg[301][301];
bool visited[301][301];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void Input()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            scanf("%d", &iceberg[i][j]);
}

void dfs_search(int y, int x)
{

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 1 && ny <= N && nx >= 1 && nx <= M)
        {
            if (iceberg[ny][nx] > 0 && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                dfs_search(ny, nx);
            }
        }
    }
}

int countIceberg()
{
    memset(visited, false, sizeof(visited));

    int cnt = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (iceberg[i][j] > 0 && !visited[i][j])
            {
                cnt++;
                visited[i][j] = true;
                dfs_search(i, j);
            }

    return cnt;
}

int countSea(int y, int x)
{
    int cnt = 0;
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 1 && ny <= N && nx >= 1 && nx <= M)
            if (iceberg[ny][nx] == 0)
                cnt++;
    }

    return cnt;
}

void bfs_melt()
{
    queue<pair<pair<int, int>, int>> Q;

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (iceberg[i][j] != 0)
                Q.push({{i, j}, countSea(i, j)});

    while (!Q.empty())
    {
        int y = Q.front().first.first;
        int x = Q.front().first.second;
        int seaCnt = Q.front().second;
        Q.pop();

        iceberg[y][x] -= seaCnt;
        if (iceberg[y][x] < 0)
            iceberg[y][x] = 0;
    }
}

void Solve()
{
    int mass;
    while (1 == (mass = countIceberg()))
    {
        bfs_melt();
        year++;
    }

    if (mass == 0)
        year = 0;

    printf("%d", year);
}

int main()
{
    Input();
    Solve();
}