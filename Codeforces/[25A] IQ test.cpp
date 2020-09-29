#include <bits/stdc++.h>
using namespace std;

int N, answer;
int ar[101];
int cnt, result;

int compareNumbers(int a, int b, int c)
{
    bool isEven_a, isEven_b, isEven_c;
    ar[a] % 2 == 0 ? isEven_a = true : isEven_a = false;
    ar[b] % 2 == 0 ? isEven_b = true : isEven_b = false;
    ar[c] % 2 == 0 ? isEven_c = true : isEven_c = false;

    if (isEven_a == isEven_b && isEven_a == isEven_c)
        return -1;
    else if (isEven_a ^ isEven_b && isEven_a ^ isEven_c)
        return a;
    else if (isEven_b ^ isEven_c && isEven_b ^ isEven_a)
        return b;
    else if (isEven_c ^ isEven_a && isEven_c ^ isEven_b)
        return c;
}

void Solve()
{
    scanf("%d", &N);

    scanf("%d%d%d", &ar[0], &ar[1], &ar[2]);
    result = compareNumbers(0, 1, 2);
    if (result != -1)
        answer = result + 1;

    cnt = 3;
    while (cnt < N)
    {
        scanf("%d", &ar[cnt]);
        result = compareNumbers(cnt - 2, cnt - 1, cnt);
        if (result != -1)
            answer = result + 1;
        cnt++;
    }

    printf("%d", answer);
}

int main()
{
    Solve();
}
