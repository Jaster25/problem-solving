from sys import stdin
from collections import deque
import heapq

N, M, K = map(int, stdin.readline().split())
road = [[] for _ in range(N + 1)]
visited = [[float("inf") for _ in range(K + 1)] for _ in range(N + 1)]

for _ in range(M):
    a, b, cost = map(int, stdin.readline().split())
    road[a].append([cost, b])
    road[b].append([cost, a])


PQ = []
visited[1][0] = 0
heapq.heappush(PQ, [0, 1, 0])

while PQ:
    d, a, k = heapq.heappop(PQ)

    # ! key point
    if a == N or d > visited[a][k]:
        continue

    for cost, b in road[a]:
        if k < K and visited[b][k + 1] > d:
            visited[b][k + 1] = d
            heapq.heappush(PQ, [visited[b][k + 1], b, k + 1])
        if visited[b][k] > d + cost:
            visited[b][k] = d + cost
            heapq.heappush(PQ, [visited[b][k], b, k])

print(min(visited[N]))