#include <bits/stdc++.h>
using namespace std;

char infixNotation[102];
int notationLength = -1;
stack<char> STACK;

void Input()
{
    scanf("%s", infixNotation);
    while (infixNotation[notationLength + 1])
    {
        notationLength++;
    }
}

int priority(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return 0;
}

void Solve()
{
    for (int i = 0; i <= notationLength; ++i)
    {
        char c = infixNotation[i];

        if (c >= 'A' && c <= 'Z')
            printf("%c", c);
        else if (c == '(')
            STACK.push('(');
        else if (c == ')')
        {
            while (STACK.top() != '(')
            {
                printf("%c", STACK.top());
                STACK.pop();
            }
            // * pop (
            STACK.pop();
        }
        else
        {

            if (STACK.empty() || priority(c) > priority(STACK.top()))
                STACK.push(c);
            else
            {
                while (!STACK.empty() && priority(c) <= priority(STACK.top()) && STACK.top() != '(')
                {
                    printf("%c", STACK.top());
                    STACK.pop();
                }
                STACK.push(c);
            }
        }
    }

    while (!STACK.empty())
    {
        printf("%c", STACK.top());
        STACK.pop();
    }
}

int main()
{
    Input();
    Solve();
}