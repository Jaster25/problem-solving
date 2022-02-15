import sys
from collections import defaultdict

# N <= 12, D <= 10,000
N, D = map(int, sys.stdin.readline().split())
graph = defaultdict(list)
for _ in range(N):
    start, goal, shortcut = map(int, sys.stdin.readline().split())
    graph[start].append([goal, shortcut])

distances = [i for i in range(10001)]
for i in range(D + 1):
    if i > 0:
        distances[i] = min(distances[i], distances[i - 1] + 1)
    for goal, shortcut in graph[i]:
        if distances[i] + shortcut < distances[goal]:
            distances[goal] = distances[i] + shortcut

print(distances[D])
