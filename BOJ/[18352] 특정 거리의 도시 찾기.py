from sys import stdin
from collections import deque


N, M, K, X = map(int, stdin.readline().split())
graph = [[] for _ in range(N + 1)]
visited = [float("inf") for _ in range(N + 1)]
for _ in range(M):
    A, B = map(int, stdin.readline().split())
    graph[A].append(B)

queue = deque([X])
visited[X] = 0
while queue:
    city = queue.popleft()
    for connectedCity in graph[city]:
        if visited[connectedCity] > visited[city] + 1:
            visited[connectedCity] = visited[city] + 1
            queue.append(connectedCity)

answer = []
for i in range(1, N + 1):
    if visited[i] == K:
        answer.append(i)

if answer:
    for num in sorted(answer):
        print(num)
else:
    print(-1)
