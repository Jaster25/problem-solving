#include <bits/stdc++.h>
using namespace std;

int N, M;
int meltingTime, remainingCnt;
int board[103][103];
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

void findEdgeThenMeltDFS(int y, int x)
{
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny <= N + 1 && nx >= 0 && nx <= M + 1)
            if (!visited[ny][nx])
            {
                visited[ny][nx] = true;

                if (board[ny][nx] == 0)
                    findEdgeThenMeltDFS(ny, nx);
                // * cheese -> melt
                else
                {
                    board[ny][nx] = 0;
                    remainingCnt--;
                }
            }
    }
}

bool edgeMelting()
{
    meltingTime++;
    memset(visited, 0, sizeof(visited));

    int beforeMeltCnt = remainingCnt;
    findEdgeThenMeltDFS(0, 0);

    if (remainingCnt == 0)
    {
        remainingCnt = beforeMeltCnt;
        return false;
    }
    return true;
}

void Solve()
{
    while (edgeMelting())
    {
    }

    printf("%d\n%d", meltingTime, remainingCnt);
}

int main()
{
    Input();
    Solve();
}
