#include <bits/stdc++.h>
using namespace std;

int N;
int day[1001];
pair<int, int> ar[1001];

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        cin >> ar[i].first >> ar[i].second;

    sort(&ar[0], &ar[N], compare);

    for (int i = 0; i < N; ++i)
    {
        if (day[ar[i].first] == 0)
            day[ar[i].first] = ar[i].second;
        else
        {
            int index = ar[i].first;
            while (day[--index])
                ;
            if (index != 0)
                day[index] = ar[i].second;
        }
    }

    int result = 0;
    for (int i = 1; i < 1001; ++i)
        result += day[i];
    cout << result;
}
