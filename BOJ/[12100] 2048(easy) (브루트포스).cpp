#include <bits/stdc++.h>
using namespace std;

int N, maxNumber;
int board[21][21];

void Input()
{
    scanf("%d", &N);
    for (int y = 1; y <= N; ++y)
        for (int x = 1; x <= N; ++x)
            scanf("%d", &board[y][x]);
}

// 지울거
void printBoard()
{
    printf("\n");
    for (int y = 1; y <= N; ++y)
    {
        for (int x = 1; x <= N; ++x)
            printf("%d ", board[y][x]);
        printf("\n");
    }
}

// 0 상 , 1 하, 2 좌, 3 우
void shift(int dir)
{
    // step 1 : 방향대로 밀기
    // step 2 : 같은 수 합치기
    // step 3 : 방향대로 밀기

    switch (dir)
    {
    case 0:
        // step 1
        for (int x = 1; x <= N; ++x)
        {
            for (int y = 1; y < N; ++y)
            {
                if (board[y][x] == 0)
                {
                    int ny = y + 1;
                    while (ny < N && !board[ny][x])
                        ny++;
                    board[y][x] = board[ny][x];
                    board[ny][x] = 0;
                }
            }
        }
        // step 2
        for (int x = 1; x <= N; ++x)
        {
            for (int y = 1; y < N; ++y)
            {
                if (board[y][x] != 0)
                {
                    int ny = y + 1;
                    while (ny < N && !board[ny][x])
                        ny++;
                    if (board[y][x] == board[ny][x])
                    {
                        board[y][x] *= 2;
                        board[ny][x] = 0;
                    }
                }
            }
        }
        // step 3
        for (int x = 1; x <= N; ++x)
        {
            for (int y = 1; y < N; ++y)
            {
                if (board[y][x] == 0)
                {
                    int ny = y + 1;
                    while (ny < N && !board[ny][x])
                        ny++;
                    board[y][x] = board[ny][x];
                    board[ny][x] = 0;
                }
            }
        }
        break;

    case 1:
        // step 1
        for (int x = 1; x <= N; ++x)
        {
            for (int y = N; y > 1; --y)
            {
                if (board[y][x] == 0)
                {
                    int ny = y - 1;
                    while (ny > 1 && !board[ny][x])
                        ny--;
                    board[y][x] = board[ny][x];
                    board[ny][x] = 0;
                }
            }
        }
        // step 2
        for (int x = 1; x <= N; ++x)
        {
            for (int y = N; y > 1; --y)
            {
                if (board[y][x] != 0)
                {
                    int ny = y - 1;
                    while (ny > 1 && !board[ny][x])
                        ny--;
                    if (board[y][x] == board[ny][x])
                    {
                        board[y][x] *= 2;
                        board[ny][x] = 0;
                    }
                }
            }
        }
        // step 3
        for (int x = 1; x <= N; ++x)
        {
            for (int y = N; y > 1; --y)
            {
                if (board[y][x] == 0)
                {
                    int ny = y - 1;
                    while (ny > 1 && !board[ny][x])
                        ny--;
                    board[y][x] = board[ny][x];
                    board[ny][x] = 0;
                }
            }
        }
        break;

    case 2:
        // step 1
        for (int y = 1; y <= N; ++y)
        {
            for (int x = 1; x < N; ++x)
            {
                if (board[y][x] == 0)
                {
                    int nx = x + 1;
                    while (nx < N && !board[y][nx])
                        nx++;
                    board[y][x] = board[y][nx];
                    board[y][nx] = 0;
                }
            }
        }
        // step 2
        for (int y = 1; y <= N; ++y)
        {
            for (int x = 1; x < N; ++x)
            {
                if (board[y][x] != 0)
                {
                    int nx = x + 1;
                    while (nx < N && !board[y][nx])
                        nx++;
                    if (board[y][x] == board[y][nx])
                    {
                        board[y][x] *= 2;
                        board[y][nx] = 0;
                    }
                }
            }
        }
        // step 3
        for (int y = 1; y <= N; ++y)
        {
            for (int x = 1; x < N; ++x)
            {
                if (board[y][x] == 0)
                {
                    int nx = x + 1;
                    while (nx < N && !board[y][nx])
                        nx++;
                    board[y][x] = board[y][nx];
                    board[y][nx] = 0;
                }
            }
        }
        break;

    case 3:
        // step 1
        for (int y = 1; y <= N; ++y)
        {
            for (int x = N; x > 1; --x)
            {
                if (board[y][x] == 0)
                {
                    int nx = x - 1;
                    while (nx > 1 && !board[y][nx])
                        nx--;
                    board[y][x] = board[y][nx];
                    board[y][nx] = 0;
                }
            }
        }
        // step 2
        for (int y = 1; y <= N; ++y)
        {
            for (int x = N; x > 1; --x)
            {
                if (board[y][x] != 0)
                {
                    int nx = x - 1;
                    while (nx > 1 && !board[y][nx])
                        nx--;
                    if (board[y][x] == board[y][nx])
                    {
                        board[y][x] *= 2;
                        board[y][nx] = 0;
                    }
                }
            }
        }
        // step 3
        for (int y = 1; y <= N; ++y)
        {
            for (int x = N; x > 1; --x)
            {
                if (board[y][x] == 0)
                {
                    int nx = x - 1;
                    while (nx > 1 && !board[y][nx])
                        nx--;
                    board[y][x] = board[y][nx];
                    board[y][nx] = 0;
                }
            }
        }
        break;
    }
}

int findMaxInBoard()
{
    int mx = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            mx = max(mx, board[i][j]);
    return mx;
}

void dfs(int cnt)
{

    if (cnt == 5)
    {
        maxNumber = max(maxNumber, findMaxInBoard());
        return;
    }

    int copy[21][21];
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            copy[i][j] = board[i][j];

    for (int i = 0; i < 4; ++i)
    {
        shift(i);
        dfs(cnt + 1);

        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                board[i][j] = copy[i][j];
    }
}

void Solve()
{
    dfs(0);
    printf("%d", maxNumber);
}

int main()
{
    Input();
    Solve();
}
