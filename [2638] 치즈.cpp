#include <bits/stdc++.h>
using namespace std;

int N, M;
int meltingTime, remainingCnt;
int board[103][103], airCnt[103][103];
bool visited[103][103];

const int dy[4] = {0, 0, 1, -1};
const int dx[4] = {1, -1, 0, 0};

void Input()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
        {
            scanf("%d", &board[i][j]);
            if (board[i][j])
                remainingCnt++;
        }
}

void findEdgeDFS(int y, int x)
{
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny <= N + 1 && nx >= 0 && nx <= M + 1)
            if (!visited[ny][nx])
            {
                if (board[ny][nx] == 0)
                {
                    visited[ny][nx] = true;
                    findEdgeDFS(ny, nx);
                }
                else
                {
                    // * cheese -> airCnt ++
                    airCnt[ny][nx]++;
                }
            }
    }
}

void melt()
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (airCnt[i][j] >= 2)
            {
                board[i][j] = 0;
                remainingCnt--;
            }
}

bool edgeMelting()
{
    meltingTime++;
    memset(visited, 0, sizeof(visited));
    memset(airCnt, 0, sizeof(airCnt));

    findEdgeDFS(0, 0);
    melt();

    if (remainingCnt <= 0)
        return false;
    return true;
}

void Solve()
{
    while (edgeMelting())
    {
    }

    printf("%d", meltingTime);
}

int main()
{
    Input();
    Solve();
}
