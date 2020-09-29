#include <bits/stdc++.h>
using namespace std;

int n, temp;
int k1_cnt, k2_cnt;
queue<int> k1, k2;
int gameTime;

void Input()
{
    scanf("%d", &n);
    scanf("%d", &k1_cnt);
    for (int i = 0; i < k1_cnt; ++i)
    {
        scanf("%d", &temp);
        k1.push(temp);
    }

    scanf("%d", &k2_cnt);
    for (int i = 0; i < k2_cnt; ++i)
    {
        scanf("%d", &temp);
        k2.push(temp);
    }
}

void Solve()
{
    while (k1.size() && k2.size() && gameTime < 1000)
    {
        if (k1.front() > k2.front())
        {
            k1.push(k2.front());
            k1.push(k1.front());
            k2.pop();
            k1.pop();
        }
        else
        {
            k2.push(k1.front());
            k2.push(k2.front());
            k1.pop();
            k2.pop();
        }
        gameTime++;
    }

    if (k2.size() == 0)
        printf("%d %d", gameTime, 1);
    else if (k1.size() == 0)
        printf("%d %d", gameTime, 2);
    else
        printf("-1");
}

int main()
{
    Input();
    Solve();
}
