#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> original;
vector<int> permutation;

void Input()
{
    scanf("%d%d", &N, &K);
}

void Solve()
{
    for (int i = 1; i <= N; ++i)
        original.push_back(i);

    int index = 0;
    while (!original.empty())
    {
        index = (index + K - 1) % N;
        permutation.push_back(original[index]);
        original.erase(original.begin() + index);
        N--;
    }

    printf("<%d", permutation[0]);
    for (int i = 1; i < permutation.size(); ++i)
        printf(", %d", permutation[i]);
    printf(">");
}

int main()
{
    Input();
    Solve();
}
