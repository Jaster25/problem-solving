#include <bits/stdc++.h>
using namespace std;

int T;
int field[51][51];
int N, M, K;
int cnt;

void dfs(int y, int x)
{
    int dy[4] = {1, -1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny >= 0 && ny < N && nx >= 0 && nx < M)
            if (field[ny][nx] == 1)
            {
                field[ny][nx] = 2;
                dfs(ny, nx);
            }
    }
}

int main()
{
    scanf("%d", &T);

    while (T--)
    {
        cnt = 0;
        memset(field, 0, sizeof(field));

        scanf("%d%d%d", &N, &M, &K);

        int y, x;
        for (int i = 0; i < K; ++i)
        {
            scanf("%d%d", &y, &x);
            field[y][x] = 1;
        }

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (field[i][j] == 1)
                {
                    dfs(i, j);
                    cnt++;
                }

        printf("%d\n", cnt);
    }
}