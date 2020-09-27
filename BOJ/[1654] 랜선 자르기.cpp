#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll K, N;
vector<ll> line;

ll findCnt(ll len)
{
    ll cnt = 0;
    for (auto i : line)
        cnt += i / len;
    return cnt;
}

ll search()
{
    ll left = 1, right = line[line.size() - 1];
    ll answer = 0;
    while (left <= right)
    {
        ll mid = (left + right) / 2;
        ll tempCnt = findCnt(mid);

        if (tempCnt >= N)
            left = mid + 1, answer = max(answer, mid);
        else
            right = mid - 1;
    }

    return answer;
}

int main()
{
    scanf("%lld%lld", &K, &N);

    ll len;
    for (int i = 0; i < K; ++i)
        scanf("%lld", &len), line.push_back(len);

    sort(line.begin(), line.end());

    printf("%lld", search());
}