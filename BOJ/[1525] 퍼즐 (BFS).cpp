#include <bits/stdc++.h>
using namespace std;

int start;
map<int, int> MAP;

void Input()
{
    int temp;
    for (int i = 1; i <= 9; ++i)
    {
        scanf("%d", &temp);
        if (temp == 0)
            start = start * 10 + 9;
        else
            start = start * 10 + temp;
    }
}

bool check(int num)
{
    while (num >= 10)
    {
        if (num % 10 < (num / 10 % 10))
            return false;
        num /= 10;
    }
    return true;
}

int move(int num, int indexA, int indexB)
{
    int numA = num / (int)pow(10, 9 - indexA) % 10;
    int numB = num / (int)pow(10, 9 - indexB) % 10;

    int moved = num - numA * (int)pow(10, 9 - indexA) - numB * (int)pow(10, 9 - indexB);
    moved += numB * (int)pow(10, 9 - indexA) + numA * (int)pow(10, 9 - indexB);

    return moved;
}

void bfs()
{
    queue<int> Q;
    MAP[start] = 1;
    Q.push(start);

    while (!Q.empty())
    {
        int num = Q.front();
        Q.pop();

        if (check(num))
        {
            printf("%d", MAP[num] - 1);
            return;
        }

        // * index: 0's position (1~9)
        int index = 9, temp = num;
        while (temp >= 10)
        {
            if (temp % 10 == 9)
                break;
            temp /= 10;
            index--;
        }

        int moved;
        // * up
        if (index > 3)
        {
            moved = move(num, index, index - 3);
            if (!MAP[moved])
            {
                MAP[moved] = MAP[num] + 1;
                Q.push(moved);
            }
        }
        // * down
        if (index < 7)
        {
            moved = move(num, index, index + 3);
            if (!MAP[moved])
            {
                MAP[moved] = MAP[num] + 1;
                Q.push(moved);
            }
        }
        // * left
        if (index != 1 && index != 4 && index != 7)
        {
            moved = move(num, index, index - 1);
            if (!MAP[moved])
            {
                MAP[moved] = MAP[num] + 1;
                Q.push(moved);
            }
        }
        // * right
        if (index != 3 && index != 6 && index != 9)
        {
            moved = move(num, index, index + 1);
            if (!MAP[moved])
            {
                MAP[moved] = MAP[num] + 1;
                Q.push(moved);
            }
        }
    }

    printf("-1");
}

void Solve()
{
    bfs();
}

int main()
{
    Input();
    Solve();
}
