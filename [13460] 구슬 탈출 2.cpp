#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int y, x;
} Bead;

typedef struct
{
    int cnt, ry, rx, by, bx;
} Node;

Bead R, B, O;
queue<Node> Q;

int N, M, answer;
char board[12][12], temp;
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};
bool isEscapable, visited[12][12][12][12];

void Input()
{
    scanf("%d%d", &N, &M);
    getchar();
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= M; ++j)
        {
            scanf("%c", &temp);
            if (temp == 'R')
            {
                board[i][j] = '.';
                R.y = i;
                R.x = j;
            }
            else if (temp == 'B')
            {
                board[i][j] = '.';
                B.y = i;
                B.x = j;
            }
            else if (temp == 'O')
            {
                board[i][j] = 'O';
                O.y = i;
                O.x = j;
            }
            else
                board[i][j] = temp;
        }
        getchar();
    }
}

void Solve()
{
    Node start = {0, R.y, R.x, B.y, B.x};
    Q.push(start);
    visited[R.y][R.x][B.y][B.x] = true;

    while (!Q.empty())
    {
        int cnt = Q.front().cnt;
        int ry = Q.front().ry;
        int rx = Q.front().rx;
        int by = Q.front().by;
        int bx = Q.front().bx;
        Q.pop();

        // * end conditions
        if (cnt > 10)
            break;

        if (ry == O.y && rx == O.x)
        {
            isEscapable = true;
            answer = cnt;
            break;
        }

        // * 4 dir
        for (int i = 0; i < 4; ++i)
        {
            int nry = ry + dy[i];
            int nrx = rx + dx[i];
            int nby = by + dy[i];
            int nbx = bx + dx[i];

            // * red ball move
            while (1)
            {
                if (board[nry][nrx] == '#')
                {
                    nry -= dy[i];
                    nrx -= dx[i];
                    break;
                }
                if (board[nry][nrx] == 'O')
                    break;
                nry += dy[i];
                nrx += dx[i];
            }
            // * blue ball move
            while (1)
            {
                if (board[nby][nbx] == '#')
                {
                    nby -= dy[i];
                    nbx -= dx[i];
                    break;
                }
                if (board[nby][nbx] == 'O')
                    break;
                nby += dy[i];
                nbx += dx[i];
            }

            // * blue == O
            if (board[nby][nbx] == 'O')
                continue;
            // * red & blue in same position
            if (nrx == nbx && nry == nby)
            {
                switch (i)
                {
                // * up down left right
                case 0:
                    if (ry > by)
                        nry++;
                    else
                        nby++;
                    break;
                case 1:
                    if (ry > by)
                        nby--;
                    else
                        nry--;
                    break;
                case 2:
                    if (rx > bx)
                        nrx++;
                    else
                        nbx++;
                    break;
                case 3:
                    if (rx > bx)
                        nbx--;
                    else
                        nrx--;
                    break;
                }
            }

            if (visited[nry][nrx][nby][nbx])
                continue;
            Node next = {cnt + 1, nry, nrx, nby, nbx};
            Q.push(next);
            visited[nry][nrx][nby][nbx] = true;
        }
    }

    if (isEscapable)
        printf("%d", answer);
    else
        printf("-1");
}

int main()
{
    Input();
    Solve();
}
