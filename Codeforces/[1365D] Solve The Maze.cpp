#include <bits/stdc++.h>
using namespace std;

int n, m;
char MAP[51][51];
bool visited[51][51];

int cntG;
vector<pair<int, int>> G;
vector<pair<int, int>> B;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

void Input()
{
    scanf("%d%d", &n, &m);
    getchar();

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%1c", &MAP[i][j]);
            if (MAP[i][j] == 'G')
            {
                cntG++;
                G.push_back(make_pair(i, j));
            }
            else if (MAP[i][j] == 'B')
                B.push_back(make_pair(i, j));
        }
        getchar();
    }
}

bool BFS(int y, int x)
{
    int cnt = 0;
    if (MAP[y][x] == '#')
    {
        if (cntG == 0)
            return true;
        else
            return false;
    }

    queue<pair<int, int>> Q;
    Q.push(make_pair(y, x));
    visited[y][x] = true;

    while (!Q.empty())
    {
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 1 && ny <= n && nx >= 1 && nx <= m)
            {
                if (!visited[ny][nx] && MAP[ny][nx] != '#')
                {
                    if (MAP[ny][nx] == 'B')
                        return false;
                    if (MAP[ny][nx] == 'G')
                        cnt++;

                    visited[ny][nx] = true;
                    Q.push(make_pair(ny, nx));
                }
            }
        }
    }

    if (cnt != cntG)
        return false;
    return true;
}

void makeWall()
{
    for (int i = 0; i < B.size(); ++i)
    {
        int y = B[i].first;
        int x = B[i].second;
        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 1 && ny <= n && nx >= 1 && nx <= m)
                if (MAP[ny][nx] == '.')
                    MAP[ny][nx] = '#';
        }
    }
}

void Solve()
{
    makeWall();
    if (BFS(n, m))
        printf("YES\n");
    else
        printf("NO\n");
};

void reset()
{
    G.clear();
    B.clear();
    memset(visited, 0, sizeof(visited));
    cntG = 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    getchar();
    while (T--)
    {
        reset();
        Input();
        Solve();
    }
}
