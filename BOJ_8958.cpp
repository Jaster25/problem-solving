#include <iostream>
using namespace std;

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        int score = 0, combo = 0;
        char str[81], *ptr;
        scanf("%s", str);

        ptr = str;
        while (*ptr != '\0')
        {
            if (*ptr == 'O')
                score += ++combo;
            else
                combo = 0;

            ptr++;
        }

        printf("%d\n", score);
    }
}