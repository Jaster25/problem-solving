#include <bits/stdc++.h>
using namespace std;
//	nCr = n-1Cr + n-1Cr-1

int n, m;
string combination[101][101];

string ADD(string a, string b)
{
    string sumString;
    string copyA(a);
    string copyB(b);

    int sum;
    bool carry = false;
    while (!copyA.empty() || !copyB.empty() || carry)
    {
        sum = 0;
        if (!copyA.empty())
        {
            sum += copyA.back() - '0';
            copyA.pop_back();
        }
        if (!copyB.empty())
        {
            sum += copyB.back() - '0';
            copyB.pop_back();
        }
        if (carry)
        {
            carry = false;
            sum += 1;
        }

        if (sum >= 10)
        {
            sum %= 10;
            carry = true;
        }
        sumString.push_back(sum + '0');
    }

    reverse(sumString.begin(), sumString.end());
    return sumString;
}

string DP(int a, int b)
{
    if (combination[a][b] != "")
        return combination[a][b];
    else if (a == b || b == 0)
        return combination[a][b] = "1";
    return combination[a][b] = ADD(DP(a - 1, b), DP(a - 1, b - 1));
}

int main()
{
    scanf("%d%d", &n, &m);

    cout << DP(n, m);
}
