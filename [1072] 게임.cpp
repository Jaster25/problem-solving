#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll X, Y, Z;
ll original;

int rf(ll left, ll right)
{
    if (original >= 99)
        return -1;

    int answer;
    int temp;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        temp = ((Y + mid) * 100) / (X + mid);

        if (original >= temp)
            left = mid + 1, answer = mid + 1;
        else
            right = mid - 1;
    }

    return answer;
}

int main()
{
    scanf("%lld%lld", &X, &Y);
    original = (Y * 100) / X;

    printf("%d", rf(0, 1000000000));
}