#include <bits/stdc++.h>
using namespace std;

char board[21][21];
bool visited[26];
int R, C;
int answer = 0;

int dirY[4] = {0, 0, 1, -1};
int dirX[4] = {1, -1, 0, 0};

void dfs(int y, int x, int count)
{
    answer = max(answer, count);

    for (int i = 0; i < 4; ++i)
    {
        int nextY = y + dirY[i];
        int nextX = x + dirX[i];

        if (nextY >= 0 && nextY < R && nextX >= 0 && nextX < C)
        {
            if (!visited[board[nextY][nextX] - 'A'])
            {
                visited[board[nextY][nextX] - 'A'] = true;
                dfs(nextY, nextX, count + 1);
                visited[board[nextY][nextX] - 'A'] = false;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &R, &C);
    getchar();

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
            scanf("%c", &board[i][j]);
        getchar();
    }

    visited[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);

    printf("%d", answer);
}
