#include <bits/stdc++.h>
using namespace std;

int N, M;
int answer;
int MAP[51][51];
bool cleaned[51][51];
int r, c, d;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void Input()
{
    scanf("%d%d", &N, &M);
    scanf("%d%d%d", &r, &c, &d);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &MAP[i][j]);
}

void DFS(int y, int x, int dir)
{
    if (MAP[y][x])
        return;

    if (!cleaned[y][x])
    {
        cleaned[y][x] = true;
        answer++;
    }

    int ny, nx;
    for (int i = 1; i <= 4; ++i)
    {
        dir = (dir + 4 - 1) % 4;
        ny = y + dy[dir];
        nx = x + dx[dir];
        if (!MAP[ny][nx] && !cleaned[ny][nx])
        {
            DFS(ny, nx, dir);
            return;
        }
    }

    ny = y + dy[(dir + 2) % 4];
    nx = x + dx[(dir + 2) % 4];
    DFS(ny, nx, dir);
}

void Solve()
{
    DFS(r, c, d);
    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}
