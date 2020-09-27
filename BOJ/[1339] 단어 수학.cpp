#include <bits/stdc++.h>
using namespace std;

vector<string> word;
map<char, int> alpha;
priority_queue<int, vector<int>, less<int>> PQ;
int N, sum;

int main()
{

    scanf("%d", &N);
    getchar();

    string temp;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        word.push_back(temp);

        string reverseTemp = temp;
        reverse(reverseTemp.begin(), reverseTemp.end());

        int index = 1;
        for (auto elem : reverseTemp)
        {
            int exist = alpha.find(elem)->second;
            alpha.erase(elem);
            alpha.insert(pair<char, int>(elem, index + exist));
            index *= 10;
        }
    }

    for (auto a : alpha)
        PQ.push(a.second);

    int index = 9;
    while (!PQ.empty())
    {
        sum += index * PQ.top();
        PQ.pop();
        index--;
    }

    printf("%d", sum);
}
