import sys
from collections import defaultdict, deque


n = int(sys.stdin.readline())
a, b = map(int, sys.stdin.readline().split())
m = int(sys.stdin.readline())

graph = defaultdict(list)
for _ in range(m):
    parent, child = map(int, sys.stdin.readline().split())
    graph[parent].append(child)
    graph[child].append(parent)

# BFS
is_visited = [-1] * (n + 1)
queue = deque([a])
is_visited[a] = 0
while queue:
    popped = queue.popleft()
    if popped == b:
        print(is_visited[popped])
        break

    for relation in graph[popped]:
        if is_visited[relation] == -1:
            is_visited[relation] = is_visited[popped] + 1
            queue.append(relation)
else:
    print(-1)
