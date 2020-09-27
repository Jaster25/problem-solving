#include <bits/stdc++.h>
using namespace std;

int N;
int answer;
vector<int> W;

void Input()
{
    scanf("%d", &N);
    int a;
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &a);
        W.push_back(a);
    }
}

void Solve()
{
    sort(W.begin(), W.end());

    for (auto i : W)
    {
        if (i > answer + 1)
            break;
        answer += i;
    }

    printf("%d", answer+1);
}

int main()
{

    Input();
    Solve();
}
