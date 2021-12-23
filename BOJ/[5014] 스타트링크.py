from collections import deque


F, S, G, U, D = map(int, input().split())

is_arrived = False
is_visited = [-1] * (F + 1)

is_visited[S] = 0
queue = deque([S])
while queue:
    popped = queue.popleft()
    if popped == G:
        is_arrived = True
        break

    up = popped + U
    if up <= F:
        if is_visited[up] == -1:
            is_visited[up] = is_visited[popped] + 1
            queue.append(up)
    down = popped - D
    if 1 <= down:
        if is_visited[down] == -1:
            is_visited[down] = is_visited[popped] + 1
            queue.append(down)

if is_arrived:
    print(is_visited[G])
else:
    print("use the stairs")
