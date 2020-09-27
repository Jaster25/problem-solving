#include <bits/stdc++.h>
using namespace std;

int N;
int MAP1[101][101];
int MAP2[101][101];
bool visited[101][101];
int cnt1, cnt2;

// * MAP2 for color-weakness person
// * R: 1   1
// * G: 2   1(MAP2)
// * B: 3   3

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

void Input()
{
    scanf("%d", &N);
    getchar();

    char temp;
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            scanf("%c", &temp);
            switch (temp)
            {
            case 'R':
                MAP1[i][j] = 1;
                MAP2[i][j] = 1;
                break;
            case 'G':
                MAP1[i][j] = 2;
                MAP2[i][j] = 1;
                break;
            case 'B':
                MAP1[i][j] = 3;
                MAP2[i][j] = 3;
                break;
            }
        }
        getchar();
    }
}

void dfs1(int y, int x)
{
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 1 && ny <= N && nx >= 1 && ny <= N)
            if (!visited[ny][nx])
                if (MAP1[y][x] == MAP1[ny][nx])
                {
                    visited[ny][nx] = true;
                    dfs1(ny, nx);
                }
    }
}

void dfs2(int y, int x)
{
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 1 && ny <= N && nx >= 1 && ny <= N)
            if (!visited[ny][nx])
                if (MAP2[y][x] == MAP2[ny][nx])
                {
                    visited[ny][nx] = true;
                    dfs2(ny, nx);
                }
    }
}

void Solve()
{
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (!visited[i][j])
            {
                cnt1++;
                visited[i][j] = true;
                dfs1(i, j);
            }

    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            if (!visited[i][j])
            {
                cnt2++;
                visited[i][j] = true;
                dfs2(i, j);
            }

    printf("%d %d", cnt1, cnt2);
}

int main()
{
    Input();
    Solve();
}
