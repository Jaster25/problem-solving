import sys
from collections import defaultdict, deque

N = int(sys.stdin.readline())
graph = defaultdict(list)

for i in range(N):
    row = list(map(int, sys.stdin.readline().split()))
    graph[i].extend(row)


def bfs(start):
    is_visited = [0] * N
    queue = deque()

    queue.append(start)
    while queue:
        popped = queue.popleft()
        for j in range(N):
            if graph[popped][j] == 1:
                if not is_visited[j]:
                    is_visited[j] = 1
                    queue.append(j)
    return is_visited


is_possible_path = [[False] * N for _ in range(N)]
for i in range(N):
    is_visited = bfs(i)
    for j in range(N):
        is_possible_path[i][j] = is_visited[j]

for i in range(N):
    for j in range(N):
        print(is_possible_path[i][j], end=" ")
    print()
