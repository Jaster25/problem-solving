#include <bits/stdc++.h>
using namespace std;

int N, K;

int dq(int left, int right)
{
    int answer;
    while (left <= right)
    {
        int cnt = 0;
        int mid = (left + right) >> 1;
        for (int i = 1; i <= N; ++i)
            cnt += min(N, mid / i);

        if (cnt >= K)
            right = mid - 1, answer = mid;
        else
            left = mid + 1;
    }

    return answer;
}

int main()
{
    scanf("%d%d", &N, &K);
    printf("%d", dq(1, K));
}