from itertools import combinations
from collections import Counter
import sys

sys.setrecursionlimit(10 ** 4)


def dfs(curNumberList, swappedCount):
    global dp
    curNumber = int("".join(curNumberList))

    if swappedCount == K:
        return curNumber
    elif dp[curNumber][swappedCount] != -1:
        return dp[curNumber][swappedCount]

    for case in combinations([x for x in range(len(curNumberList))], 2):
        newNumberList = curNumberList[:]
        newNumberList[case[0]], newNumberList[case[1]] = newNumberList[case[1]], newNumberList[case[0]]
        if newNumberList[0] != "0":
            dp[curNumber][swappedCount] = max(dp[curNumber][swappedCount], dfs(newNumberList, swappedCount + 1))
    return dp[curNumber][swappedCount]


N, K = map(int, sys.stdin.readline().split(" "))
dp = [[-1 for _ in range(K + 1)] for _ in range(1000001)]

answer = dfs(list(str(N)), 0)
print(answer)
