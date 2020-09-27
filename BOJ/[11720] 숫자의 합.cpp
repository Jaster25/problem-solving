#include <iostream>
using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    getchar();

    int sum = 0;
    char num;
    while (N--)
    {
        scanf("%c", &num);
        sum += num - '0';
    }
    printf("%d", sum);
}