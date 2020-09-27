#include <bits/stdc++.h>
using namespace std;

int N;
int total;
int line[16];

bool check(int i)
{
    for (int j = 1; j <= i; ++j)
        if (line[i] == line[j] || abs(line[i] - line[j]) == (i - j))
            return false;
    return true;
}

void placeQueen(int index)
{
    if (index == N + 1)
        total++;
    else
    {
        for (int i = 1; i <= N; ++i)
        {
            line[index] = i;
            if (check(index))
                placeQueen(index + 1);
        }
    }
}

int main()
{
    scanf("%d", &N);

    placeQueen(1);

    printf("%d", total);
}