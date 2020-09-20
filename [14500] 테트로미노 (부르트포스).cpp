#include <bits/stdc++.h>
using namespace std;

int N, M;
int currentSum, maxSum;
int MAP[501][501];
bool visited[501][501];

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

void Input()
{
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            scanf("%d", &MAP[i][j]);
}

void dfs(int cnt, int y, int x)
{
    if (cnt == 4)
    {
        maxSum = max(maxSum, currentSum);
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 1 && ny <= N && nx >= 1 && nx <= M)
            if (!visited[ny][nx])
            {
                visited[ny][nx] = true;
                currentSum += MAP[ny][nx];

                dfs(cnt + 1, ny, nx);

                visited[ny][nx] = false;
                currentSum -= MAP[ny][nx];
            }
    }
}

bool checkBoundary(int ny, int nx)
{
    if (ny >= 1 && ny <= N && nx >= 1 && nx <= M)
        return true;
    return false;
}

void dfs2(int y, int x)
{
    int currentSum;

    // * で
    if (checkBoundary(y - 1, x) && checkBoundary(y, x - 1) && checkBoundary(y, x + 1))
    {
        currentSum = MAP[y][x];
        currentSum += MAP[y - 1][x];
        currentSum += MAP[y][x - 1];
        currentSum += MAP[y][x + 1];
        maxSum = max(currentSum, maxSum);
    }

    // * ぬ
    if (checkBoundary(y + 1, x) && checkBoundary(y, x - 1) && checkBoundary(y, x + 1))
    {
        currentSum = MAP[y][x];
        currentSum += MAP[y + 1][x];
        currentSum += MAP[y][x - 1];
        currentSum += MAP[y][x + 1];
        maxSum = max(currentSum, maxSum);
    }

    // * た
    if (checkBoundary(y - 1, x) && checkBoundary(y + 1, x) && checkBoundary(y, x + 1))
    {
        currentSum = MAP[y][x];
        currentSum += MAP[y - 1][x];
        currentSum += MAP[y + 1][x];
        currentSum += MAP[y][x + 1];
        maxSum = max(currentSum, maxSum);
    }

    // * っ
    if (checkBoundary(y - 1, x) && checkBoundary(y + 1, x) && checkBoundary(y, x - 1))
    {
        currentSum = MAP[y][x];
        currentSum += MAP[y - 1][x];
        currentSum += MAP[y + 1][x];
        currentSum += MAP[y][x - 1];
        maxSum = max(currentSum, maxSum);
    }
}

void Solve()
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
        {
            // *
            visited[i][j] = true;
            currentSum += MAP[i][j];

            dfs(1, i, j);

            visited[i][j] = false;
            currentSum -= MAP[i][j];

            // !
            dfs2(i, j);
        }

    printf("%d", maxSum);
}

int main()
{
    Input();
    Solve();
}
