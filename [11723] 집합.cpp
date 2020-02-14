#include <bits/stdc++.h>
using namespace std;

bool SET[21];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;

    string order;
    int elem;

    while (M--)
    {
        cin >> order;
        if (order == "add")
        {
            cin >> elem;
            SET[elem] = true;
        }
        else if (order == "remove")
        {
            cin >> elem;
            SET[elem] = false;
        }
        else if (order == "check")
        {
            cin >> elem;
            if (SET[elem])
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (order == "toggle")
        {
            cin >> elem;
            SET[elem] = !SET[elem];
        }
        else if (order == "all")
        {
            for (int i = 1; i <= 20; ++i)
                SET[i] = true;
        }
        else if (order == "empty")
        {
            for (int i = 1; i <= 20; ++i)
                SET[i] = false;
        }
    }
}