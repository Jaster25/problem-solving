import sys


# n <= 200, m <= 10000
n, m = map(int, sys.stdin.readline().split())
graph = [[float("inf")] * (n + 1) for _ in range(n + 1)]
first_place = [[0] * (n + 1) for _ in range(n + 1)]

for _ in range(m):
    start, goal, time = map(int, sys.stdin.readline().split())
    graph[start][goal] = time
    graph[goal][start] = time
    first_place[start][goal] = goal
    first_place[goal][start] = start

# 플로이드-워셜 알고리즘
for k in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if graph[i][j] > graph[i][k] + graph[k][j]:
                graph[i][j] = graph[i][k] + graph[k][j]
                first_place[i][j] = first_place[i][k]


for i in range(1, n + 1):
    for j in range(1, n + 1):
        if i == j:
            print("-", end=" ")
        else:
            print(first_place[i][j], end=" ")
    print()
