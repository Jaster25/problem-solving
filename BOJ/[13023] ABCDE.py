from collections import deque
from sys import stdin

N, M = map(int, stdin.readline().split())
friends = [[] for _ in range(N)]
visited = [False for _ in range(N)]

global is_possible
is_possible = False

for _ in range(M):
    a, b = map(int, stdin.readline().split())
    friends[a].append(b)
    friends[b].append(a)


def dfs(a, cnt):
    if cnt == 5:
        global is_possible
        is_possible = True
        return
    for i in friends[a]:
        if not visited[i]:
            visited[i] = True
            dfs(i, cnt + 1)
            visited[i] = False


for i in range(N):
    if is_possible:
        break
    visited[i] = True
    dfs(i, 1)
    visited[i] = False


print(1 if is_possible else 0)