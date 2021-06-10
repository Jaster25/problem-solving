from sys import stdin
from math import isinf
from collections import deque

for _ in range(int(input())):
    n, d, c = map(int, stdin.readline().split())
    graph = [[] for _ in range(n + 1)]
    visited = [float("inf") for _ in range(n + 1)]
    for _ in range(d):
        a, b, s = map(int, stdin.readline().split())
        graph[b].append([a, s])

    queue = deque([c])
    visited[c] = 0
    while queue:
        computer = queue.popleft()
        for connectedInfo in graph[computer]:
            connectedComputer, takenTime = connectedInfo
            if visited[connectedComputer] > visited[computer] + takenTime:
                visited[connectedComputer] = visited[computer] + takenTime
                queue.append(connectedComputer)

    virusedCount = 1
    maxTime = 0
    for i in range(1, n + 1):
        if i != c:
            if not isinf(visited[i]):
                virusedCount += 1
                maxTime = max(maxTime, visited[i])
    print(virusedCount, maxTime)
