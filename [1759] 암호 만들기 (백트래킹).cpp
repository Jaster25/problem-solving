#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L, C;
vector<char> alphabet;

bool check(string str)
{
    int mo = 0;
    int ja = 0;

    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            mo++;
        else
            ja++;
    }

    if (mo >= 1 && ja >= 2)
        return true;
    return false;
}

void createCode(string code, int index)
{
    if (code.length() == L && check(code))
    {
        cout << code + '\n';
        return;
    }

    if (index >= alphabet.size())
        return;

    createCode(code + alphabet[index], index + 1);
    createCode(code, index + 1);
}

int main()
{
    scanf("%d%d", &L, &C);
    getchar();

    for (int i = 0; i < C; ++i)
    {
        char ch;
        scanf("%c", &ch);
        getchar();
        alphabet.push_back(ch);
    }

    sort(alphabet.begin(), alphabet.end());

    createCode("", 0);
}