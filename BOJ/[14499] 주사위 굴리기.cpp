#include <bits/stdc++.h>
using namespace std;

int N, M;
int x, y, k;
int MAP[21][21];

int dice[7];
queue<int> rollSequence;

const int dy[5] = {0, 0, 0, -1, 1};
const int dx[5] = {0, 1, -1, 0, 0};

void Input()
{
    scanf("%d%d%d%d%d", &N, &M, &y, &x, &k);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            scanf("%d", &MAP[i][j]);

    int temp;
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &temp);
        rollSequence.push(temp);
    }
}

bool check(int d)
{
    int ny = y + dy[d];
    int nx = x + dx[d];
    if (ny >= 0 && ny < N && nx >= 0 && nx < M)
        return true;
    return false;
}

bool rollTheDice(int d)
{
    if (!check(d))
        return false;

    int tempDice[7];
    for (int i = 1; i <= 6; ++i)
        tempDice[i] = dice[i];

    if (d == 1)
    {
        dice[1] = tempDice[4];
        dice[3] = tempDice[1];
        dice[4] = tempDice[6];
        dice[6] = tempDice[3];
    }
    else if (d == 2)
    {
        dice[1] = tempDice[3];
        dice[3] = tempDice[6];
        dice[4] = tempDice[1];
        dice[6] = tempDice[4];
    }
    else if (d == 3)
    {
        dice[1] = tempDice[5];
        dice[2] = tempDice[1];
        dice[5] = tempDice[6];
        dice[6] = tempDice[2];
    }
    else if (d == 4)
    {
        dice[1] = tempDice[2];
        dice[2] = tempDice[6];
        dice[5] = tempDice[1];
        dice[6] = tempDice[5];
    }

    return true;
}

void Solve()
{
    while (!rollSequence.empty())
    {
        int d = rollSequence.front();
        rollSequence.pop();

        if (rollTheDice(d))
        {
            y += dy[d];
            x += dx[d];
            if (MAP[y][x] == 0)
                MAP[y][x] = dice[6];
            else
            {
                dice[6] = MAP[y][x];
                MAP[y][x] = 0;
            }

            printf("%d\n", dice[1]);
        }
    }
}

int main()
{
    Input();
    Solve();
}
