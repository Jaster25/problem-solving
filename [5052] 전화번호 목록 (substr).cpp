#include <bits/stdc++.h>
using namespace std;

int N;
string str[10000];

void Input()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        cin >> str[i];
}

void Solve()
{
    bool answer = true;

    sort(str, str + N);
    for (int i = 1; i < N; ++i)
        if (str[i - 1].compare(str[i].substr(0, str[i - 1].size())) == 0)
            answer = false;

    if (answer)
        puts("YES");
    else
        puts("NO");
}

int main()
{
    int TC;
    scanf("%d", &TC);
    while (TC--)
    {
        for (int i = 0; i < N; ++i)
            str[i].clear();
        Input();
        Solve();
    }
}
