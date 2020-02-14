#include <iostream>
using namespace std;

int main()
{
    int ar[8];
    for (int i = 0; i < 8; ++i)
        scanf("%d", &ar[i]);

    int result;
    if (ar[0] == 1)
        result = 1;
    else if (ar[0] == 8)
        result = 2;
    else
        result = 3;

    for (int i = 1; i < 8; ++i)
    {
        if (result == 1 && ar[i - 1] == ar[i] - 1)
            continue;
        else if (result == 2 && ar[i - 1] == ar[i] + 1)
            continue;
        else
        {
            result = 3;
            break;
        }
    }

    switch (result)
    {
    case 1:
        printf("ascending");
        break;
    case 2:
        printf("descending");
        break;
    default:
        printf("mixed");
        break;
    }
}