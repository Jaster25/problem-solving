#include <iostream>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int R;
        char S[21];
        scanf("%d", &R);
        scanf("%s", S);

        char *ptr = S;
        while (*ptr != '\0')
        {
            for (int i = 0; i < R; ++i)
                printf("%c", *ptr);
            ptr++;
        }
        printf("\n");
    }
}