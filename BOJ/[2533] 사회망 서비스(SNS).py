import sys
from collections import defaultdict

sys.setrecursionlimit(10 ** 6)

# 사이클이 존재하지 않는 관계이다.
graph = defaultdict(list)
N = int(sys.stdin.readline())
for _ in range(N - 1):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

# 0: 얼리 어답터 X
# 1: 얼리 어답터 O
dp = [[0] * 2 for _ in range(N + 1)]
is_visited = [False] * (N + 1)


def check_friends(number):
    is_visited[number] = True
    dp[number][0] = 0
    dp[number][1] = 1
    for friend in graph[number]:
        if not is_visited[friend]:
            check_friends(friend)
            dp[number][0] += dp[friend][1]
            dp[number][1] += min(dp[friend][0], dp[friend][1])


check_friends(1)
print(min(dp[1][0], dp[1][1]))
