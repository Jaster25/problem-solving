#include <bits/stdc++.h>
using namespace std;

int h, w, answer;
char MAP[103][103];
bool key[26];
bool visited[103][103];
queue<pair<int, int>> door[26];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void Input()
{
    scanf("%d%d", &h, &w);
    getchar();

    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
            scanf("%c", &MAP[i][j]);
        getchar();
    }

    string stringKey;
    cin >> stringKey;
    for (int i = 0; i < stringKey.length(); i++)
    {
        if (stringKey[i] == '0')
            return;
        key[stringKey[i] - 'a'] = true;
    }
}

void dfs(int y, int x)
{
    for (int i = 0; i < 4; ++i)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny <= h + 1 && nx >= 0 && nx <= w + 1)
        {
            if (MAP[ny][nx] != '*' && !visited[ny][nx])
            {
                visited[ny][nx] = true;

                if (MAP[ny][nx] == '.')
                {
                    dfs(ny, nx);
                }
                else if (MAP[ny][nx] >= 'a' && MAP[ny][nx] <= 'z')
                {
                    key[MAP[ny][nx] - 'a'] = true;

                    while (!door[MAP[ny][nx] - 'a'].empty())
                    {
                        int doorY = door[MAP[ny][nx] - 'a'].front().first;
                        int doorX = door[MAP[ny][nx] - 'a'].front().second;
                        door[MAP[ny][nx] - 'a'].pop();

                        dfs(doorY, doorX);
                    }

                    dfs(ny, nx);
                }
                else if (MAP[ny][nx] >= 'A' && MAP[ny][nx] <= 'Z')
                {
                    if (key[MAP[ny][nx] - 'A'])
                        dfs(ny, nx);
                    else
                        door[MAP[ny][nx] - 'A'].push(make_pair(ny, nx));
                }
                else if (MAP[ny][nx] == '$')
                {
                    answer++;
                    MAP[ny][nx] = '.';
                    dfs(ny, nx);
                }
            }
        }
    }
}

void Solve()
{
    visited[0][0] = true;
    dfs(0, 0);

    printf("%d\n", answer);
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    while (T--)
    {
        answer = 0;
        fill(&MAP[0][0], &MAP[102][102], '.');
        memset(key, false, sizeof(key));
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < 26; ++i)
            while (!door[i].empty())
                door[i].pop();

        Input();
        Solve();
    }
}
