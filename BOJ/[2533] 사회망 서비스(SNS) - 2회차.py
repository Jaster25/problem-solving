import sys

# Python 3: O
# PyPy3: X
sys.setrecursionlimit(10 ** 5)

N = int(sys.stdin.readline())
graph = [[] for _ in range(N + 1)]
for _ in range(N - 1):
    u, v = map(int, sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)

dp = [[0] * 2 for _ in range(N + 1)]
is_visited = [False] * (N + 1)


def check(index):
    is_visited[index] = True
    dp[index][0] = 0
    dp[index][1] = 1  # 1이 얼리 어답터

    for friend in graph[index]:
        if not is_visited[friend]:
            check(friend)
            dp[index][0] += dp[friend][1]
            dp[index][1] += min(dp[friend][1], dp[friend][0])


check(1)
print(min(dp[1]))
