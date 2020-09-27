#include <bits/stdc++.h>
using namespace std;

int N, K, L;
int board[101][101];
int answer;
bool isEnd;

queue<pair<int, int>> snake;
queue<pair<int, char>> turnInfo;

// * up right down left
int dir = 1;
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

// * board 0 : empty
// * board 1 : apple
// * board 9 : snake

void Input()
{
    scanf("%d%d", &N, &K);
    getchar();

    // * apple info
    int ay, ax;
    for (int i = 0; i < K; ++i)
    {
        scanf("%d%d", &ay, &ax);
        getchar();
        board[ay][ax] = 1;
    }

    // * snake's turn info
    int X;
    char C;
    scanf("%d", &L);
    getchar();
    for (int i = 0; i < L; ++i)
    {
        scanf("%d %c", &X, &C);
        getchar();
        turnInfo.push(make_pair(X, C));
    }
}

void snakeMove()
{
    // * snake's head
    int sy = snake.back().first;
    int sx = snake.back().second;

    // * next position
    int nsy = sy + dy[dir];
    int nsx = sx + dx[dir];

    // * end conditions
    if (nsy >= 1 && nsy <= N && nsx >= 1 && nsx <= N)
    {
        switch (board[nsy][nsx])
        {
        case 0:
            snake.push(make_pair(nsy, nsx));
            board[snake.front().first][snake.front().second] = 0;
            board[nsy][nsx] = 9;
            snake.pop();
            break;
        case 1:
            snake.push(make_pair(nsy, nsx));
            board[nsy][nsx] = 9;
            break;
        case 9:
            isEnd = true;
            return;
        }
    }
    else
    {
        isEnd = true;
        return;
    }
}

void Solve()
{
    // * initial setting
    snake.push(make_pair(1, 1));
    board[1][1] = 9;

    while (!isEnd && !turnInfo.empty())
    {
        int timeToTurn = turnInfo.front().first;

        // * move
        while (!isEnd && timeToTurn > answer)
        {
            if (!isEnd)
            {
                answer++;
                snakeMove();
            }
        }

        // * turn
        if (turnInfo.front().second == 'L')
            dir = (dir + 4 - 1) % 4;
        else
            dir = (dir + 1) % 4;
        turnInfo.pop();
    }

    while (!isEnd)
    {
        answer++;
        snakeMove();
    }

    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}
