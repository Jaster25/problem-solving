#include <bits/stdc++.h>
using namespace std;

int N, temp;
priority_queue<int> maxPQ, minPQ;

void Solve()
{
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &temp);

        if (maxPQ.size() > minPQ.size())
            minPQ.push(-temp);
        else
            maxPQ.push(temp);

        if (maxPQ.size() && minPQ.size())
            if (maxPQ.top() > -minPQ.top())
            {
                int a = maxPQ.top();
                int b = -minPQ.top();
                maxPQ.pop();
                minPQ.pop();
                maxPQ.push(b);
                minPQ.push(-a);
            }

        printf("%d\n", maxPQ.top());
    }
}

int main()
{
    Solve();
}
