#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N, M, answer;
int a, b;
pii student[1001];
bool isChosen[1001];

bool cmp(pii a, pii b)
{
    if (a.second < b.second)
        return true;
    else if (a.second == b.second && a.first < b.first)
        return true;
    return false;
}

void Input()
{
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i)
    {
        scanf("%d%d", &a, &b);
        student[i] = make_pair(a, b);
    }
}

void Solve()
{
    answer = 0;
    memset(isChosen, 0, sizeof(isChosen));
    sort(student, student + M, cmp);

    for (int i = 0; i < M; ++i)
        for (int j = student[i].first; j <= student[i].second; ++j)
            if (!isChosen[j])
            {
                isChosen[j] = true;
                answer++;
                break;
            }

    printf("%d\n", answer);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        Input();
        Solve();
    }
}
