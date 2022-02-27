import sys
from collections import defaultdict, deque

# 2 <= N <= 1,000, M <= 1,000
N, M = map(int, sys.stdin.readline().split())
graph = defaultdict(list)
for _ in range(N - 1):
    node1, node2, distance = map(int, sys.stdin.readline().split())
    graph[node1].append([node2, distance])
    graph[node2].append([node1, distance])

for _ in range(M):
    node1, node2 = map(int, sys.stdin.readline().split())
    distances = [float("inf")] * (N + 1)
    queue = deque()

    distances[node1] = 0
    queue.append(node1)
    while queue:
        node = queue.popleft()
        for connected_node, distance in graph[node]:
            if distances[connected_node] > distances[node] + distance:
                distances[connected_node] = distances[node] + distance
                queue.append(connected_node)

    print(distances[node2])
