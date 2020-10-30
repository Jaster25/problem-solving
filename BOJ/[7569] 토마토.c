#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int z, y, x;
} Position;

int day;
int M, N, H;
int tomato[101][101][101];
int visited[101][101][101];
int isAlreadyRipen = 1;

// * 1: 익음, 0: 안익음, -1:빔

void Input()
{
    scanf("%d%d%d", &M, &N, &H);
    for (int k = 1; k <= H; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
            {
                scanf("%d", &tomato[k][i][j]);
                if (tomato[k][i][j] == 0)
                    isAlreadyRipen = 0;
            }
}

const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {-1, 1, 0, 0};

void BFS()
{
    Position q[1000001];
    int front = 0;
    int rear = 0;

    for (int k = 1; k <= H; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                if (tomato[k][i][j] == 1)
                {
                    Position newQ = {k, i, j};
                    q[++rear] = newQ;
                    visited[k][i][j] = 1;
                }

    while (front != rear)
    {
        int z = q[++front].z;
        int y = q[front].y;
        int x = q[front].x;

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 1 && ny <= N && nx >= 1 && nx <= M)
                if (!visited[z][ny][nx] && tomato[z][ny][nx] == 0)
                {
                    tomato[z][ny][nx] = 1;
                    Position newQ = {z, ny, nx};
                    q[++rear] = newQ;
                    visited[z][ny][nx] = visited[z][y][x] + 1;
                }
        }

        for (int i = 0; i < 2; i++)
        {
            int nz = z + 1;
            if (i == 1)
                nz = z - 1;

            if (nz >= 1 && nz <= H)
                if (!visited[nz][y][x] && tomato[nz][y][x] == 0)
                {
                    tomato[nz][y][x] = 1;
                    Position newQ = {nz, y, x};
                    q[++rear] = newQ;
                    visited[nz][y][x] = visited[z][y][x] + 1;
                }
        }
    }
}

int check()
{
    for (int k = 1; k <= H; ++k)
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
            {
                if (visited[k][i][j] > day)
                    day = visited[k][i][j];
                if (tomato[k][i][j] == 0)
                    return 0;
            }

    day--;
    return 1;
}

void Solve()
{
    if (isAlreadyRipen)
        printf("0");
    else
    {
        BFS();

        if (check())
            printf("%d", day);
        else
            printf("-1");
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}
