#include <bits/stdc++.h>
using namespace std;

int N, temp, MAP[21][21];
bool visited[21][21];
const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};

int dist;
vector<pair<int, int>> eatableList;

int sY, sX, sSize, sExp;
int answer;

void Input()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
        {
            scanf("%d", &temp);
            if (temp == 9)
            {
                sY = i;
                sX = j;
                MAP[i][j] = 0;
            }
            else
                MAP[i][j] = temp;
        }
}

void sharkSizeUp()
{
    sExp = 0;
    sSize++;
}

void eat()
{
    // * find best fish to eat
    int minY = eatableList[0].first;
    int minX = eatableList[0].second;
    for (int i = 1; i < eatableList.size(); ++i)
    {
        int ny = eatableList[i].first;
        int nx = eatableList[i].second;
        if (ny < minY || (ny == minY && nx < minX))
        {
            minY = ny;
            minX = nx;
        }
    }

    // * shark - move
    answer += dist;
    sY = minY;
    sX = minX;

    // * shark - eat fish
    MAP[minY][minX] = 0;
    if (++sExp == sSize)
        sharkSizeUp();
}

bool searchFishToEat()
{
    memset(visited, 0, sizeof(visited));
    dist = 100;
    eatableList.clear();

    // * moveCnt, sY, sX
    queue<pair<int, pair<int, int>>> Q;

    visited[sY][sX] = true;
    Q.push(make_pair(0, make_pair(sY, sX)));

    while (!Q.empty())
    {
        int moveCnt = Q.front().first;
        int y = Q.front().second.first;
        int x = Q.front().second.second;
        Q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny >= 1 && ny <= N && nx >= 1 && nx <= N)
                if (!visited[ny][nx])
                {
                    visited[ny][nx] = true;

                    // * can eat
                    if (MAP[ny][nx] && MAP[ny][nx] < sSize)
                    {
                        if (eatableList.empty() || (dist != 100 && dist >= moveCnt + 1))
                        {
                            dist = moveCnt + 1;
                            eatableList.push_back(make_pair(ny, nx));
                        }
                    }
                    // * can't eat - same size
                    else if (MAP[ny][nx] == sSize)
                        Q.push(make_pair(moveCnt + 1, make_pair(ny, nx)));
                    // * empty
                    else if (!MAP[ny][nx])
                        Q.push(make_pair(moveCnt + 1, make_pair(ny, nx)));
                }
        }
    }

    if (!eatableList.empty())
        return true;
    return false;
}

void Solve()
{
    sSize = 2;

    while (searchFishToEat())
    {
        eat();
    }

    printf("%d", answer);
}

int main()
{
    Input();
    Solve();
}
