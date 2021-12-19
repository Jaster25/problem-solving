import sys
from collections import deque, defaultdict

N, M, V = map(int, sys.stdin.readline().split())
graph = defaultdict(list)
for _ in range(M):
    v1, v2 = map(int, sys.stdin.readline().split())
    graph[v1].append(v2)
    graph[v2].append(v1)

# DFS
for i in range(1, N + 1):
    graph[i].sort(reverse=True)

result_dfs = []
is_visited = [False] * (N + 1)
stack = deque([V])
while stack:
    popped = stack.pop()
    if is_visited[popped]:
        continue

    is_visited[popped] = True
    result_dfs.append(popped)
    for node in graph[popped]:
        if not is_visited[node]:
            stack.append(node)

# BFS
for i in range(1, N + 1):
    graph[i].sort()

result_bfs = []
is_visited = [False] * (N + 1)
queue = deque([V])
is_visited[V] = True
while queue:
    popped = queue.popleft()
    result_bfs.append(popped)
    for node in graph[popped]:
        if not is_visited[node]:
            is_visited[node] = True
            queue.append(node)

for number in result_dfs:
    print(number, end=" ")
print()
for number in result_bfs:
    print(number, end=" ")
print()
