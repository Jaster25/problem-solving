from collections import deque

S = int(input())

queue = deque()  # [number, clipboard, time]
is_visited = [[False] * (1001) for _ in range(1001)]

queue.append([1, 0, 0])
is_visited[1][0] = True

# 1. clipboard = number
# 2. number = clipboard
# 3. number -= 1
while queue:
    number, clipboard, time = queue.popleft()
    if number == S:
        print(time)
        break

    if number != clipboard and number < 1001:
        if not is_visited[number][number]:
            queue.append([number, number, time + 1])
            is_visited[number][number] = True
    if clipboard > 0 and number + clipboard < 1001:
        if not is_visited[number + clipboard][clipboard]:
            queue.append([number + clipboard, clipboard, time + 1])
            is_visited[number + clipboard][clipboard] = True
    if number > 1:
        if not is_visited[number - 1][clipboard]:
            queue.append([number - 1, clipboard, time + 1])
            is_visited[number - 1][clipboard] = True
