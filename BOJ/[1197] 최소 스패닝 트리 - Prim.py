import sys
import heapq
from collections import defaultdict

v, e = map(int, input().split())

graph = defaultdict(list)
for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a].append([c, b])
    graph[b].append([c, a])


heap = []
visited_set = set()

# 1번 정점으로부터 시작
visited_set.add(1)
for weight, other_node in graph[1]:
    heapq.heappush(heap, [weight, 1, other_node])

min_weigth = 0
while heap:
    weight, node1, node2 = heapq.heappop(heap)

    if set([node1, node2]).issubset(visited_set):
        continue

    min_weigth += weight

    new_node = node1 if node1 not in visited_set else node2
    visited_set.add(new_node)

    for other_weight, other_node in graph[new_node]:
        heapq.heappush(heap, [other_weight, new_node, other_node])

print(min_weigth)
